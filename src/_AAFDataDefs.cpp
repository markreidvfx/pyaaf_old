
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFDataDefs.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AAFDataDefs()
{
    scope().attr("kAAFDataDef_Picture") = kAAFDataDef_Picture;
    scope().attr("kAAFDataDef_LegacyPicture") = kAAFDataDef_LegacyPicture;
    scope().attr("kAAFDataDef_Matte") = kAAFDataDef_Matte;
    scope().attr("kAAFDataDef_PictureWithMatte") = kAAFDataDef_PictureWithMatte;
    scope().attr("kAAFDataDef_Sound") = kAAFDataDef_Sound;
    scope().attr("kAAFDataDef_LegacySound") = kAAFDataDef_LegacySound;
    scope().attr("kAAFDataDef_Timecode") = kAAFDataDef_Timecode;
    scope().attr("kAAFDataDef_LegacyTimecode") = kAAFDataDef_LegacyTimecode;
    scope().attr("kAAFDataDef_Edgecode") = kAAFDataDef_Edgecode;
    scope().attr("kAAFDataDef_DescriptiveMetadata") = kAAFDataDef_DescriptiveMetadata;
    scope().attr("kAAFDataDef_Auxiliary") = kAAFDataDef_Auxiliary;
    scope().attr("kAAFDataDef_Unknown") = kAAFDataDef_Unknown;
}

