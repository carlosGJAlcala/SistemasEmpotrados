#include "leon3_uart.h"
#include "leon3_bprint.h"
/*
 La práctica además plantea un ejercicio relacionado
 con la implementación de rutinas auxiliaries empleadas en funciones de formateo y
 redirección de la información hacia un dispositivo de salida (tipo printf).
 */
int main() {
	char * pchar = "cadena\n";
	leon3_print_string(pchar);
	leon3_print_uint8(3);
	leon3_putchar('\n');
	leon3_print_uint8(143);
	leon3_putchar('\n');
	leon3_print_uint16(1080);
	leon3_putchar('\n');
	return 0;
}
