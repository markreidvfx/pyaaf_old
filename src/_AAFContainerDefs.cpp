
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFContainerDefs.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AAFContainerDefs()
{
    scope().attr("ContainerOMF") = ContainerOMF;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_PictureOnly;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_IECDV_525x5994I_25Mbps_SMPTE322M") = kAAFContainerDef_MXFGC_Clipwrapped_IECDV_525x5994I_25Mbps_SMPTE322M;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_PictureOnly;
    scope().attr("kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_625x50I_720_422") = kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_625x50I_720_422;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_IECDV_625x50I_25Mbps_SMPTE322M") = kAAFContainerDef_MXFGC_Framewrapped_IECDV_625x50I_25Mbps_SMPTE322M;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_AES3_audio_data") = kAAFContainerDef_MXFGC_Framewrapped_AES3_audio_data;
    scope().attr("ContainerAAF") = ContainerAAF;
    scope().attr("kAAFContainerDef_MXFGC_Avid_DNX_220_1080p") = kAAFContainerDef_MXFGC_Avid_DNX_220_1080p;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_IECDV_UndefinedSource_25Mbps") = kAAFContainerDef_MXFGC_Framewrapped_IECDV_UndefinedSource_25Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_DVbased_1080x50I_100Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_1080x50I_100Mbps;
    scope().attr("kAAFContainerDef_OMF") = kAAFContainerDef_OMF;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_AES3_audio_data") = kAAFContainerDef_MXFGC_Clipwrapped_AES3_audio_data;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_DefinedTemplate;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_DVbased_1080x50I_100Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_1080x50I_100Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_DVbased_1080x5994I_100Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_1080x5994I_100Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Avid_DNX_145_1080i") = kAAFContainerDef_MXFGC_Avid_DNX_145_1080i;
    scope().attr("ContainerAAFXML") = ContainerAAFXML;
    scope().attr("ContainerAAFMSS") = ContainerAAFMSS;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_DVbased_625x50I_25Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_625x50I_25Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_625x50I_720_422") = kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_625x50I_720_422;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_VC3") = kAAFContainerDef_MXFGC_Framewrapped_VC3;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_DefinedTemplate;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_PictureOnly;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_DVbased_720x50P_100Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_720x50P_100Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_525x5994P_960_422") = kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_525x5994P_960_422;
    scope().attr("ContainerFile") = ContainerFile;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_Alaw_Audio") = kAAFContainerDef_MXFGC_Framewrapped_Alaw_Audio;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_ExtendedTemplate;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_PictureOnly;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_ExtendedTemplate;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_VC1") = kAAFContainerDef_MXFGC_Framewrapped_VC1;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_DVbased_525x5994I_25Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_525x5994I_25Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_DefinedTemplate;
    scope().attr("kAAFContainerDef_External") = kAAFContainerDef_External;
    scope().attr("kAAFContainerDef_RIFFWAVE") = kAAFContainerDef_RIFFWAVE;
    scope().attr("kAAFContainerDef_MXFGC_Generic_Essence_Multiple_Mappings") = kAAFContainerDef_MXFGC_Generic_Essence_Multiple_Mappings;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_MPEGES_VideoStream0_SID") = kAAFContainerDef_MXFGC_Framewrapped_MPEGES_VideoStream0_SID;
    scope().attr("kAAFContainerDef_MXFGC_Avid_DNX_145_720p") = kAAFContainerDef_MXFGC_Avid_DNX_145_720p;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_IECDV_525x5994I_25Mbps") = kAAFContainerDef_MXFGC_Framewrapped_IECDV_525x5994I_25Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_625x50I_720_422") = kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_625x50I_720_422;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_DVbased_UndefinedSource") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_UndefinedSource;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_IECDV_625x50I_25Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_IECDV_625x50I_25Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Avid_DNX_220_720p") = kAAFContainerDef_MXFGC_Avid_DNX_220_720p;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_525x5994P_960_422") = kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_525x5994P_960_422;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_DVbased_525x5994I_25Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_525x5994I_25Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_ExtendedTemplate;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_IECDV_UndefinedSource_25Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_IECDV_UndefinedSource_25Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_DefinedTemplate;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_DVbased_625x50I_25Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_625x50I_25Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_DVbased_720x50P_100Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_720x50P_100Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_525x5994I_720_422") = kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_525x5994I_720_422;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_DVbased_1080x5994I_100Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_1080x5994I_100Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_DVbased_625x50I_50Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_625x50I_50Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_DVbased_UndefinedSource") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_UndefinedSource;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_Broadcast_Wave_audio_data") = kAAFContainerDef_MXFGC_Framewrapped_Broadcast_Wave_audio_data;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_VC1") = kAAFContainerDef_MXFGC_Clipwrapped_VC1;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_VC3") = kAAFContainerDef_MXFGC_Clipwrapped_VC3;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_50Mbps_ExtendedTemplate;
    scope().attr("kAAFContainerDef_AAFMSS") = kAAFContainerDef_AAFMSS;
    scope().attr("kAAFContainerDef_MXFGC_Avid_DNX_145_1440_1080i") = kAAFContainerDef_MXFGC_Avid_DNX_145_1440_1080i;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_DVbased_525x5994I_50Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_525x5994I_50Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_DVbased_525x5994I_50Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_525x5994I_50Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_IECDV_625x50I_25Mbps") = kAAFContainerDef_MXFGC_Framewrapped_IECDV_625x50I_25Mbps;
    scope().attr("ContainerAAFKLV") = ContainerAAFKLV;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_40Mbps_DefinedTemplate;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_IECDV_525x5994I_25Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_IECDV_525x5994I_25Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_IECDV_525x5994I_25Mbps_SMPTE322M") = kAAFContainerDef_MXFGC_Framewrapped_IECDV_525x5994I_25Mbps_SMPTE322M;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_30Mbps_ExtendedTemplate;
    scope().attr("kAAFContainerDef_AAFKLV") = kAAFContainerDef_AAFKLV;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_625x50P_960_422") = kAAFContainerDef_MXFGC_Framewrapped_Uncompressed_625x50P_960_422;
    scope().attr("kAAFContainerDef_AAF") = kAAFContainerDef_AAF;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_50Mbps_PictureOnly;
    scope().attr("kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_625x50P_960_422") = kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_625x50P_960_422;
    scope().attr("kAAFContainerDef_MXFGC_Avid_DNX_220X_1080i") = kAAFContainerDef_MXFGC_Avid_DNX_220X_1080i;
    scope().attr("kAAFContainerDef_MXFGC_Avid_DNX_220X_1080p") = kAAFContainerDef_MXFGC_Avid_DNX_220X_1080p;
    scope().attr("kAAFContainerDef_MXFGC_CustomClosedGOPwrapped_MPEGES_VideoStream1_SID") = kAAFContainerDef_MXFGC_CustomClosedGOPwrapped_MPEGES_VideoStream1_SID;
    scope().attr("kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_525x5994I_720_422") = kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_525x5994I_720_422;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_DVbased_720x5994P_100Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_720x5994P_100Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_AVCbytestream_VideoStream0_SID") = kAAFContainerDef_MXFGC_Clipwrapped_AVCbytestream_VideoStream0_SID;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_Alaw_Audio") = kAAFContainerDef_MXFGC_Clipwrapped_Alaw_Audio;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_Broadcast_Wave_audio_data") = kAAFContainerDef_MXFGC_Clipwrapped_Broadcast_Wave_audio_data;
    scope().attr("kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_525x5994P_960_422") = kAAFContainerDef_MXFGC_Linewrapped_Uncompressed_525x5994P_960_422;
    scope().attr("kAAFContainerDef_MXFGC_Avid_DNX_145_1080p") = kAAFContainerDef_MXFGC_Avid_DNX_145_1080p;
    scope().attr("kAAFContainerDef_JFIF") = kAAFContainerDef_JFIF;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_DVbased_720x5994P_100Mbps") = kAAFContainerDef_MXFGC_Framewrapped_DVbased_720x5994P_100Mbps;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_DefinedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_625x50I_40Mbps_DefinedTemplate;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_DVbased_625x50I_50Mbps") = kAAFContainerDef_MXFGC_Clipwrapped_DVbased_625x50I_50Mbps;
    scope().attr("kAAFContainerDef_AIFFAIFC") = kAAFContainerDef_AIFFAIFC;
    scope().attr("kAAFContainerDef_AAFXML") = kAAFContainerDef_AAFXML;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_ExtendedTemplate") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_ExtendedTemplate;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_525x5994I_720_422") = kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_525x5994I_720_422;
    scope().attr("kAAFContainerDef_MXFGC_Avid_DNX_36_1080p") = kAAFContainerDef_MXFGC_Avid_DNX_36_1080p;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_IECDV_625x50I_25Mbps_SMPTE322M") = kAAFContainerDef_MXFGC_Clipwrapped_IECDV_625x50I_25Mbps_SMPTE322M;
    scope().attr("kAAFContainerDef_MXFGC_Customwrapped_Alaw_Audio") = kAAFContainerDef_MXFGC_Customwrapped_Alaw_Audio;
    scope().attr("kAAFContainerDef_MXFGC_Avid_DNX_220X_720p") = kAAFContainerDef_MXFGC_Avid_DNX_220X_720p;
    scope().attr("kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_PictureOnly") = kAAFContainerDef_MXFGC_Framewrapped_SMPTE_D10_525x5994I_30Mbps_PictureOnly;
    scope().attr("kAAFContainerDef_MXFGC_Avid_DNX_220_1080i") = kAAFContainerDef_MXFGC_Avid_DNX_220_1080i;
    scope().attr("kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_625x50P_960_422") = kAAFContainerDef_MXFGC_Clipwrapped_Uncompressed_625x50P_960_422;
}

