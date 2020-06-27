/*********************************************************************************

 Copyright(c) 2012 Analog Devices, Inc. All Rights Reserved.

 This software is proprietary and confidential.  By using this software you agree
 to the terms of the associated Analog Devices License Agreement.

 *********************************************************************************/

/*
*	NAME:     main.c (Block-based Talk through)
*	PURPOSE:  Talk through framework for sending and receiving samples to the AD1835A.
*	USAGE:    This file contains the main routine calls functions to set up the talk through
              routine. It receives an input signal from the ADC via SPORT0A and outputs to
              DAC's via SPORT1A, SPORT1B, SPORT2A, and SPORT2B.
 */

#include "ADDS_21369_EzKit.h"


int main(void)
{

	int count=0;
	/* Initialize managed drivers and/or services at the start of main(). */
	adi_initComponents();

    /*Initialize PLL to run at CCLK= 331.776 MHz & SDCLK= 165.888 MHz.
      SDRAM is setup for use, but cannot be accessed until MSEN bit is enabled*/
    initPLL();
    initExternalMemory();
    /* Setting up IRQ0 and IRQ1*/
    SetupIRQ01() ;

    /* Need to initialize DAI because the sport signals need to be routed*/
    InitSRU();

    /* This function will configure the codec on the kit*/
    Init1835viaSPI();


    adi_int_InstallHandler(ADI_CID_P6I,(ADI_INT_HANDLER_PTR )TalkThroughISR,0,true);

    adi_int_InstallHandler(ADI_CID_IRQ0I,(ADI_INT_HANDLER_PTR )Irq0ISR,0,true);

    adi_int_InstallHandler(ADI_CID_IRQ1I,(ADI_INT_HANDLER_PTR )Irq1ISR,0,true);


    InitSPORT();

    /* Be in infinite loop and do nothing until done.*/

    while(1)
	{

		if(blockReady)
		{
			if(count==10)
					{
						puts("Talkthrough is running successfully");
					}
			processBlock(src_pointer[int_cntr]);
			count++;
		}
	}

}
