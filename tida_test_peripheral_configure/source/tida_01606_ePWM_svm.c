//#############################################################################
//
// FILE:   tida_01606_ePWM_svm.c
//
// TITLE: 
//        
//        
//
//#############################################################################
// $Pelab Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################

#include "tida_01606_ePWM_svm.h"

void tida_setup_ePWM_Q(void)
{

    //
    //setup clock
    //
    CpuSysRegs.PCLKCR2.bit.EPWM1    = 1;    
    CpuSysRegs.PCLKCR2.bit.EPWM2    = 1; 
    CpuSysRegs.PCLKCR2.bit.EPWM3    = 1; 
    CpuSysRegs.PCLKCR2.bit.EPWM4    = 1; 
    CpuSysRegs.PCLKCR2.bit.EPWM7    = 1;
    CpuSysRegs.PCLKCR2.bit.EPWM8    = 1; 
    //
    //setup GPIO
    //
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO0      =  TIDA_EPWM_DIS_PULL_UP;
    GpioCtrlRegs.GPAPUD.bit.GPIO1      =  TIDA_EPWM_DIS_PULL_UP;

    GpioCtrlRegs.GPAMUX1.bit.GPIO0     = TIDA_EPWM_PIN_PWM;
    GpioCtrlRegs.GPAMUX1.bit.GPIO1     = TIDA_EPWM_PIN_PWM;
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO2      =  TIDA_EPWM_DIS_PULL_UP;
    GpioCtrlRegs.GPAPUD.bit.GPIO3      =  TIDA_EPWM_DIS_PULL_UP;

    GpioCtrlRegs.GPAMUX1.bit.GPIO2     = TIDA_EPWM_PIN_PWM;
    GpioCtrlRegs.GPAMUX1.bit.GPIO3     = TIDA_EPWM_PIN_PWM;
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO4      =  TIDA_EPWM_DIS_PULL_UP;
    GpioCtrlRegs.GPAPUD.bit.GPIO5      =  TIDA_EPWM_DIS_PULL_UP;

    GpioCtrlRegs.GPAMUX1.bit.GPIO4     = TIDA_EPWM_PIN_PWM;
    GpioCtrlRegs.GPAMUX1.bit.GPIO5     = TIDA_EPWM_PIN_PWM;
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO6      =  TIDA_EPWM_DIS_PULL_UP;
    GpioCtrlRegs.GPAPUD.bit.GPIO7      =  TIDA_EPWM_DIS_PULL_UP;

    GpioCtrlRegs.GPAMUX1.bit.GPIO6     = TIDA_EPWM_PIN_PWM;
    GpioCtrlRegs.GPAMUX1.bit.GPIO7     = TIDA_EPWM_PIN_PWM;
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO12      =  TIDA_EPWM_DIS_PULL_UP;
    GpioCtrlRegs.GPAPUD.bit.GPIO13      =  TIDA_EPWM_DIS_PULL_UP;

    GpioCtrlRegs.GPAMUX1.bit.GPIO12     = TIDA_EPWM_PIN_PWM;
    GpioCtrlRegs.GPAMUX1.bit.GPIO13     = TIDA_EPWM_PIN_PWM;
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO14      =  TIDA_EPWM_DIS_PULL_UP;
    GpioCtrlRegs.GPAPUD.bit.GPIO15      =  TIDA_EPWM_DIS_PULL_UP;

    GpioCtrlRegs.GPAMUX1.bit.GPIO14     = TIDA_EPWM_PIN_PWM;
    GpioCtrlRegs.GPAMUX1.bit.GPIO15     = TIDA_EPWM_PIN_PWM;
    EDIS;

    tida_epwm_simple(                   \
        TIDA_EPWM_QA1_BASE_ADDRESS,     \
        TIDA_EPWM_QA2_BASE_ADDRESS);   
    //
    // configure PWM1 as master and phase 2 as slaves and
    // let it pass the sync in pulse from PWM1
    //
    // disable phase-shift load

    HWREG(TIDA_EPWM_QA1_BASE_ADDRESS + EPWM_O_TBCTL) |=              \
                            ((TIDA_EPWM_PHASE_DISABLE<<2)           |\
                            (TIDA_EPWM_SYNC_OUT_CTR_ZERO<<4));

    HWREG(TIDA_EPWM_QA2_BASE_ADDRESS + EPWM_O_TBCTL) |=              \
                            ((TIDA_EPWM_PHASE_ENABLE<<2)            |\
                            (TIDA_EPWM_TB_PHASEDIR_UP<<13));
    HWREG(TIDA_EPWM_QA2_BASE_ADDRESS + EPWM_O_TBPHS) = 2 ;
    // socA trigger adc
    tida_epwm_simple_ET(TIDA_EPWM_QA1_BASE_ADDRESS);
    // leg B
    tida_epwm_simple(                   \
        TIDA_EPWM_QB1_BASE_ADDRESS,     \
        TIDA_EPWM_QB2_BASE_ADDRESS);    
    HWREG(TIDA_EPWM_QB1_BASE_ADDRESS + EPWM_O_TBCTL) |=              \
                            ((TIDA_EPWM_PHASE_ENABLE<<2)            |\
                            (TIDA_EPWM_TB_PHASEDIR_UP<<13));
    HWREG(TIDA_EPWM_QB1_BASE_ADDRESS + EPWM_O_TBPHS) = 2 ;
    HWREG(TIDA_EPWM_QB2_BASE_ADDRESS + EPWM_O_TBCTL) |=              \
                            ((TIDA_EPWM_PHASE_ENABLE<<2)            |\
                            (TIDA_EPWM_TB_PHASEDIR_UP<<13));
    HWREG(TIDA_EPWM_QB2_BASE_ADDRESS + EPWM_O_TBPHS) = 2 ;

    // leg C
    tida_epwm_simple(                   \
        TIDA_EPWM_QC1_BASE_ADDRESS,     \
        TIDA_EPWM_QC2_BASE_ADDRESS);

    HWREG(TIDA_EPWM_QC1_BASE_ADDRESS + EPWM_O_TBCTL) |=              \
                            ((TIDA_EPWM_PHASE_ENABLE<<2)            |\
                            (TIDA_EPWM_TB_PHASEDIR_UP<<13));
    HWREG(TIDA_EPWM_QC1_BASE_ADDRESS + EPWM_O_TBPHS) = 2 ;
    HWREG(TIDA_EPWM_QC2_BASE_ADDRESS + EPWM_O_TBCTL) |=              \
                            ((TIDA_EPWM_PHASE_ENABLE<<2)            |\
                            (TIDA_EPWM_TB_PHASEDIR_UP<<13));
    HWREG(TIDA_EPWM_QC2_BASE_ADDRESS + EPWM_O_TBPHS) = 2 ;


}

void tida_SDFM_simple(Uint32 base_address)
{
    tida_epwm_simple_TB(base_address);
    //
    tida_epwm_simple_CC(base_address);

}



void tida_epwm_simple(Uint32 base_address1, Uint32 base_address2)
{
    tida_epwm_simple_TB(base_address1);
    tida_epwm_simple_TB(base_address2);
    //
    tida_epwm_simple_CC(base_address1);
    tida_epwm_simple_CC(base_address2);
    //
    tida_epwm_simple_AQ(base_address1);
    tida_epwm_simple_AQ(base_address2);
    //
    //chu y kenh 2 can dao do cau hinh hardware :'( .....
    //luc lam khong chu y :(((( sorry dan em di sau nha
    //
    tida_epwm_simple_DB_notswap(base_address1);
    tida_epwm_simple_DB_swap(base_address2);

}

void tida_epwm_simple_TB(Uint32 base_address)
{
    //
    //set time base submodule 
    // 
    /*
    signal :
        -Synchronization input : not use
        -Synchronization output: not use
        -CTR = PRD             : not use
        -CTR = Zero            : not use
        -CTR = CMPB            : not use
        -CTR_dir               : not use (counter up = 1 and counter down = 0)
        -CTR_max               : not use
        -TBCLK                 : prescale clock use for all submodule within the ePWM

    time-base period shadow register on
    time-base period = 20khz
    time-base counter = 0 -> reset counter
    time-base phase shift : not configure here
    time-base phase = 0
    set counter mode : count up MODE
    time-base tb clock prescale = divider 1
    */

    HWREGH(base_address + EPWM_O_TBCTL) &=~                           \
                            ((3)                                    |\
                            (1<<3)                                  |\
                            (7<<7)                                  |\
                            (7<<10)) ;                                 


    HWREGH(base_address + EPWM_O_TBCTL) |=                            \
                            ((TIDA_EPWM_COUNTER_UP_DOWN_MODE)       |\
                            (TIDA_EPWM_PRDLD_SHADOW<<3)             |\
                            (TIDA_EPWM_HSPCLK_DIV1<<7)              |\
                            (TIDA_EPWM_TBCLK_PRESACLE_DIV1<<10)) ;                                 
    HWREGH(base_address + EPWM_O_TBPRD)  |=                           \
                            ((TIDA_EPWM_QX_PERIOD_COUNT>>1));
    HWREGH(base_address + EPWM_O_TBCTR) = 0 ; // reset counter
    HWREG(base_address + EPWM_O_TBPHS) = 0 ;
}


void tida_epwm_simple_CC(Uint32 base_address)
{
    //
    //set compare submodule 
    //
    /*
        -CTR = CMPC         : not use
        -CTR = CMPD         : not use
    compare counter A = 0
    compare counter shadow load mode on
    compare counter load when time-base counter equal zero
    */
    HWREGH(base_address + EPWM_O_CMPCTL) |=                                \
                            ((TIDA_EPWM_CMP_LOAD_EVENT_CTR_0_PERIOD))      ;
    HWREG(base_address + EPWM_O_CMPA)   |=                                 \
                            ((TIDA_EPWM_QX_INT_CMP<<16));
    HWREG(base_address + EPWM_O_CMPB)   |=                                 \
                            ((TIDA_EPWM_QX_INT_CMP<<16));
}


void tida_epwm_SDFM_CC(Uint32 base_address)
{
    HWREGH(base_address + EPWM_O_CMPCTL) |=                                \
                            ((TIDA_EPWM_CMP_LOAD_EVENT_CTR_0_PERIOD))      ;
    HWREG(base_address + EPWM_O_CMPC)   |=                                 \
                            ((TIDA_EPWM_QX_INT_CMP<<16));
    HWREG(base_address + EPWM_O_CMPB)   |=                                 \
                            ((TIDA_EPWM_QX_INT_CMP<<16));

}



void tida_epwm_simple_AQ(Uint32 base_address)
{
    //
    //action qualifier submodule
    //
    /*
    input signal :                                      priority( count up mode)
        - TBCLK     : clock for subsystem
        - CTR = PRD : not use                           2
        - CTR = Zero: not use                           7
        - CTR = CMPA: use                               6
        - CTR = CMPB: use                               5
        - CTR_dir   : not use                           not
        - T1        : not use                           3
        - T2        : not use                           4
    CTR = CMPA (up)         -> set high
    CTR = CMPA (down)       -> set low
    CTR = CMPB (up)         -> set low
    CTR = CMPB (down)       -> set high
    */
    HWREGH(base_address + EPWM_O_AQCTLA)    |=                         \
                                        ((TIDA_EPWM_AQ_SET_HIGH<<4)  |\
                                        (TIDA_EPWM_AQ_SET_LOW<<6))    ;
}


void tida_epwm_simple_DB_notswap(Uint32 base_address)
{
    //
    //deadband
    //
    /*
    (phai kich hoat shadowmode cua FED va RED roi xac dinh thoi diem load)
    deadband shadow load when CTR = Zero
    deadband rising edge shadow load when CTR = period
    deadband falling edge shadow load when CTR = Zero
    counter clock = HSPclock
    rising delay = 1us
    falling delay = 1us
    input rising edge = epwmA
    input falling edge = epwmA
    output rising edge = not invert
    output falling edge = invert
        - S4 = 0 and S5 = 0 
        - S8 = 0
        - S2 = 0 and S3 = 1
        - S1 = 1 and S0 = 1 
        - S6 = 0 and S7 = 0
    */
    HWREGH(base_address  + EPWM_O_DBCTL)     |=                  \
                                ((TIDA_EPWM_DB_OUTPUT_FULL_EN)  |\
                                (TIDA_EPWM_DB_POLARITY_AHC<<2)  |\
                                (TIDA_EPWM_DB_IN_MODE_EPWMA<<4) |\
                                (TIDA_EPWM_DB_LOAD_CTR_ZERO<<6) |\
                                (TIDA_EPWM_DB_LOAD_CTR_ZERO<<8) |\
                                (TIDA_EPWM_DB_LOAD_SHADOW<<10)  |\
                                (TIDA_EPWM_DB_LOAD_SHADOW<<11)  |\
                                (TIDA_EPWM_DB_OUTSWAP_NO<<12)   |\
                                (TIDA_EPWM_DB_DEDB_MODE_NORMAL<<14));
    HWREGH(base_address  + EPWM_O_DBRED)     |=                   \
                                (TIDA_EPWM_QX_DB_COUNT);
    HWREGH(base_address  + EPWM_O_DBFED)     |=                   \
                                (TIDA_EPWM_QX_DB_COUNT);
}



void tida_epwm_simple_DB_swap(Uint32 base_address)
{
    //
    //deadband
    //
    /*
    (phai kich hoat shadowmode cua FED va RED roi xac dinh thoi diem load)
    deadband shadow load when CTR = Zero
    deadband rising edge shadow load when CTR = period
    deadband falling edge shadow load when CTR = Zero
    counter clock = HSPclock
    rising delay = 1us
    falling delay = 1us
    input rising edge = epwmA
    input falling edge = epwmA
    output rising edge = not invert
    output falling edge = invert
        - S4 = 0 and S5 = 0 
        - S8 = 0
        - S2 = 0 and S3 = 1
        - S1 = 1 and S0 = 1 
        - S6 = 1 and S7 = 1
    */
    HWREGH(base_address + EPWM_O_DBCTL)     |=                    \
                                ((TIDA_EPWM_DB_OUTPUT_FULL_EN)  |\
                                (TIDA_EPWM_DB_POLARITY_AHC<<2)  |\
                                (TIDA_EPWM_DB_IN_MODE_EPWMA<<4) |\
                                (TIDA_EPWM_DB_LOAD_CTR_ZERO<<6) |\
                                (TIDA_EPWM_DB_LOAD_CTR_ZERO<<8) |\
                                (TIDA_EPWM_DB_LOAD_SHADOW<<10)  |\
                                (TIDA_EPWM_DB_LOAD_SHADOW<<11)  |\
                                (TIDA_EPWM_DB_OUTSWAP_FULL<<12) |\
                                (TIDA_EPWM_DB_DEDB_MODE_NORMAL<<14));
    HWREGH(base_address + EPWM_O_DBRED)     |=                    \
                                (TIDA_EPWM_QX_DB_COUNT);
    HWREGH(base_address + EPWM_O_DBFED)     |=                    \
                                (TIDA_EPWM_QX_DB_COUNT);
}


// this function configure for ADC_trigger
void tida_epwm_simple_ET(Uint32 base_address)
{
    HWREGH(base_address + EPWM_O_ETSEL)     |=                      \
                                ((TIDA_EPWM_ET_SOCA_CTR_PRD<<8)   |\
                                (TIDA_EPWM_ET_SOCA_ENA<<11));
    HWREGH(base_address + EPWM_O_ETPS)      |=                      \
                                (TIDA_EPWM_ET_SOCA_PRESCALE<<8);
    #ifdef _TEST_SPEED_
    HWREGH(base_address  + EPWM_O_ETSEL)     |=                      \
                                ((TIDA_EPWM_ET_INTEN_ENA<<3)       |\
                                (TIDA_EPWM_ET_INTSEL_CTR_ZERO));
    HWREGH(base_address + EPWM_O_ETPS)      |=                      \
                                (1);
    #endif
}




//
// End of file
//




