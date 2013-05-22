
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxKLVData.h>
#include <create_instance.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

template < typename T >
void Initialize_Wrapper(AxKLVData&  axKLVData,
                  aafUID_t& key,
                  T pValue)
{
    axKLVData.Initialize(key, sizeof(pValue), reinterpret_cast<aafDataBuffer_t>(&pValue) );
    
};



// Module ======================================================================
void Export_pyste_src_AxKLVData()
{


    class_< AxKLVData, boost::noncopyable >("AxKLVData", init< IAAFKLVDataSP >())
        .def("Initialize", Initialize_Wrapper<int>)
        .def("Initialize_aafUInt8", Initialize_Wrapper<aafUInt8>)
        .def("Initialize_aafUInt16", Initialize_Wrapper<aafUInt16>)
        .def("Initialize_aafUInt32", Initialize_Wrapper<aafUInt32>)
        .def("GetKey", &AxKLVData::GetKey)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFKLVDataSP", &AxKLVData::operator IAAFKLVDataSP)
        .def("CreateInstance",create_instance<IAAFKLVData, AxKLVData>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;
}

