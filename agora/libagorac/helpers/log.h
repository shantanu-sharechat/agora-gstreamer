//
// Created by Shantanu  Sharma on 22/06/24.
//

#ifndef AGORA_GSTREAMER_LOG_H
#define AGORA_GSTREAMER_LOG_H

#include <cstdio>
#include <ctime>

enum {ERROR=-1, INFO=0, WARNING, FATAL};

#define AG_LOG(level, format, ...)                                                               \
    do {                                                                                         \
        std::time_t now = std::time(nullptr);                                                    \
        char buf[20];                                                                            \
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));              \
        ((void)fprintf(stderr, "[ APP_LOG_" #level " ] [%s] " format "\n", buf, ##__VA_ARGS__)); \
    } while (0)

#endif //AGORA_GSTREAMER_LOG_H
