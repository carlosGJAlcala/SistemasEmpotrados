/*
 * leon3_bprint.c
 *
 *  Created on: 08/03/2021
 *      Author: miguelse
 */

#include "leon3_bprint.h"

int8_t leon3_print_string(char* str){
	do{
		leon3_putchar(*str);
	} while (*str++ != '\0');

	return 0;
}

int8_t leon3_print_uint8(uint8_t i){
	if(i>0){
		int a = (i%10)+48;
		leon3_print_uint8(i /= 10);
		leon3_putchar(a);
	} else{
		return 0;
	}
	return 0;
}

int8_t leon3_print_uint32(uint32_t i){
	int error;
	if(i>0){
		int a = (i%10)+48;
		error = leon3_print_uint8(i /= 10);
		leon3_putchar(a);
	}
	return error;
}
