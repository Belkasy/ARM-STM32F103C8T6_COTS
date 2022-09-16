 /*
 *@Name: RCC_Private.h
 *@version v1.0
 *@authors: Abdelrahman Belkasy, Wx
 *Date: 8/11/2022
 *@copyright Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H

/*
----------------------------------------------------------------------------------------------------
!-											REGISTER FILE                                    
----------------------------------------------------------------------------------------------------
*/

/** @def RCC physical memory boundaries */
#define RCC_BASE_ADDRESS    ( (0x40021000ul) )
#define RCC_REGISTERS_NUM	( (cu8) 10)

typedef struct
{
	u32 volatile CR;
	u32 volatile CFGR;
	u32 volatile CIR;
	u32 volatile APB2RSTR;
	u32 volatile APB1RSTR;
	u32 volatile AHBENR;
	u32 volatile APB2ENR;
	u32 volatile APB1ENR;
	u32 volatile BDCR;
	u32 volatile CSR;
}ST_RCC_REGISTERS_t;

#define RCC	( ((ST_RCC_REGISTERS_t volatile * const) (RCC_BASE_ADDRESS)) )

/*
----------------------------------------------------------------------------------------------------
!-									  CONFIGURATION PARAMETERS                                    
----------------------------------------------------------------------------------------------------
*/

/** @defgroup SYSTEM BUS CONTROLLER */
#define   SYSTEM_BUS_AHB           ( (0b0000) )        /* Advanced High Performance Bus */
#define   SYSTEM_BUS_APB1          ( (0b0001) )        /* Advanced Performance Bus 1 */
#define   SYSTEM_BUS_APB2          ( (0b0010) )        /* Advanced Performance Bus 2 */

#define   SYSTEM_PLL               ( (0b0011) )        /* Phase Locked Loop ID */

/** @defgroup SYSTEM INPUT CLOCK SOURCE */
#define   SYSTEM_CLOCK_LSE         ( (0b0000) )      /* Low Speed External Clock Source */
#define   SYSTEM_CLOCK_LSI         ( (0b0001) )      /* Low Speed Internal Clock Source */
#define   SYSTEM_CLOCK_HSE_CRYSTAL ( (0b0010) )      /* High Speed External Clock Source - CRYSTAL */
#define   SYSTEM_CLOCK_HSE_RC      ( (0b0011) )      /* High Speed External Clock Source - RC    */
#define   SYSTEM_CLOCK_HSI         ( (0b0100) )      /* High Speed Internal Clock Source */
#define   SYSTEM_CLOCK_PLL         ( (0b0101) )      /* Phase Locked Loop Clock Source */

/** @defgroup PLL INPUT CLOCK SOURCE */
#define   PLL_INPUT_HSI_DIV_2      ( (0b0000) ) 
#define   PLL_INPUT_HSE_DIV_2      ( (0b0001) ) 
#define   PLL_INPUT_HSE_DIRECT     ( (0b0010) ) 

/** @defgroup AHB PRESCALERS */
#define    AHB_PRESCALER_1        ( (0b0000) )
#define    AHB_PRESCALER_2        ( (0b1000) )
#define    AHB_PRESCALER_4        ( (0b1001) )
#define    AHB_PRESCALER_8        ( (0b1010) )
#define    AHB_PRESCALER_16       ( (0b1011) )
#define    AHB_PRESCALER_64       ( (0b1100) )
#define    AHB_PRESCALER_128      ( (0b1101) )
#define    AHB_PRESCALER_256      ( (0b1110) )
#define    AHB_PRESCALER_512      ( (0b1111) )

/** @defgroup ABP1 PRESCALERS */
#define   APB1_PRESCALER_1        ( (0b000) )
#define   APB1_PRESCALER_2        ( (0b100) )
#define   APB1_PRESCALER_4        ( (0b101) )
#define   APB1_PRESCALER_8        ( (0b110) )
#define   APB1_PRESCALER_16       ( (0b111) )

/** @defgroup ABP2 PRESCALERS */ 
#define    APB2_PRESCALER_1       ( (0b000) )
#define    APB2_PRESCALER_2       ( (0b100) )
#define    APB2_PRESCALER_4       ( (0b101) )
#define    APB2_PRESCALER_8       ( (0b110) )
#define    APB2_PRESCALER_16      ( (0b111) )

#define  PLL_MUL_2    ( (0b0000) )
#define  PLL_MUL_3    ( (0b0001) )
#define  PLL_MUL_4    ( (0b0010) )
#define  PLL_MUL_5    ( (0b0011) )
#define  PLL_MUL_6    ( (0b0100) )
#define  PLL_MUL_7    ( (0b0101) )
#define  PLL_MUL_8    ( (0b0110) )
#define  PLL_MUL_9    ( (0b0111) )
#define  PLL_MUL_10   ( (0b1000) )
#define  PLL_MUL_11   ( (0b1001) )
#define  PLL_MUL_12   ( (0b1010) )
#define  PLL_MUL_13   ( (0b1011) )
#define  PLL_MUL_14   ( (0b1100) )
#define  PLL_MUL_15   ( (0b1101) )
#define  PLL_MUL_16   ( (0b1110) )

enum RCC_CR_BITS
{
    HSION       = 0,    /* R/W, Enable HSI */
    HSIRDY      = 1,    /* R,   Check HSI */
    HSITRIM_3   = 3,    /* R/W, HSI TRIM */
    HSITRIM_4   = 4,    /* R/W, HSI TRIM */
    HSITRIM_5   = 5,    /* R/W, HSI TRIM */
    HSITRIM_6   = 6,    /* R/W, HSI TRIM */
    HSITRIM_7   = 7,    /* R/W, HSI TRIM */
    HSICAL_8    = 8,    /* R,   HSI CALIBRATION */
    HSICAL_9    = 9,    /* R,   HSI CALIBRATION */
    HSICAL_10   = 10,   /* R,   HSI CALIBRATION */
    HSICAL_11   = 11,   /* R,   HSI CALIBRATION */
    HSICAL_12   = 12,   /* R,   HSI CALIBRATION */
    HSICAL_13   = 13,   /* R,   HSI CALIBRATION */
    HSICAL_14   = 14,   /* R,   HSI CALIBRATION */
    HSICAL_15   = 15,   /* R,   HSI CALIBRATION */
    HSEON       = 16,   /* R/W, Enable HSE */
    HSERDY      = 17,   /* R,   Check  HSE */
    HSEBYP      = 18,   /* R/W, HSE  Bypass */
    CSSON       = 19,   /* R/W, Enable  CSS */
    PLLON       = 24,   /* R/W, Enable  PLL */
    PLLRDY      = 25    /* R,   Check  PLL */
};

enum RCC_CFGR_BITS
{
    SW_0        = 0,   /* R/W, System Clock Switch */
    SW_1        = 1,   /* R/W, System Clock Switch */
    SWS_2       = 2,   /* R,   System Clock Switch Status */
    SWS_3       = 3,   /* R,   System Clock Switch Status */
    HPRE_4      = 4,   /* R/W, System AHB  Prescaler */
    HPRE_5      = 5,   /* R/W, System AHB  Prescaler */
    HPRE_6      = 6,   /* R/W, System AHB  Prescaler */
    HPRE_7      = 7,   /* R/W, System AHB  Prescaler */
    PPRE1_8     = 8,   /* R/W, System APB1 Prescaler */
    PPRE1_9     = 9,   /* R/W, System APB1 Prescaler */
    PPRE1_10    = 10,  /* R/W, System APB1 Prescaler */
    PPRE2_11    = 11,  /* R/W, System APB2 Prescaler */
    PPRE2_12    = 12,  /* R/W, System APB2 Prescaler */
    PPRE2_13    = 13,  /* R/W, System APB2 Prescaler */
    ADCPRE_14   = 14,  /* R/W, System ADC  Prescaler */
    ADCPRE_15   = 15,  /* R/W, System ADC  Prescaler */
    PLLSRC      = 16,  /* R/W, Select PLL Source     */
    PLLXTPRE    = 17,  /* R/W, HSE Divider PLL Entry */
    PLLMUL_18   = 18,  /* R/W, PLL Clock Multiplier  */
    PLLMUL_19   = 19,  /* R/W, PLL Clock Multiplier  */
    PLLMUL_20   = 20,  /* R/W, PLL Clock Multiplier  */
    PLLMUL_21   = 21,  /* R/W, PLL Clock Multiplier  */
    USBPRE      = 22,  /* R/W, USB Presacler  */
    MCO_24      = 24,  /* R/W, MCU Clock Source Select  */
    MCO_25      = 25,  /* R/W, MCU Clock Source Select  */
    MCO_26      = 26   /* R/W, MCU Clock Source Select  */
};

enum RCC_CIR_BITS
{
    LSIRDYF     = 0,            /* R, LSI Ready Interrupt Flag */
    LSERDYF     = 1,            /* R, LSE Ready Interrupt Flag */
    HSIRDYF     = 2,            /* R, HSI Ready Interrupt Flag */
    HSERDYF     = 3,            /* R, HSE Ready Interrupt Flag */
    PLLRDYF     = 4,            /* R, PLL Ready Interrupt Flag */
    CSSF        = 7,        /* R, CSS Ready Interrupt Flag */
    LSIRDIE     = 8,            /* R/W, LSI Interrupt Enable */
    LSERDYIE    = 9,           /* R/W, LSE Interrupt Enable */
    HSIRDYIE    = 10,           /* R/W, HSI Interrupt Enable */
    HSERDYIE    = 11,           /* R/W, HSE Interrupt Enable */
    PLLRDYIE    = 12,           /* R/W, PLL Interrupt Enable */
    LSIRDYC     = 16,      /* W,   LSI Interrupt Clear */
    LSERDYC     = 17,            /* W,   LSE Interrupt Clear */
    HSIRDYC     = 18,            /* W,   HSI Interrupt Clear */
    HSERDYC     = 19,            /* W,   HSE Interrupt Clear */
    PLLRDYC     = 20,            /* W,   PLL Interrupt Clear */
    CSSC        = 23       /* W,   CSS Interrupt Clear */
};


/*
----------------------------------------------------------------------------------------------------
!-                                   PRIVATE FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

static void RCC_voidDecoder(cu8 Copy_cu8Bus, cu8 Copy_cu8Value);


static void RCC_voidEnableLSI(u8 Copy_u8SetSystemClockFlag);
static void RCC_voidEnableLSE(u8 Copy_u8SetSystemClockFlag);
static void RCC_voidEnableHSI(u8 Copy_u8SetSystemClockFlag);
static void RCC_voidEnableHSE(u8 Copy_u8SetSystemClockFlag);
static void RCC_voidEnablePLL(u8 Copy_u8SetSystemClockFlag);
static void RCC_voidSetBusPrescaler(void);

#endif /* _RCC_PRIVATE_H */
