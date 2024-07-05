//
//  Agora Media SDK
//
//  Created by ChenZhipeng in 2022-06.
//  Copyright (c) 2022 Agora IO. All rights reserved.
//
#pragma once

#include <cinttypes>

namespace agora {
namespace commons {

enum log_filters {
  LOG_NONE = 0x0000,  // no trace
  LOG_INFO = 0x0001,
  LOG_WARN = 0x0002,
  LOG_ERROR = 0x0004,
  LOG_FATAL = 0x0008,
  LOG_DEFAULT = 0x000f,
  LOG_API_CALL = 0x0010,
  LOG_MODULE_CALL = 0x0020,
  LOG_QUALITY = 0x0040,
  LOG_DIAGNOSE = 0x0080,
  LOG_MEM = 0x0100,     // memory info
  LOG_TIMER = 0x0200,   // timing info
  LOG_STREAM = 0x0400,  // "continuous" stream of data
  // used for debug purposes
  LOG_DEBUG = 0x0800,  // debug

  LOG_CONSOLE = 0x8000,
  LOG_ALL = 0xffff,
  LOG_NO_API = 0xffef,

  LOG_INVALID = (int32_t)-1,
};

#if defined(__APPLE__)
#if defined(__clang__) && (__clang_major__ * 100 + __clang_minor__ * 10 + __clang_patchlevel__ >= 1316)
#define LOG_FORMAT_CHECK 1
#endif
#elif defined(__clang__) || defined(__GNUC__)
#define LOG_FORMAT_CHECK 1
#endif

#if defined(LOG_FORMAT_CHECK)
__attribute__((format(printf, 2, 3)))
#endif
void log(log_filters level, const char* fmt, ...);

}  // namespace commons
}  // namespace agora

// Log format is strict now, for instance: you must use PRId64 when print int64_t
// If you have any trouble with or advice to log format
// goto https://confluence.agoralab.co/pages/viewpage.action?pageId=1037828374
