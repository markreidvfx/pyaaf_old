
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxKLVData.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxKLVData()
{
    class_< AxKLVData, boost::noncopyable >("AxKLVData", init< IAAFKLVDataSP >())
        .def("Initialize", &AxKLVData::Initialize)
        .def("GetKey", &AxKLVData::GetKey)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFKLVDataSP", &AxKLVData::operator IAAFKLVDataSP)
    ;

}

