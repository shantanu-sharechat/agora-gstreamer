//
// Created by Shantanu  Sharma on 21/06/24.
//

#ifndef AGORA_GSTREAMER_AGORAIO_H
#define AGORA_GSTREAMER_AGORAIO_H

#include "agoraconfig.h"
#include <string>
#include "IAgoraService.h"
#include "NGIAgoraLocalUser.h"
#include "agorac.h"
#include "observers/yuvframeobserver.h"

class AgoraIO{
  std::string appid, channel, remote_uid;
  agora::base::IAgoraService* service;
  agora::agora_refptr<agora::rtc::IRtcConnection> connection;
  std::shared_ptr<agora::rtc::ILocalUserObserver> local_user_observer;
  std::shared_ptr<YUVFrameObserver> yuvFrameObserver;
  void AgoraIO::setupAudioFrameObserver();
  void AgoraIO::setupVideoFrameObserver();
  void AgoraIO::setupLocalUserObserver();
  void AgoraIO::setupConnectionObserver();
  bool AgoraIO::doConnect();
  void AgoraIO::subscribe();
  bool AgoraIO::initializeService();
  bool AgoraIO::createConnection();
public:
  AgoraIO(agora_config_t* agora_config);
  bool init();
  void setVideoOutFn(agora_media_out_fn fn, void* user_data);
  void setAudioOutFn(agora_media_out_fn fn, void* user_data);
};
#endif //AGORA_GSTREAMER_AGORAIO_H
