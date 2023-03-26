#include "leon3_uart.h"
/*
 En esta practica se configura el funcionamiento de un driver, para ello hay que saber como funciona el controlador
 aquí utilizamos espera activa para esperar que se mande los caracteres, si no queremos esto tenemos que usar interrupciones
 */
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

