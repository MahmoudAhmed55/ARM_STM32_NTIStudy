/*
 * RCC_Config.h
 *
 * Created: 2/11/2023 10:47:34 AM
 *  Author: Mahmoud Ahmed Ismail
 */

#ifndef _RCC_Config_H_
#define _RCC_Config_H_


/* clock_type 1-RCC_HSI
2-RCC_HSE_CRYSTAL
3-RCC_HSE_RC
4-RCC_PLL
 */
#define   RCC_CLOCK_TYPE          RCC_HSE_CRYSTAL

/*System clock switch
 *  1-HSI_SC
 * 2-HSE_SC
 * 3-PLL_SC
 * 4-NOT_ALLOWED
 */
#define   RCC_SYSTEM_CLOCK_SWITCH   HSE_SC

/*
  RCC_PLL_SOURCE
  (1-HSI/2
 * 2-HSE/2
 * 3-HSE)
  RCC_PLL_MUL BY_(2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,16)
 */
#if       RCC_CLOCK_TYPE==RCC_PLL

#define   RCC_PLL_SOURCE           PLL_HSI_DIVIDEBY2
#define   RCC_PLL_MUL              PLL_MULBY2
#endif



#endif
