#ifndef __MAIN_H
#define __MAIN_H
#include "stm32f0xx_hal.h"


/* UART BootLoader ------------------------------------------------------------------------------*/
//#define USART_BL_GPIO_CLK          			RCC_AHBPeriph_GPIOA
//#define USART_BL_CLK               			RCC_APB2Periph_USART1
//#define USART_BL_GPIO              			GPIOA
//#define	USART_BL												USART1
//#define USART_BL_TxPin             			GPIO_Pin_9
//#define USART_BL_RxPin             			GPIO_Pin_10
//#define USART_BL_PinSrc_9								GPIO_PinSource9
//#define USART_BL_PinSrc_10							GPIO_PinSource10
//#define USART_BL_BAUDRATE								115200

//#define USE_BOOTLOADER_UART1
#define USE_BOOTLOADER_UART3

#if defined (USE_BOOTLOADER_UART1)

	#define USART_BL_GPIO_CLK          			RCC_AHBPeriph_GPIOC
	#define USART_BL_CLK               			RCC_APB2Periph_USART1
	#define USART_BL_GPIO              			GPIOC
	#define	USART_BL												USART1
	#define USART_BL_TxPin             			GPIO_Pin_4
	#define USART_BL_RxPin             			GPIO_Pin_5
	#define USART_BL_PinSrc_TX								GPIO_PinSource4
	#define USART_BL_PinSrc_RX								GPIO_PinSource5
	#define USART_BL_BAUDRATE								115200
#elif defined (USE_BOOTLOADER_UART3)
	#define USART_BL_GPIO_CLK          			RCC_AHBPeriph_GPIOB
	#define USART_BL_CLK               			RCC_APB1Periph_USART3
	#define USART_BL_GPIO              			GPIOB
	#define	USART_BL												USART3
	#define USART_BL_TxPin             			GPIO_Pin_10
	#define USART_BL_RxPin             			GPIO_Pin_11
	#define USART_BL_PinSrc_TX							GPIO_PinSource10
	#define USART_BL_PinSrc_RX							GPIO_PinSource11
	#define USART_BL_BAUDRATE								115200
#endif

/* UART Debug ------------------------------------------------------------------------------*/
#define USART_DEBUG_GPIO_CLK          	RCC_AHBPeriph_GPIOA
#define USART_DEBUG_CLK               	RCC_APB1Periph_USART2
#define USART_DEBUG_GPIO              	GPIOA
#define	USART_DEBUG											USART2
#define USART_DEBUG_TxPin             	GPIO_Pin_2
#define USART_DEBUG_RxPin             	GPIO_Pin_3
#define USART_DEBUG_PinSrc_2						GPIO_PinSource2
#define USART_DEBUG_PinSrc_3						GPIO_PinSource3
#define USART_DEBUG_BAUDRATE						115200


/* Check MCU Memory ------------------------------------------------------------------------------*/
#define	CAPACITY_64KB								0x0040		//64 KB
#define	CAPACITY_128KB							0x0080		//128 KB
#define CAPACITY_256KB							0x0100		//256 KB
#define CAPACITY_512KB							0x0200		//512 KB

/* Memory 64KB ------------------------------------------------------------------------------*/
#define MEM64_BOOT_SIZE							0x2C00		//11 KB			
#define MEM64_APP_SIZE							0x6000		//24 KB
#define MEM64_BKUP_SIZE							0x6000		//24 KB
#define MEM64_EEPROM_SIZE						0x400			//1  KB
#define MEM64_LOGO_DFT_SIZE					0x400			//1  KB
#define MEM64_LOGO_USER_SIZE				0x400			//1  KB
#define MEM64_REVERVE_SIZE					0x800			//2  KB
#define	MEM64_PAGE_SIZE							0x400			//1  KB


/* Memory 128KB ------------------------------------------------------------------------------*/
#define MEM128_BOOT_SIZE						0x3400		//13 KB			
#define MEM128_APP_SIZE							0xD800		//54 KB
#define MEM128_BKUP_SIZE						0xD800		//54 KB
#define MEM128_EEPROM_SIZE					0x400			//1  KB
#define MEM128_LOGO_DFT_SIZE				0x400			//1  KB
#define MEM128_LOGO_USER_SIZE				0x400			//1  KB
#define MEM128_REVERVE_SIZE					0x1000		//4  KB
#define	MEM128_PAGE_SIZE						0x400			//1  KB

/* Memory 256KB ------------------------------------------------------------------------------*/
#define MEM256_BOOT_SIZE						0x3800		//14 KB			
#define MEM256_APP_SIZE							0x1C800		//116 KB
#define MEM256_BKUP_SIZE						0x1C800		//116 KB
#define MEM256_EEPROM_SIZE					0x800			//2  KB
#define MEM256_LOGO_DFT_SIZE				0x800			//2  KB
#define MEM256_LOGO_USER_SIZE				0x800			//2  KB
#define MEM256_REVERVE_SIZE					0x2000		//8  KB
#define	MEM256_PAGE_SIZE						0x800			//2  KB

/* Memory 512KB ------------------------------------------------------------------------------*/
#define MEM512_BOOT_SIZE						0x4000		//16 KB			
#define MEM512_APP_SIZE							0x3C000		//240 KB
#define MEM512_BKUP_SIZE						0x3C000		//240 KB
#define MEM512_EEPROM_SIZE					0x800			//2  KB
#define MEM512_LOGO_DFT_SIZE				0x800			//2  KB
#define MEM512_LOGO_USER_SIZE				0x800			//2  KB
#define MEM512_REVERVE_SIZE					0x2800		//10  KB
#define	MEM512_PAGE_SIZE						0x800			//2  KB


#define BASE_ADDR_UNIQUE_ID					0x1FFFF7AC
#define BASE_ADDR_FLASH_SIZE				0x1FFFF7CC

#define READ_MEM_MCU					 		*(__IO uint16_t*)(BASE_ADDR_FLASH_SIZE)


#define	EepromFlashAddress					0x0803C800

#define PageSize 0x800

#define PAGE_SIZE_PROG          								PageSize 
#define	EEPROM_FLASH_END_PAGE									((uint32_t)(EepromFlashAddress+PageSize))
 

/* BootLoader Memory Allocation ------------------------------------------------------------------------------*/
#define FLASH_STARTADDRESS          ((uint32_t)0x08000000) /* Flash Start Address */

// ----------------------------------------
#define	RUN_CODE_ADDR									0
#define	NUM_PAGE_MAIN_ADDR						1
#define	NUM_PAGE_BKUP_ADDR						2
//-----------------------------------------
#define	PRO_KIND_ADDR									3
#define	HW_VER_ADDR										5
#define	FW_VER_ADDR										7
#define	SEND_UUID_DFT_ADDR						9
#define BT_SETUP_ADDR									10
// ----------------------------------------
#define ADDRESS_BASE									12
#define BT_NAME_ADDR									ADDRESS_BASE		   //12
#define BT_NAME_SIZE									12

#define BT_PASS_ADDR									ADDRESS_BASE + BT_NAME_SIZE  //6 
#define BT_PASS_SIZE									6
//-----------------------------------------
#define SUCCESS_BKUP_ADDR							ADDRESS_BASE + BT_PASS_SIZE
#define SUCCESS_BKUP_SIZE							1

#define SUCCESS_MAIN_ADDR							ADDRESS_BASE + SUCCESS_BKUP_ADDR
#define SUCCESS_MAIN__SIZE						1

#define SUCCESS_DECODE_ADDR						ADDRESS_BASE + SUCCESS_MAIN__SIZE
#define SUCCESS_DECODE_SIZE						1

#define HAVE_APP_CODE_ADDR						ADDRESS_BASE + SUCCESS_DECODE_SIZE
#define	HAVE_APP_CODE_SIZE						1


/* End Define EEPROM --------------------------------------------------------------------------------------------*/

#define DIS_SEND_UUID_FAC							0x01


#define MARK_RUN_BOOT_CODE						0x5A		// Run BootLoader
#define MARK_RUN_RECOVER_CODE					0x5B  	// Run Recovery code
#define MARK_RUN_DECODE_CODE					0x5C		// Run Decode code
#define MARK_RUN_MAIN_CODE						0x5D  	// Run main code




/* Error BootLoader ------------------------------------------------------------------------------*/
#define IAP_PROG_SUCCESS							0x00
#define IAP_PROG_LARGESIZE_ERROR			0xA1
#define IAP_PROG_VERIFY_ERROR					0xA2
#define	IAP_PROG_ABORT_ERROR					0xA3
#define IAP_PROG_CRC_ERROR						0xA4
#define IAP_PROG_FILE_ERROR						0xA5

#define IAP_BKUP_ERASE_ERROR					0xA6
#define IAP_BKUP_VERIFY_ERROR					0xA7

#define IAP_DECODE_ERASE_ERROR				0xA8
#define IAP_DECODE_VERIFY_ERROR				0xA9

#endif
