#include "printf.h"

uint8_t fac_us;

PUTCHAR_PROTOTYPE
{
	if(HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, 200) != HAL_OK)
	{
		Error_Handler();
	}
	return ch;
}


