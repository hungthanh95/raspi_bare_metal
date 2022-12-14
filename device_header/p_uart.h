#ifndef _P_UART_H
#define _P_UART_H

#include "p_base.h"

#define         AUX_ENABLES         (MINI_UART_BASE + 0x04)
#define         AUX_MU_IO_REG       (MINI_UART_BASE + 0x40)
#define         AUX_MU_IER_REG      (MINI_UART_BASE + 0x44)
#define         AUX_MU_IIR_REG      (MINI_UART_BASE + 0x48)
#define         AUX_MU_LCR_REG      (MINI_UART_BASE + 0x4C)
#define         AUX_MU_MCR_REG      (MINI_UART_BASE + 0x50)
#define         AUX_MU_LSR_REG      (MINI_UART_BASE + 0x54)
#define         AUX_MU_MSR_REG      (MINI_UART_BASE + 0x58)
#define 		AUX_MU_SCRATCH  	(MINI_UART_BASE + 0x5C)
#define         AUX_MU_CNTL_REG     (MINI_UART_BASE + 0x60)
#define         AUX_MU_STAT_REG     (MINI_UART_BASE + 0x64)
#define         AUX_MU_BAUD_REG     (MINI_UART_BASE + 0x68)


#define         UART_DR             (UART_BASE + 0x0)
#define         UART_RSRECR         (UART_BASE + 0x4)
#define         UART_FR             (UART_BASE + 0x18)
#define         UART_IBRD           (UART_BASE + 0x24)
#define         UART_FBRD           (UART_BASE + 0x28)
#define         UART_LCRH           (UART_BASE + 0x2c)
#define         UART_CR             (UART_BASE + 0x30)


#endif /* _UART_H */