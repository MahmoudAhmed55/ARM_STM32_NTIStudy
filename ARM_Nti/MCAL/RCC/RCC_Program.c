#define "STD_TYPES.h"
#define "BIT_MATH.h"

#define "RCC_Interface.h"
#define "RCC_Private.h"
#define "RCC_Config.h"

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
	SET_BIT(RCC_CR,HSE_BYP);                //Write 1 for ByPath RC.
	SIT_BIT(RCC_CR,HSE_ON);                 //Enable HSE.
	while(READ_BIT(RCC_CR,HSE_RDY));        //BUSY_WAIT waiting for HSE ready flag.
	SIT_BIT(RCC_CFGR,SW);                   //HSE selected as system clock.

   #elif  RCC_CLOCK_TYPE==RCC_PLL

           #if    RCC_PLL_SOURCE==PLL_HSI_DIVIDEBY2

           #elif  RCC_PLL_SOURCE==PLL_HSE_DIVIDEBY2
	               SIT_BIT(RCC_CFGR,PLL_SRC);                   //HSE_SOURCE ENABLE

           #elif  RCC_PLL_SOURCE==PLL_HSE
	               SIT_BIT(RCC_CFGR,PLL_SRC);                  //HSE_SOURCE ENABLE
	               SIT_BIT(RCC_CFGR,PLL_XTPRE);                //FULL HSE

	               
          #endif

	              RCC_CFGR^=(RCC_PLL_MUL<<PLL_MUL);            //PLL_MUL*2
	              SIT_BIT(RCC_CR,PLL_ON);                      //Enable PLL_clock
	              while(READ_BIT(RCC_CR,PLL_RDY));             //BUSY_WAIT waiting for PLL ready flag.
	              RCC_CFGR^=(RCC_CLOCK_TYPE<<SW);              //CLOCK_SWITCH



#endif

}

void RCC_EnableClock(peripheralBus_t bus,u8 PeripheralId)
{
	if (PeripheralId <= 31)
		{
			switch (bus)
			{
				case RCC_AHBENR :
				SET_BIT(RCC_AHBENR,PeripheralId) ;
				break;
				case RCC_APB2ENR:
				SET_BIT(RCC_APB1ENR,PeripheralId) ;
				break;
				case RCC_APB1ENR:
				SET_BIT(RCC_APB2ENR,PeripheralId) ;
				break;
			}
		}

}
void RCC_DisEnableClock(peripheralBus_t bus,u8 PeripheralId)
{
	if (PeripheralId <= 31)
		{
			switch (bus)
			{
				case RCC_AHBENR :
				CLR_BIT(RCC_AHBENR,PeripheralId) ;
				break;
				case RCC_APB2ENR:
				CLR_BIT(RCC_APB1ENR,PeripheralId) ;
				break;
				case RCC_APB1ENR:
				CLR_BIT(RCC_APB2ENR,PeripheralId) ;
				break;
			}
		}

}
