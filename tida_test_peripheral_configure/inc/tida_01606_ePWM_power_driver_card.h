//#############################################################################
//
// FILE:   tida_01606_ePWM_power_driver_card.h
//
// TITLE: configure epwm for driver transformer
//        
//        
//
//#############################################################################
// $Pelab Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################

#ifndef _TIDA_01606_EPWM_POWER_DRIVER_CARD_H_
#define _TIDA_01606_EPWM_POWER_DRIVER_CARD_H_
#include "F2837xD_device.h"        // F2837xD Headerfile Include File

#define TIDA_POWER_EPWM_FREQ            100000000U // 200MHZ
#define TIDA_POWER_FREQ                 500000U    // 500khz
#define TIDA_POWER_PERIOD               (Uint16)(1/TIDA_POWER_FREQ)
#define TIDA_POWER_EPWM_PERIOD_COUNTER  (Uint16)(TIDA_POWER_EPWM_FREQ/TIDA_POWER_FREQ)
#define TIDA_POWER_DEADBAND_US          0.5
#define TIDA_POWER_DB_COUNT             (Uint16)(                  \
                                        (float)TIDA_POWER_EPWM_FREQ*\
                                        (float)TIDA_POWER_DEADBAND_US*\
                                        0.000001f    )

#define TIDA_POWER_EPWM_BASE_ADD        0x00004500U


//
//gpio parameter
//
#define TIDA_POWER_DIS_PULL_UP          1
#define TIDA_POWER_ENA_PULL_UP          0
#define TIDA_POWER_PIN_PWM              1




//
//ePWM parameter
//
#define TIDA_POWER_TBCLK_PRESACLE_DIV1      0
#define TIDA_POWER_HSPCLK_DIV1              0
#define TIDA_POWER_PRDLD_SHADOW             0
#define TIDA_POWER_COUNTER_UP_MODE          0
#define TIDA_POWER_PHASE_DISABLE            0
#define TIDA_POWER_PHASE_COUNTER            0

#define TIDA_POWER_CMP_LOAD_SHADOW_MODE     0
#define TIDA_POWER_CMP_LOAD_EVENT_CTR_ZERO  0


#define TIDA_POWER_AQ_DO_NOTHING            0
#define TIDA_POWER_AQ_SET_LOW               1
#define TIDA_POWER_AQ_SET_HIGH              2
#define TIDA_POWER_AQ_SET_TOGGLE            3


#define TIDA_POWER_DB_OUTPUT_FULL_EN        3
#define TIDA_POWER_DB_POLARITY_AHC          2
#define TIDA_POWER_DB_IN_MODE_EPWMA         0
#define TIDA_POWER_DB_LOAD_ON_ZERO          0
#define TIDA_POWER_DB_LOAD_SHADOW           1
#define TIDA_POWER_DB_LOAD_CTR_ZERO         0
#define TIDA_POWER_DB_LOAD_CTR_PERIOD       1
#define TIDA_POWER_DB_OUTSWAP_NO            0
#define TIDA_POWER_DB_DEDB_MODE_NORMAL      0







//
//function prototype
//
void tida_setup_ePWM_power(void);



#endif



//
// End of file
//




