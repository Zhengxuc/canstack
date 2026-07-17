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
 *        Config:  G:/matlab/S32K144_SIP/MICROSAR/CBD1800257_D01_S32K1xx/Applications/S32K144_Start_new_IAR/S32K144_Start.dpa
 *     SW-C Type:  PWL
 *  Generated at:  Fri Jun 28 16:10:52 2024
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800257
 *
 *   Description:  Application header file for SW-C <PWL> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PWL_H
# define _RTE_PWL_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_PWL_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_PWL
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_PWL, RTE_CONST, RTE_CONST) Rte_Inst_PWL; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_PWL, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_COM_CAN_BD1_St_PDWinMove_u8_Signal (0U)
# define Rte_InitValue_COM_CAN_PEPS1_S_Command_u8_Signal (0U)
# define Rte_InitValue_COM_LIN_PassWinSwSt_u8_Signal (0ULL)
# define Rte_InitValue_Cgf_WinAutoMaxRunTimPrm_u8_Signal (0U)
# define Rte_InitValue_Cgf_WinEnDelayTimPrm_u8_Signal (0U)
# define Rte_InitValue_DoorAjar_u8_Signal (0U)
# define Rte_InitValue_KL_15_IG_u8_Signal (0ULL)
# define Rte_InitValue_PWL_PassWin_Down_u8_Signal (0U)
# define Rte_InitValue_PWL_PassWin_Up_u8_Signal (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PWL_COM_CAN_PEPS1_S_Command_u8_Signal(P2VAR(uint8, AUTOMATIC, RTE_PWL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PWL_COM_LIN_PassWinSwSt_u8_Signal(P2VAR(uint64, AUTOMATIC, RTE_PWL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PWL_Cgf_WinAutoMaxRunTimPrm_u8_Signal(P2VAR(uint8, AUTOMATIC, RTE_PWL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PWL_Cgf_WinEnDelayTimPrm_u8_Signal(P2VAR(uint8, AUTOMATIC, RTE_PWL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PWL_DoorAjar_u8_Signal(P2VAR(uint8, AUTOMATIC, RTE_PWL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PWL_KL_15_IG_u8_Signal(P2VAR(uint64, AUTOMATIC, RTE_PWL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PWL_COM_CAN_BD1_St_PDWinMove_u8_Signal(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PWL_PWL_PassWin_Down_u8_Signal(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PWL_PWL_PassWin_Up_u8_Signal(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_COM_CAN_PEPS1_S_Command_u8_Signal Rte_Read_PWL_COM_CAN_PEPS1_S_Command_u8_Signal
# define Rte_Read_COM_LIN_PassWinSwSt_u8_Signal Rte_Read_PWL_COM_LIN_PassWinSwSt_u8_Signal
# define Rte_Read_Cgf_WinAutoMaxRunTimPrm_u8_Signal Rte_Read_PWL_Cgf_WinAutoMaxRunTimPrm_u8_Signal
# define Rte_Read_Cgf_WinEnDelayTimPrm_u8_Signal Rte_Read_PWL_Cgf_WinEnDelayTimPrm_u8_Signal
# define Rte_Read_DoorAjar_u8_Signal Rte_Read_PWL_DoorAjar_u8_Signal
# define Rte_Read_KL_15_IG_u8_Signal Rte_Read_PWL_KL_15_IG_u8_Signal


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_COM_CAN_BD1_St_PDWinMove_u8_Signal Rte_Write_PWL_COM_CAN_BD1_St_PDWinMove_u8_Signal
# define Rte_Write_PWL_PassWin_Down_u8_Signal Rte_Write_PWL_PWL_PassWin_Down_u8_Signal
# define Rte_Write_PWL_PassWin_Up_u8_Signal Rte_Write_PWL_PWL_PassWin_Up_u8_Signal




# define PWL_START_SEC_CODE
# include "PWL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PWL_10msRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_COM_CAN_PEPS1_S_Command_u8_Signal(uint8 *data)
 *   Std_ReturnType Rte_Read_COM_LIN_PassWinSwSt_u8_Signal(uint64 *data)
 *   Std_ReturnType Rte_Read_Cgf_WinAutoMaxRunTimPrm_u8_Signal(uint8 *data)
 *   Std_ReturnType Rte_Read_Cgf_WinEnDelayTimPrm_u8_Signal(uint8 *data)
 *   Std_ReturnType Rte_Read_DoorAjar_u8_Signal(uint8 *data)
 *   Std_ReturnType Rte_Read_KL_15_IG_u8_Signal(uint64 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_COM_CAN_BD1_St_PDWinMove_u8_Signal(uint8 data)
 *   Std_ReturnType Rte_Write_PWL_PassWin_Down_u8_Signal(uint8 data)
 *   Std_ReturnType Rte_Write_PWL_PassWin_Up_u8_Signal(uint8 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PWL_10msRunnable PWL_10msRunnable
FUNC(void, PWL_CODE) PWL_10msRunnable(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PWL_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PWL_Init PWL_Init
FUNC(void, PWL_CODE) PWL_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define PWL_STOP_SEC_CODE
# include "PWL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PWL_H */
