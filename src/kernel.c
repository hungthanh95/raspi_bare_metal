#include "uart.h"

void kernel_main(void)
{
    uart_init();
    uart_send_string("Hello from uart, world!\r\n");

    while (1) {
        uart_send(uart_recv());
    }
}
