/*
 * DMA_Private.h
 *
 *  Created on: Nov 9, 2023
 *      Author: lenovo
 */

#ifndef MCAL_DMA_DMA_PRIVATE_H_
#define MCAL_DMA_DMA_PRIVATE_H_

#define MDMA   ((volatile DMA*) 0x40020000)

typedef struct{

	volatile u32 CCR       ;//0x000
	volatile u32 CNDTR     ;//0x004
	volatile u32 CPAR      ;//0x008
	volatile u32 CMAR      ;//0x00C
	volatile u32 RESERVED  ;//0x010

}DMACHANNEL;

typedef struct{

	volatile u32 ISR  ;    //0x000
	volatile u32 IFCR ;    //0x004
	DMACHANNEL CHANNEL[7]; //0x008

}DMA;






#endif /* MCAL_DMA_DMA_PRIVATE_H_ */
