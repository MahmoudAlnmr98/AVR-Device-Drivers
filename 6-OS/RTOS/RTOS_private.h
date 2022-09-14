/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC:
*Layer:
*Version:
***********************************************************/
#ifndef RTOS_RTOS_PRIVATE_H_
#define RTOS_RTOS_PRIVATE_H_


typedef struct
{
	uint16 periodicity;
	void (*taskFunc)(void);
	
}task_t;

static void Schedular(void);

#endif /* RTOS_RTOS_PRIVATE_H_ */
