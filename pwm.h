/*
 * pwm.h
 *
 *  Created on: Sep 4, 2020
 *      Author: HECTOR ZUÑIGA
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_


#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"

//DEFINE MACROS TO PINES ACCORDING TO THE PUSHBUTTONS

#define PushButton1_PIN            GPIO_PIN_14
#define PushButton1_GPIO_PORT      GPIOB

#define PushButton2_PIN            GPIO_PIN_15
#define PushButton2_GPIO_PORT      GPIOB

//FUNCTIONS ON .C

void vPwm_Init (void);
void vDecreaseAndCreaseVel (void);



#endif /* INC_PWM_H_ */
