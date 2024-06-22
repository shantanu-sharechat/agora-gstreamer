//
// Created by Shantanu  Sharma on 22/06/24.
//

#ifndef AGORA_GSTREAMER_CONTEXT_H
#define AGORA_GSTREAMER_CONTEXT_H
#include "agoraio.h"

struct AgoraIoContext_t{

  std::shared_ptr<AgoraIO>  agoraIo;
};

#endif //AGORA_GSTREAMER_CONTEXT_H
