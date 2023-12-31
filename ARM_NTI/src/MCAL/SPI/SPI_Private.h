/*
 * SPI_Private.h
 *
 *  Created on: Nov 16, 2023
 *      Author: lenovo
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define   SPI_BASEADDRESS      (0x40013000)

#define SPI_CR1                      *((volatile u32*) (SPI_BASEADDRESS +0x00))
#define MSTR   3               //master select
#define SPE    6               //enable SPI
#define SSM    9               //control the slave with software

#define SPI_CR2                      *((volatile u32*) (SPI_BASEADDRESS +0x04))
#define TXEIE  7               //TX Interrupt Enable
#define RXNEIE 6               //RX Interrupt Enable

#define SPI_SR                       *((volatile u32*) (SPI_BASEADDRESS +0x08))
#define BSY    7

#define SPI_DR                       *((volatile u32*) (SPI_BASEADDRESS +0x0C))


#define SLAVE 0
#define MASTER 1


#define fPCLK2      0
#define fPCLK4      1
#define fPCLK8      2
#define fPCLK16     3
#define fPCLK32     4
#define fPCLK64     5
#define fPCLK128    6
#define fPCLK2S2    7


#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
