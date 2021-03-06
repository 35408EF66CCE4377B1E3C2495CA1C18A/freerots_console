#ifndef __CONFIGMANAGEMENT_H
#define __CONFIGMANAGEMENT_H

#include <stdint.h>
#include "stm32f4xx_hal.h"

typedef struct
{
	uint64_t DutyRoomNumber;
	uint64_t WatchKeeper1;
	uint64_t WatchKeeper2;
	uint8_t	Mac[6];
	uint8_t	IP[4];
	uint8_t SubMask[4];
	uint8_t Gateway[4];
	uint8_t Dns[4];

} ConfigurationTypeDef;

/*
* !!! CAUTION !!!
* DO NOT change this address! The FLASH SECTOR_11 must be used !!
*/
#define CONFIG_START_ADDRESS	0x080E0000
/* !!! CAUTION !!! */

extern ConfigurationTypeDef SystemConfig;


void ReadConfiguration(void);
HAL_StatusTypeDef SaveConfiguration(void);
#endif

