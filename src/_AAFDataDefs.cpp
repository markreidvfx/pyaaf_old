
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFDataDefs.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class DataDef {};


// Module ======================================================================
void Export_pyste_src_AAFDataDefs()
{

    scope DataDef_scope = class_<DataDef>("DataDef");
    DataDef_scope.attr("Picture") = kAAFDataDef_Picture;
    DataDef_scope.attr("LegacyPicture") = kAAFDataDef_LegacyPicture;
    DataDef_scope.attr("Matte") = kAAFDataDef_Matte;
    DataDef_scope.attr("PictureWithMatte") = kAAFDataDef_PictureWithMatte;
    DataDef_scope.attr("Sound") = kAAFDataDef_Sound;
    DataDef_scope.attr("LegacySound") = kAAFDataDef_LegacySound;
    DataDef_scope.attr("Timecode") = kAAFDataDef_Timecode;
    DataDef_scope.attr("LegacyTimecode") = kAAFDataDef_LegacyTimecode;
    DataDef_scope.attr("Edgecode") = kAAFDataDef_Edgecode;
    DataDef_scope.attr("DescriptiveMetadata") = kAAFDataDef_DescriptiveMetadata;
    DataDef_scope.attr("Auxiliary") = kAAFDataDef_Auxiliary;
    DataDef_scope.attr("Unknown") = kAAFDataDef_Unknown;
}

