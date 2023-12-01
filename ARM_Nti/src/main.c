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
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/TIMER/TIMER_Services.h"
#include "MCAL/UART/UART_Interface.h"


void main(void)
{
	//__enable_irq();
	RCC_InitClockSystem();
	//RCC_EnableClock(APB2,AFIO_EN);
	RCC_EnableClock(APB2,IOPA);
	RCC_EnableClock(APB2,IOPB);
	RCC_EnableClock(APB2,IOPC);
	RCC_EnableClock(APB2,USART);

u8 x='a';
	DIO_Init();
	//LCD_Init();
	UART_Init();
	SYSTICK_Init();
	UART_Transmit('0');


	while (1)
	{

		if (UART_Recieve()=='1')
		{
			GPIO_SetPinValue(PINA2,HIGH);
			GPIO_SetPinValue(PINA0,HIGH);
			GPIO_SetPinValue(PINA1,HIGH);
			GPIO_SetPinValue(PINA3,HIGH);
			UART_Transmit('A');
		}
		else if (UART_Recieve()=='2')
		{
			GPIO_SetPinValue(PINA2,LOW);
			GPIO_SetPinValue(PINA0,LOW);
			GPIO_SetPinValue(PINA1,LOW);
			GPIO_SetPinValue(PINA3,LOW);

		}


	}
}




