/*
 * SPI_Program.c
 *
 *  Created on: Nov 16, 2023
 *      Author: lenovo
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"


static void (*PTR1)(u8)=NULL_PTR;

void SPI1_Init(void)
{
	// clock phase 0 read then write
	// polarity    0 Rising
	//Frame format 8 bit
	// MSB transmitted first

	//ENABLE SPI1
	SIT_BIT(SPI_CR1,SPE);

	// Software slave management
	SIT_BIT(SPI_CR1,SSM);

#if SPI1==MASTER

	// master Enable
	SIT_BIT(SPI_CR1,MSTR);

	//CLOCK/8
	SPI_CR1=(SPI1_CLOCK<<3)^SPI_CR1;

#elif SPI1==SLAVE

	CLR_BIT(SPI_CR1,MSTR);

#endif
}

u8 SPI1_SendReciveSynch(u8 data)
{
	SPI_DR=data;
	while(READ_BIT(SPI_SR,BSY)==1);

	return SPI_DR;

}

void SPI1_InterruptTransmitEnable(void)
{
	SIT_BIT(SPI_CR2,TXEIE);
}
void SPI1_InterruptTransmitDisable(void)
{
	CLR_BIT(SPI_CR2,TXEIE);
}
void SPI1_InterruptRecieveEnable(void)
{
	SIT_BIT(SPI_CR2,RXNEIE);
}
void SPI1_InterruptRecieveDisable(void)
{
		CLR_BIT(SPI_CR2,RXNEIE);
}


void SPI1_SendReciveASynch(u8 data,void(*CallBack)(u8))
{
	SPI_DR=data;
    PTR1=CallBack;
}

void SPI1_IRQHANDLER(void)
{
	PTR1(SPI_DR);
}

