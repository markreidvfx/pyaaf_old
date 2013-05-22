
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxContentStorage.h>
#include <AxIterator.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================


AxMobIter PyGetAllMobs(AxContentStorage* storage)
    {
        
        aafSearchCrit_t criteria;
        criteria.searchTag = kAAFByMobKind;
        criteria.tags.mobKind = kAAFAllMob;
        AxMobIter axMobIter( storage->GetMobs( &criteria ) );
        return axMobIter;
    }
    
AxMobIter PyGetMasterMobs(AxContentStorage* storage)
    {
        
        aafSearchCrit_t criteria;
        criteria.searchTag = kAAFByMobKind;
        criteria.tags.mobKind = kAAFMasterMob;
        AxMobIter axMobIter( storage->GetMobs( &criteria ) );
        return axMobIter;
    }
    
AxMobIter PyGetCompositionMobs(AxContentStorage* storage)
    {
        
        aafSearchCrit_t criteria;
        criteria.searchTag = kAAFByMobKind;
        criteria.tags.mobKind = kAAFCompMob;
        AxMobIter axMobIter( storage->GetMobs( &criteria ) );
        return axMobIter;
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
    ;


}

