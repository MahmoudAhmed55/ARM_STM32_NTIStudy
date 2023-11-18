
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"


void RCC_InitClockSystem(void)
{
	RCC_CR=0X00000000;                     //clock_controlRegister_init=0.
	RCC_CFGR=0x00000000;                   //Clock_configurationRegister_init=0.

   #if RCC_CLOCK_TYPE==RCC_HSI
	SIT_BIT(RCC_CR,HSI_ON);                  //Enable HSI.
	SIT_BIT(RCC_CR,HSI_TRIM);                // TRIM FREQUANCY VALUE=16.
	while(READ_BIT(RCC_CR,HSI_RDY));         //BUSY_WAIT waiting for HSI ready flag.

   #elif  RCC_CLOCK_TYPE==RCC_HSE_CRYSTAL
	SIT_BIT(RCC_CR,HSE_ON);                 //Enable HSE.
	while(READ_BIT(RCC_CR,HSE_RDY));        //BUSY_WAIT waiting for HSE ready flag.
	SIT_BIT(RCC_CFGR,SW);                   //HSE selected as system clock.

   #elif  RCC_CLOCK_TYPE==RCC_HSE_RC
	SIT_BIT(RCC_CR,HSE_BYp);                //Write 1 for ByPath RC.
	SIT_BIT(RCC_CR,HSE_ON);                 //Enable HSE.
	while(READ_BIT(RCC_CR,HSE_RDY));        //BUSY_WAIT waiting for HSE ready flag.
	SIT_BIT(RCC_CFGR,SW);                   //HSE selected as system clock.

   #elif  RCC_CLOCK_TYPE==RCC_PLL

           #if    RCC_PLL_SOURCE==PLL_HSI_DIVIDEBY2

           #elif  RCC_PLL_SOURCE==PLL_HSE_DIVIDEBY2
	             SIT_BIT(RCC_CFGR,PLL_XTPRE);
	               SIT_BIT(RCC_CFGR,PLL_SRC);                   //HSE_SOURCE ENABLE

           #elif  RCC_PLL_SOURCE==PLL_HSE
	               SIT_BIT(RCC_CFGR,PLL_SRC);                  //HSE_SOURCE ENABLE
	                              //FULL HSE

	               
          #endif

	              RCC_CFGR^=(RCC_PLL_MUL<<PLL_MUL);            //PLL_MUL*2
	              SIT_BIT(RCC_CR,PLL_ON);                      //Enable PLL_clock
	              while(READ_BIT(RCC_CR,PLL_RDY));             //BUSY_WAIT waiting for PLL ready flag.
	              RCC_CFGR^=(RCC_CLOCK_TYPE<<SW);              //CLOCK_SWITCH





#endif

}

void RCC_EnableClock(peripheralBus_t bus, peripheral_EN_t id)
{
	if (id <= 31)
		{
			switch (bus)
			{
				case AHB :
				SIT_BIT(RCC_AHBENR,id) ;
				break;
				case APB1:
				SIT_BIT(RCC_APB1ENR,id) ;
				break;
				case APB2:
				SIT_BIT(RCC_APB2ENR,id) ;
				break;
			}
		}

}
void RCC_DisEnableClock(peripheralBus_t bus, peripheral_EN_t  id)
{
	if (id <= 31)
		{
			switch (bus)
			{
				case AHB :
				CLR_BIT(RCC_AHBENR,id) ;
				break;
				case APB1:
				CLR_BIT(RCC_APB1ENR,id) ;
				break;
				case APB2:
				CLR_BIT(RCC_APB2ENR,id) ;
				break;
			}
		}

}
