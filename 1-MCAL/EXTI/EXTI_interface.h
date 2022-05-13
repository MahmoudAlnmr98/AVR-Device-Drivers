/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC: External Interrupt
*Layer: MCAL
*Version: 1.00
***********************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


void EXTI_void_INT0Init(void);

void EXTI_void_INT1Init(void);

void EXTI_void_INT2Init(void);

uint8 EXTI_uint8_INT0SetCallBack(void (*copy_pf_INT0Func)(void));
uint8 EXTI_uint8_INT1SetCallBack(void (*copy_pf_INT1Func)(void));
uint8 EXTI_uint8_INT2SetCallBack(void (*copy_pf_INT2Func)(void));

#endif /* EXTI_INTERFACE_H_ */
