/*
 * queue.c
 *
 *  Created on: May 22, 2022
 *      Author: Mohamed Adel
 */

#include "queue.h"
QUEUE_STAT QUEUE_init(QUEUE_DATA_TYPE * container,unsigned int len ,QUEUE_BUFFER * buffer){

	if(container){

		buffer->base = container;
		buffer->head = container;
		buffer->tail = container;
		buffer->length = len;
		buffer->count = 0;

		return QUEUE_NO_ERROR;
	}
	else
		return QUEUE_NULL;
}

QUEUE_STAT QUEUE_add(QUEUE_BUFFER *buffer,QUEUE_DATA_TYPE student){

	if(!buffer->base||!buffer->head||!buffer->tail)
		return QUEUE_NULL;
	else if(QUEUE_isFull(buffer) == QUEUE_FULL)
		return QUEUE_FULL;

	else{
		int i;
		QUEUE_DATA_TYPE *temp = buffer->tail;

		for(i = 0; i < buffer->count; i++){
			if(temp->roll == student.roll){
				return QUEUE_ITEM_ID_NOT_UNIQUE;
			}
			temp++;
		}

		*(buffer->head) = student;
		buffer->count++;

		if(buffer->head == ((buffer->base)+((buffer->length)-1)))
			buffer->head = buffer->base;
		else
			(buffer->head)++;

		return QUEUE_NO_ERROR;
	}
}

QUEUE_STAT QUEUE_findByRL(QUEUE_BUFFER *buffer,int rl,QUEUE_DATA_TYPE * pstudent,int objective){

	if(!buffer->base||!buffer->head||!buffer->tail)
		return QUEUE_NULL;
	else if(QUEUE_isEmpty(buffer) == QUEUE_EMPTY)
		return QUEUE_EMPTY;
	else{
		int i, j;
		QUEUE_DATA_TYPE *temp = buffer->tail;
		for(i = 0; i < buffer->count; i++){
			if(rl == temp->roll){
				if(objective == QUEUE_FIND)
					*pstudent = *temp;
				else if(objective == QUEUE_UPDATE)
					*temp = *pstudent;
				else{
					for(j = i; j < buffer->count; j++){
						if(j == buffer->count-1){
							QUEUE_DATA_TYPE null_student = {""};
							*temp = null_student;
						}
						else{
							*temp = *(temp+1);
							temp++;
						}
					}

					buffer->count--;
					if(buffer->head == buffer->base)
						buffer->head = ((buffer->base)+((buffer->length)-1));
					else
						buffer->head--;
				}
				return QUEUE_NO_ERROR;
			}
			temp++;
		}
		return QUEUE_ITEM_NOT_FOUND;
	}

}

QUEUE_STAT QUEUE_findByFName(QUEUE_BUFFER *buffer,char *name,QUEUE_DATA_TYPE * student){

	if(!buffer->base||!buffer->head||!buffer->tail)
		return QUEUE_NULL;
	else if(QUEUE_isEmpty(buffer) == QUEUE_EMPTY)
		return QUEUE_EMPTY;
	else{
		int i, j = 0;
		QUEUE_DATA_TYPE *temp = buffer->tail;
		for(i = 0; i < buffer->count; i++){
			if(!stricmp(name,temp->fname)){
				*(student+j) = *temp;
				j++;
			}
			temp++;
		}
		if(j == 0)
			return QUEUE_ITEM_NOT_FOUND;
		else
			return QUEUE_NO_ERROR;
	}
}

QUEUE_STAT QUEUE_findByCID(QUEUE_BUFFER *buffer,int cid,QUEUE_DATA_TYPE * student){

	if(!buffer->base||!buffer->head||!buffer->tail)
		return QUEUE_NULL;
	else if(QUEUE_isEmpty(buffer) == QUEUE_EMPTY)
		return QUEUE_EMPTY;
	else{
		int i, j = 0, k;
		QUEUE_DATA_TYPE *temp = buffer->tail;
		for(i = 0; i < buffer->count; i++){
			for(k = 0; k < 5; k++){
				if(cid == temp->cid[k]){
					*(student+j) = *temp;
					j++;
				}
			}
			temp++;
		}
		if(j == 0)
			return QUEUE_ITEM_NOT_FOUND;
		else
			return QUEUE_NO_ERROR;
	}
}
void QUEUE_printAll(QUEUE_BUFFER *buffer){

	DPRINTF("--------------------------\n");
	if(!buffer->base||!buffer->head||!buffer->tail){
		DPRINTF("[ERROR] Students database is not yet initialized\n");
	}
	else if(QUEUE_isEmpty(buffer) == QUEUE_EMPTY){
		DPRINTF("[ERROR] Students database is empty \n");
	}
	else{
		int i, j;
		QUEUE_DATA_TYPE * temp = buffer->tail;
		for(i = 0; i < buffer->count; i++){

			DPRINTF("Student first name: %s\n",temp->fname);
			DPRINTF("Student last name: %s\n",temp->lname);
			DPRINTF("Student roll number: %d\n",temp->roll);
			DPRINTF("Student GPA: %.2f\n",temp->gpa);
			for(j = 0; j < 5; j++){
				DPRINTF(" The course ID is: %d\n",temp->cid[j]);
			}
			temp++;
			DPRINTF("--------------------------\n");

		}
	}
}

QUEUE_STAT QUEUE_isFull(QUEUE_BUFFER *buffer){
	if(buffer){
		if(buffer->count == buffer->length)
			return QUEUE_FULL;
		else
			return QUEUE_NO_ERROR;
	}else
		return QUEUE_NULL;
}

QUEUE_STAT QUEUE_isEmpty(QUEUE_BUFFER *buffer){
	if(buffer){
		if(buffer->count == 0)
			return QUEUE_EMPTY;
		else
			return QUEUE_NO_ERROR;
	}else
		return QUEUE_NULL;
}