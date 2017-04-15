//
// Created by MaMa on 2017/4/15.
//

#include "HackEngine.h"
#include <mutex>
#include "Util.h"

HackEngine *HackEngine::instance = NULL;

int HackEngine::getProcMaps(int pid, vector<string> &vec) {
    char buf[50] = {0};
    sprintf(buf, "cat /proc/%d/maps", pid);
    Util::executeCmdWithResult(string(buf), vec);
    return 0;
}

HackEngine::HackEngine() {

}

HackEngine::~HackEngine() {

}

HackEngine *HackEngine::getInstance() {
    if (!instance) {
        std::mutex mt;
        mt.lock();
        if (!instance) {
            instance = new HackEngine();
        }
        mt.unlock();
    }
    return instance;
}

void HackEngine::getProcMapsFilter(int pid, vector<string> &resultVec,
                                   const vector<string> &filterTagVec) {
    vector<string> tempVec;
    getProcMaps(pid, tempVec);
    for (string str:tempVec) {
        bool find = false;
        for (string inner:filterTagVec) {
            if (str.find(inner) != string::npos) {
                find = true;
                break;
            }
        }
        if (find) {
            resultVec.push_back(str);
        }
    }
}
