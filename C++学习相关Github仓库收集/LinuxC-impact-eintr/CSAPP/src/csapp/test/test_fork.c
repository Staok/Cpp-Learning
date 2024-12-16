#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/algorithm.h"
#include "../headers/common.h"
#include "../headers/cpu.h"
#include "../headers/memory.h"
#include "../headers/instruction.h"
#include "../headers/interrupt.h"
#include "../headers/address.h"
#include "../headers/memory.h"
#include "../headers/process.h"
#include "../headers/color.h"

void map_pte4(pte4_t *pte, uint64_t ppn);
void unmap_pte4(uint64_t ppn);
void page_map_init();
pte123_t *get_pagetableentry(pte123_t *pgd, address_t *vaddr, int level,
                             int allocate);

static void link_page_table(pte123_t *pgd, pte123_t *pud, pte123_t *pmd,
                            pte4_t *pt, int ppn, address_t *vaddr) {

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

static void TestFork() {
  // init state
  cpu_pc.rip = 0x00400000;
  cpu_reg.rsp = 0x7ffffffee0f0;

  address_t code_addr = {.address_value = cpu_pc.rip};
  address_t stack_addr = {.address_value = cpu_reg.rsp};

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

  // prepare user mode stack frame
  pte123_t p1_pud_stack[512];
  pte123_t p1_pmd_stack[512];
  pte4_t p1_pt_stack[512];
  memset(&p1_pud_stack, 0, sizeof(pte123_t) * 512);
  memset(&p1_pmd_stack, 0, sizeof(pte123_t) * 512);
  memset(&p1_pt_stack, 0, sizeof(pte4_t) * 512);
  link_page_table(&p1_pgd[0], &p1_pud_stack[0], &p1_pmd_stack[0],
                  &p1_pt_stack[0], 1, &stack_addr);

  // create kernel stacks for trap into kernel
  kstack_t *stack_buf = aligned_alloc(KERNEL_STACK_SIZE, KERNEL_STACK_SIZE);
  uint64_t p1_stack_bottom = (uint64_t)stack_buf;
  p1.kstack = stack_buf;
  p1.kstack->threadinfo.pcb = &p1;

  // run p1
  tr_global_tss.ESP0 = p1_stack_bottom + KERNEL_STACK_SIZE;

  cpu_controls.cr3 = p1.mm.pgd_paddr;
  idt_init();
  syscall_init();

  // load code to frame 0
  char code[22][MAX_INSTRUCTION_CHAR] = {
    // set PID = 0;
    "mov    $0x0,%rbx",     // 0x00400000
    // fork
    "mov    $0x39, %rax",
    "int    $0x80",
    // check fork result to detect parent or child
    "mov    %rax,%rbx",
    "cmpq   $0x0,%rbx",
    // not returns 0, then parent process
    "jne    $0x00400380",
    // child LOOP: print child
    "movq   $0x0a646c696863, %rbx",   // 0x00400180
    "pushq  %rbx",
    "movq   $1, %rax",
    "movq   $1, %rdi",
    "movq   %rsp, %rsi",
    "movq   $6, %rdx",
    "int    $0x80",
    "jmp    $0x00400200",
    // LOOP: parent
    // parent LOOP: print parent
    "movq   $0x0a746e65726170, %rbx", // 0x00400380
    "pushq  %rbx",
    "movq   $1, %rax",
    "movq   $1, %rdi",
    "movq   %rsp, %rsi",
    "movq   $7, %rdx",
    "int    $0x80",
    "jmp    $0x00400400",
  };
  memcpy(
    (char *)(&pm[0]),
    &code, sizeof(char) * 22 * MAX_INSTRUCTION_CHAR);

  // this should trigger page fault
  for (int i = 0; i < 30; ++i)
  {
    instruction_cycle();
  }

  printf(GREENSTR("\tPass\n"));
}


static void TestFork_cow() {
  // init state
  cpu_pc.rip = 0x00400000;
  cpu_reg.rsp = 0x7ffffffee0f0;

  address_t code_addr = {.address_value = cpu_pc.rip};
  address_t stack_addr = {.address_value = cpu_reg.rsp};

  page_map_init();

  // pcb is need to trigger page fault
  pcb_t p1;
  memset(&p1, 0, sizeof(pcb_t));
  p1.pid = 1;
  p1.next = &p1;
  p1.prev = &p1;

  // prepare vm areas instead of page tables
  // The memory loading should build the page tables from the vm areas
  vm_area_t vmas[2] = {
      // vm area for .text section
      {.vma_start = 0x00400000,
       .vma_end = 0x00401000,
       .vma_mode.read = 1,
       .vma_mode.write = 0,
       .vma_mode.execute = 1,
       .vma_mode.private = 1,
       .filepath = "~/fork"},
      // vm area for stack
      {.vma_start = ((cpu_reg.rsp) >> 12) << 12,
       .vma_end = (((cpu_reg.rsp) >> 12) + 1) << 12,
       .vma_mode.read = 1,
       .vma_mode.write = 1,
       .vma_mode.execute = 0,
       .vma_mode.private = 1,
       .filepath = "[stack]"},
  };

  vma_add_area(&p1, &vmas[0]);
  vma_add_area(&p1, &vmas[1]);
  setup_pagetable_from_vma(&p1); // 这里将会为第一个进程创建page table

    // load code to frame 0
  char code[22][MAX_INSTRUCTION_CHAR] = {
      // set PID = 0;
      "mov    $0x0,%rbx", // 0x00400000
      // fork
      "mov    $0x39, %rax",
      "int    $0x80",
      // check fork result to detect parent or child
      "mov    %rax,%rbx",
      "cmpq   $0x0,%rbx",
      // not returns 0, then parent process
      "jne    $0x00400380",
      // child LOOP: print child
      "movq   $0x0a646c696863, %rbx", // 0x00400180
      "pushq  %rbx",
      "movq   $1, %rax",
      "movq   $1, %rdi",
      "movq   %rsp, %rsi",
      "movq   $6, %rdx",
      "int    $0x80",
      "jmp    $0x00400200",
      // LOOP: parent
      // parent LOOP: print parent
      "movq   $0x0a746e65726170, %rbx", // 0x00400380
      "pushq  %rbx",
      "movq   $1, %rax",
      "movq   $1, %rdi",
      "movq   %rsp, %rsi",
      "movq   $7, %rdx",
      "int    $0x80",
      "jmp    $0x00400400",
  };
  uint64_t code_ppn = (uint64_t)(((pte4_t *)get_pagetableentry(
                    p1.mm.pgd, &code_addr, 4, 0))->ppn);
  memcpy((char *)(&pm[code_ppn]), &code,
         sizeof(char) * 22 * MAX_INSTRUCTION_CHAR);

  // create kernel stacks for trap into kernel
  kstack_t *stack_buf = aligned_alloc(KERNEL_STACK_SIZE, KERNEL_STACK_SIZE);
  uint64_t p1_stack_bottom = (uint64_t)stack_buf;
  p1.kstack = stack_buf;
  p1.kstack->threadinfo.pcb = &p1;

  // run p1
  tr_global_tss.ESP0 = p1_stack_bottom + KERNEL_STACK_SIZE;

  cpu_controls.cr3 = p1.mm.pgd_paddr;
  idt_init();
  syscall_init();

  // this should trigger page fault
  for (int i = 0; i < 500; ++i)
  {
    instruction_cycle();
  }

  printf(GREENSTR("\tPass\n"));
}

int main() {
  heap_init();
  TestFork_cow();
  return 0;
}
