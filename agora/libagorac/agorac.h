#ifndef _AGORA_C_H_
#define _AGORA_C_H_
#include <stdbool.h>
#ifdef __cplusplus
 #define EXTERNC extern "C"
 #else
 #define EXTERNC
 #endif

 #include "agoraconfig.h"
#include <stdint.h>


typedef  struct agora_context_t agora_context_t;

typedef  void (*agora_media_out_fn)(const uint8_t* buffer,
                                     uint64_t len,
									 void* user_data, uint64_t ts);

typedef struct agora_receive_context_t agora_receive_context_t;

typedef struct AgoraIoContext_t  AgoraIoContext_t;

EXTERNC AgoraIoContext_t*  agoraio_init(agora_config_t* config);

EXTERNC  void agoraio_media_out_handler(AgoraIoContext_t* ctx, agora_media_out_fn fn, void* userData);

#undef EXTERNC


#endif
