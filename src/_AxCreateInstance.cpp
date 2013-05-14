
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxComponent.h>
#include <AxDictionary.h>
#include <AxMob.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

template <class Type, class AxType>

struct AxCreateInstanceWrapper
{
    
    static AxType* create_instance(AxDictionary& dict)
    {
        
        AxType* result;
        result = new AxType(AxCreateInstance<Type>(dict));
        
        return result;
        
    }
    
    static void wrap(const char* python_name)
    {
        
        def(python_name, create_instance,return_value_policy<manage_new_object>());
        
    }
};




// Module ======================================================================
void Export_pyste_src_AxCreateInstance()
{

    
    AxCreateInstanceWrapper<IAAFCompositionMob, AxCompositionMob >().wrap("createAxCompositionMob");
    AxCreateInstanceWrapper<IAAFSequence, AxSequence >().wrap("createAxSequence");

}

