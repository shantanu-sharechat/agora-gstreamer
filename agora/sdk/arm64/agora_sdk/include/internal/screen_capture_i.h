//
//  Agora Media SDK
//
//  Created by Sting Feng in 2015-05.
//  Copyright (c) 2015 Agora IO. All rights reserved.
//
#pragma once

#include "NGIAgoraScreenCapturer.h"
#include "api/video/video_content_type.h"
#include "api/video/video_frame.h"
#include "api/video/video_sink_interface.h"
#include "modules/desktop_capture/desktop_capturer.h"

namespace agora {
namespace rtc {

class IScreenCaptureObserver;

class IScreenCapturerEx : public IScreenCapturer {
public:
  enum SCREEN_CAPTURER_STATE {
      SCREEN_CAPTURER_STARTED,
      SCREEN_CAPTURER_STOPPED,
  };
 public:
  virtual ~IScreenCapturerEx() {}
  virtual int StartCapture() = 0;
  virtual int StopCapture() = 0;
  virtual void RegisterCaptureDataCallback(
      std::weak_ptr<::rtc::VideoSinkInterface<webrtc::VideoFrame>> dataCallback) = 0;
  virtual int CaptureMouseCursor(bool capture) = 0;
  virtual int GetScreenDimensions(VideoDimensions& dimension) = 0;
  virtual int SetOutputDimensions(VideoDimensions dimension) {return 0;};
  virtual int SetContentType(agora::VideoContentSubType type) {return 0;};
  virtual bool FocusOnSelectedSource() = 0;
#if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS)
  virtual void SetHighLight(bool isHighLight, unsigned int color, int width) {}
#endif
#if defined(_WIN32)
  virtual int InitUsingLastRegionSetting() { return -ERR_NOT_SUPPORTED; }
  virtual void SetCaptureSource(bool allow_magnification_api, bool allow_directx_capturer) {}
  virtual void GetCaptureSource(bool& allow_magnification_api, bool& allow_directx_capturer) {}
#endif // _WIN32

#if defined(_WIN32) || (defined(WEBRTC_MAC) && !defined(WEBRTC_IOS))
  virtual void ForcedUsingScreenCapture(bool using_screen_capture) {}

  virtual void SetExcludeWindowList(const std::vector<void *>& window_list) = 0;
  virtual webrtc::DesktopCapturer::SourceId GetSourceId() = 0;
  virtual int GetCaptureType() = 0;
#endif // _WIN32 || (WEBRTC_MAC&&!WEBRTC_IOS)
  virtual int registerScreenCaptureObserver(IScreenCaptureObserver* observer) {
      return -ERR_NOT_SUPPORTED;
  }
  virtual int unregisterScreenCaptureObserver(IScreenCaptureObserver* observer) {
      return -ERR_NOT_SUPPORTED;
  }
  virtual void* getScreenCaptureSources(int thumb_cx, int thumb_cy, int icon_cx, int icon_cy,
                                                            bool include_screen) {
      return nullptr;
  }
  virtual void deinit() {};
  virtual void attachStatsSpace(uint64_t stats_space) {}
};

class IScreenCaptureObserver {
public:
  virtual void onScreenCaptureStateChanged(IScreenCapturerEx::SCREEN_CAPTURER_STATE state) {
    (void) state;
  }
protected:
  virtual ~IScreenCaptureObserver() {}
};

#if defined(__ANDROID__) || (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE)
class AudioPcmDataSinkInterface;
class IScreenCapturerEx2 : public IScreenCapturer2 {
 public:
  virtual int startVideoCapture() = 0;
  virtual int stopVideoCapture() = 0;
  virtual int startAudioCapture() = 0;
  virtual int stopAudioCapture() = 0;
  virtual void addPcmDataSink(AudioPcmDataSinkInterface* sink) = 0;
  virtual void removePcmDataSink(AudioPcmDataSinkInterface* sink) = 0;
  virtual void deinit() {};
};
#endif

} // namespace rtc
} // namespace agora
