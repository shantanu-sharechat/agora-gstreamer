//
// Created by Shantanu  Sharma on 27/06/24.
//

#ifndef AGORA_GSTREAMER_FRAMEOBSERVER_H
#define AGORA_GSTREAMER_FRAMEOBSERVER_H

class FrameObserver{
public:
  virtual void setFrameOutFn(agora_media_out_fn fn, void* user_data) = 0;
};

#endif //AGORA_GSTREAMER_FRAMEOBSERVER_H
