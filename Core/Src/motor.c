/*
 * motor.c
 *
 *  Created on: Sep 1, 2020
 *      Author: HECTOR ZUÑIGA
 */

#include "motor.h"
#include "leds.h"
#include "stdbool.h"

static bool EstButton = false;

//THE FUNCTION TAHT INIT THE H BRIDGE AND PUSHBUTTONS PINS

void vMotor_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	//__HAL_RCC_GPIOH_CLK_ENABLE();

	GPIO_InitStruct.Pin 	 = Enable_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(Enable_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = Input4_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(Input4_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = Input3_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(Input3_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = PushB_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull 	 = GPIO_PULLDOWN;
	HAL_GPIO_Init(PushB_GPIO_PORT, &GPIO_InitStruct);

	Enable_OFF; Input4_OFF; Input3_OFF;

}

//THIS FUNCTION IS USED TO PUT THE DIRECTION OF THE MOTOR

void vDirection(void)
{
	uint8_t u8PushState = HAL_GPIO_ReadPin(PushB_GPIO_PORT, PushB_PIN);

	if((u8PushState == 0) && (EstButton == 1))
	{
		EstButton = false;
	}
	else if((u8PushState == 1) && (EstButton == 0))  //TURN MOTOR TO THE RIGHT
	{
		Input3_ON; 					 //input 3
		Input4_OFF;					 //input 4
		Enable_ON;  				 //enable
		EstButton = true;
	}
	else if((u8PushState == 1) && (HAL_GPIO_ReadPin(Input3_GPIO_PORT, Input3_PIN)) == 1) //TURN THE MOTOR TO THE LEFT
	{
		Input3_OFF;
		Input4_ON;
		Enable_ON;
	}
}
