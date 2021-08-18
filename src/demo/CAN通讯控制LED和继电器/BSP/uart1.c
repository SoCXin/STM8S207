#include "pbdata.h"

void UART1_Configuration(void)
{  
    UART1_DeInit();
    //�����ʣ��ֽ�����1��ֹͣλ������żЧ��λ��   ��ͬ��ģʽ��        ������ܺͷ���
    UART1_Init((u32)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1,UART1_PARITY_NO , UART1_SYNCMODE_CLOCK_DISABLE , UART1_MODE_TXRX_ENABLE);
    UART1_ITConfig(UART1_IT_RXNE_OR,ENABLE  );
    UART1_Cmd(ENABLE );
}

void UART1_Send_byte(u8 byte)
{
    UART1_SendData8((unsigned char)byte);
    while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);//��������Ϊ��
}	

//////////////////////////printf//////////////////////////////

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE ////����һ���ַ�Э��
{
/* ��Printf���ݷ������� */
  UART1_SendData8((unsigned char) ch);
  while (!(UART1->SR & UART1_FLAG_TXE));//�������δ��ɣ� //��־λδ��λ����ѭ���ȴ�
  return (ch);

}