/*
 * SYSTIC_Private.h
 *
 *  Created on: Nov 8, 2023
 *      Author: lenovo
 */

#ifndef MCAL_SYSTICK_SYSTIC_PRIVATE_H_
#define MCAL_SYSTICK_SYSTIC_PRIVATE_H_

#define SYSTICK_BASEADDRESS                  0xE000E010

#define STK_CTRL                         (*((volatile u32*)(SYSTICK_BASEADDRESS +0x00)))
#define STK_LOAD                         (*((volatile u32*)(SYSTICK_BASEADDRESS +0x04)))
#define STK_VAL                          (*((volatile u32*)(SYSTICK_BASEADDRESS +0x08)))
#define STK_CALIB                        (*((volatile u32*)(SYSTICK_BASEADDRESS +0x0C)))

#endif /* MCAL_SYSTICK_SYSTIC_PRIVATE_H_ */
