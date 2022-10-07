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

enum THREAD_STATES
{
    Thread_Dormant,
    Thread_Waiting,
    Thread_Ready,
    Thread_Running,
    Thread_Suspended
};

/** @def: Task Function Format */
typedef void (*ThreadFunctionPointer_t)(void);

/** @def: Task (Thread) data */
__attribute__((packed))
typedef struct /** @todo: Add more thread features */
{
    void *StackPointer;
    u8 FirstDelay;
    u8 State;
    u16 Priodicity;
    ThreadFunctionPointer_t ThreadFunction;
}__ST_OSThread_t;

/**
 * @brief:
 *  Struct for the rtos threads linked lists.
 */
__attribute__((packed))
typedef struct
{
    void *OSThread;
    void *OSList;
    struct __ST_OSLinkedList_t *next;
    struct __ST_OSLinkedList_t *prev;
}__ST_OSLinkedList_t;
/**
 * @brief:
 *  Struct for rtos list (Waiting-Ready-Blocked-etc)
 */
__attribute__((packed))
typedef struct
{
    u32 NumOfItems;
    __ST_OSLinkedList_t *Index;
}__ST_OSList_t;
/**
 * @brief:
 *  Struct for the thread control block in the stack.
 */
__attribute__((packed))
typedef struct
{
    u64 Stack[__THREAD_STACK_SIZE];
}__ST_OSStack_t;


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

/**
 * @defgroup: Linked lists API's
 */
static void voidListInit(void);
static void voidListAppendItemAtLast(void);
static void voidListPushItemAtBegin(void);
static void voidListRemoveItemAtBegin(void);
static void voidListRemoveItemAtLast(void);

#endif /* _RTOS_PRIVATE_H */
