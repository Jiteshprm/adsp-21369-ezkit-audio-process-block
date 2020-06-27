/*********************************************************************************

 Copyright(c) 2012 Analog Devices, Inc. All Rights Reserved.

 This software is proprietary and confidential.  By using this software you agree
 to the terms of the associated Analog Devices License Agreement.

 *********************************************************************************/

/*
 * NAME:     blockProcess.c (Block-based Talk-through)
 * PURPOSE:  Process incoming AD1835 ADC data and prepare outgoing blocks for DAC.
 * USAGE:    This file contains the subroutines that float and fix the serial data,
         	 and copy from the inputs to the outputs.
 */
#include "ADDS_21369_EzKit.h"

/* Place the audio processing algorithm here. The input and output are given
 as unsigned integer pointers.*/

 void processBlock(unsigned int *block_ptr)
{
    int i;
    float temp_out;

    /*Clear the Block Ready Semaphore*/
    blockReady = 0;

    /*Set the Processing Active Semaphore before starting processing*/
    isProcessing = 1;

    /* for(i=0;i<NUM_SAMPLES;i++)
    {
       *(block_ptr+i) =  *(block_ptr+i);  //User can add their code here to process the data
    }*/

    /*Clear the Processing Active Semaphore after processing is complete*/
    isProcessing = 0;
}
