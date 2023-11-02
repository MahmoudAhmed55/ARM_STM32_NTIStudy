/*
 * RCC_Interface.h
 *
 * Created: 2/11/2023 10:47:34 AM
 *  Author: Mahmoud Ahmed Ismail
 */


#ifndef  _RCC_Interface_H_
#define  _RCC_Interface_H_

#include "STD_TYPES.h"

typedef enum
{
	AHB=0,
	APB2,
	APB1
}peripheralBus_t;

void RCC_InitClockSystem(void);

void RCC_EnableClock(peripheralBus_t bus,u8 PeripheralId);
void RCC_DisEnableClock(peripheralBus_t bus,u8 PeripheralId);

#endif

