cmake_minimum_required(VERSION 3.10)

project(agora-gstreamer-plugin)

add_definitions(-DHAVE_CONFIG_H=1)

#useful for installing in a custom path
set(INSTALL_PATH $ENV{INSTALL_PATH})
if(NOT INSTALL_PATH)
  message("install directory not set, will use  /usr/local/lib/x86_64-linux-gnu/gstreamer-1.0/ to install")
  set (INSTALL_PATH /usr/local/lib/x86_64-linux-gnu/gstreamer-1.0/)
endif()

find_package(PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)
pkg_search_module(GST REQUIRED gstreamer-1.0>=1.4)
pkg_check_modules(GSTREAMER_BASE REQUIRED gstreamer-app-1.0)
pkg_check_modules(GSTREAMER_SDP REQUIRED gstreamer-sdp-1.0)

include_directories(
    ${GLIB_INCLUDE_DIRS}
    ${GSTREAMER_INCLUDE_DIRS}
    ${GSTREAMER_APP_INCLUDE_DIRS}
    ${GSTREAMER_SDP_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR})

add_library(gstagorasrc SHARED plugin-src/agorasrc/gstagorasrc.c)

set(LIBS 
        ${GLIB_LIBRARIES}
        ${GSTREAMER_LDFLAGS}
        ${GSTREAMER_APP_LDFLAGS}
        ${GSTREAMER_SDP_LDFLAGS}
        ${GSTREAMER_BASE_LDFLAGS}
        ${INSTALL_PATH}/lib/libagorac.so
        ${INSTALL_PATH}/lib/libagora_rtc_sdk.so
        ${INSTALL_PATH}/lib/libagora-ffmpeg.so
        x264
        swscale
        opus
        avcodec)

#add required libs
target_link_libraries(gstagorasrc ${LIBS})

install(TARGETS gstagorasrc DESTINATION ${INSTALL_PATH}/lib)
