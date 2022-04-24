/******************************************************
 *Auther: Mahmoud Khaled Alnmr
 *Layer: MCAL
 *SWC: DIO
 *version: 1.00
 ******************************************************/


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


/*macros to choose pin state either input or output*/
#define DIO_uint8_PIN_OUTPUT                1
#define DIO_uint8_PIN_INPUT                0

/*macros to choose pin state to be high(1) or low (0)*/
#define DIO_uint8_HIGH                     1
#define DIO_uint8_LOW                      0

/*macros to set port as output or input*/
#define DIO_uint8_PORT_OUTPUT				0xFF
#define DIO_uint8_PORT_INPUT				0


#define DIO_uint8_PORTA_OUTPUT				0xFF
#define DIO_uint8_PORTB_OUTPUT				0xFF
#define DIO_uint8_PORTC_OUTPUT				0xFF
#define DIO_uint8_PORTD_OUTPUT				0xFF

#define DIO_uint8_PORTA_INPUT				0
#define DIO_uint8_PORTB_INPUT				0
#define DIO_uint8_PORTC_INPUT				0
#define DIO_uint8_PORTD_INPUT				0

/*macros for ports A,B,C,D*/
#define DIO_uint8_PORTA                    0
#define DIO_uint8_PORTB                    1
#define DIO_uint8_PORTC                    2
#define DIO_uint8_PORTD                    3

/*macros for each pin in the port*/
#define DIO_uint8_PIN0                     0
#define DIO_uint8_PIN1                     1
#define DIO_uint8_PIN2                     2
#define DIO_uint8_PIN3                     3
#define DIO_uint8_PIN4                     4
#define DIO_uint8_PIN5                     5
#define DIO_uint8_PIN6                     6
#define DIO_uint8_PIN7                     7
/**********************************************************
 * setting setter functions prototypes
 **********************************************************/
/* setting function prototypes for Pins */
uint8 DIO_uint8_SetPinDirection( uint8 copy_uint8_port,
		uint8 copy_uint8_pin,
		uint8 copy_uint8_direction);

uint8 DIO_uint8_SetPinValue    ( uint8 copy_uint8_port,
		uint8 copy_uint8_pin,
		uint8 copy_uint8_value);


/* setting function prototypes for ports */
uint8 DIO_uint8_SetPortDirection( uint8 copy_uint8_port,
		uint8 copy_uint8_direction);

uint8 DIO_uint8_SetPortValue    ( uint8 copy_uint8_port,
		uint8 copy_uint8_value);

/**********************************************************
 * setting getter functions prototypes
 **********************************************************/
uint8 DIO_uint8_GetPinValue    ( uint8 copy_uint8port,
		uint8 copy_uint8_pin,
		uint8 * copy_puint8_value);

#endif



