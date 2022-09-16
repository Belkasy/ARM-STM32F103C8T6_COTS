/**
 * @name        RTOS_Program.c
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup Related Headers */
#include "../../02-MCAL/6-SYSTICK/SYSTICK_Interface.h"

#include "RTOS_Config.h"
#include "RTOS_Private.h"
#include "RTOS_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                  Global Variables
----------------------------------------------------------------------------------------------------
*/

/** @def: Array of thread struct */
__ST_OSThread_t __RTOS_Threads[__NUM_OF_THREADS] = { NULL };

static u16 volatile TickCounter = 0;

/*
----------------------------------------------------------------------------------------------------
!-                                  RTOS PROGRAM
----------------------------------------------------------------------------------------------------
*/

void RTOS_voidCreateThread(u8 Copy_u8ThreadID,
                          u16 Copy_u16Priodicity,
                          ThreadFunctionPointer_t Copy_tThreadFunction)
{
    /** @def: Create Thread in the OS */
    __RTOS_Threads[Copy_u8ThreadID].Priodicity = Copy_u16Priodicity;
    __RTOS_Threads[Copy_u8ThreadID].ThreadFunction = Copy_tThreadFunction;
}/** @end RTOS_voidCreateThread */

void RTOS_voidStart(void)
{
    /** @defgroup: Init the tick timer */
    /**
     * @brief:
     *  SysTick: Periodically 1ms interrupt.
     */
    SYSTICK_voidInit();
    SYSTICK_voidIntervalPeriodic(__OS_PERIODIC_TIME);
    SYSTICK_voidSetCallBack(voidScheduler);
}/** @end RTOS_voidStart */

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

/**
 * @brief: RTOS Scheduler function is the backbone of the RTOS.
 * - Algorithm: The algorithm used to switch between threads.
 * - Dispatcher: The algorithm for actual CPU context switching (Saving)
 *               between threads.
 *
 * @todo: Add different algorithm for schedulers.
 *        .RoundRobin, FCFS, LTFS, STFS, etc...
 * @todo: Implement the dispatcher technique (ASM).
 */
static void voidNaiveScheduler(void)
{
    for(u8 L_u8ThreadID = 0; (L_u8ThreadID < NUM_OF_THREADS); ++L_u8ThreadID)
    {
        if( (__RTOS_Threads[L_u8ThreadID].ThreadFunction != NULL) &&
            (__RTOS_Threads[L_u8ThreadID].State == Thread_Ready) )
        {
            if( (__RTOS_Threads[L_u8ThreadID].FirstDelay == 0) )
            {
                /** @def: Treat the FirstDelay as priodicity of the thread */
                __RTOS_Threads[L_u8ThreadID].FirstDelay =
                (__RTOS_Threads[L_u8ThreadID].Priodicity - 1);
                /** @def: Call the thread function and execute it */
                __RTOS_Threads[L_u8ThreadID].ThreadFunction();
            }
            else
            {
                __RTOS_Threads[L_u8ThreadID].FirstDelay -= 1;
            }
        }else {;}
    }/** @end: For loop */
}/** @end voidScheduler */
