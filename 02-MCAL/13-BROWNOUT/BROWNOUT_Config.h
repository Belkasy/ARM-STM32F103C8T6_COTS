/**
 * @name        BROWNOUT_Config.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _BROWNOUT_CONFIG_H
#define _BROWNOUT_CONFIG_H

/*
----------------------------------------------------------------------------------------------------
!-                                      AVAILABLE OPTIONS
----------------------------------------------------------------------------------------------------
*/

/**
 * @brief: The voltage threshold to be detected
 * @def: Configuration Parameters
 * - BROWNOUT_THRESHOLD_2v2
 * - BROWNOUT_THRESHOLD_2v3
 * - BROWNOUT_THRESHOLD_2v4
 * - BROWNOUT_THRESHOLD_2v5
 * - BROWNOUT_THRESHOLD_2v6
 * - BROWNOUT_THRESHOLD_2v7
 * - BROWNOUT_THRESHOLD_2v8
 * - BROWNOUT_THRESHOLD_2v9
 */
#define BROWNOUT_THRESHOLD          (BROWNOUT_THRESHOLD_2v6)
/**
 * @brief: Enable / Diable the brownout
 * @def: Configuration Parameters
 * - BROWNOUT_ENABLE
 * - BROWNOUT_DISABLE
 */
#define BROWNOUT_STATE              (BROWNOUT_DISABLE)
/**
 * @brief: Setting the system mode after detecting.
 * @def: Configuration Parameters
 * - BROWNOUT_STOP_MODE
 * - BROWNOUT_STANDBY_MODE
 */
#define BROWNOUT_MODE               (BROWNOUT_STOP_MODE)
/**
 * @brief: Setting the system mode after detecting.
 * @def: Configuration Parameters
 * - BROWNOUT_REGULATOR_ON
 * - BROWNOUT_REGULATOR_LOW
 */
#define BROWNOUT_REGULATOR          (BROWNOUT_REGULATOR_LOW)



#endif /* _BROWNOUT_CONFIG_H */
