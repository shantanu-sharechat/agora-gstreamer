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

#include "agoraio.h"
#include "agorac.h"

#include "helpers/context.h"
#include "helpers/log.h"


AgoraIoContext_t*  agoraio_init(agora_config_t* config){

    AgoraIoContext_t* ctx=new AgoraIoContext_t;

    ctx->agoraIo=std::make_shared<AgoraIO>(config);

    auto ret=ctx->agoraIo->init();

    if(ret==false){
      AG_LOG(ERROR, "Error initializing Agora SDK");
       return nullptr;
    }

    return ctx;
}

void agoraio_media_out_handler(AgoraIoContext_t* ctx, agora_media_out_fn fn, void* userData){
   
   if(ctx==nullptr)  return;

   ctx->agoraIo->setMediaOutFn(fn, userData);
}