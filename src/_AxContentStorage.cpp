
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxContentStorage.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(AxContentStorage_GetMobs_overloads_0_1, GetMobs, 0, 1)


}// namespace 


// Module ======================================================================
void Export_pyste_src_AxContentStorage()
{
    class_< AxContentStorage, boost::noncopyable >("AxContentStorage", init< IAAFContentStorageSP >())
        .def("LookupMob", &AxContentStorage::LookupMob)
        .def("LookupEssenceData", &AxContentStorage::LookupEssenceData)
        .def("CountEssenceData", &AxContentStorage::CountEssenceData)
        .def("IsEssenceDataPresent", &AxContentStorage::IsEssenceDataPresent)
        .def("GetMobs", &AxContentStorage::GetMobs, AxContentStorage_GetMobs_overloads_0_1())
        .def("EnumEssenceData", &AxContentStorage::EnumEssenceData)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
    ;

}

