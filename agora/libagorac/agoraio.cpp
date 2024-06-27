//
// Created by Shantanu  Sharma on 21/06/24.
//

#include<iostream>
#include <string>

#include "agoraio.h"
#include "AgoraBase.h"
#include "observers/connectionobserver.h"
#include "observers/localuserobserver.h"
#include "observers/yuvframeobserver.h"
#include "observers/pcmframeobserver.h"
#include "observers/frameobserver.h"
#include "helpers/log.h"
#include "helpers/servicecreation.h"

AgoraIO::AgoraIO(agora_config_t* agora_config) {
  appid = std::string(agora_config->app_id);
  channel = agora_config->ch_id;
  remote_uid = agora_config->remote_user_id;
  is_video = agora_config->is_video;
  service = nullptr;
}

bool AgoraIO::initializeService(){
  AG_LOG(INFO, "Initializing Agora SDK service");
  service = createAndInitAgoraService(false, true, true);
  if (service == nullptr)
  {
    AG_LOG(ERROR, "Error create Agora SDK service");
    return false;
  }
  return true;
}

bool AgoraIO::createConnection(){
  AG_LOG(INFO, "Creating connection");
  agora::rtc::RtcConnectionConfiguration ccfg;
  ccfg.clientRoleType = agora::rtc::CLIENT_ROLE_AUDIENCE;
  ccfg.autoSubscribeAudio = true;
  ccfg.autoSubscribeVideo = true;
  ccfg.enableAudioRecordingOrPlayout =false;
  connection = service->createRtcConnection(ccfg);
  if (!connection.get())
  {
    AG_LOG(ERROR, "Error create connection");
    return false;
  }
  AG_LOG(INFO, "Connection created");
  return true;
}

int AgoraIO::doConnect(){
  return connection->connect(appid.c_str(), channel.c_str(), remote_uid.c_str());
}

void AgoraIO::subscribe(){
  agora::rtc::VideoSubscriptionOptions subscriptionOptions;
  subscriptionOptions.type = agora::rtc::VIDEO_STREAM_HIGH;
  connection->getLocalUser()->subscribeAllVideo(subscriptionOptions);
}

void AgoraIO::setupConnectionObserver(){
  AG_LOG(INFO, "Setting up connection observer");
  connectionObserver = new ConnectionObserver();
  AG_LOG(INFO, "Setting up connection observer");
  connection->registerObserver(connectionObserver);
}

void AgoraIO::setupLocalUserObserver(){
  local_user_observer = new LocalUserObserver(connection->getLocalUser());
}

void AgoraIO::setupFrameObserver(){
  if(is_video){
    setupVideoFrameObserver();
    return;
  }
  setupAudioFrameObserver();
}

void AgoraIO::setupAudioFrameObserver(){
  PcmFrameObserver* observer = new PcmFrameObserver();
  local_user_observer->setAudioFrameObserver(observer);
  frame_observer = observer;
}

void AgoraIO::setupVideoFrameObserver() {
  YUVFrameObserver* observer = new YUVFrameObserver();
  local_user_observer->setVideoFrameObserver(observer);
  frame_observer = observer;
}

void AgoraIO::setMediaOutFn(agora_media_out_fn fn, void *user_data) {
  frame_observer->setFrameOutFn(fn, user_data);
}

bool AgoraIO::init() {
  if(!initializeService()){
    return false;
  }
  if(!createConnection()){
    return false;
  }
  subscribe();
  setupConnectionObserver();
  setupLocalUserObserver();
  setupFrameObserver();
  if (doConnect()) {
    return false;
  }
  return true;
}