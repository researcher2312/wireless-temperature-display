/*
 * STLM75.h
 *
 *  Created on: Nov 26, 2020
 *      Author: researcher
 */

#ifndef INC_STLM75_H_
#define INC_STLM75_H_

#include <stdio.h>

#include "i2c.h"

#define TEMP_ADDRESS 0b1001000


typedef struct{
	I2C_HandleTypeDef *hi2c;
	uint8_t address;
}TEMP_HandleTypeDef;

HAL_StatusTypeDef TEMP_Reset(TEMP_HandleTypeDef *htemp);
HAL_StatusTypeDef TEMP_Sleep(TEMP_HandleTypeDef *htemp);
void TEMP_GetTemperature(TEMP_HandleTypeDef *htemp, int16_t *temperature);


#endif /* INC_STLM75_H_ */
