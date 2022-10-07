/**
 * @name        TIMER_Interface.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _TIMER_INTERFACE_H
#define _TIMER_INTERFACE_H

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

/**
 * @defgroup: TIM1 & TIM8 Functions prototype
 */
/** @defgroup: TIMER_1 API's */
void TIMER_voidTIM1_Init(void);

/**
 * @defgroup: TIM2 To TIM5 Functions prototype
 */
/** @defgroup: TIMER_2 API's */
void TIMER_voidTIM2_Init(void);
/** @defgroup: TIMER_3 API's */
void TIMER_voidTIM3_Init(void);
void TIMER_voidTIM3_DelayMS(u32 Copy_u32DelayMS);
void TIMER_voidTIM3_PWM(u32 Copy_u32Frequency, u8 Copy_u8DutyCycle);

/**
 * @defgroup: TIM6 & TIM7 Functions prototype
 */

#endif /* _TIMER_INTERFACE_H */
