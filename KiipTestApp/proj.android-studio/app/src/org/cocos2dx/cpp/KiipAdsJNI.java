package org.cocos2dx.cpp;

import android.app.Activity;
import android.util.Log;

import me.kiip.sdk.Kiip;
import me.kiip.sdk.Modal;
import me.kiip.sdk.Notification;
import me.kiip.sdk.Poptart;

public class KiipAdsJNI {
    private final static String TAG = KiipAdsJNI.class.getSimpleName();
    public static Activity activity;
    public static KiipAdsListener kiipAdsListener;


    public static void KiipAdsInitialize(final String appKey, final String appSecret){
        Log.d(TAG, "[Kiip] KiipAdsInitialize");
        if(appKey == null || appKey.isEmpty() || appSecret == null || appSecret.isEmpty()){
            Log.d(TAG,"[Kiip] KiipAdsInitialize failed");
            return;
        }

        activity.runOnUiThread(new Runnable()
        {
            public void run()
            {
                Kiip.init(activity.getApplication(),appKey,appSecret);
                Kiip.getInstance().setOnContentListener(kiipAdsListener);
            }
        });
    }


    public static void KiipSetTestMode(final boolean testMode) {
        Log.d(TAG, "[Kiip] KiipSetTestMode start");
        activity.runOnUiThread(new Runnable()
        {
            public void run()
            {
                Kiip.getInstance().setTestMode(testMode);
            }
        });
    }


    public static void KiipSaveMoment(final String momentID) {
        Log.d(TAG, "[Kiip] KiipSaveMoment started");

        Kiip.getInstance().saveMoment(momentID, new Kiip.Callback() {
            @Override
            public void onFailed(Kiip kiip, Exception e) {

            }

            @Override
            public void onFinished(Kiip kiip, Poptart poptart) {
                final Notification notification = poptart.getNotification();
                final Modal modal = poptart.getModal();
                poptart.setOnShowListener(kiipAdsListener);
                poptart.setOnDismissListener(kiipAdsListener);

                if (notification != null) {
                    notification.setOnShowListener(kiipAdsListener);
                    notification.setOnClickListener(kiipAdsListener);
                    notification.setOnDismissListener(kiipAdsListener);
                }

                if (modal != null) {
                    modal.setOnShowListener(kiipAdsListener);
                    modal.setOnDismissListener(kiipAdsListener);
                    modal.setVideoListener(kiipAdsListener);
                    modal.setWebViewListener(kiipAdsListener);
                }
                poptart.show(activity);
            }
        });
    }

}
