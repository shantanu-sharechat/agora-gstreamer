plugin_c_args = ['-DHAVE_CONFIG_H -DBOOB']

cdata = configuration_data()
cdata.set_quoted('PACKAGE_VERSION', gst_version)
cdata.set_quoted('PACKAGE', 'gst-agora')
cdata.set_quoted('GST_LICENSE', 'LGPL')
cdata.set_quoted('GST_API_VERSION', api_version)
cdata.set_quoted('GST_PACKAGE_NAME', 'agora source and sink pluging')
cdata.set_quoted('GST_PACKAGE_ORIGIN', 'https://www.agora.io')
configure_file(output : 'config.h', configuration : cdata)

# agorasrc
agorasrc_sources = [
  'agorasrc/gstagorasrc.c',
  ]

# Specify the include directories
incdir1 = include_directories('/usr/local/include')
incdir2 = include_directories('/usr/local/include/x86_64-linux-gnu')

gstagorasrc = library('gstagorasrc',
  agorasrc_sources,
  c_args: plugin_c_args,
                      include_directories : [incdir1, incdir2],
                      dependencies : [
                        libagorac,
                        libagora_rtc_sdk,
                        libagora_fdkaac,
                        libagora_ffmpeg,
                        libgstreamer,
                        libgobject,
                        libglib,
                        libgstbase
                      ],
  install : true,
  install_dir : plugins_install_dir
)
