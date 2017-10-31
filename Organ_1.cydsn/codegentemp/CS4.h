/*******************************************************************************
* File Name: CS4.h  
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

#if !defined(CY_PINS_CS4_H) /* Pins CS4_H */
#define CY_PINS_CS4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CS4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CS4__PORT == 15 && ((CS4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CS4_Write(uint8 value);
void    CS4_SetDriveMode(uint8 mode);
uint8   CS4_ReadDataReg(void);
uint8   CS4_Read(void);
void    CS4_SetInterruptMode(uint16 position, uint16 mode);
uint8   CS4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CS4_SetDriveMode() function.
     *  @{
     */
        #define CS4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CS4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CS4_DM_RES_UP          PIN_DM_RES_UP
        #define CS4_DM_RES_DWN         PIN_DM_RES_DWN
        #define CS4_DM_OD_LO           PIN_DM_OD_LO
        #define CS4_DM_OD_HI           PIN_DM_OD_HI
        #define CS4_DM_STRONG          PIN_DM_STRONG
        #define CS4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CS4_MASK               CS4__MASK
#define CS4_SHIFT              CS4__SHIFT
#define CS4_WIDTH              1u

/* Interrupt constants */
#if defined(CS4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CS4_SetInterruptMode() function.
     *  @{
     */
        #define CS4_INTR_NONE      (uint16)(0x0000u)
        #define CS4_INTR_RISING    (uint16)(0x0001u)
        #define CS4_INTR_FALLING   (uint16)(0x0002u)
        #define CS4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CS4_INTR_MASK      (0x01u) 
#endif /* (CS4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CS4_PS                     (* (reg8 *) CS4__PS)
/* Data Register */
#define CS4_DR                     (* (reg8 *) CS4__DR)
/* Port Number */
#define CS4_PRT_NUM                (* (reg8 *) CS4__PRT) 
/* Connect to Analog Globals */                                                  
#define CS4_AG                     (* (reg8 *) CS4__AG)                       
/* Analog MUX bux enable */
#define CS4_AMUX                   (* (reg8 *) CS4__AMUX) 
/* Bidirectional Enable */                                                        
#define CS4_BIE                    (* (reg8 *) CS4__BIE)
/* Bit-mask for Aliased Register Access */
#define CS4_BIT_MASK               (* (reg8 *) CS4__BIT_MASK)
/* Bypass Enable */
#define CS4_BYP                    (* (reg8 *) CS4__BYP)
/* Port wide control signals */                                                   
#define CS4_CTL                    (* (reg8 *) CS4__CTL)
/* Drive Modes */
#define CS4_DM0                    (* (reg8 *) CS4__DM0) 
#define CS4_DM1                    (* (reg8 *) CS4__DM1)
#define CS4_DM2                    (* (reg8 *) CS4__DM2) 
/* Input Buffer Disable Override */
#define CS4_INP_DIS                (* (reg8 *) CS4__INP_DIS)
/* LCD Common or Segment Drive */
#define CS4_LCD_COM_SEG            (* (reg8 *) CS4__LCD_COM_SEG)
/* Enable Segment LCD */
#define CS4_LCD_EN                 (* (reg8 *) CS4__LCD_EN)
/* Slew Rate Control */
#define CS4_SLW                    (* (reg8 *) CS4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CS4_PRTDSI__CAPS_SEL       (* (reg8 *) CS4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CS4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CS4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CS4_PRTDSI__OE_SEL0        (* (reg8 *) CS4__PRTDSI__OE_SEL0) 
#define CS4_PRTDSI__OE_SEL1        (* (reg8 *) CS4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CS4_PRTDSI__OUT_SEL0       (* (reg8 *) CS4__PRTDSI__OUT_SEL0) 
#define CS4_PRTDSI__OUT_SEL1       (* (reg8 *) CS4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CS4_PRTDSI__SYNC_OUT       (* (reg8 *) CS4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CS4__SIO_CFG)
    #define CS4_SIO_HYST_EN        (* (reg8 *) CS4__SIO_HYST_EN)
    #define CS4_SIO_REG_HIFREQ     (* (reg8 *) CS4__SIO_REG_HIFREQ)
    #define CS4_SIO_CFG            (* (reg8 *) CS4__SIO_CFG)
    #define CS4_SIO_DIFF           (* (reg8 *) CS4__SIO_DIFF)
#endif /* (CS4__SIO_CFG) */

/* Interrupt Registers */
#if defined(CS4__INTSTAT)
    #define CS4_INTSTAT            (* (reg8 *) CS4__INTSTAT)
    #define CS4_SNAP               (* (reg8 *) CS4__SNAP)
    
	#define CS4_0_INTTYPE_REG 		(* (reg8 *) CS4__0__INTTYPE)
#endif /* (CS4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CS4_H */


/* [] END OF FILE */
