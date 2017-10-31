/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

#define F_OSC_DIVIDER   8590
#define E_OSC_DIVIDER   9101
#define DS_OSC_DIVIDER  9642
#define D_OSC_DIVIDER  10216
#define CS_OSC_DIVIDER 10823
#define C_OSC_DIVIDER  11467

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Clock_1_Start();
    C_Osc_WritePeriod(C_OSC_DIVIDER);
    C_Osc_Start();
    CS_Osc_WritePeriod(CS_OSC_DIVIDER);
    CS_Osc_Start();
    D_Osc_WritePeriod(D_OSC_DIVIDER);
    D_Osc_Start();
    DS_Osc_WritePeriod(DS_OSC_DIVIDER);
    DS_Osc_Start();
    E_Osc_WritePeriod(E_OSC_DIVIDER);
    E_Osc_Start();
    F_Osc_WritePeriod(F_OSC_DIVIDER);
    F_Osc_Start();
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
