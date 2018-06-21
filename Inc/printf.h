#ifndef PRINTF_H
#define PRINTF_H 100

/* C++ detection */
#ifdef __cplusplus
extern C {
#endif
/*-----------------------------------------------------*/	
#include "stm32f0xx_hal.h"
#include "stdio.h"

extern UART_HandleTypeDef huart3;

	#ifdef __GNUC__
		/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf set to 'Yes') calls __io_putchar() */
		#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
		#define GETCHAR_PROTOTYPE int __io_getchar(int ch)
	#else
		#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
		#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
	#endif /* __GNUC__ */		
/*-----------------------------------------------------*/	
/* C++ detection */
		
#define TRACE_LEVEL 		1
#if (TRACE_LEVEL > 0 )
#include <stdio.h>
#define TRACE_DEBUG(...)	{ printf("" __VA_ARGS__); }

#else
#include <stdio.h>
#define TRACE_DEBUG(...)	{ }
#endif /* end of TRACE_LEVEL */


#ifdef __cplusplus
}
#endif
#endif

