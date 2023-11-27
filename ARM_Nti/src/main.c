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

static volatile u32 t1=0,t2=0,flag=0,c1=0;
volatile u32 time=0,d=0;

void UP(void)
{
	c1++;
}

void Func_ICU1(void)
{
	TIMx_SR=0;
	if (flag==0)
	{
		t1=TIMx_CCR1;
		Timer1_InputCaptureEdge(FALLING_TIMER);
		flag=1;
	}
	else if (flag==1)
	{
		t2=TIMx_CCR1;
		flag=2;
		time=t2-t1;
		d=time/58;
		TIMER1_ICU1InterruptDisable();
	}

}

void main(void)
{
	volatile u16 d=0;
	//__enable_irq();
	RCC_InitClockSystem();
	RCC_EnableClock(APB2,AFIO_EN);
	RCC_EnableClock(APB2,IOPA);
	RCC_EnableClock(APB2,IOPB);
	RCC_EnableClock(APB2,IOPC);
	RCC_EnableClock(APB2,TIM1);

	TIMER1_Init();
	DIO_Init();
	SYSTICK_Init();
	LCD_Init();
	EXI_Init();

	/*EXI_Disable(LN0);
	AFIO_EXI_Config(LIN0,PA_S);
	Interrupt_Set_Enable(EXTI0);
	EXI_SetCallBack(Func_ICU1);*/

	TIMER1_ICU1Init();
	TIMER1_ICUSetCallBack(Func_ICU1);
	Interrupt_Set_Enable(TIM1_CC);

	TIMER1_AutoReload(0xffff);
	/*TIMER1_InterruptEnable();
	Interrupt_Set_Enable(TIM1_UP);
	TIMER1_SetCallBack(UP);*/

	LCD_GoTo(0,0);
	LCD_WriteString("ULTRASONIC");

	/*u32 freq=0;
	u8 duty=0;*/



	while (1)
	{
		flag=0;
		TIMx_CNT=0;
		GPIO_SetPinValue(PINA7,HIGH);
		SYSTICK_BusyWait_Us(10);
		GPIO_SetPinValue(PINA7,LOW);
		Timer1_InputCaptureEdge(RISING_TIMER);
		TIMER1_ICU1InterruptEnable();
		while(flag<2);
		if (d>=30)
		{
			GPIO_TogPin(PINB3);
		}
		else if (d<30)
		{
			GPIO_TogPin(PINB4);
		}
		else
		{
			GPIO_SetPinValue(PINB5,HIGH);
		}

		SYSTICK_BusyWait_Ms(200);

		/*LCD_GoTo(1,0);
		LCD_WriteString("                   ");
		LCD_GoTo(1,0);
		LCD_WriteString("DISTANCE=");
		LCD_WriteNumber(t2-t1);
		SYSTICK_BusyWait_Ms(200);*/


	}
}





