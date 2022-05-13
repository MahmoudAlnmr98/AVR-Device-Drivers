/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC: External Interrupt
*Layer: MCAL
*Version: 1.00
***********************************************************/

#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_register.h"

/*
 * global pointer to function to hold INT0,	INT1, INT2 ISR address
 */
void (*EXTI_pf_INT0Func)(void) = NULL;
void (*EXTI_pf_INT1Func)(void) = NULL;
void (*EXTI_pf_INT2Func)(void) = NULL;

void EXTI_void_INT0Init(void)
{
#if EXTI_INT0_SENSE_CONTROL == LOW_LEVEL
	SET_BIT(GENERAL_INTERRUPT_CONTROL_REGISTER,GENERAL_INTERRUPT_CONTROL_REGISTER_INT0);
	CLR_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC01);
	CLR_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC00);

#elif EXTI_INT0_SENSE_CONTROL == ON_CHANGE
	SET_BIT(GENERAL_INTERRUPT_CONTROL_REGISTER,GENERAL_INTERRUPT_CONTROL_REGISTER_INT0);
	CLR_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC01);
	SET_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC00);

#elif EXTI_INT0_SENSE_CONTROL == FALLING_EDGE
	SET_BIT(GENERAL_INTERRUPT_CONTROL_REGISTER,GENERAL_INTERRUPT_CONTROL_REGISTER_INT0);
	SET_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC01);
	CLR_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC00);

#elif EXTI_INT0_SENSE_CONTROL == RISING_EDGE
	SET_BIT(GENERAL_INTERRUPT_CONTROL_REGISTER,GENERAL_INTERRUPT_CONTROL_REGISTER_INT0);
	SET_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC01);
	SET_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC00);

#else
#error "wrong EXTI INT0 sense control configuration, please choose the right one"
#endif
}

void EXTI_void_INT1Init(void)
{
#if EXTI_INT1_SENSE_CONTROL == LOW_LEVEL
	SET_BIT(GENERAL_INTERRUPT_CONTROL_REGISTER,GENERAL_INTERRUPT_CONTROL_REGISTER_INT1);
	CLR_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC11);
	CLR_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC10);

#elif EXTI_INT1_SENSE_CONTROL == ON_CHANGE
	SET_BIT(GENERAL_INTERRUPT_CONTROL_REGISTER,GENERAL_INTERRUPT_CONTROL_REGISTER_INT1);
	CLR_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC11);
	SET_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC10);

#elif EXTI_INT1_SENSE_CONTROL == FALLING_EDGE
	SET_BIT(GENERAL_INTERRUPT_CONTROL_REGISTER,GENERAL_INTERRUPT_CONTROL_REGISTER_INT1);
	SET_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC11);
	CLR_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC10);

#elif EXTI_INT1_SENSE_CONTROL == RISING_EDGE
	SET_BIT(GENERAL_INTERRUPT_CONTROL_REGISTER,GENERAL_INTERRUPT_CONTROL_REGISTER_INT1);
	SET_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC11);
	SET_BIT(MCU_CONTROL_REGISTER,MCU_CONTROL_REGISTER_ISC10);
#else
#error "wrong EXTI INT1 sense control configuration, please choose the right one"
#endif

}

void EXTI_void_INT2Init(void)
{
#if EXTI_INT2_SENSE_CONTROL == FALLING_EDGE
	SET_BIT(GENERAL_INTERRUPT_CONTROL_REGISTER,GENERAL_INTERRUPT_CONTROL_REGISTER_INT2);
	CLR_BIT(MCU_CONTROL_AND_STATUS_REGISTER,MCU_CONTROL_AND_STATUS_REGISTER_INT2);

#elif EXTI_INT2_SENSE_CONTROL == RISING_EDGE
	SET_BIT(GENERAL_INTERRUPT_CONTROL_REGISTER,GENERAL_INTERRUPT_CONTROL_REGISTER_INT2);
	SET_BIT(MCU_CONTROL_AND_STATUS_REGISTER,MCU_CONTROL_AND_STATUS_REGISTER_INT2);

#else
#error "wrong EXTI INT2 sense control configuration, please choose the right one"
#endif

}

uint8 EXTI_uint8_INT0SetCallBack(void (*copy_pf_INT0Func)(void))
{
	uint8 local_uint8_errorStatus = STD_LOW;

	if(copy_pf_INT0Func != NULL)
	{
		EXTI_pf_INT0Func = copy_pf_INT0Func;
	}
	else
	{
		local_uint8_errorStatus = STD_HIGH;
	}

	return local_uint8_errorStatus;
}

uint8 EXTI_uint8_INT1SetCallBack(void (*copy_pf_INT1Func)(void))
{
	uint8 local_uint8_errorStatus = STD_LOW;

	if(copy_pf_INT1Func != NULL)
	{
		EXTI_pf_INT1Func = copy_pf_INT1Func;
	}
	else
	{
		local_uint8_errorStatus = STD_HIGH;
	}

	return local_uint8_errorStatus;
}

uint8 EXTI_uint8_INT2SetCallBack(void (*copy_pf_INT2Func)(void))
{
	uint8 local_uint8_errorStatus = STD_LOW;

	if(copy_pf_INT2Func != NULL)
	{
		EXTI_pf_INT2Func = copy_pf_INT2Func;
	}
	else
	{
		local_uint8_errorStatus = STD_HIGH;
	}

	return local_uint8_errorStatus;
}


void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pf_INT0Func != NULL)
	{
		EXTI_pf_INT0Func();
	}
	else
	{
		/*
		 * do nothing
		 */
	}

}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pf_INT1Func != NULL)
	{
		EXTI_pf_INT1Func();
	}
	else
	{
		/*
		 * do nothing
		 */
	}

}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pf_INT2Func != NULL)
	{
		EXTI_pf_INT2Func();
	}
	else
	{
		/*
		 * do nothing
		 */
	}

}
