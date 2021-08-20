/*
 * motor.h
 *
 *  Created on: Sep 1, 2020
 *      Author: HECTOR ZUÑIGA
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"

//MACROS FOR THE H BRIDGE AND PUSHBUTTON

#define Enable_PIN           GPIO_PIN_9
#define Enable_GPIO_PORT     GPIOB

#define Input4_PIN            GPIO_PIN_6
#define Input4_GPIO_PORT      GPIOC

#define Input3_PIN           GPIO_PIN_13
#define Input3_GPIO_PORT     GPIOB

#define PushB_PIN            GPIO_PIN_1
#define PushB_GPIO_PORT      GPIOB

//SET PINS ON AND OFF

#define  POT_OFF		  		 HAL_GPIO_WritePin(POT_GPIO_PORT,    POT_PIN, 	   GPIO_PIN_RESET)
#define  Enable_OFF		  		 HAL_GPIO_WritePin(Enable_GPIO_PORT, Enable_PIN,   GPIO_PIN_RESET)
#define  Input4_OFF          	 HAL_GPIO_WritePin(Input4_GPIO_PORT ,Input4_PIN,   GPIO_PIN_RESET)
#define  Input3_OFF      	  	 HAL_GPIO_WritePin(Input3_GPIO_PORT, Input3_PIN,   GPIO_PIN_RESET)
#define  PushB_OFF      	  	 HAL_GPIO_WritePin(PushB_GPIO_PORT,  PushB_PIN,    GPIO_PIN_RESET)

#define  POT_ON		      		 HAL_GPIO_WritePin(POT_GPIO_PORT,     POT_PIN, 	     GPIO_PIN_SET)
#define  Enable_ON		   		 HAL_GPIO_WritePin(Enable_GPIO_PORT,  Enable_PIN,    GPIO_PIN_SET)
#define  Input4_ON           	 HAL_GPIO_WritePin(Input4_GPIO_PORT , Input4_PIN, 	 GPIO_PIN_SET)
#define  Input3_ON      	  	 HAL_GPIO_WritePin(Input3_GPIO_PORT,  Input3_PIN,    GPIO_PIN_SET)
#define  PushB_ON      	  		 HAL_GPIO_WritePin(PushB_GPIO_PORT,   PushB_PIN, 	 GPIO_PIN_SET)

//FUNCTIONS

void vMotor_Init(void);
void vDirection(void);
void vPot(void);



#endif /* INC_MOTOR_H_ */
