/*
 * AFIO.c
 *
 *  Created on: Nov 8, 2023
 *      Author: lenovo
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "AFIO_Interface.h"
#include "AFIO_Private.h"


void AFIO_EXI_Config(Line_t line,EXI_Source_t port)
{

	 if (line>=3)
	{
		AFIO_EXTICR1 &=~((0b1111)<<(line*4));
		AFIO_EXTICR1 |= (port)<<(line*4);
	}
	 else if (line>=7)
		{
			AFIO_EXTICR2 &=~((0b1111)<<(line*4));
			AFIO_EXTICR2 |= (port)<<(line*4);
		}
	 else  if (line>=11)
		{
			AFIO_EXTICR3 &=~((0b1111)<<(line*4));
			AFIO_EXTICR3 |= (port)<<(line*4);
		}
	 else if (line>=15)
		{
			AFIO_EXTICR4 &=~((0b1111)<<(line*4));
			AFIO_EXTICR4 |= (port)<<(line*4);
		}
}


