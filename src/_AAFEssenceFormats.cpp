
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFEssenceFormats.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AAFEssenceFormats()
{
    scope().attr("kAAFWillTransferLines") = kAAFWillTransferLines;
    scope().attr("kAAFCDCICompWidth") = kAAFCDCICompWidth;
    scope().attr("kAAFMaxSampleBytes") = kAAFMaxSampleBytes;
    scope().attr("kAAFStoredRect") = kAAFStoredRect;
    scope().attr("kAAFCDCIBlackLevel") = kAAFCDCIBlackLevel;
    scope().attr("kAAFSampleFormat") = kAAFSampleFormat;
    scope().attr("kAAFFieldDominance") = kAAFFieldDominance;
    scope().attr("kAAFCompressionQuality") = kAAFCompressionQuality;
    scope().attr("kAAFDisplayRect") = kAAFDisplayRect;
    scope().attr("kAAFCDCIWhiteLevel") = kAAFCDCIWhiteLevel;
    scope().attr("kAAFRGBCompSizes") = kAAFRGBCompSizes;
    scope().attr("kAAFNumChannels") = kAAFNumChannels;
    scope().attr("kAAFCDCIColorSiting") = kAAFCDCIColorSiting;
    scope().attr("kAAFAlphaTransparency") = kAAFAlphaTransparency;
    scope().attr("kAAFAudioSampleBits") = kAAFAudioSampleBits;
    scope().attr("kAAFIsCompressed") = kAAFIsCompressed;
    scope().attr("kAAFCDCIPadBits") = kAAFCDCIPadBits;
    scope().attr("kAAFLegacyAUIDs") = kAAFLegacyAUIDs;
    scope().attr("kAAFResolutionID") = kAAFResolutionID;
    scope().attr("kAAFRGBPaletteLayout") = kAAFRGBPaletteLayout;
    scope().attr("kAAFCDCIColorRange") = kAAFCDCIColorRange;
    scope().attr("kAAFPixelSize") = kAAFPixelSize;
    scope().attr("kAAFImageAlignmentFactor") = kAAFImageAlignmentFactor;
    scope().attr("kAAFLegacyCDCI") = kAAFLegacyCDCI;
    scope().attr("kAAFFieldEndOffset") = kAAFFieldEndOffset;
    scope().attr("kAAFCompression") = kAAFCompression;
    scope().attr("kAAFRGBPaletteSizes") = kAAFRGBPaletteSizes;
    scope().attr("kAAFSampledRect") = kAAFSampledRect;
    scope().attr("kAAFFrameLayout") = kAAFFrameLayout;
    scope().attr("kAAFEssenceElementKey") = kAAFEssenceElementKey;
    scope().attr("kAAFRGBCompLayout") = kAAFRGBCompLayout;
    scope().attr("kAAFRGBPalette") = kAAFRGBPalette;
    scope().attr("kAAFVideoLineMap") = kAAFVideoLineMap;
    scope().attr("kAAFAspectRatio") = kAAFAspectRatio;
    scope().attr("kAAFPixelFormat") = kAAFPixelFormat;
    scope().attr("kAAFPadBytesPerRow") = kAAFPadBytesPerRow;
    scope().attr("kAAFSampleRate") = kAAFSampleRate;
    scope().attr("kAAFGamma") = kAAFGamma;
    scope().attr("kAAFLineLength") = kAAFLineLength;
    scope().attr("kAAFNumThreads") = kAAFNumThreads;
    scope().attr("kAAFBufferLayout") = kAAFBufferLayout;
    scope().attr("kAAFCDCIHorizSubsampling") = kAAFCDCIHorizSubsampling;
    scope().attr("kAAFFieldStartOffset") = kAAFFieldStartOffset;
    scope().attr("kAAFPhysicalTrackNum") = kAAFPhysicalTrackNum;
}

