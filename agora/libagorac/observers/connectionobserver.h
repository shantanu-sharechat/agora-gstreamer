//
// Created by Shantanu  Sharma on 21/06/24.
//

#ifndef AGORA_GSTREAMER_CONNECTIONOBSERVER_H
#define AGORA_GSTREAMER_CONNECTIONOBSERVER_H

#include "NGIAgoraRtcConnection.h"
#include "sampleevent.h"
#include "log.h"

class ConnectionObserver : public agora::rtc::IRtcConnectionObserver, public agora::rtc::INetworkObserver {
public:
  ConnectionObserver()
  {
  }
  int waitUntilConnected(int waitMs)
  {
    return connect_ready_.Wait(waitMs);
  }
  ~ConnectionObserver()
  {
    AG_LOG(INFO, "ConnectionObserver destructor");
  }

public: // IRtcConnectionObserver
  void onConnected(const agora::rtc::TConnectionInfo &connectionInfo,
                   agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason) override;
  void onDisconnected(const agora::rtc::TConnectionInfo &connectionInfo,
                      agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason) override;
  void onConnecting(const agora::rtc::TConnectionInfo &connectionInfo,
                    agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason) override;
  void onReconnecting(const agora::rtc::TConnectionInfo &connectionInfo,
                      agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason) override;
  void onReconnected(const agora::rtc::TConnectionInfo &connectionInfo,
                     agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason) override;
  void onConnectionLost(const agora::rtc::TConnectionInfo &connectionInfo) override;
  void onLastmileQuality(const agora::rtc::QUALITY_TYPE quality) override
  {
  }
  void onTokenPrivilegeWillExpire(const char *token) override
  {
  }
  void onTokenPrivilegeDidExpire() override
  {
  }
  void onConnectionFailure(const agora::rtc::TConnectionInfo &connectionInfo,
                           agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason) override
  {
  }
  void onUserJoined(agora::user_id_t userId) override;
  void onUserLeft(agora::user_id_t userId, agora::rtc::USER_OFFLINE_REASON_TYPE reason) override;
  void onTransportStats(const agora::rtc::RtcStats &stats) override
  {
  }
  void onLastmileProbeResult(const agora::rtc::LastmileProbeResult &result) override
  {
  }
  void onChannelMediaRelayStateChanged(int state, int code) override
  {
  }

public: // INetworkObserver
  void onUplinkNetworkInfoUpdated(const agora::rtc::UplinkNetworkInfo &info) override;

private:
  SampleEvent connect_ready_;
  SampleEvent disconnect_ready_;
};

#endif //AGORA_GSTREAMER_CONNECTIONOBSERVER_H
