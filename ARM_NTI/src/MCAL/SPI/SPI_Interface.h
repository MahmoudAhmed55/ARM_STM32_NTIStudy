/*
 * SPI_Interface.h
 *
 *  Created on: Nov 16, 2023
 *      Author: lenovo
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_


void SPI1_Init(void);

u8 SPI1_SendReciveSynch(u8 data);


void SPI1_InterruptTransmitEnable(void);
void SPI1_InterruptTransmitDisable(void);
void SPI1_InterruptRecieveEnable(void);
void SPI1_InterruptRecieveDisable(void);
void SPI1_SendReciveASynch(u8 data,void(*CallBack)(u8));
void SPI1_IRQHANDLER(void);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
