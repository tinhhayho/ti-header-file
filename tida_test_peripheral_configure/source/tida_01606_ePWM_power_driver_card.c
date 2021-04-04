//#############################################################################
//
// FILE:   tida_01606_ePWM_power_driver_card.c
//
// TITLE: version 1
//        please contact tinhhayho@gmail.com for further information
//        
//
//#############################################################################
// $Pelab Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################

#include "tida_01606_ePWM_power_driver_card.h"



void tida_setup_ePWM_power(void)
{
    //
    //setup clock
    //
    CpuSysRegs.PCLKCR2.bit.EPWM6    = 1;


    //
    //setup  gpio 10 and 11 -> pin 61 and 63 in control card
    //
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO10      =  TIDA_POWER_DIS_PULL_UP;
    GpioCtrlRegs.GPAPUD.bit.GPIO11      =  TIDA_POWER_DIS_PULL_UP;

    GpioCtrlRegs.GPAMUX1.bit.GPIO10     = TIDA_POWER_PIN_PWM;
    GpioCtrlRegs.GPAMUX1.bit.GPIO11     = TIDA_POWER_PIN_PWM;
    EDIS;

    //
    //set time base submodule 
    // 
    /*
    signal :
        -syschronization input : not use
        -syschronization output: not use
        -CTR = PRD             : not use
        -CTR = Zero            : not use
        -CTR = CMPB            : not use
        -CTR_dir               : not use
        -CTR_max               : not use
        -TBCLK                 : prescale clock use for all submodule within the ePWM

    time-base period shadow register on
    time-base period = 500mhz
    time-base counter = 0 -> reset counter
    time-base phase shift disable
    time-base phase = 0
    set counter mode : count up MODE
    time-base tb clock prescale = divider 1
    */
    EPwm6Regs.TBCTL.bit.PRDLD   = TIDA_POWER_PRDLD_SHADOW;
    EPwm6Regs.TBPRD             = TIDA_POWER_EPWM_PERIOD_COUNTER;
    EPwm6Regs.TBCTR             = 0;
    EPwm6Regs.TBCTL.bit.PHSEN   = TIDA_POWER_PHASE_DISABLE;
    EPwm6Regs.TBPHS.bit.TBPHS   = TIDA_POWER_PHASE_COUNTER;
    EPwm6Regs.TBCTL.bit.CTRMODE = TIDA_POWER_COUNTER_UP_MODE;
    EPwm6Regs.TBCTL.bit.CLKDIV  = TIDA_POWER_TBCLK_PRESACLE_DIV1;
    EPwm6Regs.TBCTL.bit.HSPCLKDIV = TIDA_POWER_HSPCLK_DIV1;

    //
    //set compare submodule 
    //
    /*
        -CTR = CMPC         : not use
        -CTR = CMPD         : not use
    compare counter A = period/2
    compare counter shadow load mode on
    compare counter load when time-base counter equal zero
    */

    EPwm6Regs.CMPCTL.bit.SHDWAMODE = TIDA_POWER_CMP_LOAD_SHADOW_MODE;
    EPwm6Regs.CMPCTL.bit.SHDWBMODE = TIDA_POWER_CMP_LOAD_SHADOW_MODE;
    EPwm6Regs.CMPCTL.bit.LOADAMODE = TIDA_POWER_CMP_LOAD_EVENT_CTR_ZERO;
    EPwm6Regs.CMPCTL.bit.LOADBMODE = TIDA_POWER_CMP_LOAD_EVENT_CTR_ZERO;

    EPwm6Regs.CMPA.bit.CMPA        = TIDA_POWER_EPWM_PERIOD_COUNTER>>1;
    EPwm6Regs.CMPB.bit.CMPB        = TIDA_POWER_EPWM_PERIOD_COUNTER>>1;


    //
    //action qualifier submodule
    //
    /*
    input signal :                                      priority( count up mode)
        - TBCLK     : clock for subsystem
        - CTR = PRD : not use                           2
        - CTR = Zero: not use                           7
        - CTR = CMPA: use                               6
        - CTR = CMPB: not use                           5
        - CTR_dir   : not use                           not
        - T1        : not use                           3
        - T2        : not use                           4
    CTR = Zero              -> set output high
    CTR = CMPA ( count up)  -> set output low
    use only outputA but configure both
    */
    EPwm6Regs.AQCTLA.bit.ZRO = TIDA_POWER_AQ_SET_HIGH;
    EPwm6Regs.AQCTLA.bit.CAU = TIDA_POWER_AQ_SET_LOW;

    EPwm6Regs.AQCTLB.bit.ZRO = TIDA_POWER_AQ_SET_HIGH;
    EPwm6Regs.AQCTLB.bit.CAU = TIDA_POWER_AQ_SET_LOW;
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
    EPwm6Regs.DBCTL.bit.OUT_MODE            = TIDA_POWER_DB_OUTPUT_FULL_EN;     //S1 AND S0
    EPwm6Regs.DBCTL.bit.POLSEL              = TIDA_POWER_DB_POLARITY_AHC;       //S3 AND S2
    EPwm6Regs.DBCTL.bit.IN_MODE             = TIDA_POWER_DB_IN_MODE_EPWMA;      //S5 AND S4
    EPwm6Regs.DBCTL.bit.OUTSWAP             = TIDA_POWER_DB_OUTSWAP_NO;         //S7 AND S6
    EPwm6Regs.DBCTL.bit.DEDB_MODE           = TIDA_POWER_DB_DEDB_MODE_NORMAL;   //S8



    EPwm6Regs.DBCTL.bit.SHDWDBFEDMODE       = TIDA_POWER_DB_LOAD_SHADOW;
    EPwm6Regs.DBCTL.bit.SHDWDBREDMODE       = TIDA_POWER_DB_LOAD_SHADOW;
    EPwm6Regs.DBCTL.bit.LOADFEDMODE         = TIDA_POWER_DB_LOAD_CTR_ZERO;
    EPwm6Regs.DBCTL.bit.LOADREDMODE         = TIDA_POWER_DB_LOAD_CTR_PERIOD;


    EPwm6Regs.DBRED.bit.DBRED               = TIDA_POWER_DB_COUNT;
    EPwm6Regs.DBFED.bit.DBFED               = TIDA_POWER_DB_COUNT;




    //
    //choper : nothing to configure
    //




    //
    //tripzone : option ..... :'( so tired
    //
}



//
// End of file
//






