#include "leon3_uart.h"

//! LEON3 UART A Transmit FIFO is FULL
#define LEON3_UART_TFF() (0x200)

//Estructura de datos que permite acceder a los registros de la
//UART de LEON3
struct UART_regs
{
	/** \brief UART Data Register */
	volatile uint32_t Data; /* 0x80000100 */
	/** \brief UART Status Register */
	volatile uint32_t Status; /* 0x80000104 */
	/** \brief UART Control Register */
	volatile uint32_t Ctrl; /* 0x80000108 */
	/** \brief UART Scaler Register */
	volatile uint32_t Scaler; /* 0x8000010C */
};

struct UART_regs * pLEON3_UART_REGS= 0x80000100;

#define leon3_UART_TF_IS_FULL() (pLEON3_UART_REGS->Status & LEON3_UART_TFF())

int8_t leon3_putchar(char c)
{
	uint32_t write_timeout=0;
	while(leon3_UART_TF_IS_FULL()&&(write_timeout < 0xAAAAA)){
		write_timeout++;
	} //Espera mientras la cola de transmisión esté llena
	if(write_timeout < 0xAAAAA){
		pLEON3_UART_REGS->Data = c;
	}
	return (write_timeout == 0xAAAAA);
}

char leon3_getchar(){
	return (pLEON3_UART_REGS->Data);
}

uint8_t leon3_UART_TF_IS_EMPTY(){
	if(((pLEON3_UART_REGS->Status) & 4) == 4){
		return 1;
	}
	return 0;
}

void leon3_UART_RX_ENABLE(){
	(pLEON3_UART_REGS->Ctrl) = (pLEON3_UART_REGS->Ctrl) | 1;
}

void leon3_UART_RX_IRQ_ENABLE(){
	(pLEON3_UART_REGS->Ctrl) = (pLEON3_UART_REGS->Ctrl) | 4;
}

void leon3_UART_ConfigRXTXLoop(uint8_t set_rxtxloop){
	if(set_rxtxloop == 1){
		(pLEON3_UART_REGS->Ctrl) = (pLEON3_UART_REGS->Ctrl) | 128;
	}else if(set_rxtxloop == 0){
		(pLEON3_UART_REGS->Ctrl) = (pLEON3_UART_REGS->Ctrl) & (~128);
	}
	//Si set_rxtxloop != (0||1) entonces no hace nada
}


