
#include <AxSmartPointer.h>
#include <AxTypes.h>


template <class TypeSrc, class TypeDst>

IAAFSmartPointer<TypeDst> query_interface( IAAFSmartPointer<TypeSrc> spSrc)
    {
        return AxQueryInterface<TypeSrc,TypeDst>( spSrc );
    };

template <class TypeSrc>

TypeSrc query_interface_pass_through( TypeSrc spSrc)
{
    return spSrc;
};

template <typename Type, typename AxType>

AxString PyGetClassName(IAAFSmartPointer< Type >& sp)
{
    
    AxType item(sp);
    
    
    return item.GetClassName();
    
};

template <typename Type, char const * name>
char const * PyGetClassName_from_string(Type spSrc)
{
    
    return name;
    
};