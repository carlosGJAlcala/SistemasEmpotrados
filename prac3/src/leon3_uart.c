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
/*
 * Registros de Control de la uart
 0 Receiver Enable
 1 Trasmitter Enable
 2 Receiver  interrupt Enable
 3 Transmitter interrupt enable
 4 Odd parity Enable
 5 Parity enable
 6 Flow control enable
 7 Loop back
 8 External clock
 9 Transmit FIFO  irq ENABLE
 10 Receive FIFO irq enable
 */
//! LEON3 UART A Transmit FIFO is FULL
#define LEON3_UART_TFF 0x200  // Yo lo veo mejor en hexadecimal 0x200
//! LEON3 UART A Transmit FIFO is EMPTY
#define LEON3_UART_TFE 4
struct UART_regs * const pLEON3_UART_REGS = 0x80000100;



#define leon3_UART_TF_IS_FULL() (LEON3_UART_TFF&pLEON3_UART_REGS->Status) // lo tuyo funciona pero con esto es suficiente


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
