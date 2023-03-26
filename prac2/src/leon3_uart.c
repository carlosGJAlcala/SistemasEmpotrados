#include "leon3_uart.h"
//Estructura de datos que permite acceder a los registros de la
//UART de LEON3
struct UART_regs {
	/** \brief UART Data Register */
	/*
	 * El de data se utiliza tanto para rx y tx
	 */
	volatile uint32_t Data; /* 0x80000100 */
	/** \brief UART Status Register */
	volatile uint32_t Status; /* 0x80000104 */
	/** \brief UART Control Register */
	volatile uint32_t Ctrl; /* 0x80000108 */
	/** \brief UART Scaler Register */
	volatile uint32_t Scaler; /* 0x8000010C */
};

//! LEON3 UART A Transmit FIFO is FULL
#define LEON3_UART_TFF 512
//! LEON3 UART A Transmit FIFO is EMPTY
#define LEON3_UART_TFE 4
struct UART_regs * const pLEON3_UART_REGS = 0x80000100;

#define leon3_UART_TF_IS_FULL()((((pLEON3_UART_REGS->Status )& LEON3_UART_TFF )!=0)? 1 :0)
/*
 Los registros de estados son:
 0-Data Ready
1-Transmit Shift Register Empty
2-Transmit FIFO empty
3-Break
4-Overrun
5-Parity Error
6-Framing Error
7-Transmit FIFO half full
8-Receive FIFO half full
9-Transmit FIFO full
10-Receive FIFO full
20-Transmit FIFO count
26-Receive FIFO count
 */

int8_t leon3_putchar(char c) {

	uint32_t write_timeout = 0;
	/*
	 Recordad que para que una
	 caracter pueda insertarse en la cola de transmisión es necesario que el bit que se hace
	 visible al aplicar la máscara LEON3_UART_TFF NO esté a 1,
	 */
	while (leon3_UART_TF_IS_FULL() && (write_timeout < 0xAAAAA)) {
		write_timeout++;

	} //Espera mientras la cola de transmisión esté llena
	if (write_timeout < 0xAAAAA) {
		//COMPLETAR. Escribir el carácter en el registro Data
		pLEON3_UART_REGS->Data = c;
	}
	return (write_timeout == 0xAAAAA);
}
int8_t leon3_uart_tx_fifo_is_empty() {
	//COMPLETAR

	int8_t resultado = (
			(((pLEON3_UART_REGS->Status) & LEON3_UART_TFE) != 0) ? 1 : 0);
	return resultado;
}
