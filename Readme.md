## 部分内容记录

#### cout输出到logcat

```
# 方式一、设置属性
adb shell
su
stop
setprop log.redirect-stdio true
start

# 方式二、代码入口重定向到文件
freopen("/sdcard/tmp/loglog.txt", "w", stdout);
```

### 适合不同平台的log
```
	
I use a logger header to print crossplatform logs.

In c++ code just write LOGD("msg"); or LOGE("msg"); and print messages checking the platform.

Try creating a crossplatform log header like:

Logs.h

#       ifdef ANDROID
            // LOGS ANDROID
#           include <android/log.h>
#           define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG,__VA_ARGS__)
#           define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG  , LOG_TAG,__VA_ARGS__)
#           define LOGI(...) __android_log_print(ANDROID_LOG_INFO   , LOG_TAG,__VA_ARGS__)
#           define LOGW(...) __android_log_print(ANDROID_LOG_WARN   , LOG_TAG,__VA_ARGS__)
#           define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , LOG_TAG,__VA_ARGS__)
#           define LOGSIMPLE(...)
#       else
            // LOGS NO ANDROID
#           include <stdio.h>
#           define LOGV(...) printf("  ");printf(__VA_ARGS__); printf("\t -  <%s> \n", LOG_TAG);
#           define LOGD(...) printf("  ");printf(__VA_ARGS__); printf("\t -  <%s> \n", LOG_TAG);
#           define LOGI(...) printf("  ");printf(__VA_ARGS__); printf("\t -  <%s> \n", LOG_TAG);
#           define LOGW(...) printf("  * Warning: "); printf(__VA_ARGS__); printf("\t -  <%s> \n", LOG_TAG);
#           define LOGE(...) printf("  *** Error:  ");printf(__VA_ARGS__); printf("\t -  <%s> \n", LOG_TAG);
#           define LOGSIMPLE(...) printf(" ");printf(__VA_ARGS__);
#       endif // ANDROID
```

### 内存地址记录
```
af0df000-af135000 r-xp 00000000 b3:1c 188348     /data/app/com.example.mama.readmemory-2/lib/arm/libnative-lib.so
af136000-af139000 r--p 00056000 b3:1c 188348     /data/app/com.example.mama.readmemory-2/lib/arm/libnative-lib.so
af139000-af13a000 rw-p 00059000 b3:1c 188348     /data/app/com.example.mama.readmemory-2/lib/arm/libnative-lib.so

pointer: 0xb4b30e80
pointer: 0xb4b38280
pointer: 0xb4b384c0
pointer: 0xb4b38340
pointer: 0xb4b38b20
pointer: 0xb4b38580
pointer: 0xb4b38be0

b4800000-b5000000 rw-p 00000000 00:00 0          [anon:libc_malloc]
# 内存落在libc_malloc区域，堆上
```

### 内容

```
1/ 解析程序的/proc/pid/maps，指定模块及malloc的相关区域内存
2/ 等值、变大、变小扫描
```