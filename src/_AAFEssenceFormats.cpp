
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFEssenceFormats_fix.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class EssenceFormatDef {};


// Module ======================================================================
void Export_pyste_src_AAFEssenceFormats()
{

    scope EssenceFormatDef_scope = class_<EssenceFormatDef>("EssenceFormatDef");
    EssenceFormatDef_scope.attr("CDCIPadBits") = kAAFCDCIPadBits;
    EssenceFormatDef_scope.attr("SampleRate") = kAAFSampleRate;
    EssenceFormatDef_scope.attr("MaxSampleBytes") = kAAFMaxSampleBytes;
    EssenceFormatDef_scope.attr("ImageAlignmentFactor") = kAAFImageAlignmentFactor;
    EssenceFormatDef_scope.attr("Compression") = kAAFCompression;
    EssenceFormatDef_scope.attr("FieldEndOffset") = kAAFFieldEndOffset;
    EssenceFormatDef_scope.attr("PhysicalTrackNum") = kAAFPhysicalTrackNum;
    EssenceFormatDef_scope.attr("PixelFormat") = kAAFPixelFormat;
    EssenceFormatDef_scope.attr("CDCIColorRange") = kAAFCDCIColorRange;
    EssenceFormatDef_scope.attr("ResolutionID") = kAAFResolutionID;
    EssenceFormatDef_scope.attr("LegacyCDCI") = kAAFLegacyCDCI;
    EssenceFormatDef_scope.attr("NumThreads") = kAAFNumThreads;
    EssenceFormatDef_scope.attr("StoredRect") = kAAFStoredRect;
    EssenceFormatDef_scope.attr("AudioSampleBits") = kAAFAudioSampleBits;
    EssenceFormatDef_scope.attr("CDCIColorSiting") = kAAFCDCIColorSiting;
    EssenceFormatDef_scope.attr("DisplayRect") = kAAFDisplayRect;
    EssenceFormatDef_scope.attr("FieldStartOffset") = kAAFFieldStartOffset;
    EssenceFormatDef_scope.attr("PixelSize") = kAAFPixelSize;
    EssenceFormatDef_scope.attr("WillTransferLines") = kAAFWillTransferLines;
    EssenceFormatDef_scope.attr("IsCompressed") = kAAFIsCompressed;
    EssenceFormatDef_scope.attr("EssenceElementKey") = kAAFEssenceElementKey;
    EssenceFormatDef_scope.attr("CompressionQuality") = kAAFCompressionQuality;
    EssenceFormatDef_scope.attr("SampleFormat") = kAAFSampleFormat;
    EssenceFormatDef_scope.attr("AlphaTransparency") = kAAFAlphaTransparency;
    EssenceFormatDef_scope.attr("FrameLayout") = kAAFFrameLayout;
    EssenceFormatDef_scope.attr("SampledRect") = kAAFSampledRect;
    EssenceFormatDef_scope.attr("NumChannels") = kAAFNumChannels;
    EssenceFormatDef_scope.attr("CDCIBlackLevel") = kAAFCDCIBlackLevel;
    EssenceFormatDef_scope.attr("BufferLayout") = kAAFBufferLayout;
    EssenceFormatDef_scope.attr("CDCIWhiteLevel") = kAAFCDCIWhiteLevel;
    EssenceFormatDef_scope.attr("CDCICompWidth") = kAAFCDCICompWidth;
    EssenceFormatDef_scope.attr("RGBPalette") = kAAFRGBPalette;
    EssenceFormatDef_scope.attr("CDCIHorizSubsampling") = kAAFCDCIHorizSubsampling;
    EssenceFormatDef_scope.attr("RGBPaletteLayout") = kAAFRGBPaletteLayout;
    EssenceFormatDef_scope.attr("Gamma") = kAAFGamma;
    EssenceFormatDef_scope.attr("AspectRatio") = kAAFAspectRatio;
    EssenceFormatDef_scope.attr("VideoLineMap") = kAAFVideoLineMap;
    EssenceFormatDef_scope.attr("LegacyAUIDs") = kAAFLegacyAUIDs;
    EssenceFormatDef_scope.attr("LineLength") = kAAFLineLength;
    EssenceFormatDef_scope.attr("RGBCompSizes") = kAAFRGBCompSizes;
    EssenceFormatDef_scope.attr("RGBCompLayout") = kAAFRGBCompLayout;
    EssenceFormatDef_scope.attr("PadBytesPerRow") = kAAFPadBytesPerRow;
    EssenceFormatDef_scope.attr("RGBPaletteSizes") = kAAFRGBPaletteSizes;
    EssenceFormatDef_scope.attr("FieldDominance") = kAAFFieldDominance;
}

