#include "mm.h"

.globl memzero

memzero:
    str xzr, [x0], #8
    subs x1, x1, #8
    b.gt memzero
    ret

.globl init_memory
init_memory:
    adr x0, bss_begin       // copy bss_begin to x0
    adr x1, bss_end         //copy bss_end to x1
    sub x1, x1, x0          // x1 = bss_end - bss_begin
    b memzero               // set 0 to bss section
    ret

.globl get_core_id
get_core_id:
    mrs x0, mpidr_el1       // copy system register to generic purpose register
    and x0, x0, #0xFF       // and processor id with 0xff
    ret

.globl init_stack
init_stack:
    mov x1, #STACK_OFFSET   // copy stack offset to x1
    mul x1, x1, x0          // x1 = offset * processor id
    add x1, x1, #LOW_MEMORY // x1 = x1 + LOW_MEMORY
    mov sp, x1              // move stack pointer to LOW_MEMORY (which define in mm.h)
    ret
