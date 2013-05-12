
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxMob.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxMob()
{


    class_< AxMob, boost::noncopyable >("AxMob", init<IAAFMobSP  >())
        .def(init< IAAFMob2SP >())
        .def("GetMobID", &AxMob::GetMobID)
        .def("SetMobID", &AxMob::SetMobID)
        .def("GetName", (AxString (AxMob::*)() )&AxMob::GetName)
        .def("GetName", (AxString (AxMob::*)(const AxString&) )&AxMob::GetName)
        .def("SetName", &AxMob::SetName)
        .def("CountSlots", &AxMob::CountSlots)
        .def("AppendSlot", &AxMob::AppendSlot)
        .def("LookupSlot", &AxMob::LookupSlot)
        .def("Copy", &AxMob::Copy)
        .def("CloneExternal", &AxMob::CloneExternal)
        .def("AppendComment", &AxMob::AppendComment)
        .def("AppendKLVData", &AxMob::AppendKLVData)
        .def("AppendNewTimelineSlot", &AxMob::AppendNewTimelineSlot)
        .def("GetSlots", &AxMob::GetSlots)
        .def("SetUsageCode", &AxMob::SetUsageCode)
        .def("GetUsageCode", (aafUID_t (AxMob::*)() )&AxMob::GetUsageCode)
        .def("GetUsageCode", (aafUID_t (AxMob::*)(const aafUID_t&) )&AxMob::GetUsageCode)
        .def("ExistsUsageCode", &AxMob::ExistsUsageCode)
        .def("GetClassName", &AxMob::GetClassName)
        .def("GetDictionary", &AxMob::GetDictionary)
        .def("GetProperties", &AxMob::GetProperties)
        .def("GetDefinition", &AxMob::GetDefinition)
        .def("to_IAAFMobSP", &AxMob::operator IAAFMobSP)
        .def("to_IAAFMob2SP", &AxMob::operator IAAFMob2SP)
    ;

    class_< AxMasterMob, bases< AxMob > , boost::noncopyable >("AxMasterMob", init< IAAFMasterMobSP >())
        .def(init< IAAFMasterMob2SP >())
        .def("Initialize", &AxMasterMob::Initialize)
        .def("CreateEssence", &AxMasterMob::CreateEssence)
        .def("OpenEssence", &AxMasterMob::OpenEssence)
        .def("AddMasterSlot", &AxMasterMob::AddMasterSlot)
        .def("SearchSource", &AxSearchSource::SearchSource)
        .def("to_IAAFMasterMobSP", &AxMasterMob::operator IAAFMasterMobSP)
        .def("to_IAAFMasterMob2SP", &AxMasterMob::operator IAAFMasterMob2SP)
    ;

    class_< AxMasterMobEx, bases< AxMasterMob > , boost::noncopyable >("AxMasterMobEx", init< IAAFMasterMobExSP >())
        .def("ExtendEssence", &AxMasterMobEx::ExtendEssence)
        .def("to_IAAFMasterMobExSP", &AxMasterMobEx::operator IAAFMasterMobExSP)
    ;

    class_< AxCompositionMob, bases< AxMob > , boost::noncopyable >("AxCompositionMob", init< IAAFCompositionMobSP >())
        .def(init< IAAFCompositionMob2SP >())
        .def("Initialize", &AxCompositionMob::Initialize)
        .def("to_IAAFCompositionMobSP", &AxCompositionMob::operator IAAFCompositionMobSP)
        .def("to_IAAFCompositionMob2SP", &AxCompositionMob::operator IAAFCompositionMob2SP)
    ;

    class_< AxSourceMob, bases< AxMob > , boost::noncopyable >("AxSourceMob", init< IAAFSourceMobSP >())
        .def("Initialize", &AxSourceMob::Initialize)
        .def("SetEssenceDescriptor", &AxSourceMob::SetEssenceDescriptor)
        .def("GetEssenceDescriptor", &AxSourceMob::GetEssenceDescriptor)
        .def("AddNilReference", &AxSourceMob::AddNilReference)
        .def("SearchSource", &AxSearchSource::SearchSource)
        .def("to_IAAFSourceMobSP", &AxSourceMob::operator IAAFSourceMobSP)
    ;



}

