/*
 * RCC_Interface.h
 *
 * Created: 2/11/2023 10:47:34 AM
 *  Author: Mahmoud Ahmed Ismail
 */


#ifndef  _RCC_Interface_H_
#define  _RCC_Interface_H_


typedef enum
{
	AHB=0,
	APB2,
	APB1
}peripheralBus_t;

typedef enum
{
	//AHB peripheral clock enable register
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

 //APB2 peripheral clock enable register
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

	//APB1 peripheral clock enable register
	TIM2_EN=0,
	TIM3_EN,
	TIM4_EN,
	TIM5_EN,
	TIM6_EN,
	TIM7_EN,
	TIM12_EN,
	TIM13_EN,
	TIM14_EN,
	RES8,
	RES9,
	WWD_GEN,
	RES10,
	RES11,
	SPI2_EN,
	SPI3_EN,
	RES12,
	USART2_EN,
	USART3_EN,
	USART4_EN,
	USART5_EN,
	I2C1_EN,
	I2C2_EN,
	USB_EN,
	RES13,
	CAN_EN,
	RES14,
	PKB_EN,
	PWR_EN,
	DAC_EN,

}peripheral_EN_t;

void RCC_InitClockSystem(void);

void RCC_EnableClock(peripheralBus_t bus, peripheral_EN_t id);
void RCC_DisEnableClock(peripheralBus_t bus, peripheral_EN_t id);

#endif

