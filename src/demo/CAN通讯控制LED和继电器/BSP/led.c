#include "pbdata.h"
/**********************************************************************************************************
*   函 数 名: LED_Init
*   功能说明: LED的GPIO管脚初始化
*   形    参：无
*   返 回 值: 无
**********************************************************************************************************/
void LED_Init(void)
{
    GPIO_Init(LED1_PORT,LED1_PIN,GPIO_MODE_OUT_OD_HIZ_SLOW );//慢速开漏输出高阻态
    GPIO_Init(LED2_PORT,LED2_PIN,GPIO_MODE_OUT_OD_HIZ_SLOW );//慢速开漏输出高阻态
    GPIO_Init(LED3_PORT,LED3_PIN,GPIO_MODE_OUT_OD_HIZ_SLOW );//慢速开漏输出高阻态
}

/**********************************************************************************************************
*   函 数 名: LED_Demo1
*   功能说明: 闪烁例程，间隔时间为1秒。
*   形    参：无
*   返 回 值: 无
**********************************************************************************************************/
void LED_Reverse(void)
{ 
    LED1_R;
    LED2_R;
    LED3_R;
    delay_ms(1000);
}