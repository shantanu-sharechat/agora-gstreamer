#include <stdbool.h>
#include <fstream>
#include "agorac.h"

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>


//agora header files
#include "NGIAgoraRtcConnection.h"
#include "IAgoraService.h"
#include "AgoraBase.h"

#include "helpers/agoradecoder.h"
#include "helpers/agoraencoder.h"
#include "helpers/agoralog.h"
#include "helpers/localconfig.h"

//#include "userobserver.h"
#include "helpers/context.h"

#include "helpers/utilities.h"
#include "agoratype.h"
#include "helpers/agoraconstants.h"

#include "helpers/uidtofile.h"

#include "agoraio.h"


AgoraIoContext_t*  agoraio_init(agora_config_t* config){

    AgoraIoContext_t* ctx=new AgoraIoContext_t;
    if(ctx==nullptr){
        return NULL;
    }

    ctx->agoraIo=std::make_shared<AgoraIo>(config);

    auto ret=ctx->agoraIo->init();

    if(ret==false){
       return nullptr;
    }

    return ctx;
}

void agoraio_set_video_out_handler(AgoraIoContext_t* ctx, agora_media_out_fn fn, void* userData){
   
   if(ctx==nullptr)  return;

   ctx->agoraIo->setVideoOutFn(fn, userData);
}

void agoraio_set_audio_out_handler(AgoraIoContext_t* ctx, agora_media_out_fn fn, void* userData){

   if(ctx==nullptr)  return;

   ctx->agoraIo->setAudioOutFn(fn, userData);
}