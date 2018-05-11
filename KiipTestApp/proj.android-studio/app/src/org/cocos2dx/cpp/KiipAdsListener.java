package org.cocos2dx.cpp;

import android.content.DialogInterface;
import android.util.Log;

import me.kiip.sdk.Kiip;
import me.kiip.sdk.Modal;
import me.kiip.sdk.Notification;

public class KiipAdsListener implements Kiip.OnContentListener, DialogInterface.OnShowListener, DialogInterface.OnDismissListener,
        Notification.OnShowListener, Notification.OnClickListener, Notification.OnDismissListener,
        Modal.OnShowListener, Modal.OnDismissListener, Modal.VideoListener, Modal.WebViewListener {

    private final static String TAG = KiipAdsListener.class.getSimpleName();

    @Override
    public void onContent(String contentId, int quantity, String transactionId, String signature) {
        Log.d(TAG,  String.format("[Kiip] contentId = %s, quantity = %d, " +
                "transactionId = %s, signature = %s", contentId, quantity, transactionId, signature));
    }


    @Override
    public void onDismiss(DialogInterface dialogInterface) {
        Log.d(TAG, "[Kiip] onDismiss Ad");
    }

    @Override
    public void onShow(DialogInterface dialogInterface) {
        Log.d(TAG, "[Kiip] onShow Ad");
    }

    @Override
    public void onDismiss(Modal modal) {
        Log.d(TAG, "[Kiip] onDismiss modal");
    }

    @Override
    public void onShow(Modal modal) {
        Log.d(TAG, "[Kiip] onShow modal");
    }

    @Override
    public void onVideoWillPlay() {
        Log.d(TAG, "[Kiip] onVideoWillPlay in modal");
    }

    @Override
    public void onVideoStopped() {
        Log.d(TAG, "[Kiip] onVideoStopped in modal");
    }

    @Override
    public void onVideoFinished() {
    }

    @Override
    public void onWebViewOpen() {
        Log.d(TAG, "[Kiip] onWebViewOpen in modal");
    }

    @Override
    public void onWebViewDismiss() {
        Log.d(TAG, "[Kiip] onWebViewDismiss in modal");
    }

    @Override
    public void onClick(Notification notification) {
        Log.d(TAG, "[Kiip] onClick Notification");
    }

    @Override
    public void onDismiss(Notification notification) {
        Log.d(TAG, "[Kiip] onDismiss Notification");
    }

    @Override
    public void onShow(Notification notification) {
        Log.d(TAG, "[Kiip] onShow Notification");
    }
}
