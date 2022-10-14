/**
 * @authors     Abdelrahman Belkasy, Wx
 * @date: Oct  4 2022
 * @dersion: V0.0
 * @copyrights: Copyrights (c) Mohamed Wx, Abdelrahman Elbelkasy 2022
 */
/** @defgroup: Header Guards */ 
#ifndef __BTL_BTL_PRIVATE_H__
#define __BTL_BTL_PRIVATE_H__


/*									 
-------------------------------------------------------------- 
!-				 Private Defines 
-------------------------------------------------------------- 
*/ 

#define BTL_PARSER_ASSERT(DATA, VAL) (DATA != VAL)
#define DATA_BUFFER_LENGTH          (100u)
#define UART_BUFFER_LENGTH          (100u)

#define DATA_RECORD                 (0u)
#define END_OF_FILE_RECORD          (1u)
#define EXTENDED_ADDRESS_RECORD     (4u)
#define FULL_ADDRESS_RECORD         (5u)

/*									 
-------------------------------------------------------------- 
!-				 Private Functions Declaration 
-------------------------------------------------------------- 
*/ 
static void voidAsciiToHex(u8 Copy_u8AsciiData, u8 *Address_u8HexData);
static void voidParseHexFile(u8 *Address_u8HexData);
static void voidParseRecord(u8 *Address_u8HexData);

static void voidSysReset(void);

#endif /* __BTL_BTL_PRIVATE_H__ */
