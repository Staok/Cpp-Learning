#include <assert.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/allocator.h"

// Operating System Implemented
void os_syscall_brk() {
  // TODO pagefault
}

uint32_t extend_heap(uint32_t size) {
  // round up to page aligment
  size = (uint32_t)round_up((uint64_t)size, 4096);
  if (heap_end_vaddr - heap_start_vaddr + size <= HEAP_MAX_SIZE) {
    os_syscall_brk();
    heap_end_vaddr += size;
  } else {
    return 0;
  }

  uint64_t epilogue = get_epilogue();
  set_allocated(epilogue, ALLOCATED);
  set_blocksize(epilogue, 0);
  return size;
}

// Free Block Mamagement Implemented
#ifdef IMPLICIT_FREE_LIST
int implicit_list_initialize_free_block();
uint64_t implicit_list_search_free_block(uint32_t payload_size, uint32_t *alloc_blocksize);
int implicit_list_insert_free_block(uint64_t free_header);
int implicit_list_delete_free_block(uint64_t free_header);
void implicit_list_check_free_block();
#endif

#ifdef EXPLICIT_FREE_LIST
int explicit_list_initialize_free_block();
uint64_t explicit_list_search_free_block(uint32_t payload_size, uint32_t *alloc_blocksize);
int explicit_list_insert_free_block(uint64_t free_header);
int explicit_list_delete_free_block(uint64_t free_header);
void explicit_list_check_free_block();
#endif

#ifdef REDBLACK_TREE
int redblack_tree_initialize_free_block();
uint64_t redblack_tree_search_free_block(uint32_t payload_size, uint32_t *alloc_blocksize);
int redblack_tree_insert_free_block(uint64_t free_header);
int redblack_tree_delete_free_block(uint64_t free_header);
void redblack_tree_check_free_block();
#endif

static int initialize_free_block() {
#ifdef IMPLICIT_FREE_LIST
  return implicit_list_initialize_free_block();
#elif defined (EXPLICIT_FREE_LIST)
  return explicit_list_initialize_free_block();
#elif defined (REDBLACK_TREE)
  return redblack_tree_initialize_free_block();
#endif
  assert(0);
}

static uint64_t search_free_block(uint32_t payload_size, uint32_t *alloc_blocksize) {
#ifdef IMPLICIT_FREE_LIST
  return implicit_list_search_free_block(payload_size, alloc_blocksize);
#elif defined (EXPLICIT_FREE_LIST)
  return explicit_list_search_free_block(payload_size, alloc_blocksize);
#elif defined (REDBLACK_TREE)
  return redblack_tree_search_free_block(payload_size, alloc_blocksize);
#endif
  assert(0);
}

static int insert_free_block(uint64_t free_header) {
#ifdef IMPLICIT_FREE_LIST
  return implicit_list_insert_free_block(free_header);
#elif defined (EXPLICIT_FREE_LIST)
  return explicit_list_insert_free_block(free_header);
#elif defined (REDBLACK_TREE)
  return redblack_tree_insert_free_block(free_header);
#endif
  assert(0);
}

static int delete_free_block(uint64_t free_header) {
#ifdef IMPLICIT_FREE_LIST
  return implicit_list_delete_free_block(free_header);
#elif defined (EXPLICIT_FREE_LIST)
  return explicit_list_delete_free_block(free_header);
#elif defined (REDBLACK_TREE)
  return redblack_tree_delete_free_block(free_header);
#endif
  assert(0);
}

static void check_free_block() {
#ifdef IMPLICIT_FREE_LIST
  return implicit_list_check_free_block();
#elif defined (EXPLICIT_FREE_LIST)
  return explicit_list_check_free_block();
#elif defined (REDBLACK_TREE)
  return redblack_tree_check_free_block();
#endif
  assert(0);
}

// ------------------------------
//        Malloc And Free
// ------------------------------

// Util
void check_heap_correctness();

static uint64_t merge_blocks_as_free(uint64_t low, uint64_t high) {
  assert(low % 8 == 4);
  assert(high % 8 == 4);
  assert(get_firstblock() <= low && low < get_lastblock());
  assert(get_firstblock() < high && high <= get_lastblock());
  assert(get_nextheader(low) == high);
  assert(get_prevheader(high) == low);

  // must merge as free
  uint32_t blocksize = get_blocksize(low) + get_blocksize(high);

  set_blocksize(low, blocksize);
  set_allocated(low, FREE);

  uint64_t footer = get_footer(low);
  set_blocksize(footer, blocksize);
  set_allocated(footer, FREE);

  return low;
}

static uint64_t try_alloc_with_splitting(uint64_t block_vaddr, uint32_t request_blocksize) {
  if (request_blocksize < 8) {
    return NIL;
  }

  uint64_t b = block_vaddr;
  uint32_t b_blocksize = get_blocksize(b);
  uint32_t b_allocated = get_allocated(b);

  if (b_allocated == FREE && b_blocksize >= request_blocksize) {
    // allocate this block
    delete_free_block(b);
    uint64_t left_footer = get_footer(b);

    set_allocated(b, ALLOCATED);
    set_blocksize(b, request_blocksize);

    uint64_t b_footer = b + request_blocksize - 4;
    set_allocated(b_footer, ALLOCATED);
    set_blocksize(b_footer, request_blocksize);

    uint32_t left_size = b_blocksize - request_blocksize;
    if (left_size >= 8) {
      // split this block `b`
      // b_blocksize - request_blocksize >= 8
      uint64_t left_header = get_nextheader(b);
      set_allocated(left_header, FREE);
      set_blocksize(left_header, b_blocksize - request_blocksize);

      set_allocated(left_footer, FREE);
      set_blocksize(left_footer, b_blocksize - request_blocksize);

      assert(get_footer(left_header) == left_footer);
      insert_free_block(left_header);
    }
    return get_payload(b);
  }
  return NIL;
}

static uint64_t try_extend_heap_to_alloc(uint32_t size) {
  // get the size to be added
  uint64_t old_last = get_lastblock();

  uint32_t last_allocated = get_allocated(old_last);
  uint32_t last_blocksize = get_blocksize(old_last);

  uint32_t to_request_from_OS = size;
  if (last_allocated == FREE) {
    // last block can help the request
    to_request_from_OS -= last_blocksize;
    delete_free_block(old_last);
  }

  uint32_t old_epilogue = get_epilogue();
  uint32_t os_allocated_size = extend_heap(to_request_from_OS);
  if (os_allocated_size != 0) {
    assert(os_allocated_size >= 4096);
    assert(os_allocated_size % 4096 == 0);

    uint64_t payload_header = NIL;

    if (last_allocated == ALLOCATED) {
      // no merging is needed
      // take place the old epilogue as new last
      uint64_t new_last = old_epilogue;
      set_allocated(new_last, FREE);
      set_blocksize(new_last, os_allocated_size);

      // set the new footer
      uint64_t new_last_footer = get_footer(new_last);
      set_allocated(new_last_footer, FREE);
      set_blocksize(new_last_footer, os_allocated_size);
      insert_free_block(new_last);

      payload_header = new_last;
    } else {
      // merging with last_block is needed
      set_allocated(old_last, FREE);
      set_blocksize(old_last, last_blocksize + os_allocated_size);

      uint64_t last_footer = get_footer(old_last);
      set_allocated(last_footer, FREE);
      set_blocksize(last_footer, last_blocksize + os_allocated_size);

      // blocksize is different now
      // consider the balanced tree index on blocksize, it must be reinserted
      insert_free_block(old_last);

      payload_header = old_last;
    }

    // try to allocate
    uint64_t payload_vaddr = try_alloc_with_splitting(payload_header, size);
    if (payload_vaddr != NIL) {
#ifdef DEBUG_MALLOC
      check_heap_correctness();
#endif
      return payload_vaddr;
    }
  }

  if (last_allocated == FREE) {
    insert_free_block(old_last);
  }
  // else, no page can be allocated
#ifdef DEBUG_MALLOC
  check_heap_correctness();
  printf("OS cannot allocate physical page for heap!\n");
#endif
  return NIL;
}

// ------------------------------------
// Debugging and Correctness Checking
// ------------------------------------
void check_heap_correctness() {
  int liner_free_counter = 0;
  uint64_t p = get_firstblock(); // iterator
  while(p != NIL && p <= get_lastblock()) {
    assert(p % 8 == 4);
    assert(get_firstblock() <= p && p <= get_lastblock());

    uint64_t f = get_footer(p);
    uint32_t blocksize = get_blocksize(p);
    if (blocksize != 8) {
      assert(get_blocksize(p) == get_blocksize(f));
      assert(get_allocated(p) == get_allocated(f));
    }

    if (get_allocated(p) == FREE) {
      liner_free_counter += 1;
    } else {
      liner_free_counter = 0;
    }
    assert(liner_free_counter <= 1); // We don't want to have two consecutive free blocks
    p = get_nextheader(p);
  }
}

static void block_info_print(uint64_t h) {
  uint32_t a = get_allocated(h);
  uint32_t s = get_blocksize(h);
  uint64_t f = get_footer(h);

  uint32_t hv = *(uint32_t *)&heap[h];
  uint32_t fv = *(uint32_t *)&heap[f];

  uint32_t p8 = (hv >> 1) & 0x1;
  uint32_t b8 = (hv >> 2) & 0x1;
  uint32_t rb = (fv >> 1) & 0x1;

  printf("H:%lu,\tF:%lu,\tS:%u,\t(A:%u,RB:%u,B8:%u,P8:%u)\n", h, f, s, a, rb, b8, p8);
}

static void heap_blocks_print() {
  printf("============\nheap blocks:\n");
  uint64_t h = get_firstblock();
  int i = 0;
  while (i < (HEAP_MAX_SIZE / 8) && h != NIL && h < get_epilogue()) {
    block_info_print(h);
    h = get_nextheader(h);
  }
  printf("============\n");
}

// interface
int heap_init() {
  // reset all to 0
  for (int i = 0; i < HEAP_MAX_SIZE / 8; i += 8) {
    *(uint64_t *)&heap[i] = 0;
  }

  heap_start_vaddr = 0;
  heap_end_vaddr = 4096;

  // set prologue block
  uint64_t prologue_header = get_prologue();
  set_allocated(prologue_header, ALLOCATED);
  set_blocksize(prologue_header, 8);

  uint64_t prologue_footer = prologue_header + 4;
  set_allocated(prologue_footer, ALLOCATED);
  set_blocksize(prologue_footer, 8);

  // set epilogue block
  // it is a footer only
  uint64_t epilogue = get_epilogue();
  set_allocated(epilogue, ALLOCATED);
  set_blocksize(epilogue, 0);

  // set the block size & allocated of the only regular block
  uint64_t first_header = get_firstblock();
  set_allocated(first_header, FREE);
  set_blocksize(first_header, 4096 - 4 - 8 - 4);

  uint64_t first_footer = get_footer(first_header);
  set_allocated(first_footer, FREE);
  set_blocksize(first_footer, 4096 - 4 - 8 - 4);

  initialize_free_block();

  return 1;
}

//#define DEBUG_MALLOC
uint64_t mem_alloc(uint32_t size) {
  assert(0 < size && size < HEAP_MAX_SIZE - 4 - 8 - 4);

  uint32_t alloc_blocksize = 0;
  uint64_t payload_header = search_free_block(size, &alloc_blocksize);
  uint64_t payload_vaddr = NIL;

  if (payload_header != NIL) {
    payload_vaddr = try_alloc_with_splitting(payload_header, alloc_blocksize);
    assert(payload_vaddr != NIL);
  } else {
    payload_vaddr = try_extend_heap_to_alloc(alloc_blocksize);
  }
#ifdef DEBUG_MALLOC
  check_heap_correctness();
  check_free_block();
  heap_blocks_print();
#endif
  return payload_vaddr;
}


uint64_t implicit_list_search_free_aligned_block(uint32_t payload_size,
                                                 uint32_t *alloc_blocksize,
                                                 uint64_t aligned);

uint64_t mem_aligned_alloc(uint32_t size, uint64_t aligned) {
  assert(0 < size && size < HEAP_MAX_SIZE - 4 - 8 - 4);

  uint32_t alloc_blocksize = 0;
  uint64_t payload_header =
      implicit_list_search_free_aligned_block(size, &alloc_blocksize, aligned);
  uint64_t payload_vaddr = NIL;

  if (payload_header != NIL) {
    payload_vaddr = try_alloc_with_splitting(payload_header, alloc_blocksize);
    assert(payload_vaddr != NIL);
  } else {
    payload_vaddr = try_extend_heap_to_alloc(alloc_blocksize);
  }
#ifdef DEBUG_MALLOC
  check_heap_correctness();
  check_free_block();
  heap_blocks_print();
#endif
  return payload_vaddr;
}

void mem_free(uint64_t payload_vaddr) {
  if (payload_vaddr == NIL) {
    return;
  }

  assert(get_firstblock() < payload_vaddr && payload_vaddr < get_epilogue());
  assert((payload_vaddr & 0x7) == 0x0);

  // request can be first or last block
  uint64_t req_header = get_header(payload_vaddr);
  uint64_t req_footer = get_footer(req_header);

  uint32_t req_allocated = get_allocated(req_header);
  uint32_t req_blocksize = get_blocksize(req_header);
  assert(req_allocated == ALLOCATED);

  // block starting address of next & prev blocks
  uint64_t next = get_nextheader(req_header);
  uint64_t prev = get_prevheader(req_header);

  uint32_t next_allocated = get_allocated(next);
  uint32_t prev_allocated = get_allocated(prev);

  if (next_allocated == ALLOCATED && prev_allocated == ALLOCATED) { // *A(A->F)A*
    set_allocated(req_header, FREE);
    set_allocated(req_footer, FREE);
    insert_free_block(req_header);

#ifdef DEBUG_MALLOC
    check_heap_correctness();
    check_free_block();
#endif
  } else if (next_allocated == FREE && prev_allocated == ALLOCATED) { // *A(A->F)FA
    delete_free_block(next);
    uint64_t on_free= merge_blocks_as_free(req_header, next);
    insert_free_block(on_free);

#ifdef DEBUG_MALLOC
    check_heap_correctness();
    check_free_block();
#endif
  } else if (next_allocated == ALLOCATED && prev_allocated == FREE) { // AF(A->F)A*
    delete_free_block(prev);
    uint64_t on_free= merge_blocks_as_free(prev, req_header);
    insert_free_block(on_free);

#ifdef DEBUG_MALLOC
    check_heap_correctness();
    check_free_block();
#endif
  } else if (next_allocated == FREE && prev_allocated == FREE) { // AF(A->F)FA
    delete_free_block(prev);
    delete_free_block(next);
    uint64_t one_free = merge_blocks_as_free(merge_blocks_as_free(prev, req_header), next);
    insert_free_block(one_free);

#ifdef DEBUG_MALLOC
    check_heap_correctness();
    check_free_block();
#endif
  } else {
#ifdef DEBUG_MALLOC
    printf("failed to free\n");
    exit(0);
#endif
  }
}
