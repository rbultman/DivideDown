/*******************************************************************************
* File Name: C5.h  
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

#if !defined(CY_PINS_C5_H) /* Pins C5_H */
#define CY_PINS_C5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "C5_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 C5__PORT == 15 && ((C5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    C5_Write(uint8 value);
void    C5_SetDriveMode(uint8 mode);
uint8   C5_ReadDataReg(void);
uint8   C5_Read(void);
void    C5_SetInterruptMode(uint16 position, uint16 mode);
uint8   C5_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the C5_SetDriveMode() function.
     *  @{
     */
        #define C5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define C5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define C5_DM_RES_UP          PIN_DM_RES_UP
        #define C5_DM_RES_DWN         PIN_DM_RES_DWN
        #define C5_DM_OD_LO           PIN_DM_OD_LO
        #define C5_DM_OD_HI           PIN_DM_OD_HI
        #define C5_DM_STRONG          PIN_DM_STRONG
        #define C5_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define C5_MASK               C5__MASK
#define C5_SHIFT              C5__SHIFT
#define C5_WIDTH              1u

/* Interrupt constants */
#if defined(C5__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in C5_SetInterruptMode() function.
     *  @{
     */
        #define C5_INTR_NONE      (uint16)(0x0000u)
        #define C5_INTR_RISING    (uint16)(0x0001u)
        #define C5_INTR_FALLING   (uint16)(0x0002u)
        #define C5_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define C5_INTR_MASK      (0x01u) 
#endif /* (C5__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define C5_PS                     (* (reg8 *) C5__PS)
/* Data Register */
#define C5_DR                     (* (reg8 *) C5__DR)
/* Port Number */
#define C5_PRT_NUM                (* (reg8 *) C5__PRT) 
/* Connect to Analog Globals */                                                  
#define C5_AG                     (* (reg8 *) C5__AG)                       
/* Analog MUX bux enable */
#define C5_AMUX                   (* (reg8 *) C5__AMUX) 
/* Bidirectional Enable */                                                        
#define C5_BIE                    (* (reg8 *) C5__BIE)
/* Bit-mask for Aliased Register Access */
#define C5_BIT_MASK               (* (reg8 *) C5__BIT_MASK)
/* Bypass Enable */
#define C5_BYP                    (* (reg8 *) C5__BYP)
/* Port wide control signals */                                                   
#define C5_CTL                    (* (reg8 *) C5__CTL)
/* Drive Modes */
#define C5_DM0                    (* (reg8 *) C5__DM0) 
#define C5_DM1                    (* (reg8 *) C5__DM1)
#define C5_DM2                    (* (reg8 *) C5__DM2) 
/* Input Buffer Disable Override */
#define C5_INP_DIS                (* (reg8 *) C5__INP_DIS)
/* LCD Common or Segment Drive */
#define C5_LCD_COM_SEG            (* (reg8 *) C5__LCD_COM_SEG)
/* Enable Segment LCD */
#define C5_LCD_EN                 (* (reg8 *) C5__LCD_EN)
/* Slew Rate Control */
#define C5_SLW                    (* (reg8 *) C5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define C5_PRTDSI__CAPS_SEL       (* (reg8 *) C5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define C5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) C5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define C5_PRTDSI__OE_SEL0        (* (reg8 *) C5__PRTDSI__OE_SEL0) 
#define C5_PRTDSI__OE_SEL1        (* (reg8 *) C5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define C5_PRTDSI__OUT_SEL0       (* (reg8 *) C5__PRTDSI__OUT_SEL0) 
#define C5_PRTDSI__OUT_SEL1       (* (reg8 *) C5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define C5_PRTDSI__SYNC_OUT       (* (reg8 *) C5__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(C5__SIO_CFG)
    #define C5_SIO_HYST_EN        (* (reg8 *) C5__SIO_HYST_EN)
    #define C5_SIO_REG_HIFREQ     (* (reg8 *) C5__SIO_REG_HIFREQ)
    #define C5_SIO_CFG            (* (reg8 *) C5__SIO_CFG)
    #define C5_SIO_DIFF           (* (reg8 *) C5__SIO_DIFF)
#endif /* (C5__SIO_CFG) */

/* Interrupt Registers */
#if defined(C5__INTSTAT)
    #define C5_INTSTAT            (* (reg8 *) C5__INTSTAT)
    #define C5_SNAP               (* (reg8 *) C5__SNAP)
    
	#define C5_0_INTTYPE_REG 		(* (reg8 *) C5__0__INTTYPE)
#endif /* (C5__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_C5_H */


/* [] END OF FILE */
