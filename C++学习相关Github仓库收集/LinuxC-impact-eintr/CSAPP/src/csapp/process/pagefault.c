#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "../headers/memory.h"
#include "../headers/address.h"
#include "../headers/common.h"
#include "../headers/interrupt.h"
#include "../headers/cpu.h"
#include "../headers/process.h"
#include "../headers/color.h"

uint64_t mmu_vaddr_pagefault;

// swap in / out
int swap_in(uint64_t saddr, uint64_t ppn);
int swap_out(uint64_t saddr, uint64_t ppn);

vm_area_t * search_vma_vaddr(pcb_t *, uint64_t);
int copy_physicalframe(pte4_t *child_pte, uint64_t parent_ppn);

#define MAX_REVERSED_MAPPING_NUMBER (4)

// physical page descriptor
typedef struct {
  int allocated;
  int dirty;
  int time; // LRU cache: 0 - Fresh

  pte4_t *mapping[MAX_REVERSED_MAPPING_NUMBER];
  // struct page中有一个mapping字段负责反向映射
  // mapping中一个bit用来表示是fileback 还是 anonymous
  // fileback 映射到 address space
  // anonymous 映射到 anonymous_vma 这是一个链表 链接所有共享该page的vma
  uint64_t reversed_counter;
  uint64_t saddr;
} pd_t;

static pd_t page_map[MAX_NUM_PHYSICAL_PAGE];

// get the level page table entry
pte123_t* get_pagetableentry(pte123_t *pgd, address_t *vaddr, int level, int allocate) {
  int vpns[4] = {
      vaddr->vpn1,
      vaddr->vpn2,
      vaddr->vpn3,
      vaddr->vpn4,
  };
  assert(pgd != NULL);
  assert(sizeof(pte123_t) == sizeof(pte4_t));
  assert(1 <= level && level <= 4);

  int tab_level = 1;
  pte123_t *tab = pgd;
  pte123_t *pte = NULL;

  while (tab_level <= level) {
    int vpn = vpns[tab_level - 1];
    pte = &tab[vpn];

    // move to next level
    if (tab_level < 4) {
      if (pte->present != 1) {
        if (allocate == 1) {
          // allocate a new page for next level
          pte123_t *new_tab = (pte123_t *)KERNEL_malloc(PAGE_TABLE_ENTRY_NUM *
                                                        sizeof(pte123_t));
          // .paddr field is 50 bits
          tab[vpn].paddr = (uint64_t)new_tab;
          tab[vpn].present = 1;
        } else {
          return NULL;
        }
      }
      tab = (pte123_t *)((uint64_t)pte->paddr);
    }
    tab_level += 1;
  }
  return pte;
}

void page_map_init() {
  for (int k = 0;k < MAX_NUM_PHYSICAL_PAGE;++k) {
    page_map[k].allocated = 0;
    page_map[k].dirty = 0;
    page_map[k].time = 0;
    page_map[k].reversed_counter = 0;
    for (int i = 0;i < MAX_REVERSED_MAPPING_NUMBER; ++i) {
      page_map[k].mapping[i] = NULL;
    }
  }
}

void pagemap_update_time(uint64_t ppn) {
  assert(0 <= ppn && ppn < MAX_NUM_PHYSICAL_PAGE);
  assert(page_map[ppn].allocated == 1);
  // check reversed_count
  int reversed_count = 0;
  for (int i = 0;i < MAX_REVERSED_MAPPING_NUMBER; ++i) {
    if (page_map[ppn].mapping[i] != NULL) {
      assert(page_map[ppn].mapping[i]->present == 1);
      reversed_count += 1;
    }
  }
  assert(reversed_count == page_map[ppn].reversed_counter);

  for (int i = 0;i < MAX_NUM_PHYSICAL_PAGE;++i) {
    page_map[i].time += 1;
  }
  page_map[ppn].time = 0;
}

void pagemap_dirty(uint64_t ppn) {
  assert(0 <= ppn && ppn < MAX_NUM_PHYSICAL_PAGE);
  assert(page_map[ppn].allocated == 1);
  // check reversed_count
  int reversed_count = 0;
  for (int i = 0; i < MAX_REVERSED_MAPPING_NUMBER; ++i) {
    if (page_map[ppn].mapping[i] != NULL) {
      assert(page_map[ppn].mapping[i]->present == 1);
      reversed_count += 1;
    }
  }
  assert(reversed_count == page_map[ppn].reversed_counter);

  page_map[ppn].dirty = 1;
  for (int i = 0; i < MAX_REVERSED_MAPPING_NUMBER; ++i) {
    if (page_map[ppn].mapping[i] != NULL) {
      page_map[ppn].mapping[i]->dirty = 1;
      reversed_count += 1;
    }
  }
}

// used by frame swap-in from swap space
void set_pagemap_swapaddr(uint64_t ppn, uint64_t swap_address) {
  assert(0 <= ppn && ppn < MAX_NUM_PHYSICAL_PAGE);
  page_map[ppn].saddr = swap_address;
}
/*  When mapped
   Page table entry: present = 1, ppn
   page_map[ppn]: pte4, swap address
   data on DRAM[ppn] (DIRTY/CLEAN), SWAP[swap address]
*/
void map_pte4(pte4_t *pte, uint64_t ppn) {
  assert(0 <= ppn && ppn < MAX_NUM_PHYSICAL_PAGE);
  assert(page_map[ppn].dirty == 0);
  assert(page_map[ppn].reversed_counter < MAX_REVERSED_MAPPING_NUMBER);

  // Let's consider this, where can we store the swap adress on disk?
  // In this case of physical page being allocated and papped,
  // the swap address is store in reversed maping array
  page_map[ppn].saddr = pte->saddr;

  // map the level 4 page table
  pte->present = 1;
  pte->ppn = ppn;
  pte->dirty = 0;

  page_map[ppn].allocated = 1;
  //page_map[ppn].dirty = 0;
  page_map[ppn].time = 0; // LRU

  // reversed mapping
  int success = 0;
  for (int i = 0; i < MAX_REVERSED_MAPPING_NUMBER; ++i) {
    if (page_map[ppn].mapping[i] == NULL) {
      page_map[ppn].mapping[i] = pte;
      success = 1;
      break;
    }
  }
  assert(success == 1);
  page_map[ppn].reversed_counter += 1;
}

/*  When unmapped
    Page table entry: present = 0, swap address
    page_map[ppn]: not applicable any more
    data on SWAP[swap address] (WB)
*/
void unmapall_pte4(uint64_t ppn) {
  assert(0 <= ppn && ppn < MAX_NUM_PHYSICAL_PAGE);
  assert(page_map[ppn].allocated == 1);
  assert(page_map[ppn].reversed_counter > 0);

  // clear all the reversed mapping
  page_map[ppn].allocated = 0;
  page_map[ppn].dirty = 0;
  page_map[ppn].time = 0;

  for (int i = 0;i < MAX_REVERSED_MAPPING_NUMBER; ++i) {
    if (page_map[ppn].mapping[i] != NULL) {
      // release the PTE
      pte4_t *pte =page_map[ppn].mapping[i];
      assert(pte->present == 1);
      pte->pte_value = 0;
      pte->present = 0;

      pte->saddr = page_map[ppn].saddr;

      // release reversed mapping
      page_map[ppn].mapping[i] = NULL;
      page_map[ppn].reversed_counter -= 1;
    }
  }
  assert(page_map[ppn].reversed_counter == 0);
  // now page_map[ppn] can be used by other page table entry
}

static void copy_on_write(pte4_t *pte) {
  //  pte: the corresponding pte of COW vaddr
  assert(pte->present == 1);
  assert(pte->readonly == 1);
  printf(BLUESTR("\tCopy-on-Write\n"));
  // Get the old ppn, this ppn should be mapped by multiple processes's PTEs
  uint64_t old_ppn = (uint64_t)pte->ppn;
  assert(page_map[old_ppn].reversed_counter > 1);

  // Update the left mappings
  pte4_t *remaining[MAX_REVERSED_MAPPING_NUMBER];
  int remaining_count = 0;
  for (int i = 0; i < MAX_REVERSED_MAPPING_NUMBER; ++i) {
    pte4_t *t = page_map[old_ppn].mapping[i];
    if (t != pte && t != NULL) {
      remaining[i] = t;
      remaining_count += 1;
    } else {
      remaining[i] = NULL;
    }
  }

  // remove all remaining from old ppn
  unmapall_pte4(old_ppn);

  // reinsert and update r/w mode
  // parent PTE remap
  for (int i = 0; i < MAX_REVERSED_MAPPING_NUMBER; ++i) {
    if (remaining[i] != NULL) {
      assert(remaining[i]->readonly == 1);
      map_pte4(remaining[i], old_ppn);

      if (remaining_count == 1) {
        // if only one pte is left, set it to read/write
        // This is the case: old mappings = [parent, child]
        // both are read only. The new mappings are [parent]
        // [child], both are read/write.
        remaining[i]->readonly = 0;
      }
    }
  }

  // Allocate new physical frame for the PTE
  // Copy data in physical frame
  int success = copy_physicalframe(pte, old_ppn); // 这里将pte->ppn修改
  pte->readonly = 0;
  assert(success == 1);
  assert(pte->present == 1);
  uint64_t new_ppn = (uint64_t)pte->ppn;
  assert(new_ppn != old_ppn);

  printf(
      BLUESTR("\tPTE<%p> removed from Frame[%ld]. New Frame[%ld] allocated\n"),
      pte, old_ppn, new_ppn);
}

// fix pagefault : interrupt.c/pagefault_handler() call
void fix_pagefault() {
  // get page table directory from rsp
  pcb_t *pcb = get_current_pcb();
  pte123_t *pgd = pcb->mm.pgd;

  // get the faulting address from MMU register
  address_t vaddr = {.address_value = mmu_vaddr_pagefault}; // a global mmu vaddr

  // get the level 4 page table entry
  pte4_t *pte = (pte4_t *)get_pagetableentry(pgd, &vaddr, 4, 1);

#ifdef USE_FORK_COW
  // check read/write in vma
  vm_area_t *area = search_vma_vaddr(pcb, vaddr.vaddr_value);
  if (area == NULL) {
    // not in area
    assert(0);
  } else {
    // found in area
    // trap入Kernel，kernel检查VMA发现是可写的，
    // 表示这是一个COW操作，这时会发生一个拷贝
    if (pte->readonly == 1 && area->vma_mode.write == 1) {
      copy_on_write(pte); // child cow
    } else {
      assert(0);
    }
    return;
  }
#endif
  // native fork copy

  // 1 try to request one free physical page from DRAM
  for (int i = 0;i < MAX_NUM_PHYSICAL_PAGE;++i) {
    if (page_map[i].allocated == 0) {
      // found i as free ppn
      map_pte4(pte, i);
      printf(BLUESTR("\tPageFault: vaddr[%lx] use free ppn %d\n"),
             vaddr.address_value, i);
      return;
    }
  }

  // 2. no free physical page: select one clean page (LRU) and overwrite
  // int this case, there is no DRAM - DISK transaction
  // you know you can optimize this loop
  int lru_ppn = -1;
  int lru_time = -1;
  for (int i = 0;i < MAX_NUM_PHYSICAL_PAGE;++i) {
    if (page_map[i].dirty == 0 && lru_time < page_map[i].time) {
      lru_time = page_map[i].time;
      lru_ppn = i;
    }
  }
  // this si the selected ppn for vaddr
  if (-1 != lru_ppn && lru_ppn < MAX_NUM_PHYSICAL_PAGE) {
    unmapall_pte4(lru_ppn);
    // load page from disk to physical memory
    // at the victim's ppn
    swap_in(pte->saddr, lru_ppn);
    map_pte4(pte, lru_ppn);

    printf(BLUESTR("\tPageFault: discard clean ppn %d as victim\n"), lru_ppn);
    return;
  }

  // 3. no free nor clean physical page: select one LRU victim
  // write back (swap out) the DIRTY victim to disk
  lru_ppn = -1;
  lru_time = -1;
  for (int i = 0;i < MAX_NUM_PHYSICAL_PAGE; ++i) {
    if (lru_time < page_map[i].time) {
      lru_time = page_map[i].time;
      lru_ppn = i;
    }
  }
  assert(0 <= lru_ppn && lru_ppn < MAX_NUM_PHYSICAL_PAGE);

  // write back
  swap_out(page_map[lru_ppn].saddr, lru_ppn);
  // unmap victim
  unmapall_pte4(lru_ppn);
  // load page from disk to physical memory
  swap_in(pte->saddr, lru_ppn);
  map_pte4(pte, lru_ppn);

  printf(BLUESTR("\tPageFault: write back & use ppn %d\n"), lru_ppn);
}

int allocate_physicalframe(pte4_t *pte) {
  for (int i = 0;i < MAX_NUM_PHYSICAL_PAGE;++i) {
    if (page_map[i].allocated == 0) {
      // found i as frees page
      map_pte4(pte, i);
      return 1;
    }
  }
  return 0;
}

// copy one physical frame for new process to use
// And this new frame should have exactly the same data as parent process
int copy_physicalframe(pte4_t *child_pte, uint64_t parent_ppn) {
  assert(0 <= parent_ppn && parent_ppn < MAX_NUM_PHYSICAL_PAGE);
  if (allocate_physicalframe(child_pte) == 1) {
    uint64_t ppn = child_pte->ppn;
    memcpy(&pm[ppn << PHYSICAL_PAGE_OFFSET_LENGTH],
           &pm[parent_ppn << PHYSICAL_PAGE_OFFSET_LENGTH], PAGE_SIZE);
  }
  // TODO && FIXME : parent_ppn my be evicted
  // So we should fail the fork

  return 1;
}

int enough_frame(int request_num) {
  int free_num = 0;
  for (int i = 0;i < MAX_NUM_PHYSICAL_PAGE;++i) {
    if (page_map[i].allocated == 0) {
      free_num += 1;
    }
  }
  if (request_num <= free_num) {
    return 1;
  } else {
    return 0;
  }
}
