/*
 * leds.h
 *
 *  Created on: Aug 30, 2020
 *      Author: Mi PC
 */

#ifndef INC_LEDS_H_
#define INC_LEDS_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"

//MACROS for the pins to the LEDS and PushButton

#define GreenLed_PIN          	    GPIO_PIN_5
#define GreenLed_GPIO_PORT   		GPIOC

#define OrangeLed_PIN           	GPIO_PIN_8
#define OrangeLed_GPIO_PORT     	GPIOC

#define PushButton_PIN            	GPIO_PIN_9
#define PushButton_GPIO_PORT        GPIOC

//Calling Functions

void vInit_Leds(void);
void vLedFunction(void);

#endif /* INC_LEDS_H_ */
