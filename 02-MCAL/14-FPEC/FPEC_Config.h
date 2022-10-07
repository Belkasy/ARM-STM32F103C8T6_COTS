/**
 * @name        FPEC_Config.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _FPEC_CONFIG_H
#define _FPEC_CONFIG_H

/*
----------------------------------------------------------------------------------------------------
!-                                      AVAILABLE OPTIONS
----------------------------------------------------------------------------------------------------
*/

/**
 * @brief: Genearl notes about FPEC
 * - Writing to the flash: By page.
 * - Erasing the flash: By Sector. (Multiple number of bytes)
 */



/** @note: Size in words */
#define FLASH_PAGE_SIZE     (64u)

#endif /* _FPEC_CONFIG_H */
