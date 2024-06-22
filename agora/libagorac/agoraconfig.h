#ifndef _AGORA_CONFIG_H_
#define _AGORA_CONFIG_H_

typedef void (*event_fn)(void* userData,
                         int type,
                         const char* userName,
                         long param1,
                         long param2,
                         long* states);
typedef struct{
  char*           app_id;
  char*           ch_id;
  char*           remote_user_id;
}agora_config_t;

#endif