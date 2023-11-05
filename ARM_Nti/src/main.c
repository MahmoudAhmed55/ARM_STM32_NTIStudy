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

void main(void)
{
	RCC_InitClockSystem();
	RCC_EnableClock(APB2,IOPA);
	GPIO_SetPinDirection(PA,PIN0,OUTPUT10KHZ_PUSHPALL);
	u16 i=0,j=0;
	while (1)
	{
		GPIO_SetPinValue(PA,PIN0,HIGH);

		for(i=0;i<500;i++)
		{
			for(j=0;j<500;j++)
			{

			}
		}

		GPIO_SetPinValue(PA,PIN0,LOW);
					for(i=0;i<500;i++)
					{
						for(j=0;j<500;j++)
							{

								}
		    		}

	}

}



