/*
 * main.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mahmoud Ahmed Ismail
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"

#include "MCAL/RCC/RCC_Interface.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "MCAL/NVIC/NVIC_Interface.h"
#include "MCAL/SYSTICK/SYSTICK_Interface.h"
#include "MCAL/EXI_Interrupt/EXI_Interrupt_Interface.h"
#include "MCAL/AFIO/AFIO_Interface.h"
#include "MCAL/TIMER/TIMER_Interface.h"
#include "MCAL/LCD/LCD_Interface.h"



void main(void)
{
	RCC_InitClockSystem();
	RCC_EnableClock(APB2,IOPA);
	RCC_EnableClock(APB2,TIM1);
	DIO_Init();
	TIMER1_Init();
    SYSTICK_Init();
	//SYSTICK_Init();
	LCD_Init();

	/*LCD_GoTo(0,0);
	LCD_WriteString("ICU");
 u16 x=0;*/
	while (1)
	{
		/*LCD_WriteNumber(x);
		SYSTICK_BusyWait_Ms(1000);
		x++;*/
		GPIO_TogPin(PINA0);
		SYSTICK_BusyWait_Ms(1);
	}
}





