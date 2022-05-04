/******************************************************
 *Author: Mahmoud Khaled Alnmr
 *Layer: MCAL
 *SWC: Port
 *version: 1.00
 ******************************************************/
#ifndef PORT_REGISTERS_H
#define PORT_REGISTERS_H

#define DDRA           (*(volatile uint8 *)0x3a)
#define DDRB           (*(volatile uint8 *)0x37)
#define DDRC           (*(volatile uint8 *)0x34)
#define DDRD           (*(volatile uint8 *)0x31)

#define PORTA          (*(volatile uint8 *)0x3b)
#define PORTB          (*(volatile uint8 *)0x38)
#define PORTC          (*(volatile uint8 *)0x35)
#define PORTD          (*(volatile uint8 *)0x32)

#endif
