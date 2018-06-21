/* Includes ----------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include User --------------------------------------------------------
#include "umain.h"
#include "printf.h"
#include "stdbool.h"
//#include "integer.h"
//#include "uCommon.h"
//#include "uHost.h"
//#include "uAES_Mang.h"
#include "uFlash.h"



uint32_t PageError = 0;

//---------------------------------------------------


uint32_t Addr=0;
uint32_t rsource=0;
uint8_t eeFlash[2060] ={0x00};

uint32_t backupPtr=0;
uint32_t srcBkupAddr=0;
uint8_t DataBkup[2060]={0x00};


/*
void ErasePage(uint32_t addrEpFlash, uint8_t eraseNum) {
	FLASH_EraseInitTypeDef ErasePageStruct;
	//HAL_FLASH_Unlock();
	ErasePageStruct.TypeErase = FLASH_TYPEERASE_PAGES;
  ErasePageStruct.PageAddress = addrEpFlash;
  ErasePageStruct.NbPages = eraseNum;
	if(HAL_FLASHEx_Erase(&ErasePageStruct, &PageError)!=HAL_OK){
		//HAL_FLASH_Lock();
	}
	//HAL_FLASH_Lock();
}

uint8_t ReadEpromFlash(uint32_t addrEpFlash,uint8_t add) {
	memset(eeFlash,0,sizeof(eeFlash));
	rsource = (uint32_t)eeFlash;
	Addr = addrEpFlash;
	while (Addr < EEPROM_FLASH_END_PAGE) {
    *(uint32_t*)rsource = *(__IO uint32_t *)Addr;
    Addr = Addr + 4;
		rsource = rsource +4;
  }
	
	return eeFlash[add];
}
*/
/*
uint8_t ReadEpromFlash(uint32_t addrEpFlash, uint8_t add) {
	memset(eeFlash,0,sizeof(eeFlash));
	rsource = (uint32_t)eeFlash;
	Addr = addrEpFlash;
	while (Addr < EEPROM_FLASH_END_PAGE) {
    *(uint32_t*)rsource = *(__IO uint32_t *)Addr;
    Addr = Addr + 4;
		rsource = rsource +4;
  }
	return eeFlash[add];
}
*/

uint8_t WriteEpromFlash(uint32_t addrEpFlash, uint8_t add,uint8_t dat) {
	FLASH_EraseInitTypeDef EraseEpromStruct;
	HAL_FLASH_Unlock();
	memset(eeFlash,0,sizeof(eeFlash));
	
	rsource = (uint32_t)eeFlash;
	Addr = addrEpFlash;
	while (Addr < EEPROM_FLASH_END_PAGE){
    *(uint32_t*)rsource = *(__IO uint32_t *)Addr;
    Addr = Addr + 4;
		rsource = rsource +4;
  }
	EraseEpromStruct.TypeErase = FLASH_TYPEERASE_PAGES;
  EraseEpromStruct.PageAddress = addrEpFlash;
  EraseEpromStruct.NbPages = 1;
	
	if(HAL_FLASHEx_Erase(&EraseEpromStruct, &PageError)!=HAL_OK){
		HAL_FLASH_Lock();
		//printf("Xoa error\r\n");
		return false;
	}
	
	eeFlash[add] = dat;
	Addr = addrEpFlash;
	rsource = (uint32_t)eeFlash;
	while (Addr < EEPROM_FLASH_END_PAGE){
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Addr,*(uint32_t*)rsource) == HAL_OK){
      Addr = Addr + 4;
			rsource = rsource +4;
    }
		else {
			HAL_FLASH_Lock();
		//	printf("Ghi error\r\n");
			return false;
		}
  }
	HAL_FLASH_Lock();
	return true;
}

/*
void WriteEpromFlash(uint32_t addrEpFlash,uint8_t add,uint8_t dat) {
	FLASH_Layer_Unlock();
	memset(eeFlash,0,sizeof(eeFlash));
	
	rsource = (uint32_t)eeFlash;
	Addr = addrEpFlash;
	while (Addr < EEPROM_FLASH_END_PAGE){
    *(uint32_t*)rsource = *(__IO uint32_t *)Addr;
    Addr = Addr + 4;
		rsource = rsource +4;
  }
	FLASH_LAYER_ErasePage(addrEpFlash);	
	
	eeFlash[add] = dat;
	Addr = addrEpFlash;
	rsource = (uint32_t)eeFlash;
	while (Addr < EEPROM_FLASH_END_PAGE){
    if (FLASH_LAYER_ProgramWord(Addr,*(uint32_t*)rsource) == FLASH_COMPLETE){
      Addr = Addr + 4;
			rsource = rsource +4;
    }
  }
	FLASH_Layer_Lock();
}
*/

//**********************************************************************
//----------------------------------------------------------------------
/**
  * @brief  Programs a word at a specified address.
  * @param  Address: specifies the address to be programmed.
  * @param  Data: specifies the data to be programmed.
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
  *   			FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
//----------------------------------------------------------------------
//**********************************************************************
//FLASH_Status FLASH_LAYER_ProgramWord(uint32_t Address, uint32_t Data)
//{
//  FLASH_Status status = FLASH_COMPLETE;

//  status = FLASH_ProgramWord(Address, Data);
//  return status;
//}

//**********************************************************************
//----------------------------------------------------------------------
/**
  * @brief  Erases a specified FLASH page.
  * @param  Page_Address: The page address to be erased.
  * @retval FLASH Status: The returned value can be: FLASH_BUSY, FLASH_ERROR_PG,
  *   			FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
//----------------------------------------------------------------------
//**********************************************************************
//FLASH_Status FLASH_LAYER_ErasePage(uint32_t Page_Address)
//{
//  FLASH_Status status = FLASH_COMPLETE;

//  status = FLASH_ErasePage(Page_Address);
//  return status;
//}


//void FLASH_Layer_Unlock(void) {
//	FLASH_Unlock();
//}

//void FLASH_Layer_Lock(void) {
//	FLASH_Lock();
//}
//**********************************************************************
//----------------------------------------------------------------------
/**
  * @brief  Calculate the number of pages
  * @param  Size: The image size
  * @retval The number of pages
  */
//----------------------------------------------------------------------
uint32_t FLASH_PagesMask(__IO uint32_t Size) {
  uint32_t pagenumber = 0x0;
  uint32_t size = Size;

  if ((size % PAGE_SIZE_PROG) != 0)
  {
    pagenumber = (size / PAGE_SIZE_PROG) + 1;
  }
  else
  {
    pagenumber = size / PAGE_SIZE_PROG;
  }
  return pagenumber;

}
