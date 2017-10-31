/*******************************************************************************
* File Name: D_SHARP_6.c  
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

#include "D_SHARP_6.h"

uint8 D_SHARP_6_initVar = 0u;


/*******************************************************************************
* Function Name: D_SHARP_6_Init
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
void D_SHARP_6_Init(void) 
{
        #if (!D_SHARP_6_UsingFixedFunction && !D_SHARP_6_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!D_SHARP_6_UsingFixedFunction && !D_SHARP_6_ControlRegRemoved) */
        
        #if(!D_SHARP_6_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 D_SHARP_6_interruptState;
        #endif /* (!D_SHARP_6_UsingFixedFunction) */
        
        #if (D_SHARP_6_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            D_SHARP_6_CONTROL &= D_SHARP_6_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                D_SHARP_6_CONTROL2 &= ((uint8)(~D_SHARP_6_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                D_SHARP_6_CONTROL3 &= ((uint8)(~D_SHARP_6_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (D_SHARP_6_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                D_SHARP_6_CONTROL |= D_SHARP_6_ONESHOT;
            #endif /* (D_SHARP_6_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            D_SHARP_6_CONTROL2 |= D_SHARP_6_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            D_SHARP_6_RT1 &= ((uint8)(~D_SHARP_6_RT1_MASK));
            D_SHARP_6_RT1 |= D_SHARP_6_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            D_SHARP_6_RT1 &= ((uint8)(~D_SHARP_6_SYNCDSI_MASK));
            D_SHARP_6_RT1 |= D_SHARP_6_SYNCDSI_EN;

        #else
            #if(!D_SHARP_6_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = D_SHARP_6_CONTROL & ((uint8)(~D_SHARP_6_CTRL_CMPMODE_MASK));
            D_SHARP_6_CONTROL = ctrl | D_SHARP_6_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = D_SHARP_6_CONTROL & ((uint8)(~D_SHARP_6_CTRL_CAPMODE_MASK));
            
            #if( 0 != D_SHARP_6_CAPTURE_MODE_CONF)
                D_SHARP_6_CONTROL = ctrl | D_SHARP_6_DEFAULT_CAPTURE_MODE;
            #else
                D_SHARP_6_CONTROL = ctrl;
            #endif /* 0 != D_SHARP_6_CAPTURE_MODE */ 
            
            #endif /* (!D_SHARP_6_ControlRegRemoved) */
        #endif /* (D_SHARP_6_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!D_SHARP_6_UsingFixedFunction)
            D_SHARP_6_ClearFIFO();
        #endif /* (!D_SHARP_6_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        D_SHARP_6_WritePeriod(D_SHARP_6_INIT_PERIOD_VALUE);
        #if (!(D_SHARP_6_UsingFixedFunction && (CY_PSOC5A)))
            D_SHARP_6_WriteCounter(D_SHARP_6_INIT_COUNTER_VALUE);
        #endif /* (!(D_SHARP_6_UsingFixedFunction && (CY_PSOC5A))) */
        D_SHARP_6_SetInterruptMode(D_SHARP_6_INIT_INTERRUPTS_MASK);
        
        #if (!D_SHARP_6_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)D_SHARP_6_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            D_SHARP_6_WriteCompare(D_SHARP_6_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            D_SHARP_6_interruptState = CyEnterCriticalSection();
            
            D_SHARP_6_STATUS_AUX_CTRL |= D_SHARP_6_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(D_SHARP_6_interruptState);
            
        #endif /* (!D_SHARP_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: D_SHARP_6_Enable
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
void D_SHARP_6_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (D_SHARP_6_UsingFixedFunction)
        D_SHARP_6_GLOBAL_ENABLE |= D_SHARP_6_BLOCK_EN_MASK;
        D_SHARP_6_GLOBAL_STBY_ENABLE |= D_SHARP_6_BLOCK_STBY_EN_MASK;
    #endif /* (D_SHARP_6_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!D_SHARP_6_ControlRegRemoved || D_SHARP_6_UsingFixedFunction)
        D_SHARP_6_CONTROL |= D_SHARP_6_CTRL_ENABLE;                
    #endif /* (!D_SHARP_6_ControlRegRemoved || D_SHARP_6_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: D_SHARP_6_Start
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
*  D_SHARP_6_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void D_SHARP_6_Start(void) 
{
    if(D_SHARP_6_initVar == 0u)
    {
        D_SHARP_6_Init();
        
        D_SHARP_6_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    D_SHARP_6_Enable();        
}


/*******************************************************************************
* Function Name: D_SHARP_6_Stop
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
void D_SHARP_6_Stop(void) 
{
    /* Disable Counter */
    #if(!D_SHARP_6_ControlRegRemoved || D_SHARP_6_UsingFixedFunction)
        D_SHARP_6_CONTROL &= ((uint8)(~D_SHARP_6_CTRL_ENABLE));        
    #endif /* (!D_SHARP_6_ControlRegRemoved || D_SHARP_6_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (D_SHARP_6_UsingFixedFunction)
        D_SHARP_6_GLOBAL_ENABLE &= ((uint8)(~D_SHARP_6_BLOCK_EN_MASK));
        D_SHARP_6_GLOBAL_STBY_ENABLE &= ((uint8)(~D_SHARP_6_BLOCK_STBY_EN_MASK));
    #endif /* (D_SHARP_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: D_SHARP_6_SetInterruptMode
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
void D_SHARP_6_SetInterruptMode(uint8 interruptsMask) 
{
    D_SHARP_6_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: D_SHARP_6_ReadStatusRegister
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
uint8   D_SHARP_6_ReadStatusRegister(void) 
{
    return D_SHARP_6_STATUS;
}


#if(!D_SHARP_6_ControlRegRemoved)
/*******************************************************************************
* Function Name: D_SHARP_6_ReadControlRegister
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
uint8   D_SHARP_6_ReadControlRegister(void) 
{
    return D_SHARP_6_CONTROL;
}


/*******************************************************************************
* Function Name: D_SHARP_6_WriteControlRegister
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
void    D_SHARP_6_WriteControlRegister(uint8 control) 
{
    D_SHARP_6_CONTROL = control;
}

#endif  /* (!D_SHARP_6_ControlRegRemoved) */


#if (!(D_SHARP_6_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: D_SHARP_6_WriteCounter
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
void D_SHARP_6_WriteCounter(uint16 counter) \
                                   
{
    #if(D_SHARP_6_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (D_SHARP_6_GLOBAL_ENABLE & D_SHARP_6_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        D_SHARP_6_GLOBAL_ENABLE |= D_SHARP_6_BLOCK_EN_MASK;
        CY_SET_REG16(D_SHARP_6_COUNTER_LSB_PTR, (uint16)counter);
        D_SHARP_6_GLOBAL_ENABLE &= ((uint8)(~D_SHARP_6_BLOCK_EN_MASK));
    #else
        CY_SET_REG16(D_SHARP_6_COUNTER_LSB_PTR, counter);
    #endif /* (D_SHARP_6_UsingFixedFunction) */
}
#endif /* (!(D_SHARP_6_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: D_SHARP_6_ReadCounter
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
uint16 D_SHARP_6_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(D_SHARP_6_UsingFixedFunction)
		(void)CY_GET_REG16(D_SHARP_6_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(D_SHARP_6_COUNTER_LSB_PTR_8BIT);
	#endif/* (D_SHARP_6_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(D_SHARP_6_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(D_SHARP_6_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(D_SHARP_6_STATICCOUNT_LSB_PTR));
    #endif /* (D_SHARP_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: D_SHARP_6_ReadCapture
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
uint16 D_SHARP_6_ReadCapture(void) 
{
    #if(D_SHARP_6_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(D_SHARP_6_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(D_SHARP_6_STATICCOUNT_LSB_PTR));
    #endif /* (D_SHARP_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: D_SHARP_6_WritePeriod
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
void D_SHARP_6_WritePeriod(uint16 period) 
{
    #if(D_SHARP_6_UsingFixedFunction)
        CY_SET_REG16(D_SHARP_6_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG16(D_SHARP_6_PERIOD_LSB_PTR, period);
    #endif /* (D_SHARP_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: D_SHARP_6_ReadPeriod
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
uint16 D_SHARP_6_ReadPeriod(void) 
{
    #if(D_SHARP_6_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(D_SHARP_6_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(D_SHARP_6_PERIOD_LSB_PTR));
    #endif /* (D_SHARP_6_UsingFixedFunction) */
}


#if (!D_SHARP_6_UsingFixedFunction)
/*******************************************************************************
* Function Name: D_SHARP_6_WriteCompare
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
void D_SHARP_6_WriteCompare(uint16 compare) \
                                   
{
    #if(D_SHARP_6_UsingFixedFunction)
        CY_SET_REG16(D_SHARP_6_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG16(D_SHARP_6_COMPARE_LSB_PTR, compare);
    #endif /* (D_SHARP_6_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: D_SHARP_6_ReadCompare
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
uint16 D_SHARP_6_ReadCompare(void) 
{
    return (CY_GET_REG16(D_SHARP_6_COMPARE_LSB_PTR));
}


#if (D_SHARP_6_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: D_SHARP_6_SetCompareMode
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
void D_SHARP_6_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    D_SHARP_6_CONTROL &= ((uint8)(~D_SHARP_6_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    D_SHARP_6_CONTROL |= compareMode;
}
#endif  /* (D_SHARP_6_COMPARE_MODE_SOFTWARE) */


#if (D_SHARP_6_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: D_SHARP_6_SetCaptureMode
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
void D_SHARP_6_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    D_SHARP_6_CONTROL &= ((uint8)(~D_SHARP_6_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    D_SHARP_6_CONTROL |= ((uint8)((uint8)captureMode << D_SHARP_6_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (D_SHARP_6_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: D_SHARP_6_ClearFIFO
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
void D_SHARP_6_ClearFIFO(void) 
{

    while(0u != (D_SHARP_6_ReadStatusRegister() & D_SHARP_6_STATUS_FIFONEMP))
    {
        (void)D_SHARP_6_ReadCapture();
    }

}
#endif  /* (!D_SHARP_6_UsingFixedFunction) */


/* [] END OF FILE */

