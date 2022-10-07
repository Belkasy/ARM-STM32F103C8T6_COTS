/**
 * @name        RTOS_Config.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _RTOS_CONFIG_H
#define _RTOS_CONFIG_H

/*
----------------------------------------------------------------------------------------------------
!-                                      AVAILABLE OPTIONS
----------------------------------------------------------------------------------------------------
*/

/**
 * @brief:Number of threads used in the system
 */
#define __NUM_OF_THREADS        (3U)
/**
 * - @note: Add time in (microsecondes)
 *      For example: 1ms -> 1000U (us)
 */
#define __OS_PERIODIC_TIME      (1000U)
/**
 * @brief: CPU clock frequency in hertz
 */
#define __SYSTEM_CORE_CLOCK_HZ  (180000000ul)
/**
 * @brief: Max priority group used
 */
#define __MAX_OS_PRIORITES       (15u)
/**
 * @brief: TCB Stack size used
 */
#define __THREAD_STACK_SIZE      (1024u)
#endif /* _RTOS_CONFIG_H */
