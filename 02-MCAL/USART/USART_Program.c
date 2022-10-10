/**
 * @name        USART_Program.c
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup  USART1 Related Headers */
#include "USART_Config.h"
#include "USART_Private.h"
#include "USART_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                  Global Variables
----------------------------------------------------------------------------------------------------
*/

USART_CallBackFunctionFormat USART_CallBackFunction[NUM_OF_USART] = {NULL};

/** @defgroup Global Tx Usart Parameter */
u8 *G_u8Usart1TxBuffer = NULL;
u8 *G_u8Usart2TxBuffer = NULL;
u8 *G_u8Usart3TxBuffer = NULL;
u32 G_u32Usart1TxCounter = 0;
u32 G_u32Usart2TxCounter = 0;
u32 G_u32Usart3TxCounter = 0;
/** @defgroup Global Rx Usart Parameter */
u8 *G_u8Usart1RxBuffer = NULL;
u8 *G_u8Usart2RxBuffer = NULL;
u8 *G_u8Usart3RxBuffer = NULL;
u32 G_u32Usart1RxCounter = 0;
u32 G_u32Usart2RxCounter = 0;
u32 G_u32Usart3RxCounter = 0;

/*
----------------------------------------------------------------------------------------------------
!-                                  USART1 Function  PROGRAM
----------------------------------------------------------------------------------------------------
*/

void USART_voidInit(const ST_USARTConfig_t *UsartConfig)
{
    voidSetWordLength(UsartConfig->UsartID, UsartConfig->DataBits);
    voidSetStopBits(UsartConfig->UsartID, UsartConfig->StopBits);
    voidParityControl(UsartConfig->UsartID, UsartConfig->Parity);
    voidUsartMode(UsartConfig->UsartID, UsartConfig->UsartMode);
    voidSetBaudRate(UsartConfig->UsartID, UsartConfig->Baudrate);
    voidUsartEnable(UsartConfig->UsartID);
}/** @end USART1_voidInit */

void USART1_voidTransmitDataSync(u8 *Address_u8TxBuffer, u32 Copy_u32TxBytes)
{
    u8 L_u8Counter = 0;

    for(L_u8Counter = 0; (L_u8Counter < Copy_u32TxBytes); ++L_u8Counter)
    {
        while(!(BIT_GET(USART1->SR, TXE)));
        USART1->DR = Address_u8TxBuffer[L_u8Counter] & 0xFF;
    }

    while(!(BIT_GET(USART1->SR, TC)));

    BIT_CLR(USART1->SR, TC);

    return;
}/** @end USART1_voidTransmitDataSync */

void USART1_voidRecieveDataSnyc(u8 *Address_u8RxBuffer, u32 Copy_u32RxBytes)
{
    u8 L_u8Counter = 0;

    for(L_u8Counter = 0; (L_u8Counter < Copy_u32RxBytes); ++L_u8Counter)
    {
        while(!(BIT_GET(USART1->SR, RXNE)));
        Address_u8RxBuffer[L_u8Counter] = USART1->DR;
    }

    return;
}/** @end USART1_voidRecieveDataSnyc */
void USART1_voidTransmitDataAsync(u8 *Address_u8TxBuffer)
{
    /** @def: Set the global buffer */
    G_u8Usart1TxBuffer = Address_u8TxBuffer;
    /** @def: Start the transmission */
    USART1->DR = Address_u8TxBuffer[0] & 0xFF;
    /** @def: Enable TXE Interrupt */
    BIT_SET(USART1->CR[0], TXEIE);
}/** @end USART1_voidTransmitDataAsync */
void USART1_voidRecieveDataAsync(u8 *Address_u8RxBuffer)
{
    /** @def: Set the global buffer */
    G_u8Usart1RxBuffer = Address_u8RxBuffer;
    /** @def: Enable RXE Interrupt */
    BIT_SET(USART1->CR[0], RXENIE);
}/** @end USART1_voidRecieveDataAsync */

void USART2_voidTransmitDataSync(u8 *Address_u8TxBuffer, u32 Copy_u32TxBytes)
{
    u8 L_u8Counter = 0;

    for(L_u8Counter = 0; (L_u8Counter < Copy_u32TxBytes); ++L_u8Counter)
    {
        while(!(BIT_GET(USART2->SR, TXE)));
        USART2->DR = Address_u8TxBuffer[L_u8Counter] & 0xFF;
    }

    while(!(BIT_GET(USART2->SR, TC)));

    BIT_CLR(USART2->SR, TC);

    return;
}/** @end USART2_voidTransmitDataSync */


void USART2_voidRecieveDataSnyc(u8 *Address_u8RxBuffer, u32 Copy_u32RxBytes)
{
    u8 L_u8Counter = 0;

    for(L_u8Counter = 0; (L_u8Counter < Copy_u32RxBytes); ++L_u8Counter)
    {
        while(!(BIT_GET(USART2->SR, RXNE)));
        Address_u8RxBuffer[L_u8Counter] = USART2->DR;
    }

    return;
}/** @end USART2_voidRecieveDataSnyc */
void USART2_voidTransmitDataAsync(u8 *Address_u8TxBuffer)
{
    /** @def: Set the global buffer */
    G_u8Usart2TxBuffer = Address_u8TxBuffer;
    /** @def: Start the transmission */
    USART2->DR = Address_u8TxBuffer[0] & 0xFF;
    /** @def: Enable TXE Interrupt */
    BIT_SET(USART2->CR[0], TXEIE);
}/** @end USART2_voidTransmitDataAsync */
void USART2_voidRecieveDataAsync(u8 *Address_u8RxBuffer)
{
    /** @def: Set the global buffer */
    G_u8Usart2RxBuffer = Address_u8RxBuffer;
    /** @def: Enable RXE Interrupt */
    BIT_SET(USART2->CR[0], RXENIE);
}/** @end USART2_voidRecieveDataAsync */

void USART3_voidTransmitDataSync(u8 *Address_u8TxBuffer, u32 Copy_u32TxBytes)
{
    u8 L_u8Counter = 0;

    for(L_u8Counter = 0; (L_u8Counter < Copy_u32TxBytes); ++L_u8Counter)
    {
        while(!(BIT_GET(USART3->SR, TXE)));
        USART3->DR = Address_u8TxBuffer[L_u8Counter] & 0xFF;
    }

    while(!(BIT_GET(USART3->SR, TC)));

    BIT_CLR(USART3->SR, TC);

    return;
}/** @end USART3_voidTransmitDataSync */
void USART3_voidRecieveDataSnyc(u8 *Address_u8RxBuffer, u32 Copy_u32RxBytes)
{
    u8 L_u8Counter = 0;

    for(L_u8Counter = 0; (L_u8Counter < Copy_u32RxBytes); ++L_u8Counter)
    {
        while(!(BIT_GET(USART3->SR, RXNE)));
        Address_u8RxBuffer[L_u8Counter] = USART3->DR;
    }

    return;
}/** @end USART3_voidRecieveDataSnyc */
void USART3_voidTransmitDataAsync(u8 *Address_u8TxBuffer)
{
    /** @def: Set the global buffer */
    G_u8Usart3TxBuffer = Address_u8TxBuffer;
    /** @def: Start the transmission */
    USART3->DR = Address_u8TxBuffer[0] & 0xFF;
	  /** @def: Enable TXE Interrupt */
    BIT_SET(USART3->CR[0], TXEIE);
}/** @end USART3_voidTransmitDataAsync */
void USART3_voidRecieveDataAsync(u8 *Address_u8RxBuffer)
{
    /** @def: Set the global buffer */
    G_u8Usart3RxBuffer = Address_u8RxBuffer;
    /** @def: Enable RXE Interrupt */
    BIT_SET(USART3->CR[0], RXENIE);
}/** @end USART3_voidRecieveDataAsync */

void USART_voidSetCallBack(u8 Copy_u8UsartID, USART_CallBackFunctionFormat Copy_CallBackFunction)
{
    if( (Copy_CallBackFunction != NULL) )
    {
        USART_CallBackFunction[Copy_u8UsartID] = Copy_CallBackFunction;
    }else;
}/** @end USART_voidSetCallBack */

/*
----------------------------------------------------------------------------------------------------
!-                                  USART Function  PRIVATE
----------------------------------------------------------------------------------------------------
*/

static void voidUsartEnable(u8 Copy_u8UsartID)
{
    switch(Copy_u8UsartID)
    {
        case USART1_ID: BIT_SET(USART1->CR[0], UE);     break;
        case USART2_ID: BIT_SET(USART2->CR[0], UE);     break;
        case USART3_ID: BIT_SET(USART3->CR[0], UE);     break;
        default: break; /* Error handler */
    }
}/** @end voidUsartEnable */

static void voidUsartDisable(u8 Copy_u8UsartID)
{
    switch(Copy_u8UsartID)
    {
        case USART1_ID: BIT_CLR(USART1->CR[0], UE);     break;
        case USART2_ID: BIT_CLR(USART2->CR[0], UE);     break;
        case USART3_ID: BIT_CLR(USART3->CR[0], UE);     break;
        default: break; /* Error handler */
    }
}/** @end voidUsartDisable */

static void voidSetWordLength(u8 Copy_u8UsartID, u8 Copy_u8DataWord)
{
    switch(Copy_u8UsartID)
    {
        case USART1_ID: BIT_WRT(USART1->CR[0], M, Copy_u8DataWord);      break;
        case USART2_ID: BIT_WRT(USART2->CR[0], M, Copy_u8DataWord);      break;
        case USART3_ID: BIT_WRT(USART3->CR[0], M, Copy_u8DataWord);      break;
        default: break; /* Error handler */
    }
}/** @end voidSetWordLength */

static void voidSetStopBits(u8 Copy_u8UsartID, u8 Copy_u8StopBits)
{
    switch(Copy_u8UsartID)
    {
        case USART1_ID: voidSetUsart1StopBits(Copy_u8StopBits);     break;
        case USART2_ID: voidSetUsart2StopBits(Copy_u8StopBits);     break;
        case USART3_ID: voidSetUsart3StopBits(Copy_u8StopBits);     break;
        default: break; /* Error handler */
    }
}/** @end voidSetStopBits */

static void voidSetWakeupMethod(u8 Copy_u8UsartID, u8 Copy_u8WakeupMethod)
{
    ; /** @todo */
}/** @end voidSetWakeupMethod */

static void voidParityControl(u8 Copy_u8UsartID, u8 Copy_u8ParityState)
{
    switch(Copy_u8UsartID)
    {
        case USART1_ID: BIT_WRT(USART1->CR[0], PCE, Copy_u8ParityState);     break;
        case USART2_ID: BIT_WRT(USART2->CR[0], PCE, Copy_u8ParityState);     break;
        case USART3_ID: BIT_WRT(USART3->CR[0], PCE, Copy_u8ParityState);     break;
        default: break; /* Error handler */
    }
}/** @end voidParityControl */
static void voidParitySelection(u8 Copy_u8UsartID, u8 Copy_u8ParityMode)
{
    switch(Copy_u8UsartID)
    {
        case USART1_ID: BIT_WRT(USART1->CR[0], PS, Copy_u8ParityMode);     break;
        case USART2_ID: BIT_WRT(USART2->CR[0], PS, Copy_u8ParityMode);     break;
        case USART3_ID: BIT_WRT(USART3->CR[0], PS, Copy_u8ParityMode);     break;
        default: break; /* Error handler */
    }
}/** @end voidParitySelection */

static void voidUsartMode(u8 Copy_u8UsartID, u8 Copy_u8UsartMode)
{
    switch(Copy_u8UsartID)
    {
        case USART1_ID: voidSetUsart1Mode(Copy_u8UsartMode);     break;
        case USART2_ID: voidSetUsart2Mode(Copy_u8UsartMode);     break;
        case USART3_ID: voidSetUsart3Mode(Copy_u8UsartMode);     break;
        default: break; /* Error handler */
    }
}/** @end voidUsartMode */

static void voidSetUsart1Mode(u8 Copy_u8Usart1Mode)
{
    switch(Copy_u8Usart1Mode)
    {
        case USART_Transmitter:
                BIT_CLR(USART1->CR[0], RE);
                BIT_SET(USART1->CR[0], TE);
            break;
        case USART_Reciever:
                BIT_CLR(USART1->CR[0], TE);
                BIT_SET(USART1->CR[0], RE);
            break;
        case USART_TransmitterxReciever:
                BIT_SET(USART1->CR[0], TE);
                BIT_SET(USART1->CR[0], RE);
            break;
      default: break; /* Error handler */
    }
}/** @end voidSetUsart1Mode */
static void voidSetUsart2Mode(u8 Copy_u8Usart2Mode)
{
    switch(Copy_u8Usart2Mode)
    {
        case USART_Transmitter:
                BIT_CLR(USART2->CR[0], RE);
                BIT_SET(USART2->CR[0], TE);
            break;
        case USART_Reciever:
                BIT_CLR(USART2->CR[0], TE);
                BIT_SET(USART2->CR[0], RE);
            break;
        case USART_TransmitterxReciever:
                BIT_SET(USART2->CR[0], TE);
                BIT_SET(USART2->CR[0], RE);
            break;
      default: break; /* Error handler */
    }
}/** @end voidSetUsart2Mode */
static void voidSetUsart3Mode(u8 Copy_u8Usart3Mode)
{
    switch(Copy_u8Usart3Mode)
    {
        case USART_Transmitter:
                BIT_CLR(USART3->CR[0], RE);
                BIT_SET(USART3->CR[0], TE);
            break;
        case USART_Reciever:
                BIT_CLR(USART3->CR[0], TE);
                BIT_SET(USART3->CR[0], RE);
            break;
        case USART_TransmitterxReciever:
                BIT_SET(USART3->CR[0], TE);
                BIT_SET(USART3->CR[0], RE);
            break;
      default: break; /* Error handler */
    }
}/** @end voidSetUsart3Mode */

static void voidSetUsart1StopBits(u8 Copy_u8Usart1StopBits)
{
    switch(Copy_u8Usart1StopBits)
    {
      case STOP_BITS_H:     /** @note N/C for UART */
                BIT_SET(USART1->CR[1], STOP0);
                BIT_CLR(USART1->CR[1], STOP1);
            break;
      case STOP_BITS_1:
                BIT_CLR(USART1->CR[1], STOP0);
                BIT_CLR(USART1->CR[1], STOP1);
            break;
      case STOP_BITS_1H:    /** @note N/C for UART */
                BIT_SET(USART1->CR[1], STOP0);
                BIT_SET(USART1->CR[1], STOP1);
            break;
      case STOP_BITS_2:
                BIT_CLR(USART1->CR[1], STOP0);
                BIT_SET(USART1->CR[1], STOP1);
            break;
      default: break; /* Error handler */
    }
}/** @end voidSetUsart1StopBits */
static void voidSetUsart2StopBits(u8 Copy_u8Usart2StopBits)
{
    switch(Copy_u8Usart2StopBits)
    {
      case STOP_BITS_H:     /** @note N/C for UART */
                BIT_SET(USART2->CR[1], STOP0);
                BIT_CLR(USART2->CR[1], STOP1);
            break;
      case STOP_BITS_1:
                BIT_CLR(USART2->CR[1], STOP0);
                BIT_CLR(USART2->CR[1], STOP1);
            break;
      case STOP_BITS_1H:    /** @note N/C for UART */
                BIT_SET(USART2->CR[1], STOP0);
                BIT_SET(USART2->CR[1], STOP1);
            break;
      case STOP_BITS_2:
                BIT_CLR(USART2->CR[1], STOP0);
                BIT_SET(USART2->CR[1], STOP1);
            break;
      default: break; /* Error handler */
    }
}/** @end voidSetUsart2StopBits */
static void voidSetUsart3StopBits(u8 Copy_u8Usart3StopBits)
{
    switch(Copy_u8Usart3StopBits)
    {
      case STOP_BITS_H:     /** @note N/C for UART */
                BIT_SET(USART3->CR[1], STOP0);
                BIT_CLR(USART3->CR[1], STOP1);
            break;
      case STOP_BITS_1:
                BIT_CLR(USART3->CR[1], STOP0);
                BIT_CLR(USART3->CR[1], STOP1);
            break;
      case STOP_BITS_1H:    /** @note N/C for UART */
                BIT_SET(USART3->CR[1], STOP0);
                BIT_SET(USART3->CR[1], STOP1);
            break;
      case STOP_BITS_2:
                BIT_CLR(USART3->CR[1], STOP0);
                BIT_SET(USART3->CR[1], STOP1);
            break;
      default: break; /* Error handler */
    }
}/** @end voidSetUsart3StopBits */

static void voidSetBaudRate(u8 Copy_u8UsartID, u32 Copy_u32BaudRate)
{
    //u16 L_u16BRR = 0;
    //voidCalculateBaudRate(Copy_u32BaudRate, &L_u16BRR);
    switch(Copy_u8UsartID)
    {
        case USART1_ID: REG_WRT(USART1->BRR, (BRR_VALUE & 0xFFFF));  break;
        case USART2_ID: REG_WRT(USART2->BRR, (BRR_VALUE & 0xFFFF));  break;
        case USART3_ID: REG_WRT(USART3->BRR, (BRR_VALUE & 0xFFFF));  break;
        default: break; /* Error handler */
    }
}/** @end voidSetBaudRate */

/*
    Baud rate: 9600 bit/s
    1000000/(9600*16) = 6.51 [BRR]
	 	 	 M F
    Value =  6.510
    Mantissa = Value; (6)
    Fraction = Value - Mantissa = 0.51

    Mantissa = 6
    Fraction = Value - Mantissa = (51/16) = 3
    BRR[0-15] = [M11-F4] = [6-3]
*/
/** @todo to be modified: USING DEBUGGER */
static void voidCalculateBaudRate(u32 Copy_u32BaudRate, u16 *Address_u16BRRValue)
{
    f64 L_f64Value = 0;
    u16 L_u16Mantissa = 0;
    u8  L_u8Fraction = 0;

    L_f64Value = ( (SYSTEM_CLOCK ) / (OVERSAMPLE_RATE * Copy_u32BaudRate) );

    L_u16Mantissa = (u16) L_f64Value;
    L_u8Fraction =  (u8) ( ((L_f64Value - L_u16Mantissa) * OVERSAMPLE_RATE) );  /** @todo to be modified */

    *Address_u16BRRValue  |= (L_u16Mantissa);
    *Address_u16BRRValue <<= 4;
    *Address_u16BRRValue  |= (L_u8Fraction);
}/** @end USART1_voidRecieveData */

static void voidUsartTransmitViaInterrupt(ST_USART_REGISTERS_t volatile *Copy_Usart,
                                          u8 *Address_u8TxBuffer,
                                          u32 volatile *Address_u32TxCounter)
{
    /** @def: Read the flag to send the next byte */
    if( (BIT_GET(Copy_Usart->SR, TXE)) && (BIT_GET(Copy_Usart->CR[0], TXEIE)) )
    {
        ++(*Address_u32TxCounter);

        if( ((*Address_u32TxCounter) < MAX_BUFFER_SIZE) && /** @note: Assumed all information are string */
        	 (Address_u8TxBuffer[(*Address_u32TxCounter)] != '\0') )
        {
            Copy_Usart->DR = Address_u8TxBuffer[(*Address_u32TxCounter)] & 0xFF;
        }
        else
        {
            (*Address_u32TxCounter) = (u32) 0;
            BIT_CLR(Copy_Usart->CR[0], TXEIE); /** @def: Disable Interrupt */
        }
    }else { return; }
}/** @end voidUsartSendViaInterrupt */
static void voidUsartRecieveViaInterrupt(ST_USART_REGISTERS_t volatile *Copy_Usart,
                                         u8 *Address_u8RxBuffer,
                                         u32 volatile *Address_u32RxCounter)
{
   /** @def: Read the flag to get the next byte */
    if( (BIT_GET(Copy_Usart->SR, RXNE)) && (BIT_GET(Copy_Usart->CR[0], RXENIE)) )
    {
    	Address_u8RxBuffer[(*Address_u32RxCounter)] = (u8) Copy_Usart->DR;
        ++(*Address_u32RxCounter);
        if( ((*Address_u32RxCounter) > MAX_BUFFER_SIZE) )
        {
            (*Address_u32RxCounter) = 0;    /** @note: Circular Buffer */
        }else {;}
    }else {;}
}/** @end voidUsartRecieveViaInterrupt */

void USART1_IRQHandler(void)
{
    /** @defgroup: Transmitter via Interrupt Level */
    voidUsartTransmitViaInterrupt(USART1, G_u8Usart1TxBuffer, &G_u32Usart1TxCounter);

    /** @defgroup: Recieving via Interrupt Level */
    voidUsartRecieveViaInterrupt(USART1, G_u8Usart1RxBuffer, &G_u32Usart1RxCounter);
}/** @end USART1_IRQHandler */

void USART2_IRQHandler(void)
{
    /** @defgroup: Transmitter via Interrupt Level */
    voidUsartTransmitViaInterrupt(USART2, G_u8Usart2TxBuffer, &G_u32Usart2TxCounter);

    /** @defgroup: Recieving via Interrupt Level */
    voidUsartRecieveViaInterrupt(USART2, G_u8Usart2RxBuffer, &G_u32Usart2RxCounter);
}/** @end USART2_IRQHandler */

void USART3_IRQHandler(void)
{
    /** @defgroup: Transmitter via Interrupt Level */
    voidUsartTransmitViaInterrupt(USART3, G_u8Usart3TxBuffer, &G_u32Usart3TxCounter);

    /** @defgroup: Recieving via Interrupt Level */
    voidUsartRecieveViaInterrupt(USART3, G_u8Usart3RxBuffer, &G_u32Usart3RxCounter);
}/** @end USART3_IRQHandler */
