/**
 * @name        SYSTICK_Interface.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _SYSTICK_INTERFACE_H
#define _SYSTICK_INTERFACE_H

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

/** @defgroup Systick Main Functions */
void SYSTICK_voidInit(void);
void SYSTICK_voidBusyWait(u32 Copy_u32DelayTime);
void SYSTICK_voidIntervalSingle(u32 Copy_u32DelayTime);
void SYSTICK_voidIntervalPeriodic(u32 Copy_u32DelayTime);
void SYSTICK_voidStopTimer(void);
u32 SYSTICK_u32GetElapsedTime(void);
u32 SYSTICK_u32GetRemainingTime(void);
void SYSTICK_voidSetCallBack(void (*Copy_CallBackFunction)(void));

/** @defgroup Systick Sub Functions */
void SYSTICK_voidEnableCounter(void);
void SYSTICK_voidDisableCounter(void);
void SYSTICK_voidEnableInterrupt(void);
void SYSTICK_voidDisableInterrupt(void);
void SYSTICK_voidSetClockSource(u8 Copy_u8ClockSource);

#endif /* _SYSTICK_INTERFACE_H */
