/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC:
*Layer:
*Version:
***********************************************************/
#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_


void RTOS_void_Start(void);

void RTOS_void_CreateTask(uint8 copy_uint8_priority, uint16 copy_uint16_periodicity, void (*pvTaskFunc)(void));
#endif /* RTOS_RTOS_INTERFACE_H_ */
