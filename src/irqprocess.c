/*********************************************************************************

 Copyright(c) 2012 Analog Devices, Inc. All Rights Reserved.

 This software is proprietary and confidential.  By using this software you agree
 to the terms of the associated Analog Devices License Agreement.

 *********************************************************************************/

/*
*	  NAME:     irqprocess.c (Block-based Talkthrough)
*	  PURPOSE:  Talkthrough framework for sending and receiving samples to the AD1835A.
*	  USAGE:    This file contains the setup routine for IRQ0 and IRQ1, as well as the
			    interrupt service routine for handling each of the IRQ's. The ISR for
			    each button accesses the codec setting and adjusts the volume via SPI
*/


#include "ADDS_21369_EzKit.h"
#include "ad1835.h"

 void SetupIRQ01 ()
{
    /*Enable the pins as IRQ0 and IRQ1*/
    *pSYSCTL|= IRQ0EN | IRQ1EN;

    /*Set the IRQ pins to be edge sensitive*/
    sysreg_bit_set(sysreg_MODE2,IRQ0E|IRQ1E);

}

 void Irq0ISR(uint32_t iid, void *handlerarg) /* No argument is passed in this ISR */
{
      int leftDAC4Vol, rightDAC4Vol ;

    /* IRQ0 is used to decrease volume*/
    SetupSPI1835 () ;
    leftDAC4Vol = Get1835Register (RD | DACVOL_L4) ;
    rightDAC4Vol = Get1835Register (RD | DACVOL_R4) ;

    /* Now increase by a step size of 0x3F*/

   leftDAC4Vol -= 0x3F ;
   rightDAC4Vol -= 0x3F ;

    if (leftDAC4Vol > 0)
        Configure1835Register (WR | DACVOL_L4 | leftDAC4Vol) ;

    if (rightDAC4Vol > 0)
        Configure1835Register (WR | DACVOL_R4 | rightDAC4Vol) ;

    DisableSPI1835 () ;
}

void Irq1ISR (uint32_t iid, void *handlerarg) /* No argument is passed in this ISR */
{
     int leftDAC4Vol, rightDAC4Vol ;

    /* IRQ1 is used to increase volume*/
    SetupSPI1835 () ;
    leftDAC4Vol = Get1835Register (RD | DACVOL_L4) ;
    rightDAC4Vol = Get1835Register (RD | DACVOL_R4) ;

    /* Now decrease by a step size of 0x3F */

    /* Now increase by a step size of 0x3F*/
    leftDAC4Vol += 0x3F ;
    rightDAC4Vol += 0x3F ;

    if (leftDAC4Vol < 0x3FF)
        Configure1835Register (WR | DACVOL_L4 | leftDAC4Vol) ;

    if (rightDAC4Vol < 0x3FF)
        Configure1835Register (WR | DACVOL_R4 | rightDAC4Vol) ;

    DisableSPI1835 () ;
}
