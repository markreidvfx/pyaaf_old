
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFCompressionDefs.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class CompressionDef {};


// Module ======================================================================
void Export_pyste_src_AAFCompressionDefs()
{

    scope CompressionDef_scope = class_<CompressionDef>("CompressionDef");
    CompressionDef_scope.attr("LegacyDV") = kAAFCompressionDef_LegacyDV;
    CompressionDef_scope.attr("SMPTE_D10_30Mbps_625x50I") = kAAFCompressionDef_SMPTE_D10_30Mbps_625x50I;
    CompressionDef_scope.attr("SMPTE_D10_50Mbps_525x5994I") = kAAFCompressionDef_SMPTE_D10_50Mbps_525x5994I;
    CompressionDef_scope.attr("SMPTE_D10_30Mbps_525x5994I") = kAAFCompressionDef_SMPTE_D10_30Mbps_525x5994I;
    CompressionDef_scope.attr("DV_Based_100Mbps_720x5994P") = kAAFCompressionDef_DV_Based_100Mbps_720x5994P;
    CompressionDef_scope.attr("DV_Based_25Mbps_525_60") = kAAFCompressionDef_DV_Based_25Mbps_525_60;
    CompressionDef_scope.attr("SMPTE_D10_40Mbps_525x5994I") = kAAFCompressionDef_SMPTE_D10_40Mbps_525x5994I;
    CompressionDef_scope.attr("DV_Based_100Mbps_720x50P") = kAAFCompressionDef_DV_Based_100Mbps_720x50P;
    CompressionDef_scope.attr("IEC_DV_525_60") = kAAFCompressionDef_IEC_DV_525_60;
    CompressionDef_scope.attr("DV_Based_50Mbps_625_50") = kAAFCompressionDef_DV_Based_50Mbps_625_50;
    CompressionDef_scope.attr("AAF_CMPR_FULL_JPEG") = AAF_CMPR_FULL_JPEG;
    CompressionDef_scope.attr("DV_Based_50Mbps_525_60") = kAAFCompressionDef_DV_Based_50Mbps_525_60;
    CompressionDef_scope.attr("AAF_CMPR_FULL_JPEG") = kAAFCompressionDef_AAF_CMPR_FULL_JPEG;
    CompressionDef_scope.attr("DV_Based_100Mbps_1080x5994I") = kAAFCompressionDef_DV_Based_100Mbps_1080x5994I;
    CompressionDef_scope.attr("SMPTE_D10_50Mbps_625x50I") = kAAFCompressionDef_SMPTE_D10_50Mbps_625x50I;
    CompressionDef_scope.attr("IEC_DV_625_50") = kAAFCompressionDef_IEC_DV_625_50;
    CompressionDef_scope.attr("AAF_CMPR_AUNC422") = AAF_CMPR_AUNC422;
    CompressionDef_scope.attr("VC3_1") = kAAFCompressionDef_VC3_1;
    CompressionDef_scope.attr("DV_Based_100Mbps_1080x50I") = kAAFCompressionDef_DV_Based_100Mbps_1080x50I;
    CompressionDef_scope.attr("SMPTE_D10_40Mbps_625x50I") = kAAFCompressionDef_SMPTE_D10_40Mbps_625x50I;
    CompressionDef_scope.attr("DV_Based_25Mbps_625_50") = kAAFCompressionDef_DV_Based_25Mbps_625_50;
    CompressionDef_scope.attr("Avid_DNxHD_Legacy") = kAAFCompressionDef_Avid_DNxHD_Legacy;
    CompressionDef_scope.attr("AAF_CMPR_AUNC422") = kAAFCompressionDef_AAF_CMPR_AUNC422;
    }

