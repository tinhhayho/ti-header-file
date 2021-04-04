//#############################################################################
//
// FILE:   main.h
//
// TITLE: define parameter of tida board
//        
//        
//
//#############################################################################
// $Pelab Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################

#ifndef _MAIN_H_
#define _MAIN_H_

#include "F2837xD_device.h"
#include "tida_01606_adc.h"
#include "tida_01606_ePWM_power_driver_card.h"
#include "tida_01606_protection.h"
#include "tida_01606_Relay_Fan_control.h"
#include "tida_01606_ePWM_svm.h"
#include "tida_01606_CLA.h"
#include "tida_01606_SDFM.h"





//
//Define frequency subsystem
//

#define TIDA_CPU_SYS_CLOCK (200000000) // 200MHZ
#define TIDA_PWMSYSCLOCK_FREQ (100000000) //100MHZ
#define TIDA_ECAPSYSCLOCK_FREQ (200000000) // 200MHZ

//
//PROCEDURE FOR START ALGORITHM
//

//
//equal 0 for no check and 1 for check 
//
#define TIDA_CHECK_UNDER_VOLTAGE_COND 0
#define TIDA_UNDER_VOLTAGE 50 
#define TIDA_CHECK_OVER_VOLTAGE_COND 0
#define TIDA_OVER_VOLTAGE 800

//
//check grid side 
//
#define TIDA_GRID_FREQ 50 // HZ
#define TIDA_GRID_MAX_VOLTAGE 400



//
//MODE1     open loop space vector modulation
//MODE2     close loop space vector modulation
//
//





//
// variable
//
extern tida_01606_protection_state *pstate;
extern tida_01606_protection_value *pvalue;



//
//function prototype
//
extern void InitSysCtrl(void);                      //sysctrl.c
extern void InitPieCtrl(void);                      //PieCtrl.c
extern void InitPieVectTable(void);                 //PieVect.c
extern void DisablePeripheralClocks(void);          //Sysctrl.c
extern void InitGpio(void);                         //Gpio.c


#endif



//
// End of file
//





