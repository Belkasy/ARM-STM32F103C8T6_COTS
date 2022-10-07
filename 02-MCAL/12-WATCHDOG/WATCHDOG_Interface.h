/**
 * @name        WATCHDOG_Interface.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _WATCHDOG_INTERFACE_H
#define _WATCHDOG_INTERFACE_H

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

void IWDT_voidInit(void);
void IWDT_voidCounterStart(u16 Copy_u16CounterValue);
void IWDT_voidCounterStop(void);

void WWDT_voidInit(void);
void WWDT_voidDisable(void);
void WWDT_voidCounterStart(u16 Copy_u16CounterValue);
void WWDT_voidCounterStop(void);

#endif /* _WATCHDOG_INTERFACE_H */
