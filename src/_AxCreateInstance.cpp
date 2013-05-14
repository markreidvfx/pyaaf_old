
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxDictionary.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

template <class Type>

struct AxCreateInstanceWrapper
{
    
    static IAAFSmartPointer<Type> create_instance(AxDictionary& dict)
    {
        
        return AxCreateInstance<Type>(dict);
        
    }
    
    static void wrap(const char* python_name)
    {
        
        def(python_name, create_instance);
        
    }
};



// Module ======================================================================
void Export_pyste_src_AxCreateInstance()
{


    AxCreateInstanceWrapper<IAAFCompositionMob>().wrap("createCompositionMobSP");

}

