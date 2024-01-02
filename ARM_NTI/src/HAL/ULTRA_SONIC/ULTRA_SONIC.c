/*
 * ULTRA_SONIC.c
 *
 *  Created on: Dec 9, 2023
 *      Author: lenovo
 */
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"


#include"ULTRASONIC_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/TIMER/TIMER_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"
#include "../../MCAL/NVIC/NVIC_Interface.h"

static volatile u8 flag=0;

static volatile u16 t=0,t1=0,t2=0,d=0;

void ULTRASONIC_Init(void)
{
	TIMER1_ICU1Init();
	TIMER1_ICUSetCallBack(ICU);
	Interrupt_Set_Enable(TIM1_CC);
}

void ULTRASONIC_TRIG(void)
{
	flag=0;
	TIMx_CNT=0;
	GPIO_SetPinValue(PINA1,HIGH);
	SYSTICK_BusyWait_Ms(10);
	GPIO_SetPinValue(PINA1,LOW);
	Timer1_InputCaptureEdge(RISING_TIMER);
	TIMER1_ICU1InterruptEnable();
	while(flag<2);
	SYSTICK_BusyWait_Ms(60);
}
u16 ULTRASONIC_Read(void)
{
	ULTRASONIC_TRIG();
	return d;
}
void ICU(void)
{
	if (flag==0)
	{
		t1=TIMx_CCR1;
		Timer1_InputCaptureEdge(FALLING_TIMER);
		flag=1;
	}
	else if (flag==1)
	{
		t2=TIMx_CCR1;
		t=t2-t1;
		d=t/58;
		TIMER1_ICU1InterruptDisable();
		flag=2;
	}
}
