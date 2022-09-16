/**
 * @name        EXTI_Interface.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

enum EXTI_TRIGGER_MODES
{
    EXTI_RISING_EDGE,
    EXTI_FALLING_EDGE,
    EXTI_LEVEL_CHANGE
};

enum EXTI_LINES
{
    EXTI_LINE0,
    EXTI_LINE1,
    EXTI_LINE2,
    EXTI_LINE3,
    EXTI_LINE4,
    EXTI_LINE5,
    EXTI_LINE6,
    EXTI_LINE7,
    EXTI_LINE8,
    EXTI_LINE9,
    EXTI_LINE10,
    EXTI_LINE11,
    EXTI_LINE12,
    EXTI_LINE13,
    EXTI_LINE14,
    EXTI_LINE15
};

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void EXTI_voidEnableInterruptMask(u8 Copy_LineID);
void EXTI_voidDisableInterruptMask(u8 Copy_LineID);
void EXTI_voidEnableEventMask(u8 Copy_LineID);
void EXTI_voidDisableEventMask(u8 Copy_LineID);
void EXTI_voidSetInterruptMode(u8 Copy_LineID, u8 Copy_u8Mode);
void EXTI_voidSetInterruptPendingFlag(u8 Copy_LineID, u8 Copy_u8MaskState);
void EXTI_voidSetSoftwareInterrupt(u8 Copy_LineID);
void EXTI_voidSetCallBack(u8 Copy_u8LineID, void (*Copy_CallBackFunction)(void));

#endif /* _EXTI_INTERFACE_H */
