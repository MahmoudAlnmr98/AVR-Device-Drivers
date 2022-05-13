/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC: Global interrupt
*Layer: MCAL
*Version: 1.00
***********************************************************/
#ifndef GIE_REGISTERS_H_
#define GIE_REGISTERS_H_

#define STATUS_REGISTER					*((volatile uint8*)0x5F)

/*bit responsible for enabling global interrupt*/
#define STATUS_REGISTER_I				7


#endif /* GIE_REGISTERS_H_ */
