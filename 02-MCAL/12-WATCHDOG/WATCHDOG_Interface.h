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

void WWDT_voidStart(float millis);
void WWDT_voidRestart(void);
void WWDT_voidStop(void);

#endif /* _WATCHDOG_INTERFACE_H */
