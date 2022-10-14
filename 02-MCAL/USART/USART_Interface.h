/**
 * @name        USART_Interface.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _USART_INTERFACE_H
#define _USART_INTERFACE_H

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

/** @todo implment control with structs */

enum USART_ID
{
    USART1_ID,
    USART2_ID,
    USART3_ID
};

enum USART_MODE
{
    USART_Transmitter,
    USART_Reciever,
		USART_TransmitterxReciever
};

enum PARITY_MODES
{
		Parity_NONE = 0,
    Parity_EVEN = 0,
    Pairty_ODD	= 1
};

enum USART_STATES
{
    USART_Enable,
    USART_Disable
};

enum FlowCtrl_STATES
{
    FlowCtrl_Enable,
    FlowCtrl_Disable
};

enum DATA_BITS_OPTIONS
{
    DATA_WORD_8,
    DATA_WORD_9
};

enum STOP_BITS_OPTIONS
{
    STOP_BITS_H,
    STOP_BITS_1,
    STOP_BITS_1H,
    STOP_BITS_2
};

/** @todo to be implemented */
typedef struct __attribute__((__packed__))
{
    u8 UsartID;
    u32 Baudrate;
    u8 StopBits;
    u8 DataBits;
    u8 Parity;          /* E/D */
    u8 FlowCtrlMode;    /* E/D*/
    u8 UsartMode;       /* Tx/Rx*/
}ST_USARTConfig_t;

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void USART_voidInit(const ST_USARTConfig_t * UsartConfig);

void USART1_voidTransmitDataSync(u8 *Address_u8TxBuffer, u32 Copy_u32TxBytes);
void USART1_voidRecieveDataSnyc(u8 *Address_u8RxBuffer, u32 Copy_u32RxBytes);
void USART1_voidTransmitDataAsync(u8 *Address_u8TxBuffer);
void USART1_voidRecieveDataAsync(u8 *Address_u8TxBuffer);

void USART2_voidTransmitDataSync(u8 *Address_u8TxBuffer, u32 Copy_u32TxBytes);
void USART2_voidRecieveDataSnyc(u8 *Address_u8RxBuffer, u32 Copy_u32RxBytes);
void USART2_voidTransmitDataAsync(u8 *Address_u8TxBuffer);
void USART2_voidRecieveDataAsync(u8 *Address_u8TxBuffer);

void USART3_voidTransmitDataSync(u8 *Address_u8TxBuffer, u32 Copy_u32TxBytes);
void USART3_voidRecieveDataSnyc(u8 *Address_u8RxBuffer, u32 Copy_u32RxBytes);
void USART3_voidTransmitDataAsync(u8 *Address_u8TxBuffer);
void USART3_voidRecieveDataAsync(u8 *Address_u8TxBuffer);

void USART_voidSetCallBack(u8 Copy_u8UsartID, void (*Copy_CallBackFunction)(void));


#endif /* _USART_INTERFACE_H */
