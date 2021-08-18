#include "pbdata.h"

void CAN_Config(void)  //�Զ���CAN��ʼ���⺯������ʼ��CAN��������
{	
    /* Filter Parameters */
    CAN_FilterNumber_TypeDef CAN_FilterNumber;   //CAN���������
    FunctionalState CAN_FilterActivation;        //CAN����״̬
    CAN_FilterMode_TypeDef CAN_FilterMode;       //CAN����ģʽ    
    CAN_FilterScale_TypeDef CAN_FilterScale;     //������λ������
    u8 CAN_FilterID1;   //CAN ID1������ 
    u8 CAN_FilterID2;   //CAN ID2������
    u8 CAN_FilterID3;   //CAN ID3������
    u8 CAN_FilterID4;   //CAN ID4������
    u8 CAN_FilterIDMask1;   //����1   
    u8 CAN_FilterIDMask2;   //����2
    u8 CAN_FilterIDMask3;   //����3
    u8 CAN_FilterIDMask4;   //����4
    
    /* Init Parameters*/
    CAN_MasterCtrl_TypeDef CAN_MasterCtrl;  //ʱ�䴥��ģʽ
    CAN_Mode_TypeDef CAN_Mode;     //ģʽ
    CAN_SynJumpWidth_TypeDef CAN_SynJumpWidth;   //����ͬ����Ծ���
    CAN_BitSeg1_TypeDef CAN_BitSeg1;  //ʱ���1ռ��ʱ�䵥Ԫ
    CAN_BitSeg2_TypeDef CAN_BitSeg2;  //ʱ���2ռ��ʱ�䵥Ԫ 
    u8 CAN_Prescaler;	//ʱ��Դ��fMaster�����ⲿ������
    
    /* CAN register init */
    CAN_DeInit();
    
    /* CAN  init */
    CAN_MasterCtrl=CAN_MasterCtrl_AllDisabled;//�ر�����������ѡ��
    CAN_Mode = CAN_Mode_Normal;  //����ģʽ
    CAN_SynJumpWidth = CAN_SynJumpWidth_1TimeQuantum;//1��ʱ����
        
    //500K
    CAN_BitSeg1 = CAN_BitSeg1_8TimeQuantum;//ʱ���1Ϊ8��ʱ�䵥λ
    CAN_BitSeg2 = CAN_BitSeg2_7TimeQuantum;//ʱ���2Ϊ7��ʱ�䵥λ
    CAN_Prescaler = 2;//(pclk1/((1+8+7)*2)) = ϵͳʱ��/16/2= �趨��һ��ʱ�䵥λ�ĳ���2
    
    CAN_Init(CAN_MasterCtrl,CAN_Mode, CAN_SynJumpWidth, CAN_BitSeg1,CAN_BitSeg2, CAN_Prescaler);  
        
    /* CAN filter init */
    CAN_FilterNumber = CAN_FilterNumber_0;  //���������5 
    CAN_FilterActivation = ENABLE;   //״̬������
    CAN_FilterMode = CAN_FilterMode_IdMask;  //����ģʽ��ID/���룩
    CAN_FilterScale = CAN_FilterScale_32Bit;  //32λ���������
    CAN_FilterID1=0;     //ID1=0
    CAN_FilterID2=0;     //ID2=0
    CAN_FilterID3=0;     //ID3=0
    CAN_FilterID4=0;
    CAN_FilterIDMask1=0;
    CAN_FilterIDMask2=0;
    CAN_FilterIDMask3=0;
    CAN_FilterIDMask4=0;  
    CAN_FilterInit(CAN_FilterNumber, CAN_FilterActivation, CAN_FilterMode, CAN_FilterScale,CAN_FilterID1, CAN_FilterID2, CAN_FilterID3, CAN_FilterID4,CAN_FilterIDMask1, CAN_FilterIDMask2, CAN_FilterIDMask3, CAN_FilterIDMask4);	
    CAN_ITConfig(CAN_IT_FMP, ENABLE);    //CAN���������ж�����
}

void CAN_Recv_Control(void)     //CAN����   recv��������ֵ˵��
{
    u8 k,dlc;
    u8 CAN_Data[8];
    
    CAN_Receive();      
    dlc = CAN_GetReceivedDLC(); //��ȡ������Ϣ�����ݳ���
      
    for (k=0; k < dlc; k++) 
    {
        CAN_Data[k] = CAN_GetReceivedData(k);
    }
    
    if(CAN_Data[0]==0x01) {LED1_L;}    //��������еĵ�һ���ֽ���1��LED1���ƶ�����
    else {if(CAN_Data[0]==0x02) LED1_H;}   //��������еĵ�һ���ֽ���2��LED1���ƶ�����
    
    if(CAN_Data[1]==0x01) {LED2_L;}   //��������еĵڶ����ֽ���1��LED1���ƶ�����
    else {if(CAN_Data[1]==0x02) LED2_H;}   //��������еĵڶ����ֽ���2��LED1���ƶ�����
    
    if(CAN_Data[2]==0x01) {LED3_L;}
    else {if(CAN_Data[2]==0x02) LED3_H;}
    
    if(CAN_Data[3]==0x01) {JDQ_L;}
    else {if(CAN_Data[3]==0x02) JDQ_H;}
}
