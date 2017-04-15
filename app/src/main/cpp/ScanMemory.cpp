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
//    printModuleInfo();

    for (ModuleMemoryInfo module:moduleVec) {
        for (unsigned long i = module.startAddress; i < module.endAddress; i += 4) {
            if (*(unsigned long *) i == lastSearchValue) {
                resultVec.push_back(i);
            }
        }
    }
    printResult();
}

void ScanMemory::printResult( ) const {
    cout << "test : [" << lastSearchValue << "], found count : [" << resultVec.size() << "]." << endl;
    if (resultVec.size() < 20) {
        for (unsigned long address:resultVec) {
            cout << "address: " << hex << address << endl;
        }
    }
}

void ScanMemory::printModuleInfo() const {
    for (ModuleMemoryInfo module:moduleVec) {
        cout << "start: " << hex << module.startAddress
             << ", end: " << hex << module.endAddress
             << ", attr: " << module.attr
             << ", name: " << module.name << endl;
    }
}

void ScanMemory::newValue(unsigned value) {
    lastSearchValue = value;
    equal();
}

void ScanMemory::bigger() {
    vector<unsigned long> tempVec;
    for (unsigned long oldValueAddress:resultVec) {
        if (*(unsigned long *) oldValueAddress > lastSearchValue) {
            tempVec.push_back(oldValueAddress);
        }
    }
    resultVec = tempVec;
    printResult();
}

void ScanMemory::equal() {
    vector<unsigned long> tempVec;
    for (unsigned long oldValueAddress:resultVec) {
        if (*(unsigned long *) oldValueAddress == lastSearchValue) {
            tempVec.push_back(oldValueAddress);
        }
    }
    resultVec = tempVec;
    printResult();
}

void ScanMemory::smaller() {
    vector<unsigned long> tempVec;
    for (unsigned long oldValueAddress:resultVec) {
        if (*(unsigned long *) oldValueAddress < lastSearchValue) {
            tempVec.push_back(oldValueAddress);
        }
    }
    resultVec = tempVec;
    printResult();
}

void ScanMemory::clear() {
    lastSearchValue = 0;
    resultVec.clear();
    moduleVec.clear();
}
