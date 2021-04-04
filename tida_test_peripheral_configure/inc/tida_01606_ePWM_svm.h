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

#ifndef _TIDA_01606_EPWM_SVM_H_
#define _TIDA_01606_EPWM_SVM_H_
#include "F2837xD_device.h"        // F2837xD Headerfile Include File


//
//pointer cho thanh ghi
//
#define HWREGH(x)                          \
        (*((volatile Uint16 *)(Uint32)(x)))
#define HWREG(x)                            \
        (*((volatile Uint32 *)(Uint32)(x)))


#define TIDA_EPWM_QA1_BASE_ADDRESS                  0x00004000U
#define TIDA_EPWM_QA2_BASE_ADDRESS                  0x00004100U                  
#define TIDA_EPWM_QB1_BASE_ADDRESS                  0x00004200U
#define TIDA_EPWM_QB2_BASE_ADDRESS                  0x00004300U
#define TIDA_EPWM_QC1_BASE_ADDRESS                  0x00004600U
#define TIDA_EPWM_QC2_BASE_ADDRESS                  0x00004700U


#define TIDA_CPU_SYS_REGS                           0x0005D300U      

#define TIDA_EPWM_QX_CLK_IN                         100000000U // 100MHZ
#define TIDA_EPWM_QX_FREQ                           20000U     // 20kHZ
#define TIDA_EPWM_QX_PERIOD_COUNT                   (Uint16)(                     \
                                                     TIDA_EPWM_QX_CLK_IN/         \
                                                     TIDA_EPWM_QX_FREQ   )


#define TIDA_EPWM_QX_DB_US                           1U
#define TIDA_EPWM_QX_DB_COUNT                       (Uint16)(                            \
                                                    (float)TIDA_EPWM_QX_DB_US*          \
                                                    (float)TIDA_EPWM_QX_CLK_IN*         \
                                                     0.000001f   )


#define TIDA_EPWM_QX_INT_CMP                        (Uint32)1000 // for test

#define TIDA_SDFM_CLK                           20000000U
#define TIDA_EPWM_SDFM_PERIOD                   (Uint32)TIDA_EPWM_QX_CLK_IN/            \
                                                TIDA_SDFM_CLK
//
//gpio parameter
//
#define TIDA_EPWM_DIS_PULL_UP          1
#define TIDA_EPWM_ENA_PULL_UP          0
#define TIDA_EPWM_PIN_PWM              1


//
//ePWM parameter
//
#define TIDA_EPWM_TB_PHASEDIR_UP		   1
#define TIDA_EPWM_TB_PHASEDIR_DOWN		   0
#define TIDA_EPWM_TBCLK_PRESACLE_DIV1      0
#define TIDA_EPWM_HSPCLK_DIV1              0
#define TIDA_EPWM_PRDLD_SHADOW             0
#define TIDA_EPWM_COUNTER_UP_MODE          0
#define TIDA_EPWM_COUNTER_UP_DOWN_MODE     2
#define TIDA_EPWM_PHASE_DISABLE            0
#define TIDA_EPWM_PHASE_ENABLE			   1
#define TIDA_EPWM_PHASE_COUNTER            0
#define TIDA_EPWM_SYNC_OUT_CTR_ZERO		   1
#define TIDA_EPWM_SYSN_OUT_EQUAL_IN		   0	// reset value

#define TIDA_EPWM_CMP_LOAD_SHADOW_MODE     0
#define TIDA_EPWM_CMP_LOAD_EVENT_CTR_ZERO  0
#define TIDA_EPWM_CMP_LOAD_EVENT_CTR_PERIOD	1
#define TIDA_EPWM_CMP_LOAD_EVENT_CTR_0_PERIOD 2


#define TIDA_EPWM_AQ_DO_NOTHING            0
#define TIDA_EPWM_AQ_SET_LOW               1
#define TIDA_EPWM_AQ_SET_HIGH              2
#define TIDA_EPWM_AQ_SET_TOGGLE            3


#define TIDA_EPWM_DB_OUTPUT_FULL_EN        3
#define TIDA_EPWM_DB_POLARITY_AHC          2
#define TIDA_EPWM_DB_IN_MODE_EPWMA         0
#define TIDA_EPWM_DB_LOAD_ON_ZERO          0
#define TIDA_EPWM_DB_LOAD_SHADOW           1
#define TIDA_EPWM_DB_LOAD_CTR_ZERO         0
#define TIDA_EPWM_DB_LOAD_CTR_PERIOD       1
#define TIDA_EPWM_DB_OUTSWAP_NO            0
#define TIDA_EPWM_DB_OUTSWAP_FULL          3
#define TIDA_EPWM_DB_DEDB_MODE_NORMAL      0

#define TIDA_EPWM_ET_SOCA_ENA              1
#define TIDA_EPWM_ET_SOCA_CTR_ZERO         1
#define TIDA_EPWM_ET_SOCA_CTR_PRD          2
#define TIDA_EPWM_ET_SOCA_PRESCALE         1
#define TIDA_EPWM_ET_INTEN_ENA             1
#define TIDA_EPWM_ET_INTTE_DIS             0
#define TIDA_EPWM_ET_INTSEL_CTR_ZERO       1



//*****************************************************************************
//
// The following are defines for the EPWM register offsets
//
//*****************************************************************************
#define EPWM_O_TBCTL              0x0U         // Time Base Control Register
#define EPWM_O_TBCTL2             0x1U         // Time Base Control Register 2
#define EPWM_O_TBCTR              0x4U         // Time Base Counter Register
#define EPWM_O_TBSTS              0x5U         // Time Base Status Register
#define EPWM_O_CMPCTL             0x8U         // Counter Compare Control
                                               // Register
#define EPWM_O_CMPCTL2            0x9U         // Counter Compare Control
                                               // Register 2
#define EPWM_O_DBCTL              0xCU         // Dead-Band Generator Control
                                               // Register
#define EPWM_O_DBCTL2             0xDU         // Dead-Band Generator Control
                                               // Register 2
#define EPWM_O_AQCTL              0x10U        // Action Qualifier Control
                                               // Register
#define EPWM_O_AQTSRCSEL          0x11U        // Action Qualifier Trigger
                                               // Event Source Select Register
#define EPWM_O_PCCTL              0x14U        // PWM Chopper Control Register
#define EPWM_O_VCAPCTL            0x18U        // Valley Capture Control
                                               // Register
#define EPWM_O_VCNTCFG            0x19U        // Valley Counter Config
                                               // Register
#define EPWM_O_TRREM              0x2EU        // Translator High Resolution
                                               // Remainder Register
#define EPWM_O_GLDCTL             0x34U        // Global PWM Load Control
                                               // Register
#define EPWM_O_GLDCFG             0x35U        // Global PWM Load Config
                                               // Register
#define EPWM_O_XLINK              0x38U        // EPWMx Link Register
#define EPWM_O_AQCTLA             0x40U        // Action Qualifier Control
                                               // Register For Output A
#define EPWM_O_AQCTLA2            0x41U        // Additional Action Qualifier
                                               // Control Register For Output A
#define EPWM_O_AQCTLB             0x42U        // Action Qualifier Control
                                               // Register For Output B
#define EPWM_O_AQCTLB2            0x43U        // Additional Action Qualifier
                                               // Control Register For Output B
#define EPWM_O_AQSFRC             0x47U        // Action Qualifier Software
                                               // Force Register
#define EPWM_O_AQCSFRC            0x49U        // Action Qualifier Continuous
                                               // S/W Force Register
#define EPWM_O_DBRED              0x51U        // Dead-Band Generator Rising
                                               // Edge Delay High Resolution
                                               // Mirror Register
#define EPWM_O_DBFED              0x53U        // Dead-Band Generator Falling
                                               // Edge Delay Count Register
#define EPWM_O_TBPHS              0x60U        // Time Base Phase High
#define EPWM_O_TBPRD              0x63U        // Time Base Period Register
#define EPWM_O_CMPA               0x6AU        // Counter Compare A Register
#define EPWM_O_CMPB               0x6CU        // Compare B Register
#define EPWM_O_CMPC               0x6FU        // Counter Compare C Register
#define EPWM_O_CMPD               0x71U        // Counter Compare D Register
#define EPWM_O_GLDCTL2            0x74U        // Global PWM Load Control
                                               // Register 2
#define EPWM_O_SWVDELVAL          0x77U        // Software Valley Mode Delay
                                               // Register
#define EPWM_O_TZSEL              0x80U        // Trip Zone Select Register
#define EPWM_O_TZDCSEL            0x82U        // Trip Zone Digital Comparator
                                               // Select Register
#define EPWM_O_TZCTL              0x84U        // Trip Zone Control Register
#define EPWM_O_TZCTL2             0x85U        // Additional Trip Zone Control
                                               // Register
#define EPWM_O_TZCTLDCA           0x86U        // Trip Zone Control Register
                                               // Digital Compare A
#define EPWM_O_TZCTLDCB           0x87U        // Trip Zone Control Register
                                               // Digital Compare B
#define EPWM_O_TZEINT             0x8DU        // Trip Zone Enable Interrupt
                                               // Register
#define EPWM_O_TZFLG              0x93U        // Trip Zone Flag Register
#define EPWM_O_TZCBCFLG           0x94U        // Trip Zone CBC Flag Register
#define EPWM_O_TZOSTFLG           0x95U        // Trip Zone OST Flag Register
#define EPWM_O_TZCLR              0x97U        // Trip Zone Clear Register
#define EPWM_O_TZCBCCLR           0x98U        // Trip Zone CBC Clear Register
#define EPWM_O_TZOSTCLR           0x99U        // Trip Zone OST Clear Register
#define EPWM_O_TZFRC              0x9BU        // Trip Zone Force Register
#define EPWM_O_ETSEL              0xA4U        // Event Trigger Selection
                                               // Register
#define EPWM_O_ETPS               0xA6U        // Event Trigger Pre-Scale
                                               // Register
#define EPWM_O_ETFLG              0xA8U        // Event Trigger Flag Register
#define EPWM_O_ETCLR              0xAAU        // Event Trigger Clear Register
#define EPWM_O_ETFRC              0xACU        // Event Trigger Force Register
#define EPWM_O_ETINTPS            0xAEU        // Event-Trigger Interrupt
                                               // Pre-Scale Register
#define EPWM_O_ETSOCPS            0xB0U        // Event-Trigger SOC Pre-Scale
                                               // Register
#define EPWM_O_ETCNTINITCTL       0xB2U        // Event-Trigger Counter
                                               // Initialization Control Register
#define EPWM_O_ETCNTINIT          0xB4U        // Event-Trigger Counter
                                               // Initialization Register
#define EPWM_O_DCTRIPSEL          0xC0U        // Digital Compare Trip Select
                                               // Register
#define EPWM_O_DCACTL             0xC3U        // Digital Compare A Control
                                               // Register
#define EPWM_O_DCBCTL             0xC4U        // Digital Compare B Control
                                               // Register
#define EPWM_O_DCFCTL             0xC7U        // Digital Compare Filter
                                               // Control Register
#define EPWM_O_DCCAPCTL           0xC8U        // Digital Compare Capture
                                               // Control Register
#define EPWM_O_DCFOFFSET          0xC9U        // Digital Compare Filter Offset
                                               // Register
#define EPWM_O_DCFOFFSETCNT       0xCAU        // Digital Compare Filter Offset
                                               // Counter Register
#define EPWM_O_DCFWINDOW          0xCBU        // Digital Compare Filter Window
                                               // Register
#define EPWM_O_DCFWINDOWCNT       0xCCU        // Digital Compare Filter Window
                                               // Counter Register
#define EPWM_O_DCCAP              0xCFU        // Digital Compare Counter
                                               // Capture Register
#define EPWM_O_DCAHTRIPSEL        0xD2U        // Digital Compare AH Trip
                                               // Select
#define EPWM_O_DCALTRIPSEL        0xD3U        // Digital Compare AL Trip
                                               // Select
#define EPWM_O_DCBHTRIPSEL        0xD4U        // Digital Compare BH Trip
                                               // Select
#define EPWM_O_DCBLTRIPSEL        0xD5U        // Digital Compare BL Trip
                                               // Select
#define EPWM_O_HWVDELVAL          0xFDU        // Hardware Valley Mode Delay
                                               // Register
#define EPWM_O_VCNTVAL            0xFEU        // Hardware Valley Counter
                                               // Register


//*************************************************************************************************
//
// The following are defines for the SYSCTL register offsets
//
//*************************************************************************************************
#define SYSCTL_O_DEVCFGLOCK1   0x0U     // Lock bit for CPUSELx registers
#define SYSCTL_O_PARTIDL       0x8U     // Lower 32-bit of Device PART Identification Number
#define SYSCTL_O_PARTIDH       0xAU     // Upper 32-bit of Device PART Identification Number
#define SYSCTL_O_REVID         0xCU     // Device Revision Number
#define SYSCTL_O_DC0           0x10U    // Device Capability: Device Information
#define SYSCTL_O_DC1           0x12U    // Device Capability: Processing Block Customization
#define SYSCTL_O_DC2           0x14U    // Device Capability: EMIF Customization
#define SYSCTL_O_DC3           0x16U    // Device Capability: Peripheral Customization
#define SYSCTL_O_DC4           0x18U    // Device Capability: Peripheral Customization
#define SYSCTL_O_DC5           0x1AU    // Device Capability: Peripheral Customization
#define SYSCTL_O_DC6           0x1CU    // Device Capability: Peripheral Customization
#define SYSCTL_O_DC7           0x1EU    // Device Capability: Peripheral Customization
#define SYSCTL_O_DC8           0x20U    // Device Capability: Peripheral Customization
#define SYSCTL_O_DC9           0x22U    // Device Capability: Peripheral Customization
#define SYSCTL_O_DC10          0x24U    // Device Capability: Peripheral Customization
#define SYSCTL_O_DC11          0x26U    // Device Capability: Peripheral Customization
#define SYSCTL_O_DC12          0x28U    // Device Capability: Peripheral Customization
#define SYSCTL_O_DC13          0x2AU    // Device Capability: Peripheral Customization
#define SYSCTL_O_DC14          0x2CU    // Device Capability: Analog Modules Customization
#define SYSCTL_O_DC15          0x2EU    // Device Capability: Analog Modules Customization
#define SYSCTL_O_DC17          0x32U    // Device Capability: Analog Modules Customization
#define SYSCTL_O_DC18          0x34U    // Device Capability: CPU1 Lx SRAM Customization
#define SYSCTL_O_DC19          0x36U    // Device Capability: CPU2 Lx SRAM Customization
#define SYSCTL_O_DC20          0x38U    // Device Capability: GSx SRAM Customization
#define SYSCTL_O_PERCNF1       0x60U    // Peripheral Configuration register
#define SYSCTL_O_FUSEERR       0x74U    // e-Fuse error Status register
#define SYSCTL_O_SOFTPRES0     0x82U    // Processing Block Software Reset register
#define SYSCTL_O_SOFTPRES1     0x84U    // EMIF Software Reset register
#define SYSCTL_O_SOFTPRES2     0x86U    // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES3     0x88U    // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES4     0x8AU    // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES6     0x8EU    // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES7     0x90U    // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES8     0x92U    // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES9     0x94U    // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES11    0x98U    // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES13    0x9CU    // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES14    0x9EU    // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES16    0xA2U    // Peripheral Software Reset register
#define SYSCTL_O_CPUSEL0       0xD6U    // CPU Select register for common peripherals
#define SYSCTL_O_CPUSEL1       0xD8U    // CPU Select register for common peripherals
#define SYSCTL_O_CPUSEL2       0xDAU    // CPU Select register for common peripherals
#define SYSCTL_O_CPUSEL4       0xDEU    // CPU Select register for common peripherals
#define SYSCTL_O_CPUSEL5       0xE0U    // CPU Select register for common peripherals
#define SYSCTL_O_CPUSEL6       0xE2U    // CPU Select register for common peripherals
#define SYSCTL_O_CPUSEL7       0xE4U    // CPU Select register for common peripherals
#define SYSCTL_O_CPUSEL8       0xE6U    // CPU Select register for common peripherals
#define SYSCTL_O_CPUSEL9       0xE8U    // CPU Select register for common peripherals
#define SYSCTL_O_CPUSEL11      0xECU    // CPU Select register for common peripherals
#define SYSCTL_O_CPUSEL12      0xEEU    // CPU Select register for common peripherals
#define SYSCTL_O_CPUSEL14      0xF2U    // CPU Select register for common peripherals
#define SYSCTL_O_CPU2RESCTL    0x122U   // CPU2 Reset Control Register
#define SYSCTL_O_RSTSTAT       0x124U   // Reset Status register for secondary C28x CPUs
#define SYSCTL_O_LPMSTAT       0x125U   // LPM Status Register for secondary C28x CPUs
#define SYSCTL_O_SYSDBGCTL     0x12CU   // System Debug Control register

#define SYSCTL_O_CLKSEM          0x0U    // Clock Control Semaphore Register
#define SYSCTL_O_CLKCFGLOCK1     0x2U    // Lock bit for CLKCFG registers
#define SYSCTL_O_CLKSRCCTL1      0x8U    // Clock Source Control register-1
#define SYSCTL_O_CLKSRCCTL2      0xAU    // Clock Source Control register-2
#define SYSCTL_O_CLKSRCCTL3      0xCU    // Clock Source Control register-3
#define SYSCTL_O_SYSPLLCTL1      0xEU    // SYSPLL Control register-1
#define SYSCTL_O_SYSPLLMULT      0x14U   // SYSPLL Multiplier register
#define SYSCTL_O_SYSPLLSTS       0x16U   // SYSPLL Status register
#define SYSCTL_O_AUXPLLCTL1      0x18U   // AUXPLL Control register-1
#define SYSCTL_O_AUXPLLMULT      0x1EU   // AUXPLL Multiplier register
#define SYSCTL_O_AUXPLLSTS       0x20U   // AUXPLL Status register
#define SYSCTL_O_SYSCLKDIVSEL    0x22U   // System Clock Divider Select register
#define SYSCTL_O_AUXCLKDIVSEL    0x24U   // Auxillary Clock Divider Select register
#define SYSCTL_O_PERCLKDIVSEL    0x26U   // Peripheral Clock Divider Selet register
#define SYSCTL_O_XCLKOUTDIVSEL   0x28U   // XCLKOUT Divider Select register
#define SYSCTL_O_LOSPCP          0x2CU   // Low Speed Clock Source Prescalar
#define SYSCTL_O_MCDCR           0x2EU   // Missing Clock Detect Control Register
#define SYSCTL_O_X1CNT           0x30U   // 10-bit Counter on X1 Clock

#define SYSCTL_O_CPUSYSLOCK1     0x0U    // Lock bit for CPUSYS registers
#define SYSCTL_O_HIBBOOTMODE     0x6U    // HIB Boot Mode Register
#define SYSCTL_O_IORESTOREADDR   0x8U    // IORestore() routine Address Register
#define SYSCTL_O_PIEVERRADDR     0xAU    // PIE Vector Fetch Error Address register
#define SYSCTL_O_PCLKCR0         0x22U   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR1         0x24U   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR2         0x26U   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR3         0x28U   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR4         0x2AU   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR6         0x2EU   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR7         0x30U   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR8         0x32U   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR9         0x34U   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR10        0x36U   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR11        0x38U   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR12        0x3AU   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR13        0x3CU   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR14        0x3EU   // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR16        0x42U   // Peripheral Clock Gating Registers
#define SYSCTL_O_SECMSEL         0x74U   // Secondary Master Select register for common
                                         // peripherals: Selects between CLA & DMA
#define SYSCTL_O_LPMCR           0x76U   // LPM Control Register
#define SYSCTL_O_GPIOLPMSEL0     0x78U   // GPIO LPM Wakeup select registers
#define SYSCTL_O_GPIOLPMSEL1     0x7AU   // GPIO LPM Wakeup select registers
#define SYSCTL_O_TMR2CLKCTL      0x7CU   // Timer2 Clock Measurement functionality control register
#define SYSCTL_O_RESC            0x80U   // Reset Cause register

#define SYSCTL_O_SCSR     0x22U   // System Control & Status Register
#define SYSCTL_O_WDCNTR   0x23U   // Watchdog Counter Register
#define SYSCTL_O_WDKEY    0x25U   // Watchdog Reset Key Register
#define SYSCTL_O_WDCR     0x29U   // Watchdog Control Register
#define SYSCTL_O_WDWCR    0x2AU   // Watchdog Windowed Control Register

#define SYSCTL_O_CLA1TASKSRCSELLOCK   0x0U    // CLA1 Task Trigger Source Select Lock Register
#define SYSCTL_O_DMACHSRCSELLOCK      0x4U    // DMA Channel Triger Source Select Lock Register
#define SYSCTL_O_CLA1TASKSRCSEL1      0x6U    // CLA1 Task Trigger Source Select Register-1
#define SYSCTL_O_CLA1TASKSRCSEL2      0x8U    // CLA1 Task Trigger Source Select Register-2
#define SYSCTL_O_DMACHSRCSEL1         0x16U   // DMA Channel Trigger Source Select Register-1
#define SYSCTL_O_DMACHSRCSEL2         0x18U   // DMA Channel Trigger Source Select Register-2

#define SYSCTL_O_SYNCSELECT        0x0U   // Sync Input and Output Select Register
#define SYSCTL_O_ADCSOCOUTSELECT   0x2U   // External ADC (Off Chip) SOC Select Register
#define SYSCTL_O_SYNCSOCLOCK       0x4U   // SYNCSEL and EXTADCSOC Select Lock register





//
//function prototype
//


void tida_epwm_simple_TB(Uint32 base_address);
void tida_epwm_simple_CC(Uint32 base_address);
void tida_epwm_simple_AQ(Uint32 base_address);
void tida_epwm_simple_DB_notswap(Uint32 base_address);
void tida_epwm_simple_DB_swap(Uint32 base_address);
void tida_epwm_simple(Uint32 base_address1, Uint32 base_address2);
void tida_epwm_simple_ET(Uint32 base_address);
void tida_setup_ePWM_Q(void);

#endif



//
// End of file
//



