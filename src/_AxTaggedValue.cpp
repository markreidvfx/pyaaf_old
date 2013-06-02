
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxTaggedValue.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxTaggedValue()
{
    class_< AxTaggedValue, boost::noncopyable >("AxTaggedValue", init< IAAFTaggedValueSP >())
        .def("Initialize", &AxTaggedValue::Initialize)
        .def("GetName", &AxTaggedValue::GetName)
        .def("GetTypeDefinition", &AxTaggedValue::GetTypeDefinition)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFTaggedValueSP", &AxTaggedValue::operator IAAFTaggedValueSP)
    ;

}

