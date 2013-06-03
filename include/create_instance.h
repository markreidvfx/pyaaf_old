
#include <AxDictionary.h>
#include <AxDefObject.h>


template <typename Type, typename TypeSP, typename AxType>

TypeSP create_instance(AxDictionary& dict)
{
    return AxCreateInstance<Type>(dict);
    
};