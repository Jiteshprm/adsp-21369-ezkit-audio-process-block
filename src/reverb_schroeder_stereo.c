
/*****************************************************************************
 * Schroeder Reverb Adapted to stereo with memory optimization from youtube channel YetAnotherElectronicsChannel
 * Optimized for SDRAM available in ADSP 21369 EZKit board
 * https://www.youtube.com/watch?v=nRLXNmLmHqM
 * https://github.com/YetAnotherElectronicsChannel/STM32_DSP_Reverb
*****************************************************************************/
#include <math.h>
#include <stdio.h>

//Schroeder delays from 25k->96k interpolated
//*2 delay extension -> not more possible without external ram
#define l_CB0 1730*3//(3460/96000)*48000*2
#define l_CB1 1494*3//(2988/96000)*48000*2
#define l_CB2 1941*3//(3882/96000)*48000*2
#define l_CB3 2156*3//(4312/96000)*48000*2
#define l_AP0 240*3 //(480/96000)*48000*2
#define l_AP1 81*3  //(161/96000)*48000*2
#define l_AP2 23*3  //(46/96000)*48000*2

//define wet 0.0 <-> 1.0
double wet = 0.2f;
//define time delay 0.0 <-> 1.0 (max)
double time = 0.4f;

//define pointer limits = delay time
int cf0_lim, cf1_lim, cf2_lim, cf3_lim, ap0_lim, ap1_lim, ap2_lim;

//feedback defines as of Schroeder
double cf0_g = 0.805f, cf1_g=0.827f, cf2_g=0.783f, cf3_g=0.764f;
double ap0_g = 0.7f, ap1_g = 0.7f, ap2_g = 0.7f;

extern void init_reverb();
extern int reverb_schroeder_stereo(unsigned int *block_ptr);


typedef struct {
	//define buffer for comb- and allpassfilters
	double cfbuf0[l_CB0], cfbuf1[l_CB1], cfbuf2[l_CB2], cfbuf3[l_CB3];
	double apbuf0[l_AP0], apbuf1[l_AP1], apbuf2[l_AP2];
	//buffer-pointer
	int cf0_p, cf1_p, cf2_p, cf3_p, ap0_p, ap1_p, ap2_p;
}
reverb_buffer_t;

#define LEFT_BUFFER 0
#define RIGHT_BUFFER 1
section("seg_sdram") reverb_buffer_t reverb_buffer[2];

double Do_Comb0(float inSample, reverb_buffer_t *buff) {
	double readback = buff->cfbuf0[buff->cf0_p];
	double new = readback*cf0_g + inSample;
	buff->cfbuf0[buff->cf0_p] = new;
	buff->cf0_p++;
	if (buff->cf0_p==cf0_lim) buff->cf0_p = 0;
	return readback;
}

double Do_Comb1(float inSample, reverb_buffer_t *buff) {
	double readback = buff->cfbuf1[buff->cf1_p];
	double new = readback*cf1_g + inSample;
	buff->cfbuf1[buff->cf1_p] = new;
	buff->cf1_p++;
	if (buff->cf1_p==cf1_lim) buff->cf1_p = 0;
	return readback;
}

double Do_Comb2(float inSample, reverb_buffer_t *buff) {
	double readback = buff->cfbuf2[buff->cf2_p];
	double new = readback*cf2_g + inSample;
	buff->cfbuf2[buff->cf2_p] = new;
	buff->cf2_p++;
	if (buff->cf2_p==cf2_lim) buff->cf2_p = 0;
	return readback;
}
double Do_Comb3(float inSample, reverb_buffer_t *buff) {
	double readback = buff->cfbuf3[buff->cf3_p];
	double new = readback*cf3_g + inSample;
	buff->cfbuf3[buff->cf3_p] = new;
	buff->cf3_p++;
	if (buff->cf3_p==cf3_lim) buff->cf3_p = 0;
	return readback;
}


double Do_Allpass0(float inSample, reverb_buffer_t *buff) {
	double readback = buff->apbuf0[buff->ap0_p];
	readback += (-ap0_g) * inSample;
	double new = readback*ap0_g + inSample;
	buff->apbuf0[buff->ap0_p] = new;
	buff->ap0_p++;
	if (buff->ap0_p == ap0_lim) buff->ap0_p=0;
	return readback;
}

double Do_Allpass1(float inSample, reverb_buffer_t *buff) {
	double readback = buff->apbuf1[buff->ap1_p];
	readback += (-ap1_g) * inSample;
	double new = readback*ap1_g + inSample;
	buff->apbuf1[buff->ap1_p] = new;
	buff->ap1_p++;
	if (buff->ap1_p == ap1_lim) buff->ap1_p=0;
	return readback;
}
double Do_Allpass2(float inSample, reverb_buffer_t *buff) {
	double readback = buff->apbuf2[buff->ap2_p];
	readback += (-ap2_g) * inSample;
	double new = readback*ap2_g + inSample;
	buff->apbuf2[buff->ap2_p] = new;
	buff->ap2_p++;
	if (buff->ap2_p == ap2_lim) buff->ap2_p=0;
	return readback;
}

double Do_Reverb(float inSample, reverb_buffer_t *buff) {
	//Do_Comb0(inSample);
	double newsample = (Do_Comb0(inSample, buff) + Do_Comb1(inSample, buff) + Do_Comb2(inSample, buff) + Do_Comb3(inSample, buff))/4.0f;
	newsample = Do_Allpass0(newsample, buff);
	newsample = Do_Allpass1(newsample, buff);
	newsample = Do_Allpass2(newsample, buff);
	return newsample;
}

void init_reverb(){
	cf0_lim = (int)(time*l_CB0);
	cf1_lim = (int)(time*l_CB1);
	cf2_lim = (int)(time*l_CB2);
	cf3_lim = (int)(time*l_CB3);
	ap0_lim = (int)(time*l_AP0);
	ap1_lim = (int)(time*l_AP1);
	ap2_lim = (int)(time*l_AP2);
}


int reverb_schroeder_stereo(unsigned int *block_ptr){

	int left_data = *(block_ptr) << 8;
	int right_data = *(block_ptr+1) << 8;

	double left_data_sum = (double) (left_data);
	left_data_sum = (1.0f-wet)*left_data_sum + wet*Do_Reverb(left_data_sum, &reverb_buffer[LEFT_BUFFER]);

	double right_data_sum = (double) (right_data);
	right_data_sum = (1.0f-wet)*right_data_sum + wet*Do_Reverb(right_data_sum, &reverb_buffer[RIGHT_BUFFER]);

	*(block_ptr) = ((int)left_data_sum) >> 8;
	*(block_ptr+1) = ((int)right_data_sum) >> 8;
}
