#include <jni.h>
#include <string>
#include "Util.h"
#include "Test.h"
#include "ScanMemory.h"

ScanMemory *pMemory = NULL;

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_mama_readmemory_NativeHelper_stringFromJNI(
        JNIEnv *env, jclass type) {
    string hello = "Hello from C++";
    freopen("/data/local/tmp/loglog.txt", "w", stdout);
    pMemory = new ScanMemory();
    return env->NewStringUTF(hello.c_str());
}

int temp = 7777;

extern "C"
JNIEXPORT void JNICALL
Java_com_example_mama_readmemory_NativeHelper_bigger(JNIEnv *env, jclass type) {
    temp++;
    pMemory->bigger();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_mama_readmemory_NativeHelper_equal(JNIEnv *env, jclass type) {
    pMemory->equal();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_mama_readmemory_NativeHelper_smaller(JNIEnv *env, jclass type) {
    temp = temp - 10;
    pMemory->smaller();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_mama_readmemory_NativeHelper_newValue(JNIEnv *env, jclass type, jlong newValue) {
    pMemory->newValue(newValue);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_mama_readmemory_NativeHelper_clear(JNIEnv *env, jclass type) {
    pMemory->clear();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_mama_readmemory_NativeHelper_init(JNIEnv *env, jclass type, jlong value) {
    pMemory->initWithVlaue(value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_mama_readmemory_NativeHelper_test(
        JNIEnv *env, jclass type) {
    std::string hello = "Hello from C++";
    printf("%s\n", hello.c_str());
    Test test;
//    test.testCreateFolder();
//    test.testGetMaps();
//    test.testGetMapsWithFilter();
//    test.testGetMapsInfoWithFilter();
//    test.testScanMemory();
    ScanMemory scanMemory;
    scanMemory.initWithVlaue(7777);
    cout << "temp address: " << hex << &temp << endl;
}
