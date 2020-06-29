/*
 * reverb.h
 *
 *  Created on: Jun 28, 2020
 *      Author: jiteshpramodray
 */

#ifndef REVERB_H_
#define REVERB_H_


//Schroeder delays from 25k->96k interpolated
//*2 delay extension -> not more possible without external ram
#define l_CB0 3460*2
#define l_CB1 2988*2
#define l_CB2 3882*2
#define l_CB3 4312*2
#define l_AP0 480*2
#define l_AP1 161*2
#define l_AP2 46*2

//define wet 0.0 <-> 1.0
float wet = 1.0f;
//define time delay 0.0 <-> 1.0 (max)
float time = 1.0f;

//define pointer limits = delay time
int cf0_lim, cf1_lim, cf2_lim, cf3_lim, ap0_lim, ap1_lim, ap2_lim;

//define buffer for comb- and allpassfilters
//float cfbuf0[l_CB0];//, cfbuf1[l_CB1];//, cfbuf2[l_CB2];//, cfbuf3[l_CB3];
//float apbuf0[l_AP0], apbuf1[l_AP1], apbuf2[l_AP2];
//feedback defines as of Schroeder
float cf0_g = 0.805f, cf1_g=0.827f, cf2_g=0.783f, cf3_g=0.764f;
float ap0_g = 0.7f, ap1_g = 0.7f, ap2_g = 0.7f;
//buffer-pointer
extern int cf0_p=0, cf1_p=0, cf2_p=0, cf3_p=0, ap0_p=0, ap1_p=0, ap2_p=0;

extern int reverb(int lSample, int rSample);


section("seg_sdram") float cfbuf0[l_CB0], cfbuf1[l_CB1], cfbuf2[l_CB2], cfbuf3[l_CB3];
section("seg_sdram") float apbuf0[l_AP0], apbuf1[l_AP1], apbuf2[l_AP2];

#endif /* REVERB_H_ */
