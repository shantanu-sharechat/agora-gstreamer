//
//  Agora Media SDK
//
//  Copyright (c) 2020 Agora IO. All rights reserved.
//
#pragma once

#include <cstdint>
#include <functional>
#include <string>
#include <unordered_set>
#include <utility>
#include "utils/obfuscator/MetaString.h"

// internal key
#define INTERNAL_KEY_NT_ET_AP_PORT                            "nt.et.ap_port"
#define INTERNAL_KEY_NT_ET_ET_PORT_LIST                       "nt.et.et_port_list"
#define INTERNAL_KEY_NT_ET_AP_LIST                            "nt.et.ap_list"
#define INTERNAL_KEY_NT_ET_ET_LIST                            "nt.et.et_list"
#define INTERNAL_KEY_NT_PT_PUBLIC_DOMAIN_LIST                 "nt.pt.public_domain_list"

// audio adm/apm/acm/pipeline related parameters begin
#define CONFIGURABLE_KEY_RTC_AUDIO_AEC                        "che.audio.aec"
#define CONFIGURABLE_KEY_RTC_AUDIO_AGC                        "che.audio.agc"
#define CONFIGURABLE_KEY_RTC_AUDIO_ANS                        "che.audio.ans"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_AEC                 "che.audio.aec.enable"
#define CONFIGURABLE_KEY_RTC_AUDIO_AEC_AGGRESSIVENESS         "che.audio.aec.aggressiveness"
#define CONFIGURABLE_KEY_RTC_AUDIO_AEC_COMPLEXITY             "che.audio.aec.complexity"
#define CONFIGURABLE_KEY_RTC_AUDIO_AEC_FILER_LENGTH           "che.audio.aec.filter.length.ms"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_AGC                 "che.audio.agc.enable"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_ANS                 "che.audio.ans.enable"
#define CONFIGURABLE_KEY_RTC_AUDIO_ANS_COMPLEXITY             "che.audio.ans.complexity"
#define CONFIGURABLE_KEY_RTC_AUDIO_NS_LEVEL                   "che.audio.ans.aggressiveness"
#define CONFIGURABLE_KEY_RTC_AUDIO_NS_FOLLOW_AGC              "che.audio.ans.usenew"
#define CONFIGURABLE_KEY_RTC_AUDIO_NS_NOISEGATE               "che.audio.ans.noise_gate"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_MD                  "che.audio.md.enable"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_TONE_REMOVER        "che.audio.tone_remover.enable"
#define INTERNAL_KEY_RTC_AUDIO_OPENSL_MODE                    "che.audio.opensl.mode"
#define INTERNAL_KEY_RTC_AUDIO_KEEP_AUDIOSESSION              "che.audio.keep.audiosession"
#define INTERNAL_KEY_RTC_AUDIO_MUTE_ME                        "che.audio.mute_me"
#define INTERNAL_KEY_RTC_AUDIO_HAS_PUBLISHED_STREAM           "che.audio.has_published_stream"
#define INTERNAL_KEY_RTC_AUDIO_MUTE_PEERS                     "che.audio.mute_peers"
#define INTERNAL_KEY_RTC_AUDIO_SET_DEFAULT_MUTE_PEERS         "che.audio.set_default_mute_peers"
#define INTERNAL_KEY_RTC_AUDIO_MUTE_PEER                      "che.audio.mute_peer"
#define INTERNAL_KEY_RTC_AUDIO_ENABLED                        "che.audio.enabled"
#define INTERNAL_KEY_RTC_AUDIO_PAUSED                         "che.audio.paused"
#define INTERNAL_KEY_RTC_AUDIO_RECORD                         "che.audio.record"
#define INTERNAL_KEY_RTC_AUDIO_CODEC                          "che.audio.codec"
#define INTERNAL_KEY_RTC_AUDIO_DTX_MODE                       "che.audio.dtx_mode"
#define INTERNAL_KEY_RTC_AUDIO_OPTIONS                        "che.audio.options"
#define INTERNAL_KEY_RTC_AUDIO_FRAMES_PER_PACKET              "che.audio.frames_per_packet"
#define INTERNAL_KEY_RTC_AUDIO_INTERLEAVES_PER_PACKET         "che.audio.interleaves_per_packet"
#define INTERNAL_KEY_RTC_AUDIO_INSTANT_JOIN_OPTIMIZED         "che.audio.instant_join_optimized"
#define INTERNAL_KEY_RTC_AUDIO_START_CALL                     "che.audio.start_call"
#define CONFIGURABLE_KEY_RTC_AUDIO_RECORD_BOOST               "che.audio.agc.recordboost"
#define INTERNAL_KEY_RTC_AUDIO_ACM_PTIME                      "che.audio.acm_ptime"
#define CONFIGURABLE_KEY_RTC_AUDIO_AEC_STATE_DIAGNOSIS        "che.audio.aec_state_diagnosis"
#define INTERNAL_KEY_RTC_AUDIO_AINS_MODE                      "che.audio.ains_mode"
#define INTERNAL_KEY_RTC_AUDIO_AINS_GAIN_CONTROL              "che.audio.ains_gain_control"
#define INTERNAL_KEY_RTC_AUDIO_AINS_SPEECH_ENHANCE            "che.audio.ains_speech_enhance"
#define CONFIGURABLE_KEY_RTC_AUDIO_EXTRA_PLAYOUT_LATENCY      "che.audio.extra_playout_latency"
#define CONFIGURABLE_KEY_RTC_AUDIO_EXTRA_RECORD_LATENCY       "che.audio.extra_record_latency"

//AINS private parameter
#define INTERNAL_KEY_RTC_AUDIO_NSNG_ANASIZE                   "che.audio.nsng.anasize"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_FFTSIZE                   "che.audio.nsng.fftsize"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_MAXTIME                   "che.audio.nsng.maxtime"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_ATTACKFACTOR              "che.audio.nsng.attackfactor"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_RELEASEFACTOR             "che.audio.nsng.releasefactor"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_UPPERBOUND                "che.audio.nsng.upperbound"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_UPPERMASK                 "che.audio.nsng.uppermask"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_LOWERBOUND                "che.audio.nsng.lowerBound"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_LOWERMASK                 "che.audio.nsng.lowerMask"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_TRIANGLE_1                "che.audio.nsng.triangle_1"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_TRIANGLE_2                "che.audio.nsng.triangle_2"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_TRIANGLE_3                "che.audio.nsng.triangle_3"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_THREAHOLDAI               "che.audio.nsng.thresholdai"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_THREAHOLDSTATICAL         "che.audio.nsng.thresholdstastical"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_ENAFACTORAI               "che.audio.nsng.enhfactorai"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_ENHFACTORSTASTICAL        "che.audio.nsng.enhfactorstastical"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_NOISEOVERESTIMATE         "che.audio.nsng.noiseoverestimate"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_STATISTICALBOUND          "che.audio.nsng.statisticalbound"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_GAINBOOSTFREQ1            "che.audio.nsng.gainboostfreq1"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_GAINBOOSTVAL1             "che.audio.nsng.gainboostval1"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_GAINBOOSTFREQ2            "che.audio.nsng.gainboostfreq2"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_GAINBOOSTVAL2             "che.audio.nsng.gainboostval2"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_GAINBOOSTFREQ3            "che.audio.nsng.gainboostfreq3"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_GAINBOOSTVAL3             "che.audio.nsng.gainboostval3"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_FINALLOWERMAST            "che.audio.nsng.finallowermask"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_NOISEPOWFLOOR             "che.audio.nsng.noisepowfloor"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_PINKFACTOR                "che.audio.nsng.pinkfactor"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_CNGBASEMAGNITUDE          "che.audio.nsng.cngbasemagnitude"
#define INTERNAL_KEY_RTC_AUDIO_NSNG_STRATEGY                  "che.audio.nsng.strategy"

#define INTERNAL_KEY_RTC_AUDIO_AIMD_VALUE                     "che.audio.aimd_value"
#define INTERNAL_KEY_RTC_AUDIO_MAX_MIX_PARTICIPANTS           "che.audio.max_mixed_participants"
#define INTERNAL_KEY_RTC_AUDIO_PLAYOUT_UID_ANONYMOUS          "che.audio.playout_uid_anonymous"
#define INTERNAL_KEY_RTC_AUDIO_CONFIG_APPLY_SOURCE            "che.audio.config_apply_source"
#define INTERNAL_KEY_RTC_AUDIO_FROZEN_TYPE_IN_API             "che.audio.frozen_type_in_api"
#define INTERNAL_KEY_RTC_AUDIO_PROFILE                        "che.audio.profile"
#define INTERNAL_KEY_RTC_AUDIO_DUMP_PATH                      "che.audio.dump_path"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_PITCH_SMOOTHER      "che.audio.ps.enable"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_HOWLING_CONTROL     "che.audio.livehc.enable"
#define CONFIGURABLE_KEY_RTC_AUDIO_ACTIVE_SPEAKER_SWITCH_RATE "che.audio.active_speaker_switch_rate"
#define CONFIGURABLE_KEY_RTC_AUDIO_APM_DUMP                   "che.audio.apm_dump"
#define CONFIGURABLE_KEY_RTC_AUDIO_FRAME_DUMP                 "che.audio.frame_dump"
#define CONFIGURABLE_KEY_RTC_AUDIO_CUSTOM_BITRATE             "che.audio.custom_bitrate"
#define CONFIGURABLE_KEY_RTC_AUDIO_CUSTOM_PAYLOAD_TYPE        "che.audio.custom_payload_type"
#define CONFIGURABLE_KEY_RTC_AUDIO_USE_MEDIA_VOLUME_IN_BLUETOOTH  "che.audio.use_media_volume_in_bluetooth"
#define CONFIGURABLE_KEY_RTC_AUDIO_USE_MEDIA_VOLUME_IN_HEADSET    "che.audio.use_media_volume_in_headset"
#define CONFIGURABLE_KEY_RTC_AUDIO_USE_MEDIA_VOLUME_IN_AUDIENCE   "che.audio.use_media_volume_in_audience"
#define CONFIGURABLE_KEY_RTC_AUDIO_USE_MEDIA_VOLUME_IN_SOLO       "che.audio.use_media_volume_in_solo"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_OPENSL              "che.audio.opensl"
#define CONFIGURABLE_KEY_RTC_AUDIO_BANNED_SL_LEVEL            "che.audio.banned_sl_level"
#define CONFIGURABLE_KEY_RTC_AUDIO_HIGH_QUALITY_ENABLE_OPENSL_WITH_HEADSET "che.audio.highQuality.enableOpenSL.withHeadset"
#define CONFIGURABLE_KEY_RTC_AUDIO_IO_BUFFER_PERIOD_WITH_OPENSL "che.audio.opensl_io_buffer_period"
#define CONFIGURABLE_KEY_RTC_AUDIO_OBOE_ENABLE                "che.audio.oboe.enable"
#define CONFIGURABLE_KEY_RTC_AUDIO_OBOE_ENABLE_EXCLUSIVE_MODE "che.audio.oboe_enable_exclusive_mode"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_ESTIMATED_DEVICE_DELAY "che.audio.enable_estimated_device_delay"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_PREFERRED_AEC_DELAY "che.audio.enable_preferred_aec_delay"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_LOWLATENCY_CAPTURE  "che.audio.enable_lowlatency_capture"
#define CONFIGURABLE_KEY_RTC_AUDIO_ADM_LAYER                  "che.audio.adm_layer"
#define CONFIGURABLE_KEY_RTC_AUDIO_ADM_SOURCE                 "che.audio.adm_source"
#define CONFIGURABLE_KEY_RTC_AUDIO_ADM_FALLBACK_ENABLE        "che.audio.adm_fallback.enable"
#define CONFIGURABLE_KEY_RTC_AUDIO_DUCK_OTHERS                "che.audio.duck.others"
#define CONFIGURABLE_KEY_RTC_AUDIO_RESTART_WHEN_INTERRUPTED   "che.audio.restartWhenInterrupted"
#define CONFIGURABLE_KEY_RTC_AUDIO_INPUT_CHANNELS             "che.audio.input_channels"
#define CONFIGURABLE_KEY_RTC_AUDIO_INPUT_SAMPLE_RATE          "che.audio.input_sample_rate"
#define CONFIGURABLE_KEY_RTC_AUDIO_OUTPUT_CHANNELS            "che.audio.output_channels"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_HARDWARE_EAR_MONITOR "che.audio.enable_hardware_ear_monitor"
#define CONFIGURABLE_KEY_RTC_AUDIO_FORCE_USE_MEDIA_VOLUME     "che.audio.force_use_media_volume"
#define CONFIGURABLE_KEY_RTC_AUDIO_FORCE_BLUETOOTH_A2DP       "che.audio.force_bluetooth_a2dp"
#define CONFIGURABLE_KEY_RTC_AUDIO_PLAYBUFSIZE_FACTOR         "che.audio.playbufsize_factor"
#define CONFIGURABLE_KEY_RTC_AUDIO_RECORD_DEVBUF_DURATION     "che.audio.record_devbuf_duration_ms"
#define CONFIGURABLE_KEY_RTC_AUDIO_PROCESS_BLACK_LIST         "che.audio.process_black_list"
#define CONFIGURABLE_KEY_RTC_AUDIO_OPUS_HW_ENCODE             "che.audio.opus_hw_encode"
#define CONFIGURABLE_KEY_RTC_AUDIO_OPUS_HW_DECODE             "che.audio.opus_hw_decode"
#define CONFIGURABLE_KEY_RTC_AUDIO_CODEC_OPUS_CELT            "che.audio.opus_celt_only"
#define CONFIGURABLE_KEY_RTC_AUDIO_MAC_USE_AUDIO_UNIT_HAL     "che.audio.mac_use_audio_unit_hal"
#define CONFIGURABLE_KEY_RTC_AUDIO_WIN_ENABLE_MICBOOST        "che.audio.win_enable_microphone_boost"
#define CONFIGURABLE_KEY_RTC_AUDIO_SCENARIO                   "che.audio.scenario"
#define CONFIGURABLE_KEY_RTC_AUDIO_UPLINK_GAIN                "che.audio.uplink_gain"
#define CONFIGURABLE_KEY_RTC_AUDIO_DWLINK_GAIN                "che.audio.downlink_gain"
#define CONFIGURABLE_KEY_RTC_AUDIO_MAC_LOOPBACK_ALLOW_DEVICE_CHANGE "che.audio.mac.loopback.allow_device_change"
#define CONFIGURABLE_KEY_RTC_AUDIO_MAC_LOOPBACK_OUTPUT_DEVICE "che.audio.mac.loopback.default_output_device"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_MIC_SELECTION       "che.audio.enable_mic_selection"

// audio adm/apm/acm/pipeline related parameters end

// audio network related parameters begin
#define INTERNAL_KEY_RTC_AUDIO_MAX_TARGET_DELAY               "che.audio.max_target_delay"
#define INTERNAL_KEY_RTC_AUDIO_UPLINK_MAX_RETRY_TIMES         "che.audio.uplink_max_retry_times"
#define INTERNAL_KEY_RTC_AUDIO_DOWNLINK_MAX_RETRY_TIMES       "che.audio.downlink_max_retry_times"
#define INTERNAL_KEY_RTC_AUDIO_HIGH_QUALITY_MODE              "che.audio.high_quality_mode"
#define INTERNAL_KEY_RTC_AUDIO_NETWORK_OPTIMIZED              "che.audio.network_optimized"
#define INTERNAL_KEY_RTC_AUDIO_UPLINK_MAX_FEC_FRAME           "che.audio.uplink_max_fec_frame"
#define INTERNAL_KEY_RTC_AUDIO_QUALITY_INDICATION             "che.audio.quality_indication"
#define INTERNAL_KEY_RTC_AUDIO_DWLINK_MAX_ARQ                 "che.audio.dwlink.max_arq"
#define INTERNAL_KEY_RTC_AUDIO_DWLINK_ARQ_TO_RSFEC            "che.audio.dwlink.arq_to_rsfec"
#define INTERNAL_KEY_RTC_AUDIO_NETEQ_DUMP_LEVEL               "che.audio.neteq.dump_level"
#define INTERNAL_KEY_RTC_AUDIO_NETEQ_DUMP_PATH                "che.audio.neteq.dump_path"
#define INTERNAL_KEY_RTC_AUDIO_NETEQ_LIMIT_PROB               "che.audio.neteq.limit_probability"
#define INTERNAL_KEY_RTC_AUDIO_NETEQ_LOWER_LIMIT_PROBABILITY  "che.audio.neteq.lower_limit_probability"
#define INTERNAL_KEY_RTC_AUDIO_AQM_THRESHOLD                  "che.audio.aqm_threshold"
#define CONFIGURABLE_KEY_RTC_AUDIO_NETEQ_FILTER_TARGET_LOSS   "che.audio.neteq.filter_target_loss"
#define CONFIGURABLEL_KEY_RTC_AUDIO_NETEQ_FILTER_MAX_WINDOW   "che.audio.neteq.filter_max_window"
#define CONFIGURABLEL_KEY_RTC_AUDIO_NETEQ_EANBLE_EXPIRED_PEAK_DECTOR "che.audio.neteq.enable_expired_peak_dector"
#define CONFIGURABLEL_KEY_RTC_AUDIO_NETEQ_MAX_EXCEED_TIME_MS  "che.audio.neteq.max_exceed_time_ms"
#define CONFIGURABLE_KEY_RTC_AUDIO_NETEQ_FILTER_MAX_DUP_NUM   "che.audio.neteq.filter_max_duplicte_num"
#define CONFIGURABLE_KEY_RTC_AUDIO_BITRATE_LEVEL              "che.audio.bitrate_level"
#define INTERNAL_KEY_RTC_AUDIO_FEC                            "che.audio.fec"
#define INTERNAL_KEY_RTC_AUDIO_RSFEC                          "che.audio.rsfec"
#define CONFIGURABLE_KEY_RTC_AUDIO_PRESET_MAX_BITRATE         "che.audio.preset_max_bitrate"
#define CONFIGURABLE_KEY_RTC_AUDIO_BITRATE_RATIO_BASED_VIDEO  "che.audio.bitrate_ratio_based_video"
#define CONFIGURABLE_KEY_RTC_AUDIO_EXTRA_DELAY                "che.audio.extra_delay"
#define CONFIGURABLE_KEY_RTC_AUDIO_DYNAMIC_MAX_BITRATE        "che.audio.dynamic_max_bitrate"
#define CONFIGURABLE_KEY_RTC_AUDIO_CC                         "che.audio.cc"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_REXFER_CONTROL      "che.audio.enable_rexfer_control"
#define CONFIGURABLE_KEY_RTC_AUDIO_FILTER_STREAMS             "che.audio.filter_streams"
#define CONFIGURABLE_KEY_RTC_AUDIO_UPLINK_FILTERABLE          "che.audio.uplink_filterable"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_RSFEC_IN_VIDEO      "che.audio.enable_rsfec_in_video"
#define CONFIGURABLE_KEY_RTC_AUDIO_ENABLE_RSFEC               "che.audio.enable_rsfec"
#define CONFIGURABLE_KEY_RTC_AUDIO_NEW_STRATEGY_RSFEC         "che.audio.new_strategy_rsfec"
#define CONFIGURABLE_KEY_RTC_AUDIO_DWLINK_MAX_ARQ             INTERNAL_KEY_RTC_AUDIO_DWLINK_MAX_ARQ
#define CONFIGURABLE_KEY_RTC_AUDIO_DWLINK_ARQ_TO_RSFEC        INTERNAL_KEY_RTC_AUDIO_DWLINK_ARQ_TO_RSFEC
#define CONFIGURABLE_KEY_RTC_AUDIO_NETEQ_DUMP_LEVEL           INTERNAL_KEY_RTC_AUDIO_NETEQ_DUMP_LEVEL
#define CONFIGURABLE_KEY_RTC_AUDIO_NETEQ_DUMP_PATH            INTERNAL_KEY_RTC_AUDIO_NETEQ_DUMP_PATH
#define CONFIGURABLE_KEY_RTC_AUDIO_NETEQ_LIMIT_PROB           INTERNAL_KEY_RTC_AUDIO_NETEQ_LIMIT_PROB
#define CONFIGURABLE_KEY_RTC_AUDIO_NETEQ_LOWER_LIMIT_PROBABILITY INTERNAL_KEY_RTC_AUDIO_NETEQ_LOWER_LIMIT_PROBABILITY
#define CONFIGURABLE_KEY_AUDIO_NETEQ_VERSION                  "che.audio.neteq_version"
#define CONFIGURABLE_KEY_RTC_AUDIO_NETEQ_PREBUFFER            "che.audio.neteq.prebuffer"
#define CONFIGURABLE_KEY_RTC_AUDIO_NETEQ_PREBUFFER_MAX_DELAY  "che.audio.neteq.prebuffer_max_delay"
#define CONFIGURABLE_KEY_RTC_AUDIO_NETEQ_TARGETLEVEL_OFFSET   "che.audio.neteq.targetlevel_offset"
#define CONFIGURABLE_KEY_RTC_AUDIO_BLOCKFEC_AUT_ADAPT         "rtc.enable_audio_blockfec_aut_adapt"
// audio network related parameters end

#define INTERNAL_KEY_RTC_SDK_IN_BACKGROUND                    "rtc.sdk_in_background"
#define INTERNAL_KEY_RTC_VIDEO_MUTE_ME                        "rtc.video.mute_me"
#define INTERNAL_KEY_RTC_VIDEO_MUTE_PEERS                     "rtc.video.mute_peers"
#define INTERNAL_KEY_RTC_VIDEO_SET_DEFAULT_MUTE_PEERS         "rtc.video.set_default_mute_peers"
#define INTERNAL_KEY_RTC_VIDEO_MUTE_PEER                      "rtc.video.mute_peer"
#define INTERNAL_KEY_RTC_VIDEO_SET_REMOTE_VIDEO_STREAM        "rtc.video.set_remote_video_stream"
#define INTERNAL_KEY_RTC_VIDEO_SET_REMOTE_DEFAULT_VIDEO_STREAM_TYPE "rtc.video.set_remote_default_video_stream_type"
#define INTERNAL_KEY_RTC_VIDEO_CAPTURE                        "rtc.video.capture"
#define INTERNAL_KEY_RTC_VIDEO_ENABLED                        "rtc.video.enabled"
#define INTERNAL_KEY_RTC_VIDEO_HAS_PUBLISHED_STREAM           "rtc.video.has_published_stream"
#define INTERNAL_KEY_RTC_VIDEO_PREVIEW                        "rtc.video.preview"
#define INTERNAL_KEY_RTC_VIDEO_AUDIENCE_PREVIEW               "rtc.video.audience_preview"
#define INTERNAL_KEY_RTC_VIDEO_LOCAL_MIRRORED                 "rtc.video.local_mirrored"
#define INTERNAL_KEY_RTC_VIDEO_BITRATE_LIMIT                  "rtc.video.bitrate_limit"
#define INTERNAL_KEY_RTC_VIDEO_PROFILE                        "rtc.video.profile"
#define INTERNAL_KEY_RTC_VIDEO_ENGINE_PROFILE                 "rtc.video.engine_profile"
#define INTERNAL_KEY_RTC_VIDEO_CACHE                          "rtc.video.cache"
#define INTERNAL_KEY_RTC_VIDEO_CODEC                          "rtc.video.codec"
#define INTERNAL_KEY_RTC_VIDEO_PREFER_FRAME_RATE              "rtc.video.prefer_frame_rate"
#define INTERNAL_KEY_RTC_VIDEO_WEB_H264_INTEROP_ENABLE        "rtc.video.web_h264_interop_enable"
#define CONFIGURABLE_KEY_RTC_VIDEO_CUSTOM_PROFILE             "rtc.video.custom_profile"
#define INTERNAL_KEY_RTC_VIDEO_UPLINK_MAX_RETRY_TIMES         "rtc.video.uplink_max_retry_times"
#define INTERNAL_KEY_RTC_VIDEO_DOWNLINK_MAX_RETRY_TIMES       "rtc.video.downlink_max_retry_times"
#define INTERNAL_KEY_RTC_VIDEO_DOWNLINK_MAX_RETRY_TIMES_AUDIENCE "rtc.video.downlink_max_retry_times_auidence"
#define INTERNAL_KEY_RTC_VIDEO_WIFI_ACC_ENABLE                "rtc.video.wifi_acc_enable"
#define INTERNAL_KEY_RTC_NEW_VIDEO_BILLING                    "rtc.new_video_billing"
#define INTERNAL_KEY_RTC_VIDEO_BILLING_TIMEOUT                "rtc.video_billing_timeout"
#define INTERNAL_KEY_RTC_PEER_OFFLINE_PERIOD                  "rtc.peer.offline_period"
#define INTERNAL_KEY_RTC_CONNECTION_TIMEOUT_PERIOD            "rtc.connection_timeout_period"
#define INTERNAL_KEY_RTC_CHANNEL_MODE                         "rtc.channel_mode"
#define INTERNAL_KEY_RTC_AP_PORT                              "rtc.ap_port"
#define INTERNAL_KEY_RTC_VOCS_PORT                            "rtc.vocs_port"
#define INTERNAL_KEY_RTC_STUN_PORT                            "rtc.stun_port"
#define INTERNAL_KEY_RTC_LASTMILE_PROBE_TEST                  "rtc.lastmile_probe_test"
#define INTERNAL_KEY_RTC_AP_LIST                              "rtc.ap_list"
#define INTERNAL_KEY_RTC_VOCS_LIST                            "rtc.vocs_list"
#define CONFIGURABLE_KEY_RTC_VOS_IP_PORT_LIST                 "rtc.vos_list"
#define INTERNAL_KEY_RTC_PRIORITY_VOS_IP_PORT_LIST            "rtc.priority_vos_list"
#define INTERNAL_KEY_RTC_STUN_PORT                            "rtc.stun_port"
#define INTERNAL_KEY_RTC_USER_ACCOUNT_PORT                    "rtc.user_account_server_port"
#define INTERNAL_KEY_RTC_ICE_LIST                             "rtc.ice_list"
#define INTERNAL_KEY_RTC_STUN_LIST                            "rtc.stun_list"
#define INTERNAL_KEY_RTC_ICE_LIST2                            "rtc.ice_list2"
#define INTERNAL_KEY_RTC_NETOB                                "rtc.netob"
#define INTERNAL_KEY_RTC_PROXY_SERVER                         "rtc.proxy_server"
#define INTERNAL_KEY_RTC_ACCESS_WHICH_PROXY_ENV               "rtc.access_which_proxy_env"
#define INTERNAL_KEY_RTC_ENABLE_PROXY_SERVER                  "rtc.enable_proxy"
#define INTERNAL_KEY_RTC_FORCE_PROXY_IF_ENABLED               "rtc.force_proxy_if_enabled"
#define INTERNAL_KEY_RTC_AUTOFALLBACK                         "rtc.fallback_option"
#define INTERNAL_KEY_RTC_CROSS_CHANNEL_PARAM                  "rtc.cross_channel_param"
#define INTERNAL_KEY_RTC_CROSS_CHANNEL_ENABLED                "rtc.cross_channel_enabled"
#define INTERNAL_KEY_RTC_ACTIVE_VOS_LIST                      "rtc.active_vos_list"
#define INTERNAL_KEY_RTC_JOINED_VOS                           "rtc.joined.vos"
#define INTERNAL_KEY_RTC_LOCAL_PUBLISH_FALLBACK_OPTION        "rtc.local_publish_fallback_option"
#define INTERNAL_KEY_RTC_REMOTE_SUBSCRIBE_FALLBACK_OPTION     "rtc.remote_subscribe_fallback_option"
#define INTERNAL_KEY_RTC_PUBLIC_DOMAIN_LIST                   "rtc.public_domain_list"
#define INTERNAL_KEY_RTC_VOET_LIST                            "rtc.voet_list"
#define INTERNAL_KEY_RTC_VOET_PORT_LIST                       "rtc.voet_port_list"
#define INTERNAL_KEY_RTC_SIGNAL_DEBUG                         "rtc.signal_debug"
#define INTERNAL_KEY_RTC_TRANSPORT_QUALITY_INDICATION         "rtc.transport_quality_indication"
#define INTERNAL_KEY_RTC_COMPATIBLE_MODE                      "rtc.compatible_mode"
#define INTERNAL_KEY_RTC_CLIENT_TYPE                          "rtc.client_type"
#define INTERNAL_KEY_RTC_EXTENSION_PROVIDER                   "rtc.extension_provider"
#define INTERNAL_KEY_RTC_REPORT_LEVEL                         "rtc.report_level"
#define INTERNAL_KEY_RTC_CHANNEL_PROFILE                      "rtc.channel_profile"
#define INTERNAL_KEY_RTC_CLIENT_ROLE                          "rtc.client_role"
#define CONFIGURABLE_KEY_RTC_AUDIENCE_LATENCY_LEVEL           "rtc.audience_latency_level"
#define INTERNAL_KEY_RTC_DUAL_STREAM_MODE                     "rtc.dual_stream_mode"
#define INTERNAL_KEY_RTC_FORCE_UNIFIED_COMMUNICATION_MODE     "rtc.force_unified_communication_mode"
#define INTERNAL_KEY_RTC_TRY_P2P_ONLY_ONCE                    "rtc.try_p2p_only_once"
#define INTERNAL_KEY_RTC_APPLY_DEFAULT_CONFIG                 "rtc.apply_default_config"
#define INTERNAL_KEY_RTC_CACHE_CONFIG                         "rtc.cache_config"
#define INTERNAL_KEY_RTC_DUAL_SIGNALING_MODE                  "rtc.dual_signaling_mode"
#define INTERNAL_KEY_RTC_LIVE_DUAL_LBS_MODE                   "rtc.live_dual_lbs_mode"
#define INTERNAL_KEY_RTC_GEN_NOTIFICATION_WITH_ID             "rtc.gen_notification_with_id"
#define INTERNAL_KEY_RTC_UPLOAD_LOG                           "rtc.upload_log"
#define INTERNAL_KEY_RTC_LOG_FILE                             "rtc.log_file"
#define INTERNAL_KEY_RTC_LOG_SIZE                             "rtc.log_size"
#define INTERNAL_KEY_RTC_LOG_FILTER                           "rtc.log_filter"
#define INTERNAL_KEY_RTC_EXTENSION_LIST                       "rtc.extension_list"
#define INTERNAL_KEY_RTC_REQ_JOIN_PUBLISHER                   "rtc.req.join_publisher"
#define INTERNAL_KEY_RTC_RES_JOIN_PUBLISHER                   "rtc.res.join_publisher"
#define INTERNAL_KEY_RTC_REQ_REMOVE_PUBLISHER                 "rtc.req.remove_publisher"
#define INTERNAL_KEY_RTC_ENABLE_API_TRACER                    "rtc.enable_api_tracer"
#define INTERNAL_KEY_RTC_RECORDING_CONFIG                     "rtc.recording.config"
#define INTERNAL_KEY_RTC_CAPABILITIES                         "rtc.capabilities"
#define INTERNAL_KEY_RTC_USER_ACCOUNT_SERVER_LIST             "rtc.user_account_server_list"
#define INTERNAL_KEY_RTC_WORK_MANAGER_ACCOUNT_LIST            "rtc.work_manager_account_list"
#define INTERNAL_KEY_RTC_WORK_MANAGER_ADDR_LIST               "rtc.work_manager_addr_list"
#define INTERNAL_KEY_RTC_MIX_WORK_MANAGER_ACCOUNT             "rtc.mix_work_manager_account"
#define INTERNAL_KEY_RTC_MIX_WORK_MANAGER_ADDRESS             "rtc.mix_work_manager_address"
#define INTERNAL_KEY_RTC_RAW_WORK_MANAGER_ACCOUNT             "rtc.raw_work_manager_account"
#define INTERNAL_KEY_RTC_RAW_WORK_MANAGER_ADDRESS             "rtc.raw_work_manager_address"
#define INTERNAL_KEY_RTC_UAP_TLS_DOMAIN                       "rtc.uap_tls_domain"
#define INTERNAL_KEY_RTC_REPORT_TYPE                          "rtc.report_type"
#define INTERNAL_KEY_RTC_USING_UI_KIT                         "rtc.using_ui_kit"
#define INTERNAL_KEY_RTC_VIDEO_MAX_METADATA_SIZE              "rtc.video.max_metadata_size"

#define CONFIGURABLE_KEY_RTC_UAP_USER_IP                      "rtc.uap_user_ip"
#define CONFIGURABLE_KEY_RTC_UAP_REGION                       "rtc.uap_region"
#define CONFIGURABLE_KEY_RTC_UAP_ENABLE_TOKEN007              "rtc.uap_enable_token007"
#define CONFIGURABLE_KEY_UAP_ENABLE_QUERY_STREAMS             "rtc.uap_enable_query_streams"
#define CONFIGURABLE_KEY_RTC_VIDEO_PLAYOUT_DELAY_MAX          "rtc.video.playout_delay_max"
#define CONFIGURABLE_KEY_RTC_VIDEO_PLAYOUT_DELAY_MIN          "rtc.video.playout_delay_min"
#define CONFIGURABLE_KEY_RTC_VIDEO_INTERACTIVE_AUDIENCE_PLAYOUT_DELAY_MAX   "rtc.video.interactive_audience_playout_delay_max"
#define CONFIGURABLE_KEY_RTC_VIDEO_INTERACTIVE_AUDIENCE_PLAYOUT_DELAY_MIN   "rtc.video.interactive_audience_playout_delay_min"
#define CONFIGURABLE_KEY_RTC_VIDEO_BROADCASTER_PLAYOUT_DELAY_MAX      "rtc.video.broadcaster_playout_delay_max"
#define CONFIGURABLE_KEY_RTC_VIDEO_BROADCASTER_PLAYOUT_DELAY_MIN      "rtc.video.broadcaster_playout_delay_min"
#define CONFIGURABLE_KEY_RTC_AUDIENCE_LOW_LATENCY             "rtc.audience_low_latency"

//adapt main version
#define CONFIGURABLE_KEY_RTC_MIN_PLAYOUT_DELAY_SPEAKER        "rtc.min_playout_delay_speaker"
#define CONFIGURABLE_KEY_RTC_MIN_PLAYOUT_DELAY                "rtc.min_playout_delay"

#define CONFIGURABLE_KEY_RTC_E2E_DELAY_MAX                    "rtc.net.maxS2LDelay"
#define CONFIGURABLE_KEY_RTC_DECODE_RENDER_DELAY              "rtc.video.decodeAndRenderDelay"
#define CONFIGURABLE_KEY_RTC_BUFFER_MODIFY_PACER              "rtc.video.jitterModifyPacer"
#define CONFIGURABLE_KEY_RTC_BUFFER_DELAY_MIN                 "rtc.video.minPlayoutdDelayRtls"
#define CONFIGURABLE_KEY_RTC_ENABLE_SYNC_RENDER               "rtc.enable_audience_sync_render_rtt"
#define CONFIGURABLE_KEY_RTC_ENABLE_SYNC_RENDER_NTP           "rtc.video.enable_sync_render_ntp"
#define CONFIGURABLE_KEY_RTC_ENABLE_VOQA_JITTER               "rtc.enable_voqa_jitter"
#define CONFIGURABLE_KEY_RTC_VIDEO_JbAdaptScreenShare         "che.video.JbAdaptScreenShare"

#define INTERNAL_KEY_RTC_DISABLE_INTRA_REQUEST                "rtc.disable_intra_request"
#define CONFIGURABLE_KEY_FRAME_INTERVAL_INTRA_REQUEST         "rtc.max_intra_request_key_interval"
#define CONFIGURABLE_KEY_FRAME_INTERVAL_PERIOD                "che.video.keyFrameInterval"
#define CONFIGURABLE_KEY_RTC_UPLOAD_LOG_REQUEST               "rtc.upload_log_request"
#define CONFIGURABLE_KEY_RTC_USER_UPLOAD_LOG_REQUEST          "rtc.user_upload_log_request"
#define CONFIGURABLE_KEY_RTC_ENABLE_USER_UPLOAD_LOG_REQUEST   "rtc.enable_upload_log_file_api"
#define CONFIGURABLE_KEY_RTC_AUTO_UPLOAD_LOG                  "rtc.enable_auto_log_upload"
#define CONFIGURABLE_KEY_RTC_AUTO_UPLOAD_LOG_RATE             "rtc.auto_log_upload_rate_s"
#define CONFIGURABLE_KEY_RTC_WIN_ALLOW_MAGNIFICATION          "rtc.win_allow_magnification"
#define CONFIGURABLE_KEY_RTC_WIN_ALLOW_DIRECTX                "rtc.win_allow_directx"
#define CONFIGURABLE_KEY_SDK_DEBUG_ENABLE                     "rtc.debug.enable"
#define INTERNAL_KEY_SDK_DEBUG_COMMAND                        "rtc.debug.command"
#define INTERNAL_KEY_RTC_TEST_CONFIG_SERVICE                  "rtc.test_config_service"
#define CONFIGURABLE_KEY_RTC_REPORT_CONFIG                    "rtc.report_config"
#define CONFIGURABLE_KEY_RTC_IP_AREACODE                      OBFUSCATED("rtc.ip_area_code")
#define CONFIGURABLE_KEY_RTC_IP_GLOBAL                        OBFUSCATED("rtc.ip_global_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_CN                   OBFUSCATED("rtc.ip_cn_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_NA                   OBFUSCATED("rtc.ip_na_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_EUR                  OBFUSCATED("rtc.ip_eur_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_AS                   OBFUSCATED("rtc.ip_as_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_JP                   OBFUSCATED("rtc.ip_jp_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_IN                   OBFUSCATED("rtc.ip_indian_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_OCEANIA              OBFUSCATED("rtc.ip_oceania_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_SA                   OBFUSCATED("rtc.ip_south_america_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_AFRICA               OBFUSCATED("rtc.ip_africa_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_KR                   OBFUSCATED("rtc.ip_south_korea_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_HKMC                 OBFUSCATED("rtc.ip_hongkong_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_US                   OBFUSCATED("rtc.ip_us_area")
#define CONFIGURABLE_KEY_RTC_IP_AREACODE_OVS                  OBFUSCATED("rtc.ip_oversea_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_GLOBAL                    OBFUSCATED("rtc.ip_tls_global_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_CN               OBFUSCATED("rtc.ip_tls_cn_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_NA               OBFUSCATED("rtc.ip_tls_na_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_EUR              OBFUSCATED("rtc.ip_tls_eur_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_AS               OBFUSCATED("rtc.ip_tls_as_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_JP               OBFUSCATED("rtc.ip_tls_jp_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_IN               OBFUSCATED("rtc.ip_tls_indian_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_OC               OBFUSCATED("rtc.ip_tls_oceania_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_SA               OBFUSCATED("rtc.ip_tls_south_america_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_AF               OBFUSCATED("rtc.ip_tls_africa_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_KR               OBFUSCATED("rtc.ip_tls_korea_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_HKMC             OBFUSCATED("rtc.ip_tls_hk_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_US               OBFUSCATED("rtc.ip_tls_us_area")
#define CONFIGURABLE_KEY_RTC_IP_TLS_AREACODE_OVS              OBFUSCATED("rtc.ip_tls_oversea_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_AREACODE_CN             OBFUSCATED("rtc.proxy.ip_cn_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_AREACODE_NA             OBFUSCATED("rtc.proxy.ip_na_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_AREACODE_EUR            OBFUSCATED("rtc.proxy.ip_eur_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_AREACODE_AS             OBFUSCATED("rtc.proxy.ip_as_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_AREACODE_HKMC           OBFUSCATED("rtc.proxy.ip_hk_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_AREACODE_US             OBFUSCATED("rtc.proxy.ip_us_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_TLS_AREACODE_CN         OBFUSCATED("rtc.proxy.ip_tls_cn_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_TLS_AREACODE_NA         OBFUSCATED("rtc.proxy.ip_tls_na_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_TLS_AREACODE_EUR        OBFUSCATED("rtc.proxy.ip_tls_eur_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_TLS_AREACODE_AS         OBFUSCATED("rtc.proxy.ip_tls_as_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_TLS_AREACODE_HKMC       OBFUSCATED("rtc.proxy.ip_tls_hk_area")
#define CONFIGURABLE_KEY_RTC_PROXY_IP_TLS_AREACODE_US         OBFUSCATED("rtc.proxy.ip_tls_us_area")
#define CONFIGURABLE_KEY_RTC_ENABLE_DNS                       "rtc.enable_dns"
#define CONFIGURABLE_KEY_RTC_AUT_CRYPTO_FOR_VOS_LINK          "rtc.aut_crypto_for_vos_link"
#define CONFIGURABLE_KEY_RTC_ENABLE_CRYPTO_ACCESS             "rtc.enable_crypto_access"
#define CONFIGURABLE_KEY_RTC_ENABLE_TDS_REQUEST               "rtc.enable_tds_request"
#define INTERNAL_KEY_RTC_PROXY_AP_PORTS                       "rtc.proxy.ap_ports"
#define INTERNAL_KEY_RTC_PROXY_AP_AUT_PORTS                   "rtc.proxy.ap_aut_ports"
#define INTERNAL_KEY_RTC_PROXY_AP_TLS_PORTS                   "rtc.proxy.ap_tls_ports"
#define INTERNAL_KEY_RTC_PROXY_AP_TLS_443_PORTS               "rtc.proxy.tls_443_ports"
#define INTERNAL_KEY_RTC_JOIN_CHANNEL_TIMEOUT                 "rtc.join_channel_timeout"
#define INTERNAL_KEY_RTC_XLA_STATE_CHANGE_TIMEOUT             "rtc.xla_state_change_timeout"
#define CONFIGURABLE_KEY_RTC_FIRST_FRAME_DECODED_TIMEOUT      "rtc.first_frame_decoded_timeout"
#define CONFIGURABLE_KEY_RTC_JOIN_TO_FIRST_DECODED_TIMEOUT    "rtc.join_to_first_decoded_timeout"
#define CONFIGURABLE_KEY_RTC_VIDEO_ENABLED_HW_ENCODER         KEY_RTC_VIDEO_ENABLED_HW_ENCODER
#define CONFIGURABLE_KEY_RTC_VIDEO_HARDWARE_ENCODEING         KEY_RTC_VIDEO_HARDWARE_ENCODEING
#define CONFIGURABLE_KEY_RTC_VIDEO_H264_HWENC                 KEY_RTC_VIDEO_H264_HWENC
#define CONFIGURABLE_KEY_RTC_VIDEO_ENABLE_HW_DECODER          KEY_RTC_VIDEO_ENABLED_HW_DECODER
#define CONFIGURABLE_KEY_RTC_VIDEO_HARDWARE_DECODING          KEY_RTC_VIDEO_HARDWARE_DECODING
#define CONFIGURABLE_VIDEO_THRESHOLD_SWITCH_SOFTDECODER       "rtc.video_threshold_switch_softdecoder"
#define CONFIGURABLE_KEY_RTC_VIDEO_LOW_STREAM_ENABLED_HW_ENCODER     "rtc.video.low_stream_enable_hw_encoder"
#define INTERNAL_KEY_RTC_ENABLE_DEBUG_LOG                     "rtc.enable_debug_log"
#define INTERNAL_KEY_RTC_START_TRACE                          "rtc.start_trace"
#define INTERNAL_KEY_RTC_STOP_TRACE                           "rtc.stop_trace"
#define CONFIGURABLE_VIDEO_QUICK_INTRA_HIGH_FEC               "rtc.video.quickIntraHighFec"
#define CONFIGURABLE_KEY_VIDEO_LARGEST_REF_DISTANCE           "rtc.video.largest_ref_distance"
#define CONFIGURABLE_ENABLE_NEW_RTO                           "rtc.enable_new_rto"
#define CONFIGURABLE_FEEDBACK_STATS_PERIOD                    "rtc.feedback_statsperiod"
#define CONFIGURABLE_QUICK_REXFER_KEYFRAME                    "rtc.enable_quick_rexfer_keyframe"
#define CONFIGURABLE_KEY_RTC_P2P_SWITCH                       "rtc.enable_p2p"
#define INTERNAL_KEY_RTC_ENABLE_TWO_BYTE_RTP_EXTENSION        "rtc.enable_two_byte_rtp_extension"
#define CONFIGURABLE_KEY_RTC_ENABLE_DUMP                      OBFUSCATED("rtc.enable_xdump")
#define CONFIGURABLE_KEY_RTC_ENABLE_DUMP_FILE                 OBFUSCATED("rtc.enable_xdump_file")
#define CONFIGURABLE_KEY_RTC_ENABLE_DUMP_UPLOAD               OBFUSCATED("rtc.enable_xdump_upload")
#define INTERNAL_KEY_RTC_CRASH_FOR_TEST_PURPOSE               "rtc.crash_for_test_purpose"
#define INTERNAL_KEY_RTC_THREAD_HANG_FOR_TEST_PURPOSE         "rtc.thread_hang_for_test_purpose"
#define CONFIGURABLE_KEY_RAW_AUDIO_MODE                       "che.video.raw_audio_mode"
#define CONFIGURABLE_KEY_BITRATE_ADJUST_RATIO                 KEY_RTC_VIDEO_BITRATE_ADJUST_RATIO
#define CONFIGURABLE_KEY_MINBITRATE_RATIO                     KEY_RTC_VIDEO_MINBITRATE_RATIO
#define CONFIGURABLE_KEY_RTC_ENABLE_CAMERA_CAPTURE_YUV        "rtc.enable_camera_capture_yuv"
#define CONFIGURABLE_KEY_CAMERA_OUTPUT_TYPE                   "che.video.android_camera_output_type"
#define CONFIGURABLE_KEY_RTC_CAMERA_ROTATION                  "rtc.camera_rotation"
#define CONFIGURABLE_KEY_RTC_SECONDARY_CAMERA_ROTATION        "rtc.secondary_camera_rotation"
#define CONFIGURABLE_KEY_ENABLE_WEBRTC_PACER                  "rtc.enable_webrtc_pacer"
#define INTERNAL_KEY_RTC_GATEWAY_RTT                          "rtc.gateway_rtt"
#define CONFIGURABLE_KEY_VIDEO_DEGRADATION_PREFERENCE         KEY_RTC_VIDEO_DEGRADATION_PREFERENCE
#define CONFIGURABLE_KEY_VIDEO_DEGRADATION_FPS_DOWN_STEP      KEY_RTC_VIDEO_DEGRADATION_FPS_DOWN_STEP
#define CONFIGURABLE_KEY_VIDEO_DEGRADATION_FPS_UP_STEP        KEY_RTC_VIDEO_DEGRADATION_FPS_UP_STEP
#define CONFIGURABLE_KEY_RTC_VIDEO_CODEC_TYPE                 KEY_RTC_VIDEO_CODEC_TYPE
#define CONFIGURABLE_KEY_RTC_VIDEO_CODEC_INDEX                KEY_RTC_VIDEO_CODEC_INDEX
#define CONFIGURABLE_KEY_VIDEO_VQC_VERSION                    "rtc.video.vqc_version"
#define CONFIGURABLE_KEY_VIDEO_PACED_SENDER_ENABLED           "rtc.paced_sender_enabled"
#define CONFIGURABLE_KEY_VIDEO_PACED_PADDING_SENDER_ENABLE    "rtc.paced_padding_send_enable"
#define CONFIGURABLE_KEY_VIDEO_SCALABLE_LABEL_MODE            "che.video.scalable_label_mode"
#define CONFIGURABLE_KEY_VIDEO_DYNAMIC_PACED_SENDER           "rtc.video.dynamic_paced_sender"
#define CONFIGURABLE_KEY_VIDEO_PACING_FACTOR                  "rtc.video.pacing_factor"
#define CONFIGURABLE_KEY_VIDEO_PACING_MAX_QUEUE_TIME          "rtc.video.pacing_max_queue_time"
#define CONFIGURABLE_KEY_VIDEO_OVERUSE_DETECTOR_VERSION       "rtc.video.overuse_detector_version"
//TODO(kefan) these vqc parameters should placed in MediaEngineParameterCollection
#define CONFIGURABLE_KEY_VIDEO_VQC_QUICK_ADAPT_NETWORK        "che.video.quick_adapt_network"
#define CONFIGURABLE_KEY_VIDEO_VQC_SCREENSHARE_DETAIL         "che.video.screenShareDetailVqc"
#define CONFIGURABLE_KEY_VIDEO_VQC_SCREENSHARE_DETAIL_MAX_QP  "che.video.screenShareDetailMaxQP"
#define CONFIGURABLE_KEY_VIDEO_VQC_SCREENSHARE_DETAIL_MIN_QP  "che.video.screenShareDetailMinQP"
#define CONFIGURABLE_KEY_VIDEO_VQC_AUTO_RESIZE_TYPE           "che.video.vqc_auto_resize_type"
#define CONFIGURABLE_KEY_VIDEO_VQC_MIN_HOLDTIME_AUTO_RESIZE_ZOOMIN      "che.video.min_holdtime_auto_resize_zoomin"
#define CONFIGURABLE_KEY_VIDEO_VQC_MIN_HOLDTIME_AUTO_RESIZE_ZOOMOUT     "che.video.min_holdtime_auto_resize_zoomout"
#define CONFIGURABLE_KEY_VIDEO_VQC_MIN_FRAMERATE              "che.video.video_min_framerate"
#define CONFIGURABLE_KEY_VIDEO_VQC_QP_ADJUST                  "che.video.qpAdjust"
#define CONFIGURABLE_KEY_VIDEO_VQC_IOS_H265_QPADJUST          "che.video.ios_h265_qpAdjust"
#define CONFIGURABLE_KEY_VIDEO_VQC_SW_H264_QPADJUST           "che.video.sw_h264_qpAdjust"
#define CONFIGURABLE_KEY_VIDEO_VQC_VPX_QPADJUST               "che.video.vpx_qpAdjust"
#define CONFIGURABLE_KEY_VIDEO_VQC_AV1_QPADJUST               "che.video.av1_qpAdjust"
#define CONFIGURABLE_KEY_VIDEO_MIN_QP                         "che.video.minQP"
#define CONFIGURABLE_KEY_VIDEO_MAX_QP                         "che.video.maxQP"
#define CONFIGURABLE_KEY_VIDEO_FRAME_MAX_SIZE                 "che.video.frameMaxSize"
#define CONFIGURABLE_KEY_VIDEO_LOW_BITRATE_COEFF_FOR_AUTO_RESIZE      "che.video.low_br_coeff_for_auto_resize"
#define CONFIGURABLE_KEY_VIDEO_HIGH_BITRATE_COEFF_FOR_AUTO_RESIZE     "che.video.high_br_coeff_for_auto_resize"
#define CONFIGURABLE_KEY_VIDEO_VQC_ADJUST_STEP                 "che.video.vqcadjust_step"
#define CONFIGURABLE_KEY_VIDEO_LOW_FRAMERATE_MODE              "che.video.low_framerate_mode"
#define CONFIGURABLE_KEY_VIDEO_START_FRAMERATE                 "che.video.startFramerate"
#define CONFIGURABLE_KEY_VIDEO_VQC_RES_ADJUST_NUM_LIST         "che.video.vqc_res_adjust_num"
#define CONFIGURABLE_KEY_VIDEO_VQC_LOW_BITRATE_THRESHOLD       "che.video.vqc_low_bitrate_threshold"
#define CONFIGURABLE_KEY_VIDEO_OVERUSE_LOW_LOAD_EST_THRES     "che.video.overuse_low_estimate_threshold"
#define CONFIGURABLE_KEY_VIDEO_OVERUSE_HIGH_LOAD_EST_THRES    "che.video.overuse_high_estimate_threshold"
#define CONFIGURABLE_KEY_VIDEO_OVERUSE_HIGH_FPS_THRES         "che.video.overuse_high_fps_threshold"
#define CONFIGURABLE_KEY_VIDEO_OVERUSE_LOW_FPS_THRES          "che.video.overuse_low_fps_threshold"
#define CONFIGURABLE_KEY_VIDEO_DYNAMIC_SVC_ENABLE             "che.video.dynamic_svc_enable"
#define CONFIGURABLE_KEY_VIDEO_DYNAMIC_SVC_LAYER              "che.video.dynamic_svc_layers"
#define CONFIGURABLE_KEY_VIDEO_DYNAMIC_SVC_ENABLE_THRES       "che.video.dynamic_svc_enable_thres"
#define CONFIGURABLE_KEY_VIDEO_ENABLE_PVC                     "rtc.video.enable_pvc"
#define CONFIGURABLE_KEY_VIDEO_PVC_ONE_MODEL                  "rtc.video.pvc_one_model"
#define CONFIGURABLE_KEY_VIDEO_PVCSUPPORT                     "rtc.video.PvcSupport"
#define CONFIGURABLE_KEY_VIDEO_PVCCONFIG                      "rtc.video.PvcConfig"
#define CONFIGURABLE_KEY_VIDEO_ENABLE_SUPER_RESOLUTION        "rtc.video.enable_sr"
#define CONFIGURABLE_KEY_VIDEO_SUPER_RESOLUTION_SRTYPE        "rtc.video.sr_type"
#define CONFIGURABLE_KEY_RTC_VIDEO_MINOR_STREAM_CONFIG        "che.video.lowBitRateStreamParameter"
#define CONFIGURABLE_KEY_RTC_VIDEO_ENABLE_LOW_BITRATE_STREAM  "che.video.enableLowBitRateStream"
#define CONFIGURABLE_KEY_VIDEO_CAPTURE_HEIGHT                 "che.video.capture_height"
#define CONFIGURABLE_KEY_VIDEO_CAPTURE_WIDTH                  "che.video.capture_width"


#define CONFIGURABLE_KEY_FEC_METHOD                           "rtc.fec_method"
#define CONFIGURABLE_KEY_DEFAULT_FEC_METHOD                   "rtc.default_fec_method"
#define CONFIGURABLE_KEY_FEC_FIX_RATE                         "che.video.videoFecFixedRate"
#define CONFIGURABLE_KEY_ENABLE_CHECK_FOR_DISABLE_FEC         "rtc.video.enable_check_for_disable_fec"
#define CONFIGURABLE_KEY_DM_FEC_WSIZE                         "rtc.dm_wsize"
#define CONFIGURABLE_KEY_FEC_SWITCH_TO_RQ                     "rtc.switch_to_rq"
#define CONFIGURABLE_KEY_DM_FEC_MAXGC                         "rtc.video.dm.maxgc"
#define CONFIGURABLE_KEY_DM_FEC_LOWRED                        "rtc.video.dm.lowred"
#define CONFIGURABLE_KEY_DM_FEC_VERSION                       "rtc.video.dmfec_version"
#define CONFIGURABLE_KEY_DM_FEC_MultipleRedundancy            "rtc.video.multiple_redundancy"
#define CONFIGURABLE_KEY_RTC_PACKET_BUFFER_SIZE               "rtc.video.packet_buffer_size"
#define CONFIGURABLE_KEY_RTC_REXFER_MAX_ADVANCE               "rtc.net.rexfer_max_advance"

#define INTERNAL_KEY_RTC_USE_AUDIO4_PROTOCOL                  OBFUSCATED("rtc.use_audio4")
#define CONFIGURABLE_KEY_VIDEO_HAS_INTRA_REQUEST              "che.video.has_intra_request"
#define CONFIGURABLE_KEY_ENABLE_VIDEO_SENDER_FRAME_DROPPER    "che.video.enable_video_sender_frame_dropper"
#define CONFIGURABLE_KEY_RTC_VIDEO_QUALITY_SCALE_ONLY_ON_AVERAGE_QP         KEY_RTC_VIDEO_QUALITY_SCALE_ONLY_ON_AVERAGE_QP
#define CONFIGURABLE_KEY_RTC_VIDEO_H264_QP_THRESHOLD_LOW      KEY_RTC_VIDEO_H264_QP_THRESHOLD_LOW
#define CONFIGURABLE_KEY_RTC_VIDEO_H264_QP_THRESHOLD_HIGH     KEY_RTC_VIDEO_H264_QP_THRESHOLD_HIGH
#define KEY_RTC_VIDEO_RATE_CONTROL_MODE                       "che.video.rate_control_mode"
#define INTERNAL_KEY_RTC_PRIMARY_FORCED_USING_SCREEN_CAPTURE  "rtc.primary_screen.forced_using_screen_capture"
#define INTERNAL_KEY_RTC_SECONDARY_FORCED_USING_SCREEN_CAPTURE  "rtc.secondary_screen.forced_using_screen_capture"
#define INTERNAL_KEY_RTC_DESENSITISE_IP                       "rtc.desensitize.Ip"
#define INTERNAL_KEY_RTC_JOIN_VOS_TIMEOUT                     "rtc.join_vos_timeout"

#define CONFIGURABLE_VIDEO_FEC_PROTECTION_FACTOR              "rtc.video.fec_protection_factor"
#define CONFIGURABLE_VIDEO_ENABLE_FEC_REXFER                  "rtc.enable_fec_rexfer"
#define CONFIGURABLE_VIDEO_FEC_PROTECTION_RATIO_LEVEL         "rtc.video.fec_protection_ratio_level"
#define CONFIGURABLE_VIDEO_FEC_RATIO_LEVEL_RTT_THRESHOLD      "rtc.video.fec_ratio_level_rtt_threshold"
#define CONFIGURABLE_VIDEO_ENABLE_PEC                         "che.video.enable_pec"
#define CONFIGURABLE_VIDEO_CAMERA_DROP_FRAME_COUNT            "che.video.camera.drop_frame_count"
#define CONFIGURABLE_VIDEO_ANDROID_CAMERA_SELECT              "che.video.android_camera_select"
#define CONFIGURABLE_VIDEO_ANDROID_CAMERA_MIN_LEVEL           "che.video.android_camera_min_level"
#define CONFIGURABLE_VIDEO_ANDROID_YUVCONVERTER_ENABLE_PBO    "rtc.video.yuvconverter_enable_pbo"
#define CONFIGURABLE_VIDEO_ANDROID_YUVCONVERTER_ENABLE_PERF   "rtc.video.yuvconverter_enable_perf"
#define CONFIGURABLE_VIDEO_FREEZE_DIAGNOSE                    "rtc.video.freeze_diagnose"
#define CONFIGURABLE_KEY_VIDEO_QOE_ASSESS                     "rtc.video.qoe"
#define CONFIGURABLE_KEY_VIDEO_QOE_VQA_PROP                   "rtc.video.qoe_vqa_prop"
#define CONFIGURABLE_KEY_VIDEO_QOE_FROZEN_PROP                "rtc.video.qoe_frozen_prop"
#define CONFIGURABLE_VIDEO_ANDROID_CAMERA_PQ_FIRST            "che.video.android_camera_PQ_First"
#define CONFIGURABLE_VIDEO_RECOVER_CAPTURE_ON_FOREGROUND      "che.video.recover_capture_on_foreground"
#define CONFIGURABLE_VIDEO_BRIGHTNESS_DETECTION_INTERVAL      "che.video._brightness_detection_interval"

#define CONFIGURABLE_KEY_RTC_VIDEO_RESET_FRAMERATE_RATIO      "rtc.video.reset_framerate_ratio"
#define CONFIGURABLE_KEY_RTC_VIDEO_RESET_BITRATE_RATIO        "rtc.video.reset_bitrate_ratio"

#define CONFIGURABLE_VIDEO_ENABLE_CHANGE_ENCODER_PROFILE      "rtc.video.enable_change_encoder_profile"
#define CONFIGURABLE_VIDEO_ENABLE_SWH265ENC_MINDEVICESCORE    "rtc.video.minscore_for_swh265enc"

#define CONFIGURABLE_KEY_VIDEO_H264_HW_MIN_RES_LEVEL          "rtc.video.h264_hw_min_res_level"
#define CONFIGURABLE_KEY_VIDEO_ENC_MAX_SLICES                 "che.video.max_slices"
#define CONFIGURABLE_KEY_VIDEO_H264_PROFILE                   "che.video.h264Profile"
#define CONFIGURABLE_KEY_MAX_INTRAREQUEST_KEYFRAME_INTERVAL   "che.video.max_intra_key_interval"
#define CONFIGURABLE_KEY_VIDEO_ENC_BITRATE_ADJUSTMENT_TYPE    "che.video.android_bitrate_adjustment_type"
#define CONFIGURABLE_KEY_VIDEO_ENC_USR_A264                   "che.video.a264_encode"
#define CONFIGURABLE_KEY_VIDEO_ENC_VMAF_CALC                  "che.video.vmafreport"
#define CONFIGURABLE_KEY_VIDEO_ENC_SCREEN_SHARING_SUBCLASS    "che.video.screen_sharing_subclass"
#define CONFIGURABLE_KEY_VIDEO_USE_SINGLE_SLICE               "che.video.useSingleSliceParser"
#define CONFIGURABLE_KEY_VIDEO_RENDER_COLOR_SPACE_ENABLE      "rtc.video.color_space_enable"
#define CONFIGURABLE_KEY_VIDEO_RENDER_VIDEOFULLRANGE          "rtc.video.videoFullrange"
#define CONFIGURABLE_KEY_VIDEO_RENDER_MATRIXCOEFFICIENTS      "rtc.video.matrixCoefficients"
// svc
#define CONFIGURABLE_KEY_VIDEO_SVC_TEMPORAL_LAYERS            "che.video.num_temporal_layers"
#define CONFIGURABLE_KEY_VIDEO_BFRAME_SVC_TEMPORAL_LAYERS     "rtc.video.bframe_svc_num_temporal_layers"

// vp8 encoder switch enable
#define CONFIGURABLE_KEY_VIDEO_VP8_ENC_SWITCH                 "rtc.video.vp8_enc_switch"
//disable vp8 codec negotiation
#define CONFIGURABLE_KEY_VIDEO_VP8_DEC_NEGOTIATION            "che.video.vp8_dec_negotiation"
//265
#define CONFIGURABLE_KEY_VIDEO_H265_DEC_ENABLE                "che.video.h265_dec_enable"
#define CONFIGURABLE_KEY_VIDEO_H265_NEGOCIATION_DISABLE       "che.video.h265_negociation_disable"
// av1
#define CONFIGURABLE_KEY_VIDEO_AV1_DEC_ENABLE                 "che.video.av1_dec_enable"
#define CONFIGURABLE_KEY_VIDEO_AV1_CAMERA_ENABLE              "rtc.video.av1_camera_enable"
#define CONFIGURABLE_KEY_VIDEO_AV1_SCREEN_ENABLE              "rtc.video.av1_screen_enable"
#define CONFIGURABLE_KEY_VIDEO_AV1_ENCODER_THREAD_NUM         "rtc.video.av1_encoder_thread_num"
#define CONFIGURABLE_KEY_VIDEO_H265_MIN_ENC_LEVEL             "che.video.min_enc_level"
#define CONFIGURABLE_KEY_VIDEO_WZ265_DEC_ENABLE               "rtc.video.wz265_dec_enable"

#define CONFIGURABLE_KEY_RTC_ENABLE_NASA2                     OBFUSCATED("rtc.enable_nasa2")

#define CONFIGURABLE_KEY_RTC_PREFER_IPV6                      "rtc.prefer_ipv6"
#define CONFIGURABLE_KEY_RTC_DISABLE_IPV6                     "rtc.disable_ipv6"

#define CONFIGURABLE_KEY_VIDEO_VPR_ENABLE                     "che.video.vpr.enable"
#define CONFIGURABLE_KEY_VIDEO_VPR_INIT_SIZE                  "che.video.vpr.init_size"
#define CONFIGURABLE_KEY_VIDEO_VPR_MAX_SIZE                   "che.video.vpr.max_size"
#define CONFIGURABLE_KEY_VIDEO_VPR_FROZEN_MS_THRES            "che.video.vpr.frozen_ms_thres"
#define CONFIGURABLE_KEY_VIDEO_VPR_FROZEN_RATE_THRES          "che.video.vpr.frozen_rate_thres"
#define CONFIGURABLE_KEY_VIDEO_VPR_ADAPTIVE_THRES             "che.video.vpr.vpr_adaptive_thres"
#define CONFIGURABLE_KEY_VIDEO_VPR_METHOD                     "che.video.vpr.method"
#define CONFIGURABLE_KEY_VIDEO_RETRANS_DETECT_ENABLE          "che.video.retrans_detect_enable"
#define CONFIGURABLE_KEY_VIDEO_REXFER_DELAY_ENABLED           "rtc.video.rexfer_delay_enabled"
#define CONFIGURABLE_KEY_VIDEO_AUDIENCE_REXFER_DALAY_MAX      "rtc.video.audience_rexfer_delay_max_value"
#define CONFIGURABLE_KEY_VIDEO_BROADCASTER_REXFER_DALAY_MAX   "rtc.video.broadcaster_rexfer_delay_max_value"
#define CONFIGURABLE_KEY_VIDEO_DOWN_MAX_RETRY_TIMES           "rtc.video.downMaxRetryTimes"
#define CONFIGURABLE_KEY_VIDEO_UP_MAX_RETRY_TIMES             "rtc.video.upMaxRetryTimes"
#define CONFIGURABLE_KEY_VIDEO_HIGH_LOSS_THRESHOLD            "rtc.video.high_loss_threshold"
#define CONFIGURABLE_KEY_VIDEO_MULTI_REXFER_MODE              "rtc.video.multi_rexfer_mode"
#define CONFIGURABLE_KEY_VIDEO_USE_SENT_TS_ENABLE             "che.video.use_sent_ts_enable"
#define CONFIGURABLE_KEY_RTC_VIDEO_ROTATION                   "rtc.video.rotation"
#define CONFIGURABLE_KEY_RTC_VIDEO_CAPTURE_DELAY_TABLE        "rtc.video.capture_delay_table"
#define CONFIGURABLE_KEY_RTC_LOG_FILTER                       "rtc.log_filter"

#define CONFIGURABLE_KEY_VIDEO_SCALE_TYPE                     "che.video.scale_type"

#define CONFIGURABLE_KEY_VIDEO_SCC_AUTO_FRAMERATE             "che.video.scc_auto_framerate"
#define CONFIGURABLE_KEY_VIDEO_SCC_QUALITY_OPT                "che.video.scc_quality_opt"
#define CONFIGURABLE_KEY_VIDEO_RENDER_D3D9_TEXTURE            "che.video.render.d3d9_texture"
#define CONFIGURABLE_KEY_VIDEO_RENDER_D3D9_RENDER_MODE        "che.video.render.d3d9_render_mode"
#define CONFIGURABLE_KEY_VIDEO_RENDER_BUFFER_QUEUE_SIZE       "che.video.render.buffer_queue_size"

#define CONFIGURABLE_KEY_VIDEO_ENABLE_NEWCC                   "che.video.enableNewCC"
#define CONFIGURABLE_KEY_VIDEO_SMALL_NET_BUFFER               "che.video.detect_small_net_buffer"

#define CONFIGURABLE_KEY_VIDEO_ENABLE_TB_DETECT               "che.video.CC_token_bucket_detect"
#define CONFIGURABLE_KEY_VIDEO_ENABLE_TB_CMCC_BW              "che.video.CC_token_bucket_CMCC_BW"
#define CONFIGURABLE_KEY_VIDEO_ENABLE_TB_BW_DIFF_THRE         "che.video.CC_token_bucket_thre_BW"
#define CONFIGURABLE_KEY_VIDEO_ENABLE_TB_CORR_THRE            "che.video.CC_token_bucket_thre_corr"
#define CONFIGURABLE_KEY_VIDEO_ENABLE_TB_LOSS_THRE            "che.video.CC_token_bucket_thre_loss"

#define INTERNAL_KEY_RTC_NTP_DELAY_DROP_THRESHOLD             "rtc.ntp_delay_drop_threshold"
#define INTERNAL_KEY_RTC_NTP_SEND_REQ_COUNT_EACH_TIME         "rtc.ntp_send_req_count_each_time"
#define INTERNAL_KEY_RTC_NTP_EXP_GROWTH_THRESHOLD             "rtc.ntp_exp_growth_threshold"
#define INTERNAL_KEY_RTC_NTP_CHECK_TIME_INTERVAL              "rtc.ntp_check_time_interval"
#define INTERNAL_KEY_RTC_NTP_DELAY_DROP_RTT_FACTOR            "rtc.ntp_delay_drop_rtt_factor"

#define CONFIGURABLE_KEY_VIDEO_FEC_CODEC                      "rtc.video.fec_codec"
#define INTERNAL_KEY_RTC_VIDEO_ENCODER_WIDTH_ALIGNMENT        "rtc.video.encoder_width_alignment"
#define INTERNAL_KEY_RTC_VIDEO_ENCODER_HEIGHT_ALIGNMENT       "rtc.video.encoder_height_alignment"
#define INTERNAL_KEY_RTC_VIDEO_ENCODER_FORCE_ALIGNMENT        "rtc.video.encoder_force_alignment"
#define CONFIGURABLE_KEY_RTC_VIDEO_DECODER_OUT_BYTE_FRAME     "rtc.video.decoder_out_byte_frame"
#define CONFIGURABLE_KEY_RTC_VIDEO_START_BITRATE              "rtc.video.start_bitrate"
#define CONFIGURABLE_KEY_VIDEO_HWENC_CONFIGURE                "che.video.android_hwenc_config"
#define CONFIGURABLE_KEY_VIDEO_HWDEC_CONFIGURE                "che.video.android_hwdec_config"
#define CONFIGURABLE_KEY_VIDEO_HWENC_HEVC_EXCEPTIOIN          "che.video.hw_enc_hevc_exceptions"
#define CONFIGURABLE_KEY_VIDEO_HWDEC_HEVC_EXCEPTIOIN          "che.video.hw_dec_hevc_exceptions"

#define CONFIGURABLE_KEY_RTC_FORCE_DEVICE_SCORE               "che.device_score"

#define CONFIGURABLE_KEY_RTC_VIDEO_BANDWIDTH_AGGRESSIVE_LEVEL "che.video.bandwidth_aggressive_level"
#define CONFIGURABLE_KEY_RTC_VIDEO_END2END_BWE                "rtc.video.end2end_bwe"
#define CONFIGURABLE_KEY_RTC_VIDEO_MAX_PAYLOAD_SIZE           "rtc.video.max_payload_size"
#define CONFIGURABLE_KEY_CHE_VIDEO_MAX_PAYLOAD_SIZE           "che.video.maxVideoPayload"
#define CONFIGURABLE_KEY_RTC_VIDEO_MIN_FEC_LEVEL              "rtc.video.min_fec_level"
#define CONFIGURABLE_KEY_VIDEO_DEVICE_CONTENT_INSPECT         "rtc.video.enable_device_inspect"
#define CONFIGURABLE_KEY_VIDEO_CLOUD_CONTENT_INSPECT          "rtc.video.enable_cloud_inspect"
#define CONFIGURABLE_KEY_VIDEO_CONTENT_INSPECT                "rtc.video.enable_content_inspect"
#define CONFIGURABLE_KEY_VIDEO_INSPECT_THRESHOLD              "rtc.video.inspect_threshold"
#define CONFIGURABLE_KEY_VIDEO_INSPECT_CALLBACK               "rtc.video.enable_inspect_callback"
#define CONFIGURABLE_KEY_VIDEO_INSPECT_ENCRYPT                "rtc.video.content_inspect_encrypt_type"
#define CONFIGURABLE_KEY_VIDEO_INSPECT_FEATURE_RATE           "rtc.video.content_inspect_feature_rate"
#define CONFIGURABLE_KEY_VIDEO_INSPECT_VENDOR                 "rtc.video.content_inspect_vendor"
#define CONFIGURABLE_KEY_VIDEO_INSPECT_CALLBACKURL            "rtc.video.content_callback_url"
#define CONFIGURABLE_KEY_VIDEO_INSPECT_TOKEN                  "rtc.video.content_inspect_token"
#define CONFIGURABLE_KEY_VIDEO_INSPECT_EXTINFO                "rtc.video.content_inspect_ext_info"

#define INTERNAL_KEY_RTC_SET_APP_TYPE                         "rtc.set_app_type"

#define CONFIGURABLE_KEY_RTC_IPTOS_ENABLE                     "rtc.iptos"

#define CONFIGURABLE_KEY_RTC_VIDEO_SKIP_ENABLE                "rtc.video.skip_enable"
#define CONFIGURABLE_KEY_RTC_VIDEO_NEW_COMPLEXITY             "rtc.video.new_complexity"
#define CONFIGURABLE_KEY_RTC_VIDEO_DEFAULT_COMPLEXITY         "rtc.video.default_complexity"
#define CONFIGURABLE_MIN_KEYFRAME_INTERVAL                    "che.video.keyFrameEncodeMinInterval"
#define CONFIGURABLE_VIDEO_ENABLE_PARSER_REJECT               "rtc.enable_parser_reject"
#define CONFIGURABLE_VIDEO_BFRAME_NUMBER                      "rtc.video.bframes"
#define CONFIGURABLE_VIDEO_REWRITE_NUM_REORDER_FRAME          "rtc.video.disable_rewrite_num_reorder_frame"
#define CONFIGURABLE_KEY_VIDEO_HARQ_SCENE                     "che.video.harqScene"
#define CONFIGURABLE_KEY_VIDEO_FEC_OUTSIDE_RATIO              "che.video.fec_outside_bw_ratio"
#define CONFIGURABLE_KEY_VIDEO_APAS_HARQ_ENABLE               "rtc.video.apas_harq_enable"
#define CONFIGURABLE_KEY_VIDEO_MULTI_REXFER_ALPHA_ENABLE      "rtc.video.multi_rexfer_alpha_enable"
#define CONFIGURABLE_KEY_VIDEO_APAS_AA_HARQ_ENABLE            "rtc.video.apas_aa_harq_enable"
#define CONFIGURABLE_KEY_VIDEO_HARQ_VERSION                   "che.video.harqVer"
#define CONFIGURABLE_KEY_VIDEO_HARQ_MAX_FEC_RATIO             "che.video.harqMaxFecRatio"
#define CONFIGURABLE_KEY_VIDEO_HARQ_LOSS_RATIO_MULTIPLIER     "che.video.harqLossRatioMultiplier"
#define CONFIGURABLE_KEY_VIDEO_HARQ_FIXED_FEC_RATIO           "che.video.harqFixedFecRatio"
#define CONFIGURABLE_KEY_VIDEO_HARQ_ENABLE_FIXED_FEC          "che.video.harqEnableFixedFec"
#define CONFIGURABLE_KEY_VIDEO_HARQ_LOSS_WINDOWS              "che.video.harqLossWindowPrivate"
#define INTERNAL_KEY_ENABLE_GLOBAL_LOCATION_PRIORITY_DOMAIN   "rtc.enable_global_location_priority_domain"
#define CONFIGURABLE_KEY_QUICK_RESPONSE_INTRA_REQUEST         "rtc.enable_quick_response_intra_request"
#define CONFIGURABLE_KEY_PERIOD_KEY_FRAME                     "rtc.enable_period_key_frame"
#define CONFIGURABLE_KEY_RTC_VIDEO_HW_CAPTURE_DELAY           "rtc.video.hw_capture_delay"
#define CONFIGURABLE_KEY_RTC_VIDEO_THRESHHOLD_MS              "rtc.video.threshhold_ms"

#define INTERNAL_KEY_QOS_FOR_TEST_PURPOSE                     "rtc.qos_for_test_purpose"

// Used to distinguish between old and new token usage processes(join channel, renew token, set client role)
#define INTERNAL_KEY_ENABLE_SECURE_TOKEN_VALIDATION           "rtc.enable_secure_token_validation"
#define CONFIGURABLE_KEY_ENABLE_SOLE_UDP_SOCKET               "rtc.enable_sole_udp_socket"
#define INTERNAL_KEY_CHE_AVSYNC_SYNC_UID                      "che.avsync.sync_uid"
#define INTERNAL_KEY_RTC_VIDEO_AVSYNC                         "rtc.video.avsync"

#define CONFIGURABLE_KEY_RTC_SET_REXFER_STATUS                "rtc.set_rexfer_status"

#define CONFIGURABLE_DIRECT_CDN_STREAMING_VIDEO_GOP_MS        "direct_cdn_streaming.video.gop_ms"
#define CONFIGURABLE_DIRECT_CDN_STREAMING_VIDEO_H264_PROFILE  "direct_cdn_streaming.video.h264_profile"
#define CONFIGURABLE_DIRECT_CDN_STREAMING_VIDEO_ENCODER_HWSW_MODE  "direct_cdn_streaming.video.encoder_hw_sw_mode"
#define CONFIGURABLE_DIRECT_CDN_STREAMING_VIDEO_ENCODER_BITRATE_CONTROL_MODE  "direct_cdn_streaming.video.encoder_bitrate_control_mode"

#define CONFIGURABLE_KEY_VIDEO_SEND_ALPHA_DATA                "rtc.video.send_alpha_data"
#define CONFIGURABLE_KEY_VIDEO_ALPHA_DATA_CODEC_TYPE          "rtc.video.alpha_data_codec_type"
#define CONFIGURABLE_KEY_ADJUST_REMOTE_SSRC                   "rtc.adjust_remote_ssrc"
#define CONFIGURABLE_NETOB_UP_LIMIT_NUM                       "rtc.netob_up_limit_num"

#define CONFIGURABLE_KEY_RTC_VIDEO_SET_REMOTE_VIDEO_STREAM   INTERNAL_KEY_RTC_VIDEO_SET_REMOTE_DEFAULT_VIDEO_STREAM_TYPE
#define CONFIGURABLE_KEY_RTC_VIDEO_OVERRIDE_SMALL_VIDEO_NOT_USE_HWENC_POLICY  KEY_RTC_VIDEO_OVERRIDE_SMALLVIDEO_NOT_USE_HWENC_POLICY

#define INTERNAL_KEY_RTC_MOBILE_RSSI_THRESHOLD_MIN            "rtc.mobile_rssi_threshold_min"
#define INTERNAL_KEY_RTC_WIFI_RSSI_THRESHOLD_MIN              "rtc.wifi_rssi_threshold_min"
#define INTERNAL_KEY_RTC_LINK_SPEED_THRESHOLD_MIN             "rtc.link_speed_threshold_min"
#define INTERNAL_KEY_RTC_GATE_RTT_THRESHOLD_MAX               "rtc.gate_rtt_threshold_max"
#define INTERNAL_KEY_RTC_WAN_RTT_THRESHOLD_MAX                "rtc.wan_rtt_threshold_max"
#define INTERNAL_KEY_RTC_VOS_RTT_THRESHOLD_MAX                "rtc.vos_rtt_threshold_max"
#define CONFIGURABLE_KEY_ENABLE_WIFI_QOS                      "rtc.sdk_wifi_qos"
#define CONFIGURABLE_KEY_WIFI_ACC_ENABLE                      "rtc.wifi_acc_enable"
#define CONFIGURABLE_KEY_JUDGE_DISCONNECT_AP_TIME_THRE        "rtc.judgeDisconnectAPTimeThre"
#define CONFIGURABLE_KEY_JUDGE_SDK_BROADCAST_VERSION          "rtc.sdk_broadcast_version"

#define CONFIGURABLE_KEY_VIDEO_SHARP_UPLINK_BWE_INCREASE_DETECT "rtc.video.sharp_uplink_bwe_increase_detect"
#define INTERNAL_KEY_AUDIO_MIXING_POS_CHANGED_CB_INTERVAL_MS   "rtc.audio_mixing.pos_changed_cb_interval_ms"

#define CONFIGURABLE_KEY_RTC_METERING_COLLECT_INTERVAL           "rtc.metering.collect_interval"
#define CONFIGURABLE_KEY_RTC_METERING_ENABLE_WORK                "rtc.metering.enable_work"
#define INTERNAL_KEY_RTC_MOCK_TDS                                "rtc.mock_tds"

// enable/disable video dump, disabled by default
#define KEY_RTC_VIDEO_ENABLE_VIDEO_DUMP             "engine.video.enable_video_dump"

#define CONFIGURABLE_KEY_DOMAIN_TIMEOUT_PERIOD                "rtc.domain_timeout_period"
// argus report
#define CONFIGURABLE_KEY_REPORT_COUNTER_INTERVAL              "rtc.report.counter_interval"
#define CONFIGURABLE_KEY_REPORT_COUNTER_SCALE                 "rtc.report.counter_scale"
#define CONFIGURABLE_KEY_REPORT_COUNTER_FULL_PERIOD           "rtc.report.counter_full_period"
#define CONFIGURABLE_KEY_REPORT_COUNTER_ENABLE_OPTIMIZATION   "rtc.report.counter_enable_optimization"

namespace agora {
namespace config {

struct AnyValue {
  enum Type {
    UNSPEC = -1,
    INTEGER = 0,
    UNSIGNED_INTEGER = 1,
    BOOLEAN = 2,
    DOUBLE = 3,
    CSTR = 4,
    JSON = 5,
  } type;
  union {
    int val_int;
    unsigned int val_uint;
    bool val_bool;
    double val_double;
    const char* val_cstr;
    const void* val_cjson;
  };
};

template <class T>
struct ExternalParameterHelperTypeTraits {
  static const config::AnyValue::Type AnyValueType = config::AnyValue::UNSPEC;
};
template <>
struct ExternalParameterHelperTypeTraits<int> {
  static const config::AnyValue::Type AnyValueType = config::AnyValue::INTEGER;
  static int getValue(const AnyValue& value) { return value.val_int; }
  static void setValue(int from, AnyValue& to) {
    to.type = AnyValueType;
    to.val_int = from;
  }
};
template <>
struct ExternalParameterHelperTypeTraits<unsigned int> {
  static const config::AnyValue::Type AnyValueType =
      config::AnyValue::UNSIGNED_INTEGER;
  static unsigned int getValue(const AnyValue& value) { return value.val_uint; }
  static void setValue(unsigned int from, AnyValue& to) {
    to.type = AnyValueType;
    to.val_uint = from;
  }
};
template <>
struct ExternalParameterHelperTypeTraits<uint16_t> {
  static const config::AnyValue::Type AnyValueType =
      config::AnyValue::UNSIGNED_INTEGER;
  static uint16_t getValue(const AnyValue& value) { return value.val_uint; }
  static void setValue(uint16_t from, AnyValue& to) {
    to.type = AnyValueType;
    to.val_uint = from;
  }
};
template <>
struct ExternalParameterHelperTypeTraits<double> {
  static const config::AnyValue::Type AnyValueType = config::AnyValue::DOUBLE;
  static double getValue(const AnyValue& value) { return value.val_double; }
  static void setValue(double from, AnyValue& to) {
    to.type = AnyValueType;
    to.val_double = from;
  }
};
template <>
struct ExternalParameterHelperTypeTraits<bool> {
  static const config::AnyValue::Type AnyValueType = config::AnyValue::BOOLEAN;
  static bool getValue(const AnyValue& value) { return value.val_bool; }
  static void setValue(bool from, AnyValue& to) {
    to.type = AnyValueType;
    to.val_bool = from;
  }
};
template <>
struct ExternalParameterHelperTypeTraits<std::string> {
  static const config::AnyValue::Type AnyValueType = config::AnyValue::CSTR;
  static std::string getValue(const AnyValue& value) { return value.val_cstr; }
  static void setValue(const std::string& from, AnyValue& to) {
    to.type = AnyValueType;
    to.val_cstr = from.c_str();
  }
};
template <>
struct ExternalParameterHelperTypeTraits<const char*> {
  static const config::AnyValue::Type AnyValueType = config::AnyValue::CSTR;
  static const char* getValue(const AnyValue& value) { return value.val_cstr; }
  static void setValue(const char* from, AnyValue& to) {
    to.type = AnyValueType;
    to.val_cstr = from;
  }
};

template <>
struct ExternalParameterHelperTypeTraits<const void*> {
  static const config::AnyValue::Type AnyValueType = config::AnyValue::JSON;
  static const void* getValue(const AnyValue& value) { return value.val_cjson; }
  static void setValue(const void* from, AnyValue& to) {
    to.type = AnyValueType;
    to.val_cjson = from;
  }
};

class IUserIdManager {
 public:
  virtual bool toUserId(unsigned int uid, std::string& userId) const = 0;
  virtual bool toInternalUid(const char* userId, unsigned int& uid) const = 0;
  virtual bool hasUser(unsigned int uid) const = 0;
  virtual bool hasUser(const char* userId) const = 0;
  virtual ~IUserIdManager() {}
};

class IObserver {
 public:
  virtual bool onSetValue(const AnyValue& value) = 0;
  virtual bool onGetValue(AnyValue& value) { return false; }
  virtual ~IObserver() {}
};
class IFilter {
 public:
  virtual bool onSetValue(const AnyValue& value) = 0;
  virtual bool onGetValue(AnyValue& value) { return false; }
  virtual ~IFilter() {}
};

class IParameter {
 public:
  virtual void release() = 0;
  virtual bool getValue(AnyValue& value) const = 0;
  virtual bool setValue(
      const AnyValue& value,
      bool storeOnly) = 0;  // specify storeOnly to true to
                            // skip trigger observer and filter
  virtual bool getOriginalValue(AnyValue& value) const = 0;
  virtual bool setOriginalValue(const AnyValue& value) = 0;
  virtual bool connectExternalObserver(IObserver* observer,
                                       bool triggerOnConnect) = 0;
  virtual bool disconnectExternalObserver() = 0;
  virtual bool connectExternalFilter(IFilter* filter,
                                     bool triggerOnConnect) = 0;
  virtual bool disconnectExternalFilter() = 0;
  virtual ~IParameter() {}
};

class IParameterCollection {
 public:
  virtual void release() = 0;
  virtual ~IParameterCollection() {}
};

class IConfigEngine {
 public:
  enum PARAMETER_TYPE {
    VALUE_ONLY = 0,
    HAS_EXTERNAL_FILTER = 1,
    HAS_EXTERNAL_OBSERVER = 2,
    HAS_EXTERNAL_TRIGGER = 3,
    HAS_ORIGINAL_VALUE = 4,
  };
  virtual IParameter* createParameter(const char* key, AnyValue::Type valueType,
                                      PARAMETER_TYPE paramType) = 0;
  virtual IParameter* getParameter(const char* key) = 0;
  virtual int setParameters(const char* parameters) = 0;
  virtual ~IConfigEngine() {}
};

template <class T>
class InternalParameterHelper {
 public:
  InternalParameterHelper(const T& defValue) : value_(defValue) {}
  const T& value() const { return value_; }
  bool setValue(const T& value) {
    value_ = value;
    return true;
  }

 protected:
  T value_;
};

class ExternalTriggerParameterHelper {
 public:
  /*ExternalTriggerParameterHelper(IConfigEngine& engine, const char* key)
      :parameter_(engine.getParameter(key))
  {
  }*/
  ExternalTriggerParameterHelper(IConfigEngine& engine, const char* key,
                                 AnyValue::Type valueType,
                                 IConfigEngine::PARAMETER_TYPE paramType)
      : parameter_(engine.createParameter(key, valueType, paramType)) {}
  ~ExternalTriggerParameterHelper() {
    if (parameter_) parameter_->release();
  }
  operator bool() { return parameter_ != nullptr; }

 protected:
  IParameter* parameter_;
};

template <class T>
class ExternalParameterHelper : public ExternalTriggerParameterHelper {
 public:
  ExternalParameterHelper(
      IConfigEngine& engine, const char* key, const T& defValue,
      AnyValue::Type valueType =
          ExternalParameterHelperTypeTraits<T>::AnyValueType,
      IConfigEngine::PARAMETER_TYPE paramType = IConfigEngine::VALUE_ONLY)
      : ExternalTriggerParameterHelper(engine, key, valueType, paramType) {
    setValue(defValue, true);
  }
  T value() const {
    AnyValue val;
    if (parameter_ && parameter_->getValue(val)) {
      return ExternalParameterHelperTypeTraits<T>::getValue(val);
    }
    return T();
  }
  bool setValue(const AnyValue& value, bool storeValue = true) {
    if (parameter_) {
      return parameter_->setValue(value, storeValue);
    }
    return false;
  }
  bool setValue(T value, bool storeValue = true) {
    AnyValue v;
    ExternalParameterHelperTypeTraits<T>::setValue(value, v);
    return setValue(v, storeValue);
  }
};

template <class T>
class ExternalParameterHelperWithOriginalValue
    : public ExternalParameterHelper<T> {
 public:
  ExternalParameterHelperWithOriginalValue(
      IConfigEngine& engine, const char* key, const T& defValue,
      AnyValue::Type valueType =
          ExternalParameterHelperTypeTraits<T>::AnyValueType,
      IConfigEngine::PARAMETER_TYPE paramType = IConfigEngine::VALUE_ONLY)
      : ExternalParameterHelper<T>(engine, key, defValue, valueType,
                                   paramType) {
    setOriginalValue(defValue);
  }
  bool getOriginalValue(T& v) const {
    AnyValue val;
    if (this->parameter_ && this->parameter_->getOriginalValue(val)) {
      v = ExternalParameterHelperTypeTraits<T>::getValue(val);
      return true;
    }
    return false;
  }

 protected:
  bool setOriginalValue(const T& value) {
    if (this->parameter_) {
      AnyValue v;
      ExternalParameterHelperTypeTraits<T>::setValue(value, v);
      return this->parameter_->setOriginalValue(v);
    }
    return false;
  }
};

class ExternalParameterHasSlots {
 public:
  virtual ~ExternalParameterHasSlots() { disconnectAll(); }
  void disconnectAll() {
    for (auto& param : parameters_) {
      param->disconnectExternalObserver();
      param->disconnectExternalFilter();
    }
    parameters_.clear();
  }
  void addParameter(IParameter* param) {
    if (param) parameters_.insert(param);
  }

 private:
  std::unordered_set<IParameter*> parameters_;
};

template <class T>
class ExternalParameterHelperWithObserver : public ExternalParameterHelper<T>,
                                            public IObserver {
  typedef std::function<int(const T&)> setter_type;
  typedef std::function<int(T&)> getter_type;

 public:
  ExternalParameterHelperWithObserver(
      IConfigEngine& engine, const char* key, const T& defValue,
      AnyValue::Type valueType =
          ExternalParameterHelperTypeTraits<T>::AnyValueType)
      : ExternalParameterHelper<T>(engine, key, defValue, valueType,
                                   IConfigEngine::HAS_EXTERNAL_OBSERVER) {}
  bool connect(ExternalParameterHasSlots* om, setter_type&& setter,
               getter_type&& getter = nullptr, bool triggerOnConnect = false) {
    if (this->parameter_) {
      this->setter_ = std::move(setter);
      this->getter_ = std::move(getter);
      if (om) om->addParameter(this->parameter_);
      return this->parameter_->connectExternalObserver(this, triggerOnConnect);
    }
    return false;
  }
  virtual bool onSetValue(const AnyValue& value) override {
    if (this->setter_) {
      return this->setter_(
                 ExternalParameterHelperTypeTraits<T>::getValue(value)) == 0;
    }
    return false;
  }
  virtual bool onGetValue(AnyValue& value) override {
    if (this->getter_) {
      T tmp;
      if (this->getter_(tmp) == 0) {
        ExternalParameterHelperTypeTraits<T>::setValue(tmp, value);
        return true;
      }
    }
    return false;
  }

 private:
  setter_type setter_;
  getter_type getter_;
};

template <class T>
class ExternalParameterHelperWithFilter : public ExternalParameterHelper<T>,
                                          public IFilter {
  typedef std::function<int(const T&)> setter_type;
  typedef std::function<int(T&)> getter_type;

 public:
  ExternalParameterHelperWithFilter(
      IConfigEngine& engine, const char* key, const T& defValue,
      AnyValue::Type valueType =
          ExternalParameterHelperTypeTraits<T>::AnyValueType)
      : ExternalParameterHelper<T>(engine, key, defValue, valueType,
                                   IConfigEngine::HAS_EXTERNAL_FILTER) {}
  bool connect(ExternalParameterHasSlots* om, setter_type&& setter,
               getter_type&& getter = nullptr, bool triggerOnConnect = false) {
    if (this->parameter_) {
      this->setter_ = std::move(setter);
      this->getter_ = std::move(getter);
      if (om) om->addParameter(this->parameter_);
      return this->parameter_->connectExternalFilter(this, triggerOnConnect);
    }
    return false;
  }
  virtual bool onSetValue(const AnyValue& value) override {
    return this->setter_ &&
           this->setter_(
               ExternalParameterHelperTypeTraits<T>::getValue(value) == 0);
  }
  virtual bool onGetValue(AnyValue& value) override {
    if (this->getter_) {
      T tmp;
      if (this->getter_(tmp) == 0) {
        ExternalParameterHelperTypeTraits<T>::setValue(tmp, value);
        return true;
      }
    }
    return false;
  }

 private:
  setter_type setter_;
  getter_type getter_;
};

template <class T>
class ExternalTriggerParameterHelperWithObserver
    : public ExternalTriggerParameterHelper,
      public IObserver {
  typedef std::function<int(const T&)> setter_type;
  typedef std::function<int(T&)> getter_type;

 public:
  ExternalTriggerParameterHelperWithObserver(
      IConfigEngine& engine, const char* key,
      AnyValue::Type valueType =
          ExternalParameterHelperTypeTraits<T>::AnyValueType)
      : ExternalTriggerParameterHelper(engine, key, valueType,
                                       IConfigEngine::HAS_EXTERNAL_TRIGGER) {}
  bool connect(ExternalParameterHasSlots* om, setter_type&& setter,
               getter_type&& getter = nullptr, bool triggerOnConnect = false) {
    if (this->parameter_) {
      this->setter_ = std::move(setter);
      this->getter_ = std::move(getter);
      if (om) om->addParameter(this->parameter_);
      return this->parameter_->connectExternalObserver(this, triggerOnConnect);
    }
    return false;
  }
  virtual bool onSetValue(const AnyValue& value) override {
    if (this->setter_) {
      return this->setter_(
                 ExternalParameterHelperTypeTraits<T>::getValue(value)) == 0;
    }
    return false;
  }
  virtual bool onGetValue(AnyValue& value) override {
    if (this->getter_) {
      T tmp;
      if (this->getter_(tmp) == 0) {
        ExternalParameterHelperTypeTraits<T>::setValue(tmp, value);
        return true;
      }
    }
    return false;
  }

 private:
  setter_type setter_;
  getter_type getter_;
};

}  // namespace config
}  // namespace agora
