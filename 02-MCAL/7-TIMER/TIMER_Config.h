/**
 * @name        TIMER_Config.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _TIMER_CONFIG_H
#define _TIMER_CONFIG_H

/*
----------------------------------------------------------------------------------------------------
!-                                      AVAILABLE OPTIONS
----------------------------------------------------------------------------------------------------
*/

/**
 * @defgroup: Useful Timer Calculations.
 *
 * For Specific Timer Frequeuncy: Choose your required frequency
 *  Peripheral_Clock/F_OUT = (ARR * Timer_Prescaler).
 *
 */

/**
 * @defgroup: General Timers Configuration
 */

#define TIMER_USE_DELAY       ( TIM4 )
#define TIMER_USE_PWM_1       ( TIM3 )
#define TIMER_USE_PWM_2       ( TIM2 )
#define TIMER_USE_PWM_3       ( TIM6 )
#define TIMER_USE_PWM_4       ( TIM7 )

/**
 * @defgroup: TIM1 Configurations Parameters - ACT
 */

#define TIM1_MODE       ()
#define TIM1_CHANNEL    ()

/**
 * @defgroup: TIM2 Configurations Parameters - GPT
 */

#define TIM2_MODE       ()
#define TIM2_CHANNEL    ()

/**
 * @defgroup: TIM3 Configurations Parameters - GPT
 */

#define TIM3_MODE               (TIM_EDGE_ALIGN_MODE)
#define COUTING_MODE            (TIM_UPCOUNTING_MODE)
#define TIM3_PRESCALER_VALUE    (1U)
#define TIM3_AUTORELOAD_VALUE   (40000U)
/** Timer 3 - Channel 1 Configuration */
#define TIM3_CH1_MODE           (TIM3_CH_PWM_MODE1)
#define TIM3_CH1_CCR            (1U)
/** Timer 3 - Channel 2 Configuration */
#define TIM3_CH2_MODE           (TIM3_CH_PWM_MODE1)
#define TIM3_CH2_CCR            (4000U)
/** Timer 3 - Channel 3 Configuration */
#define TIM3_CH3_MODE           (TIM3_CH_PWM_MODE1)
#define TIM3_CH3_CCR            (4000U)
/** Timer 3 - Channel 4 Configuration */
#define TIM3_CH4_MODE           (TIM3_CH_PWM_MODE1)
#define TIM3_CH4_CCR            (4000U)

/**
 * @defgroup: TIM4 Configurations Parameters - GPT
 */


/**
 * @defgroup: TIM5 Configurations Parameters - GPT
 */


/**
 * @defgroup: TIM6 Configurations Parameters - BUT
 */


/**
 * @defgroup: TIM7 Configurations Parameters - BUT
 */





#endif /* _TIMER_CONFIG_H */
