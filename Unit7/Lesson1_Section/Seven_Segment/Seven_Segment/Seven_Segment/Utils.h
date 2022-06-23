/*
 * Utils.h
 *
 * Created: 6/23/2022 3:07:39 AM
 *  Author: 101
 */ 


#ifndef UTILS_H_
#define UTILS_H_


#define Sit_Bit(reg,bit) (reg |= (1<<bit))
#define Clear_Bit(reg,bit) (reg &=~ (1<<bit))
#define Toggle_Bit(reg,bit) (reg ^= (1<<bit))
#define Read_Bit(reg,bit) ((reg>>bit)&1)



#endif /* UTILS_H_ */