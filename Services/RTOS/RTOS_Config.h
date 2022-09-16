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

#define __NUM_OF_THREADS  (3U)

/**
 * @def: Configratuin parameters
 * - @note: Add time in (microsecondes)
 *      For example: 1ms -> 1000U (us)
 */
#define __OS_PERIODIC_TIME (1000U)

#endif /* _RTOS_CONFIG_H */
