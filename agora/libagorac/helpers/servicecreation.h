//
// Created by Shantanu  Sharma on 24/06/24.
//

#ifndef AGORA_GSTREAMER_SERVICECREATION_H
#define AGORA_GSTREAMER_SERVICECREATION_H

#include "IAgoraService.h"

agora::base::IAgoraService* createAndInitAgoraService(bool enableAudioDevice,
                                                      bool enableAudioProcessor, bool enableVideo,bool enableuseStringUid = false,bool enablelowDelay = false, const char* appid =nullptr);

#endif //AGORA_GSTREAMER_SERVICECREATION_H
