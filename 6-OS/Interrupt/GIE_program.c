/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC: Global interrupt
*Layer: MCAL
*Version: 1.00
***********************************************************/

#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_registers.h"
#include "GIE_private.h"
#include "GIE_config.h"


void GIE_void_EnableGlobalInterrupt(void)
{
	SET_BIT(STATUS_REGISTER,STATUS_REGISTER_I);
}

void GIE_void_DisableGlobalInterrupt(void)
{
	CLR_BIT(STATUS_REGISTER,STATUS_REGISTER_I);
}
