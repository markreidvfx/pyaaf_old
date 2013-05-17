
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxSmartPointer.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================


template <class TypeSrc, class TypeDst>
struct AxQueryInterfaceWrapper
{
    
    static IAAFSmartPointer<TypeDst> query_interface( IAAFSmartPointer<TypeSrc> spSrc)
    {
        
        return AxQueryInterface<TypeSrc,TypeDst>( spSrc );
    }
    
    static void wrap(const char* python_name)
    {
        
        def(python_name, query_interface);
        
    }
    
};



// Module ======================================================================
void Export_pyste_src_AxQueryInterface()
{

    //Mobs
    AxQueryInterfaceWrapper<IAAFMob,IAAFMasterMob>().wrap("_MobSPtoMasterMobSP");
    AxQueryInterfaceWrapper<IAAFMob,IAAFMasterMobEx>().wrap("_MobSPtoMasterMobExSP");
    AxQueryInterfaceWrapper<IAAFMob,IAAFCompositionMob>().wrap("_MobSPtoCompositionMobSP");
    AxQueryInterfaceWrapper<IAAFMob,IAAFSourceMob>().wrap("_MobSPtoSourceMobSP");
    
    //MobSlots
    AxQueryInterfaceWrapper<IAAFMobSlot,IAAFTimelineMobSlot>().wrap("_MobSlotSPtoTimelineMobSlotSP");


}

