
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
    AxQueryInterfaceWrapper<IAAFMob,IAAFMasterMob>().wrap("_MobSP_to_MasterMobSP");
    AxQueryInterfaceWrapper<IAAFMob,IAAFMasterMobEx>().wrap("_MobSP_to_MasterMobExSP");
    AxQueryInterfaceWrapper<IAAFMob,IAAFCompositionMob>().wrap("_MobSP_to_CompositionMobSP");
    AxQueryInterfaceWrapper<IAAFMob,IAAFSourceMob>().wrap("_MobSP_to_SourceMobSP");
    
    //MobSlots
    AxQueryInterfaceWrapper<IAAFMobSlot,IAAFTimelineMobSlot>().wrap("_MobSlotSP_to_TimelineMobSlotSP");
    AxQueryInterfaceWrapper<IAAFSegment,IAAFSourceClip>().wrap("_SegmentSP_to_SourceClipSP");
    
    //Essence's
    AxQueryInterfaceWrapper<IAAFEssenceDescriptor,IAAFWAVEDescriptor>().wrap("_EssenceDescriptorSP_to_WAVEDescriptorSP");
    

}

