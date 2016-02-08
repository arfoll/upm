// Include doxygen-generated documentation
%include "pyupm_doxy2swig.i"
%module pyupm_adafruitledbck
%include "../upm.i"

%feature("autodoc", "3");

%include "adafruitledbck.h"
%{
    #include "adafruitledbck.h"
%}
