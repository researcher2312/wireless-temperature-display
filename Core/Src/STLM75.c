/*
 * STLM75.c
 *
 *  Created on: Nov 26, 2020
 *      Author: researcher
 */
#include "STLM75.h"

HAL_StatusTypeDef TEMP_Reset(TEMP_HandleTypeDef *htemp){
	uint8_t overwrite = 0x00;
	return HAL_I2C_Mem_Write(htemp->hi2c, htemp->address, 0x01, 1, &overwrite, 1, 100);
}

HAL_StatusTypeDef TEMP_Sleep(TEMP_HandleTypeDef *htemp){
	uint8_t overwrite = 0x01;
	return HAL_I2C_Mem_Write(htemp->hi2c, htemp->address, 0x01, 1, &overwrite, 1, 100);
}

void TEMP_GetTemperature(TEMP_HandleTypeDef *htemp, int16_t *temperature){
	uint8_t reading[2];
	HAL_I2C_Mem_Read(htemp->hi2c, htemp->address, 0x00, 1, reading, 2, 100);
	*temperature = (reading[0] << 1) + (reading[1] >> 7);
	if (*temperature & 0x100){
		*temperature = !*temperature;
		*temperature++;
	}
}

