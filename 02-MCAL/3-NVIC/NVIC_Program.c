/**
 * @name        NVIC_Program.c
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup  *RCC Related Headers */
#include "NVIC_Config.h"
#include "NVIC_Private.h"
#include "NVIC_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                     NVIC PROGRAM
----------------------------------------------------------------------------------------------------
*/

void NVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
    u8 L_u8RegisterIndex = (Copy_u8IntNumber >> 5);
	NVIC_ISER[L_u8RegisterIndex] |= (1 << (Copy_u8IntNumber & 0x1F));
}/** @end NVIC_voidEnableInterrupt */

void NVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
    u8 L_u8RegisterIndex = (Copy_u8IntNumber >> 5);
	NVIC_ICER[Copy_u8IntNumber]	|= (1 << (Copy_u8IntNumber & 0x1F));
}/** @end NVIC_voidDisableInterrupt */

void NVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
    u8 L_u8RegisterIndex = (Copy_u8IntNumber >> 5);
	NVIC_ISPR[Copy_u8IntNumber]	|= (1 << (Copy_u8IntNumber & 0x1F));
}/** @end NVIC_voidSetBendingFlag */

void NVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
    u8 L_u8RegisterIndex = (Copy_u8IntNumber >> 5);
	NVIC_ICPR[Copy_u8IntNumber]	|= (1 << (Copy_u8IntNumber & 0x1F));
}/** @end NVIC_voidClearBendingFlag */

void NVIC_voidGetActiveFlag(u8 Copy_u8IntNumber, u8 *Address_u8ActiveFlag)
{
    u8 L_u8ActiveFlag = 0;
    u8 L_u8RegisterIndex = (Copy_u8IntNumber >> 5);

    L_u8ActiveFlag = ( NVIC_IABR[Copy_u8IntNumber] &  (1 << (Copy_u8IntNumber & 0x1F)) );

    *Address_u8ActiveFlag = L_u8ActiveFlag;
}/** @end NVIC_voidGetActiveFlag */

void NVIC_voidSetPriorityBits(u8 Copy_u8PriorityBitsSettings)
{
    SCB_AIRCR = Copy_u8PriorityBitsSettings;
}/** @end NVIC_voidIPRxControlBits */

void NVIC_voidSetPriority(u8 Copy_u8IntNumber, u8 Copy_u8GroupPriorityID, u8 Copy_u8SubPriorityID)
{
    /** @note Equation to directly set the pirority */
    u8 L_u8Priority = (Copy_u8SubPriorityID |  /** @todo to be changed */
                      (Copy_u8GroupPriorityID << ((PRIORITY_BITS - 0x05FA0300) / 0x100)));

    if( (Copy_u8IntNumber <= 0) )   /* For internal interrupts */
    {
        ; /** @todo to be implemented */
    }
    else if( (Copy_u8IntNumber > 0) )   /* For external interrupts */
    {
        NVIC_IPR[Copy_u8IntNumber] = L_u8Priority;
    }
    else;
}/** @end NVIC_voidSetPriority */
