/*******************************************************************************
* File Name: C_Out.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_C_Out_ALIASES_H) /* Pins C_Out_ALIASES_H */
#define CY_PINS_C_Out_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define C_Out_0			(C_Out__0__PC)
#define C_Out_0_INTR	((uint16)((uint16)0x0001u << C_Out__0__SHIFT))

#define C_Out_1			(C_Out__1__PC)
#define C_Out_1_INTR	((uint16)((uint16)0x0001u << C_Out__1__SHIFT))

#define C_Out_2			(C_Out__2__PC)
#define C_Out_2_INTR	((uint16)((uint16)0x0001u << C_Out__2__SHIFT))

#define C_Out_3			(C_Out__3__PC)
#define C_Out_3_INTR	((uint16)((uint16)0x0001u << C_Out__3__SHIFT))

#define C_Out_4			(C_Out__4__PC)
#define C_Out_4_INTR	((uint16)((uint16)0x0001u << C_Out__4__SHIFT))

#define C_Out_5			(C_Out__5__PC)
#define C_Out_5_INTR	((uint16)((uint16)0x0001u << C_Out__5__SHIFT))

#define C_Out_INTR_ALL	 ((uint16)(C_Out_0_INTR| C_Out_1_INTR| C_Out_2_INTR| C_Out_3_INTR| C_Out_4_INTR| C_Out_5_INTR))

#endif /* End Pins C_Out_ALIASES_H */


/* [] END OF FILE */
