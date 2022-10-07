/**
 * @name        WATCHDOG_Program.c
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup: WATCHDOG Related Headers */
#include "WATCHDOG_Config.h"
#include "WATCHDOG_Private.h"
#include "WATCHDOG_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                  Global Variables
----------------------------------------------------------------------------------------------------
*/

/*
----------------------------------------------------------------------------------------------------
!-                                WATCHDOG  Function  PROGRAM
----------------------------------------------------------------------------------------------------
*/

void IWDT_voidInit(void)
{
    /* Write the key to access the registers */
    REG_WRT(IWDT->KR, (u32)(IWDT_ACCESS_KEY & 0xFFFFU));
    /* Set the prescaler */
    REG_WRT(IWDT->PR, (IWDT_PRESCALER_VALUE & 0x7U));
}/** @end IWDT_voidInit */

void IWDT_voidCounterStart(u16 Copy_u16CounterValue)
{
    /* Write the key to access the registers */
    REG_WRT(IWDT->KR, (u32)(IWDT_ACCESS_KEY & 0xFFFFU));
    /* Set the counter value */
    REG_WRT(IWDT->RLR, (u32)(Copy_u16CounterValue & 0xFFFU));
    /* Start the watchdog counter */
    REG_WRT(IWDT->KR, (u32)(IWDT_START_KEY & 0xFFFFU));
}/** @end IWDT_voidSetCounterValue */

void IWDT_voidCounterStop(void)
{
    /* Write the key to access the registers */
    REG_WRT(IWDT->KR, (u32)(IWDT_ACCESS_KEY & 0xFFFFU));
    /* Set the counter value */
    REG_WRT(IWDT->RLR, (u32)(0 & 0xFFFU));
    /* Start the watchdog counter */
    REG_WRT(IWDT->KR, (u32)(IWDT_STOP_KEY & 0xFFFFU));
}/** @end IWDT_voidCounterStop */


void WWDT_voidInit(void)
{
     /* Enable */
    BIT_GET(WWDT->CR, BIT7);
    /* Set the prescaler */
    REG_WRT(WWDT->PR, (7>>WWDT_PRESCALER_VALUE));
}
void WWDT_voidDisable(void)
{
    /* Disable */
    BIT_CLR(WWDT->CR, BIT7);
}
void WWDT_voidCounterStart(u16 Copy_u16ResetValue)
{
     /* Write the key to access the registers */
    u16 Local_u16CounterValue = Copy_u16ResetValue;

    REG_WRT(IWDT->KR, (u32)(IWDT_START_KEY & 0xFFFFU));
}
void WWDT_voidCounterStop(void);
/*
----------------------------------------------------------------------------------------------------
!-                                  WATCHDOG Function  PRIVATE
----------------------------------------------------------------------------------------------------
*/

