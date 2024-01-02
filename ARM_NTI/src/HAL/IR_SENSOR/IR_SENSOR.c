/*
 * IR_SENSOR.c
 *
 *  Created on: Dec 10, 2023
 *      Author: lenovo
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"


u8 IR_SENSOR1(void)
{
	return GPIO_GetPinValue(PINA12);

}
u8 IR_SENSOR2(void)
{
	return GPIO_GetPinValue(PINA13);
}
