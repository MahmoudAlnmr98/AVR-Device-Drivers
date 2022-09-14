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
	uint8 taskstate;
	uint16 firstDelay;
	void (*taskFunc)(void);
	
	
}task_t;

static void Schedular(void);

#define TASK_RUNNING			0
#define TASK_SUSPENDED			1

#define OFFSET					1

#endif /* RTOS_RTOS_PRIVATE_H_ */
