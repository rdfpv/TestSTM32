#ifndef __UFLASH_H
#define __UFLASH_H

/* Includes ----------------------------------------------------------*/
#include "stm32f0xx_hal.h"

#include <stdint.h>


/* Private typedef -----------------------------------------------------------*/
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

//uint8_t WriteEpromFlash(uint8_t add,uint8_t dat);
//uint8_t ReadEpromFlash(uint8_t add);



uint32_t FLASH_PagesMask(__IO uint32_t Size);
//void FLASH_Layer_Lock(void);
//void FLASH_Layer_Unlock(void);
//FLASH_Status FLASH_LAYER_ErasePage(uint32_t Page_Address);
//FLASH_Status FLASH_LAYER_ProgramWord(uint32_t Address, uint32_t Data);

uint32_t ReadWordEpromFlash(uint32_t eepAddress);


void ErasePage(uint32_t addrEpFlash, uint8_t eraseNum);
uint8_t ReadEpromFlash(uint32_t addrEpFlash, uint8_t add);
uint8_t WriteEpromFlash(uint32_t addrEpFlash,uint8_t add,uint8_t dat);


uint8_t RecoveryBackup(uint32_t srcAddr, uint32_t dstAddr, uint8_t numPage,uint16_t pageSize);

uint8_t DecodeCodeAES(uint32_t srcAddr,uint8_t numPage, const uint8_t *key,uint16_t pageSize);

#endif
