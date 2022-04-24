/*
 * FIFO.h
 *
 *  Created on: Apr 20, 2022
 *      Author: 101
 */

#ifndef FIFO_H_
#define FIFO_H_
#include"stdio.h"
#include"stdint.h"

//User Config

//Select the element type(uint8_t,uint16_t,uint32_t)
#define element_type uint8_t

//When creating buffer choose
#define width1 5
element_type uart_buffer[width1];


//FIFO datatypes
typedef struct {
	unsigned int length;
	unsigned int count ;
	element_type * base ;
	element_type * head ;
	element_type * tail ;
}FIFO_buffer_t;

typedef enum {
	FIFO_No_Error ,
	FIFO_Null ,
	FIFO_Empty,
	FIFO_Full

}FIFO_buff_status;

//APIS
FIFO_buff_status init_fifo(FIFO_buffer_t *fifo , element_type * buf , element_type length);
FIFO_buff_status enqueue_fifo(FIFO_buffer_t *fifo , element_type item);
FIFO_buff_status dequeue_fifo(FIFO_buffer_t *fifo , element_type* item);
FIFO_buff_status is_FULL_fifo(FIFO_buffer_t *fifo);
void print_fifo(FIFO_buffer_t *fifo);

#endif /* FIFO_H_ */
