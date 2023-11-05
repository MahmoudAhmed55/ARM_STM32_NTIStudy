
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"



void GPIO_SetPinDirection(Port_t port,Pin_t pin,MODE_CNF_t mode)
{
	switch(port)
	{
	case PA:
		if (pin<8)
		{
			GPIOA_CRL&=~((0b1111)<<(pin*4));
			GPIOA_CRL|= ((mode)<<(pin*4));

		}
		else if (pin<=15&&pin>7)
				{
			        pin=pin-8;
					GPIOA_CRH&=~((0b1111)<<(pin*4));
					GPIOA_CRH|= ((mode)<<(pin*4));
				}
		break;
	case PB:
			if (pin<8)
			{
				GPIOB_CRL&=~((0b1111)<<(pin*4));
				GPIOB_CRL|= ((mode)<<(pin*4));

			}
			else if (pin<=15&&pin>7)
					{
				        pin=pin-8;
						GPIOB_CRH&=~((0b1111)<<(pin*4));
						GPIOB_CRH|= ((mode)<<(pin*4));
					}
			break;
	case PC:
			if (pin<8)
			{
				GPIOC_CRL&=~((0b1111)<<(pin*4));
				GPIOC_CRL|= ((mode)<<(pin*4));

			}
			else if (pin<=15&&pin>7)
					{
				        pin=pin-8;
						GPIOC_CRH&=~((0b1111)<<(pin*4));
						GPIOC_CRH|= ((mode)<<(pin*4));
					}
			break;
	default:break;
	}
}

void GPIO_SetPinValue(Port_t port,Pin_t pin,Pin_Value_t value)
{
	switch(port)
		{
		case PA:
			if (value==HIGH)
			{
				SIT_BIT(GPIOA_ODR,pin);
			}
			else if (value==LOW)
			{
				CLR_BIT(GPIOA_ODR,pin);
			}
			break;
		case PB:
					if (value==HIGH)
					{
						SIT_BIT(GPIOB_ODR,pin);
					}
					else if (value==LOW)
					{
						CLR_BIT(GPIOB_ODR,pin);
					}
					break;
		case PC:
					if (value==HIGH)
					{
						SIT_BIT(GPIOC_ODR,pin);
					}
					else if (value==LOW)
					{
						CLR_BIT(GPIOC_ODR,pin);
					}
					break;
		default:break;

}
}

u8 GPIO_GetPinValue(Port_t  port,Pin_t  pin)
{
	u8 read=0;

	switch(port)
			{
			case PA:read=READ_BIT(GPIOA_IDR,pin);
				break;
			case PB:read=READ_BIT(GPIOB_IDR,pin);
				break;
			case PC:read=READ_BIT(GPIOC_IDR,pin);
				break;
			default:break;
			}
	return read;

}