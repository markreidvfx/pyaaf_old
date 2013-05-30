
#include <AxSmartPointer.h>


template <class TypeSrc, class TypeDst>

IAAFSmartPointer<TypeDst> query_interface( IAAFSmartPointer<TypeSrc> spSrc)
    {
        return AxQueryInterface<TypeSrc,TypeDst>( spSrc );
    };
    
template <typename Type, typename AxType>

AxString PyGetClassName(IAAFSmartPointer< Type >& sp)
{
    
    AxType item(sp);
    
    
    return item.GetClassName();
    
};