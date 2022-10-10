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

u8 G_u8WWDTtimeOut;

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


void WWDT_voidStart(float millis)
{
    /* Disable the periphral */
    BIT_CLR(WWDT->CR, 7);
    /* Clear prescaler */
    WWDT->CFR &= (u32) (~(0b11 << 7u));

    if( (millis < 9.0) )
    {
        WWDT->CFR |= (u32) ((WWDT_PRESCALER_1 << 7u));
        G_u8WWDTtimeOut = (u8) WWDT_EQ(millis, 1);
    }
    else if( (millis <  16.0) )
    {
        WWDT->CFR |= (u32) ((WWDT_PRESCALER_2 << 7u));
        G_u8WWDTtimeOut = (u8) WWDT_EQ(millis, 2);
    }
    else if( (millis < 31.0) )
    {
        WWDT->CFR |= (u32) ((WWDT_PRESCALER_4 << 7u));
        G_u8WWDTtimeOut = (u8) WWDT_EQ(millis, 4);
    }
    else if( (millis < 60.0) )
    {
        WWDT->CFR |= (u32) ((WWDT_PRESCALER_8 << 7u));
        G_u8WWDTtimeOut = (u8) WWDT_EQ(millis, 8);
    }
    else {;}

    WWDT->CR  &= (u32) (~(0x3F));
    WWDT->CR  |= (u32) ((1 << 6u) | (G_u8WWDTtimeOut));
    WWDT->CFR |= (u32) (G_u8WWDTtimeOut - 20u);

    /* Enable the periphral */
    BIT_SET(WWDT->CR, 7);
}/** @end WWDT_voidStart */

void WWDT_voidRestart(void)
{
    u8 L_u8Time = ( (WWDT->CFR) & (0x7F) );
    u8 L_u8Counter = ( (WWDT->CR) & (0x3F) );

    if( (L_u8Counter < L_u8Time) && (L_u8Counter > 63) )
    {
        WWDT->CR |= ( (1 << 6u) | G_u8WWDTtimeOut);
    }
    else{;}
}/** @end WWDT_voidRestart */

void WWDT_voidStop(void)
{
    /* Disable the periphral */
    BIT_CLR(WWDT->CR, 7);
}/** @end WWDT_voidStop */

/*
----------------------------------------------------------------------------------------------------
!-                                  WATCHDOG Function  PRIVATE
----------------------------------------------------------------------------------------------------
*/

