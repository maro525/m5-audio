#ifndef _I2S_H
#define _I2S_H
#include <Arduino.h>
#include "driver/i2s.h"
#include "AudioOutput.h"

enum MicType {
  ADMP441,
  ICS43434,
  SPH0645LM4H,
  M5GO,
  M5STACKFIRE,
  M5ATOM_ECHO
};

class I2S : public AudioOutput{
  MicType micType;
public:
  I2S(MicType micType);
  void initMic();
  int read(char* data, int numData);
  void initSpeaker();
  size_t write(const unsigned char audio_data[], const size_t numData);
};

#endif // _I2S_H
