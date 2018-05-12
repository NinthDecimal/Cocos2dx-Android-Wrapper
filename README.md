# Kiip Android SDK Wrapper for Cocos2dx

This project provides the Kiip SDK (v3.0.0) for use with the Cocos2d-x framework in Android Studio. 

Helpers and `KiipSDK.jar` are located in `../proj.android-studio/app/libs`.

## Run Sample App

  1. Clone or download the KiipTestApp
  2. Open the `pro.android-studio` using Android Studio
  3. If this is your first time setting up the Cocos2dx environment please review the [Android Studio installation notes](http://www.cocos2d-x.org/docs/cocos2d-x/en/installation/Android-Studio.html)
  4. Create an app in the [Kiip Dashboard](https://app.kiip.me/app/dashboard)
  5. Open `HellowWorldScene.cpp`, located in `../Classes`, and modify the `gameKey` and `gameSecret` using credentials obtained in (4)
  6. Run the project (try Clean Project and Refresh Linked C++ Project, if it needs to be rebuilt)
  7. Pressing the power button on the bottom right corner will trigger an ad moment

## Instructions

If you want to use KiipSDK inside your Cocos2dx project, please follow the instructions down below.
Note: We are using **Android Studio** for this tutorial.

### [To Get Started]
  1. Create an app in the [Kiip Dashboard](https://app.kiip.me/app/dashboard)
  2. Project helpers and dependencies
      - `KiipSDK.jar` (`../proj.android-studio/app/libs`) **Must be present**
      - `KiipAdsJNI.java` (`../proj.android-studio/app/src/org/cocos2dx/cpp`)
      - `KiipAdsListener` (`../proj.android-studio/app/src/org/cocos2dx/cpp`)
      - `KiipAdsJNI.cpp` (`../proj.android-studio/app/jni/hellocpp`)
      - `KiipAdsNativeAPI.h` (`../Classes`)
  3. Modify your `Android.mk` file to link `KiipAdsJNI.cpp` file in your project
      - ex) `$(LOCAL_PATH)/hellocpp/KiipAdsJNI.cpp \`
  4. `KiipAdsNativeAPI.h` contains three helper Kiip functions
      - `KiipAdsInit(const char* key, const char* secrect)`
      - `KiipSaveMoment(const char* momentID)`
      - `KiipAdsSetTestMode(bool testMode)`
  5. Check `HellowWorldScene.cpp` (`../Classes`) file to see how it is used
