/**
 * @name        USART_Private.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _USART_PRIVATE_H
#define _USART_PRIVATE_H


/*
----------------------------------------------------------------------------------------------------
!-                                          REGISTER FILE
----------------------------------------------------------------------------------------------------
*/

#define USART1_BASE_ADDRESS  ( (0x40013800) )
#define USART2_BASE_ADDRESS  ( (0x40004400) )
#define USART3_BASE_ADDRESS  ( (0x40004800) )

typedef struct
{
    u32 volatile SR;
    u32 volatile DR;
    u32 volatile BRR;
    u32 volatile CR[3];
    u32 volatile GTPR;
}ST_USART_REGISTERS_t;

#define USART1   ( ((ST_USART_REGISTERS_t volatile *) (USART1_BASE_ADDRESS)) )
#define USART2   ( ((ST_USART_REGISTERS_t volatile *) (USART2_BASE_ADDRESS)) )
#define USART3   ( ((ST_USART_REGISTERS_t volatile *) (USART3_BASE_ADDRESS)) )

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

typedef void (*USART_CallBackFunctionFormat)(void);
#define NUM_OF_USART    (3U)
#define OVERSAMPLE_8	(8U)
#define OVERSAMPLE_16 	(16U)
#define MAX_BUFFER_SIZE (32U)

enum SR_BITS    /** @note Flags Register (Status)*/
{
    PE,     /** @note: Parity Error */
    FE,     /** @note: Framing Error */
    NE,     /** @note: Noise Error */
    ORE,    /** @note: Overrun Error */
    IDLE,   /** @note: Idle Line Detect */
    RXNE,   /** @note: Read Data Register Not Empty */
    TC,     /** @note: Transmission Complete */
    TXE,    /** @note: Transmitt Data Register Empty */
    LBD,    /** @note: LIN Break Detection */
    CTS     /** @note: CTS Flag */
};  /** @note Other bits are reserved */

enum CR1_BITS
{
    SBK,
    RWU,
    RE,
    TE,
    IDLEIE,
    RXENIE,
    TCIE,
    TXEIE,
    PEIE,
    PS,
    PCE,
    WAKE,
    M,
    UE
};  /** @note Other bits are reserved */

enum CR2_BITS
{
    ADD0    = 0,
    ADD1    = 1,
    ADD2    = 2,
    ADD3    = 3,
    LBDL    = 5,
    LBDIE   = 6,
    LBCL    = 8,
    CPHA    = 9,
    CPOL    = 10,
    CLKEN   = 11,
    STOP0   = 12,
    STOP1   = 13,
    LINEN   = 14
};  /** @note Other bits are reserved */

enum CR3_BITS
{
    EIE,
    IREN,
    IRLP,
    HDSEL,
    NACK,
    SCEN,
    DMAR,
    DMAT,
    RTSE,
    CTSE,
    CTSIE
};  /** @note Other bits are reserved */

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

static void voidUsartEnable(u8 Copy_u8UsartID);
static void voidUsartDisable(u8 Copy_u8UsartID);
static void voidSetWordLength(u8 Copy_u8UsartID, u8 Copy_u8DataWord);
static void voidSetStopBits(u8 Copy_u8UsartID, u8 Copy_u8StopBits);
static void voidSetWakeupMethod(u8 Copy_u8UsartID, u8 Copy_u8WakeupMethod);
static void voidParityControl(u8 Copy_u8UsartID, u8 Copy_u8ParityState);
static void voidParitySelection(u8 Copy_u8UsartID, u8 Copy_u8ParityMode);
static void voidUsartMode(u8 Copy_u8UsartID, u8 Copy_u8UsartMode);
static void voidSetBaudRate(u8 Copy_u8UsartID, u32 Copy_u32BaudRate);
static void voidCalculateBaudRate(u32 Copy_u32BaudRate, u16 *Address_u16BRRValue);

static void voidSetUsart1Mode(u8 Copy_u8Usart1Mode);
static void voidSetUsart2Mode(u8 Copy_u8Usart2Mode);
static void voidSetUsart3Mode(u8 Copy_u8Usart3Mode);
static void voidSetUsart1StopBits(u8 Copy_u8Usart1StopBits);
static void voidSetUsart2StopBits(u8 Copy_u8Usart2StopBits);
static void voidSetUsart3StopBits(u8 Copy_u8Usart3StopBits);

static void voidUsartTransmitViaInterrupt(ST_USART_REGISTERS_t *Copy_Usart,
                                          u8 *Address_u8TxBuffer,
                                          u32 *Address_u32TxCounter);
static void voidUsartRecieveViaInterrupt(ST_USART_REGISTERS_t *Copy_Usart,
                                         u8 *Address_u8TxBuffer,
                                         u32 *Address_u32TxCounter);
#endif /* _USART_PRIVATE_H */
