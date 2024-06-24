//
// Created by Shantanu  Sharma on 21/06/24.
//

#include "agoraio.h"
#include "IAgoraService.h"
#include "AgoraBase.h"
#include "observers/connectionobserver.h"
#include "observers/localuserobserver.h"
#include "observers/yuvframeobserver.h"
#include "helpers/log.h"

AgoraIO::AgoraIO(agora_config_t* agora_config) {
  appid = agora_config->app_id;
  channel = agora_config->ch_id;
  remote_uid = agora_config->remote_user_id;
  service = nullptr;
}

bool AgoraIO::initializeService(){
  AG_LOG(INFO, "Initializing Agora SDK service");
  service = createAgoraService();
  agora::base::AgoraServiceConfiguration scfg;
  AG_LOG(INFO, "Setting before appid");
  scfg.appId = appid.c_str();
  AG_LOG(INFO, "Setting after appid");
  scfg.enableAudioProcessor = true;
  scfg.enableAudioDevice = false;
  scfg.enableVideo = true;
  if (service->initialize(scfg) != agora::ERR_OK)
  {
    AG_LOG(ERROR, "Error initialize Agora SDK");
    return false;
  }
  AG_LOG(INFO, "Agora SDK service initialized");
  return true;
}

bool AgoraIO::createConnection(){
  agora::rtc::RtcConnectionConfiguration ccfg;
  ccfg.clientRoleType = agora::rtc::CLIENT_ROLE_AUDIENCE;
  ccfg.autoSubscribeAudio = true;
  ccfg.autoSubscribeVideo = true;
  ccfg.enableAudioRecordingOrPlayout =false;
  connection = service->createRtcConnection(ccfg);
  if (!connection)
  {
    AG_LOG(ERROR, "Error create connection");
    return false;
  }
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

void AgoraIO::setupAudioFrameObserver(){
}

void AgoraIO::setupVideoFrameObserver() {
  yuvFrameObserver = new YUVFrameObserver();
  local_user_observer->setVideoFrameObserver(yuvFrameObserver);
}

void AgoraIO::setVideoOutFn(agora_media_out_fn fn, void *user_data) {
  yuvFrameObserver->setFrameOutFn(fn, user_data);
}

void AgoraIO::setAudioOutFn(agora_media_out_fn fn, void *user_data) {
  // todo
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