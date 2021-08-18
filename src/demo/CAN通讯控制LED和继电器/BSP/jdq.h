#ifndef __JDQ_H
#define __JDQ_H
#include "stm8s.h"

#define JDQ_PIN        GPIO_PIN_7
#define JDQ_PORT       GPIOG

#define JDQ_L GPIO_WriteLow(JDQ_PORT,JDQ_PIN)
#define JDQ_H GPIO_WriteHigh(JDQ_PORT,JDQ_PIN)
#define JDQ_R GPIO_WriteReverse(JDQ_PORT,JDQ_PIN)

void JDQ_Init(void);
void JDQ_Demo1(void);

#endif

