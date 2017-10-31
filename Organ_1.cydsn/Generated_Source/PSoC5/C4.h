/*******************************************************************************
* File Name: C4.h  
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

#if !defined(CY_PINS_C4_H) /* Pins C4_H */
#define CY_PINS_C4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "C4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 C4__PORT == 15 && ((C4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    C4_Write(uint8 value);
void    C4_SetDriveMode(uint8 mode);
uint8   C4_ReadDataReg(void);
uint8   C4_Read(void);
void    C4_SetInterruptMode(uint16 position, uint16 mode);
uint8   C4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the C4_SetDriveMode() function.
     *  @{
     */
        #define C4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define C4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define C4_DM_RES_UP          PIN_DM_RES_UP
        #define C4_DM_RES_DWN         PIN_DM_RES_DWN
        #define C4_DM_OD_LO           PIN_DM_OD_LO
        #define C4_DM_OD_HI           PIN_DM_OD_HI
        #define C4_DM_STRONG          PIN_DM_STRONG
        #define C4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define C4_MASK               C4__MASK
#define C4_SHIFT              C4__SHIFT
#define C4_WIDTH              1u

/* Interrupt constants */
#if defined(C4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in C4_SetInterruptMode() function.
     *  @{
     */
        #define C4_INTR_NONE      (uint16)(0x0000u)
        #define C4_INTR_RISING    (uint16)(0x0001u)
        #define C4_INTR_FALLING   (uint16)(0x0002u)
        #define C4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define C4_INTR_MASK      (0x01u) 
#endif /* (C4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define C4_PS                     (* (reg8 *) C4__PS)
/* Data Register */
#define C4_DR                     (* (reg8 *) C4__DR)
/* Port Number */
#define C4_PRT_NUM                (* (reg8 *) C4__PRT) 
/* Connect to Analog Globals */                                                  
#define C4_AG                     (* (reg8 *) C4__AG)                       
/* Analog MUX bux enable */
#define C4_AMUX                   (* (reg8 *) C4__AMUX) 
/* Bidirectional Enable */                                                        
#define C4_BIE                    (* (reg8 *) C4__BIE)
/* Bit-mask for Aliased Register Access */
#define C4_BIT_MASK               (* (reg8 *) C4__BIT_MASK)
/* Bypass Enable */
#define C4_BYP                    (* (reg8 *) C4__BYP)
/* Port wide control signals */                                                   
#define C4_CTL                    (* (reg8 *) C4__CTL)
/* Drive Modes */
#define C4_DM0                    (* (reg8 *) C4__DM0) 
#define C4_DM1                    (* (reg8 *) C4__DM1)
#define C4_DM2                    (* (reg8 *) C4__DM2) 
/* Input Buffer Disable Override */
#define C4_INP_DIS                (* (reg8 *) C4__INP_DIS)
/* LCD Common or Segment Drive */
#define C4_LCD_COM_SEG            (* (reg8 *) C4__LCD_COM_SEG)
/* Enable Segment LCD */
#define C4_LCD_EN                 (* (reg8 *) C4__LCD_EN)
/* Slew Rate Control */
#define C4_SLW                    (* (reg8 *) C4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define C4_PRTDSI__CAPS_SEL       (* (reg8 *) C4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define C4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) C4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define C4_PRTDSI__OE_SEL0        (* (reg8 *) C4__PRTDSI__OE_SEL0) 
#define C4_PRTDSI__OE_SEL1        (* (reg8 *) C4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define C4_PRTDSI__OUT_SEL0       (* (reg8 *) C4__PRTDSI__OUT_SEL0) 
#define C4_PRTDSI__OUT_SEL1       (* (reg8 *) C4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define C4_PRTDSI__SYNC_OUT       (* (reg8 *) C4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(C4__SIO_CFG)
    #define C4_SIO_HYST_EN        (* (reg8 *) C4__SIO_HYST_EN)
    #define C4_SIO_REG_HIFREQ     (* (reg8 *) C4__SIO_REG_HIFREQ)
    #define C4_SIO_CFG            (* (reg8 *) C4__SIO_CFG)
    #define C4_SIO_DIFF           (* (reg8 *) C4__SIO_DIFF)
#endif /* (C4__SIO_CFG) */

/* Interrupt Registers */
#if defined(C4__INTSTAT)
    #define C4_INTSTAT            (* (reg8 *) C4__INTSTAT)
    #define C4_SNAP               (* (reg8 *) C4__SNAP)
    
	#define C4_0_INTTYPE_REG 		(* (reg8 *) C4__0__INTTYPE)
#endif /* (C4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_C4_H */


/* [] END OF FILE */
