/*
 * Utils.h
 *
 * Created: 8/17/2022 2:51:36 AM
 *  Author: Mohamed Adel
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define Read_Bit(reg,bit) ((reg>>bit)&1)
#define Set_Bit(reg,bit) (reg |= (1<<bit))
#define Clear_Bit(reg,bit) (reg &=~ (1<<bit))
#define Toggle_Bit(reg,bit) (reg ^= (1<<bit))
#define Read_Bit(reg,bit) ((reg>>bit)&1)

typedef unsigned char* *P_uint8_t;
typedef  char* *P_sint8_t;

typedef void(*PTR_VoidFUN)(void);

#define NULL_PTR	((void*)(0))

typedef enum
{
	Ok ,
	Error
}E_Status;
#endif /* UTILS_H_ */