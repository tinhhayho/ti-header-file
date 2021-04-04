//#############################################################################
//
// FILE:   tida_01606_adc.h
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

#ifndef _TIDA_01606_SDFM_H_
#define _TIDA_01606_SDFM_H_
#include "F2837xD_device.h"        // F2837xD Headerfile Include File


#define SDCLK           20000000U
#define SYSCLK          200000000U
#define ECAP_PERIOD     (Uint16)(SYSCLK/SDCLK)

#define OUTPUT_ECAP     3
#define OUTPUT_ENABLE   1

#define GPIO_DIS_PULL_UP    1
#define GPIO_OUTPUT_MODE    1
#define GPIO_OUTPUT_xBar    1
#define ECAP_APWM_ENABLE    1



 int16_t tida_01606_eCap_setup_for_SDFM();
 int16_t tida_01606_ePWM11_setup_for_SDFM();
int16_t tida_01606_GPIO_setup_for_SDFM();
 int16_t tida_01606_SDFM_setup_input_control();
 int16_t tida_01606_SDFM_setup_sinc_filter();






#endif



//
// End of file
//





