/*******************************************************************************
* File Name: C_6.c  
* Version 3.0
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
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

uint8 C_6_initVar = 0u;


/*******************************************************************************
* Function Name: C_6_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void C_6_Init(void) 
{
        #if (!C_6_UsingFixedFunction && !C_6_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!C_6_UsingFixedFunction && !C_6_ControlRegRemoved) */
        
        #if(!C_6_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 C_6_interruptState;
        #endif /* (!C_6_UsingFixedFunction) */
        
        #if (C_6_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            C_6_CONTROL &= C_6_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                C_6_CONTROL2 &= ((uint8)(~C_6_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                C_6_CONTROL3 &= ((uint8)(~C_6_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (C_6_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                C_6_CONTROL |= C_6_ONESHOT;
            #endif /* (C_6_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            C_6_CONTROL2 |= C_6_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            C_6_RT1 &= ((uint8)(~C_6_RT1_MASK));
            C_6_RT1 |= C_6_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            C_6_RT1 &= ((uint8)(~C_6_SYNCDSI_MASK));
            C_6_RT1 |= C_6_SYNCDSI_EN;

        #else
            #if(!C_6_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = C_6_CONTROL & ((uint8)(~C_6_CTRL_CMPMODE_MASK));
            C_6_CONTROL = ctrl | C_6_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = C_6_CONTROL & ((uint8)(~C_6_CTRL_CAPMODE_MASK));
            
            #if( 0 != C_6_CAPTURE_MODE_CONF)
                C_6_CONTROL = ctrl | C_6_DEFAULT_CAPTURE_MODE;
            #else
                C_6_CONTROL = ctrl;
            #endif /* 0 != C_6_CAPTURE_MODE */ 
            
            #endif /* (!C_6_ControlRegRemoved) */
        #endif /* (C_6_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!C_6_UsingFixedFunction)
            C_6_ClearFIFO();
        #endif /* (!C_6_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        C_6_WritePeriod(C_6_INIT_PERIOD_VALUE);
        #if (!(C_6_UsingFixedFunction && (CY_PSOC5A)))
            C_6_WriteCounter(C_6_INIT_COUNTER_VALUE);
        #endif /* (!(C_6_UsingFixedFunction && (CY_PSOC5A))) */
        C_6_SetInterruptMode(C_6_INIT_INTERRUPTS_MASK);
        
        #if (!C_6_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)C_6_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            C_6_WriteCompare(C_6_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            C_6_interruptState = CyEnterCriticalSection();
            
            C_6_STATUS_AUX_CTRL |= C_6_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(C_6_interruptState);
            
        #endif /* (!C_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: C_6_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void C_6_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (C_6_UsingFixedFunction)
        C_6_GLOBAL_ENABLE |= C_6_BLOCK_EN_MASK;
        C_6_GLOBAL_STBY_ENABLE |= C_6_BLOCK_STBY_EN_MASK;
    #endif /* (C_6_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!C_6_ControlRegRemoved || C_6_UsingFixedFunction)
        C_6_CONTROL |= C_6_CTRL_ENABLE;                
    #endif /* (!C_6_ControlRegRemoved || C_6_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: C_6_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  C_6_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void C_6_Start(void) 
{
    if(C_6_initVar == 0u)
    {
        C_6_Init();
        
        C_6_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    C_6_Enable();        
}


/*******************************************************************************
* Function Name: C_6_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void C_6_Stop(void) 
{
    /* Disable Counter */
    #if(!C_6_ControlRegRemoved || C_6_UsingFixedFunction)
        C_6_CONTROL &= ((uint8)(~C_6_CTRL_ENABLE));        
    #endif /* (!C_6_ControlRegRemoved || C_6_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (C_6_UsingFixedFunction)
        C_6_GLOBAL_ENABLE &= ((uint8)(~C_6_BLOCK_EN_MASK));
        C_6_GLOBAL_STBY_ENABLE &= ((uint8)(~C_6_BLOCK_STBY_EN_MASK));
    #endif /* (C_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: C_6_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void C_6_SetInterruptMode(uint8 interruptsMask) 
{
    C_6_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: C_6_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   C_6_ReadStatusRegister(void) 
{
    return C_6_STATUS;
}


#if(!C_6_ControlRegRemoved)
/*******************************************************************************
* Function Name: C_6_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   C_6_ReadControlRegister(void) 
{
    return C_6_CONTROL;
}


/*******************************************************************************
* Function Name: C_6_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    C_6_WriteControlRegister(uint8 control) 
{
    C_6_CONTROL = control;
}

#endif  /* (!C_6_ControlRegRemoved) */


#if (!(C_6_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: C_6_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void C_6_WriteCounter(uint16 counter) \
                                   
{
    #if(C_6_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (C_6_GLOBAL_ENABLE & C_6_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        C_6_GLOBAL_ENABLE |= C_6_BLOCK_EN_MASK;
        CY_SET_REG16(C_6_COUNTER_LSB_PTR, (uint16)counter);
        C_6_GLOBAL_ENABLE &= ((uint8)(~C_6_BLOCK_EN_MASK));
    #else
        CY_SET_REG16(C_6_COUNTER_LSB_PTR, counter);
    #endif /* (C_6_UsingFixedFunction) */
}
#endif /* (!(C_6_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: C_6_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) The present value of the counter.
*
*******************************************************************************/
uint16 C_6_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(C_6_UsingFixedFunction)
		(void)CY_GET_REG16(C_6_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(C_6_COUNTER_LSB_PTR_8BIT);
	#endif/* (C_6_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(C_6_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(C_6_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(C_6_STATICCOUNT_LSB_PTR));
    #endif /* (C_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: C_6_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint16) Present Capture value.
*
*******************************************************************************/
uint16 C_6_ReadCapture(void) 
{
    #if(C_6_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(C_6_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(C_6_STATICCOUNT_LSB_PTR));
    #endif /* (C_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: C_6_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint16) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void C_6_WritePeriod(uint16 period) 
{
    #if(C_6_UsingFixedFunction)
        CY_SET_REG16(C_6_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG16(C_6_PERIOD_LSB_PTR, period);
    #endif /* (C_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: C_6_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) Present period value.
*
*******************************************************************************/
uint16 C_6_ReadPeriod(void) 
{
    #if(C_6_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(C_6_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(C_6_PERIOD_LSB_PTR));
    #endif /* (C_6_UsingFixedFunction) */
}


#if (!C_6_UsingFixedFunction)
/*******************************************************************************
* Function Name: C_6_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void C_6_WriteCompare(uint16 compare) \
                                   
{
    #if(C_6_UsingFixedFunction)
        CY_SET_REG16(C_6_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG16(C_6_COMPARE_LSB_PTR, compare);
    #endif /* (C_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: C_6_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint16) Present compare value.
*
*******************************************************************************/
uint16 C_6_ReadCompare(void) 
{
    return (CY_GET_REG16(C_6_COMPARE_LSB_PTR));
}


#if (C_6_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: C_6_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void C_6_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    C_6_CONTROL &= ((uint8)(~C_6_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    C_6_CONTROL |= compareMode;
}
#endif  /* (C_6_COMPARE_MODE_SOFTWARE) */


#if (C_6_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: C_6_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void C_6_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    C_6_CONTROL &= ((uint8)(~C_6_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    C_6_CONTROL |= ((uint8)((uint8)captureMode << C_6_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (C_6_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: C_6_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void C_6_ClearFIFO(void) 
{

    while(0u != (C_6_ReadStatusRegister() & C_6_STATUS_FIFONEMP))
    {
        (void)C_6_ReadCapture();
    }

}
#endif  /* (!C_6_UsingFixedFunction) */


/* [] END OF FILE */

