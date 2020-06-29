#ifndef _AUDIO_PROCESSING
#define _AUDIO_PROCESSING

#include <stdint.h>

extern void init_audio_processing(void);

extern void audio_processing(unsigned int *block_ptr, int num_chans);
extern void init_reverb();

#endif // _AUDIO_PROCESSING
