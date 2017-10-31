/*******************************************************************************
* File Name: MainClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_MainClock_H)
#define CY_CLOCK_MainClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void MainClock_Start(void) ;
void MainClock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void MainClock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void MainClock_StandbyPower(uint8 state) ;
void MainClock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 MainClock_GetDividerRegister(void) ;
void MainClock_SetModeRegister(uint8 modeBitMask) ;
void MainClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 MainClock_GetModeRegister(void) ;
void MainClock_SetSourceRegister(uint8 clkSource) ;
uint8 MainClock_GetSourceRegister(void) ;
#if defined(MainClock__CFG3)
void MainClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 MainClock_GetPhaseRegister(void) ;
#endif /* defined(MainClock__CFG3) */

#define MainClock_Enable()                       MainClock_Start()
#define MainClock_Disable()                      MainClock_Stop()
#define MainClock_SetDivider(clkDivider)         MainClock_SetDividerRegister(clkDivider, 1u)
#define MainClock_SetDividerValue(clkDivider)    MainClock_SetDividerRegister((clkDivider) - 1u, 1u)
#define MainClock_SetMode(clkMode)               MainClock_SetModeRegister(clkMode)
#define MainClock_SetSource(clkSource)           MainClock_SetSourceRegister(clkSource)
#if defined(MainClock__CFG3)
#define MainClock_SetPhase(clkPhase)             MainClock_SetPhaseRegister(clkPhase)
#define MainClock_SetPhaseValue(clkPhase)        MainClock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(MainClock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define MainClock_CLKEN              (* (reg8 *) MainClock__PM_ACT_CFG)
#define MainClock_CLKEN_PTR          ((reg8 *) MainClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define MainClock_CLKSTBY            (* (reg8 *) MainClock__PM_STBY_CFG)
#define MainClock_CLKSTBY_PTR        ((reg8 *) MainClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define MainClock_DIV_LSB            (* (reg8 *) MainClock__CFG0)
#define MainClock_DIV_LSB_PTR        ((reg8 *) MainClock__CFG0)
#define MainClock_DIV_PTR            ((reg16 *) MainClock__CFG0)

/* Clock MSB divider configuration register. */
#define MainClock_DIV_MSB            (* (reg8 *) MainClock__CFG1)
#define MainClock_DIV_MSB_PTR        ((reg8 *) MainClock__CFG1)

/* Mode and source configuration register */
#define MainClock_MOD_SRC            (* (reg8 *) MainClock__CFG2)
#define MainClock_MOD_SRC_PTR        ((reg8 *) MainClock__CFG2)

#if defined(MainClock__CFG3)
/* Analog clock phase configuration register */
#define MainClock_PHASE              (* (reg8 *) MainClock__CFG3)
#define MainClock_PHASE_PTR          ((reg8 *) MainClock__CFG3)
#endif /* defined(MainClock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define MainClock_CLKEN_MASK         MainClock__PM_ACT_MSK
#define MainClock_CLKSTBY_MASK       MainClock__PM_STBY_MSK

/* CFG2 field masks */
#define MainClock_SRC_SEL_MSK        MainClock__CFG2_SRC_SEL_MASK
#define MainClock_MODE_MASK          (~(MainClock_SRC_SEL_MSK))

#if defined(MainClock__CFG3)
/* CFG3 phase mask */
#define MainClock_PHASE_MASK         MainClock__CFG3_PHASE_DLY_MASK
#endif /* defined(MainClock__CFG3) */

#endif /* CY_CLOCK_MainClock_H */


/* [] END OF FILE */
