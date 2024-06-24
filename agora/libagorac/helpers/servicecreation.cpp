//
// Created by Shantanu  Sharma on 24/06/24.
//

#include "servicecreation.h"
#include "log.h"
#include <iostream>
#include "AgoraBase.h"

int verifyLicense()
{
#ifdef LICENSE_CHECK
  // Step1: read the certificate buffer from the certificate.bin file
  std::cout<<"licences: "<<std::endl;
  char* cert_buffer = NULL;
  int cert_length = 0;
  std::ifstream f_cert(CERTIFICATE_FILE.c_str(), std::ios::binary);
  if (f_cert) {
    f_cert.seekg(0, f_cert.end);
    cert_length = f_cert.tellg();
    f_cert.seekg(0, f_cert.beg);

    cert_buffer = new char[cert_length + 1];
    AG_LOG(INFO, "cert_length: %d", cert_length);
    memset(cert_buffer, 0, cert_length + 1);
    f_cert.read(cert_buffer, cert_length);
    if (!cert_buffer || f_cert.gcount() < cert_length) {
      f_cert.close();
      if (cert_buffer) {
        delete[] cert_buffer;
        cert_buffer = NULL;
      }
      AG_LOG(ERROR, "read %s failed", CERTIFICATE_FILE.c_str());
      return -1;
    }
    else {
      f_cert.close();
    }
  }
  else {
    AG_LOG(ERROR, "%s doesn't exist", CERTIFICATE_FILE.c_str());
    return -1;
  }
  AG_LOG(INFO, "certificate: %s", cert_buffer);

  // Step3: register callback of license state
  LicenseCallbackImpl *cb = static_cast<LicenseCallbackImpl *>(getAgoraLicenseCallback());
  if (!cb) {
    cb = new LicenseCallbackImpl();
    setAgoraLicenseCallback(static_cast<agora::base::LicenseCallback *>(cb));
  }

  // Step4: verify the license with credential and certificate
  int result = getAgoraCertificateVerifyResult(NULL, 0, cert_buffer, cert_length);
  AG_LOG(INFO, "verify result: %d", result);

  if (cert_buffer) {
    delete[] cert_buffer;
    cert_buffer = NULL;
  }

  return result;
#else
  return 0;
#endif
}

agora::base::IAgoraService* createAndInitAgoraService(bool enableAudioDevice,
                                                      bool enableAudioProcessor, bool enableVideo,bool enableuseStringUid,bool enablelowDelay,const char* appid) {
  int32_t buildNum = 0;
  getAgoraSdkVersion(&buildNum);
#if defined(SDK_BUILD_NUM)
  if ( buildNum != SDK_BUILD_NUM ) {
    AG_LOG(ERROR, "SDK VERSION CHECK FAILED!\nSDK version: %d\nAPI Version: %d\n", buildNum, SDK_BUILD_NUM);
    //return nullptr;
  }
#endif
  AG_LOG(INFO, "SDK version: %d\n", buildNum);
  auto service = createAgoraService();
  agora::base::AgoraServiceConfiguration scfg;
  scfg.appId = appid;
  scfg.enableAudioProcessor = enableAudioProcessor;
  scfg.enableAudioDevice = enableAudioDevice;
  scfg.enableVideo = enableVideo;
  scfg.useStringUid = enableuseStringUid;
  if(enablelowDelay){
    scfg.channelProfile = agora::CHANNEL_PROFILE_TYPE::CHANNEL_PROFILE_CLOUD_GAMING;
  }
  AG_LOG(INFO, "Before init");
  if (service->initialize(scfg) != agora::ERR_OK) {
    return nullptr;
  }

  AG_LOG(INFO, "Created log file at %s", DEFAULT_LOG_PATH);
  if (service->setLogFile(DEFAULT_LOG_PATH, DEFAULT_LOG_SIZE) != 0) {
    std::cout<<"returned from lifo file "<<std::endl;
    return nullptr;
  }
  if(verifyLicense() != 0) return nullptr;
  return service;
}
