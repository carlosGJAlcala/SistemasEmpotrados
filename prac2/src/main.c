#include "leon3_uart.h"
int main() {
	int i = 0;
	char aux = '0';
	for (i = 0; i < 10; i++) {
		leon3_putchar(aux);
		leon3_putchar('\n');
		aux++;
	}
	while (!leon3_uart_tx_fifo_is_empty());
	printf(aux);
	return 0;
}

