/*
 * AFIO_Interface.h
 *
 *  Created on: Nov 8, 2023
 *      Author: lenovo
 */

#ifndef MCAL_AFIO_AFIO_INTERFACE_H_
#define MCAL_AFIO_AFIO_INTERFACE_H_
typedef enum
{
	LIN0=0,
	LIN1,
	LIN2,
	LIN3,
	LIN4,
	LIN5,
	LIN6,
	LIN7,
	LIN8,
	LIN9,
	LIN10,
	LIN11,
	LIN12,
	LIN13,
	LIN14,
	LIN15,
}Line_t;
typedef enum
{
	PA_S=0,
	PB_S,
	PC_S

}EXI_Source_t;

void AFIO_EXI_Config(Line_t line,EXI_Source_t port);

#endif /* MCAL_AFIO_AFIO_INTERFACE_H_ */
