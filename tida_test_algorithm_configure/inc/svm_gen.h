/*
 * svm_gen.h
 *
 *  Created on: Dec 21, 2020
 *      Author: Tinh_deptrai
 *      input : uapha , ubeta, udc ( da chuan hoa)
 *      output: time counter for epwm
 */

#ifndef SVM_GEN_H_
#define SVM_GEN_H_
#include "F2837xD_device.h"        // F2837xD Headerfile Include File







#define TIDA_SVM_QX_CLK_IN                         100000000U // 100MHZ
#define TIDA_SVM_QX_FREQ                           20000U     // 20kHZ
#define TIDA_SVM_QX_PERIOD_COUNT                   (                             \
                                                     TIDA_SVM_QX_CLK_IN/         \
                                                     TIDA_SVM_QX_FREQ   )



extern INPUT_SVM *pinput;
extern SECTOR_SECLECT *psector;
extern TIME_VECTOR *ptime_v;
extern TIME_VECTOR_OUT *ptime_out;
extern EPWM_COUNTER *pepwm_count;





extern int16_t svm_gen(INPUT_SVM *input,
                 SECTOR_SECLECT* csector,
                 TIME_VECTOR *time_vector,
                 TIME_VECTOR_OUT *time_out,
                 EPWM_COUNTER* epwm_counter );


extern int16_t Seclect_sector_subsector(INPUT_SVM *input,
                                  SECTOR_SECLECT* csector);

extern int16_t Calculate_time_vector(INPUT_SVM *input,
                               TIME_VECTOR *time_vector,
                               SECTOR_SECLECT *csector);


extern int16_t Calculate_time_out(SECTOR_SECLECT *csector,
                            TIME_VECTOR *time,
                            TIME_VECTOR_OUT *time_out);

extern uint16_t Assign_ePWM_counter(TIME_VECTOR_OUT *time_out,
                             EPWM_COUNTER *counter);


#endif /* SVM_GEN_H_ */
