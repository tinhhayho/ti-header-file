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

#ifndef _TIDA_01606_PROTECTION_H_
#define _TIDA_01606_PROTECTION_H_
#include "F2837xD_device.h"        // F2837xD Headerfile Include File

#define TIDA_LED1           31
#define TIDA_LED2           34
#define TIDA_LED1_SET       1
#define TIDA_LED2_SET       1
#define TIDA_LED1_CLEAR     1
#define TIDA_LED2_CLEAR     1


#define TIDA_RDY            26
#define TIDA_RST            27






#define TIDA_PRO_DIS_PULL_UP_RES        1
#define TIDA_PRO_ENA_PULL_UP_RES        0
#define TIDA_PRO_INPUT_SYS              0
#define TIDA_PRO_INPUT_ASYS             3
#define TIDA_PRO_PIN_GPIO               0
#define TIDA_PRO_PIN_INPUT              0
#define TIDA_PRO_PIN_OUTPUT             1



























void Power_card_protect(void);



#endif



//
// End of file
//


