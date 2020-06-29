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
#include "audio_processing.h"

/* Place the audio processing algorithm here. The input and output are given
 as unsigned integer pointers.*/

int Block_Left[NUM_SAMPLES/2] ;
int Block_Right[NUM_SAMPLES/2] ;
double xm1 = 0;

unsigned int y[NUM_SAMPLES/2];

double simplp (unsigned int *x, unsigned int *y,
               int M, double xm1)
{
  int n;
  y[0] = x[0] + xm1;
  for (n=1; n < M ; n++) {
    y[n] =  x[n]  + x[n-1];
//    y[n] = 0;
  }
  return x[M-1];
}

 void processBlock(unsigned int *block_ptr)
{
    int i,j;
    float temp_out;


    /*Clear the Block Ready Semaphore*/
    blockReady = 0;

    /*Set the Processing Active Semaphore before starting processing*/
    isProcessing = 1;

//	for(i=0, j=0;i<NUM_SAMPLES;i+=2)
//	{
//		audio_processing(block_ptr+i, 0);
//	}

	for(i=0, j=0;i<NUM_SAMPLES;i+=2)
	{
		int res=reverb(*(block_ptr+i)<<8, *(block_ptr+i+1)<<8);
		*(block_ptr+i)=res>>8;
		*(block_ptr+i+1)=res>>8;
	}





//	for(i=0, j=0;i<NUM_SAMPLES;i+=2)
//	{
//		//simplp(block_ptr+i, y, NUM_SAMPLES/2, xml);
//		//audio_processing(block_ptr+i, 0);
//		//*(block_ptr+i) = *(block_ptr+i) ;  //User can add their code here to process the data
//	}

//
//    for(i=0, j=0;i<NUM_SAMPLES;i++)
//    {
//    	Block_Left[j]=*(block_ptr+i)<<8;
//    	i++;
//    	Block_Right[j]=*(block_ptr+i);
//    	j++;
//
//    	//*(block_ptr+i) =  *(block_ptr+i) ;  //User can add their code here to process the data
//    }
////    for(i=0;i<NUM_SAMPLES/2;i++)
////    {
////    	Block_Right[i]=0;
////    }
//        for(i=0;i<NUM_SAMPLES/2;i++)
//        {
//        	Block_Left[i]/=2;
//        }
//    // xm1=simplp(Block_Left, y, (NUM_SAMPLES/2), xm1);
//    for(i=0, j=0;i<NUM_SAMPLES;i++)
//    {
//    	*(block_ptr+i) =Block_Left[j]>>8;
//    	i++;
//    	*(block_ptr+i) =Block_Right[j];
//    	j++;
//    }


    /*Clear the Processing Active Semaphore after processing is complete*/
    isProcessing = 0;
}
