//
// Created by Shantanu  Sharma on 21/06/24.
//

#ifndef AGORA_GSTREAMER_YUVFRAMEOBSERVER_H
#define AGORA_GSTREAMER_YUVFRAMEOBSERVER_H

#include "NGIAgoraLocalUser.h"
#include "agorac.h"

class YUVFrameObserver : public agora::rtc::IVideoFrameObserver2 {
  agora_media_out_fn fn;
  void* user_data;
public:
  YUVFrameObserver(){};
  void onFrame(const char* channelId, agora::user_id_t remoteUid, const agora::media::base::VideoFrame* frame) override;
  void setFrameOutFn(agora_media_out_fn fn, void* user_data);
}

#endif //AGORA_GSTREAMER_YUVFRAMEOBSERVER_H
