/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC:
*Layer:
*Version:
***********************************************************/
#include "../Library/STD_TYPES.h"

#include "../Timer/Timer_interface.h"

#include "../Interrupt/GIE_interface.h"

#include "RTOS_config.h"
#include "RTOS_private.h"
#include "RTOS_interface.h"


task_t SystemTasks[TASK_NUM] = {{0}};

void RTOS_void_Start(void)
{
	Timer0_uint8_CompareMatchSetCallBack(&Schedular);
	GIE_void_EnableGlobalInterrupt();
	Timer0_void_CTC();
}

uint8 RTOS_uint8_CreateTask(uint8 copy_uint8_priority, uint16 copy_uint16_periodicity, void (*pvTaskFunc)(void))
{
	uint8 local_uint8_errorStatus = EMPTY_PRIORITY;
	
	if(SystemTasks[copy_uint8_priority].taskFunc == NULL)
	{
		SystemTasks[copy_uint8_priority].periodicity = copy_uint16_periodicity;
		SystemTasks[copy_uint8_priority].taskFunc = pvTaskFunc;
		SystemTasks[copy_uint8_priority].taskstate = TASK_RUNNING;
	}
	else
	{
		local_uint8_errorStatus = TAKEN_PRIORITY;
	}
	
	return local_uint8_errorStatus;

}


void RTOS_void_suspendTask(uint8 copy_uint8_priority)
{
	SystemTasks[copy_uint8_priority].taskstate = TASK_SUSPENDED;
}

void RTOS_void_ResumeTask(uint8 copy_uint8_priority)
{
	SystemTasks[copy_uint8_priority].taskstate = TASK_RUNNING;
}

void RTOS_void_DeleteTask(uint8 copy_uint8_priority)
{
	SystemTasks[copy_uint8_priority].taskFunc = NULL;
}

static void Schedular(void)
{
	static uint16 local_uint16_tickCounter = 0;
	uint8 local_uint8_taskCounter;
	
	local_uint16_tickCounter++;
	
	/*loop on all tasks to check their periodicity*/
	for(local_uint8_taskCounter = 0 ; local_uint8_taskCounter < TASK_NUM ; local_uint8_taskCounter++)
	{
		/*checking if task is running execute it else do nothing*/
		if (SystemTasks[local_uint8_taskCounter].taskstate == TASK_RUNNING)
		{
			if((local_uint16_tickCounter % SystemTasks[local_uint8_taskCounter].periodicity) == 0)
				{
					if(SystemTasks[local_uint8_taskCounter].taskFunc != NULL)
					{
						SystemTasks[local_uint8_taskCounter].taskFunc();
					}
					else
					{
						/*do nothing*/
					}
				}
		}
		else
		{
			/*task is suspended do nothing*/
		}
	
	}
	
}
