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
#include "MCAL/TIMER/TIMER_INTERFACE.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "HAL/ESP/ESP_Interface.h"

#include "HAL/ULTRASONIC/ULTRASONIC_SENSOR_INTERFACE.h"

//volatile char str[100]={'0'};
//volatile u8 i=0;
//
///*void rx(void)
//{
//	str[i]=UART_Recieve();
//	i++;
//}*/
//volatile u16 t1=0,t2=0,flag=0,t=0,d=0;
//void EXI0(void)
//{
//	if (flag==0)
//	{
//		EXI_SignalLatch(LN0,FALLING);
//		t1=TIMx_CNT;
//		flag = 1;
//	}
//	else if (flag==1)
//	{
//		t2=TIMx_CNT;
//		flag = 0;
//		//EXI_Disable(LN0);
//	}
//
//}
//void main(void)
//{
//	//__enable_irq();
//	RCC_InitClockSystem();
//	RCC_EnableClock(APB2,AFIO_EN);
//	RCC_EnableClock(APB2,IOPA);
//	RCC_EnableClock(APB2,IOPB);
//	RCC_EnableClock(APB2,IOPC);
//	RCC_EnableClock(APB2,USART);
//	RCC_EnableClock(APB2,TIM1);
//
//	Interrupt_Set_Enable(EXTI0);
//
//	DIO_Init();
//	LCD_Init();
//	//UART_Init();
//	SYSTICK_Init();
//	TIMER1_Init();
//	TIMER1_AutoReload(0xffff);
//	EXI_Init();
//
//	AFIO_EXI_Config(LIN0,PA_S);
//	EXI_SetCallBack(EXI0);
//	/*UART_RX_SetCallBack(rx);
//	Interrupt_Set_Enable(USART1);
//	UART_RX_InterruptEnable();*/
//
//
//	while (1)
//	{
//		flag=0;
//		TIMx_CNT=0;
//		EXI_SignalLatch(LN0,RISING);
//		EXI_Enable(LN0);
//		GPIO_SetPinValue(PINA1,HIGH);
//		SYSTICK_BusyWait_Us(10);
//		GPIO_SetPinValue(PINA1,LOW);
//
//		//while (flag<2);
//		t=t2-t1;
//		d=t/58;
//		//d=d/10;
//		//d=20;
//		//SYSTICK_BusyWait_Ms(60);
//		if (d<20)
//		{
//			GPIO_SetPinValue(PINB0,HIGH);
//		}
//		else
//		{
//			GPIO_SetPinValue(PINB1,HIGH);
//		}
//	}
//}
//
//
///*if (x=='0')
//{
//	GPIO_SetPinValue(PINB0,HIGH);
//	GPIO_SetPinValue(PINB1,LOW);
//	GPIO_SetPinValue(PINB5,LOW);
//	GPIO_SetPinValue(PINB6,LOW);
//}
//else if (x=='1')
//{
//	GPIO_SetPinValue(PINB0,LOW);
//	GPIO_SetPinValue(PINB1,HIGH);
//	GPIO_SetPinValue(PINB5,LOW);
//	GPIO_SetPinValue(PINB6,LOW);
//}
//else if (x=='2')
//{
//	GPIO_SetPinValue(PINB0,LOW);
//	GPIO_SetPinValue(PINB1,LOW);
//	GPIO_SetPinValue(PINB5,HIGH);
//	GPIO_SetPinValue(PINB6,LOW);
//}
//else if (x=='5')
//{
//	GPIO_SetPinValue(PINB0,LOW);
//	GPIO_SetPinValue(PINB1,LOW);
//	GPIO_SetPinValue(PINB5,LOW);
//	GPIO_SetPinValue(PINB6,HIGH);
//}
// */

void main(void)
{
	u32 Distance[4] = { 0 };
	HULTRASONIC_SENSOR_voidInit();
	GPIO_SetPinDirection(PA , PINA4, OUTPUT10KHZ_PUSHPALL);
	while(1)
	{
		HULTRASONIC_SENSOR_voidCalculateDistance(Distance);
		if(Distance[0] < 10)
		{
			GPIO_SetPinValue(PINA4 , 1);
		}
		else
		{
			GPIO_SetPinValue(PINA4 , 0);
		}

	}
}




