#ifndef __PBDATA_H
#define __PBDATA_H
#include "stm8s.h"
#include <stdio.h>
//#include <string.h>

#include "can.h"   //声明CAN头文件
#include "led.h"   //声明LED头文件
#include "jdq.h"   //声明继电器头文件

void delay_us(u16 nCount);  //微秒延时程序
void delay_ms(u16 nCount);
#endif

