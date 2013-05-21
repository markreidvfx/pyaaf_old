
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFCodecDefs.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class CodecDef {};


// Module ======================================================================
void Export_pyste_src_AAFCodecDefs()
{

    scope CodecDef_scope = class_<CodecDef>("CodecDef");
    CodecDef_scope.attr("NilCodecFlavour") = kAAFNilCodecFlavour;
    CodecDef_scope.attr("Flavour_None") = kAAFCodecFlavour_None;
    CodecDef_scope.attr("Def_None") = kAAFCodecDef_None;
    CodecDef_scope.attr("PCM") = kAAFCodecPCM;
    CodecDef_scope.attr("JPEG") = kAAFCodecJPEG;
    CodecDef_scope.attr("Flavour_SMPTE_D10_50Mbps_625x50I") = kAAFCodecFlavour_SMPTE_D10_50Mbps_625x50I;
    CodecDef_scope.attr("Def_CDCI") = kAAFCodecDef_CDCI;
    CodecDef_scope.attr("Def_JPEG") = kAAFCodecDef_JPEG;
    CodecDef_scope.attr("Def_RGBA") = kAAFCodecDef_RGBA;
    CodecDef_scope.attr("AIFC") = kAAFCODEC_AIFC;
    CodecDef_scope.attr("Flavour_DV_Based_25Mbps_525_60") = kAAFCodecFlavour_DV_Based_25Mbps_525_60;
    CodecDef_scope.attr("Def_VC3") = kAAFCodecDef_VC3;
    CodecDef_scope.attr("NoCodec") = kAAFNoCodec;
    CodecDef_scope.attr("RGBA") = kAAFCodecRGBA;
    CodecDef_scope.attr("Flavour_LegacyDV_525_60") = kAAFCodecFlavour_LegacyDV_525_60;
    CodecDef_scope.attr("DNxHD") = kAAFCodecDNxHD;
    CodecDef_scope.attr("Def_PCM") = kAAFCodecDef_PCM;
    CodecDef_scope.attr("Flavour_VC3_1251") = kAAFCodecFlavour_VC3_1251;
    CodecDef_scope.attr("Flavour_SMPTE_D10_40Mbps_525x5994I") = kAAFCodecFlavour_SMPTE_D10_40Mbps_525x5994I;
    CodecDef_scope.attr("Def_DNxHD") = kAAFCodecDef_DNxHD;
    CodecDef_scope.attr("Flavour_DV_Based_100Mbps_1080x50I") = kAAFCodecFlavour_DV_Based_100Mbps_1080x50I;
    CodecDef_scope.attr("Flavour_LegacyDV_625_50") = kAAFCodecFlavour_LegacyDV_625_50;
    CodecDef_scope.attr("Flavour_IEC_DV_625_50") = kAAFCodecFlavour_IEC_DV_625_50;
    CodecDef_scope.attr("Flavour_DV_Based_100Mbps_1080x5994I") = kAAFCodecFlavour_DV_Based_100Mbps_1080x5994I;
    CodecDef_scope.attr("Def_AIFC") = kAAFCodecDef_AIFC;
    CodecDef_scope.attr("Flavour_VC3_1244") = kAAFCodecFlavour_VC3_1244;
    CodecDef_scope.attr("Flavour_VC3_1241") = kAAFCodecFlavour_VC3_1241;
    CodecDef_scope.attr("Flavour_VC3_1242") = kAAFCodecFlavour_VC3_1242;
    CodecDef_scope.attr("Flavour_VC3_1243") = kAAFCodecFlavour_VC3_1243;
    CodecDef_scope.attr("Flavour_VC3_1237") = kAAFCodecFlavour_VC3_1237;
    CodecDef_scope.attr("Flavour_VC3_1238") = kAAFCodecFlavour_VC3_1238;
    CodecDef_scope.attr("VC3") = kAAFCodecVC3;
    CodecDef_scope.attr("Flavour_SMPTE_D10_30Mbps_625x50I") = kAAFCodecFlavour_SMPTE_D10_30Mbps_625x50I;
    CodecDef_scope.attr("Flavour_DV_Based_100Mbps_720x5994P") = kAAFCodecFlavour_DV_Based_100Mbps_720x5994P;
    CodecDef_scope.attr("Flavour_DV_Based_25Mbps_625_50") = kAAFCodecFlavour_DV_Based_25Mbps_625_50;
    CodecDef_scope.attr("Flavour_VC3_1235") = kAAFCodecFlavour_VC3_1235;
    CodecDef_scope.attr("Flavour_DV_Based_100Mbps_720x50P") = kAAFCodecFlavour_DV_Based_100Mbps_720x50P;
    CodecDef_scope.attr("Def_WAVE") = kAAFCodecDef_WAVE;
    CodecDef_scope.attr("Flavour_SMPTE_D10_30Mbps_525x5994I") = kAAFCodecFlavour_SMPTE_D10_30Mbps_525x5994I;
    CodecDef_scope.attr("Flavour_DV_Based_50Mbps_625_50") = kAAFCodecFlavour_DV_Based_50Mbps_625_50;
    CodecDef_scope.attr("WAVE") = kAAFCodecWAVE;
    CodecDef_scope.attr("Flavour_VC3_1254") = kAAFCodecFlavour_VC3_1254;
    CodecDef_scope.attr("Flavour_VC3_1253") = kAAFCodecFlavour_VC3_1253;
    CodecDef_scope.attr("Flavour_VC3_1252") = kAAFCodecFlavour_VC3_1252;
    CodecDef_scope.attr("Flavour_VC3_1250") = kAAFCodecFlavour_VC3_1250;
    CodecDef_scope.attr("Flavour_DV_Based_50Mbps_525_60") = kAAFCodecFlavour_DV_Based_50Mbps_525_60;
    CodecDef_scope.attr("CDCI") = kAAFCodecCDCI;
    CodecDef_scope.attr("Flavour_SMPTE_D10_40Mbps_625x50I") = kAAFCodecFlavour_SMPTE_D10_40Mbps_625x50I;
    CodecDef_scope.attr("Flavour_IEC_DV_525_60") = kAAFCodecFlavour_IEC_DV_525_60;
    CodecDef_scope.attr("Flavour_SMPTE_D10_50Mbps_525x5994I") = kAAFCodecFlavour_SMPTE_D10_50Mbps_525x5994I;
}

