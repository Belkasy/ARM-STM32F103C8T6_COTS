/**
 * @author: Mohamed Ashraf
 * @date: Oct  5 2022
 * @dersion: V0.0
 * @copyrights: Copyrights (c) Mohamed Wx 2022
 */
/** @defgroup: Header Guards */ 
#ifndef __ADC_ADC_PRIVATE_H__
#define __ADC_ADC_PRIVATE_H__

#define ADC_BASE_ADDRESS (0x40012400)
/*									 
-------------------------------------------------------------- 
!-				 Register File 
-------------------------------------------------------------- 
*/ 

typedef struct
{
   volatile u32 SR;
   volatile u32 CR1;
   volatile u32 CR2;
   volatile u32 SMPR1;
   volatile u32 SMPR2
   volatile u32 JOFR[4];
   volatile u32 HTR;
   volatile u32 LTR;
   volatile u32 SQR1;
   volatile u32 SQR2;
   volatile u32 SQR3;
   volatile u32 JSQR;
   volatile u32 JDR[4];
   volatile u32 DR;
}ST_ADCRegisters_t ;

#define ADC   ( ((ST_ADCRegisters_t volatile *) (ADC_BASE_ADDRESS)) )

/*									 
-------------------------------------------------------------- 
!-				 Private Defines 
-------------------------------------------------------------- 
*/ 


/*									 
-------------------------------------------------------------- 
!-				 Private Functions Declaration 
-------------------------------------------------------------- 
*/ 


#endif /* __ADC_ADC_PRIVATE_H__ */
