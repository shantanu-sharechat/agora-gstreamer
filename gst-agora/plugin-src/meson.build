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

gst_base_dep = dependency('gstreamer-base-1.0')
gst_app_dep = dependency('gstreamer-app-1.0')

gstagorasrc = library('gstagorasrc',
  agorasrc_sources,
  c_args: plugin_c_args,
  dependencies : [gst_dep, gst_base_dep, agorac, agora_rtc_sdk, agora_fdkaac, agora_ffmpeg],
  install : true,
  install_dir : plugins_install_dir
)
