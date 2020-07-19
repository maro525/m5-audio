#include "ESPAudioWrapper.h"

Audio::Audio(MicType micType) {
  i2s = new I2S(micType);
  initMic();
}

Audio::~Audio() {
  delete i2s;
  delete file;
  delete wav;
}

void Audio::initMic() {
    i2s->initMic();
}
void Audio::initSpeaker() {
  i2s->initSpeaker();
}

// not working yet
// void Audio::begin(const void *data, uint32_t len) {
//   file = new AudioFileSourcePROGMEM(data, len);
//   wav = new AudioGeneratorWAV();
//   bool flag = wav->begin(file, i2s);
//   Serial.println(flag);
// }

void Audio::record() {
}

void Audio::playRecorded() {

}

void Audio::playWaveBuf(const unsigned char audio_data[], const size_t numData) {
  i2s->write(audio_data, numData);
}
