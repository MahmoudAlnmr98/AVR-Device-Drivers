/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC: External Interrupt
*Layer: MCAL
*Version: 1.00
***********************************************************/
#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define	GENERAL_INTERRUPT_CONTROL_REGISTER					*((volatile uint8* )0x5B)

#define GENERAL_INTERRUPT_CONTROL_REGISTER_INT1				7
#define GENERAL_INTERRUPT_CONTROL_REGISTER_INT0				6
#define GENERAL_INTERRUPT_CONTROL_REGISTER_INT2				5

#define	GIFR												*((volatile uint8* )0x5A)
#define	MCU_CONTROL_REGISTER								*((volatile uint8* )0x5B)

/*ISC INTERRUPT SENSE CONTROL*/
#define MCU_CONTROL_REGISTER_ISC11							3
#define MCU_CONTROL_REGISTER_ISC10							2
#define MCU_CONTROL_REGISTER_ISC01							1
#define MCU_CONTROL_REGISTER_ISC00 							0

#define	MCU_CONTROL_AND_STATUS_REGISTER						*((volatile uint8* )0x5B)

#define MCU_CONTROL_AND_STATUS_REGISTER_INT2				6

#endif /* EXTI_REGISTER_H_ */
