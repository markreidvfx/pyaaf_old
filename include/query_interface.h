
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

template <typename Type, typename AxType>
AxString PyGetTypeCategory(Type SP)
{
    
    AxType ax(SP);
    
    AxString s = AxTypeCatMap::getInstance().getStr( ax.GetTypeCategory() );
    
    s.replace(s.find(L"IAAF"), 4, L"");
    return s;
    
};

template <class TypeDst>
inline bool PyAxIsA( IUnknownSP sp )
{
    
    try
    {
        
        HRESULT hr;
        TypeDst* dummy = NULL;
        IAAFSmartPointer<TypeDst> spDst;
        
        hr = sp->QueryInterface( AxIID( dummy ),
                                reinterpret_cast<void**>(&spDst) );
        
        
        if ( SUCCEEDED(hr) ) {
            return true;
        }
        else if ( hr == E_NOINTERFACE ) {
            return false;
        }
        
        CHECK_HRESULT( hr );
    }
    catch( const AxExSmartPointer& ex ) {
        std::wcout << ex.what() << L"\n";
        return false;
    }
    
	
	// Never reached;
	return false;
}
