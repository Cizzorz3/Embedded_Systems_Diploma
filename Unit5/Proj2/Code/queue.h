/*
 * queue.h
 *
 *  Created on: May 22, 2022
 *      Author: Mohamed Adel
 */


#ifndef QUEUE_H_
#define QUEUE_H_

#include "students_database.h"

#define QUEUE_DATA_TYPE struct sinfo
#define QUEUE_FIND 1
#define QUEUE_UPDATE 2
#define QUEUE_DELETE 3

typedef enum {
	QUEUE_NULL,
	QUEUE_EMPTY,
	QUEUE_FULL,
	QUEUE_NO_ERROR,
	QUEUE_ITEM_ID_NOT_UNIQUE,
	QUEUE_ITEM_NOT_FOUND
}QUEUE_STAT;

typedef struct{

	unsigned int length;
	unsigned int count;
	QUEUE_DATA_TYPE *base;
	QUEUE_DATA_TYPE *head;
	QUEUE_DATA_TYPE *tail;

}QUEUE_BUFFER;



QUEUE_STAT QUEUE_init(QUEUE_DATA_TYPE * container,unsigned int len ,QUEUE_BUFFER * buffer);
QUEUE_STAT QUEUE_add(QUEUE_BUFFER *buffer,QUEUE_DATA_TYPE student);
QUEUE_STAT QUEUE_findByRL(QUEUE_BUFFER *buffer,int rl,QUEUE_DATA_TYPE *pstudent,int state);
QUEUE_STAT QUEUE_findByFName(QUEUE_BUFFER *buffer,char *name,QUEUE_DATA_TYPE * student);
QUEUE_STAT QUEUE_findByCID(QUEUE_BUFFER *buffer,int cid,QUEUE_DATA_TYPE * student);
QUEUE_STAT QUEUE_isFull(QUEUE_BUFFER *buffer);
QUEUE_STAT QUEUE_isEmpty(QUEUE_BUFFER *buffer);
void QUEUE_printAll(QUEUE_BUFFER *buffer);
#endif /* QUEUE_H_ */