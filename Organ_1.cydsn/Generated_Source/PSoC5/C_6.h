/*******************************************************************************
* File Name: C_6.h  
* Version 3.0
*
*  Description:
*   Contains the function prototypes and constants available to the counter
*   user module.
*
*   Note:
*    None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
    
#if !defined(CY_COUNTER_C_6_H)
#define CY_COUNTER_C_6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 C_6_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Counter_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Error message for removed C_6_CounterUDB_sCTRLReg_ctrlreg through optimization */
#ifdef C_6_CounterUDB_sCTRLReg_ctrlreg__REMOVED
    #error Counter_v3_0 detected with a constant 0 for the enable, a \
                                constant 0 for the count or constant 1 for \
                                the reset. This will prevent the component from\
                                operating.
#endif /* C_6_CounterUDB_sCTRLReg_ctrlreg__REMOVED */


/**************************************
*           Parameter Defaults        
**************************************/

#define C_6_Resolution            16u
#define C_6_UsingFixedFunction    1u
#define C_6_ControlRegRemoved     0u
#define C_6_COMPARE_MODE_SOFTWARE 0u
#define C_6_CAPTURE_MODE_SOFTWARE 0u
#define C_6_RunModeUsed           0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Mode API Support
 * Backup structure for Sleep Wake up operations
 *************************************************************************/
typedef struct
{
    uint8 CounterEnableState; 
    uint16 CounterUdb;         /* Current Counter Value */

    #if (!C_6_ControlRegRemoved)
        uint8 CounterControlRegister;               /* Counter Control Register */
    #endif /* (!C_6_ControlRegRemoved) */

}C_6_backupStruct;


/**************************************
 *  Function Prototypes
 *************************************/
void    C_6_Start(void) ;
void    C_6_Stop(void) ;
void    C_6_SetInterruptMode(uint8 interruptsMask) ;
uint8   C_6_ReadStatusRegister(void) ;
#define C_6_GetInterruptSource() C_6_ReadStatusRegister()
#if(!C_6_ControlRegRemoved)
    uint8   C_6_ReadControlRegister(void) ;
    void    C_6_WriteControlRegister(uint8 control) \
        ;
#endif /* (!C_6_ControlRegRemoved) */
#if (!(C_6_UsingFixedFunction && (CY_PSOC5A)))
    void    C_6_WriteCounter(uint16 counter) \
            ; 
#endif /* (!(C_6_UsingFixedFunction && (CY_PSOC5A))) */
uint16  C_6_ReadCounter(void) ;
uint16  C_6_ReadCapture(void) ;
void    C_6_WritePeriod(uint16 period) \
    ;
uint16  C_6_ReadPeriod( void ) ;
#if (!C_6_UsingFixedFunction)
    void    C_6_WriteCompare(uint16 compare) \
        ;
    uint16  C_6_ReadCompare( void ) \
        ;
#endif /* (!C_6_UsingFixedFunction) */

#if (C_6_COMPARE_MODE_SOFTWARE)
    void    C_6_SetCompareMode(uint8 compareMode) ;
#endif /* (C_6_COMPARE_MODE_SOFTWARE) */
#if (C_6_CAPTURE_MODE_SOFTWARE)
    void    C_6_SetCaptureMode(uint8 captureMode) ;
#endif /* (C_6_CAPTURE_MODE_SOFTWARE) */
void C_6_ClearFIFO(void)     ;
void C_6_Init(void)          ;
void C_6_Enable(void)        ;
void C_6_SaveConfig(void)    ;
void C_6_RestoreConfig(void) ;
void C_6_Sleep(void)         ;
void C_6_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Counter__CompareModes, Used in Compare Mode retained for backward compatibility of tests*/
#define C_6__B_COUNTER__LESS_THAN 1
#define C_6__B_COUNTER__LESS_THAN_OR_EQUAL 2
#define C_6__B_COUNTER__EQUAL 0
#define C_6__B_COUNTER__GREATER_THAN 3
#define C_6__B_COUNTER__GREATER_THAN_OR_EQUAL 4
#define C_6__B_COUNTER__SOFTWARE 5

/* Enumerated Type Counter_CompareModes */
#define C_6_CMP_MODE_LT 1u
#define C_6_CMP_MODE_LTE 2u
#define C_6_CMP_MODE_EQ 0u
#define C_6_CMP_MODE_GT 3u
#define C_6_CMP_MODE_GTE 4u
#define C_6_CMP_MODE_SOFTWARE_CONTROLLED 5u

/* Enumerated Type B_Counter__CaptureModes, Used in Capture Mode retained for backward compatibility of tests*/
#define C_6__B_COUNTER__NONE 0
#define C_6__B_COUNTER__RISING_EDGE 1
#define C_6__B_COUNTER__FALLING_EDGE 2
#define C_6__B_COUNTER__EITHER_EDGE 3
#define C_6__B_COUNTER__SOFTWARE_CONTROL 4

/* Enumerated Type Counter_CompareModes */
#define C_6_CAP_MODE_NONE 0u
#define C_6_CAP_MODE_RISE 1u
#define C_6_CAP_MODE_FALL 2u
#define C_6_CAP_MODE_BOTH 3u
#define C_6_CAP_MODE_SOFTWARE_CONTROLLED 4u


/***************************************
 *  Initialization Values
 **************************************/
#define C_6_CAPTURE_MODE_CONF       0u
#define C_6_INIT_PERIOD_VALUE       1911u
#define C_6_INIT_COUNTER_VALUE      0u
#if (C_6_UsingFixedFunction)
#define C_6_INIT_INTERRUPTS_MASK    ((uint8)((uint8)0u << C_6_STATUS_ZERO_INT_EN_MASK_SHIFT))
#else
#define C_6_INIT_COMPARE_VALUE      1u
#define C_6_INIT_INTERRUPTS_MASK ((uint8)((uint8)0u << C_6_STATUS_ZERO_INT_EN_MASK_SHIFT) | \
        ((uint8)((uint8)0u << C_6_STATUS_CAPTURE_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << C_6_STATUS_CMP_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << C_6_STATUS_OVERFLOW_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << C_6_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT)))
#define C_6_DEFAULT_COMPARE_MODE    1u

#if( 0 != C_6_CAPTURE_MODE_CONF)
    #define C_6_DEFAULT_CAPTURE_MODE    ((uint8)((uint8)0u << C_6_CTRL_CAPMODE0_SHIFT))
#else    
    #define C_6_DEFAULT_CAPTURE_MODE    (0u )
#endif /* ( 0 != C_6_CAPTURE_MODE_CONF) */

#endif /* (C_6_UsingFixedFunction) */


/**************************************
 *  Registers
 *************************************/
#if (C_6_UsingFixedFunction)
    #define C_6_STATICCOUNT_LSB     (*(reg16 *) C_6_CounterHW__CAP0 )
    #define C_6_STATICCOUNT_LSB_PTR ( (reg16 *) C_6_CounterHW__CAP0 )
    #define C_6_PERIOD_LSB          (*(reg16 *) C_6_CounterHW__PER0 )
    #define C_6_PERIOD_LSB_PTR      ( (reg16 *) C_6_CounterHW__PER0 )
    /* MODE must be set to 1 to set the compare value */
    #define C_6_COMPARE_LSB         (*(reg16 *) C_6_CounterHW__CNT_CMP0 )
    #define C_6_COMPARE_LSB_PTR     ( (reg16 *) C_6_CounterHW__CNT_CMP0 )
    /* MODE must be set to 0 to get the count */
    #define C_6_COUNTER_LSB         (*(reg16 *) C_6_CounterHW__CNT_CMP0 )
    #define C_6_COUNTER_LSB_PTR     ( (reg16 *) C_6_CounterHW__CNT_CMP0 )
    #define C_6_RT1                 (*(reg8 *) C_6_CounterHW__RT1)
    #define C_6_RT1_PTR             ( (reg8 *) C_6_CounterHW__RT1)
#else
    
    #if (C_6_Resolution <= 8u) /* 8-bit Counter */
    
        #define C_6_STATICCOUNT_LSB     (*(reg8 *) \
            C_6_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define C_6_STATICCOUNT_LSB_PTR ( (reg8 *) \
            C_6_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define C_6_PERIOD_LSB          (*(reg8 *) \
            C_6_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define C_6_PERIOD_LSB_PTR      ( (reg8 *) \
            C_6_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define C_6_COMPARE_LSB         (*(reg8 *) \
            C_6_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define C_6_COMPARE_LSB_PTR     ( (reg8 *) \
            C_6_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define C_6_COUNTER_LSB         (*(reg8 *) \
            C_6_CounterUDB_sC16_counterdp_u0__A0_REG )  
        #define C_6_COUNTER_LSB_PTR     ( (reg8 *)\
            C_6_CounterUDB_sC16_counterdp_u0__A0_REG )
    
    #elif(C_6_Resolution <= 16u) /* 16-bit Counter */
        #if(CY_PSOC3) /* 8-bit address space */ 
            #define C_6_STATICCOUNT_LSB     (*(reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define C_6_STATICCOUNT_LSB_PTR ( (reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define C_6_PERIOD_LSB          (*(reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define C_6_PERIOD_LSB_PTR      ( (reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define C_6_COMPARE_LSB         (*(reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define C_6_COMPARE_LSB_PTR     ( (reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define C_6_COUNTER_LSB         (*(reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__A0_REG )  
            #define C_6_COUNTER_LSB_PTR     ( (reg16 *)\
                C_6_CounterUDB_sC16_counterdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define C_6_STATICCOUNT_LSB     (*(reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__16BIT_F0_REG )
            #define C_6_STATICCOUNT_LSB_PTR ( (reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__16BIT_F0_REG )
            #define C_6_PERIOD_LSB          (*(reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__16BIT_D0_REG )
            #define C_6_PERIOD_LSB_PTR      ( (reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__16BIT_D0_REG )
            #define C_6_COMPARE_LSB         (*(reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__16BIT_D1_REG )
            #define C_6_COMPARE_LSB_PTR     ( (reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__16BIT_D1_REG )
            #define C_6_COUNTER_LSB         (*(reg16 *) \
                C_6_CounterUDB_sC16_counterdp_u0__16BIT_A0_REG )  
            #define C_6_COUNTER_LSB_PTR     ( (reg16 *)\
                C_6_CounterUDB_sC16_counterdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */   
    #elif(C_6_Resolution <= 24u) /* 24-bit Counter */
        
        #define C_6_STATICCOUNT_LSB     (*(reg32 *) \
            C_6_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define C_6_STATICCOUNT_LSB_PTR ( (reg32 *) \
            C_6_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define C_6_PERIOD_LSB          (*(reg32 *) \
            C_6_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define C_6_PERIOD_LSB_PTR      ( (reg32 *) \
            C_6_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define C_6_COMPARE_LSB         (*(reg32 *) \
            C_6_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define C_6_COMPARE_LSB_PTR     ( (reg32 *) \
            C_6_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define C_6_COUNTER_LSB         (*(reg32 *) \
            C_6_CounterUDB_sC16_counterdp_u0__A0_REG )  
        #define C_6_COUNTER_LSB_PTR     ( (reg32 *)\
            C_6_CounterUDB_sC16_counterdp_u0__A0_REG )
    
    #else /* 32-bit Counter */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define C_6_STATICCOUNT_LSB     (*(reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define C_6_STATICCOUNT_LSB_PTR ( (reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define C_6_PERIOD_LSB          (*(reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define C_6_PERIOD_LSB_PTR      ( (reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define C_6_COMPARE_LSB         (*(reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define C_6_COMPARE_LSB_PTR     ( (reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define C_6_COUNTER_LSB         (*(reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__A0_REG )  
            #define C_6_COUNTER_LSB_PTR     ( (reg32 *)\
                C_6_CounterUDB_sC16_counterdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define C_6_STATICCOUNT_LSB     (*(reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__32BIT_F0_REG )
            #define C_6_STATICCOUNT_LSB_PTR ( (reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__32BIT_F0_REG )
            #define C_6_PERIOD_LSB          (*(reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__32BIT_D0_REG )
            #define C_6_PERIOD_LSB_PTR      ( (reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__32BIT_D0_REG )
            #define C_6_COMPARE_LSB         (*(reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__32BIT_D1_REG )
            #define C_6_COMPARE_LSB_PTR     ( (reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__32BIT_D1_REG )
            #define C_6_COUNTER_LSB         (*(reg32 *) \
                C_6_CounterUDB_sC16_counterdp_u0__32BIT_A0_REG )  
            #define C_6_COUNTER_LSB_PTR     ( (reg32 *)\
                C_6_CounterUDB_sC16_counterdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */   
    #endif

	#define C_6_COUNTER_LSB_PTR_8BIT     ( (reg8 *)\
                C_6_CounterUDB_sC16_counterdp_u0__A0_REG )
				
    #define C_6_AUX_CONTROLDP0 \
        (*(reg8 *) C_6_CounterUDB_sC16_counterdp_u0__DP_AUX_CTL_REG)
    
    #define C_6_AUX_CONTROLDP0_PTR \
        ( (reg8 *) C_6_CounterUDB_sC16_counterdp_u0__DP_AUX_CTL_REG)
    
    #if (C_6_Resolution == 16 || C_6_Resolution == 24 || C_6_Resolution == 32)
       #define C_6_AUX_CONTROLDP1 \
           (*(reg8 *) C_6_CounterUDB_sC16_counterdp_u1__DP_AUX_CTL_REG)
       #define C_6_AUX_CONTROLDP1_PTR \
           ( (reg8 *) C_6_CounterUDB_sC16_counterdp_u1__DP_AUX_CTL_REG)
    #endif /* (C_6_Resolution == 16 || C_6_Resolution == 24 || C_6_Resolution == 32) */
    
    #if (C_6_Resolution == 24 || C_6_Resolution == 32)
       #define C_6_AUX_CONTROLDP2 \
           (*(reg8 *) C_6_CounterUDB_sC16_counterdp_u2__DP_AUX_CTL_REG)
       #define C_6_AUX_CONTROLDP2_PTR \
           ( (reg8 *) C_6_CounterUDB_sC16_counterdp_u2__DP_AUX_CTL_REG)
    #endif /* (C_6_Resolution == 24 || C_6_Resolution == 32) */
    
    #if (C_6_Resolution == 32)
       #define C_6_AUX_CONTROLDP3 \
           (*(reg8 *) C_6_CounterUDB_sC16_counterdp_u3__DP_AUX_CTL_REG)
       #define C_6_AUX_CONTROLDP3_PTR \
           ( (reg8 *) C_6_CounterUDB_sC16_counterdp_u3__DP_AUX_CTL_REG)
    #endif /* (C_6_Resolution == 32) */

#endif  /* (C_6_UsingFixedFunction) */

#if (C_6_UsingFixedFunction)
    #define C_6_STATUS         (*(reg8 *) C_6_CounterHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define C_6_STATUS_MASK             (*(reg8 *) C_6_CounterHW__SR0 )
    #define C_6_STATUS_MASK_PTR         ( (reg8 *) C_6_CounterHW__SR0 )
    #define C_6_CONTROL                 (*(reg8 *) C_6_CounterHW__CFG0)
    #define C_6_CONTROL_PTR             ( (reg8 *) C_6_CounterHW__CFG0)
    #define C_6_CONTROL2                (*(reg8 *) C_6_CounterHW__CFG1)
    #define C_6_CONTROL2_PTR            ( (reg8 *) C_6_CounterHW__CFG1)
    #if (CY_PSOC3 || CY_PSOC5LP)
        #define C_6_CONTROL3       (*(reg8 *) C_6_CounterHW__CFG2)
        #define C_6_CONTROL3_PTR   ( (reg8 *) C_6_CounterHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define C_6_GLOBAL_ENABLE           (*(reg8 *) C_6_CounterHW__PM_ACT_CFG)
    #define C_6_GLOBAL_ENABLE_PTR       ( (reg8 *) C_6_CounterHW__PM_ACT_CFG)
    #define C_6_GLOBAL_STBY_ENABLE      (*(reg8 *) C_6_CounterHW__PM_STBY_CFG)
    #define C_6_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) C_6_CounterHW__PM_STBY_CFG)
    

    /********************************
    *    Constants
    ********************************/

    /* Fixed Function Block Chosen */
    #define C_6_BLOCK_EN_MASK          C_6_CounterHW__PM_ACT_MSK
    #define C_6_BLOCK_STBY_EN_MASK     C_6_CounterHW__PM_STBY_MSK 
    
    /* Control Register Bit Locations */    
    /* As defined in Register Map, part of TMRX_CFG0 register */
    #define C_6_CTRL_ENABLE_SHIFT      0x00u
    #define C_6_ONESHOT_SHIFT          0x02u
    /* Control Register Bit Masks */
    #define C_6_CTRL_ENABLE            ((uint8)((uint8)0x01u << C_6_CTRL_ENABLE_SHIFT))         
    #define C_6_ONESHOT                ((uint8)((uint8)0x01u << C_6_ONESHOT_SHIFT))

    /* Control2 Register Bit Masks */
    /* Set the mask for run mode */
    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        #define C_6_CTRL_MODE_SHIFT        0x01u    
        #define C_6_CTRL_MODE_MASK         ((uint8)((uint8)0x07u << C_6_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Use CFG2 Mode bits to set run mode */
        #define C_6_CTRL_MODE_SHIFT        0x00u    
        #define C_6_CTRL_MODE_MASK         ((uint8)((uint8)0x03u << C_6_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    /* Set the mask for interrupt (raw/status register) */
    #define C_6_CTRL2_IRQ_SEL_SHIFT     0x00u
    #define C_6_CTRL2_IRQ_SEL          ((uint8)((uint8)0x01u << C_6_CTRL2_IRQ_SEL_SHIFT))     
    
    /* Status Register Bit Locations */
    #define C_6_STATUS_ZERO_SHIFT      0x07u  /* As defined in Register Map, part of TMRX_SR0 register */ 

    /* Status Register Interrupt Enable Bit Locations */
    #define C_6_STATUS_ZERO_INT_EN_MASK_SHIFT      (C_6_STATUS_ZERO_SHIFT - 0x04u)

    /* Status Register Bit Masks */                           
    #define C_6_STATUS_ZERO            ((uint8)((uint8)0x01u << C_6_STATUS_ZERO_SHIFT))

    /* Status Register Interrupt Bit Masks*/
    #define C_6_STATUS_ZERO_INT_EN_MASK       ((uint8)((uint8)C_6_STATUS_ZERO >> 0x04u))
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define C_6_RT1_SHIFT            0x04u
    #define C_6_RT1_MASK             ((uint8)((uint8)0x03u << C_6_RT1_SHIFT))  /* Sync TC and CMP bit masks */
    #define C_6_SYNC                 ((uint8)((uint8)0x03u << C_6_RT1_SHIFT))
    #define C_6_SYNCDSI_SHIFT        0x00u
    #define C_6_SYNCDSI_MASK         ((uint8)((uint8)0x0Fu << C_6_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    #define C_6_SYNCDSI_EN           ((uint8)((uint8)0x0Fu << C_6_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    
#else /* !C_6_UsingFixedFunction */
    #define C_6_STATUS               (* (reg8 *) C_6_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define C_6_STATUS_PTR           (  (reg8 *) C_6_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define C_6_STATUS_MASK          (* (reg8 *) C_6_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define C_6_STATUS_MASK_PTR      (  (reg8 *) C_6_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define C_6_STATUS_AUX_CTRL      (*(reg8 *) C_6_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define C_6_STATUS_AUX_CTRL_PTR  ( (reg8 *) C_6_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define C_6_CONTROL              (* (reg8 *) C_6_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )
    #define C_6_CONTROL_PTR          (  (reg8 *) C_6_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )


    /********************************
    *    Constants
    ********************************/
    /* Control Register Bit Locations */
    #define C_6_CTRL_CAPMODE0_SHIFT    0x03u       /* As defined by Verilog Implementation */
    #define C_6_CTRL_RESET_SHIFT       0x06u       /* As defined by Verilog Implementation */
    #define C_6_CTRL_ENABLE_SHIFT      0x07u       /* As defined by Verilog Implementation */
    /* Control Register Bit Masks */
    #define C_6_CTRL_CMPMODE_MASK      0x07u 
    #define C_6_CTRL_CAPMODE_MASK      0x03u  
    #define C_6_CTRL_RESET             ((uint8)((uint8)0x01u << C_6_CTRL_RESET_SHIFT))  
    #define C_6_CTRL_ENABLE            ((uint8)((uint8)0x01u << C_6_CTRL_ENABLE_SHIFT)) 

    /* Status Register Bit Locations */
    #define C_6_STATUS_CMP_SHIFT       0x00u       /* As defined by Verilog Implementation */
    #define C_6_STATUS_ZERO_SHIFT      0x01u       /* As defined by Verilog Implementation */
    #define C_6_STATUS_OVERFLOW_SHIFT  0x02u       /* As defined by Verilog Implementation */
    #define C_6_STATUS_UNDERFLOW_SHIFT 0x03u       /* As defined by Verilog Implementation */
    #define C_6_STATUS_CAPTURE_SHIFT   0x04u       /* As defined by Verilog Implementation */
    #define C_6_STATUS_FIFOFULL_SHIFT  0x05u       /* As defined by Verilog Implementation */
    #define C_6_STATUS_FIFONEMP_SHIFT  0x06u       /* As defined by Verilog Implementation */
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define C_6_STATUS_CMP_INT_EN_MASK_SHIFT       C_6_STATUS_CMP_SHIFT       
    #define C_6_STATUS_ZERO_INT_EN_MASK_SHIFT      C_6_STATUS_ZERO_SHIFT      
    #define C_6_STATUS_OVERFLOW_INT_EN_MASK_SHIFT  C_6_STATUS_OVERFLOW_SHIFT  
    #define C_6_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT C_6_STATUS_UNDERFLOW_SHIFT 
    #define C_6_STATUS_CAPTURE_INT_EN_MASK_SHIFT   C_6_STATUS_CAPTURE_SHIFT   
    #define C_6_STATUS_FIFOFULL_INT_EN_MASK_SHIFT  C_6_STATUS_FIFOFULL_SHIFT  
    #define C_6_STATUS_FIFONEMP_INT_EN_MASK_SHIFT  C_6_STATUS_FIFONEMP_SHIFT  
    /* Status Register Bit Masks */                
    #define C_6_STATUS_CMP             ((uint8)((uint8)0x01u << C_6_STATUS_CMP_SHIFT))  
    #define C_6_STATUS_ZERO            ((uint8)((uint8)0x01u << C_6_STATUS_ZERO_SHIFT)) 
    #define C_6_STATUS_OVERFLOW        ((uint8)((uint8)0x01u << C_6_STATUS_OVERFLOW_SHIFT)) 
    #define C_6_STATUS_UNDERFLOW       ((uint8)((uint8)0x01u << C_6_STATUS_UNDERFLOW_SHIFT)) 
    #define C_6_STATUS_CAPTURE         ((uint8)((uint8)0x01u << C_6_STATUS_CAPTURE_SHIFT)) 
    #define C_6_STATUS_FIFOFULL        ((uint8)((uint8)0x01u << C_6_STATUS_FIFOFULL_SHIFT))
    #define C_6_STATUS_FIFONEMP        ((uint8)((uint8)0x01u << C_6_STATUS_FIFONEMP_SHIFT))
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define C_6_STATUS_CMP_INT_EN_MASK            C_6_STATUS_CMP                    
    #define C_6_STATUS_ZERO_INT_EN_MASK           C_6_STATUS_ZERO            
    #define C_6_STATUS_OVERFLOW_INT_EN_MASK       C_6_STATUS_OVERFLOW        
    #define C_6_STATUS_UNDERFLOW_INT_EN_MASK      C_6_STATUS_UNDERFLOW       
    #define C_6_STATUS_CAPTURE_INT_EN_MASK        C_6_STATUS_CAPTURE         
    #define C_6_STATUS_FIFOFULL_INT_EN_MASK       C_6_STATUS_FIFOFULL        
    #define C_6_STATUS_FIFONEMP_INT_EN_MASK       C_6_STATUS_FIFONEMP         
    

    /* StatusI Interrupt Enable bit Location in the Auxilliary Control Register */
    #define C_6_STATUS_ACTL_INT_EN     0x10u /* As defined for the ACTL Register */
    
    /* Datapath Auxillary Control Register definitions */
    #define C_6_AUX_CTRL_FIFO0_CLR         0x01u   /* As defined by Register map */
    #define C_6_AUX_CTRL_FIFO1_CLR         0x02u   /* As defined by Register map */
    #define C_6_AUX_CTRL_FIFO0_LVL         0x04u   /* As defined by Register map */
    #define C_6_AUX_CTRL_FIFO1_LVL         0x08u   /* As defined by Register map */
    #define C_6_STATUS_ACTL_INT_EN_MASK    0x10u   /* As defined for the ACTL Register */
    
#endif /* C_6_UsingFixedFunction */

#endif  /* CY_COUNTER_C_6_H */


/* [] END OF FILE */

