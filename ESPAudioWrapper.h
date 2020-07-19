#ifndef _ESPAUDIOWRAPPER_H
#define _ESPAUDIOWRAPPER_H

#include <Arduino.h>
#include "I2S.h"
#include "AudioGeneratorWAV.h"
#include "AudioFileSourcePROGMEM.h"

// 16bit, monoral, 16000Hz,  linear PCM
class Audio {
  I2S* i2s;
  AudioGeneratorWAV *wav;
  AudioFileSourcePROGMEM *file;

public:
  Audio(MicType micType);
  ~Audio();
  void initMic();
  void initSpeaker();
  // void SetGain(float f){ i2s->SetGain(f); };
  void SetGain(float f){ Serial.println(f); };
  // void begin(const void *data, uint32_t len);
  void record();
  void playRecorded();
  void playWaveBuf(const unsigned char audio_data[], const size_t numData);
};

#endif // _AUDIO_H
