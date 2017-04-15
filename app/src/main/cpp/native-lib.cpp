#include <jni.h>
#include <string>
#include "Util.h"
#include "HackEngine.h"

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
    int pid = getpid();
    cout << "pid = " << pid << endl;
    vector<string> mapVec;
    HackEngine::getInstance()->getProcMaps(pid, mapVec);
    for (string str:mapVec) {
        cout << str << endl;
    }

    cout << "after filter:" << endl;

    vector<string> mapVecFilter;
    vector<string> mapVecFilterTag;
    mapVecFilterTag.push_back("libc_malloc");
    mapVecFilterTag.push_back("libnative-lib.so");
    HackEngine::getInstance()->getProcMapsWithFilter(pid, mapVecFilter, mapVecFilterTag);
    for (string str:mapVecFilter) {
        cout << str << endl;
    }
    vector<ModuleMemoryInfo> moduleVec;

    HackEngine::getInstance()->getProcMapsModuleWithFilter(pid, moduleVec, mapVecFilter);

    for (ModuleMemoryInfo module:moduleVec) {
        cout << "start: " << hex << module.startAddress
             << ", end: " << hex << module.endAddress
             << ", attr: " << module.attr
             << ", name: " << module.name << endl;
    }
}
