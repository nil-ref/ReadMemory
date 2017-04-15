#include <jni.h>
#include <string>
#include "Util.h"
#include "Test.h"
#include "ScanMemory.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_mama_readmemory_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Hello from C++";
    freopen("/data/local/tmp/loglog.txt", "w", stdout);
    return env->NewStringUTF(hello.c_str());
}
int temp = 7777;
extern "C"
JNIEXPORT void JNICALL
Java_com_example_mama_readmemory_MainActivity_search(
        JNIEnv *env,
        jobject /* this */) {
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
