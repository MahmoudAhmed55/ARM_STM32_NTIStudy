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


volatile char str[1000]={'0','0'},flag=0,n;
volatile u8 i=0;
void rx(void)
{
	//n=UART_Recieve();
	//if(n=='O' || n=='K' )
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
	UART_Send_String("ATE0\r\n");
	SYSTICK_BusyWait_Ms(10);
	u8 data='A';
	u8 arr[]={'l','e','d','=',data,'\r','\n'};


	while (1)
	{

		UART_Send_String("AT+CIPSTART=\"TCP\",\"185.176.43.108\",80\r\n");
		SYSTICK_BusyWait_Ms(10);
		UART_Send_String("AT+CIPSEND=142\r\n");
		SYSTICK_BusyWait_Ms(10);
		UART_Send_String("POST /script.php HTTP/1.1\r\n");
		SYSTICK_BusyWait_Ms(10);
		UART_Send_String("Host: ntigreaters.scienceontheweb.net\r\n");
		SYSTICK_BusyWait_Ms(10);
		UART_Send_String("Content-Type: application/x-www-form-urlencoded\r\n");
		SYSTICK_BusyWait_Ms(10);
		UART_Send_String("Content-Length: 6\r\n");
		SYSTICK_BusyWait_Ms(10);
		UART_Send_String("\r\n");
		SYSTICK_BusyWait_Ms(10);
		UART_Send_String("led=0\r\n");
		SYSTICK_BusyWait_Ms(10);
		UART_Send_String("AT+CIPCLOSE\r\n");
		SYSTICK_BusyWait_Ms(10);



		UART_Send_String("AT+CIPSTART=\"TCP\",\"185.176.43.108\",80\r\n");
		SYSTICK_BusyWait_Ms(100);
		UART_Send_String("AT+CIPSEND=55\r\n");
		SYSTICK_BusyWait_Ms(100);
		UART_Send_String("GET http://ntigreaters.scienceontheweb.net/status.txt\r\n");
		i=0;
		SYSTICK_BusyWait_Ms(100);

		if (str[37]=='0')
		{
			GPIO_SetPinValue(PINB0,HIGH);
			GPIO_SetPinValue(PINB1,LOW);
			GPIO_SetPinValue(PINB5,LOW);
			GPIO_SetPinValue(PINB6,LOW);
		}
		else if (str[37]=='1')
		{
			GPIO_SetPinValue(PINB0,LOW);
			GPIO_SetPinValue(PINB1,HIGH);
			GPIO_SetPinValue(PINB5,LOW);
			GPIO_SetPinValue(PINB6,LOW);
		}
		else if (str[37]=='2')
		{
			GPIO_SetPinValue(PINB0,LOW);
			GPIO_SetPinValue(PINB1,LOW);
			GPIO_SetPinValue(PINB5,HIGH);
			GPIO_SetPinValue(PINB6,LOW);
		}
		else if (str[37]=='3')
		{
			GPIO_SetPinValue(PINB0,LOW);
			GPIO_SetPinValue(PINB1,LOW);
			GPIO_SetPinValue(PINB5,LOW);
			GPIO_SetPinValue(PINB6,HIGH);
		}
	}


}


