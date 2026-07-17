/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_PWL.h
 *        Config:  S32K144_Start.dpa
 *   ECU-Project:  MyECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800257
 *
 *   Description:  Application header file for SW-C <PWL>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PWL_H
# define _RTE_PWL_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_PWL_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_COM_CAN_BD1_St_PDWinMove_u8_Signal (0U)
#  define Rte_InitValue_COM_CAN_PEPS1_S_Command_u8_Signal (0U)
#  define Rte_InitValue_COM_LIN_PassWinSwSt_u8_Signal (0ULL)
#  define Rte_InitValue_Cgf_WinAutoMaxRunTimPrm_u8_Signal (0U)
#  define Rte_InitValue_Cgf_WinEnDelayTimPrm_u8_Signal (0U)
#  define Rte_InitValue_DoorAjar_u8_Signal (0U)
#  define Rte_InitValue_KL_15_IG_u8_Signal (0ULL)
#  define Rte_InitValue_PWL_PassWin_Down_u8_Signal (0U)
#  define Rte_InitValue_PWL_PassWin_Up_u8_Signal (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_COM_CAN_PEPS1_S_Command_u8_Signal Rte_Read_PWL_COM_CAN_PEPS1_S_Command_u8_Signal
#  define Rte_Read_PWL_COM_CAN_PEPS1_S_Command_u8_Signal(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_COM_LIN_PassWinSwSt_u8_Signal Rte_Read_PWL_COM_LIN_PassWinSwSt_u8_Signal
#  define Rte_Read_PWL_COM_LIN_PassWinSwSt_u8_Signal(data) (*(data) = 0ULL, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Cgf_WinAutoMaxRunTimPrm_u8_Signal Rte_Read_PWL_Cgf_WinAutoMaxRunTimPrm_u8_Signal
#  define Rte_Read_PWL_Cgf_WinAutoMaxRunTimPrm_u8_Signal(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Cgf_WinEnDelayTimPrm_u8_Signal Rte_Read_PWL_Cgf_WinEnDelayTimPrm_u8_Signal
#  define Rte_Read_PWL_Cgf_WinEnDelayTimPrm_u8_Signal(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DoorAjar_u8_Signal Rte_Read_PWL_DoorAjar_u8_Signal
#  define Rte_Read_PWL_DoorAjar_u8_Signal(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_KL_15_IG_u8_Signal Rte_Read_PWL_KL_15_IG_u8_Signal
#  define Rte_Read_PWL_KL_15_IG_u8_Signal(data) (*(data) = 0ULL, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_COM_CAN_BD1_St_PDWinMove_u8_Signal Rte_Write_PWL_COM_CAN_BD1_St_PDWinMove_u8_Signal
#  define Rte_Write_PWL_COM_CAN_BD1_St_PDWinMove_u8_Signal(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PWL_PassWin_Down_u8_Signal Rte_Write_PWL_PWL_PassWin_Down_u8_Signal
#  define Rte_Write_PWL_PWL_PassWin_Down_u8_Signal(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PWL_PassWin_Up_u8_Signal Rte_Write_PWL_PWL_PassWin_Up_u8_Signal
#  define Rte_Write_PWL_PWL_PassWin_Up_u8_Signal(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define PWL_START_SEC_CODE
# include "PWL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_PWL_10msRunnable PWL_10msRunnable
#  define RTE_RUNNABLE_PWL_Init PWL_Init
# endif

FUNC(void, PWL_CODE) PWL_10msRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, PWL_CODE) PWL_Init(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define PWL_STOP_SEC_CODE
# include "PWL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PWL_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
