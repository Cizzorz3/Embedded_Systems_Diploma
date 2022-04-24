/*
 *  LIFO.C
 *
 *  Created on: Apr 19, 2022
 *      Author: Mohamed Adel
 */

#include"LIFO.h"
// To Push an item to the LIFO (Pass the LIFO you want the element to be added to , the value of item)
LIFO_Status Add_item (LIFO_BUFF_t *Lifo_buffer , unsigned int item){

	//check if the LIFO is valid
	if( !Lifo_buffer->base  || !Lifo_buffer->head){
		printf("LIFO is NULL \n");
		return LIFO_NULL ;
	}
	//check if the LIFO is not FULL
	if(Lifo_buffer->length == Lifo_buffer->count){
		printf("LIFO is FULL \n");
		return LIFO_FULL ;
	}
	//Push a value
	*(Lifo_buffer->head) = item ;
	Lifo_buffer->head++;
	Lifo_buffer->count++;

	return LIFO_NO_ERROR ;
}
// To POP an item to the LIFO (Pass the LIFO you want the element to be pop , the value of item)
LIFO_Status Get_item (LIFO_BUFF_t *Lifo_buffer , unsigned int *item){

	//check if the lifo is valid
	if( !Lifo_buffer->base  || !Lifo_buffer->head)
		return LIFO_NULL ;

	//check of the lifo is empty
	if(Lifo_buffer->count ==0)
		return LIFO_EMPTY ;

	(Lifo_buffer->head)--;
	*item=*(Lifo_buffer->head);
	Lifo_buffer->count--;
	return LIFO_NO_ERROR ;

}
// To init a LIFO (Pass the LIFO you want to initiallize  , the value of buffer , the length of buffer)
LIFO_Status init_LIFO (LIFO_BUFF_t *Lifo_buffer , unsigned int *buf, unsigned int length){

	//check if the value sent from the buf is not NULL (The size of heap is not enough it will return NUll)
	if( buf==NULL )
		return LIFO_NULL ;



	Lifo_buffer->base = buf ;
	Lifo_buffer->head = buf ;
	Lifo_buffer->length = length ;
	Lifo_buffer->count = 0;





	return LIFO_NO_ERROR ;

}
