
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFContainerDefs.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class ContainerDef {};


// Module ======================================================================
void Export_pyste_src_AAFContainerDefs()
{

    scope ContainerDef_scope = class_<ContainerDef>("ContainerDef");
    ContainerDef_scope.attr("ContainerOMF") = ContainerOMF;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_PictureOnly;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_IECDV_525x5994I_25Mbps_SMPTE322M") = kAAFContainerDef_MXFGC_Clipwrapped_IECDV_525x5994I_25Mbps_SMPTE322M;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_PictureOnly;
    ContainerDef_scope.attr("MXFGC_Linewrapped_Uncompressed_625x50I_720_422") = kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_625x50I_720_422;
    ContainerDef_scope.attr("MXFGC_Framewrapped_IECDV_625x50I_25Mbps_SMPTE322M") = kAAFContainerDef_MXFGC_Framewrapped_IECDV_625x50I_25Mbps_SMPTE322M;
    ContainerDef_scope.attr("MXFGC_Framewrapped_AES3_audio_data") = kAAFContainerDef_MXFGC_Framewrapped_AES3_audio_data;
    ContainerDef_scope.attr("ContainerAAF") = ContainerAAF;
    ContainerDef_scope.attr("MXFGC_Avid_DNX_220_1080p") = kAAFContainerDef_MXFGC_Avid_DNX_220_1080p;
    ContainerDef_scope.attr("MXFGC_Framewrapped_IECDV_UndefinedSource_25Mbps") = kAAFContainerDef_MXFGC_Framewrapped_IECDV_UndefinedSource_25Mbps;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_DVbased_1080x50I_100Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_1080x50I_100Mbps;
    ContainerDef_scope.attr("OMF") = kAAFContainerDef_OMF;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_AES3_audio_data") = kAAFContainerDef_MXFGC_Clipwrapped_AES3_audio_data;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_DefinedTemplate;
    ContainerDef_scope.attr("MXFGC_Framewrapped_DVbased_1080x50I_100Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_1080x50I_100Mbps;
    ContainerDef_scope.attr("MXFGC_Framewrapped_DVbased_1080x5994I_100Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_1080x5994I_100Mbps;
    ContainerDef_scope.attr("MXFGC_Avid_DNX_145_1080i") = kAAFContainerDef_MXFGC_Avid_DNX_145_1080i;
    ContainerDef_scope.attr("ContainerAAFXML") = ContainerAAFXML;
    ContainerDef_scope.attr("ContainerAAFMSS") = ContainerAAFMSS;
    ContainerDef_scope.attr("MXFGC_Framewrapped_DVbased_625x50I_25Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_625x50I_25Mbps;
    ContainerDef_scope.attr("MXFGC_Framewrapped_Uncompressed_625x50I_720_422") = kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_625x50I_720_422;
    ContainerDef_scope.attr("MXFGC_Framewrapped_VC3") = kAAFContainerDef_MXFGC_Framewrapped_VC3;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_DefinedTemplate;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_PictureOnly;
    ContainerDef_scope.attr("MXFGC_Framewrapped_DVbased_720x50P_100Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_720x50P_100Mbps;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_Uncompressed_525x5994P_960_422") = kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_525x5994P_960_422;
    ContainerDef_scope.attr("ContainerFile") = ContainerFile;
    ContainerDef_scope.attr("MXFGC_Framewrapped_Alaw_Audio") = kAAFContainerDef_MXFGC_Framewrapped_Alaw_Audio;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_ExtendedTemplate;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_PictureOnly;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_ExtendedTemplate;
    ContainerDef_scope.attr("MXFGC_Framewrapped_VC1") = kAAFContainerDef_MXFGC_Framewrapped_VC1;
    ContainerDef_scope.attr("MXFGC_Framewrapped_DVbased_525x5994I_25Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_525x5994I_25Mbps;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_DefinedTemplate;
    ContainerDef_scope.attr("External") = kAAFContainerDef_External;
    ContainerDef_scope.attr("RIFFWAVE") = kAAFContainerDef_RIFFWAVE;
    ContainerDef_scope.attr("MXFGC_Generic_Essence_Multiple_Mappings") = kAAFContainerDef_MXFGC_Generic_Essence_Multiple_Mappings;
    ContainerDef_scope.attr("MXFGC_Framewrapped_MPEGES_VideoStream0_SID") = kAAFContainerDef_MXFGC_Framewrapped_MPEGES_VideoStream0_SID;
    ContainerDef_scope.attr("MXFGC_Avid_DNX_145_720p") = kAAFContainerDef_MXFGC_Avid_DNX_145_720p;
    ContainerDef_scope.attr("MXFGC_Framewrapped_IECDV_525x5994I_25Mbps") = kAAFContainerDef_MXFGC_Framewrapped_IECDV_525x5994I_25Mbps;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_Uncompressed_625x50I_720_422") = kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_625x50I_720_422;
    ContainerDef_scope.attr("MXFGC_Framewrapped_DVbased_UndefinedSource") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_UndefinedSource;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_IECDV_625x50I_25Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_IECDV_625x50I_25Mbps;
    ContainerDef_scope.attr("MXFGC_Avid_DNX_220_720p") = kAAFContainerDef_MXFGC_Avid_DNX_220_720p;
    ContainerDef_scope.attr("MXFGC_Framewrapped_Uncompressed_525x5994P_960_422") = kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_525x5994P_960_422;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_DVbased_525x5994I_25Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_525x5994I_25Mbps;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_ExtendedTemplate;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_IECDV_UndefinedSource_25Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_IECDV_UndefinedSource_25Mbps;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_DefinedTemplate;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_DVbased_625x50I_25Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_625x50I_25Mbps;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_DVbased_720x50P_100Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_720x50P_100Mbps;
    ContainerDef_scope.attr("MXFGC_Framewrapped_Uncompressed_525x5994I_720_422") = kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_525x5994I_720_422;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_DVbased_1080x5994I_100Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_1080x5994I_100Mbps;
    ContainerDef_scope.attr("MXFGC_Framewrapped_DVbased_625x50I_50Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_625x50I_50Mbps;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_DVbased_UndefinedSource") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_UndefinedSource;
    ContainerDef_scope.attr("MXFGC_Framewrapped_Broadcast_Wave_audio_data") = kAAFContainerDef_MXFGC_Framewrapped_Broadcast_Wave_audio_data;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_VC1") = kAAFContainerDef_MXFGC_Clipwrapped_VC1;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_VC3") = kAAFContainerDef_MXFGC_Clipwrapped_VC3;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_ExtendedTemplate;
    ContainerDef_scope.attr("AAFMSS") = kAAFContainerDef_AAFMSS;
    ContainerDef_scope.attr("MXFGC_Avid_DNX_145_1440_1080i") = kAAFContainerDef_MXFGC_Avid_DNX_145_1440_1080i;
    ContainerDef_scope.attr("MXFGC_Framewrapped_DVbased_525x5994I_50Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_525x5994I_50Mbps;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_DVbased_525x5994I_50Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_525x5994I_50Mbps;
    ContainerDef_scope.attr("MXFGC_Framewrapped_IECDV_625x50I_25Mbps") = kAAFContainerDef_MXFGC_Framewrapped_IECDV_625x50I_25Mbps;
    ContainerDef_scope.attr("ContainerAAFKLV") = ContainerAAFKLV;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_DefinedTemplate;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_IECDV_525x5994I_25Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_IECDV_525x5994I_25Mbps;
    ContainerDef_scope.attr("MXFGC_Framewrapped_IECDV_525x5994I_25Mbps_SMPTE322M") = kAAFContainerDef_MXFGC_Framewrapped_IECDV_525x5994I_25Mbps_SMPTE322M;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_ExtendedTemplate;
    ContainerDef_scope.attr("AAFKLV") = kAAFContainerDef_AAFKLV;
    ContainerDef_scope.attr("MXFGC_Framewrapped_Uncompressed_625x50P_960_422") = kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_625x50P_960_422;
    ContainerDef_scope.attr("AAF") = kAAFContainerDef_AAF;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_PictureOnly;
    ContainerDef_scope.attr("MXFGC_Linewrapped_Uncompressed_625x50P_960_422") = kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_625x50P_960_422;
    ContainerDef_scope.attr("MXFGC_Avid_DNX_220X_1080i") = kAAFContainerDef_MXFGC_Avid_DNX_220X_1080i;
    ContainerDef_scope.attr("MXFGC_Avid_DNX_220X_1080p") = kAAFContainerDef_MXFGC_Avid_DNX_220X_1080p;
    ContainerDef_scope.attr("MXFGC_CustomClosedGOPwrapped_MPEGES_VideoStream1_SID") = kAAFContainerDef_MXFGC_CustomClosedGOPwrapped_MPEGES_VideoStream1_SID;
    ContainerDef_scope.attr("MXFGC_Linewrapped_Uncompressed_525x5994I_720_422") = kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_525x5994I_720_422;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_DVbased_720x5994P_100Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_720x5994P_100Mbps;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_AVCbytestream_VideoStream0_SID") = kAAFContainerDef_MXFGC_Clipwrapped_AVCbytestream_VideoStream0_SID;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_Alaw_Audio") = kAAFContainerDef_MXFGC_Clipwrapped_Alaw_Audio;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_Broadcast_Wave_audio_data") = kAAFContainerDef_MXFGC_Clipwrapped_Broadcast_Wave_audio_data;
    ContainerDef_scope.attr("MXFGC_Linewrapped_Uncompressed_525x5994P_960_422") = kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_525x5994P_960_422;
    ContainerDef_scope.attr("MXFGC_Avid_DNX_145_1080p") = kAAFContainerDef_MXFGC_Avid_DNX_145_1080p;
    ContainerDef_scope.attr("JFIF") = kAAFContainerDef_JFIF;
    ContainerDef_scope.attr("MXFGC_Framewrapped_DVbased_720x5994P_100Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_720x5994P_100Mbps;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_DefinedTemplate;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_DVbased_625x50I_50Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_625x50I_50Mbps;
    ContainerDef_scope.attr("AIFFAIFC") = kAAFContainerDef_AIFFAIFC;
    ContainerDef_scope.attr("AAFXML") = kAAFContainerDef_AAFXML;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_ExtendedTemplate;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_Uncompressed_525x5994I_720_422") = kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_525x5994I_720_422;
    ContainerDef_scope.attr("MXFGC_Avid_DNX_36_1080p") = kAAFContainerDef_MXFGC_Avid_DNX_36_1080p;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_IECDV_625x50I_25Mbps_SMPTE322M") = kAAFContainerDef_MXFGC_Clipwrapped_IECDV_625x50I_25Mbps_SMPTE322M;
    ContainerDef_scope.attr("MXFGC_Customwrapped_Alaw_Audio") = kAAFContainerDef_MXFGC_Customwrapped_Alaw_Audio;
    ContainerDef_scope.attr("MXFGC_Avid_DNX_220X_720p") = kAAFContainerDef_MXFGC_Avid_DNX_220X_720p;
    ContainerDef_scope.attr("MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_PictureOnly;
    ContainerDef_scope.attr("MXFGC_Avid_DNX_220_1080i") = kAAFContainerDef_MXFGC_Avid_DNX_220_1080i;
    ContainerDef_scope.attr("MXFGC_Clipwrapped_Uncompressed_625x50P_960_422") = kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_625x50P_960_422;
}

