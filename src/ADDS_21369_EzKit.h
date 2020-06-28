/*********************************************************************************

 Copyright(c) 2012 Analog Devices, Inc. All Rights Reserved.

 This software is proprietary and confidential.  By using this software you agree
 to the terms of the associated Analog Devices License Agreement.

 *********************************************************************************/
/*
*NAME:   ADDS_21469_EzKit.h
*PURPOSE:  Header file with definitions use in the C-based talkthrough examples
*/

#ifndef __ADDS_21369_EZKIT_H__
#define __ADDS_21369_EZKIT_H__

/* include files */
#include <stdio.h>     /* Get declaration of puts and definition of NULL. */
#include <stdint.h>    /* Get definition of uint32_t. */
#include <assert.h>    /* Get the definition of support for standard C asserts. */
#include <builtins.h>  /* Get definitions of compiler built-in functions */
#include <platform_include.h>      /* System and IOP register bit and address definitions. */
#include <processor_include.h>	   /* Get definitions of the part being built*/
#include <services/int/adi_int.h>  /* Interrupt Handler API header. */
#include "adi_initialize.h"
#include <sru.h>
#include "ad1835.h"
#include<sysreg.h>

/* Block Size per Audio Channel*/
#define NUM_SAMPLES 1024
#define PCI 0x00080000

#define OFFSET_MASK 0x7FFFF

/* Function prototypes for this talkthrough code */

extern void initPLL(void);
extern void initExternalMemory(void);
extern void processBlock(unsigned int *);

extern void InitSRU(void);
extern void Init1835viaSPI(void);

extern void InitSPORT(void);
extern void TalkThroughISR(uint32_t , void *);
extern void ClearSPORT(void);

 void SetupSPI1835 (void) ;
 void DisableSPI1835 (void) ;
 void Configure1835Register (int i) ;
 unsigned int Get1835Register (int i) ;

extern void SetupIRQ01 (void) ;
extern void Irq0ISR(uint32_t , void *);
extern void Irq1ISR(uint32_t , void *);

static void Delay (int i) ;

extern volatile int isProcessing;
extern volatile int blockReady;
extern unsigned int *src_pointer[3];
extern volatile int int_cntr;

extern  void init_uart_before_pll();

extern  void init_uart();

extern void xmitUARTmessage(char*, int); /* function to transmit the welcome message*/
#endif
