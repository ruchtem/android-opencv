#include <jni.h>
#include <string>
#include <android/bitmap.h>
#include <android/log.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define LOG_TAG    "native-lib"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

extern "C" {

JNIEXPORT void JNICALL
Java_com_example_moa_myjnitest_MainActivity_bitmapFromJNI(JNIEnv *env, jclass type, jobject bitmap,
                                                          jbyteArray data_) {
    jbyte *data = env->GetByteArrayElements(data_, NULL);
    void *pixels;
    AndroidBitmapInfo info;
    int ret;

    if ((ret = AndroidBitmap_getInfo(env, bitmap, &info)) < 0) {
        LOGE("AndroidBitmap_getInfo() failed ! error=%d", ret);
        return;
    }

    if (info.format != ANDROID_BITMAP_FORMAT_RGB_565) {
        LOGE("Bitmap format is not RGB_565 !");
        return;
    }

    if ((ret = AndroidBitmap_lockPixels(env, bitmap, &pixels)) < 0) {
        LOGE("AndroidBitmap_lockPixels() failed ! error=%d", ret);
    }

    // Manipulate pixels here
    // int rows, int cols, int type, void *data, size_t step=AUTO_STEP
    cv::Mat src = cv::Mat(info.height, info.width, CV_8UC1, &data);
    cv::Mat dst;

    cv::cvtColor(src, dst, cv::COLOR_YUV2RGBA_NV21);


    AndroidBitmap_unlockPixels(env, bitmap);

    env->ReleaseByteArrayElements(data_, data, 0);
}

JNIEXPORT jstring JNICALL
Java_com_example_moa_myjnitest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

}