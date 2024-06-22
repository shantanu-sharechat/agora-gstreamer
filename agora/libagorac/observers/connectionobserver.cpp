#include "connectionobserver.h"

#include "../helpers/log.h"

void ConnectionObserver::onConnected(const agora::rtc::TConnectionInfo &connectionInfo,
                                           agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason)
{
  AG_LOG(INFO, "onConnected: id %u, channelId %s, localUserId %s, reason %d\n", connectionInfo.id,
         connectionInfo.channelId.get()->c_str(), connectionInfo.localUserId.get()->c_str(),
         reason);

  // notify the thread which is waiting for the SDK to be connected
  connect_ready_.Set();
}

void ConnectionObserver::onDisconnected(const agora::rtc::TConnectionInfo &connectionInfo,
                                              agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason)
{
  AG_LOG(INFO, "onDisconnected: id %u, channelId %s, localUserId %s, reason %d\n",
         connectionInfo.id, connectionInfo.channelId.get()->c_str(),
         connectionInfo.localUserId.get()->c_str(), reason);

  // notify the thread which is waiting for the SDK to be disconnected
  disconnect_ready_.Set();
}

void ConnectionObserver::onConnecting(const agora::rtc::TConnectionInfo &connectionInfo,
                                            agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason)
{
  AG_LOG(INFO, "onConnecting: id %u, channelId %s, localUserId %s, reason %d\n",
         connectionInfo.id, connectionInfo.channelId.get()->c_str(),
         connectionInfo.localUserId.get()->c_str(), reason);
}

void ConnectionObserver::onReconnecting(const agora::rtc::TConnectionInfo &connectionInfo,
                                              agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason)
{
  AG_LOG(INFO, "onReconnecting: id %u, channelId %s, localUserId %s, reason %d\n",
         connectionInfo.id, connectionInfo.channelId.get()->c_str(),
         connectionInfo.localUserId.get()->c_str(), reason);
}

void ConnectionObserver::onReconnected(const agora::rtc::TConnectionInfo &connectionInfo,
                                             agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason)
{
  AG_LOG(INFO, "onReconnected: id %u, channelId %s, localUserId %s, reason %d\n",
         connectionInfo.id, connectionInfo.channelId.get()->c_str(),
         connectionInfo.localUserId.get()->c_str(), reason);
}

void ConnectionObserver::onConnectionLost(const agora::rtc::TConnectionInfo &connectionInfo)
{
  AG_LOG(INFO, "onConnectionLost: id %u, channelId %s, localUserId %s\n", connectionInfo.id,
         connectionInfo.channelId.get()->c_str(), connectionInfo.localUserId.get()->c_str());
}

void ConnectionObserver::onUplinkNetworkInfoUpdated(const agora::rtc::UplinkNetworkInfo &info)
{
  AG_LOG(INFO, "onBandwidthEstimationUpdated: video_encoder_target_bitrate_bps %d\n",
         info.video_encoder_target_bitrate_bps);
}

void ConnectionObserver::onUserJoined(agora::user_id_t userId)
{
  AG_LOG(INFO, "onUserJoined: userId %s\n", userId);
}

void ConnectionObserver::onUserLeft(agora::user_id_t userId,
                                          agora::rtc::USER_OFFLINE_REASON_TYPE reason)
{
  AG_LOG(INFO, "onUserLeft: userId %s, reason %d\n", userId, reason);
}