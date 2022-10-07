/**
 * @name        TIMER_Private.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _TIMER_PRIVATE_H
#define _TIMER_PRIVATE_H


/*
----------------------------------------------------------------------------------------------------
!-                                          REGISTER FILE
----------------------------------------------------------------------------------------------------
*/

#define TIM1_BASE_ADDRESS   ( (0x40012C00) )
#define TIM2_BASE_ADDRESS   ( (0x40000000) )
#define TIM3_BASE_ADDRESS   ( (0x40000400) )
#define TIM4_BASE_ADDRESS   ( (0x40000800) )
#define TIM5_BASE_ADDRESS   ( (0x40000C00) )
#define TIM6_BASE_ADDRESS   ( (0x40001000) )
#define TIM7_BASE_ADDRESS   ( (0x40001400) )
//#define TIM8_BASE_ADDRESS   ( (0x40013400) )

typedef struct
{
    u32 CR[2];
    u32 SMCR;
    u32 DIER;
    u32 SR;
    u32 EGR;
    u32 CCMR[2];
    u32 CCER;
    u32 CNT;
    u32 PSC;
    u32 ARR;
    u32 RCR;
    u32 CCR[4];
    u32 BDTR;
    u32 DCR;
    u32 DMAR;
}ST_TIMER1AND8_REGISTERS_t;

typedef struct
{
    u32 CR[2];
    u32 SMCR;
    u32 DIER;
    u32 SR;
    u32 EGR;
    u32 CCMR[2];
    u32 CCER;
    u32 CNT;
    u32 PSC;
    u32 ARR;
    u32 RESERVED_1;
    u32 CCR[4];
    u32 RESERVED_2;
    u32 DCR;
    u32 DMAR;
}ST_TIMER2TO5_REGISTERS_t;

typedef struct
{
    u32 CR[2];
    u32 RESERVED_1;
    u32 DIER;
    u32 SR;
    u32 EGR;
    u32 RESERVED_2[3];
    u32 CNT;
    u32 PSC;
    u32 ARR;
}ST_TIMER6AND7_REGISTERS_t;

#define TIM1 ( (ST_TIMER1AND8_REGISTERS_t volatile *) (TIM1_BASE_ADDRESS) )
#define TIM2 ( (ST_TIMER2TO5_REGISTERS_t  volatile *) (TIM2_BASE_ADDRESS) )
#define TIM3 ( (ST_TIMER2TO5_REGISTERS_t  volatile *) (TIM3_BASE_ADDRESS) )
#define TIM4 ( (ST_TIMER2TO5_REGISTERS_t  volatile *) (TIM4_BASE_ADDRESS) )
#define TIM5 ( (ST_TIMER2TO5_REGISTERS_t  volatile *) (TIM5_BASE_ADDRESS) )
#define TIM6 ( (ST_TIMER6AND7_REGISTERS_t volatile *) (TIM6_BASE_ADDRESS) )
#define TIM7 ( (ST_TIMER6AND7_REGISTERS_t volatile *) (TIM7_BASE_ADDRESS) )
//#define TIM8 ( (ST_TIMER1AND8_REGISTERS_t volatile *) (TIM8_BASE_ADDRESS) )


/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

/**
 * @defgroup: TIMIER 1 & 8 Registers Bits.
 */


/**
 * @defgroup: TIMIER 2 To 5 Registers Bits.
 */

enum CR1_BITS
{
    CEN,
    UDIS,
    OPM,
    DIR,
    CMS0,
		CMS1,
    ARPE,
    CKD0,
    CKD1
};

enum CR2_BITS
{
    CCDS = 3,
    MMS0 = 4,
    MMS1 = 5,
    MMS2 = 6,
    TI1S = 7
};

enum SMCR_BITS
{
    SMS0    = 0,
    SMS1    = 1,
    TS0     = 4,
    TS1     = 5,
    TS2     = 6,
    MSM     = 7,
    ETF0    = 8,
    ETF1    = 9,
    ETF2    = 10,
    ETF3    = 11,
    ETPS0   = 12,
    ETPS1   = 13,
    ECE     = 14,
    ETP     = 15
};

enum DIER_BITS
{
    UIE     = 0,
    CC1IE   = 1,
    CC2IE   = 2,
    CC3IE   = 3,
    CC4IE   = 4,
    TIE     = 6,
    UDE     = 8,
    CC1DE   = 9,
    CC2DE   = 10,
    CC3DE   = 11,
    CC4DE   = 12,
    TDE     = 14
};

enum SR_BITS
{
    UIF   = 0,
    CC1IF = 1,
    CC2IF = 2,
    CC3IF = 3,
    CC4IF = 4,
    TIF   = 5,
    CC1OF = 9,
    CC2OF = 10,
    CC3OF = 11,
    CC4OF = 12
};

enum EGR_BITS
{
    UG 	  = 0,
	CC1G  = 1,
	CC2G  = 2,
	CC3G  = 3,
	CC4G  = 4,
	TG    = 6
};

enum CCMR1_BITS
{
    OC1FE = 2,
    OC1PE = 3,
    OC1CE = 7,
    OC2FE = 10,
    OC2PE = 11,
    OC2CE = 15
};

enum CCER_BITS
{
    CC1E = 0,
    CC1P = 1,
    CC2E = 4,
    CC2P = 5,
    CC3E = 8,
    CC3P = 9,
    CC4E = 12,
    CC4P = 13
};

/**
 * @defgroup: TIMIER 6 & 7 Registers Bits.
 */

/**
 * @defgroup: TIM1 Configurations Parameters
 */

/** @defgroup: Timer 1 - Modes */

/**
 * @defgroup: TIM(2->5) Configurations Parameters
 */

/** @defgroup: Timer - Modes */
#define TIM_EDGE_ALIGN_MODE       (0)
#define TIM_CENTER_ALIGN1_MODE    (1) /** @note: Set when counting down only */
#define TIM_CENTER_ALIGN2_MODE    (2) /** @note: Set when counting up only  */
#define TIM_CENTER_ALIGN3_MODE    (3) /** @note: Set when counting both    */
#define TIM_UPCOUNTING_MODE       (0)
#define TIM_DOWNCOUNTING_MODE     (1)
/** @defgroup: Timer - Channel Configurations */
#define TIM3_CH_FROZEN_MODE         (0)
#define TIM3_CH_MATCHxACTIVE_MODE   (1)
#define TIM3_CH_MATCHxINACTIVE_MODE (2)
#define TIM3_CH_FORCExACTIVE_MODE   (3)
#define TIM3_CH_FORCExINACTIVE_MODE (4)
#define TIM3_CH_TOGGLE_MODE         (5)
#define TIM3_CH_PWM_MODE1           (6)
#define TIM3_CH_PWM_MODE2           (7)

/**
 * @defgroup: TIM6 Configurations Parameters
 */

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

static void voidSetTIM3_SetChannelsMode(void);


#endif /* _TIMER_PRIVATE_H */
