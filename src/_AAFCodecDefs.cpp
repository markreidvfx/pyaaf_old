
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFCodecDefs.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AAFCodecDefs()
{
    scope().attr("kAAFNilCodecFlavour") = kAAFNilCodecFlavour;
    scope().attr("kAAFCodecFlavour_None") = kAAFCodecFlavour_None;
    scope().attr("kAAFCodecDef_None") = kAAFCodecDef_None;
    scope().attr("kAAFCodecPCM") = kAAFCodecPCM;
    scope().attr("kAAFCodecJPEG") = kAAFCodecJPEG;
    scope().attr("kAAFCodecFlavour_SMPTE_D10_50Mbps_625x50I") = kAAFCodecFlavour_SMPTE_D10_50Mbps_625x50I;
    scope().attr("kAAFCodecDef_CDCI") = kAAFCodecDef_CDCI;
    scope().attr("kAAFCodecDef_JPEG") = kAAFCodecDef_JPEG;
    scope().attr("kAAFCodecDef_RGBA") = kAAFCodecDef_RGBA;
    scope().attr("kAAFCODEC_AIFC") = kAAFCODEC_AIFC;
    scope().attr("kAAFCodecFlavour_DV_Based_25Mbps_525_60") = kAAFCodecFlavour_DV_Based_25Mbps_525_60;
    scope().attr("kAAFCodecDef_VC3") = kAAFCodecDef_VC3;
    scope().attr("kAAFNoCodec") = kAAFNoCodec;
    scope().attr("kAAFCodecRGBA") = kAAFCodecRGBA;
    scope().attr("kAAFCodecFlavour_LegacyDV_525_60") = kAAFCodecFlavour_LegacyDV_525_60;
    scope().attr("kAAFCodecDNxHD") = kAAFCodecDNxHD;
    scope().attr("kAAFCodecDef_PCM") = kAAFCodecDef_PCM;
    scope().attr("kAAFCodecFlavour_VC3_1251") = kAAFCodecFlavour_VC3_1251;
    scope().attr("kAAFCodecFlavour_SMPTE_D10_40Mbps_525x5994I") = kAAFCodecFlavour_SMPTE_D10_40Mbps_525x5994I;
    scope().attr("kAAFCodecDef_DNxHD") = kAAFCodecDef_DNxHD;
    scope().attr("kAAFCodecFlavour_DV_Based_100Mbps_1080x50I") = kAAFCodecFlavour_DV_Based_100Mbps_1080x50I;
    scope().attr("kAAFCodecFlavour_LegacyDV_625_50") = kAAFCodecFlavour_LegacyDV_625_50;
    scope().attr("kAAFCodecFlavour_IEC_DV_625_50") = kAAFCodecFlavour_IEC_DV_625_50;
    scope().attr("kAAFCodecFlavour_DV_Based_100Mbps_1080x5994I") = kAAFCodecFlavour_DV_Based_100Mbps_1080x5994I;
    scope().attr("kAAFCodecDef_AIFC") = kAAFCodecDef_AIFC;
    scope().attr("kAAFCodecFlavour_VC3_1244") = kAAFCodecFlavour_VC3_1244;
    scope().attr("kAAFCodecFlavour_VC3_1241") = kAAFCodecFlavour_VC3_1241;
    scope().attr("kAAFCodecFlavour_VC3_1242") = kAAFCodecFlavour_VC3_1242;
    scope().attr("kAAFCodecFlavour_VC3_1243") = kAAFCodecFlavour_VC3_1243;
    scope().attr("kAAFCodecFlavour_VC3_1237") = kAAFCodecFlavour_VC3_1237;
    scope().attr("kAAFCodecFlavour_VC3_1238") = kAAFCodecFlavour_VC3_1238;
    scope().attr("kAAFCodecVC3") = kAAFCodecVC3;
    scope().attr("kAAFCodecFlavour_SMPTE_D10_30Mbps_625x50I") = kAAFCodecFlavour_SMPTE_D10_30Mbps_625x50I;
    scope().attr("kAAFCodecFlavour_DV_Based_100Mbps_720x5994P") = kAAFCodecFlavour_DV_Based_100Mbps_720x5994P;
    scope().attr("kAAFCodecFlavour_DV_Based_25Mbps_625_50") = kAAFCodecFlavour_DV_Based_25Mbps_625_50;
    scope().attr("kAAFCodecFlavour_VC3_1235") = kAAFCodecFlavour_VC3_1235;
    scope().attr("kAAFCodecFlavour_DV_Based_100Mbps_720x50P") = kAAFCodecFlavour_DV_Based_100Mbps_720x50P;
    scope().attr("kAAFCodecDef_WAVE") = kAAFCodecDef_WAVE;
    scope().attr("kAAFCodecFlavour_SMPTE_D10_30Mbps_525x5994I") = kAAFCodecFlavour_SMPTE_D10_30Mbps_525x5994I;
    scope().attr("kAAFCodecFlavour_DV_Based_50Mbps_625_50") = kAAFCodecFlavour_DV_Based_50Mbps_625_50;
    scope().attr("kAAFCodecWAVE") = kAAFCodecWAVE;
    scope().attr("kAAFCodecFlavour_VC3_1254") = kAAFCodecFlavour_VC3_1254;
    scope().attr("kAAFCodecFlavour_VC3_1253") = kAAFCodecFlavour_VC3_1253;
    scope().attr("kAAFCodecFlavour_VC3_1252") = kAAFCodecFlavour_VC3_1252;
    scope().attr("kAAFCodecFlavour_VC3_1250") = kAAFCodecFlavour_VC3_1250;
    scope().attr("kAAFCodecFlavour_DV_Based_50Mbps_525_60") = kAAFCodecFlavour_DV_Based_50Mbps_525_60;
    scope().attr("kAAFCodecCDCI") = kAAFCodecCDCI;
    scope().attr("kAAFCodecFlavour_SMPTE_D10_40Mbps_625x50I") = kAAFCodecFlavour_SMPTE_D10_40Mbps_625x50I;
    scope().attr("kAAFCodecFlavour_IEC_DV_525_60") = kAAFCodecFlavour_IEC_DV_525_60;
    scope().attr("kAAFCodecFlavour_SMPTE_D10_50Mbps_525x5994I") = kAAFCodecFlavour_SMPTE_D10_50Mbps_525x5994I;
}

