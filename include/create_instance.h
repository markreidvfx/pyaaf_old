
#include <AxDictionary.h>
#include <AxDefObject.h>


template <class Type, class AxType>

AxType* create_instance(AxDictionary& dict)
{
    return new AxType(AxCreateInstance<Type>(dict));
    
};