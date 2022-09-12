/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC: ADC
*Layer: MCAL
*Version: 1.00
***********************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/* channel macros */
#define ADC_SINGLE_ENDED_ADC0							0b00000
#define ADC_SINGLE_ENDED_ADC1           				0b00001
#define ADC_SINGLE_ENDED_ADC2           				0b00010
#define ADC_SINGLE_ENDED_ADC3           				0b00011
#define ADC_SINGLE_ENDED_ADC4           				0b00100
#define ADC_SINGLE_ENDED_ADC5           				0b00101
#define ADC_SINGLE_ENDED_ADC6           				0b00110
#define ADC_SINGLE_ENDED_ADC7           				0b00111


#define ADC_DIFFERENTIAL_ADC0_ADC0_10X					0b01000
#define ADC_DIFFERENTIAL_ADC1_ADC0_10X					0b01001
#define ADC_DIFFERENTIAL_ADC0_ADC0_200X					0b01010
#define ADC_DIFFERENTIAL_ADC1_ADC0_100X					0b01011
#define ADC_DIFFERENTIAL_ADC2_ADC2_10X					0b01100
#define ADC_DIFFERENTIAL_ADC3_ADC2_10X					0b01101
#define ADC_DIFFERENTIAL_ADC2_ADC2_200X					0b01110
#define ADC_DIFFERENTIAL_ADC3_ADC2_200X					0b01111


#define ADC_DIFFERENTIAL_ADC0_ADC1						0b10000
#define ADC_DIFFERENTIAL_ADC1_ADC1						0b10001
#define ADC_DIFFERENTIAL_ADC2_ADC1						0b10010
#define ADC_DIFFERENTIAL_ADC3_ADC1						0b10011
#define ADC_DIFFERENTIAL_ADC4_ADC1						0b10100
#define ADC_DIFFERENTIAL_ADC5_ADC1						0b10101
#define ADC_DIFFERENTIAL_ADC6_ADC1						0b10110
#define ADC_DIFFERENTIAL_ADC7_ADC1						0b10111


#define ADC_DIFFERENTIAL_ADC0_ADC2						0b11000
#define ADC_DIFFERENTIAL_ADC1_ADC2						0b11001
#define ADC_DIFFERENTIAL_ADC2_ADC2						0b11010
#define ADC_DIFFERENTIAL_ADC3_ADC2						0b11011
#define ADC_DIFFERENTIAL_ADC4_ADC2						0b11100
#define ADC_DIFFERENTIAL_ADC5_ADC2						0b11101


#define ADC_SINGLE_ENDED_1_22V							0b11110
#define	ADC_SINGLE_ENDED_0V_GND							0b11111



typedef struct
{
	uint8 * channel;
	uint16 * result;
	uint8 size;
	void (*NotificationFunc)(void);
}chain_t;



void ADC_void_Init();

uint8 ADC_uint8_GetChannelReading(uint8 copy_uint8_channel);

uint8 ADC_uint8_StartConversionSynch(uint8 copy_uint8_channel, uint8* copy_puint8_reading);

uint8 ADC_uint8_StartConversionAsynch(uint8 copy_uint8_channel, uint8* copy_puint8_reading, void (*copy_pv_NotificationFunction)(void));

uint8 ADC_uiny8_StartConversoinAsyn(chain_t *copy_chain);

#endif /* ADC_INTERFACE_H_ */
