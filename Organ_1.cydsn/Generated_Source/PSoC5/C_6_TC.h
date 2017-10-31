/*******************************************************************************
* File Name: C_6_TC.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_C_6_TC_H) /* Pins C_6_TC_H */
#define CY_PINS_C_6_TC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "C_6_TC_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 C_6_TC__PORT == 15 && ((C_6_TC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    C_6_TC_Write(uint8 value);
void    C_6_TC_SetDriveMode(uint8 mode);
uint8   C_6_TC_ReadDataReg(void);
uint8   C_6_TC_Read(void);
void    C_6_TC_SetInterruptMode(uint16 position, uint16 mode);
uint8   C_6_TC_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the C_6_TC_SetDriveMode() function.
     *  @{
     */
        #define C_6_TC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define C_6_TC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define C_6_TC_DM_RES_UP          PIN_DM_RES_UP
        #define C_6_TC_DM_RES_DWN         PIN_DM_RES_DWN
        #define C_6_TC_DM_OD_LO           PIN_DM_OD_LO
        #define C_6_TC_DM_OD_HI           PIN_DM_OD_HI
        #define C_6_TC_DM_STRONG          PIN_DM_STRONG
        #define C_6_TC_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define C_6_TC_MASK               C_6_TC__MASK
#define C_6_TC_SHIFT              C_6_TC__SHIFT
#define C_6_TC_WIDTH              1u

/* Interrupt constants */
#if defined(C_6_TC__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in C_6_TC_SetInterruptMode() function.
     *  @{
     */
        #define C_6_TC_INTR_NONE      (uint16)(0x0000u)
        #define C_6_TC_INTR_RISING    (uint16)(0x0001u)
        #define C_6_TC_INTR_FALLING   (uint16)(0x0002u)
        #define C_6_TC_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define C_6_TC_INTR_MASK      (0x01u) 
#endif /* (C_6_TC__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define C_6_TC_PS                     (* (reg8 *) C_6_TC__PS)
/* Data Register */
#define C_6_TC_DR                     (* (reg8 *) C_6_TC__DR)
/* Port Number */
#define C_6_TC_PRT_NUM                (* (reg8 *) C_6_TC__PRT) 
/* Connect to Analog Globals */                                                  
#define C_6_TC_AG                     (* (reg8 *) C_6_TC__AG)                       
/* Analog MUX bux enable */
#define C_6_TC_AMUX                   (* (reg8 *) C_6_TC__AMUX) 
/* Bidirectional Enable */                                                        
#define C_6_TC_BIE                    (* (reg8 *) C_6_TC__BIE)
/* Bit-mask for Aliased Register Access */
#define C_6_TC_BIT_MASK               (* (reg8 *) C_6_TC__BIT_MASK)
/* Bypass Enable */
#define C_6_TC_BYP                    (* (reg8 *) C_6_TC__BYP)
/* Port wide control signals */                                                   
#define C_6_TC_CTL                    (* (reg8 *) C_6_TC__CTL)
/* Drive Modes */
#define C_6_TC_DM0                    (* (reg8 *) C_6_TC__DM0) 
#define C_6_TC_DM1                    (* (reg8 *) C_6_TC__DM1)
#define C_6_TC_DM2                    (* (reg8 *) C_6_TC__DM2) 
/* Input Buffer Disable Override */
#define C_6_TC_INP_DIS                (* (reg8 *) C_6_TC__INP_DIS)
/* LCD Common or Segment Drive */
#define C_6_TC_LCD_COM_SEG            (* (reg8 *) C_6_TC__LCD_COM_SEG)
/* Enable Segment LCD */
#define C_6_TC_LCD_EN                 (* (reg8 *) C_6_TC__LCD_EN)
/* Slew Rate Control */
#define C_6_TC_SLW                    (* (reg8 *) C_6_TC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define C_6_TC_PRTDSI__CAPS_SEL       (* (reg8 *) C_6_TC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define C_6_TC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) C_6_TC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define C_6_TC_PRTDSI__OE_SEL0        (* (reg8 *) C_6_TC__PRTDSI__OE_SEL0) 
#define C_6_TC_PRTDSI__OE_SEL1        (* (reg8 *) C_6_TC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define C_6_TC_PRTDSI__OUT_SEL0       (* (reg8 *) C_6_TC__PRTDSI__OUT_SEL0) 
#define C_6_TC_PRTDSI__OUT_SEL1       (* (reg8 *) C_6_TC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define C_6_TC_PRTDSI__SYNC_OUT       (* (reg8 *) C_6_TC__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(C_6_TC__SIO_CFG)
    #define C_6_TC_SIO_HYST_EN        (* (reg8 *) C_6_TC__SIO_HYST_EN)
    #define C_6_TC_SIO_REG_HIFREQ     (* (reg8 *) C_6_TC__SIO_REG_HIFREQ)
    #define C_6_TC_SIO_CFG            (* (reg8 *) C_6_TC__SIO_CFG)
    #define C_6_TC_SIO_DIFF           (* (reg8 *) C_6_TC__SIO_DIFF)
#endif /* (C_6_TC__SIO_CFG) */

/* Interrupt Registers */
#if defined(C_6_TC__INTSTAT)
    #define C_6_TC_INTSTAT            (* (reg8 *) C_6_TC__INTSTAT)
    #define C_6_TC_SNAP               (* (reg8 *) C_6_TC__SNAP)
    
	#define C_6_TC_0_INTTYPE_REG 		(* (reg8 *) C_6_TC__0__INTTYPE)
#endif /* (C_6_TC__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_C_6_TC_H */


/* [] END OF FILE */
