//#############################################################################
//
// FILE:   tida_01606_adc.c
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


#include "tida_01606_adc.h"




void tida_setupADC(void)
{
    EALLOW;
    //
    //write ADC config and power up the ADC for both ADC 
    // 
    Uint16 i;

    //set prescale
    AdcaRegs.ADCCTL2.bit.PRESCALE = TIDA_ADC_PRESCALE_DIV4;
    AdcbRegs.ADCCTL2.bit.PRESCALE = TIDA_ADC_PRESCALE_DIV4;
    AdccRegs.ADCCTL2.bit.PRESCALE = TIDA_ADC_PRESCALE_DIV4;
    AdcdRegs.ADCCTL2.bit.PRESCALE = TIDA_ADC_PRESCALE_DIV4;

    //set mode : 12 bit, single mode
    AdcSetMode(0, TIDA_ADC_SETMODE_12BIT, TIDA_ADC_SETMODE_SINGLE_ENDED);
    AdcSetMode(1, TIDA_ADC_SETMODE_12BIT, TIDA_ADC_SETMODE_SINGLE_ENDED);
    AdcSetMode(2, TIDA_ADC_SETMODE_12BIT, TIDA_ADC_SETMODE_SINGLE_ENDED);
    AdcSetMode(3, TIDA_ADC_SETMODE_12BIT, TIDA_ADC_SETMODE_SINGLE_ENDED);

    //set pusle interrupt

    
    //power up Sequence
    /*
    // set the bit to enable the desired ADC clock in PCLKCR13
    // set prescale 
    // set power up
    // delay before sampling
    //
    */
    CpuSysRegs.PCLKCR13.bit.ADC_A = 1;
    CpuSysRegs.PCLKCR13.bit.ADC_B = 1;
    CpuSysRegs.PCLKCR13.bit.ADC_C = 1;
    CpuSysRegs.PCLKCR13.bit.ADC_D = 1;

    AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1;
    AdcbRegs.ADCCTL1.bit.ADCPWDNZ = 1;
    AdccRegs.ADCCTL1.bit.ADCPWDNZ = 1;
    AdcdRegs.ADCCTL1.bit.ADCPWDNZ = 1;

    //
    //delay for > 1ms to allow ADC time to power up
    //

    for ( i = 0; i < 60000; i++)
    {
        ;
    }
    

    //setup soc : trigger source, pin, acqps
    //
    // adc a : IA, VINA, VGRIDA
    //
    AdcaRegs.ADCSOC0CTL.bit.TRIGSEL = TIDA_IA_TRIGGER_SOURCE;
    AdcaRegs.ADCSOC0CTL.bit.CHSEL   = TIDA_IA_PIN;
    AdcaRegs.ADCSOC0CTL.bit.ACQPS   = TIDA_IA_ACQPS;

    AdcaRegs.ADCSOC3CTL.bit.TRIGSEL = TIDA_UA_GRID_TRIGGER_SOURCE;
    AdcaRegs.ADCSOC3CTL.bit.CHSEL   = TIDA_UA_GRID_PIN;
    AdcaRegs.ADCSOC3CTL.bit.ACQPS   = TIDA_UA_GRID_ACQPS;

    AdcaRegs.ADCSOC6CTL.bit.TRIGSEL = TIDA_UA_INV_TRIGGER_SOURCE;
    AdcaRegs.ADCSOC6CTL.bit.CHSEL   = TIDA_UA_INV_PIN;
    AdcaRegs.ADCSOC6CTL.bit.ACQPS   = TIDA_UA_INV_ACQPS;
    //
    // adc b : TEMPA, TEMPB, TEMPC, TEMPAMP
    //
    AdcbRegs.ADCSOC10CTL.bit.TRIGSEL = TIDA_TEMPA_TRIGGER_SOURCE;
    AdcbRegs.ADCSOC10CTL.bit.CHSEL   = TIDA_TEMPA_PIN;
    AdcbRegs.ADCSOC10CTL.bit.ACQPS   = TIDA_TEMPA_ACQPS;

    AdcbRegs.ADCSOC11CTL.bit.TRIGSEL = TIDA_TEMPB_TRIGGER_SOURCE;
    AdcbRegs.ADCSOC11CTL.bit.CHSEL   = TIDA_TEMPB_PIN;
    AdcbRegs.ADCSOC11CTL.bit.ACQPS   = TIDA_TEMPB_ACQPS;

    AdcbRegs.ADCSOC12CTL.bit.TRIGSEL = TIDA_TEMPC_TRIGGER_SOURCE;
    AdcbRegs.ADCSOC12CTL.bit.CHSEL   = TIDA_TEMPC_PIN;
    AdcbRegs.ADCSOC12CTL.bit.ACQPS   = TIDA_TEMPC_ACQPS;

    AdcbRegs.ADCSOC13CTL.bit.TRIGSEL = TIDA_TEMPAMP_TRIGGER_SOURCE;
    AdcbRegs.ADCSOC13CTL.bit.CHSEL   = TIDA_TEMPAMP_PIN;
    AdcbRegs.ADCSOC13CTL.bit.ACQPS   = TIDA_TEMPAMP_ACQPS;
    //
    // adc c : IB, VINB, VGRIDB 
    //
    AdccRegs.ADCSOC1CTL.bit.TRIGSEL = TIDA_IB_TRIGGER_SOURCE;
    AdccRegs.ADCSOC1CTL.bit.CHSEL   = TIDA_IB_PIN;
    AdccRegs.ADCSOC1CTL.bit.ACQPS   = TIDA_IB_ACQPS;

    AdccRegs.ADCSOC4CTL.bit.TRIGSEL = TIDA_UB_GRID_TRIGGER_SOURCE;
    AdccRegs.ADCSOC4CTL.bit.CHSEL   = TIDA_UB_GRID_PIN;
    AdccRegs.ADCSOC4CTL.bit.ACQPS   = TIDA_UB_GRID_ACQPS;

    AdccRegs.ADCSOC7CTL.bit.TRIGSEL = TIDA_UB_INV_TRIGGER_SOURCE;
    AdccRegs.ADCSOC7CTL.bit.CHSEL   = TIDA_UB_INV_PIN;
    AdccRegs.ADCSOC7CTL.bit.ACQPS   = TIDA_UB_INV_ACQPS;
    //
    // adc d : IC, VINC, VGRIDC  , VBUS
    //
    AdcdRegs.ADCSOC2CTL.bit.TRIGSEL = TIDA_IC_TRIGGER_SOURCE;
    AdcdRegs.ADCSOC2CTL.bit.CHSEL   = TIDA_IC_PIN;
    AdcdRegs.ADCSOC2CTL.bit.ACQPS   = TIDA_IC_ACQPS;

    AdcdRegs.ADCSOC5CTL.bit.TRIGSEL = TIDA_UC_GRID_TRIGGER_SOURCE;
    AdcdRegs.ADCSOC5CTL.bit.CHSEL   = TIDA_UC_GRID_PIN;
    AdcdRegs.ADCSOC5CTL.bit.ACQPS   = TIDA_UC_GRID_ACQPS;

    AdcdRegs.ADCSOC8CTL.bit.TRIGSEL = TIDA_UC_INV_TRIGGER_SOURCE;
    AdcdRegs.ADCSOC8CTL.bit.CHSEL   = TIDA_UC_INV_PIN;
    AdcdRegs.ADCSOC8CTL.bit.ACQPS   = TIDA_UC_INV_ACQPS;

    (*((volatile Uint32 *)(Uint32)(0x00007580 + 0x22)))    |=  TIDA_VBUS_ACQPS;
//    AdccRegs.ADCSOC9CTL.bit.ACQPS   = TIDA_VBUS_ACQPS;
    AdcdRegs.ADCSOC9CTL.bit.TRIGSEL = TIDA_VBUS_TRIGGER_SOURCE;
    AdcdRegs.ADCSOC9CTL.bit.CHSEL   = TIDA_VBUS_PIN;

    //
    //set interrupt adcd int4
    //
    AdcdRegs.ADCINTSEL3N4.bit.INT4CONT  = TIDA_CON_INT_MODE;
    AdcdRegs.ADCINTSEL3N4.bit.INT4E     = TIDA_ENA_INT;
    AdcdRegs.ADCINTSEL3N4.bit.INT4SEL   = TIDA_INT4_SEL;
    // make sure interrupt flag clear 
    AdcdRegs.ADCINTFLGCLR.bit.ADCINT4   = 1;
    /*
    // pie vector 
    PieVectTable.ADCD4_INT              = &adcIsr1;
    PieCtrlRegs.PIEIER10.bit.INTx16     = 1;
    // cpu level
    IER                                 |= M_INT10;
    */
    EDIS;


}





//
// End of file
//







