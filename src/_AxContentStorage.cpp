
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFClassDefUIDs.h>
#include <AAFExtEnum.h>
#include <AxContentStorage.h>
#include <AxIterator.h>
#include <AxSmartPointer.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================


IEnumAAFMobsSP PyGetAllMobs(AxContentStorage& storage)
    {
        
        aafSearchCrit_t criteria;
        criteria.searchTag = kAAFByMobKind;
        criteria.tags.mobKind = kAAFAllMob;
        return storage.GetMobs( &criteria );
    }
    
IEnumAAFMobsSP PyGetMasterMobs(AxContentStorage& storage)
    {
        
        aafSearchCrit_t criteria;
        criteria.searchTag = kAAFByMobKind;
        criteria.tags.mobKind = kAAFMasterMob;
        return storage.GetMobs( &criteria );
    }
    
IEnumAAFMobsSP PyGetCompositionMobs(AxContentStorage& storage)
    {
        
        aafSearchCrit_t criteria;
        criteria.searchTag = kAAFByMobKind;
        criteria.tags.mobKind = kAAFCompMob;
        return storage.GetMobs( &criteria );

    }
    
IEnumAAFMobsSP PyGetSourceMobs(AxContentStorage& storage)
{
    
    aafSearchCrit_t criteria;
    criteria.searchTag = kAAFByClass;
    criteria.tags.objClass = kAAFClassID_SourceMob;
    return storage.GetMobs( &criteria );
    
}

IEnumAAFMobsSP PyGetTopLevelMobs(AxContentStorage& storage)
{
    
    aafSearchCrit_t criteria;
    criteria.searchTag = kAAFByCompositionMobUsageCode;
    criteria.tags.usageCode = kAAFUsage_TopLevel;
    return storage.GetMobs( &criteria );
    
}




// Module ======================================================================
void Export_pyste_src_AxContentStorage()
{


    class_< AxContentStorage, boost::noncopyable >("AxContentStorage", init< IAAFContentStorageSP >())
        .def("LookupMob", &AxContentStorage::LookupMob)
        .def("LookupEssenceData", &AxContentStorage::LookupEssenceData)
        .def("CountEssenceData", &AxContentStorage::CountEssenceData)
        .def("IsEssenceDataPresent", &AxContentStorage::IsEssenceDataPresent)
        .def("GetMobs",PyGetAllMobs)
        .def("EnumEssenceData", &AxContentStorage::EnumEssenceData)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("GetMasterMobs",PyGetMasterMobs)
        .def("GetCompositionMobs",PyGetCompositionMobs)
        .def("GetSourceMobs",PyGetSourceMobs)
        .def("GetTopLevelMobs",PyGetTopLevelMobs)
    ;


}

