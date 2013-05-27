
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFInterpolatorDefs.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class InterpolationDef {};


// Module ======================================================================
void Export_pyste_src_AAFInterpolatorDefs()
{

    scope InterpolationDef_scope = class_<InterpolationDef>("InterpolationDef");
    InterpolationDef_scope.attr("Constant") = kAAFInterpolationDef_Constant;
    InterpolationDef_scope.attr("Power") = kAAFInterpolationDef_Power;
    InterpolationDef_scope.attr("ConstantInterpolator") = ConstantInterpolator;
    InterpolationDef_scope.attr("Linear") = kAAFInterpolationDef_Linear;
    InterpolationDef_scope.attr("PowerInterpolator") = PowerInterpolator;
    InterpolationDef_scope.attr("NoInterpolator") = NoInterpolator;
    InterpolationDef_scope.attr("LinearInterpolator") = LinearInterpolator;
    InterpolationDef_scope.attr("None_") = kAAFInterpolationDef_None;
    InterpolationDef_scope.attr("BSplineInterpolator") = BSplineInterpolator;
    InterpolationDef_scope.attr("LogInterpolator") = LogInterpolator;
    InterpolationDef_scope.attr("BSpline") = kAAFInterpolationDef_BSpline;
    InterpolationDef_scope.attr("Log") = kAAFInterpolationDef_Log;
}

