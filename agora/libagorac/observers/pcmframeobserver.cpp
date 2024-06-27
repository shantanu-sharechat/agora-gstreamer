//
// Created by Shantanu  Sharma on 27/06/24.
//

#include "pcmframeobserver.h"
#include "agorac.h"

bool PcmFrameObserver::onPlaybackAudioFrameBeforeMixing(const char* channelId, agora::media::base::user_id_t userId, AudioFrame& audioFrame) {
  if(fn){
    fn((uint8_t*)audioFrame.buffer, audioFrame.samplesPerChannel * audioFrame.channels * 2, user_data, audioFrame.renderTimeMs);
  }
  return true;
}

void PcmFrameObserver::setFrameOutFn(agora_media_out_fn _fn, void* _user_data) {
  fn = _fn;
  user_data = _user_data;
}