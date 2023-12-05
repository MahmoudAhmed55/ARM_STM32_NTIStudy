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
#include "HAL/ESP/ESP_Interface.h"


volatile char str[100]={'0'};
volatile u8 i=0;
void rx(void)
{
	str[i]=UART_Recieve();
	i++;
}

void main(void)
{
	//__enable_irq();
	RCC_InitClockSystem();
	//RCC_EnableClock(APB2,AFIO_EN);
	RCC_EnableClock(APB2,IOPA);
	RCC_EnableClock(APB2,IOPB);
	RCC_EnableClock(APB2,IOPC);
	RCC_EnableClock(APB2,USART);

	DIO_Init();
	LCD_Init();
	UART_Init();
	SYSTICK_Init();
	UART_RX_SetCallBack(rx);
	Interrupt_Set_Enable(USART1);
	UART_RX_InterruptEnable();
	ESP_Init();
	u8 x=0;
	while (1)
	{
		x=ESP_Get();

		if (x=='0')
		{
			GPIO_SetPinValue(PINB0,HIGH);
			GPIO_SetPinValue(PINB1,LOW);
			GPIO_SetPinValue(PINB5,LOW);
			GPIO_SetPinValue(PINB6,LOW);
		}
		else if (x=='1')
		{
			GPIO_SetPinValue(PINB0,LOW);
			GPIO_SetPinValue(PINB1,HIGH);
			GPIO_SetPinValue(PINB5,LOW);
			GPIO_SetPinValue(PINB6,LOW);
		}
		else if (x=='2')
		{
			GPIO_SetPinValue(PINB0,LOW);
			GPIO_SetPinValue(PINB1,LOW);
			GPIO_SetPinValue(PINB5,HIGH);
			GPIO_SetPinValue(PINB6,LOW);
		}
		else if (x=='3')
		{
			GPIO_SetPinValue(PINB0,LOW);
			GPIO_SetPinValue(PINB1,LOW);
			GPIO_SetPinValue(PINB5,LOW);
			GPIO_SetPinValue(PINB6,HIGH);
		}
	}


}


