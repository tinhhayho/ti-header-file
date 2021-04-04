//#############################################################################
//
// FILE:   tida_01606_Relay_Fan_control.c
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


#include "tida_01606_Relay_Fan_control.h"




void tida_setup_relay(void)
{

    EALLOW;
    //
    // configure Relay A - active high - GPIO34
    //


    GpioCtrlRegs.GPBPUD.bit.GPIO34  = TIDA_REL_ENA_PULL_UP_RES;
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = TIDA_REL_PIN_GPIO;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO34= TIDA_REL_INPUT_SYS;
    GpioCtrlRegs.GPBDIR.bit.GPIO34  = TIDA_REL_PIN_OUTPUT;

    GpioDataRegs.GPBSET.bit.GPIO34  = 0;
    GpioDataRegs.GPBSET.bit.GPIO39  = 0;
    GpioDataRegs.GPBSET.bit.GPIO44  = 0;
    //
    // configure Relay B - active high - GPIO39
    //
    GpioCtrlRegs.GPBPUD.bit.GPIO39  = TIDA_REL_ENA_PULL_UP_RES;
    GpioCtrlRegs.GPBMUX1.bit.GPIO39 = TIDA_REL_PIN_GPIO;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO39= TIDA_REL_INPUT_SYS;
    GpioCtrlRegs.GPBDIR.bit.GPIO39  = TIDA_REL_PIN_OUTPUT;

    GpioDataRegs.GPBSET.bit.GPIO39  = 0;


    //
    // configure Relay C - active high - GPIO44
    //
    GpioCtrlRegs.GPBPUD.bit.GPIO44  = TIDA_REL_ENA_PULL_UP_RES;
    GpioCtrlRegs.GPBMUX1.bit.GPIO44 = TIDA_REL_PIN_GPIO;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO44= TIDA_REL_INPUT_SYS;
    GpioCtrlRegs.GPBDIR.bit.GPIO44  = TIDA_REL_PIN_OUTPUT;

    GpioDataRegs.GPBSET.bit.GPIO44  = 0;





    //
    // configure Relay N - active high - GPIO45
    //
    GpioCtrlRegs.GPBPUD.bit.GPIO45  = TIDA_REL_ENA_PULL_UP_RES;
    GpioCtrlRegs.GPBMUX1.bit.GPIO45 = TIDA_REL_PIN_GPIO;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO45= TIDA_REL_INPUT_SYS;
    GpioCtrlRegs.GPBDIR.bit.GPIO45  = TIDA_REL_PIN_OUTPUT;

    GpioDataRegs.GPBSET.bit.GPIO45  = 0;


    EDIS;



}


//
// End of file
//







