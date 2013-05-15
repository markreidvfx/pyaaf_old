
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxMetaDef.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

struct AxTypeDef_Wrapper: AxTypeDef
{
    AxTypeDef_Wrapper(PyObject* py_self_, IAAFTypeDefSP p0):
        AxTypeDef(p0), py_self(py_self_) {}

    eAAFTypeCategory_t GetTypeCategory() {
        return call_method< eAAFTypeCategory_t >(py_self, "GetTypeCategory");
    }

    eAAFTypeCategory_t default_GetTypeCategory() {
        return AxTypeDef::GetTypeCategory();
    }

    PyObject* py_self;
};


}// namespace 


// Module ======================================================================
void Export_pyste_src_AxMetaDef()
{
    class_< AxMetaDefinition, boost::noncopyable >("AxMetaDefinition", init< IAAFMetaDefinitionSP >())
        .def("GetAUID", &AxMetaDefinition::GetAUID)
        .def("GetName", &AxMetaDefinition::GetName)
        .def("GetDescription", &AxMetaDefinition::GetDescription)
    ;

    class_< AxClassDef, bases< AxMetaDefinition > , boost::noncopyable >("AxClassDef", init< IAAFClassDefSP >())
        .def("GetParent", &AxClassDef::GetParent)
        .def("IsConcrete", &AxClassDef::IsConcrete)
        .def("GetPropertyDefs", &AxClassDef::GetPropertyDefs)
        .def("LookupPropertyDef", &AxClassDef::LookupPropertyDef)
        .def("to_IAAFClassDefSP", &AxClassDef::operator IAAFClassDefSP)
    ;

    class_< AxPropertyDef, bases< AxMetaDefinition > , boost::noncopyable >("AxPropertyDef", init< IAAFPropertyDefSP >())
        .def("GetIsOptional", &AxPropertyDef::GetIsOptional)
        .def("GetIsUniqueIdentifier", &AxPropertyDef::GetIsUniqueIdentifier)
        .def("GetTypeDef", &AxPropertyDef::GetTypeDef)
        .def("to_IAAFPropertyDefSP", &AxPropertyDef::operator IAAFPropertyDefSP)
    ;

    class_< AxTypeDef, bases< AxMetaDefinition > , boost::noncopyable, AxTypeDef_Wrapper >("AxTypeDef", init< IAAFTypeDefSP >())
        .def("GetTypeCategory", &AxTypeDef::GetTypeCategory, &AxTypeDef_Wrapper::default_GetTypeCategory)
        .def("GetTypeDefSP", &AxTypeDef::GetTypeDefSP)
        .def("to_IAAFTypeDefSP", &AxTypeDef::operator IAAFTypeDefSP)
    ;

    class_< AxTypeDefIndirect, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefIndirect", init< IAAFTypeDefIndirectSP >())
        .def("GetActualType", &AxTypeDefIndirect::GetActualType)
        .def("GetActualValue", &AxTypeDefIndirect::GetActualValue)
    ;

    class_< AxTypeDefOpaque, bases< AxTypeDefIndirect > , boost::noncopyable >("AxTypeDefOpaque", init< IAAFTypeDefOpaqueSP >())
        .def("GetActualTypeID", &AxTypeDefOpaque::GetActualTypeID)
        .def("GetHandleBufLen", &AxTypeDefOpaque::GetHandleBufLen)
    ;

    class_< AxTypeDefRename, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefRename", init< IAAFTypeDefRenameSP >())
        .def("Initialize", &AxTypeDefRename::Initialize)
        .def("GetBaseType", &AxTypeDefRename::GetBaseType)
        .def("GetBaseValue", &AxTypeDefRename::GetBaseValue)
        .def("to_IAAFTypeDefRenameSP", &AxTypeDefRename::operator IAAFTypeDefRenameSP)
    ;

    class_< AxTypeDefInt, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefInt", init< IAAFTypeDefIntSP >())
        .def("GetSize", &AxTypeDefInt::GetSize)
        .def("IsSigned", &AxTypeDefInt::IsSigned)
        .def("CreateValue", &AxTypeDefInt::CreateValue)
    ;

    class_< AxTypeDefFixedArray, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefFixedArray", init< IAAFTypeDefFixedArraySP >())
        .def("GetType", &AxTypeDefFixedArray::GetType)
        .def("GetCount", &AxTypeDefFixedArray::GetCount)
        .def("GetElements", &AxTypeDefFixedArray::GetElements)
        .def("GetElementValue", &AxTypeDefFixedArray::GetElementValue)
    ;

    class_< AxTypeDefRecord, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefRecord", init< IAAFTypeDefRecordSP >())
        .def("GetCount", &AxTypeDefRecord::GetCount)
        .def("GetMemberType", &AxTypeDefRecord::GetMemberType)
        .def("GetMemberName", &AxTypeDefRecord::GetMemberName)
        .def("GetValue", &AxTypeDefRecord::GetValue)
    ;

    class_< AxTypeDefStream, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefStream", init< IAAFTypeDefStreamSP >())
        .def("GetSize", &AxTypeDefStream::GetSize)
    ;

    class_< AxTypeDefString, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefString", init< IAAFTypeDefStringSP >())
        .def("GetElements", &AxTypeDefString::GetElements)
    ;

    class_< AxTypeDefSet, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefSet", init< IAAFTypeDefSetSP >())
        .def("GetElementType", &AxTypeDefSet::GetElementType)
        .def("GetType", &AxTypeDefSet::GetType)
        .def("GetElements", &AxTypeDefSet::GetElements)
    ;

    class_< AxTypeDefObjRef, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefObjRef", init< IAAFTypeDefObjectRefSP >())
        .def("GetObjectType", &AxTypeDefObjRef::GetObjectType)
    ;

    class_< AxTypeDefWeakObjRef, bases< AxTypeDefObjRef > , boost::noncopyable >("AxTypeDefWeakObjRef", init< IAAFTypeDefWeakObjRefSP >())
    ;

    class_< AxTypeDefStrongObjRef, bases< AxTypeDefObjRef > , boost::noncopyable >("AxTypeDefStrongObjRef", init< IAAFTypeDefStrongObjRefSP >())
    ;

    class_< AxTypeDefVariableArrayEx, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefVariableArrayEx", init< IAAFTypeDefVariableArrayExSP >())
    ;

    class_< AxTypeDefVariableArray, bases< AxTypeDefVariableArrayEx > , boost::noncopyable >("AxTypeDefVariableArray", init< IAAFTypeDefVariableArraySP >())
        .def("GetType", &AxTypeDefVariableArray::GetType)
        .def("GetCount", &AxTypeDefVariableArray::GetCount)
        .def("GetElements", &AxTypeDefVariableArray::GetElements)
    ;

    class_< AxTypeDefEnum, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefEnum", init< IAAFTypeDefEnumSP >())
        .def("GetElementType", &AxTypeDefEnum::GetElementType)
        .def("CountElements", &AxTypeDefEnum::CountElements)
        .def("GetElementName", &AxTypeDefEnum::GetElementName)
        .def("GetElementValue", &AxTypeDefEnum::GetElementValue)
        .def("GetNameFromValue", &AxTypeDefEnum::GetNameFromValue)
        .def("GetIntegerValue", &AxTypeDefEnum::GetIntegerValue)
    ;

    class_< AxTypeDefExtEnum, bases< AxTypeDef > , boost::noncopyable >("AxTypeDefExtEnum", init< IAAFTypeDefExtEnumSP >())
        .def("CountElements", &AxTypeDefExtEnum::CountElements)
        .def("GetElementName", &AxTypeDefExtEnum::GetElementName)
        .def("GetElementValue", &AxTypeDefExtEnum::GetElementValue)
        .def("GetNameFromValue", &AxTypeDefExtEnum::GetNameFromValue)
    ;

}

