#ifndef _UART_H
#define _UART_H

#include "kernel.h"

void uart_init ( unsigned int baud );
char uart_recv ( void );
void uart_send (char c);
void uart_send_string(char* str);

#endif /* _UART_H*/