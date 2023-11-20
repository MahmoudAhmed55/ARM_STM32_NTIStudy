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


static volatile u16 t1=0,t2=0,t3=0,flag=0;

// private function
void PWM_Measure(u32* Pfreq,u8* Pduty,u32 timeout)
{
	u16 Ton,Toff;
	u32 c=0;
	TIMx_CCR1=0;
	TIMER1_ICUSetCallBack(Func_ICU);
	Timer1_InputCaptureEdge(RISING_TIMER);
	TIMER1_InterruptEnable();
	flag=0;
	while((flag<3)&&(c<timeout))
	{
		c++;
		//_delay_us(1);
	}
   if (flag==3)
   {
	  Ton=t2-t1;//+c*65535
	  Toff=t3-t2;

	  *Pduty=((u32)Ton*100)/((u32)Ton+Toff);
	  *Pfreq=(u32)1000000/((u32)Toff+Ton);
   }
   else
   {
	   *Pfreq=0;
	   if (GPIO_GetPinValue(PINB6)==LOW)
	   {
		   *Pduty=0;
	   }
	   else
	   {
		   *Pduty=100;
	   }
   }
}
static void Func_ICU(void)
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
		Timer1_InputCaptureEdge(RISING_TIMER);
		flag=2;
	}
	else if (flag==2)
	{
		t3=TIMx_CCR1;
		TIMER1_InterruptDisable();
		flag=3;

	}

}

