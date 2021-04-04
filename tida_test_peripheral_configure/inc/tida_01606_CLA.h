//#############################################################################
//
// FILE:   tida_01606_CLA.h
//
// TITLE: configure adc subsystem for tida 01606 board
//        
//        
//
//#############################################################################
// $Pelab Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################

#ifndef _TIDA_01606_CLA_H_
#define _TIDA_01606_CLA_H_
#include "F2837xD_device.h"        // F2837xD Headerfile Include File


#include "F2837xD_Cla_defines.h"
#include "CLAmath.h"

#include "svm_gen.h"




typedef struct {
    float Ua_input;
    float Ub_input;
    float B0;
    float B1;
    float fre_normal;
    float fre_pll;
    float Ts;
    float ylf0;
    float ylf1;
    float vd_pll;
    float vq_pll;
    float vq_pll_1;
    float theta;
    float theta_1;

}PLL_var;

typedef struct {
    float i_inv_alpha;
    float i_inv_beta;

    //
    float v_inv_alpha;
    float v_inv_beta;

    //
    float v_grid_alpha;
    float v_grid_beta;

}CLARKE_var;

typedef struct {
    float id_inv;
    float iq_inv;
    //
    float vd_inv;
    float vq_inv;
}PARK_var;



typedef struct {
    float eid[2];
    float eiq[2];
    float pid[2];
    float piq[2];
    float id_star;
    float iq_star;
    float vd_star;
    float vq_star;
}CURRENT_LOOP_var;

typedef struct {
    float floor0[3];
    float floor1[3];
    float floor2[2];
    float io0[2];
    float io1[2];
    float io2[2];
}IIR_5_order;

typedef struct {
    float u[3];
    float osg_u[3];
    float osg_qu[3];
}SOGI_;

typedef struct {
    float u_Q[2];
    float u_D[2];
    float input_alpha;
    float input_beta;
    float ylf[2];
    float fo;
    float theta[2];
}PLL;


#define buffer_size             2400 //2^12






//
//variable in C28x
//
extern float Xn;
extern CLA_ADC_VALUE adcValue;
extern float UA;
extern float UB;
extern float Vddd;
extern float Vqqq;

extern float angle;
extern float set_point;
extern float set_point2;

extern Uint32 ez;
extern Uint32 j;
extern float data_analysis[buffer_size];
extern PLL pll;

//
// function prototype
//
extern void configCLAMemory(void);
extern void initCPU1CLA1(void);
extern void initCLA1PIE(void);




extern __interrupt void cla1Isr1();
extern __interrupt void cla1Isr2();
extern __interrupt void cla1Isr3();
extern __interrupt void cla1Isr4();
extern __interrupt void cla1Isr5();
extern __interrupt void cla1Isr6();
extern __interrupt void cla1Isr7();
extern __interrupt void cla1Isr8();

extern __interrupt void epwm1ISR();


extern __attribute__((interrupt)) void Cla1Task1(void);
extern __attribute__((interrupt)) void Cla1Task2(void);
extern __attribute__((interrupt)) void Cla1Task3(void);
extern __attribute__((interrupt)) void Cla1Task4(void);
extern __attribute__((interrupt)) void Cla1Task5(void);
extern __attribute__((interrupt)) void Cla1Task6(void);
extern __attribute__((interrupt)) void Cla1Task7(void);
extern __attribute__((interrupt)) void Cla1Task8(void);





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
//defualt Ref value to hardware
//
#define TIDA_VREF_HIGH_ 3.265f
#define TIDA_VREF_LOW_  0

#define TIDA_ADCA_RESULT_BASE_ADDRESS       0x0B00
#define TIDA_ADCB_RESULT_BASE_ADDRESS       0x0B20
#define TIDA_ADCC_RESULT_BASE_ADDRESS       0x0B40
#define TIDA_ADCD_RESULT_BASE_ADDRESS       0x0B60




//----------------
#define RESULT_IA                 (float)(AdcaResultRegs.ADCRESULT0*TIDA_VREF_HIGH_/4096)
#define RESULT_VGRID_A            (float)(AdcaResultRegs.ADCRESULT3*TIDA_VREF_HIGH_/4096)
#define RESULT_VINV_A             (float)(AdcaResultRegs.ADCRESULT6*TIDA_VREF_HIGH_/4096)

#define RESULT_IB                 (float)(AdccResultRegs.ADCRESULT1*TIDA_VREF_HIGH_/4096)
#define RESULT_VGRID_B            (float)(AdccResultRegs.ADCRESULT4*TIDA_VREF_HIGH_/4096)
#define RESULT_VINV_B             (float)(AdccResultRegs.ADCRESULT7*TIDA_VREF_HIGH_/4096)


#define RESULT_IC                 (float)(AdcdResultRegs.ADCRESULT2*TIDA_VREF_HIGH_/4096)
#define RESULT_VGRID_C            (float)(AdcdResultRegs.ADCRESULT5*TIDA_VREF_HIGH_/4096)
#define RESULT_VINV_C             (float)(AdcdResultRegs.ADCRESULT8*TIDA_VREF_HIGH_/4096)

#define RESULT_VBUS               (float)(AdcdResultRegs.ADCRESULT9*TIDA_VREF_HIGH_/4096)

#define RESULT_TEMPA              (float)(AdcbResultRegs.ADCRESULT10*TIDA_VREF_HIGH_/4096)
#define RESULT_TEMPB              (float)(AdcbResultRegs.ADCRESULT11*TIDA_VREF_HIGH_/4096)
#define RESULT_TEMPC              (float)(AdcbResultRegs.ADCRESULT12*TIDA_VREF_HIGH_/4096)
#define RESULT_TEMPAMB            (float)(AdcbResultRegs.ADCRESULT13*TIDA_VREF_HIGH_/4096)




#endif



//
// End of file
//




