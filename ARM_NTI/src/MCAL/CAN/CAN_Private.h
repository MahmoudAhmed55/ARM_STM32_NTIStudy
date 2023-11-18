/*
 * CAN_Private.h
 *
 *  Created on: Nov 10, 2023
 *      Author: lenovo
 */

#ifndef MCAL_CAN_CAN_PRIVATE_H_
#define MCAL_CAN_CAN_PRIVATE_H_


#define CAN1_BASE_ADDRESS       (0x40010800)

#define CAN_MCR                 *((volatile u32*) (CAN1_BASE_ADDRESS +0X00))
#define CAN_MSR                 *((volatile u32*) (CAN1_BASE_ADDRESS +0X04))




#endif /* MCAL_CAN_CAN_PRIVATE_H_ */
