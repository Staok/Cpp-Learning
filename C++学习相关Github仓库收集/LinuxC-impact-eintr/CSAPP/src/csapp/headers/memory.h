#ifndef MEMORY_H_
#define MEMORY_H_

#include <stdint.h>

#define PHYSICAL_MEMORY_SPACE (65536)
#define MAX_NUM_PHYSICAL_PAGE (16)

#define PAGE_TABLE_ENTRY_NUM (512)
#define PAGE_SIZE (4096)

extern uint8_t pm[PHYSICAL_MEMORY_SPACE];

// page table struct

// PGD PUD PMD Level 1 2 3 Page Table Entry
typedef union {
  uint64_t pte_value;
  struct {
    uint64_t present : 1;
    uint64_t readonly : 1;
    uint64_t usermode : 1;
    uint64_t writethough : 1;
    uint64_t cachedisabled : 1;
    uint64_t reference : 1;
    uint64_t unused6 : 1;
    uint64_t smallpage : 1;
    uint64_t global : 1;
    uint64_t unused9_11 : 3;
    uint64_t paddr : 50; // virtua; address (48 bits) pn simulator't heap
    uint64_t xdisabled : 1;
  };
  struct {
    uint64_t _present :1;
    uint64_t saddr :63; // swap space address
  };
} pte123_t; // 8 bytes = 64bits

// PT
typedef union {
  uint64_t pte_value;
  struct {
    uint64_t present : 1; // present = 1
    uint64_t readonly : 1;
    uint64_t usermode : 1;
    uint64_t writethough : 1;
    uint64_t cachedisabled : 1;
    uint64_t reference : 1;
    uint64_t dirty : 1; // dirty bit - 1: dirty; 0: clean
    uint64_t zero7 : 1;
    uint64_t global : 1;
    uint64_t unused9_11 : 3;
    uint64_t ppn : 40;
    uint64_t unused52_62 : 10;
    uint64_t xdisabled : 1;
  };
  struct {
    uint64_t _present : 1; // present = 1
    uint64_t saddr : 63;   // swap space address
  };
} pte4_t; // 8 bytes = 64bits

/*======================================*/
/*      memory R/W                      */
/*======================================*/

// used by instructions: use virtual address
uint64_t virtual_read_data(uint64_t vaddr);
void virtual_write_data(uint64_t vaddr, uint64_t data);
void virtual_read_inst(uint64_t vaddr, char *buf);
void virtual_write_inst(uint64_t vaddr, const char *str);

// used by instructions: read or write uint8_t to DRAM
uint8_t cpu_read8bits_dram(uint64_t paddr);
void cpu_write8bits_dram(uint64_t paddr, uint8_t data);
// used by instructions: read or write uint64_t to DRAM
uint64_t cpu_read64bits_dram(uint64_t paddr);
void cpu_write64bits_dram(uint64_t paddr, uint64_t data);
void cpu_readinst_dram(uint64_t paddr, char *buf);
void cpu_writeinst_dram(uint64_t paddr, const char *str);

void bus_read_cacheline(uint64_t paddr, uint8_t *block);
void bus_write_cacheline(uint64_t paddr, uint8_t *block);
#endif // MEMORY_H_
