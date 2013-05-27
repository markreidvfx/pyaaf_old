
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFOPDefs.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class OPDef {};


// Module ======================================================================
void Export_pyste_src_AAFOPDefs()
{

    scope OPDef_scope = class_<OPDef>("OPDef");
    OPDef_scope.attr("Unconstrained") = kAAFOPDef_Unconstrained;
    OPDef_scope.attr("EditProtocol") = kAAFOPDef_EditProtocol;
}

