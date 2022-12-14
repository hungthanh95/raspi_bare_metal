#include "kernel.h"
#include "mini_uart.h"
#include "utils.h"

void kernel_main(unsigned int core_id)
{
    if (core_id == 0) {
        mini_uart_init(115200);
    } else {
        delay(300000 * core_id);
    }

    mini_uart_send_string("Hello world from #");
    mini_uart_send(core_id + '0');
    mini_uart_send_string(" Core.\r\n");

    while (1) {
        if (core_id == 0) {
            mini_uart_send(mini_uart_recv());
        } else {
            /* Do nothing */
        }
    }
}
