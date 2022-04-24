/*
 * LIFO.h
 *
 *  Created on: Apr 19, 2022
 *      Author: Mohamed Adel
 */



#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
#include "stdlib.h"
// type definitions
typedef struct {
	unsigned int  length ;
	unsigned int count ;
	unsigned int *base ;
	unsigned int *head ;

}LIFO_BUFF_t;



//APIS
typedef enum {
	LIFO_NO_ERROR ,
	LIFO_FULL ,
	LIFO_NULL ,
	LIFO_EMPTY
}LIFO_Status;

// To Push an item to the LIFO (Pass the LIFO you want the element to be added to , the value of item)
LIFO_Status Add_item (LIFO_BUFF_t *Lifo_buffer , unsigned int item);
// To POP an item to the LIFO (Pass the LIFO you want the element to be pop , the value of item)
LIFO_Status Get_item (LIFO_BUFF_t *Lifo_buffer , unsigned int *item);
// To init a LIFO (Pass the LIFO you want to initiallize  , the value of buffer , the length of buffer)
LIFO_Status init_LIFO (LIFO_BUFF_t *Lifo_buffer , unsigned int *buf, unsigned int length);



#endif /* LIFO_H_ */
