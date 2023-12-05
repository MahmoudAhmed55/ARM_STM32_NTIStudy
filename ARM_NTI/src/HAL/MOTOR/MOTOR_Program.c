/*
 * MOTOR_Program.c
 *
 *  Created on: Nov 24, 2023
 *      Author: lenovo
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "MOTOR_Config.h"
#include "MOTOR_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"

void MOTOR_Stop(MOTOR_type m)
{
	switch(m)
	{
		case M1:
		GPIO_SetPinValue(M1_IN1,LOW);
		GPIO_SetPinValue(M1_IN2,LOW);
		break;
		case M2:
		GPIO_SetPinValue(M2_IN1,LOW);
		GPIO_SetPinValue(M2_IN2,LOW);
		break;
		case M3:
		GPIO_SetPinValue(M3_IN1,LOW);
		GPIO_SetPinValue(M3_IN2,LOW);
		break;
		case M4:
		GPIO_SetPinValue(M4_IN1,LOW);
		GPIO_SetPinValue(M4_IN2,LOW);
		break;
	}
}

void MOTOR_CW(MOTOR_type m)
{
	switch(m)
	{
		case M1:
		GPIO_SetPinValue(M1_IN1,HIGH);
		GPIO_SetPinValue(M1_IN2,LOW);
		break;
		case M2:
		GPIO_SetPinValue(M2_IN1,HIGH);
		GPIO_SetPinValue(M2_IN2,LOW);
		break;
		case M3:
		GPIO_SetPinValue(M3_IN1,HIGH);
		GPIO_SetPinValue(M3_IN2,LOW);
		break;
		case M4:
		GPIO_SetPinValue(M4_IN1,HIGH);
		GPIO_SetPinValue(M4_IN2,LOW);
		break;
	}

}
void MOTOR_CCW(MOTOR_type m)
{
	switch(m)
	{
		case M1:
		GPIO_SetPinValue(M1_IN1,LOW);
		GPIO_SetPinValue(M1_IN2,HIGH);
		break;
		case M2:
		GPIO_SetPinValue(M2_IN1,LOW);
		GPIO_SetPinValue(M2_IN2,HIGH);
		break;
		case M3:
		GPIO_SetPinValue(M3_IN1,LOW);
		GPIO_SetPinValue(M3_IN2,HIGH);
		break;
		case M4:
		GPIO_SetPinValue(M4_IN1,LOW);
		GPIO_SetPinValue(M4_IN2,HIGH);
	}

}
