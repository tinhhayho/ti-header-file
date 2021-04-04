
//#############################################################################
//
// FILE:   tida_01606_adc.h
//
// TITLE: configure adc subsystem for tida 01606 board
//        refer to Texas Instruments
//        
//
//#############################################################################
// $Pelab Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################

#include "tida_01606_CLA.h"
#include "svm_gen.h"
#include "math.h"


#define _TEST_UDC_AND_TEMP_     1
#define _TEST_SENSOR_I_INV_     1
#define _TEST_SENSOR_U_GRID_    1
#define _TEST_SENSOR_U_CAP_     1


#ifdef  _RAM_LOAD_TEST_OPEN_LOOP_

#define offset1 1.65f
#define offset2 1.65f
#define offset3 1.65f

//
//define variable for CLA function
//

#pragma DATA_SECTION(Xn, "CpuToCla1MsgRAM")
float Xn;


#pragma DATA_SECTION(j, "CpuToCla1MsgRAM")
Uint32 j;
#pragma DATA_SECTION(pll, "Cla1ToCpuMsgRAM")
PLL pll;
#pragma DATA_SECTION(UA, "Cla1ToCpuMsgRAM")

float UA;
#pragma DATA_SECTION(UB, "Cla1ToCpuMsgRAM")
float UB;

#pragma DATA_SECTION(Vddd, "Cla1ToCpuMsgRAM")
float Vddd;
#pragma DATA_SECTION(Vqqq, "Cla1ToCpuMsgRAM")
float Vqqq;

#pragma DATA_SECTION(angle, "Cla1ToCpuMsgRAM")
float angle;


#pragma DATA_SECTION(set_point, "CpuToCla1MsgRAM")
float set_point;

#pragma DATA_SECTION(set_point2, "CpuToCla1MsgRAM")
float set_point2;

#pragma DATA_SECTION(data_analysis, "Test_memory")
float data_analysis[buffer_size];


#pragma DATA_SECTION(adcValue, "CpuToCla1MsgRAM")
CLA_ADC_VALUE adcValue;

Uint16 a = 0;

Uint32 ez = 0;

typedef struct {
    float offsetUdc;
    float GainUdc;
    float offsetUga;
    float GainUga;
    float offsetUgb;
    float GainUgb;
    float offsetUgc;
    float GainUgc;
}Adc_parameter;
Adc_parameter adc_param ;


typedef struct {
    float Vin;
    float Threshold;
    float Vrms;
    float Vacc_rms;
    float curr_sample;
    Uint16 prev_sign;
    Uint16 curr_sign;
    Uint16 nsample;
} Analyzer;

#define NsampleMin  250
#define NsampleMax  450

Analyzer    analyzer ;
//
// Task 1 (C) Variables
//



//
// Task 2 (C) Variables
//





//
// Task 3 (C) Variables
//




//
// Task 4 (C) Variables
//



//
// Task 5 (C) Variables
//




//
// Task 6 (C) Variables
//




//
// Task 7 (C) Variables
//




//
// Task 8 (C) Variables
//


//
//memory section
//


extern uint16_t Cla1ProgRunStart, Cla1ProgLoadStart, Cla1ProgLoadSize;
extern uint16_t CLA1mathTablesRunStart, CLA1mathTablesLoadStart;
extern uint16_t CLA1mathTablesLoadSize;


extern tida_01606_protection_state *pstate_protect ;
extern tida_01606_protection_value *pvalue_protect ;

void configCLAMemory(void)
{

#ifdef _FLASH
    //
    // Copy over code from FLASH to RAM
    //
    memcpy((uint32_t *)&Cla1ProgRunStart, (uint32_t *)&Cla1ProgLoadStart,
           (uint32_t)&Cla1ProgLoadSize);
#endif //_FLASH
    
    EALLOW;
    //
    // Perform RAM initialization on the message RAMs
    //
    MemCfgRegs.MSGxINIT.bit.INIT_CLA1TOCPU = 1;
    while(MemCfgRegs.MSGxINITDONE.bit.INITDONE_CLA1TOCPU != 1)
    {
    }

    MemCfgRegs.MSGxINIT.bit.INIT_CPUTOCLA1 = 1;
    while(MemCfgRegs.MSGxINITDONE.bit.INITDONE_CPUTOCLA1 != 1)
    {
    }

    //gram ls4-5 for cla program
    // 1 for progarn space
    // 0 for data space


    //data ls0-1

    MemCfgRegs.LSxMSEL.bit.MSEL_LS0 = 1;
    MemCfgRegs.LSxCLAPGM.bit.CLAPGM_LS0 = 0;

    MemCfgRegs.LSxMSEL.bit.MSEL_LS1 = 1;
    MemCfgRegs.LSxCLAPGM.bit.CLAPGM_LS1 = 0;

    MemCfgRegs.LSxMSEL.bit.MSEL_LS2 = 1;
    MemCfgRegs.LSxCLAPGM.bit.CLAPGM_LS2 = 0;


    MemCfgRegs.LSxMSEL.bit.MSEL_LS3 = 1;
    MemCfgRegs.LSxCLAPGM.bit.CLAPGM_LS3 = 1;

    MemCfgRegs.LSxMSEL.bit.MSEL_LS4 = 1;
    MemCfgRegs.LSxCLAPGM.bit.CLAPGM_LS4 = 1;

    MemCfgRegs.LSxMSEL.bit.MSEL_LS5 = 1;
    MemCfgRegs.LSxCLAPGM.bit.CLAPGM_LS5 = 1;


    EDIS;
}



void initCPU1CLA1(void)
{
    //
    // Compute all CLA task vectors
    // On Type-1 CLAs the MVECT registers accept full 16-bit task addresses as
    // opposed to offsets used on older Type-0 CLAs
    //
    // Assign the task vectors
    //
    EALLOW;
    Cla1Regs.MVECT1 = (uint16_t)(&Cla1Task1);
    Cla1Regs.MVECT2 = (uint16_t)(&Cla1Task2);
    Cla1Regs.MVECT3 = (uint16_t)(&Cla1Task3);
    Cla1Regs.MVECT4 = (uint16_t)(&Cla1Task4);
    Cla1Regs.MVECT5 = (uint16_t)(&Cla1Task5);
    Cla1Regs.MVECT6 = (uint16_t)(&Cla1Task6);
    Cla1Regs.MVECT7 = (uint16_t)(&Cla1Task7);
    Cla1Regs.MVECT8 = (uint16_t)(&Cla1Task8);

    //
    // Enable IACK instruction to start a task on CLA in software
    // and enable all  8 CLA tasks
    //
    __asm("   RPT #3 || NOP");
    Cla1Regs.MCTL.bit.IACKE = 1;
    Cla1Regs.MIER.all   = 0x00FF;

    //
    //set adcd.4 as the trigger for task 1
    // rewrite : -> task 1 trigger by software
    //
    //DmaClaSrcSelRegs.CLA1TASKSRCSEL1.bit.TASK1  = 19;

    EDIS;
}

void initCLA1PIE(void)
{
    //
    // Configure the vectors for the end-of-task interrupt for all
    // 8 tasks
    //
    EALLOW;
    PieVectTable.CLA1_1_INT = &cla1Isr1;
    PieVectTable.CLA1_2_INT = &cla1Isr2;
    PieVectTable.CLA1_3_INT = &cla1Isr3;
    PieVectTable.CLA1_4_INT = &cla1Isr4;
    PieVectTable.CLA1_5_INT = &cla1Isr5;
    PieVectTable.CLA1_6_INT = &cla1Isr6;
    PieVectTable.CLA1_7_INT = &cla1Isr7;
    PieVectTable.CLA1_8_INT = &cla1Isr8;
    IER                    |= M_INT11;
    #ifdef _TEST_SPEED_


    PieVectTable.EPWM1_INT  = &epwm1ISR;
    IER                     |=M_INT3;
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;

    #endif

    //
    // Enable CLA interrupts at the group and subgroup levels
    //
    PieCtrlRegs.PIEIER11.all = 0xFFFF;
    EDIS;
}


//
// cla1Isr1 - CLA1 ISR 1
//
__interrupt void cla1Isr1 ()
{
    // 
    //  clear the adc interrupt flag so the next SOC can occur
    //  clear the PIEACK bits so another interrupt can be taken
    //









    EALLOW;
    if(a)
    {
        GpioDataRegs.GPBSET.bit.GPIO43 = 1;
    }
    else
    {
        GpioDataRegs.GPBCLEAR.bit.GPIO43 = 1;
    }
    EDIS;


    if(adcValue.TIDA_VDC_BUS <= 20)
    {
        pinput->ua  = 0;
        pinput->ub  = 0;
    }
    else
    {
        pinput->udc     =adcValue.TIDA_VDC_BUS*0.5773503;
        pinput->ua = UA;
        pinput->ub = UB;
        svm_gen(pinput, psector, ptime_v, ptime_out, pepwm_count);
    }



    EALLOW;

    GpioDataRegs.GPBCLEAR.bit.GPIO35  = 1;
    EDIS;

    PieCtrlRegs.PIEACK.all = M_INT11;


}

//
// cla1Isr1 - CLA1 ISR 2
//
__interrupt void cla1Isr2 ()
{
    PieCtrlRegs.PIEACK.all = M_INT11;

}

//
// cla1Isr1 - CLA1 ISR 3
//
__interrupt void cla1Isr3 ()
{
    asm(" ESTOP0");
}

//
// cla1Isr1 - CLA1 ISR 4
//
__interrupt void cla1Isr4 ()
{
    asm(" ESTOP0");
}

//
// cla1Isr1 - CLA1 ISR 5
//
__interrupt void cla1Isr5 ()
{
    asm(" ESTOP0");
}

//
// cla1Isr1 - CLA1 ISR 6
//
__interrupt void cla1Isr6 ()
{
    asm(" ESTOP0");
}

//
// cla1Isr1 - CLA1 ISR 7
//
__interrupt void cla1Isr7 ()
{
    asm(" ESTOP0");
}

//
// cla1Isr1 - CLA1 ISR 8
//
__interrupt void cla1Isr8 ()
{

    //
    // Acknowledge the end-of-task interrupt for task 8
    //
//    pinput->udc = 200/1.732;
    PieCtrlRegs.PIEACK.all = M_INT11;



    //
    //  init data
    //

}






__interrupt void adcIsr1()
{

    AdcdRegs.ADCINTFLGCLR.bit.ADCINT4   = 1;
    PieCtrlRegs.PIEACK.all = M_INT10;


}

const float s_input[3] = {0.291811494452136f, 0.134808447143827753f, \
                         0.0105243353319224887f \
};

const float a_input[5] = {-1.99043176025571267f, 0.990750137821239441f,   \
                         -1.97033929712363998f, 0.970724190841448897f,   \
                         -0.978951329336155029f \
};

const float b_output[2] = {-1.99890896153311415f, -1.99714488427124803f \
};
static IIR_5_order VDC_irr;


#ifdef _TEST_SPEED_

__interrupt void epwm1ISR(void)
{


    EALLOW;
//    GpioDataRegs.GPBTOGGLE.bit.GPIO35 = 1
    GpioDataRegs.GPBSET.bit.GPIO35    = 1;
    EDIS;
#ifdef _TEST_SENSOR_I_INV_
    // iir filter


     adcValue.TIDA_IA = (RESULT_IA - 1.7)*32;
     adcValue.TIDA_IB = (RESULT_IB - 1.7)*32;
     adcValue.TIDA_IC = (RESULT_IC - 1.7)*32;


#endif

#ifdef _TEST_SENSOR_U_GRID_


    adcValue.TIDA_UGRID_A = (RESULT_VGRID_A-1.65)*-272.773f;
    adcValue.TIDA_UGRID_B = (RESULT_VGRID_B-1.65)*-292.773f;
    adcValue.TIDA_UGRID_C = (RESULT_VGRID_C-1.65)*-272.773f;

#endif

#ifdef _TEST_SENSOR_U_CAP_




    adcValue.TIDA_UINV_A  = (RESULT_VINV_A-1.65)*-272.773f;
    adcValue.TIDA_UINV_B  = (RESULT_VINV_B-1.65)*-290.773f;
    adcValue.TIDA_UINV_C  = (RESULT_VINV_C-1.65)*-270.773f;


#endif

#ifdef _TEST_UDC_AND_TEMP_


    adcValue.TIDA_TEMPA = RESULT_TEMPA;
    adcValue.TIDA_TEMPB = RESULT_TEMPB;
    adcValue.TIDA_TEMPC = RESULT_TEMPC;
    adcValue.TIDA_TEMPAMP  = RESULT_TEMPAMB;



    VDC_irr.io0[0] = RESULT_VBUS;
    //---floor 1---//
    VDC_irr.floor0[0] = VDC_irr.io0[0]*s_input[0] - \
                        VDC_irr.floor0[1]*a_input[0] - \
                        VDC_irr.floor0[2]*a_input[1] ;

    VDC_irr.io0[1]    = VDC_irr.floor0[0] + \
                        VDC_irr.floor0[1]*b_output[0] + \
                        VDC_irr.floor0[2];

    VDC_irr.floor0[2] = VDC_irr.floor0[1];
    VDC_irr.floor0[1] = VDC_irr.floor0[0];



    //---floor 2---//
    VDC_irr.io1[0]    = VDC_irr.io0[1];

    VDC_irr.floor1[0] = VDC_irr.io1[0]*s_input[1] - \
                        VDC_irr.floor1[1]*a_input[2] - \
                        VDC_irr.floor1[2]*a_input[3];
    VDC_irr.io1[1]    = VDC_irr.floor1[0] + \
                        VDC_irr.floor1[1]*b_output[1] + \
                        VDC_irr.floor1[2];
    VDC_irr.floor1[2] = VDC_irr.floor1[1];
    VDC_irr.floor1[1] = VDC_irr.floor1[0];

    //---floor 3---//
    VDC_irr.io2[0]    = VDC_irr.io1[1];

    VDC_irr.floor2[0] = VDC_irr.io2[0]*s_input[2] - \
                        VDC_irr.floor2[1]*a_input[4];
    VDC_irr.io2[1]    = VDC_irr.floor2[0] + \
                        VDC_irr.floor2[1];
    VDC_irr.floor2[1] = VDC_irr.floor2[0];

    adcValue.TIDA_VDC_BUS = (VDC_irr.io2[1]-0.434)*569.05;



#endif

    // end conversion adc value
    // start algorithm

    Cla1ForceTask1();



    //
    //  clear the adc interrupt flag so the next SOC can occur
    //  clear the PIEACK bits so another interrupt can be taken
    //


    if (j)
    {
        data_analysis[ez] = adcValue.TIDA_UGRID_A;
        //asm(" ESTOP0");
        data_analysis[ez+800] = pll.theta[0];
        data_analysis[ez+1600] = adcValue.TIDA_IC;
        ez++;
    }


    if(ez >= 800)
    {
        asm(" ESTOP0");

        float gain1, gain2, gain3 ;
        float tb1, tb2, tb3;
        tb1 =0;tb2 = 0;tb3 = 0;
        gain1 = 0; gain2 =0; gain3 = 0;
        int dem;
        for( dem = 0; dem < 800; dem++)
        {
            tb1 += data_analysis[dem];
            tb2 += data_analysis[dem+800];
            tb3 += data_analysis[dem+1600];
        }
        tb1 = tb1/800;
        tb2 = tb2/800;
        tb3 = tb3/800;



        // tinh binh phuong
        for(dem = 0; dem < 800; dem++)
        {
            data_analysis[dem] = data_analysis[dem] - offset1;
            data_analysis[dem] = data_analysis[dem]*data_analysis[dem];

            data_analysis[dem+800] = data_analysis[dem+800] - offset2;
            data_analysis[dem+800] = data_analysis[dem+800]*data_analysis[dem+800];

            data_analysis[dem+1600] = data_analysis[dem+1600] - offset3;
            data_analysis[dem+1600] = data_analysis[dem+1600]*data_analysis[dem+1600];
        }
        for(dem = 0; dem < 800; dem++)
        {
            gain1 += data_analysis[dem];
            gain2 += data_analysis[dem+800];
            gain3 += data_analysis[dem+1600];
        }
        gain1 = sqrt(gain1/800);
        gain2 = sqrt(gain2/800);
        gain3 = sqrt(gain3/800);




    }



    EALLOW;
    if(a)
    {
        GpioDataRegs.GPBSET.bit.GPIO43 = 1;
        GpioDataRegs.GPBSET.bit.GPIO34  = 1;
        GpioDataRegs.GPBSET.bit.GPIO39  = 1;
        GpioDataRegs.GPBSET.bit.GPIO44  = 1;
    }
    else
    {
        GpioDataRegs.GPBCLEAR.bit.GPIO43 = 1;
        GpioDataRegs.GPBCLEAR.bit.GPIO34  = 1;
        GpioDataRegs.GPBCLEAR.bit.GPIO39  = 1;
        GpioDataRegs.GPBCLEAR.bit.GPIO44  = 1;

    }
    EDIS;







    //
    // Clear INT flag for this timer
    //
    EPwm1Regs.ETCLR.bit.INT = 1;

    //
    // Acknowledge this interrupt to receive more interrupts from group 3
    //
    PieCtrlRegs.PIEACK.all = 4;

}
#endif


#endif















//
//end of file
//







