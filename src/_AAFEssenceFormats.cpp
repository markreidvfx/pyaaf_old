
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFEssenceFormats_fix.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AAFEssenceFormats()
{
    scope().attr("kAAFCDCIPadBits") = kAAFCDCIPadBits;
    scope().attr("kAAFSampleRate") = kAAFSampleRate;
    scope().attr("kAAFMaxSampleBytes") = kAAFMaxSampleBytes;
    scope().attr("kAAFImageAlignmentFactor") = kAAFImageAlignmentFactor;
    scope().attr("kAAFCompression") = kAAFCompression;
    scope().attr("kAAFFieldEndOffset") = kAAFFieldEndOffset;
    scope().attr("kAAFPhysicalTrackNum") = kAAFPhysicalTrackNum;
    scope().attr("kAAFPixelFormat") = kAAFPixelFormat;
    scope().attr("kAAFCDCIColorRange") = kAAFCDCIColorRange;
    scope().attr("kAAFResolutionID") = kAAFResolutionID;
    scope().attr("kAAFLegacyCDCI") = kAAFLegacyCDCI;
    scope().attr("kAAFNumThreads") = kAAFNumThreads;
    scope().attr("kAAFStoredRect") = kAAFStoredRect;
    scope().attr("kAAFAudioSampleBits") = kAAFAudioSampleBits;
    scope().attr("kAAFCDCIColorSiting") = kAAFCDCIColorSiting;
    scope().attr("kAAFDisplayRect") = kAAFDisplayRect;
    scope().attr("kAAFFieldStartOffset") = kAAFFieldStartOffset;
    scope().attr("kAAFPixelSize") = kAAFPixelSize;
    scope().attr("kAAFWillTransferLines") = kAAFWillTransferLines;
    scope().attr("kAAFIsCompressed") = kAAFIsCompressed;
    scope().attr("kAAFEssenceElementKey") = kAAFEssenceElementKey;
    scope().attr("kAAFCompressionQuality") = kAAFCompressionQuality;
    scope().attr("kAAFSampleFormat") = kAAFSampleFormat;
    scope().attr("kAAFAlphaTransparency") = kAAFAlphaTransparency;
    scope().attr("kAAFFrameLayout") = kAAFFrameLayout;
    scope().attr("kAAFSampledRect") = kAAFSampledRect;
    scope().attr("kAAFNumChannels") = kAAFNumChannels;
    scope().attr("kAAFCDCIBlackLevel") = kAAFCDCIBlackLevel;
    scope().attr("kAAFBufferLayout") = kAAFBufferLayout;
    scope().attr("kAAFCDCIWhiteLevel") = kAAFCDCIWhiteLevel;
    scope().attr("kAAFCDCICompWidth") = kAAFCDCICompWidth;
    scope().attr("kAAFRGBPalette") = kAAFRGBPalette;
    scope().attr("kAAFCDCIHorizSubsampling") = kAAFCDCIHorizSubsampling;
    scope().attr("kAAFRGBPaletteLayout") = kAAFRGBPaletteLayout;
    scope().attr("kAAFGamma") = kAAFGamma;
    scope().attr("kAAFAspectRatio") = kAAFAspectRatio;
    scope().attr("kAAFVideoLineMap") = kAAFVideoLineMap;
    scope().attr("kAAFLegacyAUIDs") = kAAFLegacyAUIDs;
    scope().attr("kAAFLineLength") = kAAFLineLength;
    scope().attr("kAAFRGBCompSizes") = kAAFRGBCompSizes;
    scope().attr("kAAFRGBCompLayout") = kAAFRGBCompLayout;
    scope().attr("kAAFPadBytesPerRow") = kAAFPadBytesPerRow;
    scope().attr("kAAFRGBPaletteSizes") = kAAFRGBPaletteSizes;
    scope().attr("kAAFFieldDominance") = kAAFFieldDominance;
}

