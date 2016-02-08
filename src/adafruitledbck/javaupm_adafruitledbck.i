%module javaupm_adafruitledbck
%include "../upm.i"

%{
    #include "adafruitledbck.h"
%}

%include "adafruitledbck.h"

%pragma(java) jniclasscode=%{
    static {
        try {
            System.loadLibrary("javaupm_adafruitledbck");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Native code library failed to load. \n" + e);
            System.exit(1);
        }
    }
%}
