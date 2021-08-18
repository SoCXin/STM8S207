#include "pbdata.h"

void UART1_Configuration(void)
{  
    UART1_DeInit();
    //波特率，字节数，1个停止位，无奇偶效验位，   非同步模式，        允许接受和发送
    UART1_Init((u32)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1,UART1_PARITY_NO , UART1_SYNCMODE_CLOCK_DISABLE , UART1_MODE_TXRX_ENABLE);
    UART1_ITConfig(UART1_IT_RXNE_OR,ENABLE  );
    UART1_Cmd(ENABLE );
}

void UART1_Send_byte(u8 byte)
{
    UART1_SendData8((unsigned char)byte);
    while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);//发送数据为空
}	

//////////////////////////printf//////////////////////////////

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE ////发送一个字符协议
{
/* 将Printf内容发往串口 */
  UART1_SendData8((unsigned char) ch);
  while (!(UART1->SR & UART1_FLAG_TXE));//如果发送未完成， //标志位未置位，则循环等待
  return (ch);

}