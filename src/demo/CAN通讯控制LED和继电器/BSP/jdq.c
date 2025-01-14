#include "pbdata.h"
/**********************************************************************************************************
*   函 数 名: LED_Init
*   功能说明: LED的GPIO管脚初始化
*   形    参：无
*   返 回 值: 无
**********************************************************************************************************/
void JDQ_Init(void)
{
   GPIO_Init(JDQ_PORT,JDQ_PIN,GPIO_MODE_OUT_PP_HIGH_FAST );//定义LED的管脚的模式
}

/**********************************************************************************************************
*   函 数 名: LED_Demo1
*   功能说明: 闪烁例程，间隔时间为1秒。
*   形    参：无
*   返 回 值: 无
**********************************************************************************************************/
void JDQ_Demo1(void)
{
    JDQ_L; 
    delay_ms(1000);
    
    JDQ_H;
    delay_ms(1000);
}