/**
 * @author: Mohamed Ashraf
 * @date: Oct  4 2022
 * @dersion: V0.0
 * @copyrights: Copyrights (c) Mohamed Wx 2022
 */
/** @defgroup: Header Guards */ 
#ifndef __BTL_BTL_INTERFACE_H__
#define __BTL_BTL_INTERFACE_H__


/*									 
-------------------------------------------------------------- 
!-				 Public Defines 
-------------------------------------------------------------- 
*/ 

#define BOOTLOADER_PAGE_SIZE BTL_SIZE

/*									 
-------------------------------------------------------------- 
!-				 Public Functions Declaration 
-------------------------------------------------------------- 
*/ 

void BTL_voidInit(void);
void BTL_voidUpdate(void);

#endif /* __BTL_BTL_INTERFACE_H__ */
