/**
 * @author: Mohamed Ashraf
 * @date: Oct  4 2022
 * @dersion: V0.0
 * @copyrights: Copyrights (c) Mohamed Wx, Abdelrahman Elbelkasy 2022
 */

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

#include "../../02-MCAL/01-RCC/RCC_Interface.h"
#include "../../02-MCAL/02-DIO/DIO_Interface.h"
#include "../../02-MCAL/USART/USART_Interface.h"
#include "../../02-MCAL/14-FPEC/FPEC_Interface.h"
#include "../../02-MCAL/06-SYSTICK/SYSTICK_Interface.h"

#include "BTL_Private.h"
#include "BTL_Config.h"
#include "BTL_Interface.h"

/*
--------------------------------------------------------------
!-				 Global Variables
--------------------------------------------------------------
*/

/** @def: The flash address to write the data in it */
u32 G_u32FlashAddress = FLASH_START_ADDRESS;
/** @def: Buffer to store the data to be flashed */
u16 G_u16Data[DATA_BUFFER_LENGTH];
/** @def: Number of data to be flashed */
u8  G_u8CharCount = 0;
/** @def: Buffer to receive the uart data */
u8 G_u8RxBuffer[UART_BUFFER_LENGTH];
u8 G_u8RxCounter = 0;

/*									 
-------------------------------------------------------------- 
!-				 Public Function Implementation 
-------------------------------------------------------------- 
*/ 

void BTL_voidInit(void)
{
    /** @defgroup: RCC Inits */
    RCC_voidSystemClockInit(SYSTEM_CLOCK);
    RCC_voidEnableClock(AHB_ID, FPEC);
    RCC_voidEnableClock(APB2_ID, USART1EN);
    RCC_voidEnableClock(APB2_ID, IOPAEN);

    /** @defgroup: GPIOA Inits */
    DIO_voidSetPinStatus(PORTA_ID, PIN_9, DIO_AFIO_PUSHPULL_50MHZ); // MCU-Tx
    DIO_voidSetPinStatus(PORTA_ID, PIN_10, DIO_INPUT_FLOATING); // MCU-Rx

    /** @defgroup: SYSTICK Inits */
    SYSTICK_voidInit();

    /** @defgroup: USART Inits */
    ST_USARTConfig_t myUsartConfig =
    {
        .UsartID  = USART1_ID,
        .Baudrate = 9600,
        .StopBits = STOP_BITS_1,
        .DataBits = DATA_WORD_8,
        .Parity   = Parity_NONE,
        .FlowCtrlMode = FlowCtrl_Disable,
        .UsartMode = USART_TransmitterxReciever
    };
    USART_voidInit(&myUsartConfig);

    /** @defgroup: FPEC Inits */
    FPEC_voidInit();

    /**
     * @todo: Change it
     * @brief: Erase the flash application memory.
     */
    for(u8 i = BOOTLOADER_PAGE_SIZE; (i < FLASH_MEMORY_PAGE_SIZE); ++i)
    {
        FPEC_u8FlashPageErase(i);
    }
}/** @end BTL_voidInit */

void BTL_voidUpdate(void)
{
    /* Set fault handler */
    SYSTICK_voidSetCallBack(&voidSysReset);
    SYSTICK_voidIntervalSingle(10000);

    USART1_voidRecieveDataSnyc(&G_u8RxBuffer[G_u8RxCounter], 1u);

    if( (G_u8RxBuffer[G_u8RxCounter] > 0) )
    {
        SYSTICK_voidStopTimer();

        if( ('\n' == G_u8RxBuffer[G_u8RxCounter]) )
        {
            voidParseRecord(G_u8RxBuffer);
            USART1_voidTransmitDataSync("ok", 3u);
            G_u8RxCounter = 0;
        }
        else
        {
            ++G_u8RxCounter;
        }

        SYSTICK_voidIntervalSingle(10000);
    }
    else {;}
}/** @end BTL_voidStartFlashing */

/*									 
-------------------------------------------------------------- 
!-				 Private Functions Implementation 
-------------------------------------------------------------- 
*/ 

static void voidAsciiToHex(u8 Copy_u8AsciiData, u8 *Address_u8HexData)
{
    u8 L_u8ResultData = 0;

    /* If the ASCII is number */
    if( (Copy_u8AsciiData >= '0') && (Copy_u8AsciiData <= '9') )
    {
        L_u8ResultData = Copy_u8AsciiData - '0';
    }
    /* If the ASCII is charachter */
    else if( ((Copy_u8AsciiData >= 'A') && (Copy_u8AsciiData <= 'Z')) ||
             ((Copy_u8AsciiData >= 'a') && (Copy_u8AsciiData <= 'z')) )
    {
        // "55": Offset for The ASCII Charachter Eqiv Hex Charachter.
        L_u8ResultData = Copy_u8AsciiData - 55U;
    }
    else
    {
        /* Error handle */
    }

    *Address_u8HexData = L_u8ResultData;
}/** @end voidHexParser */


/** @todo: Change it as fast as possible !!!!! */
#define BIGe_2_LITe(A, B, C, D) ( (A << 4u) | (B) | (C << 12u) | (D << 8u) )

static void voidParseHexFile(u8 *Address_u8HexData)
{
    u8 L_u8DigitHigh = 0,
       L_u8DigitLow  = 0;

    u8 L_u8Digit0 = 0,
       L_u8Digit1 = 0,
       L_u8Digit2 = 0,
       L_u8Digit3 = 0;

    u8 L_u8DataCounter = 0;

    /* Get Charachter count */
    voidAsciiToHex(Address_u8HexData[1], &L_u8DigitHigh);
    voidAsciiToHex(Address_u8HexData[2], &L_u8DigitLow);
    G_u8CharCount = ((L_u8DigitHigh << 4u) | L_u8DigitLow);

    /* Get the lower address */
   voidAsciiToHex(Address_u8HexData[3], &L_u8Digit0);
   voidAsciiToHex(Address_u8HexData[4], &L_u8Digit1);
   voidAsciiToHex(Address_u8HexData[5], &L_u8Digit2);
   voidAsciiToHex(Address_u8HexData[6], &L_u8Digit3);

   /* Masking the address */ /* Clear the lower hword*/
   G_u32FlashAddress &= 0xFFFF0000;
   G_u32FlashAddress |= ( (L_u8Digit3 << 0u) | (L_u8Digit2 << 4u) |
                          (L_u8Digit1 << 8u) | (L_u8Digit0 << 12u) );

   /* Fetch the data */
   u8 L_u8DataRecordIterator = 0;
   for(u8 i = 0 ; (i < G_u8CharCount/2); ++i)
   {
       voidAsciiToHex(Address_u8HexData[(4 * i) + 9],  &L_u8Digit0);
       voidAsciiToHex(Address_u8HexData[(4 * i) + 10], &L_u8Digit1);
       voidAsciiToHex(Address_u8HexData[(4 * i) + 11], &L_u8Digit2);
       voidAsciiToHex(Address_u8HexData[(4 * i) + 12], &L_u8Digit3);

       G_u16Data[L_u8DataRecordIterator++] = /* Big Endieanto Little Endian */
       BIGe_2_LITe(L_u8Digit0, L_u8Digit1, L_u8Digit2, L_u8Digit3);
   }
}/** @end voidParseHexFile */

static void voidParseRecord(u8 *Address_u8HexData)
{
    switch( (Address_u8HexData[8]) )
    {
        case DATA_RECORD:
                voidParseHexFile(Address_u8HexData);
                FPEC_u8WriteFlash(G_u32FlashAddress,
																	G_u16Data,
																 (G_u8CharCount >> 1u));
            break;
        case END_OF_FILE_RECORD:
                // TODO:
            break;
        case EXTENDED_ADDRESS_RECORD:
                // TODO:
            break;
        case FULL_ADDRESS_RECORD:
                // TODO:
            break;
        default: break; /* Error handler */
    }
}/** @end voidGetFcknUpperAddress */

// TODO: TO BE CHANGED ASAP!
typedef void (*Function_t)(void);

#define GotoReset() ( *(Function_t *) (FLASH_START_ADDRESS + 0x1004) )
#define SCB_VTOR (*((u32 volatile *) (0xE000ED08)))

static void voidSysReset(void)
{
    SCB_VTOR = FLASH_START_ADDRESS + 0x1000;

    GotoReset();
}/** @end voidJumpSysReset */
