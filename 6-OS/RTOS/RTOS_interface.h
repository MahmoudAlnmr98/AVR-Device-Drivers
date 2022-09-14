/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC:
*Layer:
*Version:
***********************************************************/
#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_

#define EMPTY_PRIORITY			0	
#define TAKEN_PRIORITY			1

void RTOS_void_Start(void);

uint8 RTOS_uint8_CreateTask(uint8 copy_uint8_priority, uint16 copy_uint16_periodicity, uint16 copy_uint8_firstDelay, void (*pvTaskFunc)(void));

void RTOS_void_suspendTask(uint8 copy_uint8_priority);

void RTOS_void_ResumeTask(uint8 copy_uint8_priority);

void RTOS_void_DeleteTask(uint8 copy_uint8_priority);
#endif /* RTOS_RTOS_INTERFACE_H_ */
