/**
 * @name        AFIO_Program.c
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup  *RCC Related Headers */
#include "AFIO_Config.h"
#include "AFIO_Private.h"
#include "AFIO_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                  Alternative Function  PROGRAM
----------------------------------------------------------------------------------------------------
*/

void AFIO_voidEXTILineConfig(u8 Copy_u8LineID, u8 Copy_u8LinePortID)
{
    /*
     *  @note This equations are mapping the required values directly with low operations.
     **/
    u8 L_u8RegisterIndex = (Copy_u8LineID >> 2);    /** @note Get register index directly */
    Copy_u8LineID %= 4; /** @note Get line index directly */

    AFIO->EXTICR[L_u8RegisterIndex] &= (~(0xF << (Copy_u8LineID * 4)));
    AFIO->EXTICR[L_u8RegisterIndex] |= ((Copy_u8LinePortID << (Copy_u8LineID * 4)));
}/** @end AFIO_voidEXTILineEnable */
