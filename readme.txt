 Analog Devices, Inc. CrossCore(R) Embedded Studio Application Example
 
	Example:  Block_Based_Talkthrough
	Target:   ADSP-21369
	Hardware: ADSP-21369 EZ-KIT LITE

Description :

    This project contains a talkthrough example using the onboard AD1835A to acquire
	and output an audio stream. The digital audio data is available for processing
	in the file SPORTisr.c. The block size is 1024 samples.

	The AD1835A is set up with a 48 Khz Sampling rate.  The ADC is connected to
	SPORT 0A. DAC1 is connected to SPORT 1A, DAC2 to SPORT 1B, DAC3 to SPORT2A, 
	and DAC4 (Headphone output) to SPORT2B. All channels of the codec are accessed
	in I2S mode. See initSRU.c for the details of which DAI pins are used to access 
	the codec.
	
Instructions: 
    
	Apply an input signal to J10 on the ADSP-21369 EZ-KIT LITE, and
    attach an output device to the selected channel of J5.

Required Switch Settings: 
    
    SW3 - 1=Off, 2=On, 3=On, 4=On (this is the default setting)

Source Files contained in this directory:
    
	init1835viaSPI.c     ADSP-21369 source - SPI Subroutines
	initSRU.c            Set up the SRU to connect to the AD1835
	main.c               Main section to call setup routines
	initSPORT.c          Initialize the SPORT DMA to communicate with the AD1835
	initPLL_SDRAM.c      Configures the DSP Core clock
	IRQprocess.c         Set up and process IRQ0 and IRQ1 (Push Button) interrupts
	SPORTisr.c           Process SPORT 0 interrupts
	blockProcess.c       Process the audio data in the current block
	ad1835.h             Macro Definitions for AD1835 registers
	ADDS_21369_EzKit.h   Includes and external declarations used for all files

			
NOTE:  		If the application is halted within the CCES, the executable should 
      		be reloaded to the target to ensure proper operation.

Reference:	ADSP-213xx Hardware Reference Manual
			ADSP-21369 EZ-Kit lite Manual
		
(c) 2012 Analog Devices, Inc.  All rights reserved.

