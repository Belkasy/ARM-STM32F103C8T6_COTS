/**
 * @name        BROWNOUT_Program.c
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup  USART Related Headers */
#include "BROWNOUT_Config.h"
#include "BROWNOUT_Private.h"
#include "BROWNOUT_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                  Global Variables
----------------------------------------------------------------------------------------------------
*/

/*
----------------------------------------------------------------------------------------------------
!-                                BROWNOUT Function  PROGRAM
----------------------------------------------------------------------------------------------------
*/

void BROWNOUT_voidInit(void)
{
    /** @def: Set the voltage threshold */
    PWR->CR &= (~(0b111 << 5u));
    PWR->CR |= ((BROWNOUT_THRESHOLD) << 5u);
    /** @def: Set the brownout mode */
    BIT_WRT(PWR->CR, PDDS, BROWNOUT_MODE);
    /** @def: Set the regulator config in stop mode */
#if (BROWNOUT_MODE == BROWNOUT_STOP_MODE)
    BIT_WRT(PWR->CR, LPDS, BROWNOUT_REGULATOR);
#else
    /* Do nothing */
#endif
    /** @def: Clear the main flags */
    BIT_CLR(PWR->CR, CSBF);
    BIT_CLR(PWR->CR, CWUF);
    /** @def: Enable/Disable the peripheral */
    BIT_WRT(PWR->CR, PVDE, BROWNOUT_STATE);
}/** @end BROWNOUT_voidInit */


/*
----------------------------------------------------------------------------------------------------
!-                                  BROWNOUT Function  PRIVATE
----------------------------------------------------------------------------------------------------
*/

