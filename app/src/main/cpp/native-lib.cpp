#include <jni.h>
#include <string>
#include "Util.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_mama_readmemory_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Hello from C++";
    freopen("/data/local/tmp/loglog.txt", "w", stdout);
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_mama_readmemory_MainActivity_search(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    printf("%s\n", hello.c_str());
    Util::createFolder(string("/data/data/com.example.mama.readmemory/ssss"));
    char *p = (char *) Util::pe_malloc(88);
    memset(p, 'c', 88);
    int *temp = (int *) p;
    printf("pointer: %p\n", p);
    int value = 80;
    vector<unsigned int> vec;
    // 速度还是很快的，需要获取模块地址，不然可能有些地址不能操作
    for (unsigned int i = 0; i < 0x8000 / 4; i++) {
        // cout << "value: " << hex << * (temp + i) << endl;
        if (*(temp + i) == value) {
            vec.push_back(i);
//            if(vec.size()>500){
//                break;
//            }
        }
    }
    cout << "finish. the value of " << value << "'s count is: " << vec.size() << endl;
}
