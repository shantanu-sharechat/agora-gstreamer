//  Agora SDK
//
//  Copyright (c) 2019 Agora.io. All rights reserved.
//  Reference from WebRTC project
//
#pragma once

#include <string>

#include "AgoraOptional.h"

#define SET_FROM(X) SetFrom(&X, change.X)

#define BEGIN_COMPARE() bool b = true
#define ADD_COMPARE(X) b = (b && (X == o.X))
#define END_COMPARE_AND_RETURN() \
  ;                              \
  return b

#define UNPUBLISH(X) X.reset()

namespace agora {
namespace rtc {

/**
 * OpenSL mode
 */
enum OPENSL_MODE {
  /**
   * always on
   */
  ALWAYS_ON,

  /**
   * always off
   */
  ALWAYS_OFF,

  /**
   * on with headset
   */
  ON_WITH_HEADSET,
};

// Options that can be applied to an audio track or audio engine.
struct AudioOptions {
  AudioOptions() = default;
  ~AudioOptions() = default;

  void SetAll(const AudioOptions& change) {
    SET_FROM(audio_scenario);
    SET_FROM(audio_routing);
    SET_FROM(opensl_mode);
    SET_FROM(adm_enable_estimated_device_delay);
    SET_FROM(adm_enable_preferred_aec_delay);
    SET_FROM(adm_enable_lowlatency_capture);
    SET_FROM(adm_duck_others);
    SET_FROM(adm_restart_when_interrupted);
    SET_FROM(adm_enable_oboe);
    SET_FROM(adm_enable_fallback);
    SET_FROM(has_published_stream);
    SET_FROM(has_subscribed_stream);
    SET_FROM(has_enabled_ear_monitor);

    SET_FROM(adm_mix_option_selected);
    SET_FROM(adm_input_sample_rate);
    SET_FROM(adm_output_sample_rate);
    SET_FROM(adm_enable_exclusive_mode);
    SET_FROM(adm_input_channels);
    SET_FROM(adm_output_channels);
    SET_FROM(adm_has_recorded);
    SET_FROM(adm_enable_mic_selection);
    SET_FROM(adm_force_use_bluetooth_a2dp);
    SET_FROM(adm_use_bluetooth_hfp);
    SET_FROM(adm_use_hw_aec);
    SET_FROM(adm_enable_hardware_ear_monitor);
    SET_FROM(adm_force_restart);
    SET_FROM(adm_audio_layer);
    SET_FROM(adm_audio_source);
    SET_FROM(adm_playout_bufsize_factor);
    SET_FROM(adm_extra_playout_latency);
    SET_FROM(adm_extra_record_latency);
    SET_FROM(apm_process_channels);
    SET_FROM(apm_enable_aec);
    SET_FROM(apm_enable_aec_external);
    SET_FROM(apm_enable_ns);
    SET_FROM(apm_ains_mode);
    SET_FROM(apm_ains_gain_control);
    SET_FROM(apm_ains_speech_enhance);
    SET_FROM(apm_enable_agc);
    SET_FROM(apm_enable_md);
    SET_FROM(apm_aimd_value);
    SET_FROM(apm_enable_highpass_filter);
    SET_FROM(apm_enable_tone_remover);
    SET_FROM(apm_enable_pitch_smoother);
    SET_FROM(apm_enable_howling_control);
    SET_FROM(apm_delay_offset_ms);
    SET_FROM(apm_aec_nlp_aggressiveness);
    SET_FROM(apm_aec_complexity);
    SET_FROM(apm_aec_sw_processing_mode);
    SET_FROM(apm_aec_linear_filter_length_ms);
    SET_FROM(apm_aec_state_diagnosis);
    SET_FROM(apm_agc_target_level_dbfs);
    SET_FROM(apm_agc_compression_gain_db);
    SET_FROM(apm_agc_mode);
    SET_FROM(apm_ns_enable_ns_follow_agc);
    SET_FROM(apm_ns_level);
    SET_FROM(apm_ns_noiseGateThres);
    SET_FROM(apm_ns_complexity);
    SET_FROM(apm_enable_dtd);
    SET_FROM(apm_enable_record_boost);
    // AINS
    SET_FROM(apm_ains_fft_size);
    SET_FROM(apm_ains_maxtolerant_ms);
    SET_FROM(apm_ains_attack_factor);
    SET_FROM(apm_ains_release_factor);
    SET_FROM(apm_ains_upper_bound);
    SET_FROM(apm_ains_upper_mask);
    SET_FROM(apm_ains_lower_bound);
    SET_FROM(apm_ains_lower_mask);
    SET_FROM(apm_ains_triangle_1);
    SET_FROM(apm_ains_triangle_2);
    SET_FROM(apm_ains_triangle_3);
    SET_FROM(apm_ains_threshold_ai);
    SET_FROM(apm_ains_threshold_stastical);
    SET_FROM(apm_ains_enh_factor_ai);
    SET_FROM(apm_ains_enh_factor_stastical);
    SET_FROM(apm_ains_noise_over_estimate);
    SET_FROM(apm_ains_statistical_bound);
    SET_FROM(apm_ains_gain_boost_frq1);
    SET_FROM(apm_ains_gain_boost_gain1);
    SET_FROM(apm_ains_gain_boost_frq2);
    SET_FROM(apm_ains_gain_boost_gain2);
    SET_FROM(apm_ains_gain_boost_frq3);
    SET_FROM(apm_ains_gain_boost_gain3);
    SET_FROM(apm_ains_final_lower_mask);
    SET_FROM(apm_ains_noise_pow_floor);
    SET_FROM(apm_ains_cng_base_magnitude);
    SET_FROM(apm_ains_strategy);
    SET_FROM(acm_bitrate);
    SET_FROM(acm_codec);
    SET_FROM(acm_dtx);
    SET_FROM(acm_plc);
    SET_FROM(acm_complex_level);
    SET_FROM(acm_ptime);
    SET_FROM(acm_hw_encode_opus);
    SET_FROM(acm_hw_decode_opus);
    SET_FROM(acm_opus_celt_only);
    SET_FROM(audio_resend);
    SET_FROM(audio_rsfec_frame_num);
    SET_FROM(audio_rsfec_interleave_num);
    SET_FROM(audio_fec_frame_num);
    SET_FROM(audio_fec_interleave_num);
    SET_FROM(neteq_live_min_delay);
    SET_FROM(neteq_jitter_buffer_max_packets);
    SET_FROM(neteq_jitter_buffer_fast_accelerate);
    SET_FROM(neteq_jitter_max_target_delay);
    SET_FROM(neteq_filter_target_loss);
    SET_FROM(neteq_max_filter_window);
    SET_FROM(neteq_enable_expired_peak_dector);
    SET_FROM(neteq_max_exceed_time_ms);
    SET_FROM(neteq_max_filter_dup_num);
    SET_FROM(neteq_targetlevel_offset);
    SET_FROM(neteq_target_level_optimization);
    SET_FROM(neteq_aqm_voice_threshold);
    SET_FROM(neteq_dump_level);
    SET_FROM(neteq_dump_path);
    SET_FROM(neteq_limit_prob);
    SET_FROM(neteq_lower_limit_probability);
    SET_FROM(dwlink_gain);
    SET_FROM(uplink_gain);
    SET_FROM(derived_headset_black_list_device);
    SET_FROM(use_media_volume_in_headset);
    SET_FROM(use_media_volume_in_audience);
    SET_FROM(use_media_volume_in_solo);
    SET_FROM(use_media_volume_in_bluetooth);
  }

  bool operator==(const AudioOptions& o) const {
    BEGIN_COMPARE();
    ADD_COMPARE(audio_scenario);
    ADD_COMPARE(audio_routing);
    ADD_COMPARE(opensl_mode);
    ADD_COMPARE(adm_enable_estimated_device_delay);
    ADD_COMPARE(adm_enable_preferred_aec_delay);
    ADD_COMPARE(adm_enable_lowlatency_capture);
    ADD_COMPARE(adm_duck_others);
    ADD_COMPARE(adm_restart_when_interrupted);
    ADD_COMPARE(adm_enable_oboe);
    ADD_COMPARE(adm_enable_fallback);
    ADD_COMPARE(has_published_stream);
    ADD_COMPARE(has_subscribed_stream);
    ADD_COMPARE(has_enabled_ear_monitor);
    ADD_COMPARE(adm_mix_option_selected);
    ADD_COMPARE(adm_input_sample_rate);
    ADD_COMPARE(adm_output_sample_rate);
    ADD_COMPARE(adm_enable_exclusive_mode);
    ADD_COMPARE(adm_input_channels);
    ADD_COMPARE(adm_output_channels);
    ADD_COMPARE(adm_has_recorded);
    ADD_COMPARE(adm_enable_mic_selection);
    ADD_COMPARE(adm_force_use_bluetooth_a2dp);
    ADD_COMPARE(adm_use_bluetooth_hfp);
    ADD_COMPARE(adm_use_hw_aec);
    ADD_COMPARE(adm_enable_hardware_ear_monitor);
    ADD_COMPARE(adm_force_restart);
    ADD_COMPARE(adm_audio_layer);
    ADD_COMPARE(adm_audio_source);
    ADD_COMPARE(adm_playout_bufsize_factor);
    ADD_COMPARE(adm_extra_playout_latency);
    ADD_COMPARE(adm_extra_record_latency);
    ADD_COMPARE(apm_process_channels);
    ADD_COMPARE(apm_enable_aec);
    ADD_COMPARE(apm_enable_aec_external);
    ADD_COMPARE(apm_enable_ns);
    ADD_COMPARE(apm_ains_mode);
    ADD_COMPARE(apm_ains_gain_control);
    ADD_COMPARE(apm_ains_speech_enhance);
    // AINS
    ADD_COMPARE(apm_ains_fft_size);
    ADD_COMPARE(apm_ains_maxtolerant_ms);
    ADD_COMPARE(apm_ains_attack_factor);
    ADD_COMPARE(apm_ains_release_factor);
    ADD_COMPARE(apm_ains_upper_bound);
    ADD_COMPARE(apm_ains_upper_mask);
    ADD_COMPARE(apm_ains_lower_bound);
    ADD_COMPARE(apm_ains_lower_mask);
    ADD_COMPARE(apm_ains_triangle_1);
    ADD_COMPARE(apm_ains_triangle_2);
    ADD_COMPARE(apm_ains_triangle_3);
    ADD_COMPARE(apm_ains_threshold_ai);
    ADD_COMPARE(apm_ains_threshold_stastical);
    ADD_COMPARE(apm_ains_enh_factor_ai);
    ADD_COMPARE(apm_ains_enh_factor_stastical);
    ADD_COMPARE(apm_ains_noise_over_estimate);
    ADD_COMPARE(apm_ains_statistical_bound);
    ADD_COMPARE(apm_ains_gain_boost_frq1);
    ADD_COMPARE(apm_ains_gain_boost_gain1);
    ADD_COMPARE(apm_ains_gain_boost_frq2);
    ADD_COMPARE(apm_ains_gain_boost_gain2);
    ADD_COMPARE(apm_ains_gain_boost_frq3);
    ADD_COMPARE(apm_ains_gain_boost_gain3);
    ADD_COMPARE(apm_ains_final_lower_mask);
    ADD_COMPARE(apm_ains_noise_pow_floor);
    ADD_COMPARE(apm_ains_cng_base_magnitude);
    ADD_COMPARE(apm_ains_strategy);
    ADD_COMPARE(apm_enable_agc);
    ADD_COMPARE(apm_enable_md);
    ADD_COMPARE(apm_aimd_value);
    ADD_COMPARE(apm_enable_highpass_filter);
    ADD_COMPARE(apm_enable_tone_remover);
    ADD_COMPARE(apm_enable_pitch_smoother);
    ADD_COMPARE(apm_enable_howling_control);
    ADD_COMPARE(apm_delay_offset_ms);
    ADD_COMPARE(apm_aec_nlp_aggressiveness);
    ADD_COMPARE(apm_aec_complexity);
    ADD_COMPARE(apm_aec_sw_processing_mode);
    ADD_COMPARE(apm_aec_linear_filter_length_ms);
    ADD_COMPARE(apm_aec_state_diagnosis);
    ADD_COMPARE(apm_agc_target_level_dbfs);
    ADD_COMPARE(apm_agc_compression_gain_db);
    ADD_COMPARE(apm_agc_mode);
    ADD_COMPARE(apm_ns_enable_ns_follow_agc);
    ADD_COMPARE(apm_ns_level);
    ADD_COMPARE(apm_ns_noiseGateThres);
    ADD_COMPARE(apm_ns_complexity);
    ADD_COMPARE(apm_enable_dtd);
    ADD_COMPARE(apm_enable_record_boost);
    ADD_COMPARE(acm_bitrate);
    ADD_COMPARE(acm_codec);
    ADD_COMPARE(acm_dtx);
    ADD_COMPARE(acm_plc);
    ADD_COMPARE(acm_complex_level);
    ADD_COMPARE(acm_ptime);
    ADD_COMPARE(acm_hw_encode_opus);
    ADD_COMPARE(acm_hw_decode_opus);
    ADD_COMPARE(acm_opus_celt_only);
    ADD_COMPARE(audio_resend);
    ADD_COMPARE(audio_rsfec_frame_num);
    ADD_COMPARE(audio_rsfec_interleave_num);
    ADD_COMPARE(audio_fec_frame_num);
    ADD_COMPARE(audio_fec_interleave_num);
    ADD_COMPARE(neteq_live_min_delay);
    ADD_COMPARE(neteq_jitter_buffer_max_packets);
    ADD_COMPARE(neteq_jitter_buffer_fast_accelerate);
    ADD_COMPARE(neteq_jitter_max_target_delay);
    ADD_COMPARE(neteq_filter_target_loss);
    ADD_COMPARE(neteq_max_filter_window);
    ADD_COMPARE(neteq_enable_expired_peak_dector);
    ADD_COMPARE(neteq_max_exceed_time_ms);
    ADD_COMPARE(neteq_max_filter_dup_num);
    ADD_COMPARE(neteq_targetlevel_offset);
    ADD_COMPARE(neteq_target_level_optimization);
    ADD_COMPARE(neteq_aqm_voice_threshold);
    ADD_COMPARE(neteq_dump_level);
    ADD_COMPARE(neteq_dump_path);
    ADD_COMPARE(neteq_limit_prob);
    ADD_COMPARE(neteq_lower_limit_probability);
    ADD_COMPARE(dwlink_gain);
    ADD_COMPARE(uplink_gain);
    ADD_COMPARE(derived_headset_black_list_device);
    ADD_COMPARE(use_media_volume_in_headset);
    ADD_COMPARE(use_media_volume_in_audience);
    ADD_COMPARE(use_media_volume_in_solo);
    ADD_COMPARE(use_media_volume_in_bluetooth);
    END_COMPARE_AND_RETURN();
  }

  AudioOptions& Filter() {
    UNPUBLISH(derived_headset_black_list_device);
    return *this;
  }

  bool operator!=(const AudioOptions& o) const { return !(*this == o); }

  Optional<uint32_t> audio_scenario;  // agora::rtc::AUDIO_SCENARIO_TYPE
  Optional<uint32_t> audio_routing;  // agora::rtc::AudioRoute
  Optional<uint32_t> opensl_mode;  // agora::rtc::OPENSL_MODE
  Optional<bool> adm_enable_estimated_device_delay;
  Optional<bool> adm_enable_preferred_aec_delay;
  Optional<bool> adm_enable_lowlatency_capture;
  Optional<bool> adm_duck_others;
  Optional<bool> adm_restart_when_interrupted;
  Optional<bool> adm_enable_oboe;
  Optional<bool> adm_enable_fallback;
  Optional<bool> has_published_stream;
  Optional<bool> has_subscribed_stream;
  Optional<bool> has_enabled_ear_monitor;
  // ios::AVAudioSessionCategoryOptionMixWithOthers
  Optional<uint32_t> adm_mix_option_selected;
  Optional<uint32_t> adm_input_sample_rate;
  Optional<uint32_t> adm_output_sample_rate;
  Optional<bool> adm_enable_exclusive_mode;
  Optional<uint32_t> adm_input_channels;
  Optional<uint32_t> adm_output_channels;
  Optional<bool> adm_has_recorded;
  Optional<bool> adm_enable_mic_selection;
  // ios::AVAudioSessionCategoryOptionAllowBluetoothA2DP
  Optional<bool> adm_force_use_bluetooth_a2dp;
  Optional<bool> adm_use_bluetooth_hfp;
  Optional<bool> adm_use_hw_aec;
  Optional<bool> adm_enable_hardware_ear_monitor;
  Optional<bool> adm_force_restart;
  Optional<uint32_t> adm_audio_layer;
  Optional<uint32_t> adm_audio_source;  // for android
  Optional<uint32_t> adm_playout_bufsize_factor;  // for android
  Optional<int> adm_extra_playout_latency; // for android
  Optional<int> adm_extra_record_latency; // for android
  Optional<int> apm_process_channels;  // agora::media::base::AUDIO_PROCESS_CHANNELS
  Optional<bool> apm_enable_aec;
  Optional<bool> apm_enable_aec_external;
  Optional<bool> apm_enable_ns;
  Optional<int> apm_ains_mode;
  Optional<int> apm_ains_gain_control;
  Optional<int> apm_ains_speech_enhance;
  Optional<bool> apm_enable_agc;
  Optional<bool> apm_enable_md;
  Optional<int> apm_aimd_value;
  Optional<bool> apm_enable_highpass_filter;
  Optional<bool> apm_enable_tone_remover;
  Optional<bool> apm_enable_pitch_smoother;
  Optional<bool> apm_enable_howling_control;
  Optional<uint32_t> apm_delay_offset_ms;
  Optional<int32_t> apm_aec_nlp_aggressiveness;
  Optional<int32_t> apm_aec_complexity;
  Optional<int32_t> apm_aec_sw_processing_mode;
  Optional<int32_t> apm_aec_linear_filter_length_ms;
  Optional<int32_t> apm_aec_state_diagnosis;
  Optional<uint32_t> apm_agc_target_level_dbfs;
  Optional<uint32_t> apm_agc_compression_gain_db;
  Optional<uint32_t> apm_agc_mode;
  Optional<uint32_t> apm_ns_enable_ns_follow_agc;
  Optional<int32_t>  apm_ns_level;
  Optional<uint32_t> apm_ns_noiseGateThres;
  Optional<int32_t> apm_ns_complexity;
  // AINS
  // che.audio.nsng.anasize , che.audio.nsng.fftsize
  Optional<int32_t> apm_ains_fft_size;
  // che.audio.nsng.maxtime
  Optional<int32_t> apm_ains_maxtolerant_ms;
  // che.audio.nsng.attackfactor
  Optional<int32_t> apm_ains_attack_factor;
  // che.audio.nsng.releasefactor
  Optional<int32_t> apm_ains_release_factor;
  // che.audio.nsng.upperbound
  Optional<int32_t> apm_ains_upper_bound;
  // che.audio.nsng.uppermask
  Optional<int32_t> apm_ains_upper_mask;
  // che.audio.nsng.lowerBound
  Optional<int32_t> apm_ains_lower_bound;
  // che.audio.nsng.lowerMask
  Optional<int32_t> apm_ains_lower_mask;
  // che.audio.nsng.triangle_1
  Optional<int32_t> apm_ains_triangle_1;
  // che.audio.nsng.triangle_2
  Optional<int32_t> apm_ains_triangle_2;
  // che.audio.nsng.triangle_3
  Optional<int32_t> apm_ains_triangle_3;
  // che.audio.nsng.thresholdai
  Optional<int32_t> apm_ains_threshold_ai;
  // che.audio.nsng.thresholdstastical
  Optional<int32_t> apm_ains_threshold_stastical;
  // che.audio.nsng.enhfactorai
  Optional<int32_t> apm_ains_enh_factor_ai;
  // che.audio.nsng.enhfactorstastical
  Optional<int32_t> apm_ains_enh_factor_stastical;
  // che.audio.nsng.noiseoverestimate
  Optional<int32_t> apm_ains_noise_over_estimate;
  // che.audio.nsng.statisticalbound
  Optional<int32_t> apm_ains_statistical_bound;
  // che.audio.nsng.gainboostfreq1
  Optional<int32_t> apm_ains_gain_boost_frq1;
  // che.audio.nsng.gainboostval1
  Optional<int32_t> apm_ains_gain_boost_gain1;
  // che.audio.nsng.gainboostfreq2
  Optional<int32_t> apm_ains_gain_boost_frq2;
  // che.audio.nsng.gainboostval2
  Optional<int32_t> apm_ains_gain_boost_gain2;
  // che.audio.nsng.gainboostfreq3
  Optional<int32_t> apm_ains_gain_boost_frq3;
  // che.audio.nsng.gainboostval3
  Optional<int32_t> apm_ains_gain_boost_gain3;
  // che.audio.nsng.finallowermask
  Optional<int32_t> apm_ains_final_lower_mask;
  // che.audio.nsng.noisepowfloor
  Optional<int32_t> apm_ains_noise_pow_floor;
  // che.audio.nsng.pinkfactor , che.audio.nsng.cngbasemagnitude
  Optional<int32_t> apm_ains_cng_base_magnitude;
  // che.audio.nsng.strategy
  Optional<int32_t> apm_ains_strategy;

  // Double talk detection switcher.
  // Android game streaming scenario should be true, all other cases should be false;
  Optional<int32_t> apm_enable_dtd;
  Optional<bool> apm_enable_record_boost;

  Optional<uint32_t> acm_bitrate;
  Optional<uint32_t> acm_codec;
  Optional<bool> acm_dtx;
  Optional<bool> acm_plc;
  Optional<uint32_t> acm_complex_level;
  Optional<uint32_t> acm_ptime;
  Optional<bool> acm_hw_encode_opus;
  Optional<bool> acm_hw_decode_opus;
  Optional<bool> acm_opus_celt_only;
  Optional<bool> audio_resend;
  Optional<uint32_t> audio_rsfec_frame_num;
  Optional<uint32_t> audio_rsfec_interleave_num;
  Optional<uint32_t> audio_fec_frame_num;
  Optional<uint32_t> audio_fec_interleave_num;
  Optional<uint32_t> neteq_live_min_delay;
  Optional<uint32_t> neteq_jitter_buffer_max_packets;
  Optional<bool> neteq_jitter_buffer_fast_accelerate;
  Optional<int32_t> neteq_jitter_max_target_delay;
  Optional<int32_t> neteq_filter_target_loss;
  Optional<int32_t> neteq_max_filter_window;
  Optional<bool> neteq_enable_expired_peak_dector;
  Optional<int32_t> neteq_max_exceed_time_ms;
  Optional<uint32_t> neteq_max_filter_dup_num;
  Optional<int32_t> neteq_targetlevel_offset;
  Optional<bool> neteq_target_level_optimization;
  Optional<uint32_t> neteq_aqm_voice_threshold;
  Optional<uint32_t> neteq_dump_level;
  Optional<std::string> neteq_dump_path;
  Optional<int> neteq_limit_prob;
  Optional<int> neteq_lower_limit_probability;
  Optional<uint32_t> dwlink_gain;
  Optional<uint32_t> uplink_gain;

  // derived options
  Optional<bool> derived_headset_black_list_device;
  Optional<int> use_media_volume_in_headset;
  Optional<int> use_media_volume_in_audience;
  Optional<int> use_media_volume_in_solo;
  Optional<int> use_media_volume_in_bluetooth;

 private:
  template <typename T>
  static void SetFrom(Optional<T>* s, const Optional<T>& o) {
    if (o) {
      *s = o;
    }
  }
};

}  // namespace rtc
}  // namespace agora
