//
// Created by Shantanu  Sharma on 21/06/24.
//

#include "yuvframeobserver.h"
#include "../helpers/log.h"

void YUVFrameObserver::onFrame(const char* channelId, agora::user_id_t remoteUid, const agora::media::base::VideoFrame* frame){

  const int len = frame->height * frame->width * 3 / 2;
  AG_LOG( INFO, "YUVFrameObserver::onFrame len %d", len);
  uint8_t* buffer = new uint8_t[len];
  const int ySize = frame->yStride * frame->height;
  const int uSize = frame->uStride * frame->height / 2;
  const int vSize = frame->vStride * frame->height / 2;
  memcpy((void*)buffer, frame->yBuffer, ySize);
  memcpy((void*)(buffer + ySize), frame->uBuffer, uSize);
  memcpy((void*)(buffer + ySize + uSize), frame->vBuffer, vSize);

  if(fn){
    fn(buffer, len, user_data, frame->renderTimeMs);
  }

}

void YUVFrameObserver::setFrameOutFn(agora_media_out_fn _fn, void* _user_data){
  fn = _fn;
  user_data = _user_data;
}
