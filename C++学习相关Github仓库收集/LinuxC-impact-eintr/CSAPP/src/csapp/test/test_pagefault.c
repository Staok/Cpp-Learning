#include <assert.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/algorithm.h"
#include "../headers/address.h"
#include "../headers/common.h"
#include "../headers/cpu.h"
#include "../headers/instruction.h"
#include "../headers/interrupt.h"
#include "../headers/memory.h"
#include "../headers/process.h"

void map_pte4(pte4_t *pte, uint64_t ppn);
void unmap_pte4(uint64_t ppn);
void page_map_init();
void pagemap_dirty(uint64_t ppn);
void pagemap_update_time(uint64_t ppn);
void set_pagemap_swapaddr(uint64_t ppn, uint64_t swap_address);
uint64_t allocate_swappage(uint64_t ppn);

static void link_page_table(pte123_t *pgd,pte123_t *pud,pte123_t *pmd,pte4_t *pt,
  int ppn, address_t *vaddr) {

  int vpn1 = vaddr->vpn1;
  int vpn2 = vaddr->vpn2;
  int vpn3 = vaddr->vpn3;
  int vpn4 = vaddr->vpn4;

  (&(pgd[vpn1]))->paddr = (uint64_t)&pud[0];
  (&(pgd)[vpn1])->present = 1;

  (&(pud[vpn2]))->paddr = (uint64_t)&pmd[0];
  (&(pud)[vpn2])->present = 1;

  (&(pmd[vpn3]))->paddr = (uint64_t)&pt[0];
  (&(pmd)[vpn3])->present = 1;

  (&(pt[vpn4]))->ppn = ppn;
  (&(pt)[vpn4])->present = 1;

  map_pte4(&pt[vpn4], ppn);
}

static void TestPageFaultHandlingCase1() {
  cpu_pc.rip = 0x00400000;
  address_t fault_addr = {.address_value = 0x7fff1234};
  address_t code_addr = {.address_value = cpu_pc.rip};

  page_map_init();

  // pcb is need to trigger page fault
  pcb_t p1;
  memset(&p1, 0, sizeof(pcb_t));
  p1.pid = 1;
  p1.next = &p1;
  p1.prev = &p1;

  // prepare PGD
  pte123_t p1_pgd[512];
  memset(&p1_pgd, 0, sizeof(pte123_t) * 512);
  p1.mm.pgd = &p1_pgd[0];
  // prepare PUD
  pte123_t p1_pud[512];
  memset(&p1_pud, 0, sizeof(pte123_t) * 512);
  // prepare PMD
  pte123_t p1_pmd[512];
  memset(&p1_pmd, 0, sizeof(pte123_t) * 512);
  // prepare PT
  pte4_t p1_pt[512];
  memset(&p1_pt, 0, sizeof(pte4_t) * 512);
  link_page_table(&p1_pgd[0], &p1_pud[0], &p1_pmd[0], &p1_pt[0], 0, &code_addr);
  // load code to frame 0
  char code[3][MAX_INSTRUCTION_CHAR] = {
      "mov %rsp, 0x7fff1234",
      "mov $1, %rax",
      "mov $2, %rax",
  };

  memcpy((char *)(&pm[0 + code_addr.ppo]), &code, sizeof(char) * 3 * MAX_INSTRUCTION_CHAR);
  // virtual address 0x7fff1234 would trigger page fault
  // Mark all other page_map as allocated
  uint64_t free_ppn = 13;
  pte4_t other_process_pte4[MAX_NUM_PHYSICAL_PAGE];
  for (int i = 1; i < MAX_NUM_PHYSICAL_PAGE; ++i) {
    if (i != free_ppn) {
      map_pte4(&other_process_pte4[i], i);
    }
  }
  // create kernel stacks for trap into kernel
  uint8_t stack_buf[8192 * 2];
  uint64_t p1_stack_bottom = (((uint64_t)&stack_buf[8192]) >> 13) << 13;
  p1.kstack = (kstack_t *)p1_stack_bottom;
  p1.kstack->threadinfo.pcb = &p1;

  // run p1
  tr_global_tss.ESP0 = p1_stack_bottom + KERNEL_STACK_SIZE;

  cpu_controls.cr3 = p1.mm.pgd_paddr;
  idt_init();

  // this should trigger page fault
  for (int i = 0; i < 2; ++i) {
    instruction_cycle();
  }
  printf("\033[32;1m\tPass\033[0m\n");
}

static void TestPageFaultHandlingCase2() {
  cpu_pc.rip = 0x00400000;
  address_t fault_addr = {.address_value = 0x7fff1234};
  address_t code_addr = {.address_value = cpu_pc.rip};

  page_map_init();

  // pcb is need to trigger page fault
  pcb_t p1;
  memset(&p1, 0, sizeof(pcb_t));
  p1.pid = 1;
  p1.next = &p1;
  p1.prev = &p1;

  // prepare PGD
  pte123_t p1_pgd[512];
  memset(&p1_pgd, 0, sizeof(pte123_t) * 512);
  p1.mm.pgd = &p1_pgd[0];
  // prepare PUD
  pte123_t p1_pud[512];
  memset(&p1_pud, 0, sizeof(pte123_t) * 512);
  // prepare PMD
  pte123_t p1_pmd[512];
  memset(&p1_pmd, 0, sizeof(pte123_t) * 512);
  // prepare PT
  pte4_t p1_pt[512];
  memset(&p1_pt, 0, sizeof(pte4_t) * 512);
  link_page_table(&p1_pgd[0], &p1_pud[0], &p1_pmd[0], &p1_pt[0], 0, &code_addr);
  // load code to frame 0
  char code[3][MAX_INSTRUCTION_CHAR] = {
      "mov %rsp, 0x7fff1234",
      "mov $1, %rax",
      "mov $2, %rax",
  };

  memcpy((char *)(&pm[0 + code_addr.ppo]), &code,
         sizeof(char) * 3 * MAX_INSTRUCTION_CHAR);
  // virtual address 0x7fff1234 would trigger page fault
  // Mark all other page_map as allocated
  uint64_t clean_ppn = 7;
  pte4_t other_process_pte4[MAX_NUM_PHYSICAL_PAGE];
  for (int i = 1; i < MAX_NUM_PHYSICAL_PAGE; ++i) {
    map_pte4(&other_process_pte4[i], i);
    if (i != clean_ppn) {
      pagemap_dirty(i);
    }
  }
  // create kernel stacks for trap into kernel
  uint8_t stack_buf[8192 * 2];
  uint64_t p1_stack_bottom = (((uint64_t)&stack_buf[8192]) >> 13) << 13;
  p1.kstack = (kstack_t *)p1_stack_bottom;
  p1.kstack->threadinfo.pcb = &p1;

  // run p1
  tr_global_tss.ESP0 = p1_stack_bottom + KERNEL_STACK_SIZE;

  cpu_controls.cr3 = p1.mm.pgd_paddr;
  idt_init();

  // this should trigger page fault
  for (int i = 0; i < 2; ++i) {
    instruction_cycle();
  }
  printf("\033[32;1m\tPass\033[0m\n");
}

static void TestPageFaultHandlingCase3() {
  cpu_pc.rip = 0x00400000;
  address_t fault_addr = {.address_value = 0x7fff1234};
  address_t code_addr = {.address_value = cpu_pc.rip};

  page_map_init();

  // pcb is need to trigger page fault
  pcb_t p1;
  memset(&p1, 0, sizeof(pcb_t));
  p1.pid = 1;
  p1.next = &p1;
  p1.prev = &p1;

  // prepare PGD
  pte123_t p1_pgd[512];
  memset(&p1_pgd, 0, sizeof(pte123_t) * 512);
  p1.mm.pgd = &p1_pgd[0];
  // prepare PUD
  pte123_t p1_pud[512];
  memset(&p1_pud, 0, sizeof(pte123_t) * 512);
  // prepare PMD
  pte123_t p1_pmd[512];
  memset(&p1_pmd, 0, sizeof(pte123_t) * 512);
  // prepare PT
  pte4_t p1_pt[512];
  memset(&p1_pt, 0, sizeof(pte4_t) * 512);
  link_page_table(&p1_pgd[0], &p1_pud[0], &p1_pmd[0], &p1_pt[0], 0, &code_addr);
  // load code to frame 0
  char code[3][MAX_INSTRUCTION_CHAR] = {
      "mov %rsp, 0x7fff1234",
      "mov $1, %rax",
      "mov $2, %rax",
  };

  memcpy((char *)(&pm[0 + code_addr.ppo]), &code,
         sizeof(char) * 3 * MAX_INSTRUCTION_CHAR);
  // virtual address 0x7fff1234 would trigger page fault
  // Mark all other page_map as allocated
  pte4_t other_process_pte4[MAX_NUM_PHYSICAL_PAGE];
  char filename[128];
  for (int i = 0; i < MAX_NUM_PHYSICAL_PAGE; ++i) {
    if (i > 0) {
      map_pte4(&other_process_pte4[i], i);
      pagemap_dirty(i);
      allocate_swappage(i);
    } else {
      pagemap_dirty(i);
    }
  }

  uint64_t lru_ppn = 14;
  for (int i =0;i < MAX_NUM_PHYSICAL_PAGE;++i) {
    if (i != lru_ppn) {
      pagemap_update_time(i);
    }
  }

  // create kernel stacks for trap into kernel
  uint8_t stack_buf[8192 * 2];
  uint64_t p1_stack_bottom = (((uint64_t)&stack_buf[8192]) >> 13) << 13;
  p1.kstack = (kstack_t *)p1_stack_bottom;
  p1.kstack->threadinfo.pcb = &p1;

  // run p1
  tr_global_tss.ESP0 = p1_stack_bottom + KERNEL_STACK_SIZE;

  cpu_controls.cr3 = p1.mm.pgd_paddr;
  idt_init();

  // this should trigger page fault
  for (int i = 0; i < 2; ++i) {
    instruction_cycle();
  }
  printf("\033[32;1m\tPass\033[0m\n");
}

int main() {
  TestPageFaultHandlingCase1();
  //TestPageFaultHandlingCase2();
  //TestPageFaultHandlingCase3();
  return 0;
}
