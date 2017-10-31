/*******************************************************************************
* File Name: C_6_PM.c  
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

#include "C_6.h"

static C_6_backupStruct C_6_backup;


/*******************************************************************************
* Function Name: C_6_SaveConfig
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
*  C_6_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void C_6_SaveConfig(void) 
{
    #if (!C_6_UsingFixedFunction)

        C_6_backup.CounterUdb = C_6_ReadCounter();

        #if(!C_6_ControlRegRemoved)
            C_6_backup.CounterControlRegister = C_6_ReadControlRegister();
        #endif /* (!C_6_ControlRegRemoved) */

    #endif /* (!C_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: C_6_RestoreConfig
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
*  C_6_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void C_6_RestoreConfig(void) 
{      
    #if (!C_6_UsingFixedFunction)

       C_6_WriteCounter(C_6_backup.CounterUdb);

        #if(!C_6_ControlRegRemoved)
            C_6_WriteControlRegister(C_6_backup.CounterControlRegister);
        #endif /* (!C_6_ControlRegRemoved) */

    #endif /* (!C_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: C_6_Sleep
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
*  C_6_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void C_6_Sleep(void) 
{
    #if(!C_6_ControlRegRemoved)
        /* Save Counter's enable state */
        if(C_6_CTRL_ENABLE == (C_6_CONTROL & C_6_CTRL_ENABLE))
        {
            /* Counter is enabled */
            C_6_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            C_6_backup.CounterEnableState = 0u;
        }
    #else
        C_6_backup.CounterEnableState = 1u;
        if(C_6_backup.CounterEnableState != 0u)
        {
            C_6_backup.CounterEnableState = 0u;
        }
    #endif /* (!C_6_ControlRegRemoved) */
    
    C_6_Stop();
    C_6_SaveConfig();
}


/*******************************************************************************
* Function Name: C_6_Wakeup
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
*  C_6_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void C_6_Wakeup(void) 
{
    C_6_RestoreConfig();
    #if(!C_6_ControlRegRemoved)
        if(C_6_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            C_6_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!C_6_ControlRegRemoved) */
    
}


/* [] END OF FILE */
