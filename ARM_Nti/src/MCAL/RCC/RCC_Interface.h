/*
 * RCC_Interface.h
 *
 * Created: 2/11/2023 10:47:34 AM
 *  Author: Mahmoud Ahmed Ismail
 */


#ifndef  _RCC_Interface_H_
#define  _RCC_Interface_H_

#include "../../lib/STD_TYPES.h"

typedef enum
{
	AHB=0,
	APB2,
	APB1
}peripheralBus_t;

typedef enum
{
	DMA1_EN=0,
	DMA2_EN,
	SRAM_EN,
	RES0,
	FLITF_EN,
	RES1,
	CRCE_N,
	RES2,
	FSMC_EN,
	RES3,
	SDIO_EN,

	AFIO_EN=0,
	RES4,
	IOPA,
	IOPB,
	IOPC,
	IOPD,
	IOPE,
	IOPF,
	IOPG,
	ADC1,
	ADC2,
	TIM1,
	SPI1,
	TIM8,
	USART,
	ADC3,
	RES5,
	RES6,
	RES7,
	TIM9,
	TIM10,
	TIM11,

}APB2_peripheral_t;

void RCC_InitClockSystem(void);

void RCC_EnableClock(peripheralBus_t bus, APB2_peripheral_t id);
void RCC_DisEnableClock(peripheralBus_t bus, APB2_peripheral_t id);

#endif

