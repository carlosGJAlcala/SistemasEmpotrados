#ifndef LEON3_UART_H_
#define LEON3_UART_H_
#include "rtems_osswr/leon3_types.h"
int8_t leon3_putchar(char c);

char leon3_getchar();

uint8_t leon3_UART_TF_IS_EMPTY();

void leon3_UART_RX_ENABLE();
void leon3_UART_RX_IRQ_ENABLE();
void leon3_UART_ConfigRXTXLoop(uint8_t set_rxtxloop);
#endif /* LEON3_UART_H_*/


