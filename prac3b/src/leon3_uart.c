#include "leon3_uart.h"
//Estructura de datos que permite acceder a los registros de la
//UART de LEON3
struct UART_regs {
	/** \brief UART Data Register */
	volatile uint32_t Data; /* 0x80000100 */
	/** \brief UART Status Register */
	volatile uint32_t Status; /* 0x80000104 */
	/** \brief UART Control Register */
	volatile uint32_t Ctrl; /* 0x80000108 */
	/** \brief UART Scaler Register */
	volatile uint32_t Scaler; /* 0x8000010C */
};

//! LEON3 UART A Transmit FIFO is FULL
#define LEON3_UART_TFF 256
//! LEON3 UART A Transmit FIFO is EMPTY
#define LEON3_UART_TFE 4

#define LEON3_UART_RE 1

#define LEON3_UART_RIE 8

struct UART_regs * const pLEON3_UART_REGS = 0x80000100;

#define leon3_UART_TF_IS_FULL()((((pLEON3_UART_REGS->Status )& LEON3_UART_TFF )!=0)? 1 :0)

int8_t leon3_putchar(char c) {

	uint32_t write_timeout = 0;

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

	int8_t resultado =((((pLEON3_UART_REGS->Status )& LEON3_UART_TFE )!=0)? 1 :0);
	return resultado;
}
//codigo practica 3b
char leon3_getchar() {
	char resultado = 0;
	resultado = pLEON3_UART_REGS->Data;
	return resultado;
}
/*pone a 1 el campo Receiver_enable
 del registro de control de la UART-A sin modificar el resto de campos
 de ese registro habilitando la recepción de datos a través de la UART.
 (Ver la figura siguiente para ubicar la posición del campo).
 */
void leon3_uart_ctrl_rx_enable() {
	pLEON3_UART_REGS->Status |= LEON3_UART_RE;
}
/*
 * leon3_uart_ctrl_rx_irq_enable pone a 1 el campo
 Receiver_interrupt_enable del registro de control de la UART-A sin
 modificar el resto de campos de ese registro habilitando las
 interrupciones tras la recepción de datos a través de la UART. (Ver la
 figura siguiente para ubicar la posición del campo).
 */

void leon3_uart_ctrl_rx_irq_enable() {
	pLEON3_UART_REGS->Status |= LEON3_UART_RIE;

}
void leon3_uart_ctrl_config_rxtx_loop(int8_t set_rxtxloop) {
	pLEON3_UART_REGS->Status |= set_rxtxloop<<7;

}
