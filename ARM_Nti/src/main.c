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
#include "MCAL/TIMER/TIMER_Services.h"

volatile u32 t1=0,t2=0,flag=0,c1=0;

/*void up(void)
{
	c1++;
}*/

void Func_ICU1(void)
{
	TIMx_SR=0;
	/*CLR_BIT(TIMx_SR,CC1IF);
	CLR_BIT(TIMx_SR,9);*/
	TIMER1_ICU1InterruptDisable();
	if (flag==0)
	{
		t1=TIMx_CCR1;
		flag=1;
		Timer1_InputCaptureEdge(FALLING_TIMER);
		GPIO_SetPinValue(PINB3,HIGH);
	}

	else if (flag==1)
	{
		t2=TIMx_CCR1;
		flag=2;
		GPIO_SetPinValue(PINB4,HIGH);
		TIMER1_ICU1InterruptDisable();
	}

}

void main(void)
{
	//__enable_irq();

	RCC_InitClockSystem();
	RCC_EnableClock(APB2,IOPA);
	RCC_EnableClock(APB2,IOPB);
	RCC_EnableClock(APB2,IOPC);
	RCC_EnableClock(APB2,TIM1);

	TIMER1_Init();
	TIMER1_ICU1Init();
	DIO_Init();
	SYSTICK_Init();
	LCD_Init();
	TIMER1_AutoReload(0xffff);
	Interrupt_Set_Enable(TIM1_CC);
	//Interrupt_Set_Enable(TIM1_UP);
	TIMER1_ICUSetCallBack(Func_ICU1);
	//TIMER1_SetCallBack(up);

	LCD_GoTo(0,0);
	LCD_WriteString("ULTRASONIC");
	u32 freq=0;
	u8 duty=0;
	u8 d=0;
	u16 time=0;
	while (1)
	{
		//TIMER1_Init();
		//TIMER1_ICU1Init();
		//TIMER1_AutoReload(0xffff);
		//Timer1_InputCaptureEdge(RISING_TIMER);
		//TIMER1_ICUSetCallBack(Func_ICU1);
		GPIO_SetPinValue(PINA7,HIGH);
		SYSTICK_BusyWait_Us(30);
		GPIO_SetPinValue(PINA7,LOW);
		flag=0;
		TIMx_CNT=0;
		TIMER1_ICU1InterruptEnable();
		while(flag<2)
		{
			TIMER1_ICU1InterruptEnable();
		}
		TIMER1_ICU1InterruptDisable();
		LCD_GoTo(2,0);
		LCD_WriteString("t1=");
		LCD_WriteNumber(t1);
		LCD_GoTo(3,0);
		LCD_WriteString("t2=");
		LCD_WriteNumber(t2);
		time=t2-t1;
		d=time/58;
		LCD_GoTo(1,0);
		LCD_WriteString("DISTANCE=");
		LCD_WriteNumber(d);
		SYSTICK_BusyWait_Ms(200);


		/* PWM_Measure(&freq,&duty,(u32)1000);
		        LCD_GoTo(1,0);
				LCD_WriteString("freq=");
				LCD_WriteNumber(freq);
				LCD_GoTo(2,0);
				LCD_WriteString("duty=");
				LCD_WriteNumber(duty);*/
	}
}





