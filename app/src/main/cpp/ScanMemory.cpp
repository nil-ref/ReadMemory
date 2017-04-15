//
// Created by MaMa on 2017/4/15.
//

#include "ScanMemory.h"
#include "HackEngine.h"

void ScanMemory::initWithVlaue(unsigned long value) {
    lastSearchValue = value;
    vector<string> mapVecFilterTag;
    mapVecFilterTag.push_back("libc_malloc");
    mapVecFilterTag.push_back(moduleName);
    moduleVec.clear();
    HackEngine::getInstance()->getProcMapsModuleWithFilter(getpid(), moduleVec, mapVecFilterTag);
//    for (ModuleMemoryInfo module:moduleVec) {
//        cout << "start: " << hex << module.startAddress
//             << ", end: " << hex << module.endAddress
//             << ", attr: " << module.attr
//             << ", name: " << module.name << endl;
//    }

    for (ModuleMemoryInfo module:moduleVec) {
        for (unsigned long i = module.startAddress; i < module.endAddress; i += 4) {
            if (*(unsigned long *) i == lastSearchValue) {
                resultVec.push_back(i);
            }
        }
    }
    cout << "search : [" << value << "], found count : [" << resultVec.size() << "]." << endl;
    if (resultVec.size() < 10) {
        for (unsigned long address:resultVec) {
            cout << "address: " << hex << address << endl;
        }
    }
}

void ScanMemory::newValue(unsigned value) {
    lastSearchValue = value;
    vector<unsigned long> tempVec;
    for (unsigned long oldValueAddress:resultVec) {
        if (*(unsigned long *) oldValueAddress != lastSearchValue) {
            tempVec.push_back(oldValueAddress);
        }
    }
    resultVec = tempVec;
}

void ScanMemory::bigger() {

}

void ScanMemory::equal() {

}

void ScanMemory::smaller() {

}

void ScanMemory::restart() {

}
