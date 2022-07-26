/*
 * STM32_F103_C6_RCC.h
 *
 *  Created on: Jul 16, 2022
 *      Author: Mohamed Adel
 */

#ifndef INC_STM32_F103_C6_RCC_H_
#define INC_STM32_F103_C6_RCC_H_

#include "STM32f103C6.h"
#include "STM_F103C6_GPIO_Driver.h"

uint32_t MCAL_RCC_GetSysCLK_Freq(void);
uint32_t MCAL_RCC_GetHCLK_Freq(void);
uint32_t MCAL_RCC_GetPCLK1_Freq(void);
uint32_t MCAL_RCC_GetPCLK2_Freq(void);

#define HSI_RC_CLk  (uint32_t)8000000
#define HSE_clk		(uint32_t)16000000

#endif /* INC_STM32_F103_C6_RCC_H_ */
