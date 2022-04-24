#include "uart.h"
#define UARTODR *(volatile unsigned int *)((unsigned int *)0x101f1000)


void uart_send_string(unsigned char* ptx_string){

	while(*ptx_string!='\0'){
		UARTODR=(unsigned int)(*ptx_string);
		ptx_string++;
	}

}