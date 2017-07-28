#include <jni.h>
#include <string>
#include "tesseract-file.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_moa_myjnitest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    double outputValue = mysqrt(25);

    std::string hello = "Hello from C++ with function value " ;

    return env->NewStringUTF(hello.c_str());
}
