/******************************************************
 *Author: Mahmoud Khaled Alnmr
 *Layer: HAL
 *SWC: Keypad
 *version: 1.00
 ******************************************************/
#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "Keypad_interface.h"
#include "Keypad_config.h"
#include "Keypad_private.h"
#include "keypad_registers.h"

void KeyPad_void_init()
{
	DIO_uint8_SetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN0_PIN, DIO_uint8_PIN_OUTPUT);
	DIO_uint8_SetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN1_PIN, DIO_uint8_PIN_OUTPUT);
	DIO_uint8_SetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN2_PIN, DIO_uint8_PIN_OUTPUT);
	DIO_uint8_SetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN3_PIN, DIO_uint8_PIN_OUTPUT);

	DIO_uint8_SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN0_PIN, DIO_uint8_HIGH);
	DIO_uint8_SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN1_PIN, DIO_uint8_HIGH);
	DIO_uint8_SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN2_PIN, DIO_uint8_HIGH);
	DIO_uint8_SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN3_PIN, DIO_uint8_HIGH);

	DIO_uint8_SetPinDirection(KEYPAD_PORT, KEYPAD_ROW0_PIN, DIO_uint8_PIN_INPUT);
	DIO_uint8_SetPinDirection(KEYPAD_PORT, KEYPAD_ROW1_PIN, DIO_uint8_PIN_INPUT);
	DIO_uint8_SetPinDirection(KEYPAD_PORT, KEYPAD_ROW2_PIN, DIO_uint8_PIN_INPUT);
	DIO_uint8_SetPinDirection(KEYPAD_PORT, KEYPAD_ROW3_PIN, DIO_uint8_PIN_INPUT);

	DIO_uint8_SetPinValue(KEYPAD_PORT, KEYPAD_ROW0_PIN, DIO_uint8_HIGH);
	DIO_uint8_SetPinValue(KEYPAD_PORT, KEYPAD_ROW1_PIN, DIO_uint8_HIGH);
	DIO_uint8_SetPinValue(KEYPAD_PORT, KEYPAD_ROW2_PIN, DIO_uint8_HIGH);
	DIO_uint8_SetPinValue(KEYPAD_PORT, KEYPAD_ROW3_PIN, DIO_uint8_HIGH);
}


uint8 KeyPad_uint8_PressedKey()
{
	uint8 local_uint8_columnIterator = STD_LOW;
	uint8 local_uint8_rowIterator = STD_LOW;
	uint8 local_uint8_keyPressed = KEY_NOT_PRESSED;
	uint8 local_uint8_pinState;

	static uint8 Keypad_uint8_KeyNumber[KEYPAD_COLUMN_NUMBER][KEYPAD_ROW_NUMBER] =
	{
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11},
		{12, 13, 14, 15}
	};

	static uint8 local_uint8_columnArray[KEYPAD_COLUMN_NUMBER] =
	{
		KEYPAD_COLUMN0_PIN,KEYPAD_COLUMN1_PIN,KEYPAD_COLUMN2_PIN,KEYPAD_COLUMN3_PIN
	};

	static uint8 local_uint8_rowArray[KEYPAD_ROW_NUMBER] =
	{
		KEYPAD_ROW0_PIN,KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN
	};

	for (local_uint8_columnIterator = STD_LOW; local_uint8_columnIterator < KEYPAD_COLUMN_NUMBER; ++local_uint8_columnIterator)
	{
		DIO_uint8_SetPinValue(KEYPAD_PORT, local_uint8_columnArray[local_uint8_columnIterator], DIO_uint8_LOW);

		for (local_uint8_rowIterator = STD_LOW; local_uint8_rowIterator < KEYPAD_ROW_NUMBER; ++local_uint8_rowIterator)
		{
			DIO_uint8_GetPinValue(KEYPAD_PORT, local_uint8_rowArray[local_uint8_rowIterator], &local_uint8_pinState);
			if(local_uint8_pinState == STD_LOW)
			{
				local_uint8_keyPressed = Keypad_uint8_KeyNumber[local_uint8_columnIterator][local_uint8_rowIterator];
				while(local_uint8_pinState == STD_LOW)
				{
					DIO_uint8_GetPinValue(KEYPAD_PORT, local_uint8_rowArray[local_uint8_rowIterator], &local_uint8_pinState);
				}
				return local_uint8_keyPressed;
			}
		}
		DIO_uint8_SetPinValue(KEYPAD_PORT, local_uint8_columnArray[local_uint8_columnIterator], DIO_uint8_HIGH);

	}
	return local_uint8_keyPressed ;
}


