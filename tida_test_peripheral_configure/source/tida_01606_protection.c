//#############################################################################
//
// FILE:   tida_01606_protection.c
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



#include "tida_01606_protection.h"


tida_01606_protection_state Protect_state;
tida_01606_protection_value Protect_value;
tida_01606_protection_state *pstate_protect = &Protect_state;
tida_01606_protection_value *pvalue_protect = &Protect_value;


// gate drive control GPIO

void Power_card_protect(void)
{
    EALLOW;
    //
    // configure RDY - power ready - GPIO26
    // input mode, disable pull-up resistor
    //
    /*
        - set pull-up resistor
        - peripheral muxing chooce
        - input qualification
        - if I/O is GPIO -> select input or output
    */
    GpioCtrlRegs.GPAPUD.bit.GPIO26  = TIDA_PRO_DIS_PULL_UP_RES;
    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = TIDA_PRO_PIN_GPIO;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO26= TIDA_PRO_INPUT_SYS;
    GpioCtrlRegs.GPADIR.bit.GPIO26  = TIDA_PRO_PIN_INPUT;

    //
    // configure RST - reset pin - active low - GPIO27
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO27  = TIDA_PRO_ENA_PULL_UP_RES;
    GpioCtrlRegs.GPAMUX2.bit.GPIO27 = TIDA_PRO_PIN_GPIO;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO27= TIDA_PRO_INPUT_SYS;
    GpioCtrlRegs.GPADIR.bit.GPIO27  = TIDA_PRO_PIN_OUTPUT;
    GpioDataRegs.GPASET.bit.GPIO27  = 1;
    //
    // configure FLTA- fault pin - active low - GPIO 32
    //
    GpioCtrlRegs.GPBPUD.bit.GPIO32  = TIDA_PRO_DIS_PULL_UP_RES;
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = TIDA_PRO_PIN_GPIO;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO32= TIDA_PRO_INPUT_SYS;
    GpioCtrlRegs.GPBDIR.bit.GPIO32  = TIDA_PRO_PIN_INPUT;

    //
    // configure FLTB - fault pin - active low - GPIO 33
    //
    GpioCtrlRegs.GPBPUD.bit.GPIO33  = TIDA_PRO_DIS_PULL_UP_RES;
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = TIDA_PRO_PIN_GPIO;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO33= TIDA_PRO_INPUT_SYS;
    GpioCtrlRegs.GPBDIR.bit.GPIO33  = TIDA_PRO_PIN_INPUT;


    //
    // configure FLTC - fault pin - active low - GPIO 40
    //
    GpioCtrlRegs.GPBPUD.bit.GPIO40  = TIDA_PRO_DIS_PULL_UP_RES;
    GpioCtrlRegs.GPBMUX1.bit.GPIO40 = TIDA_PRO_PIN_GPIO;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO40= TIDA_PRO_INPUT_SYS;
    GpioCtrlRegs.GPBDIR.bit.GPIO40  = TIDA_PRO_PIN_INPUT;



    //
    // configure ENA - enable pwm buffer - active high - GPIO43
    //

    GpioCtrlRegs.GPBPUD.bit.GPIO43  = TIDA_PRO_ENA_PULL_UP_RES;
    GpioCtrlRegs.GPBMUX1.bit.GPIO43 = TIDA_PRO_PIN_GPIO;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO43= TIDA_PRO_INPUT_SYS;
    GpioCtrlRegs.GPBDIR.bit.GPIO43  = TIDA_PRO_PIN_OUTPUT;
    GpioDataRegs.GPBSET.bit.GPIO43  = 1;

    #ifdef _TEST_SPEED_

    //
    // configure TEST time executive
    //
    GpioCtrlRegs.GPBPUD.bit.GPIO35  = TIDA_PRO_ENA_PULL_UP_RES;
    GpioCtrlRegs.GPBMUX1.bit.GPIO35 = TIDA_PRO_PIN_GPIO;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO35= TIDA_PRO_INPUT_SYS;
    GpioCtrlRegs.GPBDIR.bit.GPIO35  = TIDA_PRO_PIN_OUTPUT;
    GpioDataRegs.GPBSET.bit.GPIO35  = 1;
    #endif
    EDIS;

}


//
// End of file



//





