#include <jni.h>
#include <string>
#include <android/bitmap.h>
#include<android/log.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

#define loge(content)   __android_log_write(ANDROID_LOG_ERROR,"yhkj",content)
#define logd(content)   __android_log_write(ANDROID_LOG_DEBUG,"yhkj",content)

extern "C"
JNIEXPORT jstring JNICALL
Java_com_opencv_opencvlib_OpencvHandle_test(JNIEnv *env, jobject thiz) {
    char strBuffer[128];
    sprintf(strBuffer, "Hello from opencvv %s\n", CV_VERSION);
//    hello += string(cv::CV_VERSION_MAJOR) ;
    return env->NewStringUTF(strBuffer);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_opencv_opencvlib_OpencvHandle_processBitmap(JNIEnv *env, jobject thiz, jobject bitmap) {
    AndroidBitmapInfo bitmapInfo;
    void* pixels;
    CV_Assert(AndroidBitmap_getInfo(env, bitmap, & bitmapInfo) >= 0);
    CV_Assert(AndroidBitmap_lockPixels(env, bitmap, &pixels) >= 0);
    CV_Assert(pixels);
    if (bitmapInfo.format == ANDROID_BITMAP_FORMAT_RGBA_8888) {
        Mat temp(bitmapInfo.height, bitmapInfo.width, CV_8UC4, pixels);
        Mat gray;
        cvtColor(temp, gray, COLOR_RGBA2GRAY);
        cvtColor(gray, temp, COLOR_GRAY2RGBA);
    } else if (bitmapInfo.format == ANDROID_BITMAP_FORMAT_RGB_565) {
        Mat temp(bitmapInfo.height, bitmapInfo.width, CV_8UC2, pixels);
        Mat gray;
        cvtColor(temp, gray, COLOR_RGB2GRAY);
        cvtColor(gray, temp, COLOR_GRAY2RGB);
    }
    AndroidBitmap_unlockPixels(env, bitmap);
    logd("processBitmap complete.");
}