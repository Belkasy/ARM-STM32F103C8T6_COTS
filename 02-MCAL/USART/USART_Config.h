/**
 * @name        USART_Config.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _USART_CONFIG_H
#define _USART_CONFIG_H

/*
----------------------------------------------------------------------------------------------------
!-                                      AVAILABLE OPTIONS
----------------------------------------------------------------------------------------------------
*/

#define OVERSAMPLE_RATE		OVERSAMPLE_16
#define SYSTEM_CLOCK 		(1000000U)

#define BRR_VALUE	(0x0068)	/** @note: 1M Hz - 9600b/s */

#endif /* _USART_CONFIG_H */
