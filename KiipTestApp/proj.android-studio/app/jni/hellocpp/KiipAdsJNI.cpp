//
// Created by Daniel on 5/7/18.
//


#include "KiipAdsNativeAPI.h"
#include <android/log.h>
#include "HelloWorldScene.h"
#include "AppDelegate.h"
#include "cocos2d.h"


#define LOG_TAG    "KiipAdsJNI"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

#define CLASS_NAME "org/cocos2dx/cpp/KiipAdsJNI"

static char* jstringTostring(JNIEnv* env, jstring jstr)
{
    char* rtn = NULL;

    // convert jstring to byte array
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
    jsize alen =  env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);

    // copy byte array into char[]
    if (alen > 0)
    {
        rtn = new char[alen + 1];
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);

    return rtn;
}

static std::string jstringToStdstring(JNIEnv* env, jstring jstr) {

    char* cstring = NULL;
    cstring = jstringTostring(env, jstr);
    //std::string returnString;
    //returnString = std::string str(cstring);
    std::string str(cstring);
    return str;
}

using namespace cocos2d;


#ifdef __cplusplus
extern "C" {
#endif


void KiipAdsInit(const char* key, const char* secret) {

    JniMethodInfo methodInfo;

    if (! JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "KiipAdsInitialize", "(Ljava/lang/String;Ljava/lang/String;)V"))
    {
        LOGD("Failed to find static method of KiipAdsInitialize");
        return;
    }

    jstring appKey = methodInfo.env->NewStringUTF(key);
    jstring appSecrect = methodInfo.env->NewStringUTF(secret);

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, appKey, appSecrect);
}


void KiipAdsSetTestMode(bool testMode) {
    JniMethodInfo methodInfo;

    LOGD("entered testmode");
    if (! JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "KiipSetTestMode", "(Z)V"))
    {
        LOGD("Failed to find static method of KiipSetTestMode");
        return;
    }

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, testMode);
}


void KiipSaveMoment(const char* momentID) {
    JniMethodInfo methodInfo;

    if (! JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "KiipSaveMoment", "(Ljava/lang/String;)V"))
    {
        LOGD("Failed to find static method of KiipSaveMoment");
        return;
    }

    jstring appKey = methodInfo.env->NewStringUTF(momentID);

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, appKey);
}


#ifdef __cplusplus
}
#endif