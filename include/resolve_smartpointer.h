#include <boost/python.hpp>
#include <boost/cstdint.hpp>

#include <AxEx.h>
#include <AxSmartPointer.h>
#include <AxMetaDef.h>
#include <AxObject.h>

#include <AAFTypeDefUIDs.h>
#include <utilities.h>

boost::python::object resolve_smartpointer(IUnknownSP sp);

template <class T>
boost::python::object resolve_any_smartpointer(IAAFSmartPointer< T >& sp)
{
    
    IUnknownSP spUnkown = AxQueryInterface<T,IUnknown>(sp);
    return resolve_smartpointer(spUnkown);
    
    
};
