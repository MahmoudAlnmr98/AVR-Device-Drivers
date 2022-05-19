/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC:
*Layer:
*Version:
***********************************************************/

#include "..\Library\STD_TYPES.h"
#include "..\Library\BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_config.h"
#include "ADC_private.h"



static uint8* ADC_puint8_Reading = NULL;
static void (*ADC_pv_CallBackNotification)(void) = NULL;

uint8 ADC_uint8_BusyState = ADC_NOTBUSY;

void ADC_void_Init()
{
#if ADC_REFERENCE_VOLATGE == AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_REFERENCE_VOLATGE == AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_REFERENCE_VOLATGE == INTERNAL_2_56V
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#endif

/*ADC resolution configurations*/
#if ADC_RESOLUTION_MODE == ADC_RESOLUTION_8_BITS
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_RESOLUTION_MODE == ADC_RESOLUTION_10_BITS
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#endif
/*end of ADC resolution configurations*/

/* ADC conversion mode configuratio */
#if ADC_CONVERSION_MODE == ADC_SINGLE_CONVERSION_MODE
	CLR_BIT(ADCSRA,ADCSRA_ADATE);

#elif ADC_CONVERSION_MODE == ADC_FREE_RUNNING_MODE
	SET_BIT(ADCSRA,ADCSRA_ADATE);
	#if ADC_AUTO_TRIGGER_SOURCE	== FREE_RUNNING_MODE
				CLR_BIT(SFIOR,SFIOR_ADTS_2);
				CLR_BIT(SFIOR,SFIOR_ADTS_1);
				CLR_BIT(SFIOR,SFIOR_ADTS_0);
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR_MODE
				CLR_BIT(SFIOR,SFIOR_ADTS_2);
				CLR_BIT(SFIOR,SFIOR_ADTS_1);
				SET_BIT(SFIOR,SFIOR_ADTS_0);
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRUPT_REQ_0
				CLR_BIT(SFIOR,SFIOR_ADTS_2);
				SET_BIT(SFIOR,SFIOR_ADTS_1);
				CLR_BIT(SFIOR,SFIOR_ADTS_0);
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER0_COMPARE_MATCH
				CLR_BIT(SFIOR,SFIOR_ADTS_2);
				SET_BIT(SFIOR,SFIOR_ADTS_1);
				SET_BIT(SFIOR,SFIOR_ADTS_0);
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER0_OVERFLOW
				SET_BIT(SFIOR,SFIOR_ADTS_2);
				CLR_BIT(SFIOR,SFIOR_ADTS_1);
				CLR_BIT(SFIOR,SFIOR_ADTS_0);
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER1_COMPARE_MATCH_B
				SET_BIT(SFIOR,SFIOR_ADTS_2);
				CLR_BIT(SFIOR,SFIOR_ADTS_1);
				SET_BIT(SFIOR,SFIOR_ADTS_0);
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER1_OVERFLOW
				SET_BIT(SFIOR,SFIOR_ADTS_2);
				SET_BIT(SFIOR,SFIOR_ADTS_1);
				CLR_BIT(SFIOR,SFIOR_ADTS_0);
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER1_COMPARE_CAPTURE_MODE
				SET_BIT(SFIOR,SFIOR_ADTS_2);
				SET_BIT(SFIOR,SFIOR_ADTS_1);
				SET_BIT(SFIOR,SFIOR_ADTS_0);
	#endif
#endif
/*end of ADC conversion mode configuratio */

	/*ADC interrupt configuration*/
	#if ADC_INTERRUPT_MODE == ADC_INTERRUPT_OFF
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	#elif ADC_INTERRUPT_MODE == ADC_INTERRUPT_OFF
		SET_BIT(ADCSRA,ADCSRA_ADIE);
	#endif
	/*end of ADC interrupt configuration*/


	/*ADC prescalar configurations */
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	ADCSRA |= ADC_PRESCALAR;
	/*end of ADC prescalar configurations */

	/*enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

uint8 ADC_uint8_GetChannelReading(uint8 copy_uint8_channel)
{
	/* clear the ADC MUX bits in ADMUX register */
	CLR_BIT(ADMUX,ADMUX_MUX4);
	CLR_BIT(ADMUX,ADMUX_MUX3);
	CLR_BIT(ADMUX,ADMUX_MUX2);
	CLR_BIT(ADMUX,ADMUX_MUX1);
	CLR_BIT(ADMUX,ADMUX_MUX0);

	/*set the required channel into MUX bits*/
	ADMUX |= copy_uint8_channel;

	/*start the conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*Polling (busy waiting) until the conversion complete flag is set*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF)) == STD_LOW);

	/*clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	/*return the reading*/
	return ADCH;
}

uint8 ADC_uint8_StartConversionSynch(uint8 copy_uint8_channel, uint8* copy_puint8_reading)
{
	if(ADC_uint8_BusyState == ADC_NOTBUSY)
	{
		ADC_uint8_BusyState = ADC_BUSY;
		uint32 local_uint32_counter = STD_LOW;
		uint8 local_uint8_error = TRUE;

		/* clear the ADC MUX bits in ADMUX register */
		CLR_BIT(ADMUX,ADMUX_MUX4);
		CLR_BIT(ADMUX,ADMUX_MUX3);
		CLR_BIT(ADMUX,ADMUX_MUX2);
		CLR_BIT(ADMUX,ADMUX_MUX1);
		CLR_BIT(ADMUX,ADMUX_MUX0);

		/*set the required channel into MUX bits*/
		ADMUX |= copy_uint8_channel;

		/*start the conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*Polling (busy waiting) until the conversion complete flag is set or counter reach timeout value*/
		while(((GET_BIT(ADCSRA,ADCSRA_ADIF)) == STD_LOW) && (local_uint32_counter != ADC_uint32_TIMEOUT))
		{
			local_uint32_counter++;
		}

		if(local_uint32_counter == ADC_uint32_TIMEOUT)
		{
			/*loop is broken as timeout is reached*/
			local_uint8_error = FALSE;
			ADC_uint8_BusyState = ADC_NOTBUSY;
		}
		else
		{
			/*loop is broken as timeout is reached*/
			/*clear the conversion complete flag*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);
			*copy_puint8_reading = ADCH;
			ADC_uint8_BusyState = ADC_NOTBUSY;
		}
		/*return the error state*/
		return local_uint8_error;
	}


}

uint8 ADC_uint8_StartConversionAsynch(uint8 copy_uint8_channel, uint8* copy_puint8_reading, void (*copy_pv_NotificationFunction)(void))
{
	uint8 local_uint8_error = TRUE;
	if(ADC_uint8_BusyState == ADC_NOTBUSY)
	{
		if ((copy_puint8_reading == NULL) || (copy_pv_NotificationFunction == NULL))
		{
			local_uint8_error = FALSE;
		}
		else
		{
			/*set ADC to busy to not receive any new conversion request*/
			ADC_uint8_BusyState = ADC_BUSY;

			/*initialize the reading variable*/
			ADC_puint8_Reading = copy_puint8_reading;

			/*initialize the call back function*/
			ADC_pv_CallBackNotification = copy_pv_NotificationFunction;

			/* clear the ADC MUX bits in ADMUX register */
			CLR_BIT(ADMUX,ADMUX_MUX4);
			CLR_BIT(ADMUX,ADMUX_MUX3);
			CLR_BIT(ADMUX,ADMUX_MUX2);
			CLR_BIT(ADMUX,ADMUX_MUX1);
			CLR_BIT(ADMUX,ADMUX_MUX0);

			/*set the required channel into MUX bits*/
			ADMUX |= copy_uint8_channel;

			/*start the conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*ADC interrupt Enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}


	}
		return local_uint8_error;

}

void __vector_16 (void)	__attribute__((signal));
void __vector_16 (void)
{
	/*read the ADC result*/
	*ADC_puint8_Reading = ADCH;

	/*call the call back function*/
	ADC_pv_CallBackNotification();

	/*disable ADC conversion complete interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);

	/*set the ADC to NOTBUSY to start new conversion if requested*/
	ADC_uint8_BusyState = ADC_NOTBUSY;
}


