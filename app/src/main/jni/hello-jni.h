
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL
Java_com_example_jackfan_hellojniold_MainActivity_stringFromJNI( JNIEnv* env,
                                                  jobject thiz );
JNIEXPORT jint JNICALL
Java_com_example_jackfan_hellojniold_MainActivity_runTest( JNIEnv* env, jobject thiz,
    jint parameter1, jint parameter2, jstring parameterString);

#ifdef __cplusplus
}
#endif