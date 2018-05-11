# Kiip Android SDK Wrapper for Cocos2dx

This project includes Kiip SDK (v3.0.0) for Cocos2dx using Android Studio. 

There are few files you want to use along with the KiipSDK.jar located in ../proj.android-studio/app/libs.

## Run Sample App

  1. Clone or download the KiipTestApp
  2. Open the pro.android-studio using Android Studio
  3. If this is your frist time setting up the Cocos2dx environment please check [here](http://www.cocos2d-x.org/docs/cocos2d-x/en/installation/Android-Studio.html)
  4. Create a Project in the [Kiip Ads Dashboard](https://app.kiip.me/app/dashboard)
  5. Check HellowWorldScene.cpp (../Classes) and modify the gameKey and gameSecret from Kiip App
  6. Run the project (try Clean Project and Refresh Linked C++ Project, if you can't run it)
  7. Pressing the power button on the bottom right coner will trigger an ad

## Instructions

If you want to use KiipSDK inside your Cocos2dx project, please follow the instructions down below.
Note: We are using **Android Studio** for this tutorial.

### [To Get Started]
  1. Create a Project in the [Kiip Ads Dashboard](https://app.kiip.me/app/dashboard)
  2. There are serveral files you may want to use (or as your references) inside your project
      - KiipSDK.jar (../proj.android-studio/app/libs) **Must download this**
      - KiipAdsJNI.java (../proj.android-studio/app/src/org/cocos2dx/cpp)
      - KiipAdsListener (../proj.android-studio/app/src/org/cocos2dx/cpp)
      - KiipAdsJNI.cpp (../proj.android-studio/app/jni/hellocpp)
      - KiipAdsNativeAPI.h (../Classes)
  3. Modify your Android.mk file by linking the KiipAdsJNI.cpp file in your project
      - ex) $(LOCAL_PATH)/hellocpp/KiipAdsJNI.cpp \
  4. KiipAdsNativeAPI.h contains three functions that helps you initialize Kiip functions
      - KiipAdsInit(const char* key, const char* secrect)
      - KiipSaveMoment(const char* momentID)
      - KiipAdsSetTestMode(bool testMode)
  5. Check HellowWorldScene.cpp (../Classes) file and see how it's being used
