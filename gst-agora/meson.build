project('gst-template', 'c', version : '1.17.0.1', license : 'LGPL')

plugins_install_dir = join_paths(get_option('libdir'), 'gstreamer-1.0')

message('Value of plugins_install_dir: ' + plugins_install_dir)

cc = meson.get_compiler('c')

gst_version = meson.project_version()

api_version = '1.0'

# Specify the library search paths
libdir1 = '/usr/local/lib'
libdir2 = '/usr/local/lib/x86_64-linux-gnu'

# Find libraries in /usr/local/lib
libagorac = cc.find_library('agorac', dirs : [libdir1])
libagora_rtc_sdk = cc.find_library('agora_rtc_sdk', dirs : [libdir1])
libagora_fdkaac = cc.find_library('agora-fdkaac', dirs : [libdir1])
libagora_ffmpeg = cc.find_library('agora-ffmpeg', dirs : [libdir1])

# Find libraries in /usr/local/lib/x86_64-linux-gnu
libgstreamer = cc.find_library('gstreamer-1.0', dirs : [libdir2])
libgobject = cc.find_library('gobject-2.0', dirs : [libdir2])
libglib = cc.find_library('glib-2.0', dirs : [libdir2])
libgstbase = cc.find_library('gstbase-1.0', dirs : [libdir2])

subdir('plugin-src')
