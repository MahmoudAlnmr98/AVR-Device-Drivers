/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC: Timer
*Layer: MCAL
*Version: 1.00
***********************************************************/

#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"

#include "Timer_interface.h"
#include "Timer_config.h"
#include "Timer_private.h"
#include "Timer_registers.h"


static void (*Timer0_pvCompareMatchCallBackFun)(void) = NULL;



void Timer0_void_CTC()
{
	/*set timer0 in CTC mode*/
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

	/*enable interrupt for CTC mode*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/*set compare match value*/
	OCR0 = TIMER0_COMPARE_MATCH_VALUE;

	/*choose prescaler*/
	CLR_BIT(TCCR0,TCCR0_CS02);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS00);

#if TIMER_PRESCALER_MODE == TIMER_PRESCALER_ON
	TCCR0 |= TIMER_PRESCALER;
#elif TIMER_PRESCALER_MODE == TIMER_EXTERNAL_CLK_ON
	TCCR0 |= TIMER_EXTERNAL_CLK;
#endif


}



uint8 Timer0_uint8_CompareMatchSetCallBack(void (*copy_pv_CallBackFunc)(void))
{
	uint8 local_uint8_error = STD_LOW;
	if(copy_pv_CallBackFunc != NULL)
	{
		Timer0_pvCompareMatchCallBackFun = copy_pv_CallBackFunc;
	}
	else
	{
		local_uint8_error = STD_LOW;
	}
	return local_uint8_error;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(Timer0_pvCompareMatchCallBackFun != NULL)
		{
			Timer0_pvCompareMatchCallBackFun();
		}
}


