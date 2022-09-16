/**
 * @name        RTOS_Private.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _RTOS_PRIVATE_H
#define _RTOS_PRIVATE_H

/*
----------------------------------------------------------------------------------------------------
!-                                          Defines
----------------------------------------------------------------------------------------------------
*/

/** @def: Task Function Format */
typedef void (*ThreadFunctionPointer_t)(void);

/** @def: Task (Thread) data */
typedef struct
{
//    void *StackPointer;
/** @todo: Add more thread features */
    u8 FirstDelay;
    u8 State;
    u16 Priodicity;
    ThreadFunctionPointer ThreadFunction;
}__ST_OSThread_t;

enum THREAD_STATES
{
    Thread_Dormant,
    Thread_Waiting,
    Thread_Ready,
    Thread_Running,
    Thread_Suspended
};

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

static void voidNaiveScheduler(void);

/**
 * @defgroup: RTOS Thread API's
 */
static void voidSuspendThread(u8 Copy_u8ThreadID);
static void voidResumeThread(u8 Copy_u8ThreadID);
static void voidDeleteThread(u8 Copy_u8ThreadID);

#endif /* _RTOS_PRIVATE_H */
