#include <string.h>
#include "hello-jni.h"

#include <android/log.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "JNI",__VA_ARGS__)


jstring JNICALL
Java_com_example_jackfan_hellojniold_MainActivity_stringFromJNI( JNIEnv* env,
                                                  jobject thiz )
{
#if defined(__arm__)
    #if defined(__ARM_ARCH_7A__)
      #if defined(__ARM_NEON__)
        #if defined(__ARM_PCS_VFP)
          #define ABI "armeabi-v7a/NEON (hard-float)"
        #else
          #define ABI "armeabi-v7a/NEON"
        #endif
      #else
        #if defined(__ARM_PCS_VFP)
          #define ABI "armeabi-v7a (hard-float)"
        #else
          #define ABI "armeabi-v7a"
        #endif
      #endif
    #else
     #define ABI "armeabi"
    #endif
#elif defined(__i386__)
    #define ABI "x86"
#elif defined(__x86_64__)
    #define ABI "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
    #define ABI "mips64"
#elif defined(__mips__)
    #define ABI "mips"
#elif defined(__aarch64__)
#define ABI "arm64-v8a"
#else
    #define ABI "unknown"
#endif

    return env->NewStringUTF("Hello from JNI !  Compiled with ABI " ABI ".");
}

jint JNICALL
Java_com_example_jackfan_hellojniold_MainActivity_runTest( JNIEnv* env, jobject thiz,
    jint parameter1, jint parameter2, jstring parameterString)
{
    const char *c_string = env->GetStringUTFChars(parameterString, NULL);

    LOGD("runTest %d, %d - %s", parameter1, parameter2, c_string);

    env->ReleaseStringUTFChars(parameterString, c_string);
    return -10;
}