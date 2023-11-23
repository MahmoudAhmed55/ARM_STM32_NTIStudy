/*
 * TIMER_Services.c
 *
 *  Created on: Nov 18, 2023
 *      Author: lenovo
 */
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "TIMER_Services.h"
#include "TIMER_Interface.h"
#include "TIMER_Services.h"
#include "TIMER_Private.h"
#include "../GPIO/GPIO_Interface.h"
#include "../SYSTICK/SYSTICK_Interface.h"
#include "../LCD/LCD_Interface.h"
#include "TIMER_Private.h"
static volatile u32 t1=0,t2=0,t3=0,flag=0,c1=0;

void PWM_Measure(u32* Pfreq,u8* Pduty,u32 time)
{
	u16 Ton,Toff;
	u32 c=0;
	TIMx_CNT=0;
	TIMER1_ICU1InterruptEnable();
	TIMER1_ICUSetCallBack(Func_ICU);
	Timer1_InputCaptureEdge(RISING_TIMER);
	while(time>c)
	{
		c++;
		TIMER1_ICU1InterruptEnable();

		if (flag==3)
		   {
			   flag=0;
			  Ton=t2-(t1+(c1*65535));
			  Toff=t3-t2;
			  *Pduty=((u32)Ton*100)/((u32)Ton+Toff);
			  *Pfreq=(u32)1000000/((u32)Toff+Ton);
			  GPIO_SetPinValue(PINB6,HIGH);
			  c1=0;
		   }
		  else
		   {
			   *Pfreq=0;
			   if (GPIO_GetPinValue(PINA8)==LOW)
			   {
				   *Pduty=0;
			   }
			   else
			   {
				   *Pduty=100;
			   }
		   }
		}
	}

 void Func_ICU(void)
{
	if (flag==0)
	{
		t1=TIMx_CCR1;
		Timer1_InputCaptureEdge(FALLING_TIMER);
		flag=1;
		GPIO_SetPinValue(PINB3,HIGH);
		TIMER1_ICU1InterruptEnable();
	}
	else if (flag==1)
	{
		t2=TIMx_CCR1;
		Timer1_InputCaptureEdge(RISING_TIMER);
		flag=2;
		GPIO_SetPinValue(PINB4,HIGH);
		TIMER1_ICU1InterruptEnable();
	}
	else if (flag==2)
	{
		t3=TIMx_CCR1;
		flag=3;
		GPIO_SetPinValue(PINB5,HIGH);
		TIMER1_ICU1InterruptDisable();
	}
}

