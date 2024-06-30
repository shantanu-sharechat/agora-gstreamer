//
// Created by Shantanu  Sharma on 27/06/24.
//

#ifndef AGORA_GSTREAMER_PCMFRAMEOBSERVER_H
#define AGORA_GSTREAMER_PCMFRAMEOBSERVER_H

#include "AgoraMediaBase.h"
#include "agorac.h"
#include "NGIAgoraAudioTrack.h"

class PcmFrameObserver : public agora::media::IAudioFrameObserverBase{
  agora_media_out_fn fn;
  void* user_data;
public:
  PcmFrameObserver(){}

  bool onPlaybackAudioFrame(const char* channelId,AudioFrame& audioFrame) override ;

  bool onRecordAudioFrame(const char* channelId,AudioFrame& audioFrame) override { return true; };

  bool onMixedAudioFrame(const char* channelId,AudioFrame& audioFrame) override { return true; };

  bool onPlaybackAudioFrameBeforeMixing(const char* channelId, agora::media::base::user_id_t userId, AudioFrame& audioFrame) override { return true; };

  bool onEarMonitoringAudioFrame(AudioFrame& audioFrame) override {return true;};

  void setFrameOutFn(agora_media_out_fn _fn, void* _user_data);

};

#endif //AGORA_GSTREAMER_PCMFRAMEOBSERVER_H
