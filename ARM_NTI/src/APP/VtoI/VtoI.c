/*
 * VtoI.c
 *
 *  Created on: Dec 4, 2023
 *      Author: lenovo
 */
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"
#include "../../HAL/MOTOR/MOTOR_Interface.h"
#include "../../HAL/ESP/ESP_Interface.h"

void moveForward(void)
{
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	MOTOR_CW(M3);
	MOTOR_CW(M4);
}

void movebackward(void)
{
	MOTOR_CCW(M1);
	MOTOR_CCW(M2);
	MOTOR_CCW(M3);
	MOTOR_CCW(M4);

}
void Car_Stop(void)
{
	MOTOR_Stop(M1);
	MOTOR_Stop(M2);
	MOTOR_Stop(M3);
	MOTOR_Stop(M4);
}
void MOVE_RIGHT(void)
{
	MOTOR_CW(M1);
	MOTOR_CW(M3);
	MOTOR_Stop(M2);
	MOTOR_Stop(M4);
}
void MOVE_LEFT(void)
{
	MOTOR_Stop(M1);
	MOTOR_Stop(M3);
	MOTOR_CW(M2);
	MOTOR_CW(M4);
}