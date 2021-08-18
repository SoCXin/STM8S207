#ifndef __LED_H
#define __LED_H
#include "stm8s.h"

#define LED1_PIN        GPIO_PIN_0
#define LED2_PIN        GPIO_PIN_3 
#define LED3_PIN        GPIO_PIN_6 
#define LED1_PORT       GPIOE
#define LED2_PORT       GPIOA
#define LED3_PORT       GPIOA

#define LED1_L GPIO_WriteLow(LED1_PORT,LED1_PIN);
#define LED1_H GPIO_WriteHigh(LED1_PORT,LED1_PIN);
#define LED1_R GPIO_WriteReverse(LED1_PORT,LED1_PIN);

#define LED2_L GPIO_WriteLow(LED2_PORT,LED2_PIN);
#define LED2_H GPIO_WriteHigh(LED2_PORT,LED2_PIN);
#define LED2_R GPIO_WriteReverse(LED2_PORT,LED2_PIN);

#define LED3_L GPIO_WriteLow(LED3_PORT,LED3_PIN);
#define LED3_H GPIO_WriteHigh(LED3_PORT,LED3_PIN);
#define LED3_R GPIO_WriteReverse(LED3_PORT,LED3_PIN);

void LED_Init(void);
void LED_Reverse(void);

#endif

