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
#include "MCAL/EXI_Interrupt/EXI_Interrupt_Interface.h"
#include "MCAL/AFIO/AFIO_Interface.h"
#include "MCAL/TIMER/TIMER_Interface.h"

void EXI0(void)
{
	GPIO_TogPin(PINA0);
}

void TIMER1_IRQ_Callback(void)
{

	GPIO_TogPin(PINA0);

}
void main(void)
{
	RCC_InitClockSystem();
	RCC_EnableClock(APB2,TIM1);
	RCC_EnableClock(APB2,IOPA);
	RCC_EnableClock(APB2,IOPB);
	RCC_EnableClock(APB2,IOPC);
	RCC_EnableClock(APB2,TIM1);
	DIO_Init();
	TIMER_Init();
	Interrupt_Set_Enable(TIM1_UP);
	TIMER_InterruptEnable();
	TIMER1_SetCallBack(TIMER1_IRQ_Callback);
	Interrupt_Set_Enable(EXTI0);

	EXI_SetCallBack(EXI0);

	/*
	Interrupt_Set_Pending(TIM1_UP);
u16 i,j;*/
	while (1)
	{
		/*Interrupt_Set_Pending(EXTI0);

		for (i=0;i<1000;i++)
		{
			for (j=0;j<1000;j++)
			{

			}
		}*/


	}
}




/*void SysTick_Handler(void)
{

}*/


