/*********************************************************************************

 Copyright(c) 2012 Analog Devices, Inc. All Rights Reserved.

 This software is proprietary and confidential.  By using this software you agree
 to the terms of the associated Analog Devices License Agreement.

 *********************************************************************************/

/*
	NAME:     SPORTisr.c (Block-based Talk-through)
	PURPOSE:  Talk-through framework for sending and receiving samples to the AD1835.
	USAGE:    This file contains SPORT0 Interrupt Service Routine. Three buffers are used
			  for this example. One is filled by the ADC, another is sent to the DAC, and
			  the final buffer is processed. Each buffer rotates between these functions
			  upon each SP0 interrupt received.*/

/*
   Here is the mapping between the SPORTS and the DACS
   ADC -> DSP  : SPORT0A : I2S
   DSP -> DAC1 : SPORT1A : I2S
   DSP -> DAC2 : SPORT1B : I2S
   DSP -> DAC3 : SPORT2A : I2S
   DSP -> DAC4 : SPORT2B : I2S
*/

#include "ADDS_21369_EzKit.h"
#include <stdio.h>

extern unsigned int Block_A[NUM_SAMPLES] ;
extern unsigned int Block_B[NUM_SAMPLES] ;
extern unsigned int Block_C[NUM_SAMPLES] ;



/*Pointer to the blocks*/

 unsigned int *src_pointer[3] = {Block_A,
                                Block_C,
                                Block_B};

/* Counter to choose which buffer to process*/
volatile int int_cntr=2;

/* Semaphore to indicate to main that a block is ready for processing*/
volatile int blockReady=0;

/* Semaphore to indicate to the ISR that the processing has not completed before the
     buffer will be overwritten.*/
volatile int isProcessing=0;

/*If the processing takes too long, the program will be stuck in this infinite loop.*/
void ProcessingTooLong(void)
{
    while(1)
    {
    	NOP();
    }
}

void TalkThroughISR(uint32_t iid, void *handlerarg) /* No argument is passed in this ISR */
{
    if(isProcessing)
        ProcessingTooLong();

    /*Increment the block pointer*/
    int_cntr++;
    int_cntr %= 3;

    blockReady = 1;

}
