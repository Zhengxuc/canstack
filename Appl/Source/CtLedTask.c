/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtLedTask.c
 *        Config:  D:/PANDORA/CarCode/AUTOSAR_TOOLs/S32K144_SIP/MICROSAR/CBD1800257_D01_S32K1xx/Applications/S32K144_Start_new_IAR/S32K144_Start.dpa
 *     SW-C Type:  CtLedTask
 *  Generated at:  Mon Jul  6 19:00:48 2026
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800257
 *
 *   Description:  C-Code implementation template for SW-C <CtLedTask>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * ComM_ModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_CtLedTask.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Dio.h"
//引入com头文件

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ComM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 *   COMM_NO_COMMUNICATION (0U)
 *   COMM_SILENT_COMMUNICATION (1U)
 *   COMM_FULL_COMMUNICATION (2U)
 *
 *********************************************************************************************************************/


#define CtLedTask_START_SEC_CODE
#include "CtLedTask_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#include "Com_Cfg.h"
#include "Appl_Cbk.h"
#include "Pwm.h"
/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtLedTask_InitRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_UR_CN_CAN00_06ecbb07_GetCurrentComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_UR_CN_CAN00_06ecbb07_GetMaxComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_UR_CN_CAN00_06ecbb07_GetRequestedComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_UR_CN_CAN00_06ecbb07_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CtLedTask_InitRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtLedTask_CODE) CtLedTask_InitRunnable(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtLedTask_InitRunnable
 *********************************************************************************************************************/

  static uint16 u16ResultBuffer[1] = {0u};
  Adc_SetupResultBuffer(0,u16ResultBuffer);//设置buffer
  Adc_EnableGroupNotification(0);//使能
  Rte_Call_UR_CN_CAN00_06ecbb07_RequestComMode(COMM_FULL_COMMUNICATION);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LedRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 300ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RearLedftWindow_Position_u8_Signal(uint8 *data)
 *   Std_ReturnType Rte_Read_RearRightWindow_Position_u8_Signal(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_FrontInterLight_bool_Signal(boolean data)
 *   Std_ReturnType Rte_Write_LampCnt_u8_Singal(uint8 data)
 *   Std_ReturnType Rte_Write_RearInterLight_Bool_Signal(boolean data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LedRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtLedTask_CODE) LedRunnable(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LedRunnable
 *********************************************************************************************************************/

  //现在的runnable时300ms周期调用的
static unsigned char  LedState=0;
static int  LedCnt=0;


LedCnt++;
LedState ^= 0x01;

//user code 
//static uint8 RearLeftWindowPosition = 0;
//static uint8 RearRightWindowPosition = 0 ;
//static unsigned char  InterLampState = 0;

//com发送属性练习
static unsigned char RearLeftWindow = 99;
static unsigned char RearRightWindow = 255 ;
static unsigned char ComSendCnt  = 0 ;
static boolean RearLeftWindow_value  = 0;


// if(ComSendCnt == 10 ){
//    Com_SendSignal(ComConf_ComSignal_RearLeft_Window, (&RearLeftWindow));
//    ComSendCnt  = 0;
// }else{
//   ComSendCnt ++ ;
// }

 Dio_WriteChannel(112,LedState);//写电平 led闪烁
 //user code
// Rte_Write_CtLedTask_LampCnt_u8_Singal(LedCnt);
// Rte_Write_CtLedTask_RearInterLight_Bool_Signal(1);
// 
// Rte_Read_RearLedftWindow_Position_u8_Signal(&RearLeftWindowPosition);
// Rte_Read_RearRightWindow_Position_u8_Signal(&RearRightWindowPosition);
// 
// if(0x65 == RearLeftWindowPosition ){
//   Rte_Write_LampCnt_u8_Singal(RearLeftWindowPosition);
//   InterLampState =1;
// }else if (0x37 == RearRightWindowPosition){
//   Rte_Write_LampCnt_u8_Singal(RearRightWindowPosition);
//   InterLampState = 1;
// }else{
//   InterLampState = 0;
//   
// }
// Rte_Write_FrontInterLight_bool_Signal(InterLampState);

 //com属性练习
    // RearLeftWindow_value ++; 
    // Com_SendSignal(ComConf_ComSignal_RearLeft_Window, &RearLeftWindow_value);//300ms触发一次++ 信号值改变 触发发送
    // Com_SendSignal(ComConf_ComSignal_RearRight_Window, (&RearRightWindow));//这里是每2s发一次 不受 runnable的影响
  //signal_group练习 多个信号打包一起发送
    // Com_SendSignal(ComConf_ComGroupSignal_MyECUGroupSignal, &RearLeftWindow);//
    // Com_SendSignal(ComConf_ComGroupSignal_MyECUGroupSignal_1, (&RearRightWindow));//
    // Com_SendSignalGroup(ComConf_ComSignalGroup_MyECUSignalGroup);//比send signal多一步  ,这里
 
 //MCAL:adc练习
//   static uint16 Adc_Data = 0;
//   static uint16 retValue = 0;
//   Adc_StartGroupConversion(0);
//   retValue = Adc_ReadGroup(0,&Adc_Data);
//   Adc_Data = Adc_Data/20; //这里要除一下是因为要能放在pdu里面 因为adc_data是16位的 send signal只能装下8位 (好像是 待确认)
//   Com_SendSignal(ComConf_ComSignal_sig_LampCnt_omsg_MyECU_Lamp_oCAN00_f37e68ea_Tx,(&Adc_Data));
  
   //MCal:adc带中断的练习
  Adc_StartGroupConversion(0);//开启这句话下面的adc回调函数才能起作用
  
  //Mcal ：PWM
 
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
//CanStack 超时回调练习
static uint8 u8CbkData = 0;
FUNC (void ,COM_APPL_CODE) ComCbxToutRx_RearLeftWindowPosition (void) {
  u8CbkData = 1;
  Com_SendSignal(ComConf_ComSignal_RearLeft_Window, &u8CbkData);
}

//CanStack: 回调函数
FUNC (void ,COM_APPL_CODE)  ComCbxRx_RearLeftWindowPosition (void){
  
  u8CbkData = 0 ;
  Com_SendSignal(ComConf_ComSignal_RearLeft_Window, &u8CbkData);
}

////MCAL:ADC 回调函数
//void AdcGroup0Notification(void)
//{
//     static uint16 Adc_Data = 0;
//     static uint16 retValue = 0;
//     retValue = Adc_ReadGroup(0,&Adc_Data);
//     Adc_Data = Adc_Data/20;
// 
//     Com_SendSignal(ComConf_ComSignal_sig_LampCnt_omsg_MyECU_Lamp_oCAN00_f37e68ea_Tx,(&Adc_Data));
//
//}

//MCAL:ADC 回调函数 与pwm练习
static Pwm_OutputStateType ePwmOutStsRet = 0u;
void AdcGroup0Notification(void)
{
     static uint16 Adc_Data = 0;
     static uint16 retValue = 0;
     uint16 u16AdcToPwmData =0u;
     uint16 u16AdcCH2_Data = 0u;
     retValue = Adc_ReadGroup(0,&u16AdcCH2_Data);
     u16AdcToPwmData = u16AdcCH2_Data*8;
       
     Pwm_SetDutyCycle(0,u16AdcToPwmData);//设置占空比
     ePwmOutStsRet = Pwm_GetOutputState(0);//返回状态
     Com_SendSignal(ComConf_ComSignal_sig_LampCnt_omsg_MyECU_Lamp_oCAN00_f37e68ea_Tx,(&u16AdcToPwmData));
     
     
}


#define CtLedTask_STOP_SEC_CODE
#include "CtLedTask_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
