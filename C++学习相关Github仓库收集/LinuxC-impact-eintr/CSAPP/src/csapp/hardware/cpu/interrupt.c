#include <assert.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "../../headers/color.h"
#include "../../headers/interrupt.h"
#include "../../headers/process.h"

tss_s0_t tr_global_tss;
jmp_buf USER_INSTRUCTION_ON_IRET;

typedef void (*interrupt_handler_t)();

// the entry of IDT/IVT
// kernel mode. So ensure that the kernel stack is empty now
typedef struct IDT_ENTRY_STRUCT
{
  interrupt_handler_t handler;
} idt_entry_t;

// Interrupt Descriptor/Vector Table
idt_entry_t idt[256];

// handlers of IDT
void pagefault_handler(); // trap gate - exception
void syscall_handler();   // trap gate - software interrupt / trap
void timer_handler();     // interrupt gate - local APIC

// implementation of hanlers
void do_syscall(int syscall_no);
void fix_pagefault();
void os_schedule();

// initialize od IDT
void idt_init() {
  idt[0x0e].handler = pagefault_handler;
  idt[0x80].handler = syscall_handler;
  idt[0x81].handler = timer_handler;
}

static void print_kstack();

// get the high vaddr of kstack from TSS
uint64_t get_kstack_top_TSS() {
  uint64_t ks = tr_global_tss.ESP0;
  assert(ks % KERNEL_STACK_SIZE == 0);
  return ks;
}

uint64_t get_kstack_RSP() { return (((cpu_reg.rsp) >> 13) << 13); }

// TRAP FRAME IS PART OF HARDWARE's CONCERN
//
// 8191 +------------+ RSP from TSS when interrupt begin
//      | Trap Frame |
//      +------------+ RSP after trap
//      | User Frame |
//      +------------+
//      |            |
//      | Used By    |
//      | Kernel Func|
//      |            |
//      +------------+
//      | Tread Info |
//    0 +------------+

static uint64_t hardware_push_trapframe(trapframe_t *tf) {
  // 1.  Get the current RSP value. The value is a VIRTUAL address.
  //     This virtual address points to the kernel stack top.
  //     This virtual address comes from TSS of the process in DRAM.
  //     The kernel stack is allocated on PCB creation, and stored
  //     to TSS in DRAM when the process is switched to.
  //     This function is only invoked when trap from user mode to
  uint64_t rsp = cpu_reg.rsp;
  assert(rsp == get_kstack_top_TSS());

  // 2.  Push the prepared trapframe to kernel stack
  uint32_t tf_size = sizeof(trapframe_t);
  assert(tf_size < KERNEL_STACK_SIZE);
  rsp -= tf_size;
  memcpy((trapframe_t *)rsp, tf, tf_size);
  //printf("tf->rip: %lx tf->rsp: %lx cpu_reg.rsp: %lx\n", tf->rip, tf->rsp, rsp+tf_size);

  // 3.  Update RSP
  cpu_reg.rsp = rsp;

  return cpu_reg.rsp;
}

// This function simulates the implementation of CPU hardware
// it's part of CPU's interrupt return
static void hardware_pop_trapframe() {
  // Trap frame should be at the very top of kernel stack
  // since it's from kernel mode back to user mode
  uint32_t tf_size = sizeof(trapframe_t);
  assert(tf_size < KERNEL_STACK_SIZE);

  // get the starting address of trap frame
  // which is the user thread context
  uint64_t rsp = cpu_reg.rsp;
  assert((rsp + tf_size) == get_kstack_top_TSS());

  // restore the trap frame
  // tf is holding the user thread context
  trapframe_t tf;
  memcpy(&tf, (trapframe_t *)rsp, tf_size);

  // pop trap frame
  rsp += tf_size;
  cpu_reg.rsp = rsp;
  // Restore the CS and EIP registerrs top their values prior to the interrupt or exception
  cpu_pc.rip = tf.rip;
  // Restores the EFLAGS register.
  // Restore the SS and ESP registerrs top their values prior to the interrupt or exception
  cpu_reg.rsp = tf.rsp;
}

// USER FRAME IS PART OF OS/SOFTWARE's CONCERN
//
// 8191 +-------------+
//      | Trap Frame  |
//      +-------------+ RSP from TSS when interrupt begin
//      | User Frame  |
//      +-------------+ RSP after the first assemley lines of interrupt handler
//      |             |
//      | Used By     |
//      | Kernel Func |
//      |             |
//      +-------------+
//      | Tread Info  |
//    0 +-------------+


static void software_push_userframe() {
  // check the size
  uint32_t uf_size = sizeof(userframe_t);
  uint32_t tf_size = sizeof(trapframe_t);
  assert(tf_size < KERNEL_STACK_SIZE);
  assert(uf_size < KERNEL_STACK_SIZE - sizeof(trapframe_t));

  // get the vaddr of stack low
  uint64_t rsp  = cpu_reg.rsp;
  assert((rsp + tf_size) == get_kstack_top_TSS());

  // stroe user frame to kstack
  rsp -= uf_size;
  userframe_t uf = {
    .regs = cpu_reg,
    .flags = cpu_flags
  };
  memcpy((userframe_t *)rsp, &uf, uf_size);
  // push RSP
  cpu_reg.rsp = rsp;
}

static void software_pop_userframe() {
  // check the size
  uint32_t uf_size = sizeof(userframe_t);
  uint32_t tf_size = sizeof(trapframe_t);
  assert(tf_size < KERNEL_STACK_SIZE);
  assert(uf_size < KERNEL_STACK_SIZE - sizeof(trapframe_t));

  // get the vaddr of stack low
  uint64_t rsp  = cpu_reg.rsp;
  assert((rsp + tf_size + uf_size) == get_kstack_top_TSS());

  // restore user frame from kstack
  userframe_t uf;
  memcpy(&uf, (trapframe_t *)rsp, uf_size);
  rsp += uf_size;

  // restore cpu registers from user frame
  memcpy(&cpu_reg, &uf.regs, sizeof(cpu_reg));
  memcpy(&cpu_flags, &uf.flags, sizeof(cpu_flags));

  // pop rsp
  cpu_reg.rsp = rsp;
}

// call interrupt with stack switching user -> kernel
void interrupt_stack_switching(uint64_t int_vec) {
  assert(0 <= int_vec && int_vec <= 255);
  // 1.  Temorarily saves (internally) the current contents of
  //     the SS, RSP, EFLAGS, CS, and EIP registers.
  trapframe_t tf = {
    .rip = cpu_pc.rip,
    .rsp = cpu_reg.rsp
  };

  //printf("int_vec:%lx tf.rip: %lx tf.rsp: %lx\n", int_vec, tf.rip, tf.rsp);
  // 2.  Loads the segment selector and stack pointer for the new stack
  //     (that is, the stack for the privilege level(特权级) begin called)
  //     from the TSS into the SS and ESP registers and switchrs to the new stack
  // stack switch
  // this kstack is allocated in the heap of emulator
  cpu_reg.rsp = get_kstack_top_TSS();
  // 3.  Pushes the temporarily saved SS, ESP, EFLAGS, CS, and EIP values
  //     for the interrupted procedure's stack onto the new stack
  hardware_push_trapframe(&tf);
  // 4.  Pushes an error code on the new stack (if appropriate).
  // 5.  Loads the segment selector for the new code segment and
  //     the new instruction pointer (from the interrupt gate or trap gate)
  //     into the CS and EIP registers, respectively.
  interrupt_handler_t handler = idt[int_vec].handler;

  // 6.  If the call is through an interrupt gete
  //     clears the IF flag in the EFLAGS register.
  // 7.  Begins execution of the handler procedure at the new privilege level
  cpu_pc.rip = (uint64_t)&handler; // rip should be kernel handler starting address
  handler(); // in this func ,we will call os_schedule() so process changed after call

  // interrupt return IRET
  interrupt_return_stack_switching();

  // This function (longjmp) will not return
  // The longjmp will move to the instruction sycle of the newly scheduled process
  // This interrupt_stack_switching will not return to the old process (invoker)
  longjmp(USER_INSTRUCTION_ON_IRET, 1);
}

// interrupt return with stack switching (kernel --> user)
void interrupt_return_stack_switching() {
  hardware_pop_trapframe();
}

// interrupt handlers

void timer_handler() {
  printf(GREENSTR("Timer interrupt to invoke OS scheduling\n"));
  software_push_userframe(); // p1
  os_schedule();
  // After 'os_schedule', rip is running on another process.
  // Though the kernel code part does not change, but PCB,
  // page table, kernel stack are all new.
  // So the user frame restored here is for the new scheduled process.
  software_pop_userframe(); // maybe p2
}

void pagefault_handler() {
  printf(GREENSTR("Page fault handling\n"));
  software_push_userframe();
  fix_pagefault();
  os_schedule();
  software_pop_userframe();
}

void syscall_handler() {
  printf(GREENSTR("Invoking system call [%lx]\n"), cpu_reg.rax);

  // push user general registers to kernel stack
  // to save the context of user thread
  software_push_userframe();

  // TRICK: rsp should not be stored here
  // but we need to simulate kernel stack push & pop.
  // So this is the vaddr of RSP when `do_syscall` returns
  uint64_t rsp_after_do_syscall = cpu_reg.rsp;
  // The following instructions are executed in the
  // left space in the kernel stack
  do_syscall(cpu_reg.rax);
  cpu_reg.rsp = rsp_after_do_syscall;

  // after the task of syscall
  // OS schedules to another process
  os_schedule();

  // recover user registers of new scheduled process
  software_pop_userframe();
}

static void print_kstack() {
  uint64_t kstack_bottom_vaddr = get_kstack_RSP();
  uint64_t kstack_top_vaddr = kstack_bottom_vaddr + KERNEL_STACK_SIZE;
  if (kstack_bottom_vaddr == 0) {
    // trap frame
    printf("=====\nTrap frame: 0x%016lx\n", 0l);
    printf("RIP: %016lx\nRSP: %016lx\n", 0l, 0l);

    // user frame
    printf("=====\nUser frame: 0x%016lx\n", 0l);
    printf("RAX: %016lx\n"
           "RBX: %016lx\n"
           "RCX: %016lx\n"
           "RDX: %016lx\n"
           "RSI: %016lx\n"
           "RDI: %016lx\n"
           "RBP: %016lx\n"
           "RSP: %016lx\n"
           "CF: %d\tZF: %d\tSF: %d\tOF: %d\n",
           0l, 0l, 0l, 0l, 0l, 0l, 0l, 0l, 0, 0, 0, 0);
    return;
  }

  uint64_t tfa = kstack_top_vaddr - sizeof(trapframe_t);
  uint64_t ufa = tfa - sizeof(userframe_t);

  pcb_t *pcb = get_current_pcb();
  assert(pcb != NULL);

  // general info
  printf("Kernel stack info [PID = %ld]\n"
         "top vaddr:\t0x%016lx\n"
         "bottom vaddr:\t0x%016lx\n"
         "RSP now:\t0x%016lx\n"
         "RIP now:\t0x%016lx\n",
         pcb->pid, kstack_top_vaddr, kstack_bottom_vaddr, cpu_reg.rsp,
         cpu_pc.rip);

  // whole stack
  int size64 = sizeof(uint64_t);
  int num64 = KERNEL_STACK_SIZE / size64;
  int n_cols = 8;
  uint64_t base = kstack_top_vaddr - size64;
  for (int r = 0; r < 3; ++r) {
    printf("[%16lx]  ", base);

    for (int c = 0; c < n_cols; ++c) {
      uint64_t val64 = *(uint64_t *)base;

      if (tfa <= base) {
        // print trap frame green
        printf(""GREENSTR("%16lx  ")"", val64);
      } else if (ufa <= base) {
        // print user frame yellow
        printf(""YELLOWSTR("%16lx  ")"", val64);
      } else {
        printf("%16lx  ", val64);
      }
      base -= size64;
    }

    printf("\n");
  }
  // trap frame
  printf("=====\nTrap frame: 0x%016lx\n", tfa);
  trapframe_t *tf = (trapframe_t *)tfa;
  printf("RIP: %016lx\nRSP: %016lx\n", tf->rip, tf->rsp);

  // user frame
  printf("=====\nUser frame: 0x%016lx\n", ufa);
  userframe_t *uf = (userframe_t *)ufa;
  printf("RAX: %016lx\n"
         "RBX: %016lx\n"
         "RCX: %016lx\n"
         "RDX: %016lx\n"
         "RSI: %016lx\n"
         "RDI: %016lx\n"
         "RBP: %016lx\n"
         "RSP: %016lx\n"
         "CF: %d\tZF: %d\tSF: %d\tOF: %d\n",
         uf->regs.rax, uf->regs.rbx, uf->regs.rcx, uf->regs.rdx, uf->regs.rsi,
         uf->regs.rdi, uf->regs.rbp, uf->regs.rsp, uf->flags.CF, uf->flags.ZF,
         uf->flags.SF, uf->flags.OF);
}
