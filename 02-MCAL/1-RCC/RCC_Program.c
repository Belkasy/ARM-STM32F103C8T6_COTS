/**
 *@name     RCC_Program.c
 *@version  v1.BIT_DEACTIVATE
 *@authors: Abdelrahman Belkasy, Wx
 *@date     8/11/2022
 *@copyright Belkasy, Wx
*/

#include " ../../01-LIB/BIT_MATH.h"
#include " ../../01-LIB/STD_TYPES.h"

/** @defgroup  *RCC Related Headers */
#include "RCC_Config.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                               Reset Clock Control Driver Program
----------------------------------------------------------------------------------------------------
*/
#define RCC_CLOCK_TYPE (SYSTEM_CLOCK_HSI)

void RCC_voidSystemClockInit(void)
{
    /** @def enable the Clock Security System for unstable clock */
    BIT_WRT(*RCC[CR_ID], CSSON, BIT_ACTIVATE); /** @note enables the HSI */

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
        case SYSTEM_BUS_AHB  : BIT_WRT(*RCC[AHBENR],  Copy_cu8PeripheralID, BIT_ACTIVATE); break;
        case SYSTEM_BUS_APB1 : BIT_WRT(*RCC[APB1ENR], Copy_cu8PeripheralID, BIT_ACTIVATE); break;
        case SYSTEM_BUS_APB2 : BIT_WRT(*RCC[APB2ENR], Copy_cu8PeripheralID, BIT_ACTIVATE); break;
        default: return; /** @todo error handler */
    }
}/** @end RCC_voidEnableClock */

void RCC_voidDisableClock(cu8 Copy_cu8BusID, cu8 Copy_cu8PeripheralID)
{
    switch(Copy_cu8BusID)
    {
        case SYSTEM_BUS_AHB  : BIT_WRT(*RCC[AHBENR],  Copy_cu8PeripheralID, BIT_ACTIVATE); break;
        case SYSTEM_BUS_APB1 : BIT_WRT(*RCC[APB1ENR], Copy_cu8PeripheralID, BIT_ACTIVATE); break;
        case SYSTEM_BUS_APB2 : BIT_WRT(*RCC[APB2ENR], Copy_cu8PeripheralID, BIT_ACTIVATE); break;
        default: return; /** @todo error handler */
    }
}/** @end RCC_voidDisableClock */

/*
----------------------------------------------------------------------------------------------------
!-                                 PRIVATE FUNCTIONS IMPLEMENTATION
----------------------------------------------------------------------------------------------------
*/

static void RCC_voidEnableHSI(u8 Copy_u8SetSystemClockFlag)
{
    /** @def configure hsi */
    BIT_WRT(*RCC[CR_ID], HSION, BIT_ACTIVATE);
    
    /** @def Iterate until the signal get stable */
    while( !(BIT_GET(*RCC[CR_ID], HSIRDY)) );
    
    if( (Copy_u8SetSystemClockFlag == True) )
    {
        /** @def set as system clock source: 00*/
        BIT_WRT(*RCC[CFGR_ID],SW_0, BIT_DEACTIVATE);
        BIT_WRT(*RCC[CFGR_ID],SW_1, BIT_DEACTIVATE);
    }
    else;
}/** @end RCC_voidEnableHSI */

static void RCC_voidEnableHSE(u8 Copy_u8SetSystemClockFlag)
{
    #if (HSE_INPUT_TYPE == SYSTEM_CLOCK_HSE_RC)
    /** @def configure hse rc */
    BIT_WRT(*RCC[CR_ID], HSEBYP, BIT_ACTIVATE);
        
    /** @def Iterate until the signal get stable */
    while( !(BIT_GET(*RCC[CR_ID], HSERDY)) );

    #elif (HSE_INPUT_TYPE == SYSTEM_CLOCK_HSE_CRYSTAL)
    /** @def configure hse crystal */
    BIT_WRT(*RCC[CR_ID], HSEBYP, BIT_DEACTIVATE);
        
    /** @def Iterate until the signal get stable */
    while( !(BIT_GET(*RCC[CR_ID], HSERDY)) );

    #endif /* HSE_INPUT_TYPE */
    if( (Copy_u8SetSystemClockFlag == True) )
    {
        /** @def set as system clock source: 01 */
        BIT_WRT(*RCC[CFGR_ID],SW_0, BIT_ACTIVATE);
        BIT_WRT(*RCC[CFGR_ID],SW_1, BIT_DEACTIVATE);
    }
    else;
}/** @end RCC_voidEnableHSE */

static void RCC_voidEnablePLL(u8 Copy_u8SetSystemClockFlag)
{
#if (PLL_INPUT_TYPE == PLL_INPUT_HSI_DIV_2)
    /** @note enable HSI */
    RCC_voidEnableHSI(False);
    /** @note set it as pll source */
    BIT_WRT(*RCC[CFGR_ID], PLLXTPRE, BIT_DEACTIVATE);
    BIT_WRT(*RCC[CFGR_ID], PLLSRC, BIT_DEACTIVATE);

#elif (PLL_INPUT_TYPE == PLL_INPUT_HSE_DIRECT)
    /** @note enable HSE */
    RCC_voidEnableHSE(False);
    /** @note set it as pll source */
    BIT_WRT(*RCC[CFGR_ID], PLLXTPRE, BIT_DEACTIVATE);
    BIT_WRT(*RCC[CFGR_ID], PLLSRC, BIT_ACTIVATE);

#elif (PLL_INPUT_TYPE == PLL_INPUT_HSE_DIV_2)
    /** @note enable HSE */
    RCC_voidEnableHSE(False);
    /** @note set it as pll source */
    BIT_WRT(*RCC[CFGR_ID], PLLXTPRE, BIT_ACTIVATE);
    BIT_WRT(*RCC[CFGR_ID], PLLSRC, BIT_ACTIVATE);

#else 
    #error ("No PLL source selected!") 
#endif /* PLL_CLOCK_INPUT */

    /** @def PLL Multiplier */ 
    RCC_voidDecoder(SYSTEM_PLL, PLL_MULTIPLIER);
        
    /** @def enable PLL */ 
    BIT_WRT(*RCC[CR_ID], PLLON, BIT_ACTIVATE);
    while( !(BIT_GET(*RCC[CR_ID], PLLRDY)) );

    /** @def set as system clock source: 10 */
    if( (Copy_u8SetSystemClockFlag == True) )
    {
        BIT_WRT(*RCC[CFGR_ID], SW_0, BIT_DEACTIVATE);
        BIT_WRT(*RCC[CFGR_ID], SW_1, BIT_ACTIVATE);
    }
    else;
}/** @end RCC_voidEnablePLL */

static void RCC_voidSetBusPrescaler(void)
{
    RCC_voidDecoder(SYSTEM_BUS_AHB,  AHB_PRESCALER);
    RCC_voidDecoder(SYSTEM_BUS_APB2, APB1_PRESCALER);
    RCC_voidDecoder(SYSTEM_BUS_APB2, APB2_PRESCALER);
}/** @end RCC_voidSetBusPrescaler */

static void RCC_voidDecoder(cu8 Copy_cu8Bus, cu8 Copy_cu8Value)
{
   switch (Copy_cu8Bus)
   {
        case SYSTEM_BUS_AHB :   
            *RCC[CFGR_ID] &=  (~( (0b1111) << (HPRE_4) ));
            *RCC[CFGR_ID] |=  ((Copy_cu8Value) << (HPRE_4)); 
            break;
        case SYSTEM_BUS_APB1:
            *RCC[CFGR_ID] &=  (~( (0b111) << (PPRE1_8) )); 
            *RCC[CFGR_ID] |=  ((Copy_cu8Value) << (PPRE1_8));
            break;
        case SYSTEM_BUS_APB2:
            *RCC[CFGR_ID] &=  (~( (0b111) << (PPRE2_11) ));
            *RCC[CFGR_ID] |=  ((Copy_cu8Value) << (PPRE2_11));        
            break;

        case  SYSTEM_PLL:   
            *RCC[CFGR_ID] &=  (~( (0b111) << (PLLMUL_18) ));
            *RCC[CFGR_ID] |=  ((Copy_cu8Value) << (PLLMUL_18));
            break;
        default: return; /** @todo error handler */
   }
}/** @end RCC_voidBusPrescalerDecoder */
