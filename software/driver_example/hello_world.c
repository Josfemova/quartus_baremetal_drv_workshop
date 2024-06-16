/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */
#include <stdio.h>

#include "uart_driver.h"
#include "system.h"
#include "io.h"

#define UART_CLK 50000000

struct uart16550* uart = (struct uart16550*)UART0_BASE;

int main() {
  //printf("Hello from Nios II!\n");
  uart16550_init(uart, UART_CLK, 115200, UART16550_PARITY_NONE,
                 UART16550_LCR_STB_1BIT, UART16550_LCR_WLS_8BIT_WORD);
  char buffer[20];
  uart16550_read(uart, buffer, 20);
  uart16550_write(uart, buffer, 20);
  printf("Hello from Nios II!\n");
  return 0;
}
