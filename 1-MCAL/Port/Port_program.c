/******************************************************
 *Author: Mahmoud Khaled Alnmr
 *Layer: MCAL
 *SWC: Port
 *version: 1.00
 ******************************************************/
#include "..\Library\STD_TYPES.h"

#include "Port_config.h"
#include "Port_private.h"
#include "Port_interface.h"
#include "Port_registers.h"

void Port_void_voidInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;

	PORTA = PORTA_INITIAL_VALUE;
	PORTB = PORTB_INITIAL_VALUE;
	PORTC = PORTC_INITIAL_VALUE;
	PORTD = PORTD_INITIAL_VALUE;

}
