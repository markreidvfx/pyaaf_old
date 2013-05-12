
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxDictionary.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxDictionary()
{
    class_< AxDictionary, boost::noncopyable >("AxDictionary", init< IAAFDictionarySP >())
        .def(init< IAAFDictionary2SP >())
        .def("isKnownTypeDef", &AxDictionary::isKnownTypeDef)
        .def("isKnownOperationDef", &AxDictionary::isKnownOperationDef)
        .def("isKnownParameterDef", &AxDictionary::isKnownParameterDef)
        .def("isKnownInterpolationDef", &AxDictionary::isKnownInterpolationDef)
        .def("RegisterClassDef", &AxDictionary::RegisterClassDef)
        .def("LookupTypeDef", &AxDictionary::LookupTypeDef)
        .def("LookupClassDef", &AxDictionary::LookupClassDef)
        .def("LookupDataDef", &AxDictionary::LookupDataDef)
        .def("LookupOperationDef", &AxDictionary::LookupOperationDef)
        .def("LookupParameterDef", &AxDictionary::LookupParameterDef)
        .def("LookupContainerDef", &AxDictionary::LookupContainerDef)
        .def("LookupInterpolationDef", &AxDictionary::LookupInterpolationDef)
        .def("LookupCodecDef", &AxDictionary::LookupCodecDef)
        .def("GetClassDefs", &AxDictionary::GetClassDefs)
        .def("GetTypeDefs", &AxDictionary::GetTypeDefs)
        .def("GetDataDefs", &AxDictionary::GetDataDefs)
        .def("GetOperationDefs", &AxDictionary::GetOperationDefs)
        .def("GetParameterDefs", &AxDictionary::GetParameterDefs)
        .def("GetPluginDefs", &AxDictionary::GetPluginDefs)
        .def("GetContainerDefs", &AxDictionary::GetContainerDefs)
        .def("GetInterpolationDefs", &AxDictionary::GetInterpolationDefs)
        .def("GetCodecDefs", &AxDictionary::GetCodecDefs)
        .def("GetKLVDataDefs", &AxDictionary::GetKLVDataDefs)
        .def("GetTaggedValueDefs", &AxDictionary::GetTaggedValueDefs)
        .def("RegisterOpaqueTypeDef", &AxDictionary::RegisterOpaqueTypeDef)
        .def("RegisterOperationDef", &AxDictionary::RegisterOperationDef)
        .def("RegisterParameterDef", &AxDictionary::RegisterParameterDef)
        .def("RegisterCodecDef", &AxDictionary::RegisterCodecDef)
        .def("RegisterKLVDataKey", &AxDictionary::RegisterKLVDataKey)
        .def("RegisterDataDef", &AxDictionary::RegisterDataDef)
        .def("RegisterPluginDef", &AxDictionary::RegisterPluginDef)
        .def("RegisterContainerDef", &AxDictionary::RegisterContainerDef)
        .def("RegisterInterpolationDef", &AxDictionary::RegisterInterpolationDef)
        .def("RegisterKLVDataDef", &AxDictionary::RegisterKLVDataDef)
        .def("RegisterTaggedValueDef", &AxDictionary::RegisterTaggedValueDef)
        .def("CreateInstance", &AxDictionary::CreateInstance)
        .def("CreateMetaInstance", &AxDictionary::CreateMetaInstance)
        .def("CountOpaqueTypeDefs", &AxDictionary::CountOpaqueTypeDefs)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFDictionarySP", &AxDictionary::operator IAAFDictionarySP)
        .def("to_IAAFDictionary2SP", &AxDictionary::operator IAAFDictionary2SP)
    ;

}

