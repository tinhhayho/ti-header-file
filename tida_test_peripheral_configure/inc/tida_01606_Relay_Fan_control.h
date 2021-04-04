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

#ifndef _TIDA_01606_RELAY_FAN_CONTROL_H_
#define _TIDA_01606_RELAY_FAN_CONTROL_H_
#include "F2837xD_device.h"        // F2837xD Headerfile Include File










#define TIDA_REL_DIS_PULL_UP_RES        1
#define TIDA_REL_ENA_PULL_UP_RES        0
#define TIDA_REL_INPUT_SYS              0
#define TIDA_REL_INPUT_ASYS             3
#define TIDA_REL_PIN_GPIO               0
#define TIDA_REL_PIN_INPUT              0
#define TIDA_REL_PIN_OUTPUT             1




//
//  function prototype
//



void tida_setup_relay(void);


#endif



//
// End of file
//



