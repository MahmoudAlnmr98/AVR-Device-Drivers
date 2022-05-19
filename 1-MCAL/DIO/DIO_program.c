/******************************************************
 *Author: Mahmoud Khaled Alnmr
 *Layer: MCAL
 *SWC: DIO
 *version: 1.00
 ******************************************************/

#include "..\Library\STD_TYPES.h"
#include "..\Library\BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_registers.h"
#include "DIO_private.h"
#include "DIO_config.h"



uint8 DIO_uint8_SetPinDirection( uint8 copy_uint8_port,
									uint8 copy_uint8_pin,
									uint8 copy_uint8_direction)
{
	uint8 local_uint8_errorState = 0 ;

	if (copy_uint8_pin <= DIO_uint8_PIN7)
	{
		if (copy_uint8_direction == DIO_uint8_PIN_INPUT)
		{
			switch(copy_uint8_port)
			{
			case DIO_uint8_PORTA  : CLR_BIT(DDRA , copy_uint8_pin ); break;
			case DIO_uint8_PORTB  : CLR_BIT(DDRB , copy_uint8_pin ); break;
			case DIO_uint8_PORTC  : CLR_BIT(DDRC , copy_uint8_pin ); break;
			case DIO_uint8_PORTD  : CLR_BIT(DDRD , copy_uint8_pin ); break;
			default : local_uint8_errorState = 1; break ;
			}
		}
		else if (copy_uint8_direction == DIO_uint8_PIN_OUTPUT)
		{
			switch(copy_uint8_port)
			{
			case DIO_uint8_PORTA  : SET_BIT(DDRA , copy_uint8_pin ); break;
			case DIO_uint8_PORTB  : SET_BIT(DDRB , copy_uint8_pin ); break;
			case DIO_uint8_PORTC  : SET_BIT(DDRC , copy_uint8_pin ); break;
			case DIO_uint8_PORTD  : SET_BIT(DDRD , copy_uint8_pin ); break;
			default : local_uint8_errorState = 1; break;
			}

		}
		else
		{
			local_uint8_errorState = 1;
		}

	}
	else
	{
		local_uint8_errorState = 1;
	}

	return local_uint8_errorState;
}

uint8 DIO_uint8_SetPinValue    ( uint8 copy_uint8_port,
									uint8 copy_uint8_pin,
									uint8 copy_uint8_value)
{
	uint8 local_uint8_errorState = 0 ;


	if (copy_uint8_pin <= DIO_uint8_PIN7)
	{
		if (copy_uint8_value == DIO_uint8_HIGH)
		{
			switch(copy_uint8_port)
			{
			case DIO_uint8_PORTA  : SET_BIT(PORTA , copy_uint8_pin ); break;
			case DIO_uint8_PORTB  : SET_BIT(PORTB , copy_uint8_pin ); break;
			case DIO_uint8_PORTC  : SET_BIT(PORTC , copy_uint8_pin ); break;
			case DIO_uint8_PORTD  : SET_BIT(PORTD , copy_uint8_pin ); break;
			default : local_uint8_errorState = 1; break ;
			}
		}
		else if (copy_uint8_value == DIO_uint8_LOW)
		{
			switch(copy_uint8_port)
			{
			case DIO_uint8_PORTA  : CLR_BIT(PORTA, copy_uint8_pin ); break;
			case DIO_uint8_PORTB  : CLR_BIT(PORTB, copy_uint8_pin ); break;
			case DIO_uint8_PORTC  : CLR_BIT(PORTC, copy_uint8_pin ); break;
			case DIO_uint8_PORTD  : CLR_BIT(PORTC, copy_uint8_pin ); break;
			default : local_uint8_errorState = 1; break;
			}

		}
		else
		{
			local_uint8_errorState = 1;
		}

	}
	else
	{
		local_uint8_errorState = 1;
	}
	return local_uint8_errorState;
}


uint8 DIO_uint8_SetPortDirection( uint8 copy_uint8_port,
									uint8 copy_uint8_direction)
{

	uint8 local_uint8_errorState = 0 ;

	switch(copy_uint8_port)
	{
	case DIO_uint8_PORTA  : DDRA = copy_uint8_direction; break;
	case DIO_uint8_PORTB  : DDRB = copy_uint8_direction; break;
	case DIO_uint8_PORTC  : DDRC = copy_uint8_direction; break;
	case DIO_uint8_PORTD  : DDRD = copy_uint8_direction; break;
	default: local_uint8_errorState = 1;
	}

	return local_uint8_errorState;
}

uint8 DIO_uint8_SetPortValue    ( uint8 copy_uint8_port,
								   uint8 copy_uint8_value)
{
	uint8 local_uint8_errorState = 0 ;

	switch(copy_uint8_port)
	{
	case DIO_uint8_PORTA  : PORTA = copy_uint8_value; break;
	case DIO_uint8_PORTB  : PORTB = copy_uint8_value; break;
	case DIO_uint8_PORTC  : PORTC = copy_uint8_value; break;
	case DIO_uint8_PORTD  : PORTD = copy_uint8_value; break;
	default : local_uint8_errorState = 1;
	}

	return local_uint8_errorState;
}

uint8 DIO_uint8_GetPinValue    ( uint8 copy_uint8_port,
									uint8 copy_uint8_pin,
									uint8 * copy_puint8_value)
{
	uint8 local_uint8_errorState = 0 ;

	if ((copy_puint8_value != NULL) && (copy_uint8_pin <= DIO_uint8_PIN7))
	{
		switch(copy_uint8_port)
		{
		case DIO_uint8_PORTA  : *copy_puint8_value = GET_BIT(PINA, copy_uint8_pin); break;
		case DIO_uint8_PORTB  : *copy_puint8_value = GET_BIT(PINB, copy_uint8_pin); break;
		case DIO_uint8_PORTC  : *copy_puint8_value = GET_BIT(PINC, copy_uint8_pin); break;
		case DIO_uint8_PORTD  : *copy_puint8_value = GET_BIT(PIND, copy_uint8_pin); break;
		default: local_uint8_errorState = 1;
		}

	}

	return local_uint8_errorState;
}
