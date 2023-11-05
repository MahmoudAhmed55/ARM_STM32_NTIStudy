

#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_

typedef enum
{
	PA=0,
	PB,
	PC,
}Port_t;
typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
}Pin_t;

typedef enum
{
	INPUT_ANALOG=0,
	OUTPUT10KHZ_PUSHPALL,
	OUTPUT2KHZ_PUSHPALL,
	OUTPUT50KHZ_PUSHPALL,
	INPUT_FLOATING,
	OUTPUT10KHZ_OPENDRAIN,
	OUTPUT2KHZ_OPENDRAIN,
	OUTPUT50KHZ_OPENDRAIN,
	INPUT_PULL_UP_DOWN,
	OUTPUT10KHZ_AF_PUSHPALL,
	OUTPUT2KHZ_AF_PUSHPALL,
	OUTPUT50KHZ_AF_PUSHPALL,
	INPUT_RESERVED,
	OUTPUT10KHZ_AF_OPENDRAIN,
	OUTPUT2KHZ_AF_OPENDRAIN,
	OUTPUT50KHZ_AF_OPENDRAIN,
}MODE_CNF_t;

typedef enum
{
	LOW=0,
	HIGH,
}Pin_Value_t;

void GPIO_SetPinDirection(Port_t port,Pin_t pin,MODE_CNF_t mode);
void GPIO_SetPinValue(Port_t port,Pin_t pin,Pin_Value_t value);
u8 GPIO_GetPinValue(Port_t  port,Pin_t  pin);

void GPIO_SetPort(Port_t port,MODE_CNF_t mode);
void GPIO_SetPortValue(Port_t port,u32 value);


#endif
