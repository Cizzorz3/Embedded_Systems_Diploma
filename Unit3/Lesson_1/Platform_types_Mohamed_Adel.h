/*
 * Platform_types.h

 *
 *  Created on: Mar 16, 2022
 *      Author: MohamedAdel
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#define CPU_TYPE  CPU_TYPE_32
#define CPU_BIT_ORDER MSB_FIRST
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST

#include<stdint.h>
#include<float.h>

//bool

typedef unsigned char boolean ;
//unsigned

typedef uint8_t uint8 ;
typedef uint16_t uint16;
typedef uint32_t uint32;


//signed
typedef int8_t sint8 ;
typedef int16_t sint16;
typedef int32_t sint32;


//least unsigned
typedef uint_least8_t uint8_least ; //at least of 8 bit unsigned
typedef uint_least16_t uint16_least;
typedef uint_least32_t uint32_least ;


//least signed
typedef int_least8_t sint8_least ;
typedef int_least16_t sint16_least;
typedef int_least32_t sint32_least;



// float

typedef float float32 ;
typedef double float64;

//volatile
typedef volatile uint8_t vuint8 ;
typedef volatile int8_t vsint8 ;

typedef volatile uint16_t vuint16;
typedef volatile int16_t vsint16;

typedef volatile uint32_t vuint32;
typedef volatile int32_t vsint32;

















#endif /* PLATFORM_TYPES_H_ */





