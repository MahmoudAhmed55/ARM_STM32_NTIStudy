/*
 * main.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mahmoud Ahmed Ismail
 */

#include "APP/VtoI/VtoI_Interface.h"


void main(void)
{

	VtoI_Init();

	while(1)
	{

		VtoI_APP();
	}
}




