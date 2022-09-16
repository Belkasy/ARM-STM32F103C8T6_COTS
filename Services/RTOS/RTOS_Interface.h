/**
 * @name        RTOS_Interface.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _RTOS_INTERFACE_H
#define _RTOS_INTERFACE_H

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

void RTOS_voidCreateThread(u8 Copy_u8ThreadID,
                           u16 Copy_u16Priority,
                           ThreadFunctionPointer_t Copy_tThreadFunction);
void RTOS_voidStart(void);


#endif /* _RTOS_INTERFACE_H */
