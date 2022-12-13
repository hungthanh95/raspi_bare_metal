#include "mm.h"

.section ".text.boot"

.globl _start

_start:
    mrs x0, mpidr_el1   // copy system register to generic purpose register
    and x0, x0,#0xFF    // and processor id with 0xff
    cbz x0, master      // enter master function if process id = 0
    b proc_hang

proc_hang:
    b proc_hang

master:
    adr x0, bss_begin   // copy bss_begin to x0
    adr x1, bss_end     //copy bss_end to x1
    sub x1, x1, x0      // x1 = bss_end - bss_begin
    bl memzero          // set 0 to bss section

    mov sp, #LOW_MEMORY    // move stack pointer to LOW_MEMORY (which define in mm.h)
    bl kernel_main      // enter to main fumction
    b proc_hang