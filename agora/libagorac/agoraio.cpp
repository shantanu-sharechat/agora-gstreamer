//
// Created by Shantanu  Sharma on 21/06/24.
//

#include<iostream>
#include <string>

#include "agoraio.h"
#include "IAgoraService.h"
#include "AgoraBase.h"
#include "observers/connectionobserver.h"
#include "observers/localuserobserver.h"
#include "observers/yuvframeobserver.h"
#include "observers/pcmframeobserver.h"
#include "helpers/log.h"
#include "helpers/servicecreation.h"

AgoraIO::AgoraIO(agora_config_t* agora_config) {
  appid = std::string(agora_config->app_id);
  channel = agora_config->ch_id;
  remote_uid = agora_config->remote_user_id;
  enable_video = agora_config->enable_video;
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
  ccfg.autoSubscribeAudio = false;
  ccfg.autoSubscribeVideo = false;
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
//  if(enable_video){
    agora::rtc::VideoSubscriptionOptions subscriptionOptions;
    subscriptionOptions.type = agora::rtc::VIDEO_STREAM_HIGH;
    connection->getLocalUser()->subscribeAllVideo(subscriptionOptions);
//  }
//  else {
    connection->getLocalUser()->subscribeAllAudio();
//  }
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

void AgoraIO::setupAudioFrameObserver(){
  if(enable_video){
    return;
  }
  AG_LOG(INFO, "Setting up audio frame observer");
  pcmFrameObserver = new PcmFrameObserver();
  connection->getLocalUser()->setPlaybackAudioFrameBeforeMixingParameters(
          1, 48000);
  local_user_observer->setAudioFrameObserver(pcmFrameObserver);
}

void AgoraIO::setupVideoFrameObserver() {
  if(!enable_video){
    return;
  }
  yuvFrameObserver = new YUVFrameObserver();
  local_user_observer->setVideoFrameObserver(yuvFrameObserver);
}

void AgoraIO::setVideoOutFn(agora_media_out_fn fn, void *user_data) {
  if(!enable_video){
    return;
  }
  yuvFrameObserver->setFrameOutFn(fn, user_data);
}

void AgoraIO::setAudioOutFn(agora_media_out_fn fn, void *user_data) {
  if(enable_video){
    return;
  }
  pcmFrameObserver->setFrameOutFn(fn, user_data);
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
  setupAudioFrameObserver();
  setupVideoFrameObserver();
  if (doConnect()) {
    return false;
  }
  return true;
}