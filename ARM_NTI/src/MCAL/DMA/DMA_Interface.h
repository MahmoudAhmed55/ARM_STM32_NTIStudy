/*
 * DMA_Interface.h
 *
 *  Created on: Nov 9, 2023
 *      Author: lenovo
 */

#ifndef MCAL_DMA_DMA_INTERFACE_H_
#define MCAL_DMA_DMA_INTERFACE_H_

void DMA_Init(void);
void DMA_ChannelStart(u32* source,u32* distination,u32 length);


#endif /* MCAL_DMA_DMA_INTERFACE_H_ */
