/*
 * Main.c
 *
 *  Created on: Apr 19, 2022
 *      Author: Mohamed Adel
 */

#include "LIFO.h"
#include "LIFO.C"


unsigned int static_buffer[5];

void main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int i , temp=0;
	LIFO_BUFF_t uart_LIFO , I2c_LIFO ;
	init_LIFO(&uart_LIFO , static_buffer , 5);
	unsigned int * dynamic_buffer = (unsigned int *)malloc(5*sizeof(unsigned int));
	init_LIFO(&I2c_LIFO ,dynamic_buffer,5 );

	for(i=0 ;i<5;i++){
		if (  Add_item(&uart_LIFO , i)  == LIFO_NO_ERROR)
			printf("The Added LIFO UART Element is : %d \n",i);
	}
	for(i=0 ;i<5;i++){
		if (Get_item(&uart_LIFO , &temp) == LIFO_NO_ERROR)
			printf("The Returned LIFO UART Element is : %d \n",temp);
	 }
}

