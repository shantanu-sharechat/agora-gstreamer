//
//  Agora RTC/MEDIA SDK
//
//  Created by Ning Huang in 2022-06.
//  Copyright (c) 2022 Agora.io. All rights reserved.
//
#pragma once

#include <string>
#include <vector>

#include "AgoraMediaBase.h"

namespace agora {
namespace media {
enum CONTENT_INSPECT_VENDOR { CONTENT_INSPECT_VENDOR_AGORA = 1, CONTENT_INSPECT_VENDOR_TUPU = 2, CONTENT_INSPECT_VENDOR_HIVE = 3 };
enum CONTENT_INSPECT_DEVICE_TYPE{
    CONTENT_INSPECT_DEVICE_INVALID = 0,
    CONTENT_INSPECT_DEVICE_AGORA = 1
};
enum CONTENT_INSPECT_WORK_TYPE {
/**
 * video moderation on device
 */
CONTENT_INSPECT_WORK_DEVICE = 0,
/**
 * video moderation on cloud
 */
CONTENT_INSPECT_WORK_CLOUD = 1,
/**
 * video moderation on cloud and device
 */
CONTENT_INSPECT_WORK_DEVICE_CLOUD = 2
};

struct ContentInspectModuleEx : ContentInspectModule {
  /**
   * The content inspect module type.
   */
  CONTENT_INSPECT_TYPE type;
  CONTENT_INSPECT_VENDOR vendor;
  std::string callbackUrl;
  std::string token;
  /**The content inspect frequency, default is 0 second.
   * the frequency <= 0 is invalid.
   */
  unsigned int interval;
  ContentInspectModuleEx() {
    type = CONTENT_INSPECT_INVALID;
    interval = 0;
    vendor = CONTENT_INSPECT_VENDOR_AGORA;
  }
};

/** Definition of ContentInspectConfig.
 */
struct ContentInspectConfigEx : ContentInspectConfig {
  /** video moderation work type.*/
  CONTENT_INSPECT_WORK_TYPE ContentWorkType;

  /**the type of video moderation on device.*/
  CONTENT_INSPECT_DEVICE_TYPE DeviceworkType;
  const char* extraInfo;

  /**The content inspect modules, max length of modules is 32.
   * the content(snapshot of send video stream, image) can be used to max of 32 types functions.
   */
  ContentInspectModuleEx modules[MAX_CONTENT_INSPECT_MODULE_COUNT];
  /**The content inspect module count.
   */
  int moduleCount;
   ContentInspectConfigEx& operator=(const ContentInspectConfig& rth)
  {
    extraInfo = rth.extraInfo;
    moduleCount = rth.moduleCount;
    for(int i = 0; i < MAX_CONTENT_INSPECT_MODULE_COUNT; i++) {
      modules[i].type = rth.modules[i].type;
      modules[i].interval = rth.modules[i].interval;
    }
    return *this;
  }
  ContentInspectConfigEx() :ContentWorkType(CONTENT_INSPECT_WORK_CLOUD),DeviceworkType(CONTENT_INSPECT_DEVICE_INVALID),extraInfo(NULL), moduleCount(0){}
};

}  // namespace rtc
}  // namespace agora
