package com.opencv.opencvlib;

import android.graphics.Bitmap;

public class OpencvHandle {

    static {
        System.loadLibrary("native-cv");
    }

    private static OpencvHandle mInstance = null;

    public static OpencvHandle getInstance() {
        if (mInstance == null) {
            synchronized (OpencvHandle.class) {
                if (mInstance == null) {
                    mInstance = new OpencvHandle();
                }
            }
        }
        return mInstance;
    }

    private OpencvHandle(){}

    public native String test();

    public native void processBitmap(Bitmap bitmap);
}
