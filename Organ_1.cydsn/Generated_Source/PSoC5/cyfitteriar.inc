;
; File Name: cyfitteriar.inc
; 
; PSoC Creator  4.1 Update 1
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2017 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar.inc
    INCLUDE cydeviceiar_trm.inc

/* A_6_Out */
A_6_Out__0__INTTYPE EQU CYREG_PICU0_INTTYPE6
A_6_Out__0__MASK EQU 0x40
A_6_Out__0__PC EQU CYREG_PRT0_PC6
A_6_Out__0__PORT EQU 0
A_6_Out__0__SHIFT EQU 6
A_6_Out__AG EQU CYREG_PRT0_AG
A_6_Out__AMUX EQU CYREG_PRT0_AMUX
A_6_Out__BIE EQU CYREG_PRT0_BIE
A_6_Out__BIT_MASK EQU CYREG_PRT0_BIT_MASK
A_6_Out__BYP EQU CYREG_PRT0_BYP
A_6_Out__CTL EQU CYREG_PRT0_CTL
A_6_Out__DM0 EQU CYREG_PRT0_DM0
A_6_Out__DM1 EQU CYREG_PRT0_DM1
A_6_Out__DM2 EQU CYREG_PRT0_DM2
A_6_Out__DR EQU CYREG_PRT0_DR
A_6_Out__INP_DIS EQU CYREG_PRT0_INP_DIS
A_6_Out__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
A_6_Out__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
A_6_Out__LCD_EN EQU CYREG_PRT0_LCD_EN
A_6_Out__MASK EQU 0x40
A_6_Out__PORT EQU 0
A_6_Out__PRT EQU CYREG_PRT0_PRT
A_6_Out__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
A_6_Out__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
A_6_Out__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
A_6_Out__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
A_6_Out__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
A_6_Out__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
A_6_Out__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
A_6_Out__PS EQU CYREG_PRT0_PS
A_6_Out__SHIFT EQU 6
A_6_Out__SLW EQU CYREG_PRT0_SLW

/* A_Sharp_6_Out */
A_Sharp_6_Out__0__INTTYPE EQU CYREG_PICU1_INTTYPE6
A_Sharp_6_Out__0__MASK EQU 0x40
A_Sharp_6_Out__0__PC EQU CYREG_PRT1_PC6
A_Sharp_6_Out__0__PORT EQU 1
A_Sharp_6_Out__0__SHIFT EQU 6
A_Sharp_6_Out__AG EQU CYREG_PRT1_AG
A_Sharp_6_Out__AMUX EQU CYREG_PRT1_AMUX
A_Sharp_6_Out__BIE EQU CYREG_PRT1_BIE
A_Sharp_6_Out__BIT_MASK EQU CYREG_PRT1_BIT_MASK
A_Sharp_6_Out__BYP EQU CYREG_PRT1_BYP
A_Sharp_6_Out__CTL EQU CYREG_PRT1_CTL
A_Sharp_6_Out__DM0 EQU CYREG_PRT1_DM0
A_Sharp_6_Out__DM1 EQU CYREG_PRT1_DM1
A_Sharp_6_Out__DM2 EQU CYREG_PRT1_DM2
A_Sharp_6_Out__DR EQU CYREG_PRT1_DR
A_Sharp_6_Out__INP_DIS EQU CYREG_PRT1_INP_DIS
A_Sharp_6_Out__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
A_Sharp_6_Out__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
A_Sharp_6_Out__LCD_EN EQU CYREG_PRT1_LCD_EN
A_Sharp_6_Out__MASK EQU 0x40
A_Sharp_6_Out__PORT EQU 1
A_Sharp_6_Out__PRT EQU CYREG_PRT1_PRT
A_Sharp_6_Out__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
A_Sharp_6_Out__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
A_Sharp_6_Out__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
A_Sharp_6_Out__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
A_Sharp_6_Out__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
A_Sharp_6_Out__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
A_Sharp_6_Out__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
A_Sharp_6_Out__PS EQU CYREG_PRT1_PS
A_Sharp_6_Out__SHIFT EQU 6
A_Sharp_6_Out__SLW EQU CYREG_PRT1_SLW

/* B_6_Out */
B_6_Out__0__INTTYPE EQU CYREG_PICU15_INTTYPE1
B_6_Out__0__MASK EQU 0x02
B_6_Out__0__PC EQU CYREG_IO_PC_PRT15_PC1
B_6_Out__0__PORT EQU 15
B_6_Out__0__SHIFT EQU 1
B_6_Out__AG EQU CYREG_PRT15_AG
B_6_Out__AMUX EQU CYREG_PRT15_AMUX
B_6_Out__BIE EQU CYREG_PRT15_BIE
B_6_Out__BIT_MASK EQU CYREG_PRT15_BIT_MASK
B_6_Out__BYP EQU CYREG_PRT15_BYP
B_6_Out__CTL EQU CYREG_PRT15_CTL
B_6_Out__DM0 EQU CYREG_PRT15_DM0
B_6_Out__DM1 EQU CYREG_PRT15_DM1
B_6_Out__DM2 EQU CYREG_PRT15_DM2
B_6_Out__DR EQU CYREG_PRT15_DR
B_6_Out__INP_DIS EQU CYREG_PRT15_INP_DIS
B_6_Out__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU15_BASE
B_6_Out__LCD_COM_SEG EQU CYREG_PRT15_LCD_COM_SEG
B_6_Out__LCD_EN EQU CYREG_PRT15_LCD_EN
B_6_Out__MASK EQU 0x02
B_6_Out__PORT EQU 15
B_6_Out__PRT EQU CYREG_PRT15_PRT
B_6_Out__PRTDSI__CAPS_SEL EQU CYREG_PRT15_CAPS_SEL
B_6_Out__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT15_DBL_SYNC_IN
B_6_Out__PRTDSI__OE_SEL0 EQU CYREG_PRT15_OE_SEL0
B_6_Out__PRTDSI__OE_SEL1 EQU CYREG_PRT15_OE_SEL1
B_6_Out__PRTDSI__OUT_SEL0 EQU CYREG_PRT15_OUT_SEL0
B_6_Out__PRTDSI__OUT_SEL1 EQU CYREG_PRT15_OUT_SEL1
B_6_Out__PRTDSI__SYNC_OUT EQU CYREG_PRT15_SYNC_OUT
B_6_Out__PS EQU CYREG_PRT15_PS
B_6_Out__SHIFT EQU 1
B_6_Out__SLW EQU CYREG_PRT15_SLW

/* C1 */
C1__0__INTTYPE EQU CYREG_PICU2_INTTYPE2
C1__0__MASK EQU 0x04
C1__0__PC EQU CYREG_PRT2_PC2
C1__0__PORT EQU 2
C1__0__SHIFT EQU 2
C1__AG EQU CYREG_PRT2_AG
C1__AMUX EQU CYREG_PRT2_AMUX
C1__BIE EQU CYREG_PRT2_BIE
C1__BIT_MASK EQU CYREG_PRT2_BIT_MASK
C1__BYP EQU CYREG_PRT2_BYP
C1__CTL EQU CYREG_PRT2_CTL
C1__DM0 EQU CYREG_PRT2_DM0
C1__DM1 EQU CYREG_PRT2_DM1
C1__DM2 EQU CYREG_PRT2_DM2
C1__DR EQU CYREG_PRT2_DR
C1__INP_DIS EQU CYREG_PRT2_INP_DIS
C1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
C1__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
C1__LCD_EN EQU CYREG_PRT2_LCD_EN
C1__MASK EQU 0x04
C1__PORT EQU 2
C1__PRT EQU CYREG_PRT2_PRT
C1__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
C1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
C1__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
C1__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
C1__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
C1__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
C1__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
C1__PS EQU CYREG_PRT2_PS
C1__SHIFT EQU 2
C1__SLW EQU CYREG_PRT2_SLW

/* C2 */
C2__0__INTTYPE EQU CYREG_PICU2_INTTYPE1
C2__0__MASK EQU 0x02
C2__0__PC EQU CYREG_PRT2_PC1
C2__0__PORT EQU 2
C2__0__SHIFT EQU 1
C2__AG EQU CYREG_PRT2_AG
C2__AMUX EQU CYREG_PRT2_AMUX
C2__BIE EQU CYREG_PRT2_BIE
C2__BIT_MASK EQU CYREG_PRT2_BIT_MASK
C2__BYP EQU CYREG_PRT2_BYP
C2__CTL EQU CYREG_PRT2_CTL
C2__DM0 EQU CYREG_PRT2_DM0
C2__DM1 EQU CYREG_PRT2_DM1
C2__DM2 EQU CYREG_PRT2_DM2
C2__DR EQU CYREG_PRT2_DR
C2__INP_DIS EQU CYREG_PRT2_INP_DIS
C2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
C2__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
C2__LCD_EN EQU CYREG_PRT2_LCD_EN
C2__MASK EQU 0x02
C2__PORT EQU 2
C2__PRT EQU CYREG_PRT2_PRT
C2__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
C2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
C2__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
C2__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
C2__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
C2__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
C2__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
C2__PS EQU CYREG_PRT2_PS
C2__SHIFT EQU 1
C2__SLW EQU CYREG_PRT2_SLW

/* C3 */
C3__0__INTTYPE EQU CYREG_PICU0_INTTYPE0
C3__0__MASK EQU 0x01
C3__0__PC EQU CYREG_PRT0_PC0
C3__0__PORT EQU 0
C3__0__SHIFT EQU 0
C3__AG EQU CYREG_PRT0_AG
C3__AMUX EQU CYREG_PRT0_AMUX
C3__BIE EQU CYREG_PRT0_BIE
C3__BIT_MASK EQU CYREG_PRT0_BIT_MASK
C3__BYP EQU CYREG_PRT0_BYP
C3__CTL EQU CYREG_PRT0_CTL
C3__DM0 EQU CYREG_PRT0_DM0
C3__DM1 EQU CYREG_PRT0_DM1
C3__DM2 EQU CYREG_PRT0_DM2
C3__DR EQU CYREG_PRT0_DR
C3__INP_DIS EQU CYREG_PRT0_INP_DIS
C3__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
C3__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
C3__LCD_EN EQU CYREG_PRT0_LCD_EN
C3__MASK EQU 0x01
C3__PORT EQU 0
C3__PRT EQU CYREG_PRT0_PRT
C3__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
C3__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
C3__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
C3__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
C3__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
C3__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
C3__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
C3__PS EQU CYREG_PRT0_PS
C3__SHIFT EQU 0
C3__SLW EQU CYREG_PRT0_SLW

/* C4 */
C4__0__INTTYPE EQU CYREG_PICU2_INTTYPE4
C4__0__MASK EQU 0x10
C4__0__PC EQU CYREG_PRT2_PC4
C4__0__PORT EQU 2
C4__0__SHIFT EQU 4
C4__AG EQU CYREG_PRT2_AG
C4__AMUX EQU CYREG_PRT2_AMUX
C4__BIE EQU CYREG_PRT2_BIE
C4__BIT_MASK EQU CYREG_PRT2_BIT_MASK
C4__BYP EQU CYREG_PRT2_BYP
C4__CTL EQU CYREG_PRT2_CTL
C4__DM0 EQU CYREG_PRT2_DM0
C4__DM1 EQU CYREG_PRT2_DM1
C4__DM2 EQU CYREG_PRT2_DM2
C4__DR EQU CYREG_PRT2_DR
C4__INP_DIS EQU CYREG_PRT2_INP_DIS
C4__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
C4__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
C4__LCD_EN EQU CYREG_PRT2_LCD_EN
C4__MASK EQU 0x10
C4__PORT EQU 2
C4__PRT EQU CYREG_PRT2_PRT
C4__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
C4__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
C4__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
C4__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
C4__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
C4__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
C4__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
C4__PS EQU CYREG_PRT2_PS
C4__SHIFT EQU 4
C4__SLW EQU CYREG_PRT2_SLW

/* C5 */
C5__0__INTTYPE EQU CYREG_PICU2_INTTYPE3
C5__0__MASK EQU 0x08
C5__0__PC EQU CYREG_PRT2_PC3
C5__0__PORT EQU 2
C5__0__SHIFT EQU 3
C5__AG EQU CYREG_PRT2_AG
C5__AMUX EQU CYREG_PRT2_AMUX
C5__BIE EQU CYREG_PRT2_BIE
C5__BIT_MASK EQU CYREG_PRT2_BIT_MASK
C5__BYP EQU CYREG_PRT2_BYP
C5__CTL EQU CYREG_PRT2_CTL
C5__DM0 EQU CYREG_PRT2_DM0
C5__DM1 EQU CYREG_PRT2_DM1
C5__DM2 EQU CYREG_PRT2_DM2
C5__DR EQU CYREG_PRT2_DR
C5__INP_DIS EQU CYREG_PRT2_INP_DIS
C5__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
C5__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
C5__LCD_EN EQU CYREG_PRT2_LCD_EN
C5__MASK EQU 0x08
C5__PORT EQU 2
C5__PRT EQU CYREG_PRT2_PRT
C5__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
C5__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
C5__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
C5__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
C5__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
C5__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
C5__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
C5__PS EQU CYREG_PRT2_PS
C5__SHIFT EQU 3
C5__SLW EQU CYREG_PRT2_SLW

/* C6 */
C6__0__INTTYPE EQU CYREG_PICU2_INTTYPE0
C6__0__MASK EQU 0x01
C6__0__PC EQU CYREG_PRT2_PC0
C6__0__PORT EQU 2
C6__0__SHIFT EQU 0
C6__AG EQU CYREG_PRT2_AG
C6__AMUX EQU CYREG_PRT2_AMUX
C6__BIE EQU CYREG_PRT2_BIE
C6__BIT_MASK EQU CYREG_PRT2_BIT_MASK
C6__BYP EQU CYREG_PRT2_BYP
C6__CTL EQU CYREG_PRT2_CTL
C6__DM0 EQU CYREG_PRT2_DM0
C6__DM1 EQU CYREG_PRT2_DM1
C6__DM2 EQU CYREG_PRT2_DM2
C6__DR EQU CYREG_PRT2_DR
C6__INP_DIS EQU CYREG_PRT2_INP_DIS
C6__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
C6__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
C6__LCD_EN EQU CYREG_PRT2_LCD_EN
C6__MASK EQU 0x01
C6__PORT EQU 2
C6__PRT EQU CYREG_PRT2_PRT
C6__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
C6__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
C6__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
C6__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
C6__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
C6__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
C6__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
C6__PS EQU CYREG_PRT2_PS
C6__SHIFT EQU 0
C6__SLW EQU CYREG_PRT2_SLW

/* CS5 */
CS5__0__INTTYPE EQU CYREG_PICU0_INTTYPE2
CS5__0__MASK EQU 0x04
CS5__0__PC EQU CYREG_PRT0_PC2
CS5__0__PORT EQU 0
CS5__0__SHIFT EQU 2
CS5__AG EQU CYREG_PRT0_AG
CS5__AMUX EQU CYREG_PRT0_AMUX
CS5__BIE EQU CYREG_PRT0_BIE
CS5__BIT_MASK EQU CYREG_PRT0_BIT_MASK
CS5__BYP EQU CYREG_PRT0_BYP
CS5__CTL EQU CYREG_PRT0_CTL
CS5__DM0 EQU CYREG_PRT0_DM0
CS5__DM1 EQU CYREG_PRT0_DM1
CS5__DM2 EQU CYREG_PRT0_DM2
CS5__DR EQU CYREG_PRT0_DR
CS5__INP_DIS EQU CYREG_PRT0_INP_DIS
CS5__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
CS5__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
CS5__LCD_EN EQU CYREG_PRT0_LCD_EN
CS5__MASK EQU 0x04
CS5__PORT EQU 0
CS5__PRT EQU CYREG_PRT0_PRT
CS5__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
CS5__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
CS5__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
CS5__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
CS5__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
CS5__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
CS5__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
CS5__PS EQU CYREG_PRT0_PS
CS5__SHIFT EQU 2
CS5__SLW EQU CYREG_PRT0_SLW

/* CS6 */
CS6__0__INTTYPE EQU CYREG_PICU0_INTTYPE4
CS6__0__MASK EQU 0x10
CS6__0__PC EQU CYREG_PRT0_PC4
CS6__0__PORT EQU 0
CS6__0__SHIFT EQU 4
CS6__AG EQU CYREG_PRT0_AG
CS6__AMUX EQU CYREG_PRT0_AMUX
CS6__BIE EQU CYREG_PRT0_BIE
CS6__BIT_MASK EQU CYREG_PRT0_BIT_MASK
CS6__BYP EQU CYREG_PRT0_BYP
CS6__CTL EQU CYREG_PRT0_CTL
CS6__DM0 EQU CYREG_PRT0_DM0
CS6__DM1 EQU CYREG_PRT0_DM1
CS6__DM2 EQU CYREG_PRT0_DM2
CS6__DR EQU CYREG_PRT0_DR
CS6__INP_DIS EQU CYREG_PRT0_INP_DIS
CS6__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
CS6__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
CS6__LCD_EN EQU CYREG_PRT0_LCD_EN
CS6__MASK EQU 0x10
CS6__PORT EQU 0
CS6__PRT EQU CYREG_PRT0_PRT
CS6__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
CS6__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
CS6__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
CS6__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
CS6__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
CS6__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
CS6__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
CS6__PS EQU CYREG_PRT0_PS
CS6__SHIFT EQU 4
CS6__SLW EQU CYREG_PRT0_SLW

/* C_6_CounterHW */
C_6_CounterHW__CAP0 EQU CYREG_TMR0_CAP0
C_6_CounterHW__CAP1 EQU CYREG_TMR0_CAP1
C_6_CounterHW__CFG0 EQU CYREG_TMR0_CFG0
C_6_CounterHW__CFG1 EQU CYREG_TMR0_CFG1
C_6_CounterHW__CFG2 EQU CYREG_TMR0_CFG2
C_6_CounterHW__CNT_CMP0 EQU CYREG_TMR0_CNT_CMP0
C_6_CounterHW__CNT_CMP1 EQU CYREG_TMR0_CNT_CMP1
C_6_CounterHW__PER0 EQU CYREG_TMR0_PER0
C_6_CounterHW__PER1 EQU CYREG_TMR0_PER1
C_6_CounterHW__PM_ACT_CFG EQU CYREG_PM_ACT_CFG3
C_6_CounterHW__PM_ACT_MSK EQU 0x01
C_6_CounterHW__PM_STBY_CFG EQU CYREG_PM_STBY_CFG3
C_6_CounterHW__PM_STBY_MSK EQU 0x01
C_6_CounterHW__RT0 EQU CYREG_TMR0_RT0
C_6_CounterHW__RT1 EQU CYREG_TMR0_RT1
C_6_CounterHW__SR0 EQU CYREG_TMR0_SR0

/* C_Sharp_6_CounterHW */
C_Sharp_6_CounterHW__CAP0 EQU CYREG_TMR1_CAP0
C_Sharp_6_CounterHW__CAP1 EQU CYREG_TMR1_CAP1
C_Sharp_6_CounterHW__CFG0 EQU CYREG_TMR1_CFG0
C_Sharp_6_CounterHW__CFG1 EQU CYREG_TMR1_CFG1
C_Sharp_6_CounterHW__CFG2 EQU CYREG_TMR1_CFG2
C_Sharp_6_CounterHW__CNT_CMP0 EQU CYREG_TMR1_CNT_CMP0
C_Sharp_6_CounterHW__CNT_CMP1 EQU CYREG_TMR1_CNT_CMP1
C_Sharp_6_CounterHW__PER0 EQU CYREG_TMR1_PER0
C_Sharp_6_CounterHW__PER1 EQU CYREG_TMR1_PER1
C_Sharp_6_CounterHW__PM_ACT_CFG EQU CYREG_PM_ACT_CFG3
C_Sharp_6_CounterHW__PM_ACT_MSK EQU 0x02
C_Sharp_6_CounterHW__PM_STBY_CFG EQU CYREG_PM_STBY_CFG3
C_Sharp_6_CounterHW__PM_STBY_MSK EQU 0x02
C_Sharp_6_CounterHW__RT0 EQU CYREG_TMR1_RT0
C_Sharp_6_CounterHW__RT1 EQU CYREG_TMR1_RT1
C_Sharp_6_CounterHW__SR0 EQU CYREG_TMR1_SR0

/* Clock_1 */
Clock_1__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
Clock_1__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
Clock_1__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
Clock_1__CFG2_SRC_SEL_MASK EQU 0x07
Clock_1__INDEX EQU 0x00
Clock_1__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_1__PM_ACT_MSK EQU 0x01
Clock_1__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_1__PM_STBY_MSK EQU 0x01

/* D_6_CounterHW */
D_6_CounterHW__CAP0 EQU CYREG_TMR2_CAP0
D_6_CounterHW__CAP1 EQU CYREG_TMR2_CAP1
D_6_CounterHW__CFG0 EQU CYREG_TMR2_CFG0
D_6_CounterHW__CFG1 EQU CYREG_TMR2_CFG1
D_6_CounterHW__CFG2 EQU CYREG_TMR2_CFG2
D_6_CounterHW__CNT_CMP0 EQU CYREG_TMR2_CNT_CMP0
D_6_CounterHW__CNT_CMP1 EQU CYREG_TMR2_CNT_CMP1
D_6_CounterHW__PER0 EQU CYREG_TMR2_PER0
D_6_CounterHW__PER1 EQU CYREG_TMR2_PER1
D_6_CounterHW__PM_ACT_CFG EQU CYREG_PM_ACT_CFG3
D_6_CounterHW__PM_ACT_MSK EQU 0x04
D_6_CounterHW__PM_STBY_CFG EQU CYREG_PM_STBY_CFG3
D_6_CounterHW__PM_STBY_MSK EQU 0x04
D_6_CounterHW__RT0 EQU CYREG_TMR2_RT0
D_6_CounterHW__RT1 EQU CYREG_TMR2_RT1
D_6_CounterHW__SR0 EQU CYREG_TMR2_SR0

/* D_6_Out */
D_6_Out__0__INTTYPE EQU CYREG_PICU0_INTTYPE1
D_6_Out__0__MASK EQU 0x02
D_6_Out__0__PC EQU CYREG_PRT0_PC1
D_6_Out__0__PORT EQU 0
D_6_Out__0__SHIFT EQU 1
D_6_Out__AG EQU CYREG_PRT0_AG
D_6_Out__AMUX EQU CYREG_PRT0_AMUX
D_6_Out__BIE EQU CYREG_PRT0_BIE
D_6_Out__BIT_MASK EQU CYREG_PRT0_BIT_MASK
D_6_Out__BYP EQU CYREG_PRT0_BYP
D_6_Out__CTL EQU CYREG_PRT0_CTL
D_6_Out__DM0 EQU CYREG_PRT0_DM0
D_6_Out__DM1 EQU CYREG_PRT0_DM1
D_6_Out__DM2 EQU CYREG_PRT0_DM2
D_6_Out__DR EQU CYREG_PRT0_DR
D_6_Out__INP_DIS EQU CYREG_PRT0_INP_DIS
D_6_Out__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
D_6_Out__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
D_6_Out__LCD_EN EQU CYREG_PRT0_LCD_EN
D_6_Out__MASK EQU 0x02
D_6_Out__PORT EQU 0
D_6_Out__PRT EQU CYREG_PRT0_PRT
D_6_Out__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
D_6_Out__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
D_6_Out__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
D_6_Out__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
D_6_Out__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
D_6_Out__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
D_6_Out__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
D_6_Out__PS EQU CYREG_PRT0_PS
D_6_Out__SHIFT EQU 1
D_6_Out__SLW EQU CYREG_PRT0_SLW

/* D_SHARP_6_CounterHW */
D_SHARP_6_CounterHW__CAP0 EQU CYREG_TMR3_CAP0
D_SHARP_6_CounterHW__CAP1 EQU CYREG_TMR3_CAP1
D_SHARP_6_CounterHW__CFG0 EQU CYREG_TMR3_CFG0
D_SHARP_6_CounterHW__CFG1 EQU CYREG_TMR3_CFG1
D_SHARP_6_CounterHW__CFG2 EQU CYREG_TMR3_CFG2
D_SHARP_6_CounterHW__CNT_CMP0 EQU CYREG_TMR3_CNT_CMP0
D_SHARP_6_CounterHW__CNT_CMP1 EQU CYREG_TMR3_CNT_CMP1
D_SHARP_6_CounterHW__PER0 EQU CYREG_TMR3_PER0
D_SHARP_6_CounterHW__PER1 EQU CYREG_TMR3_PER1
D_SHARP_6_CounterHW__PM_ACT_CFG EQU CYREG_PM_ACT_CFG3
D_SHARP_6_CounterHW__PM_ACT_MSK EQU 0x08
D_SHARP_6_CounterHW__PM_STBY_CFG EQU CYREG_PM_STBY_CFG3
D_SHARP_6_CounterHW__PM_STBY_MSK EQU 0x08
D_SHARP_6_CounterHW__RT0 EQU CYREG_TMR3_RT0
D_SHARP_6_CounterHW__RT1 EQU CYREG_TMR3_RT1
D_SHARP_6_CounterHW__SR0 EQU CYREG_TMR3_SR0

/* D_Sharp_6_Out */
D_Sharp_6_Out__0__INTTYPE EQU CYREG_PICU0_INTTYPE3
D_Sharp_6_Out__0__MASK EQU 0x08
D_Sharp_6_Out__0__PC EQU CYREG_PRT0_PC3
D_Sharp_6_Out__0__PORT EQU 0
D_Sharp_6_Out__0__SHIFT EQU 3
D_Sharp_6_Out__AG EQU CYREG_PRT0_AG
D_Sharp_6_Out__AMUX EQU CYREG_PRT0_AMUX
D_Sharp_6_Out__BIE EQU CYREG_PRT0_BIE
D_Sharp_6_Out__BIT_MASK EQU CYREG_PRT0_BIT_MASK
D_Sharp_6_Out__BYP EQU CYREG_PRT0_BYP
D_Sharp_6_Out__CTL EQU CYREG_PRT0_CTL
D_Sharp_6_Out__DM0 EQU CYREG_PRT0_DM0
D_Sharp_6_Out__DM1 EQU CYREG_PRT0_DM1
D_Sharp_6_Out__DM2 EQU CYREG_PRT0_DM2
D_Sharp_6_Out__DR EQU CYREG_PRT0_DR
D_Sharp_6_Out__INP_DIS EQU CYREG_PRT0_INP_DIS
D_Sharp_6_Out__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
D_Sharp_6_Out__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
D_Sharp_6_Out__LCD_EN EQU CYREG_PRT0_LCD_EN
D_Sharp_6_Out__MASK EQU 0x08
D_Sharp_6_Out__PORT EQU 0
D_Sharp_6_Out__PRT EQU CYREG_PRT0_PRT
D_Sharp_6_Out__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
D_Sharp_6_Out__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
D_Sharp_6_Out__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
D_Sharp_6_Out__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
D_Sharp_6_Out__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
D_Sharp_6_Out__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
D_Sharp_6_Out__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
D_Sharp_6_Out__PS EQU CYREG_PRT0_PS
D_Sharp_6_Out__SHIFT EQU 3
D_Sharp_6_Out__SLW EQU CYREG_PRT0_SLW

/* E_6_Out */
E_6_Out__0__INTTYPE EQU CYREG_PICU1_INTTYPE7
E_6_Out__0__MASK EQU 0x80
E_6_Out__0__PC EQU CYREG_PRT1_PC7
E_6_Out__0__PORT EQU 1
E_6_Out__0__SHIFT EQU 7
E_6_Out__AG EQU CYREG_PRT1_AG
E_6_Out__AMUX EQU CYREG_PRT1_AMUX
E_6_Out__BIE EQU CYREG_PRT1_BIE
E_6_Out__BIT_MASK EQU CYREG_PRT1_BIT_MASK
E_6_Out__BYP EQU CYREG_PRT1_BYP
E_6_Out__CTL EQU CYREG_PRT1_CTL
E_6_Out__DM0 EQU CYREG_PRT1_DM0
E_6_Out__DM1 EQU CYREG_PRT1_DM1
E_6_Out__DM2 EQU CYREG_PRT1_DM2
E_6_Out__DR EQU CYREG_PRT1_DR
E_6_Out__INP_DIS EQU CYREG_PRT1_INP_DIS
E_6_Out__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
E_6_Out__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
E_6_Out__LCD_EN EQU CYREG_PRT1_LCD_EN
E_6_Out__MASK EQU 0x80
E_6_Out__PORT EQU 1
E_6_Out__PRT EQU CYREG_PRT1_PRT
E_6_Out__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
E_6_Out__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
E_6_Out__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
E_6_Out__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
E_6_Out__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
E_6_Out__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
E_6_Out__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
E_6_Out__PS EQU CYREG_PRT1_PS
E_6_Out__SHIFT EQU 7
E_6_Out__SLW EQU CYREG_PRT1_SLW

/* F_6_Out */
F_6_Out__0__INTTYPE EQU CYREG_PICU1_INTTYPE5
F_6_Out__0__MASK EQU 0x20
F_6_Out__0__PC EQU CYREG_PRT1_PC5
F_6_Out__0__PORT EQU 1
F_6_Out__0__SHIFT EQU 5
F_6_Out__AG EQU CYREG_PRT1_AG
F_6_Out__AMUX EQU CYREG_PRT1_AMUX
F_6_Out__BIE EQU CYREG_PRT1_BIE
F_6_Out__BIT_MASK EQU CYREG_PRT1_BIT_MASK
F_6_Out__BYP EQU CYREG_PRT1_BYP
F_6_Out__CTL EQU CYREG_PRT1_CTL
F_6_Out__DM0 EQU CYREG_PRT1_DM0
F_6_Out__DM1 EQU CYREG_PRT1_DM1
F_6_Out__DM2 EQU CYREG_PRT1_DM2
F_6_Out__DR EQU CYREG_PRT1_DR
F_6_Out__INP_DIS EQU CYREG_PRT1_INP_DIS
F_6_Out__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
F_6_Out__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
F_6_Out__LCD_EN EQU CYREG_PRT1_LCD_EN
F_6_Out__MASK EQU 0x20
F_6_Out__PORT EQU 1
F_6_Out__PRT EQU CYREG_PRT1_PRT
F_6_Out__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
F_6_Out__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
F_6_Out__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
F_6_Out__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
F_6_Out__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
F_6_Out__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
F_6_Out__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
F_6_Out__PS EQU CYREG_PRT1_PS
F_6_Out__SHIFT EQU 5
F_6_Out__SLW EQU CYREG_PRT1_SLW

/* F_Sharp_6_Out */
F_Sharp_6_Out__0__INTTYPE EQU CYREG_PICU1_INTTYPE4
F_Sharp_6_Out__0__MASK EQU 0x10
F_Sharp_6_Out__0__PC EQU CYREG_PRT1_PC4
F_Sharp_6_Out__0__PORT EQU 1
F_Sharp_6_Out__0__SHIFT EQU 4
F_Sharp_6_Out__AG EQU CYREG_PRT1_AG
F_Sharp_6_Out__AMUX EQU CYREG_PRT1_AMUX
F_Sharp_6_Out__BIE EQU CYREG_PRT1_BIE
F_Sharp_6_Out__BIT_MASK EQU CYREG_PRT1_BIT_MASK
F_Sharp_6_Out__BYP EQU CYREG_PRT1_BYP
F_Sharp_6_Out__CTL EQU CYREG_PRT1_CTL
F_Sharp_6_Out__DM0 EQU CYREG_PRT1_DM0
F_Sharp_6_Out__DM1 EQU CYREG_PRT1_DM1
F_Sharp_6_Out__DM2 EQU CYREG_PRT1_DM2
F_Sharp_6_Out__DR EQU CYREG_PRT1_DR
F_Sharp_6_Out__INP_DIS EQU CYREG_PRT1_INP_DIS
F_Sharp_6_Out__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
F_Sharp_6_Out__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
F_Sharp_6_Out__LCD_EN EQU CYREG_PRT1_LCD_EN
F_Sharp_6_Out__MASK EQU 0x10
F_Sharp_6_Out__PORT EQU 1
F_Sharp_6_Out__PRT EQU CYREG_PRT1_PRT
F_Sharp_6_Out__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
F_Sharp_6_Out__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
F_Sharp_6_Out__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
F_Sharp_6_Out__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
F_Sharp_6_Out__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
F_Sharp_6_Out__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
F_Sharp_6_Out__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
F_Sharp_6_Out__PS EQU CYREG_PRT1_PS
F_Sharp_6_Out__SHIFT EQU 4
F_Sharp_6_Out__SLW EQU CYREG_PRT1_SLW

/* G_6_Out */
G_6_Out__0__INTTYPE EQU CYREG_PICU0_INTTYPE5
G_6_Out__0__MASK EQU 0x20
G_6_Out__0__PC EQU CYREG_PRT0_PC5
G_6_Out__0__PORT EQU 0
G_6_Out__0__SHIFT EQU 5
G_6_Out__AG EQU CYREG_PRT0_AG
G_6_Out__AMUX EQU CYREG_PRT0_AMUX
G_6_Out__BIE EQU CYREG_PRT0_BIE
G_6_Out__BIT_MASK EQU CYREG_PRT0_BIT_MASK
G_6_Out__BYP EQU CYREG_PRT0_BYP
G_6_Out__CTL EQU CYREG_PRT0_CTL
G_6_Out__DM0 EQU CYREG_PRT0_DM0
G_6_Out__DM1 EQU CYREG_PRT0_DM1
G_6_Out__DM2 EQU CYREG_PRT0_DM2
G_6_Out__DR EQU CYREG_PRT0_DR
G_6_Out__INP_DIS EQU CYREG_PRT0_INP_DIS
G_6_Out__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
G_6_Out__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
G_6_Out__LCD_EN EQU CYREG_PRT0_LCD_EN
G_6_Out__MASK EQU 0x20
G_6_Out__PORT EQU 0
G_6_Out__PRT EQU CYREG_PRT0_PRT
G_6_Out__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
G_6_Out__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
G_6_Out__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
G_6_Out__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
G_6_Out__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
G_6_Out__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
G_6_Out__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
G_6_Out__PS EQU CYREG_PRT0_PS
G_6_Out__SHIFT EQU 5
G_6_Out__SLW EQU CYREG_PRT0_SLW

/* G_Sharp_6_Out */
G_Sharp_6_Out__0__INTTYPE EQU CYREG_PICU1_INTTYPE2
G_Sharp_6_Out__0__MASK EQU 0x04
G_Sharp_6_Out__0__PC EQU CYREG_PRT1_PC2
G_Sharp_6_Out__0__PORT EQU 1
G_Sharp_6_Out__0__SHIFT EQU 2
G_Sharp_6_Out__AG EQU CYREG_PRT1_AG
G_Sharp_6_Out__AMUX EQU CYREG_PRT1_AMUX
G_Sharp_6_Out__BIE EQU CYREG_PRT1_BIE
G_Sharp_6_Out__BIT_MASK EQU CYREG_PRT1_BIT_MASK
G_Sharp_6_Out__BYP EQU CYREG_PRT1_BYP
G_Sharp_6_Out__CTL EQU CYREG_PRT1_CTL
G_Sharp_6_Out__DM0 EQU CYREG_PRT1_DM0
G_Sharp_6_Out__DM1 EQU CYREG_PRT1_DM1
G_Sharp_6_Out__DM2 EQU CYREG_PRT1_DM2
G_Sharp_6_Out__DR EQU CYREG_PRT1_DR
G_Sharp_6_Out__INP_DIS EQU CYREG_PRT1_INP_DIS
G_Sharp_6_Out__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
G_Sharp_6_Out__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
G_Sharp_6_Out__LCD_EN EQU CYREG_PRT1_LCD_EN
G_Sharp_6_Out__MASK EQU 0x04
G_Sharp_6_Out__PORT EQU 1
G_Sharp_6_Out__PRT EQU CYREG_PRT1_PRT
G_Sharp_6_Out__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
G_Sharp_6_Out__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
G_Sharp_6_Out__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
G_Sharp_6_Out__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
G_Sharp_6_Out__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
G_Sharp_6_Out__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
G_Sharp_6_Out__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
G_Sharp_6_Out__PS EQU CYREG_PRT1_PS
G_Sharp_6_Out__SHIFT EQU 2
G_Sharp_6_Out__SLW EQU CYREG_PRT1_SLW

/* Miscellaneous */
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 16
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 16
CYDEV_CHIP_MEMBER_4D EQU 12
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 17
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 15
CYDEV_CHIP_MEMBER_4I EQU 21
CYDEV_CHIP_MEMBER_4J EQU 13
CYDEV_CHIP_MEMBER_4K EQU 14
CYDEV_CHIP_MEMBER_4L EQU 20
CYDEV_CHIP_MEMBER_4M EQU 19
CYDEV_CHIP_MEMBER_4N EQU 9
CYDEV_CHIP_MEMBER_4O EQU 7
CYDEV_CHIP_MEMBER_4P EQU 18
CYDEV_CHIP_MEMBER_4Q EQU 11
CYDEV_CHIP_MEMBER_4R EQU 8
CYDEV_CHIP_MEMBER_4S EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 22
CYDEV_CHIP_MEMBER_FM3 EQU 26
CYDEV_CHIP_MEMBER_FM4 EQU 27
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 23
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 24
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 25
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 0
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000000
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */