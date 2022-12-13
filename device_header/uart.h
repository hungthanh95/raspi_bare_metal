#ifndef _UART_H
#define _UART_H

#include "base.h"

#define         AUX_ENABLES         (UART_BASE + 0x04)
#define         AUX_MU_IO_REG       (UART_BASE + 0x40)
#define         AUX_MU_IER_REG      (UART_BASE + 0x44)
#define         AUX_MU_IIR_REG      (UART_BASE + 0x48)
#define         AUX_MU_LCR_REG      (UART_BASE + 0x4C)
#define         AUX_MU_MCR_REG      (UART_BASE + 0x50)
#define         AUX_MU_LSR_REG      (UART_BASE + 0x54)
#define         AUX_MU_MSR_REG      (UART_BASE + 0x58)
#define 		AUX_MU_SCRATCH  	(UART_BASE + 0x5C)
#define         AUX_MU_CNTL_REG     (UART_BASE + 0x60)
#define         AUX_MU_STAT_REG     (UART_BASE + 0x64)
#define         AUX_MU_BAUD_REG     (UART_BASE + 0x68)


#endif /* _UART_H */