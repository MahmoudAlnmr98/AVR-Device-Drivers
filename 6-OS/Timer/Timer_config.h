/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC: Timer
*Layer: MCAL
*Version: 1.00
***********************************************************/
#ifndef TIMER_TIMER_CONFIG_H_
#define TIMER_TIMER_CONFIG_H_

/*timer0 prescaler option*/

#define TIMER_PRESCALER_NO                       1
#define TIMER_PRESCALER_8                        2
#define TIMER_PRESCALER_64                       3
#define TIMER_PRESCALER_256                      4
#define TIMER_PRESCALER_1024                     5
#define TIMER_EXTERNAL_CLK_T0_FALLING_EDGE       6
#define TIMER_EXTERNAL_CLK_T0_RISING_EDGE        7


#define TIMER_PRESCALER_ON						0
#define TIMER_EXTERNAL_CLK_ON					1

#define TIMER_PRESCALER_MODE					TIMER_PRESCALER_ON

#define TIMER_PRESCALER							TIMER_PRESCALER_64
#define TIMER_EXTERNAL_CLK						TIMER_EXTERNAL_CLK_T0_FALLING_EDGE

/*compare match value*/
#define TIMER0_COMPARE_MATCH_VALUE				125

#endif /* TIMER_TIMER_CONFIG_H_ */
