/*******************************************************************************
* File Name: D_SHARP_6_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "D_SHARP_6.h"

static D_SHARP_6_backupStruct D_SHARP_6_backup;


/*******************************************************************************
* Function Name: D_SHARP_6_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  D_SHARP_6_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void D_SHARP_6_SaveConfig(void) 
{
    #if (!D_SHARP_6_UsingFixedFunction)

        D_SHARP_6_backup.CounterUdb = D_SHARP_6_ReadCounter();

        #if(!D_SHARP_6_ControlRegRemoved)
            D_SHARP_6_backup.CounterControlRegister = D_SHARP_6_ReadControlRegister();
        #endif /* (!D_SHARP_6_ControlRegRemoved) */

    #endif /* (!D_SHARP_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: D_SHARP_6_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  D_SHARP_6_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void D_SHARP_6_RestoreConfig(void) 
{      
    #if (!D_SHARP_6_UsingFixedFunction)

       D_SHARP_6_WriteCounter(D_SHARP_6_backup.CounterUdb);

        #if(!D_SHARP_6_ControlRegRemoved)
            D_SHARP_6_WriteControlRegister(D_SHARP_6_backup.CounterControlRegister);
        #endif /* (!D_SHARP_6_ControlRegRemoved) */

    #endif /* (!D_SHARP_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: D_SHARP_6_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  D_SHARP_6_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void D_SHARP_6_Sleep(void) 
{
    #if(!D_SHARP_6_ControlRegRemoved)
        /* Save Counter's enable state */
        if(D_SHARP_6_CTRL_ENABLE == (D_SHARP_6_CONTROL & D_SHARP_6_CTRL_ENABLE))
        {
            /* Counter is enabled */
            D_SHARP_6_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            D_SHARP_6_backup.CounterEnableState = 0u;
        }
    #else
        D_SHARP_6_backup.CounterEnableState = 1u;
        if(D_SHARP_6_backup.CounterEnableState != 0u)
        {
            D_SHARP_6_backup.CounterEnableState = 0u;
        }
    #endif /* (!D_SHARP_6_ControlRegRemoved) */
    
    D_SHARP_6_Stop();
    D_SHARP_6_SaveConfig();
}


/*******************************************************************************
* Function Name: D_SHARP_6_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  D_SHARP_6_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void D_SHARP_6_Wakeup(void) 
{
    D_SHARP_6_RestoreConfig();
    #if(!D_SHARP_6_ControlRegRemoved)
        if(D_SHARP_6_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            D_SHARP_6_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!D_SHARP_6_ControlRegRemoved) */
    
}


/* [] END OF FILE */
