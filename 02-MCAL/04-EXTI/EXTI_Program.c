/**
 * @name        EXTI_Program.c
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup  *RCC Related Headers */
#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                  Global Variables
----------------------------------------------------------------------------------------------------
*/

EXTI_CallBackFunctionFormat EXTI_CallBackFunction[NUM_OF_EXTI] = {NULL, NULL, NULL};

/*
----------------------------------------------------------------------------------------------------
!-                                  External Interrupt  PROGRAM
----------------------------------------------------------------------------------------------------
*/

void EXTI_voidEnableInterruptMask(u8 Copy_u8LineID)
{
    if( (Copy_u8LineID < (MAX_REGISTER_USED_BITS+1)) )
    {
        BIT_SET(EXTI->IMR, Copy_u8LineID);
    }
    else;
}/** @end EXTI_voidEnableInterruptMask */

void EXTI_voidDisableInterruptMask(u8 Copy_u8LineID)
{
    if( (Copy_u8LineID < (MAX_REGISTER_USED_BITS+1)) )
    {
        BIT_CLR(EXTI->IMR, Copy_u8LineID);
    }
    else;
}/** @end EXTI_voidDisableInterruptMask */

void EXTI_voidEnableEventMask(u8 Copy_u8LineID)
{
    if( (Copy_u8LineID < (MAX_REGISTER_USED_BITS+1)) )
    {
        BIT_SET(EXTI->EMR, Copy_u8LineID);
    }
    else;
}/** @end EXTI_voidEnableEventMask */

void EXTI_voidDisableEventMask(u8 Copy_u8LineID)
{
    if( (Copy_u8LineID < (MAX_REGISTER_USED_BITS+1)) )
    {
        BIT_CLR(EXTI->EMR, Copy_u8LineID);
    }
    else;
}/** @end EXTI_voidDisableEventMask */

void EXTI_voidSetInterruptMode(u8 Copy_u8LineID, u8 Copy_u8Mode)
{
    if( (Copy_u8LineID < (MAX_REGISTER_USED_BITS+1)) )
    {
        switch(Copy_u8Mode)
        {
            case EXTI_RISING_EDGE:
                        BIT_SET(EXTI->RTSR, Copy_u8LineID);
                        BIT_CLR(EXTI->FTSR, Copy_u8LineID);
                     break;
            case EXTI_FALLING_EDGE:
                        BIT_CLR(EXTI->RTSR, Copy_u8LineID);
                        BIT_SET(EXTI->FTSR, Copy_u8LineID);
                     break;
            case EXTI_LEVEL_CHANGE:
						BIT_SET(EXTI->RTSR, Copy_u8LineID);
						BIT_SET(EXTI->FTSR, Copy_u8LineID);
            		 break;
            default: break; /* Error handler */
        }
    }
    else;
}/** @end EXTI_voidSetInterruptMode */

void EXTI_voidSetSoftwareInterrupt(u8 Copy_u8LineID)
{
    if( (Copy_u8LineID < (MAX_REGISTER_USED_BITS+1)) )
    {
    	BIT_SET(EXTI->SWIER, Copy_u8LineID);
    }
    else;
}/* EXTI_voidSetSoftwareInterrupt */

void EXTI_voidSetInterruptPendingFlag(u8 Copy_u8LineID, u8 Copy_u8MaskState)
{
    if( (Copy_u8LineID < (MAX_REGISTER_USED_BITS+1)) )
    {
        BIT_WRT(EXTI->PR, Copy_u8LineID, Copy_u8MaskState);
    }
    else;
}/** @end EXTI_voidSetInterruptPendingFlag */

void EXTI_voidSetCallBack(u8 Copy_u8LineID, EXTI_CallBackFunctionFormat CallBackFunction)
{
    if( (CallBackFunction != NULL) && (Copy_u8LineID < NUM_OF_EXTI))
    {
    	EXTI_CallBackFunction[Copy_u8LineID] = CallBackFunction;
    }else;
}/** @end EXTI_voidSetCallBack */

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void EXTI0_IRQHandler(void)
{
    if((EXTI_CallBackFunction[EXTI_LINE0] != NULL))
    {
        EXTI_CallBackFunction[EXTI_LINE0]();
    }else;
}/** @end EXTI0_IRQHandler */

void EXTI1_IRQHandler(void)
{
    if((EXTI_CallBackFunction[EXTI_LINE1] != NULL))
    {
        EXTI_CallBackFunction[EXTI_LINE1]();
    }else;
}/** @end EXTI0_IRQHandler */

void EXTI2_IRQHandler(void)
{
    if((EXTI_CallBackFunction[EXTI_LINE2] != NULL))
    {
        EXTI_CallBackFunction[EXTI_LINE2]();
    }else;
}/** @end EXTI2_IRQHandler */

void EXTI3_IRQHandler(void)
{
    if((EXTI_CallBackFunction[EXTI_LINE3] != NULL))
    {
        EXTI_CallBackFunction[EXTI_LINE3]();
    }else;
}/** @end EXTI3_IRQHandler */
