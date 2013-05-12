
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxHeader.h>
#include <AxSmartPointer.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxHeader()
{
    class_< AxHeader >("AxHeader", init< IAAFHeaderSP >())
        .def(init< IAAFHeader2SP >())
        .def(init< const AxHeader& >())
        .def("GetDictionary", (IAAFDictionarySP (AxHeader::*)() const)&AxHeader::GetDictionary)
        .def("GetContentStorage", &AxHeader::GetContentStorage)
        .def("CountMobs", (aafUInt32 (AxHeader::*)() const)&AxHeader::CountMobs)
        .def("CountMobs", (aafUInt32 (AxHeader::*)(aafMobKind_e) const)&AxHeader::CountMobs)
        .def("GetMobs", (IEnumAAFMobsSP (AxHeader::*)() const)&AxHeader::GetMobs)
        .def("GetMobs", (IEnumAAFMobsSP (AxHeader::*)(aafSearchCrit_t&) const)&AxHeader::GetMobs)
        .def("LookupMob", &AxHeader::LookupMob)
        .def("LookupEssenceData", &AxHeader::LookupEssenceData)
        .def("CountEssenceData", &AxHeader::CountEssenceData)
        .def("IsEssenceDataPresent", &AxHeader::IsEssenceDataPresent)
        .def("CountIdentifications", &AxHeader::CountIdentifications)
        .def("GetIdentificationAt", &AxHeader::GetIdentificationAt)
        .def("CountEssence", &AxHeader::CountEssence)
        .def("AddMob", &AxHeader::AddMob)
        .def("RemoveMob", &AxHeader::RemoveMob)
        .def("EnumEssenceData", &AxHeader::EnumEssenceData)
        .def("AddEssenceData", &AxHeader::AddEssenceData)
        .def("RemoveEssenceData", &AxHeader::RemoveEssenceData)
        .def("GetLastIdentification", &AxHeader::GetLastIdentification)
        .def("LookupIdentification", &AxHeader::LookupIdentification)
        .def("GetIdentifications", &AxHeader::GetIdentifications)
        .def("AppendIdentification", &AxHeader::AppendIdentification)
        .def("GetRefImplVersion", &AxHeader::GetRefImplVersion)
        .def("GetFileRevision", &AxHeader::GetFileRevision)
        .def("GetLastModified", &AxHeader::GetLastModified)
        .def("GetPrimaryMob", &AxHeader::GetPrimaryMob)
        .def("SetPrimaryMob", &AxHeader::SetPrimaryMob)
        .def("GetOperationalPattern", &AxHeader::GetOperationalPattern)
        .def("SetOperationalPattern", &AxHeader::SetOperationalPattern)
        .def("UpdateEssenceContainers", &AxHeader::UpdateEssenceContainers)
        .def("GetEssenceContainers", &AxHeader::GetEssenceContainers)
        .def("IsEssenceContainerPresent", &AxHeader::IsEssenceContainerPresent)
        .def("GetDescriptiveSchemes", &AxHeader::GetDescriptiveSchemes)
        .def("IsDescriptiveSchemePresent", &AxHeader::IsDescriptiveSchemePresent)
        .def("AddDescriptiveScheme", &AxHeader::AddDescriptiveScheme)
        .def("RemoveDescriptiveScheme", &AxHeader::RemoveDescriptiveScheme)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", (IAAFDictionarySP (AxObject::*)() )&AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFHeaderSP", &AxHeader::operator IAAFHeaderSP)
        .def("to_IAAFHeader2SP", &AxHeader::operator IAAFHeader2SP)
    ;



//class_<IAAFSmartPointer<IAAFHeader> >("IAAFHeader");

}

