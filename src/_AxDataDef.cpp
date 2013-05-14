
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxDefObject.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxDataDef()
{
    class_< AxDefObject, boost::noncopyable >("AxDefObject", init< IAAFDefObjectSP >())
        .def("GetAUID", &AxDefObject::GetAUID)
        .def("GetName", &AxDefObject::GetName)
        .def("GetDescription", &AxDefObject::GetDescription)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFDefObjectSP", &AxDefObject::operator IAAFDefObjectSP)
    ;

    class_< AxContainerDef, bases< AxDefObject > , boost::noncopyable >("AxContainerDef", init< IAAFContainerDefSP >())
        .def("Initialize", &AxContainerDef::Initialize)
        .def("to_IAAFContainerDefSP", &AxContainerDef::operator IAAFContainerDefSP)
    ;

    class_< AxInterpolationDef, bases< AxDefObject > , boost::noncopyable >("AxInterpolationDef", init< IAAFInterpolationDefSP >())
        .def("Initialize", &AxInterpolationDef::Initialize)
        .def("to_IAAFInterpolationDefSP", &AxInterpolationDef::operator IAAFInterpolationDefSP)
    ;

    class_< AxParameterDef, bases< AxDefObject > , boost::noncopyable >("AxParameterDef", init< IAAFParameterDefSP >())
        .def("Initialize", &AxParameterDef::Initialize)
        .def("GetTypeDefinition", &AxParameterDef::GetTypeDefinition)
        .def("SetDisplayUnits", &AxParameterDef::SetDisplayUnits)
        .def("GetDisplayUnits", &AxParameterDef::GetDisplayUnits)
        .def("GetDisplayUnitsBufLen", &AxParameterDef::GetDisplayUnitsBufLen)
        .def("to_IAAFParameterDefSP", &AxParameterDef::operator IAAFParameterDefSP)
    ;

    class_< AxPluginDef, bases< AxDefObject > , boost::noncopyable >("AxPluginDef", init< IAAFPluginDefSP >())
        .def("Initialize", &AxPluginDef::Initialize)
        .def("SetCategoryClass", &AxPluginDef::SetCategoryClass)
        .def("SetPluginVersionString", &AxPluginDef::SetPluginVersionString)
        .def("SetManufacturerID", &AxPluginDef::SetManufacturerID)
        .def("SetPluginManufacturerName", &AxPluginDef::SetPluginManufacturerName)
        .def("SetIsSoftwareOnly", &AxPluginDef::SetIsSoftwareOnly)
        .def("SetIsAccelerated", &AxPluginDef::SetIsAccelerated)
        .def("SetSupportsAuthentication", &AxPluginDef::SetSupportsAuthentication)
        .def("SetManufacturerInfo", &AxPluginDef::SetManufacturerInfo)
        .def("to_IAAFPluginDefSP", &AxPluginDef::operator IAAFPluginDefSP)
    ;

    class_< AxCodecDef, bases< AxDefObject > , boost::noncopyable >("AxCodecDef", init< IAAFCodecDefSP >())
        .def("Initialize", &AxCodecDef::Initialize)
        .def("SetFileDescriptorClass", &AxCodecDef::SetFileDescriptorClass)
        .def("AddEssenceKind", &AxCodecDef::AddEssenceKind)
        .def("IsEssenceKindSupported", &AxCodecDef::IsEssenceKindSupported)
        .def("CountEssenceKinds", &AxCodecDef::CountEssenceKinds)
        .def("GetEssenceKinds", &AxCodecDef::GetEssenceKinds)
        .def("AreThereFlavours", &AxCodecDef::AreThereFlavours)
        .def("EnumCodecFlavours", &AxCodecDef::EnumCodecFlavours)
        .def("to_IAAFCodecDefSP", &AxCodecDef::operator IAAFCodecDefSP)
    ;

    class_< AxDataDef, bases< AxDefObject > , boost::noncopyable >("AxDataDef", init< IAAFDataDefSP >())
        .def(init< IAAFDataDef2SP >())
        .def(init< IAAFDataDef3SP >())
        .def("Initialize", &AxDataDef::Initialize)
        .def("IsSoundKind", &AxDataDef::IsSoundKind)
        .def("IsPictureKind", &AxDataDef::IsPictureKind)
        .def("IsMatteKind", &AxDataDef::IsMatteKind)
        .def("IsPictureWithMatteKind", &AxDataDef::IsPictureWithMatteKind)
        .def("IsEdgecodeKind", &AxDataDef::IsEdgecodeKind)
        .def("IsTimecodeKind", &AxDataDef::IsTimecodeKind)
        .def("IsAuxiliaryKind", &AxDataDef::IsAuxiliaryKind)
        .def("IsDescriptiveMetadataKind", &AxDataDef::IsDescriptiveMetadataKind)
        .def("DoesDataDefConvertTo", &AxDataDef::DoesDataDefConvertTo)
        .def("IsDataDefOf", &AxDataDef::IsDataDefOf)
        .def("DoesDataDefConvertFrom", &AxDataDef::DoesDataDefConvertFrom)
        .def("to_IAAFDataDefSP", &AxDataDef::operator IAAFDataDefSP)
        .def("to_IAAFDataDef2SP", &AxDataDef::operator IAAFDataDef2SP)
        .def("to_IAAFDataDef3SP", &AxDataDef::operator IAAFDataDef3SP)
    ;

    class_< AxOperationDef, bases< AxDefObject > , boost::noncopyable >("AxOperationDef", init< IAAFOperationDefSP >())
        .def("Initialize", &AxOperationDef::Initialize)
        .def("SetDataDef", &AxOperationDef::SetDataDef)
        .def("SetIsTimeWarp", &AxOperationDef::SetIsTimeWarp)
        .def("SetCategory", &AxOperationDef::SetCategory)
        .def("SetNumberInputs", &AxOperationDef::SetNumberInputs)
        .def("SetBypass", &AxOperationDef::SetBypass)
        .def("GetDataDef", &AxOperationDef::GetDataDef)
        .def("IsTimeWarp", &AxOperationDef::IsTimeWarp)
        .def("GetCategory", &AxOperationDef::GetCategory)
        .def("GetNumberInputs", &AxOperationDef::GetNumberInputs)
        .def("GetBypass", &AxOperationDef::GetBypass)
        .def("to_IAAFOperationDefSP", &AxOperationDef::operator IAAFOperationDefSP)
    ;

    class_< AxKLVDataDef, bases< AxDefObject > , boost::noncopyable >("AxKLVDataDef", init< IAAFKLVDataDefinitionSP >())
        .def("Initialize", &AxKLVDataDef::Initialize)
        .def("AddParentProperty", &AxKLVDataDef::AddParentProperty)
        .def("RemoveParentProperty", &AxKLVDataDef::RemoveParentProperty)
        .def("SetKLVDataType", &AxKLVDataDef::SetKLVDataType)
        .def("GetParentProperties", &AxKLVDataDef::GetParentProperties)
        .def("CountParentProperties", &AxKLVDataDef::CountParentProperties)
        .def("GetKLVDataType", &AxKLVDataDef::GetKLVDataType)
        .def("to_IAAFKLVDataDefinitionSP", &AxKLVDataDef::operator IAAFKLVDataDefinitionSP)
    ;

    class_< AxTaggedValueDef, bases< AxDefObject > , boost::noncopyable >("AxTaggedValueDef", init< IAAFTaggedValueDefinitionSP >())
        .def("Initialize", &AxTaggedValueDef::Initialize)
        .def("AddParentProperty", &AxTaggedValueDef::AddParentProperty)
        .def("RemoveParentProperty", &AxTaggedValueDef::RemoveParentProperty)
        .def("GetParentProperties", &AxTaggedValueDef::GetParentProperties)
        .def("CountParentProperties", &AxTaggedValueDef::CountParentProperties)
        .def("to_IAAFTaggedValueDefinitionSP", &AxTaggedValueDef::operator IAAFTaggedValueDefinitionSP)
    ;

}

