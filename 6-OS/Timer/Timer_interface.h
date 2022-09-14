/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC: Timer
*Layer: MCAL
*Version: 1.00
***********************************************************/
#ifndef TIMER_TIMER_INTERFACE_H_
#define TIMER_TIMER_INTERFACE_H_

void Timer0_void_CTC(void);

uint8 Timer0_uint8_CompareMatchSetCallBack(void (*copy_pv_CallBackFunc)(void));

#endif /* TIMER_TIMER_INTERFACE_H_ */
