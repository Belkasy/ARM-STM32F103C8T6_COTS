/**
 *@name     RCC_Program.c
 *@version  v1.BIT_DEACTIVATE
 *@authors: Abdelrahman Belkasy, Wx
 *@date     8/11/2022
 *@copyright Belkasy, Wx
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup  *RCC Related Headers */
#include "RCC_Private.h"
#include "RCC_Config.h"
#include "RCC_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                               Reset Clock Control Driver Program
----------------------------------------------------------------------------------------------------
*/

void RCC_voidSystemClockInit(u8 Copy_u8SystemClockID)
{
    /** @def enable the Clock Security System for unstable clock */
    BIT_WRT(RCC->CR, CSSON, BIT_ACTIVATE); /** @note enables the HSI */

#if   (RCC_CLOCK_TYPE == SYSTEM_CLOCK_LSE)
    RCC_voidEnableLSE(True);
    /** @todo to be implemented if needed*/
    #error ("SYSTEM_CLOCK_LSE not implemented")
#elif (RCC_CLOCK_TYPE == SYSTEM_CLOCK_HSI) 
    RCC_voidEnableHSI(True);
#elif (RCC_CLOCK_TYPE == SYSTEM_CLOCK_HSE)
    RCC_voidEnableHSE(True);
#elif (RCC_CLOCK_TYPE == SYSTEM_CLOCK_PLL) 
    RCC_voidEnablePLL(True);
#else
    #error ("Undefined Clock type")
#endif /* RCC_CLOCK_TYPE */

    /** @def Setting the bus's clock prescaler */
    RCC_voidSetBusPrescaler();
}/** @end RCC_voidSystemInit */


void RCC_voidEnableClock(cu8 Copy_cu8BusID, cu8 Copy_cu8PeripheralID)
{
    switch(Copy_cu8BusID)
    {
        case SYSTEM_BUS_AHB  : BIT_WRT(RCC->AHBENR,  Copy_cu8PeripheralID, BIT_ACTIVATE); break;
        case SYSTEM_BUS_APB1 : BIT_WRT(RCC->APB1ENR, Copy_cu8PeripheralID, BIT_ACTIVATE); break;
        case SYSTEM_BUS_APB2 : BIT_WRT(RCC->APB2ENR, Copy_cu8PeripheralID, BIT_ACTIVATE); break;
        default: return; /** @todo error handler */
    }
}/** @end RCC_voidEnableClock */

void RCC_voidDisableClock(cu8 Copy_cu8BusID, cu8 Copy_cu8PeripheralID)
{
    switch(Copy_cu8BusID)
    {
        case SYSTEM_BUS_AHB  : BIT_WRT(RCC->AHBENR,  Copy_cu8PeripheralID, BIT_DEACTIVATE); break;
        case SYSTEM_BUS_APB1 : BIT_WRT(RCC->APB1ENR, Copy_cu8PeripheralID, BIT_DEACTIVATE); break;
        case SYSTEM_BUS_APB2 : BIT_WRT(RCC->APB2ENR, Copy_cu8PeripheralID, BIT_DEACTIVATE); break;
        default: return; /** @todo error handler */
    }
}/** @end RCC_voidDisableClock */

void RCC_voidSetMCO(u8 Copy_u8ClockType)
{
	switch(Copy_u8ClockType)
	{
		case NO_CLOCK:
						BIT_CLR(RCC->CFGR, MCO_26);
					break;
		case SYSTEM_CLOCK:
						BIT_SET(RCC->CFGR, MCO_26);
						BIT_CLR(RCC->CFGR, MCO_25);
						BIT_CLR(RCC->CFGR, MCO_24);
					break;
		case HSI_CLOCK:
						BIT_SET(RCC->CFGR, MCO_26);
						BIT_CLR(RCC->CFGR, MCO_25);
						BIT_SET(RCC->CFGR, MCO_24);
					break;
		case HSE_CLOCK:
						BIT_SET(RCC->CFGR, MCO_26);
						BIT_SET(RCC->CFGR, MCO_25);
						BIT_CLR(RCC->CFGR, MCO_24);
					break;
		case PLL_DIV_2_CLOCK:
						BIT_SET(RCC->CFGR, MCO_26);
						BIT_SET(RCC->CFGR, MCO_25);
						BIT_SET(RCC->CFGR, MCO_24);
					break;
		default: return; /** @todo error handler */
	}

}/** @end RCC_voidSetMCO */

/*
----------------------------------------------------------------------------------------------------
!-                                 PRIVATE FUNCTIONS IMPLEMENTATION
----------------------------------------------------------------------------------------------------
*/

#if (RCC_CLOCK_TYPE == SYSTEM_CLOCK_HSI || (RCC_CLOCK_TYPE == SYSTEM_CLOCK_PLL))
static void RCC_voidEnableHSI(u8 Copy_u8SetSystemClockFlag)
{
    /** @def configure hsi */
    BIT_SET(RCC->CR, HSION);
    
    /** @def Iterate until the signal get stable */
    while( !(BIT_GET(RCC->CR, HSIRDY)) );
    
    if( (Copy_u8SetSystemClockFlag == True) )
    {
        /** @def set as system clock source: 00*/
        BIT_CLR(RCC->CFGR, SW_0);
        BIT_CLR(RCC->CFGR, SW_1);
    }
    else;
}/** @end RCC_voidEnableHSI */
#endif /* SYSTEM_CLOCK_HSI */

#if (RCC_CLOCK_TYPE == SYSTEM_CLOCK_HSE || (RCC_CLOCK_TYPE == SYSTEM_CLOCK_PLL))
static void RCC_voidEnableHSE(u8 Copy_u8SetSystemClockFlag)
{
    #if (HSE_INPUT_TYPE == SYSTEM_CLOCK_HSE_RC)
    /** @def configure hse rc */
	BIT_SET(RCC->CR, HSEBYP);
        
    /** @def Iterate until the signal get stable */
    while( !(BIT_GET(RCC->CR, HSERDY)) );

    #elif (HSE_INPUT_TYPE == SYSTEM_CLOCK_HSE_CRYSTAL)
    /** @def configure hse crystal */
    BIT_CLR(RCC->CR, HSEBYP);
        
    /** @def Iterate until the signal get stable */
    while( !(BIT_GET(RCC->CR, HSERDY)) );

    #endif /* HSE_INPUT_TYPE */
    if( (Copy_u8SetSystemClockFlag == True) )
    {
        /** @def set as system clock source: 01 */
    	BIT_SET(RCC->CFGR, SW_0);
        BIT_CLR(RCC->CFGR, SW_1);
    }
    else;
}/** @end RCC_voidEnableHSE */
#endif /* SYSTEM_CLOCK_HSE */

#if (RCC_CLOCK_TYPE == SYSTEM_CLOCK_PLL)
static void RCC_voidEnablePLL(u8 Copy_u8SetSystemClockFlag)
{
#if (PLL_INPUT_TYPE == PLL_INPUT_HSI_DIV_2)
    /** @note enable HSI */
    RCC_voidEnableHSI(False);
    /** @note set it as pll source */
    BIT_CLR(RCC->CFGR, PLLXTPRE);
    BIT_CLR(RCC->CFGR, PLLSRC);

#elif (PLL_INPUT_TYPE == PLL_INPUT_HSE_DIRECT)
    /** @note enable HSE */
    RCC_voidEnableHSE(False);
    /** @note set it as pll source */
    BIT_CLR(RCC->CFGR, PLLXTPRE);
    BIT_SET(RCC->CFGR, PLLSRC);

#elif (PLL_INPUT_TYPE == PLL_INPUT_HSE_DIV_2)
    /** @note enable HSE */
    RCC_voidEnableHSE(False);
    /** @note set it as pll source */
    BIT_SET(RCC->CFGR, PLLXTPRE);
    BIT_SET(RCC->CFGR, PLLSRC);

#else 
    #error ("No PLL source selected!") 
#endif /* PLL_CLOCK_INPUT */

    /** @def PLL Multiplier */ 
    RCC_voidDecoder(SYSTEM_PLL, PLL_MULTIPLIER);
        
    /** @def enable PLL */ 
    BIT_SET(RCC->CR, PLLON);
    while( !(BIT_GET(RCC->CR, PLLRDY)) );

    /** @def set as system clock source: 10 */
    if( (Copy_u8SetSystemClockFlag == True) )
    {
        BIT_CLR(RCC->CFGR, SW_0);
        BIT_SET(RCC->CFGR, SW_1);
    }
    else;
}/** @end RCC_voidEnablePLL */
#endif /* SYSTEM_CLOCK_PLL */

static void RCC_voidSetBusPrescaler(void)
{
    RCC_voidDecoder(SYSTEM_BUS_AHB,  AHB_PRESCALER);
    RCC_voidDecoder(SYSTEM_BUS_APB1, APB1_PRESCALER);
    RCC_voidDecoder(SYSTEM_BUS_APB2, APB2_PRESCALER);
}/** @end RCC_voidSetBusPrescaler */

static void RCC_voidDecoder(cu8 Copy_cu8Bus, cu8 Copy_cu8Value)
{
   switch (Copy_cu8Bus)
   {
        case SYSTEM_BUS_AHB :   
				RCC->CFGR &=  (u32) (~( (0b1111) << (HPRE_4) ));
				RCC->CFGR |=  (u32) ((Copy_cu8Value) << (HPRE_4));
            break;
        case SYSTEM_BUS_APB1:
				RCC->CFGR &=  (u32) (~( (0b111) << (PPRE1_8) ));
				RCC->CFGR |=  (u32) ((Copy_cu8Value) << (PPRE1_8));
            break;
        case SYSTEM_BUS_APB2:
				RCC->CFGR &=  (u32) (~( (0b111) << (PPRE2_11) ));
				RCC->CFGR |=  (u32) ((Copy_cu8Value) << (PPRE2_11));
            break;
        case  SYSTEM_PLL:   
				RCC->CFGR &=  (u32) (~( (0b111) << (PLLMUL_18) ));
				RCC->CFGR |=  (u32) ((Copy_cu8Value) << (PLLMUL_18));
            break;
        default: return; /** @todo error handler */
   }
}/** @end RCC_voidBusPrescalerDecoder */
