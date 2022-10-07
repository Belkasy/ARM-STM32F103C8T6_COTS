/**
 * @name        TIMER_Program.c
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup  USART Related Headers */
#include "TIMER_Config.h"
#include "TIMER_Private.h"
#include "TIMER_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                  Global Variables
----------------------------------------------------------------------------------------------------
*/


/*
----------------------------------------------------------------------------------------------------
!-                                  TIMER 1 & 8 Function  PROGRAM
----------------------------------------------------------------------------------------------------
*/


/*
----------------------------------------------------------------------------------------------------
!-                                  TIMER 2 To 5 Function  PROGRAM
----------------------------------------------------------------------------------------------------
*/
/** @defgroup: TIMER_2 API's */
void TIMER_voidTIM2_Init(void)
{
    /** Enable Timer */
    BIT_SET(TIM2->CR[0], CEN);
}/** @end TIMER_voidTIM2_Init */

/** @defgroup: TIMER_3 API's */
void TIMER_voidTIM3_Init(void)
{
/** @def: Configure the general timer */
#if   (TIM3_MODE == TIM_EDGE_ALIGN_MODE)
    BIT_CLR(TIM3->CR[0], CMS0);
    BIT_CLR(TIM3->CR[0], CMS1);
    #if   (COUTING_MODE == TIM_UPCOUNTING_MODE)
    BIT_CLR(TIM3->CR[0], DIR);
    #elif (COUTING_MODE == TIM_DOWNCOUNTING_MODE)
    BIT_SET(TIM3->CR[0], DIR);
    #else
        #error ("TIMER3 COUNTING MODE CORRUPTED!")
    #endif
#elif (TIM3_MODE == TIM_CENTER_ALIGN1_MODE)
    BIT_SET(TIM3->CR[0], CMS0);
    BIT_CLR(TIM3->CR[0], CMS1);
#elif (TIM3_MODE == TIM_CENTER_ALIGN2_MODE)
    BIT_CLR(TIM3->CR[0], CMS0);
    BIT_SET(TIM3->CR[0], CMS1);
#elif (TIM3_MODE == TIM_CENTER_ALIGN3_MODE)
    BIT_SET(TIM3->CR[0], CMS0);
    BIT_SET(TIM3->CR[0], CMS1);
#else
    #error ("TIMER3 MODE CORRUPTED!")
#endif
    voidSetTIM3_SetChannelsMode();
    /** Set The AutoReload - Masked 16-bit value */
    REG_WRT(TIM3->ARR, (TIM3_AUTORELOAD_VALUE & 0xFFFF));
    /** Set The Prescaler Value - Masked 16-bit value */
    REG_WRT(TIM3->PSC, (TIM3_PRESCALER_VALUE & 0xFFFF));
    /** Enable Timer */
    BIT_SET(TIM3->CR[0], CEN);
}/** @end TIMER_voidTIM3_Init */

void TIMER_voidTIM3_DelayMS(u32 Copy_u32DelayMS);
/**
 * @brief: Output PWM frequency is dependent on "ARR Value & Prescaler"
 *         Output PWM DutyCycle is depentent on "CCRx Value"
 */
void TIMER_voidTIM3_PWM(u32 Copy_u32Frequency, u8 Copy_u8DutyCycle);

/*
----------------------------------------------------------------------------------------------------
!-                                  TIMER 6 & 7 Function  PROGRAM
----------------------------------------------------------------------------------------------------
*/














/*
----------------------------------------------------------------------------------------------------
!-                                  TIMER 1 & 8 Function  Private
----------------------------------------------------------------------------------------------------
*/

/** @defgroup: TIMER_1 API's */

/*
----------------------------------------------------------------------------------------------------
!-                                  TIMER 2 To 5 Function  Private
----------------------------------------------------------------------------------------------------
*/


/** @defgroup: TIMER_2 API's */


/** @defgroup: TIMER_3 API's */
static void voidSetTIM3_SetChannelsMode(void)
{
/** @def: Detect if channel is active */
#if ( (TIM3_CH1_MODE > -1) )
    /** @defgroup: Channel Output Capture Modes */
    #if   (TIM3_CH1_MODE == TIM3_CH_FROZEN_MODE)
    TIM3->CCMR[0] &= (~(0b111 << 4u));
    TIM3->CCMR[0] |= (0b000 << 4u); /** @def: Set the Mode */

    #elif (TIM3_CH1_MODE == TIM3_CH_MATCHxACTIVE_MODE)
    TIM3->CCMR[0] &= (~(0b111 << 4u));
    TIM3->CCMR[0] |= (0b001 << 4u); /** @def: Set the Mode */

    #elif (TIM3_CH1_MODE == TIM3_CH_MATCHxINACTIVE_MODE)
    TIM3->CCMR[0] &= (~(0b111 << 4u));
    TIM3->CCMR[0] |= (0b010 << 4u); /** @def: Set the Mode */

    #elif (TIM3_CH1_MODE == TIM3_CH_TOGGLE_MODE)
    TIM3->CCMR[0] &= (~(0b111 << 4u));
    TIM3->CCMR[0] |= (0b011 << 4u); /** @def: Set the Mode */

    #elif (TIM3_CH1_MODE == TIM3_CH_FORCExACTIVE_MODE)
    TIM3->CCMR[0] &= (~(0b111 << 4u));
    TIM3->CCMR[0] |= (0b100 << 4u); /** @def: Set the Mode */

    #elif (TIM3_CH1_MODE == TIM3_CH_FORCExINACTIVE_MODE)
    TIM3->CCMR[0] &= (~(0b111 << 4u));
    TIM3->CCMR[0] |= (0b101 << 4u); /** @def: Set the Mode */

    #elif (TIM3_CH1_MODE == TIM3_CH_PWM_MODE1)
    BIT_SET(TIM3->CR[0], ARPE); /** @def: Enable auto-reload preload. */
		BIT_SET(TIM3->CCER, CC1P); /** @def: Define as active low. */
    TIM3->CCMR[0] &= (~(0b11));
    TIM3->CCMR[0] |= (0b00); /** @def: Set as output capture */
    TIM3->CCMR[0] &= (~(0b111 << 4u));
    TIM3->CCMR[0] |= (0b110 << 4u); /** @def: Enable the channel mode . */
    REG_WRT(TIM3->CCR[0], TIM3_CH1_CCR); /** @def: Set the CC value. */
    BIT_SET(TIM3->CCMR[0], OC1PE);  /** @def: Enable Preload */
	BIT_SET(TIM3->EGR, UG); /** @def: Enable the update generation. */
    BIT_SET(TIM3->CCER, CC1E); /** @def: Enable the channel mode. */

    #elif (TIM3_CH1_MODE == TIM3_CH_PWM_MODE2)
    BIT_SET(TIM3->CR[0], ARPE); /** @def: Enable auto-reload preload. */
    BIT_SET(TIM3->EGR, UG); /** @def: Enable the update generation. */
    BIT_SET(TIM3->CCER, CC1P); /** @def: Define as active low. */
    TIM3->CCMR[0] &= (~(0b11));
    TIM3->CCMR[0] |= (0b00); /** @def: Set as output capture */
    TIM3->CCMR[0] &= (~(0b111 << 4u));
    TIM3->CCMR[0] |= (0b111 << 4u); /** @def: Set the Mode. */
    REG_WRT(TIM3->CCR[0], TIM3_CH1_CCR); /** @def: Set the CC value. */
    BIT_SET(TIM3->CCMR[0], OC1PE);  /** @def: Enable Preload */
    BIT_SET(TIM3->CCER, CC1E); /** @def: Enable the channel mode. */
    #else
        #error ("TIMER3 CHANNEL_1 MODE CORRUPTED!")
    #endif
#endif

    /** @todo: Add the other Timer 3 Channels */
}/** @end voidSetTIM3_ChannelsMode */

/*
----------------------------------------------------------------------------------------------------
!-                                  TIMER 6 & 7 Function  Private
----------------------------------------------------------------------------------------------------
*/


