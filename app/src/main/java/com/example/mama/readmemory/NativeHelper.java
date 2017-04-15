package com.example.mama.readmemory;

/**
 * Created by mama on 2017/4/15.
 */

public class NativeHelper {
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public static native String stringFromJNI();
    public static native void test();
    public static native void init(long value);
    public static native void bigger();
    public static native void equal();
    public static native void smaller();
    public static native void newValue(long newValue);
    public static native void clear();
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
