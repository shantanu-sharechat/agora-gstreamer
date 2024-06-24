//
// Created by Shantanu  Sharma on 21/06/24.
//

#include "yuvframeobserver.h"
#include<iostream>

void YUVFrameObserver::onFrame(const char* channelId, agora::user_id_t remoteUid, const agora::media::base::VideoFrame* frame){
  std::cout<<"Frame received "<< "ts: "<<frame->timestamp<<" width: "<<frame->width<<std::endl;
  if(fn){
//    fn(channelId, remoteUid, frame, user_data);
  }
}

void YUVFrameObserver::setFrameOutFn(agora_media_out_fn _fn, void* _user_data){
  std::cout<<"Frame out function set"<<std::endl;
  fn = _fn;
  user_data = _user_data;
}
