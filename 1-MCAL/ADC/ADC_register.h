/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC: ADC
*Layer: MCAL
*Version: 1.00
***********************************************************/
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX				*((volatile uint8*)0x27)	/*ADC multiplexer selection register */
#define ADMUX_REFS1         7							/*Reference selection bit1           */
#define ADMUX_REFS0         6							/*Reference selection bit0           */
#define ADMUX_ADLAR         5							/*ADC left adjust result             */
#define ADMUX_MUX4			4
#define ADMUX_MUX3			3
#define ADMUX_MUX2			2
#define ADMUX_MUX1			1
#define ADMUX_MUX0			0


#define ADCSRA				*((volatile uint8*)0x26)	/*ADC control and status register A  */
#define ADCSRA_ADEN			7							/*ADC enable                         */
#define ADCSRA_ADSC			6                           /*Start conversion                   */
#define ADCSRA_ADATE		5                           /*Auto trigger enable                */
#define ADCSRA_ADIF			4                           /*Interrupt flag                     */
#define ADCSRA_ADIE			3                           /*Interrupt enable                   */
#define ADCSRA_ADPS2		2                           /*Prescaler bit2                     */
#define ADCSRA_ADPS1		1                           /*Prescaler bit1                     */
#define ADCSRA_ADPS0		0                           /*Prescaler bit0                     */

#define ADCH				*((volatile uint8*)0x25)	/*ADC high register                  */
#define ADCL				*((volatile uint8*)0x24)	/*ADC Low register                   */

#define SFIOR				*((volatile uint8*)0x50)	/*special function IO register		 */
#define SFIOR_ADTS_2		7
#define SFIOR_ADTS_1		6
#define SFIOR_ADTS_0		5


#endif /* ADC_REGISTER_H_ */
