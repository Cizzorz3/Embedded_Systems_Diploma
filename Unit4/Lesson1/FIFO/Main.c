/*
 * Main.c
 *
 *  Created on: Apr 20, 2022
 *      Author: 101
 */

#include "FIFO.h"
void main(){
	element_type i , temp = 0;
	FIFO_buffer_t FIFO_uart ;
	if(init_fifo(&FIFO_uart,uart_buffer,5)== FIFO_No_Error)
		printf("FIFO init is done \n");

	for(i=0;i<7;i++){
		printf("FIFO Enqueue %x \n",i);
		if(enqueue_fifo(&FIFO_uart,i)==FIFO_No_Error)
			printf("FIFO Enqueue is done \n");
		else
			printf("FIFO Enqueue Failed \n");
	}
	print_fifo(&FIFO_uart);

	if(dequeue_fifo(&FIFO_uart,&temp)==FIFO_No_Error)
		printf("FIFO dequeue %x is done \n",temp);
	if(dequeue_fifo(&FIFO_uart,&temp)==FIFO_No_Error)
		printf("FIFO dequeue %x is done \n",temp);

	print_fifo(&FIFO_uart);



}
