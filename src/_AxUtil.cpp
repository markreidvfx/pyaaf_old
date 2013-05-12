
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxUtil.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxUtil()
{
    class_< AxStringUtil >("AxStringUtil", init<  >())
        .def(init< const AxStringUtil& >())
        .def("bool2Str", (AxString (*)(bool))&AxStringUtil::bool2Str)
        .def("bool2Str", (AxString (*)(aafBoolean_t))&AxStringUtil::bool2Str)
        .def("int2StrHex", &AxStringUtil::int2StrHex)
        .def("int2Str", &AxStringUtil::int2Str)
        .def("uid2Str", &AxStringUtil::uid2Str)
        .def("mobid2Str", &AxStringUtil::mobid2Str)
        .def("mbtowc", &AxStringUtil::mbtowc)
        .def("wctomb", &AxStringUtil::wctomb)
        .def("strtol", (long int (*)(const char*))&AxStringUtil::strtol)
        .def("strtoul", (long unsigned int (*)(const char*))&AxStringUtil::strtoul)
        .def("strtol", (long int (*)(const AxString&))&AxStringUtil::strtol)
        .def("strtoul", (long unsigned int (*)(const AxString&))&AxStringUtil::strtoul)
        .staticmethod("strtol")
        .staticmethod("mbtowc")
        .staticmethod("wctomb")
        .staticmethod("int2Str")
        .staticmethod("int2StrHex")
        .staticmethod("uid2Str")
        .staticmethod("strtoul")
        .staticmethod("mobid2Str")
        .staticmethod("bool2Str")
    ;

}

