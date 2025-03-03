#include "pbdata.h"

void CAN_Config(void)  //自定义CAN初始化库函数，初始化CAN过滤器，
{	
    /* Filter Parameters */
    CAN_FilterNumber_TypeDef CAN_FilterNumber;   //CAN过滤器编号
    FunctionalState CAN_FilterActivation;        //CAN功能状态
    CAN_FilterMode_TypeDef CAN_FilterMode;       //CAN过滤模式    
    CAN_FilterScale_TypeDef CAN_FilterScale;     //过滤器位宽设置
    u8 CAN_FilterID1;   //CAN ID1过滤器 
    u8 CAN_FilterID2;   //CAN ID2过滤器
    u8 CAN_FilterID3;   //CAN ID3过滤器
    u8 CAN_FilterID4;   //CAN ID4过滤器
    u8 CAN_FilterIDMask1;   //掩码1   
    u8 CAN_FilterIDMask2;   //掩码2
    u8 CAN_FilterIDMask3;   //掩码3
    u8 CAN_FilterIDMask4;   //掩码4
    
    /* Init Parameters*/
    CAN_MasterCtrl_TypeDef CAN_MasterCtrl;  //时间触发模式
    CAN_Mode_TypeDef CAN_Mode;     //模式
    CAN_SynJumpWidth_TypeDef CAN_SynJumpWidth;   //重新同步跳跃宽度
    CAN_BitSeg1_TypeDef CAN_BitSeg1;  //时间段1占用时间单元
    CAN_BitSeg2_TypeDef CAN_BitSeg2;  //时间段2占用时间单元 
    u8 CAN_Prescaler;	//时间源（fMaster或者外部振荡器）
    
    /* CAN register init */
    CAN_DeInit();
    
    /* CAN  init */
    CAN_MasterCtrl=CAN_MasterCtrl_AllDisabled;//关闭所有主控制选项
    CAN_Mode = CAN_Mode_Normal;  //正常模式
    CAN_SynJumpWidth = CAN_SynJumpWidth_1TimeQuantum;//1个时间量
        
    //500K
    CAN_BitSeg1 = CAN_BitSeg1_8TimeQuantum;//时间段1为8个时间单位
    CAN_BitSeg2 = CAN_BitSeg2_7TimeQuantum;//时间段2为7个时间单位
    CAN_Prescaler = 2;//(pclk1/((1+8+7)*2)) = 系统时钟/16/2= 设定了一个时间单位的长度2
    
    CAN_Init(CAN_MasterCtrl,CAN_Mode, CAN_SynJumpWidth, CAN_BitSeg1,CAN_BitSeg2, CAN_Prescaler);  
        
    /* CAN filter init */
    CAN_FilterNumber = CAN_FilterNumber_0;  //过滤器编号5 
    CAN_FilterActivation = ENABLE;   //状态（允许）
    CAN_FilterMode = CAN_FilterMode_IdMask;  //过滤模式（ID/掩码）
    CAN_FilterScale = CAN_FilterScale_32Bit;  //32位过滤器宽度
    CAN_FilterID1=0;     //ID1=0
    CAN_FilterID2=0;     //ID2=0
    CAN_FilterID3=0;     //ID3=0
    CAN_FilterID4=0;
    CAN_FilterIDMask1=0;
    CAN_FilterIDMask2=0;
    CAN_FilterIDMask3=0;
    CAN_FilterIDMask4=0;  
    CAN_FilterInit(CAN_FilterNumber, CAN_FilterActivation, CAN_FilterMode, CAN_FilterScale,CAN_FilterID1, CAN_FilterID2, CAN_FilterID3, CAN_FilterID4,CAN_FilterIDMask1, CAN_FilterIDMask2, CAN_FilterIDMask3, CAN_FilterIDMask4);	
    CAN_ITConfig(CAN_IT_FMP, ENABLE);    //CAN过滤器总中断允许
}

void CAN_Recv_Control(void)     //CAN控制   recv函数返回值说明
{
    u8 k,dlc;
    u8 CAN_Data[8];
    
    CAN_Receive();      
    dlc = CAN_GetReceivedDLC(); //获取接收消息的数据长度
      
    for (k=0; k < dlc; k++) 
    {
        CAN_Data[k] = CAN_GetReceivedData(k);
    }
    
    if(CAN_Data[0]==0x01) {LED1_L;}    //如果数组中的第一个字节是1，LED1控制端拉低
    else {if(CAN_Data[0]==0x02) LED1_H;}   //如果数组中的第一个字节是2，LED1控制端拉高
    
    if(CAN_Data[1]==0x01) {LED2_L;}   //如果数组中的第二个字节是1，LED1控制端拉低
    else {if(CAN_Data[1]==0x02) LED2_H;}   //如果数组中的第二个字节是2，LED1控制端拉高
    
    if(CAN_Data[2]==0x01) {LED3_L;}
    else {if(CAN_Data[2]==0x02) LED3_H;}
    
    if(CAN_Data[3]==0x01) {JDQ_L;}
    else {if(CAN_Data[3]==0x02) JDQ_H;}
}
