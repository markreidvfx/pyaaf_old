
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxComponent.h>
#include <AxDefObject.h>
#include <AxHeader.h>
#include <AxMob.h>
#include <AxSmartPointer.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_implicitly_convertible()
{

    
    //Components
    implicitly_convertible<AxSequence,IAAFSmartPointer<IAAFSegment> > ();
    
    //Mobs
    implicitly_convertible<AxMob,IAAFSmartPointer<IAAFMob> > ();
    implicitly_convertible<AxMasterMob,IAAFSmartPointer<IAAFMob> > ();
    implicitly_convertible<AxMasterMob,IAAFSmartPointer<IAAFMasterMob> > ();
    
    //AxDefObject
    
    implicitly_convertible<AxDataDef,IAAFDataDefSP > ();
    implicitly_convertible<AxOperationDef,IAAFOperationDefSP > ();
    implicitly_convertible<AxOperationGroup,IAAFOperationGroupSP > ();


}

