//
// Created by Shantanu  Sharma on 27/06/24.
//

#ifndef AGORA_GSTREAMER_PCMFRAMEOBSERVER_H
#define AGORA_GSTREAMER_PCMFRAMEOBSERVER_H

#include "AgoraMediaBase.h"
#include "frameobserver.h"
#include "agorac.h"

class PcmFrameObserver : public agora::media::IAudioFrameObserverBase, public FrameObserver{
  agora_media_out_fn fn;
  void* user_data;
public:
  PcmFrameObserver(){}

  void setFrameOutFn(agora_media_out_fn fn, void* user_data);

  bool onPlaybackAudioFrame(const char* channelId,AudioFrame& audioFrame) override { return true; };

  bool onRecordAudioFrame(const char* channelId,AudioFrame& audioFrame) override { return true; };

  bool onMixedAudioFrame(const char* channelId,AudioFrame& audioFrame) override { return true; };

  bool onPlaybackAudioFrameBeforeMixing(const char* channelId, agora::media::base::user_id_t userId, AudioFrame& audioFrame) override;

  bool onEarMonitoringAudioFrame(AudioFrame& audioFrame) override {return true;};

  AudioParams getEarMonitoringAudioParams()override {return  AudioParams();};

  int getObservedAudioFramePosition() override {return 0;};

  AudioParams getPlaybackAudioParams() override {return  AudioParams();};

  AudioParams getRecordAudioParams()  override {return  AudioParams();};

  AudioParams getMixedAudioParams() override {return  AudioParams();};

  void setFrameOutFn(agora_media_out_fn _fn, void* _user_data) override;

};

#endif //AGORA_GSTREAMER_PCMFRAMEOBSERVER_H
