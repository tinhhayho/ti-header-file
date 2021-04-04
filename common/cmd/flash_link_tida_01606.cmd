// this file make by Nguyen Trung Tinh 
// for test tida-01606-board
/*	--------note -------------*/


/*
- .usect section will be located in ram or copy from flash to ram
- .sect section will be located in flash 
	special : TI.ramfunc is .sect section but must be run on ram
	
	.text 
	.cinit
	.const
	.reset
	Cla1Prog
	
	
	
	-----------
	
	
	
	.stack
	.init_array
	.bss
	.data
	.Cla1ToCpuMsgRAM
	.CpuToCla1MsgRAM
	.CLAscratch
	.scratchpad
	.const_cla
	.Test_memory


*/



// - this file use compiler 20.xx

// user must be define CLA_C in project 
// because i use cla for calculating 

#ifdef CLA_C
// cratchpad is same stack in c28x
// this size equal 1 bank of ramLS
CLA_SCRATCHPAD_SIZE	= 0x00800;

//--undef_sym = __cla_scratchpad_end
//--undef_sym = __cla_scratchpad_start

#endif

// this section define memory location 


MEMORY 
{
PAGE 0: // this page for program code
	
	/* BEGIN is used for the boot to FLASH -> so we define it
	on the top of FLASHA */
	BEGIN 			: origin = 0x080000,   length = 0x002
	
	RESET			: origin = 0x3FFFC0,   length = 0x002
	
	/* this is for ramfunc */ 
	

	RAMD0			: origin = 0x00B000,   length = 0x00800	
	/* CLA program code is located in LS3-4-5 	*/
	RAMLS3_4_5		: origin = 0x009800,   length = 0x001800
	
	/* C28x code is located in FLASH */
	
	FLASH_C28x		: origin = 0x080002,   length = 0x3FFFE
	
	
PAGE 1: // this page for data 
	
	RAMM1			: origin = 0x000400,   length = 0x0003F8
	RAMD1			: origin = 0x00B800,   length = 0x00800
	
	/* cla data				*/
	RAMLS0			: origin = 0x008000,   length = 0x00800
	RAMLS1			: origin = 0x008800,   length = 0x00800
	RAMLS2			: origin = 0x009000,   length = 0x00800
	
   RAMGS0_1_2_3     : origin = 0x00C000,   length = 0x004000


   EMIF1_CS0n       : origin = 0x80000000, length = 0x10000000
   EMIF1_CS2n       : origin = 0x00100000, length = 0x00200000
   EMIF1_CS3n       : origin = 0x00300000, length = 0x00080000
   EMIF1_CS4n       : origin = 0x00380000, length = 0x00060000
   EMIF2_CS0n       : origin = 0x90000000, length = 0x10000000
   EMIF2_CS2n       : origin = 0x00002000, length = 0x00001000
   
   CLA1_MSGRAMLOW   : origin = 0x001480,   length = 0x000080
   CLA1_MSGRAMHIGH  : origin = 0x001500,   length = 0x000080
	
}

SECTIONS
{
	// this example use EABI 
	
	.text			:> FLASH_C28x		PAGE = 0, ALIGN(8)		
	// tables which initialize global variables
	.cinit			:> FLASH_C28x		PAGE = 0, ALIGN(8)	
	// initialized global variables
	.const			:> FLASH_C28x		PAGE = 0, ALIGN(8)
	// jump tables for switch case
	.switch			:> FLASH_C28x		PAGE = 0, ALIGN(8)
	// table of C++ constructors called at startup
	.init_array		:> FLASH_C28x		PAGE = 0
	.reset			:> RESET			PAGE = 0	, TYPE = DSECT	
	codestart		:> BEGIN			PAGE = 0
	
	
	.stack			:> RAMM1			PAGE = 1
	.bss			:> RAMD1			PAGE = 1
	.bss:output		:> RAMD1			PAGE = 1
	.data			:> RAMD1			PAGE = 1
	.sysmem			:> RAMM1			PAGE = 1


	
   .em2_cs0         : > EMIF2_CS0n, PAGE = 1
   .em2_cs2         : > EMIF2_CS2n, PAGE = 1

	Cla1Prog		: LOAD = FLASH_C28x,
					RUN = RAMLS3_4_5,
					LOAD_START(Cla1ProgLoadStart),
					LOAD_END(Cla1funcsLoadEnd),
					RUN_START(Cla1ProgRunStart),
					LOAD_SIZE(Cla1ProgLoadSize),
					PAGE = 0, ALIGN(8)
					
					
	CLADataLS0		:> RAMLS0, PAGE = 1
	CLADataLS1		:> RAMLS1, PAGE = 1
	CLADataLS2		:> RAMLS2, PAGE = 1
	
	Cla1ToCpuMsgRAM :> CLA1_MSGRAMLOW, PAGE = 1
	CpuToCla1MsgRAM :> CLA1_MSGRAMHIGH, PAGE = 1
	
	/* this is for ramfunc*/
	
	.TI.ramfunc : {}	LOAD = FLASH_C28x,
						RUN  = RAMD0,
						LOAD_START(RamfuncsLoadStart),
						LOAD_SIZE(RamfuncsLoadSize),
						LOAD_END(RamfuncsLoadEnd),
						RUN_START(RamfuncsRunStart),
						RUN_SIZE(RamfuncsRunSize),
						RUN_END(RamfuncsRunEnd),
									PAGE = 0, ALIGN(8)
				
#ifdef CLA_C
	CLAscratch		: 
						{*.obj(CLAscratch)
						. += CLA_SCRATCHPAD_SIZE;
						*.obj(CLAscratch_end) } > RAMLS0, PAGE = 1
						
	.scratchpad		:> RAMLS1, 			PAGE = 1
	.bss_cla		:> RAMLS2, 			PAGE = 1
	.const_cla		:	LOAD = FLASH_C28x,
						RUN  = RAMLS2,
                        RUN_START(_Cla1ConstRunStart),
                        LOAD_START(_Cla1ConstLoadStart),
                        LOAD_SIZE(_Cla1ConstLoadSize),
                        PAGE = 1

#endif
	Test_memory		:> RAMGS0_1_2_3, PAGE = 1

}
































