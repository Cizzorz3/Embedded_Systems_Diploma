/*
 * FIFO.c
 *
 *  Created on: Apr 20, 2022
 *      Author: 101
 */
#include "FIFO.h"
FIFO_buff_status init_fifo(FIFO_buffer_t *fifo , element_type * buf , element_type length){
	if(buf==NULL)
		return FIFO_Null ;

	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->count = 0 ;
	return FIFO_No_Error ;
}
FIFO_buff_status enqueue_fifo(FIFO_buffer_t *fifo , element_type item){
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null ;
	if (is_FULL_fifo(fifo) == FIFO_Full)
		return FIFO_Full ;

	*(fifo->head) = item ;
	fifo->count++;

	//circuilar fifo
	if(fifo->head == (fifo->base + fifo->length * sizeof(element_type)))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_No_Error ;


}
FIFO_buff_status dequeue_fifo(FIFO_buffer_t *fifo , element_type* item){
	if(!fifo->base || !fifo->head || !fifo->tail)
			return FIFO_Null ;

	//check if fifo is empty
	if(fifo->count==0)
		return FIFO_Empty ;
	*item = *(fifo->tail);
	fifo->count--;
	if(fifo->tail == (fifo->base + fifo->length * sizeof(element_type)))
			fifo->tail = fifo->base;
		else
			fifo->tail++;
	return FIFO_No_Error ;

}
FIFO_buff_status is_FULL_fifo(FIFO_buffer_t *fifo){
	if(!fifo->base || !fifo->head || !fifo->tail)
			return FIFO_Null ;
	if(fifo->count == fifo->length)
		return FIFO_Full ;
	return FIFO_No_Error ;

}
void print_fifo(FIFO_buffer_t *fifo){
	element_type * temp ;
	int i ;
	if(fifo->count==0){
		printf("FIFO is empty \n");
	}
	else {
		temp=fifo->tail;
		printf("FIFO print \n");
		for(i=0;i<fifo->count;i++){
			printf("%x \n",*temp);
			temp++;
		}
	}

}
