/*******************************************************************************
* File Name: C3.h  
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

#if !defined(CY_PINS_C3_H) /* Pins C3_H */
#define CY_PINS_C3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "C3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 C3__PORT == 15 && ((C3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    C3_Write(uint8 value);
void    C3_SetDriveMode(uint8 mode);
uint8   C3_ReadDataReg(void);
uint8   C3_Read(void);
void    C3_SetInterruptMode(uint16 position, uint16 mode);
uint8   C3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the C3_SetDriveMode() function.
     *  @{
     */
        #define C3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define C3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define C3_DM_RES_UP          PIN_DM_RES_UP
        #define C3_DM_RES_DWN         PIN_DM_RES_DWN
        #define C3_DM_OD_LO           PIN_DM_OD_LO
        #define C3_DM_OD_HI           PIN_DM_OD_HI
        #define C3_DM_STRONG          PIN_DM_STRONG
        #define C3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define C3_MASK               C3__MASK
#define C3_SHIFT              C3__SHIFT
#define C3_WIDTH              1u

/* Interrupt constants */
#if defined(C3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in C3_SetInterruptMode() function.
     *  @{
     */
        #define C3_INTR_NONE      (uint16)(0x0000u)
        #define C3_INTR_RISING    (uint16)(0x0001u)
        #define C3_INTR_FALLING   (uint16)(0x0002u)
        #define C3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define C3_INTR_MASK      (0x01u) 
#endif /* (C3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define C3_PS                     (* (reg8 *) C3__PS)
/* Data Register */
#define C3_DR                     (* (reg8 *) C3__DR)
/* Port Number */
#define C3_PRT_NUM                (* (reg8 *) C3__PRT) 
/* Connect to Analog Globals */                                                  
#define C3_AG                     (* (reg8 *) C3__AG)                       
/* Analog MUX bux enable */
#define C3_AMUX                   (* (reg8 *) C3__AMUX) 
/* Bidirectional Enable */                                                        
#define C3_BIE                    (* (reg8 *) C3__BIE)
/* Bit-mask for Aliased Register Access */
#define C3_BIT_MASK               (* (reg8 *) C3__BIT_MASK)
/* Bypass Enable */
#define C3_BYP                    (* (reg8 *) C3__BYP)
/* Port wide control signals */                                                   
#define C3_CTL                    (* (reg8 *) C3__CTL)
/* Drive Modes */
#define C3_DM0                    (* (reg8 *) C3__DM0) 
#define C3_DM1                    (* (reg8 *) C3__DM1)
#define C3_DM2                    (* (reg8 *) C3__DM2) 
/* Input Buffer Disable Override */
#define C3_INP_DIS                (* (reg8 *) C3__INP_DIS)
/* LCD Common or Segment Drive */
#define C3_LCD_COM_SEG            (* (reg8 *) C3__LCD_COM_SEG)
/* Enable Segment LCD */
#define C3_LCD_EN                 (* (reg8 *) C3__LCD_EN)
/* Slew Rate Control */
#define C3_SLW                    (* (reg8 *) C3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define C3_PRTDSI__CAPS_SEL       (* (reg8 *) C3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define C3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) C3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define C3_PRTDSI__OE_SEL0        (* (reg8 *) C3__PRTDSI__OE_SEL0) 
#define C3_PRTDSI__OE_SEL1        (* (reg8 *) C3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define C3_PRTDSI__OUT_SEL0       (* (reg8 *) C3__PRTDSI__OUT_SEL0) 
#define C3_PRTDSI__OUT_SEL1       (* (reg8 *) C3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define C3_PRTDSI__SYNC_OUT       (* (reg8 *) C3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(C3__SIO_CFG)
    #define C3_SIO_HYST_EN        (* (reg8 *) C3__SIO_HYST_EN)
    #define C3_SIO_REG_HIFREQ     (* (reg8 *) C3__SIO_REG_HIFREQ)
    #define C3_SIO_CFG            (* (reg8 *) C3__SIO_CFG)
    #define C3_SIO_DIFF           (* (reg8 *) C3__SIO_DIFF)
#endif /* (C3__SIO_CFG) */

/* Interrupt Registers */
#if defined(C3__INTSTAT)
    #define C3_INTSTAT            (* (reg8 *) C3__INTSTAT)
    #define C3_SNAP               (* (reg8 *) C3__SNAP)
    
	#define C3_0_INTTYPE_REG 		(* (reg8 *) C3__0__INTTYPE)
#endif /* (C3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_C3_H */


/* [] END OF FILE */
