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

#ifndef _TIDA_01606_ADC_H_
#define _TIDA_01606_ADC_H_
#include "F2837xD_device.h"        // F2837xD Headerfile Include File
//
//no gpio are configured 
//
#define TIDA_VREF_HIGH 3.255f
#define TIDA_VREF_LOW  0


//
//ADC reading default calibrations
//
#define TIDA_CURRENT_OFFSET 1.7f
#define TIDA_CURRENT_SCALE  1.5f
#define TIDA_VOLTAGE_OFFSET 1.65f
#define TIDA_VOLTAGE_SCALE  -0.6f
#define TIDA_VBUS_SCALE     0.706f

//adc base address

#define TIDA_ADCA_ADDRESS   0x00007400
#define TIDA_ADCB_ADDRESS   0x00007480
#define TIDA_ADCC_ADDRESS   0x00007500
#define TIDA_ADCD_ADDRESS   0x00007580


// prescale 
#define TIDA_ADC_PRESCALE_DIV4              6
#define TIDA_ADC_SETMODE_12BIT              0
#define TIDA_ADC_SETMODE_SINGLE_ENDED       0
#define TIDA_ADC_PULSE_END_CONV             1


// SOC FOR EACH SENSOR


#define TIDA_IA_SOC_NO                      0
#define TIDA_IB_SOC_NO                      1
#define TIDA_IC_SOC_NO                      2

#define TIDA_UA_INV_SOC_NO                  3
#define TIDA_UB_INV_SOC_NO                  4
#define TIDA_UC_INV_SOC_NO                  5


#define TIDA_UA_GRID_SOC_NO                 6
#define TIDA_UB_GRID_SOC_NO                 7
#define TIDA_UC_GRID_SOC_NO                 8

#define TIDA_VBUS                           9

#define TIDA_TEMPA                          10
#define TIDA_TEMPB                          11
#define TIDA_TEMPC                          12
#define TIDA_TEMPAMP                        13

// TRIGGER SOURCE----> ePWM1 socA
#define TIDA_IA_TRIGGER_SOURCE              5
#define TIDA_IB_TRIGGER_SOURCE              5
#define TIDA_IC_TRIGGER_SOURCE              5

#define TIDA_UA_INV_TRIGGER_SOURCE          5
#define TIDA_UB_INV_TRIGGER_SOURCE          5
#define TIDA_UC_INV_TRIGGER_SOURCE          5

#define TIDA_UA_GRID_TRIGGER_SOURCE         5
#define TIDA_UB_GRID_TRIGGER_SOURCE         5
#define TIDA_UC_GRID_TRIGGER_SOURCE         5

#define TIDA_VBUS_TRIGGER_SOURCE            5

#define TIDA_TEMPA_TRIGGER_SOURCE           5
#define TIDA_TEMPB_TRIGGER_SOURCE           5
#define TIDA_TEMPC_TRIGGER_SOURCE           5
#define TIDA_TEMPAMP_TRIGGER_SOURCE         5

//PARTICULAR PIN 
#define TIDA_IA_PIN                         14       
#define TIDA_IB_PIN                         4
#define TIDA_IC_PIN                         2

#define TIDA_UA_INV_PIN                     4
#define TIDA_UB_INV_PIN                     3
#define TIDA_UC_INV_PIN                     1

#define TIDA_UA_GRID_PIN                    2
#define TIDA_UB_GRID_PIN                    2
#define TIDA_UC_GRID_PIN                    0

#define TIDA_VBUS_PIN                       5

#define TIDA_TEMPA_PIN                      0
#define TIDA_TEMPB_PIN                      1
#define TIDA_TEMPC_PIN                      2
#define TIDA_TEMPAMP_PIN                    3



#define TIDA_IA_ACQPS                       74
#define TIDA_IB_ACQPS                       74
#define TIDA_IC_ACQPS                       74

#define TIDA_UA_INV_ACQPS                   74
#define TIDA_UB_INV_ACQPS                   74
#define TIDA_UC_INV_ACQPS                   74

#define TIDA_UA_GRID_ACQPS                  74
#define TIDA_UB_GRID_ACQPS                  74
#define TIDA_UC_GRID_ACQPS                  74

#define TIDA_VBUS_ACQPS                     108

#define TIDA_TEMPA_ACQPS                    99
#define TIDA_TEMPB_ACQPS                    99
#define TIDA_TEMPC_ACQPS                    99
#define TIDA_TEMPAMP_ACQPS                  99



#define TIDA_CON_INT_MODE                   1
#define TIDA_ENA_INT                        1
#define TIDA_INT4_SEL                       9


//
//read adc result
//

/*
#define RESULT_IA                 (float)(AdcaResultRegs.ADCRESULT0*TIDA_VREF_HIGH/4096)
#define RESULT_VGRID_A            (float)(AdcaResultRegs.ADCRESULT3*TIDA_VREF_HIGH/4096)
#define RESULT_VINV_A             (float)(AdcaResultRegs.ADCRESULT6*TIDA_VREF_HIGH/4096)

#define RESULT_IB                 (float)(AdccResultRegs.ADCRESULT1*TIDA_VREF_HIGH/4096)
#define RESULT_VGRID_B            (float)(AdccResultRegs.ADCRESULT4*TIDA_VREF_HIGH/4096)
#define RESULT_VINV_B             (float)(AdccResultRegs.ADCRESULT7*TIDA_VREF_HIGH/4096)


#define RESULT_IC                 (float)(AdcdResultRegs.ADCRESULT2*TIDA_VREF_HIGH/4096)
#define RESULT_VGRID_C            (float)(AdcdResultRegs.ADCRESULT5*TIDA_VREF_HIGH/4096)
#define RESULT_VINV_C             (float)(AdcdResultRegs.ADCRESULT8*TIDA_VREF_HIGH/4096)

#define RESULT_VBUS               (float)(AdcdResultRegs.ADCRESULT9*TIDA_VREF_HIGH/4096)

#define RESULT_TEMPA              (float)(AdcbResultRegs.ADCRESULT10*TIDA_VREF_HIGH/4096)
#define RESULT_TEMPB              (float)(AdcbResultRegs.ADCRESULT11*TIDA_VREF_HIGH/4096)
#define RESULT_TEMPC              (float)(AdcbResultRegs.ADCRESULT12*TIDA_VREF_HIGH/4096)
#define RESULT_TEMPAMB            (float)(AdcbResultRegs.ADCRESULT13*TIDA_VREF_HIGH/4096)

*/


//
//prototype function
//
extern void AdcSetMode(Uint16 adc, Uint16 resolution, Uint16 signalmode);


extern __interrupt void adcIsr1();


void tida_setupADC(void);




#endif



//
// End of file
//



