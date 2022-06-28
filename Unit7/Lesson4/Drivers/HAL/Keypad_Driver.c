/*
 * Keypad_Driver.c
 *
 * Created: 6/24/2022 10:57:40 AM
 *  Author: Mohamed Adel 
 */ 
#include "Keypad_Driver.h"

int keypad_rows[] = {R0,R1,R2,R3};
int keypad_cols[] = {C0,C1,C2,C3};


void keypad_init()
{
	//setting all the rows as input
	//	Keypad_PORT_Dir &=~ (1<<R0) | (1<<R1) | (1<<R2) | (1<<R3);
	//	Keypad_PORT_Dir |= (1<<C0) | (1<<C1) | (1<<C2) | (1<<C3);
	//	//All pins VCC
	//	Keypad_PORT = 0xff;
	GPIO_Pinconfig_t PinCfg;

	PinCfg.GPIO_Pin_Number =R0 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	PinCfg.GPIO_Pin_Number =R1 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	PinCfg.GPIO_Pin_Number =R2 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	PinCfg.GPIO_Pin_Number =R3 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	PinCfg.GPIO_Pin_Number =C0 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	PinCfg.GPIO_Pin_Number =C1 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	PinCfg.GPIO_Pin_Number =C2 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	PinCfg.GPIO_Pin_Number =C3 ;
	PinCfg.GPIO_Pin_Mode = GPIO_output_push_pull_Mode ;
	PinCfg.GPIO_Pin_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	MCAL_GPIO_WritePort(GPIOB, 0xFF);
}

char keyoad_getchar()
{
	int i , j ;
	for(i=0;i<=3;i++)
	{
		MCAL_GPIO_WritePin(GPIOB, keypad_cols[0], GPIO_Pin_SET);
		MCAL_GPIO_WritePin(GPIOB, keypad_cols[1], GPIO_Pin_SET);
		MCAL_GPIO_WritePin(GPIOB, keypad_cols[2], GPIO_Pin_SET);
		MCAL_GPIO_WritePin(GPIOB, keypad_cols[3], GPIO_Pin_SET);
		MCAL_GPIO_WritePin(GPIOB, keypad_cols[i], GPIO_Pin_Reset);
		for(j=0;j<=3;j++)
		{
			if(MCAL_GPIO_ReadPin(GPIOB, keypad_rows[j])==0)
			{
				while(MCAL_GPIO_ReadPin(GPIOB, keypad_rows[j])==0);
				switch(i)
				{
				case(0):
										if(j==0) return '7';
										else if(j==1) return '4';
										else if(j==2) return '1';
										else if(j==3) return '!';
				break;
				case(1):
										if(j==0) return '8';
										else if(j==1) return '5';
										else if(j==2) return '2';
										else if(j==3) return '0';
				break;
				case(2):
										if(j==0) return '9';
										else if(j==1) return '6';
										else if(j==2) return '3';
										else if(j==3) return '0';
				break;
				case(3):
										if(j==0) return '/';
										else if(j==1) return '*';
										else if(j==2) return '-';
										else if(j==3) return '+';
				break;
				}
			}
		}
	}
	return 'A';

}
