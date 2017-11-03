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
    Note7_Osc_WritePeriod(C_OSC_DIVIDER);
    Note7_Osc_Start();
    Note5_Osc_WritePeriod(CS_OSC_DIVIDER);
    Note5_Osc_Start();
    Note4_Osc_WritePeriod(D_OSC_DIVIDER);
    Note4_Osc_Start();
    Note3_Osc_WritePeriod(DS_OSC_DIVIDER);
    Note3_Osc_Start();
    Note2_Osc_WritePeriod(E_OSC_DIVIDER);
    Note2_Osc_Start();
    Note1_Osc_WritePeriod(F_OSC_DIVIDER);
    Note1_Osc_Start();
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
