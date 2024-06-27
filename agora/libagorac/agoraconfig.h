#ifndef _AGORA_CONFIG_H_
#define _AGORA_CONFIG_H_

typedef struct{
  char*           app_id;
  char*           ch_id;
  char*           remote_user_id;
  bool            enable_video;
}agora_config_t;

#endif