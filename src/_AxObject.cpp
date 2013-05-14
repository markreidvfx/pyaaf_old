
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


    class_<AxObject ,std::auto_ptr<AxObject>, boost::noncopyable> ("AxObject", no_init)
    .def("GetClassName",&AxObject::GetClassName)
    .def("GetProperties",&AxObject::GetProperties)
    .def("GetDefinition",&AxObject::GetDefinition)
    ;
}

