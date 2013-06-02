
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxObject.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxObject()
{


    class_<AxObject ,boost::noncopyable> ("AxObject", init <IAAFObjectSP>())
    .def("GetClassName",&AxObject::GetClassName)
    .def("GetClassName",&AxObject::GetDictionary)
    .def("GetProperties",&AxObject::GetProperties)
    .def("GetDefinition",&AxObject::GetDefinition)
    ;
}

