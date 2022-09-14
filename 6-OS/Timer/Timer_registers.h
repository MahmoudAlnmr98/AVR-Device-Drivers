/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC: Timer
*Layer: MCAL
*Version: 1.00
***********************************************************/
#ifndef TIMER_TIMER_REGISTERS_H_
#define TIMER_TIMER_REGISTERS_H_




/*timer 0 registers*/

#define TCCR0				*((volatile uint8*)0x53) /*timer0 control register*/

#define TCCR0_FOC0			7
#define TCCR0_WGM00			6
#define TCCR0_COM01			5
#define TCCR0_COM00			4
#define TCCR0_WGM01			3
#define TCCR0_CS02			2
#define TCCR0_CS01			1
#define TCCR0_CS00			0

#define TCNT0				*((volatile uint8*)0x52) /*timer/counter register*/

#define OCR0				*((volatile uint8*)0x5C) /*output compare register*/

#define TIMSK				*((volatile uint8*)0x59) /*timer mask*/
#define TIMSK_OCIE0			1
#define TIMSK_TOIE0			0


#endif /* TIMER_TIMER_REGISTERS_H_ */
