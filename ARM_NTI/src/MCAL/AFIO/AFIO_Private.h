/*
 * AFIO_Private.h
 *
 *  Created on: Nov 8, 2023
 *      Author: lenovo
 */

#ifndef MCAL_AFIO_AFIO_PRIVATE_H_
#define MCAL_AFIO_AFIO_PRIVATE_H_

#define   AFIO_BASEADDRESS      (0x40010000)

#define AFIO_EVCR                     *((volatile u32*) (AFIO_BASEADDRESS +0x00))
#define AFIO_MAPR                     *((volatile u32*) (AFIO_BASEADDRESS +0x04))
#define AFIO_EXTICR1                  *((volatile u32*) (AFIO_BASEADDRESS +0x08))
#define AFIO_EXTICR2                  *((volatile u32*) (AFIO_BASEADDRESS +0x0C))
#define AFIO_EXTICR3                  *((volatile u32*) (AFIO_BASEADDRESS +0x10))
#define AFIO_EXTICR4                  *((volatile u32*) (AFIO_BASEADDRESS +0x14))
#define AFIO_MAPR2                    *((volatile u32*) (AFIO_BASEADDRESS +0x1C))


#endif /* MCAL_AFIO_AFIO_PRIVATE_H_ */
