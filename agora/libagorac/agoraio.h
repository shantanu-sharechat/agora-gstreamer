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
#include "observers/localuserobserver.h"
#include "observers/connectionobserver.h"

class AgoraIO{
  std::string appid, channel, remote_uid;
  agora::base::IAgoraService* service;
  agora::agora_refptr<agora::rtc::IRtcConnection> connection;
  std::shared_ptr<LocalUserObserver> local_user_observer;
  std::shared_ptr<YUVFrameObserver> yuvFrameObserver;
  std::shared_ptr<ConnectionObserver> connectionObserver;
  void setupAudioFrameObserver();
  void setupVideoFrameObserver();
  void setupLocalUserObserver();
  void setupConnectionObserver();
  int doConnect();
  void subscribe();
  bool initializeService();
  bool createConnection();
public:
  AgoraIO(agora_config_t* agora_config);
  bool init();
  void setVideoOutFn(agora_media_out_fn fn, void* user_data);
  void setAudioOutFn(agora_media_out_fn fn, void* user_data);
};
#endif //AGORA_GSTREAMER_AGORAIO_H
