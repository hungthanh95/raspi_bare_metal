#include "utils.h"
#include "uart.h"
#include "p_uart.h"
#include "p_gpio.h"

void uart_init ( unsigned int baud )
{
    unsigned int selector;

    selector = get32(GPFSEL1);
    selector &= ~(7<<12);                   // clean gpio14
    selector |= 4<<12;                      // set alt0 for gpio14
    selector &= ~(7<<15);                   // clean gpio15
    selector |= 4<<15;                      // set alt0 for gpio 15
    put32(GPFSEL1, selector);

    put32(GPPUD, 0);
    delay(150);
    put32(GPPUDCLK0, (1<<14)|(1<<15));
    delay(150);
    put32(GPPUDCLK0, 0);

    // calculate integer and fractional
    // 64 * UART_CLK / (16 * BAUDRATE) = 4 * UARTLCK / BAUDRATE
    unsigned int div = 4 * UART_REF_CLK / baud;
    put32(UART_IBRD, ((div >> 6) & 0xffff));
    put32(UART_FBRD, (div & 0x3f));

    // set WLEN
    put32(UART_LCRH, (0x3 << 5));

    //Finally, enable transmitter and receiver
    put32(UART_CR, (1u << 9) | (1u << 8) | 1u);
}

void uart_send ( char c )
{
    // while until transmit FIFO can accept at least one bytes
	while(get32(UART_FR) & (1 << 5)) {};
    // send one byte
	put32(UART_DR, c);
}

char uart_recv ( void )
{
    // loop until receive FIFO holds at least 1 symbol
	while(get32(UART_FR) & (1 << 4)) {};
    // read one byte
	return(get32(UART_DR)&0xFF);
}

void uart_send_string(char* str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		uart_send((char)str[i]);
	}
}
