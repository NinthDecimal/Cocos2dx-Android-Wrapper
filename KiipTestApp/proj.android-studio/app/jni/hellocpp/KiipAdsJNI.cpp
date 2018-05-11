
#include "KiipAdsNativeAPI.h"
#include <android/log.h>
#include "HelloWorldScene.h"
#include "AppDelegate.h"
#include "cocos2d.h"


#define LOG_TAG    "KiipAdsJNI"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

#define CLASS_NAME "org/cocos2dx/cpp/KiipAdsJNI"

using namespace cocos2d;

#ifdef __cplusplus
extern "C" {
#endif


void KiipAdsInit(const char* key, const char* secret) {

    cocos2d::JniMethodInfo methodInfo;

    if (! JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "KiipAdsInitialize", "(Ljava/lang/String;Ljava/lang/String;)V"))
    {
        LOGD("Failed to find static method of KiipAdsInitialize");
        return;
    }

    jstring appKey = methodInfo.env->NewStringUTF(key);
    jstring appSecrect = methodInfo.env->NewStringUTF(secret);

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, appKey, appSecrect);
    methodInfo.env->DeleteLocalRef(appKey);
    methodInfo.env->DeleteLocalRef(appSecrect);
}


void KiipAdsSetTestMode(bool testMode) {
    cocos2d::JniMethodInfo methodInfo;

    LOGD("entered testmode");
    if (! JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "KiipSetTestMode", "(Z)V"))
    {
        LOGD("Failed to find static method of KiipSetTestMode");
        return;
    }

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, testMode);
}


void KiipSaveMoment(const char* momentID) {
    cocos2d::JniMethodInfo methodInfo;

    if (! JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "KiipSaveMoment", "(Ljava/lang/String;)V"))
    {
        LOGD("Failed to find static method of KiipSaveMoment");
        return;
    }

    jstring moment = methodInfo.env->NewStringUTF(momentID);

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, moment);
    methodInfo.env->DeleteLocalRef(moment);
}


#ifdef __cplusplus
}
#endif