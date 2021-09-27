#include <jni.h>
#include <string>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

extern "C" JNIEXPORT jstring JNICALL
Java_com_opencv_stitch_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from opencv ";
    char strBuffer[128];
    sprintf(strBuffer, "Hello from opencv %s\n", CV_VERSION);
//    hello += string(cv::CV_VERSION_MAJOR) ;
    return env->NewStringUTF(strBuffer);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_opencv_opencvlib_OpencvHandle_test(JNIEnv *env, jobject thiz) {
    char strBuffer[128];
    sprintf(strBuffer, "Hello from opencvv %s\n", CV_VERSION);
//    hello += string(cv::CV_VERSION_MAJOR) ;
    return env->NewStringUTF(strBuffer);
}