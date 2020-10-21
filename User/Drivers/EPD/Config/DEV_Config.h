/*****************************************************************************
* | File      	: DEV_Config.h
* | Author      : Waveshare team
* | Function    :	debug with prntf
* | Info        :
*   Image scanning
*      Please use progressive scanning to generate images or fonts
*----------------
* |	This version:   V1.0
* | Date        :   2018-01-11
* | Info        :   Basic version
*
******************************************************************************/
#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_gpio.h"
#include "main.h"
#include <stdint.h>

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

#define EPD_RST_PIN     EPD_RST_GPIO_Port, EPD_RST_Pin
#define EPD_DC_PIN      EPD_DC_GPIO_Port, EPD_DC_Pin
#define EPD_CS_PIN      EPD_CS_GPIO_Port, EPD_CS_Pin
#define EPD_BUSY_PIN    EPD_BUSY_GPIO_Port, EPD_BUSY_Pin

/**
 * GPIO read and write
**/
#define DEV_Digital_Write(_pin, _value) HAL_GPIO_WritePin(_pin, _value == 0? GPIO_PIN_RESET:GPIO_PIN_SET)
#define DEV_Digital_Read(_pin) HAL_GPIO_ReadPin(_pin)


/**
 * delay x ms
**/
#define DEV_Delay_ms(__xms) HAL_Delay(__xms);

/**
 * SPI RAM
**/
//#define SPIRAM_CS_0		HAL_GPIO_WritePin(SPIRAM_CS_GPIO_Port, SPIRAM_CS_Pin, GPIO_PIN_RESET)
//#define SPIRAM_CS_1		HAL_GPIO_WritePin(SPIRAM_CS_GPIO_Port, SPIRAM_CS_Pin, GPIO_PIN_SET)

/**
 * SD Card
**/
//#define SD_CS_0		HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_RESET)
//#define SD_CS_1		HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_SET)

/**
 * e-Paper GPIO
**/
#define EPD_CS_0		HAL_GPIO_WritePin(EPD_CS_PIN, GPIO_PIN_RESET)
#define EPD_CS_1		HAL_GPIO_WritePin(EPD_CS_PIN, GPIO_PIN_SET)

#define EPD_DC_0		HAL_GPIO_WritePin(EPD_DC_PIN, GPIO_PIN_RESET)
#define EPD_DC_1		HAL_GPIO_WritePin(EPD_DC_PIN, GPIO_PIN_SET)

#define EPD_RST_0		HAL_GPIO_WritePin(EPD_RST_PIN, GPIO_PIN_RESET)
#define EPD_RST_1		HAL_GPIO_WritePin(EPD_RST_PIN, GPIO_PIN_SET)

#define EPD_BUSY_RD		HAL_GPIO_ReadPin(EPD_BUSY_PIN)

UBYTE DEV_Module_Init(void);
void DEV_Module_Exit(void);

void DEV_SPI_WriteByte(UBYTE value);
UBYTE DEV_SPI_ReadByte(void);

void DEV_Delay_us(UWORD xus);


#endif
