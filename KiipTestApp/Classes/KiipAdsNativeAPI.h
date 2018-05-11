//
// Created by Daniel on 5/7/18.
//

#ifndef PROJ_ANDROID_STUDIO_KIIPADSNATIVEAPI_H
#define PROJ_ANDROID_STUDIO_KIIPADSNATIVEAPI_H

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    #include <jni.h>
    #include "platform/android/jni/JniHelper.h"
#endif

/* implement these functions with sdk api of different platforms */
#ifdef __cplusplus
extern "C" {
#endif

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        static char* jstringTostring(JNIEnv* env, jstring jstr);
        static std::string jstringToStdstring(JNIEnv* env, jstring jstr);

        //Kiip Ads required methods
        extern void KiipAdsInit(const char* key, const char* secrect);
        extern void KiipSaveMoment(const char* momentID);

        // Kiip Ads assist methods
        extern void KiipAdsSetTestMode(bool testMode);

    #endif

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

    #endif

#ifdef __cplusplus
}
#endif

#endif //PROJ_ANDROID_STUDIO_KIIPADSNATIVEAPI_H
