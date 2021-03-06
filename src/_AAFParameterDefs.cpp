
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFParameterDefs.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class ParameterDef {};


// Module ======================================================================
void Export_pyste_src_AAFParameterDefs()
{

    scope ParameterDef_scope = class_<ParameterDef>("ParameterDef");
    ParameterDef_scope.attr("OpacityLevel") = kAAFParameterDef_OpacityLevel;
    ParameterDef_scope.attr("TitleText") = kAAFParameterDef_TitleText;
    ParameterDef_scope.attr("Pan") = kAAFParameterDef_Pan;
    ParameterDef_scope.attr("IncomingLevel") = kAAFParameterDef_IncomingLevel;
    ParameterDef_scope.attr("PinTopRightX") = kAAFParameterDef_PinTopRightX;
    ParameterDef_scope.attr("PinTopRightY") = kAAFParameterDef_PinTopRightY;
    ParameterDef_scope.attr("SMPTETumble") = kAAFParameterDef_SMPTETumble;
    ParameterDef_scope.attr("SpeedRatio") = kAAFParameterDef_SpeedRatio;
    ParameterDef_scope.attr("ColorOffsetB") = kAAFParameterDef_ColorOffsetB;
    ParameterDef_scope.attr("SMPTEPosition") = kAAFParameterDefSMPTEPosition;
    ParameterDef_scope.attr("PinBottomRightX") = kAAFParameterDef_PinBottomRightX;
    ParameterDef_scope.attr("PinBottomRightY") = kAAFParameterDef_PinBottomRightY;
    ParameterDef_scope.attr("TitleItalic") = kAAFParameterDef_TitleItalic;
    ParameterDef_scope.attr("ColorCorrectionDescription") = kAAFParameterDef_ColorCorrectionDescription;
    ParameterDef_scope.attr("TitleFontSize") = kAAFParameterDef_TitleFontSize;
    ParameterDef_scope.attr("CropRight") = kAAFParameterDef_CropRight;
    ParameterDef_scope.attr("SMPTEReplicationV") = kAAFParameterDef_SMPTEReplicationV;
    ParameterDef_scope.attr("LumKeyClip") = kAAFParameterDef_LumKeyClip;
    ParameterDef_scope.attr("TitlePositionX") = kAAFParameterDef_TitlePositionX;
    ParameterDef_scope.attr("Pan") = kAAFParameterDefPan;
    ParameterDef_scope.attr("SMPTEModulator") = kAAFParameterDefSMPTEModulator;
    ParameterDef_scope.attr("SMPTESpotlight") = kAAFParameterDef_SMPTESpotlight;
    ParameterDef_scope.attr("PinBottomLeftX") = kAAFParameterDef_PinBottomLeftX;
    ParameterDef_scope.attr("SpeedRatio") = kAAFParameterDefSpeedRatio;
    ParameterDef_scope.attr("Level") = kAAFParameterDef_Level;
    ParameterDef_scope.attr("CropTop") = kAAFParameterDef_CropTop;
    ParameterDef_scope.attr("SMPTESpotlight") = kAAFParameterDefSMPTESpotlight;
    ParameterDef_scope.attr("PinBottomLeftY") = kAAFParameterDef_PinBottomLeftY;
    ParameterDef_scope.attr("SMPTEModulator") = kAAFParameterDef_SMPTEModulator;
    ParameterDef_scope.attr("CropLeft") = kAAFParameterDef_CropLeft;
    ParameterDef_scope.attr("ScaleX") = kAAFParameterDef_ScaleX;
    ParameterDef_scope.attr("TitleAlignment") = kAAFParameterDef_TitleAlignment;
    ParameterDef_scope.attr("SMPTEShadow") = kAAFParameterDef_SMPTEShadow;
    ParameterDef_scope.attr("AlphaKeyInvertAlpha") = kAAFParameterDef_AlphaKeyInvertAlpha;
    ParameterDef_scope.attr("TitlePositionY") = kAAFParameterDef_TitlePositionY;
    ParameterDef_scope.attr("SMPTEReverse") = kAAFParameterDefSMPTEReverse;
    ParameterDef_scope.attr("SMPTEWipeNumber") = kAAFParameterDefSMPTEWipeNumber;
    ParameterDef_scope.attr("SMPTEWipeNumber") = kAAFParameterDef_SMPTEWipeNumber;
    ParameterDef_scope.attr("SMPTEBorder") = kAAFParameterDef_SMPTEBorder;
    ParameterDef_scope.attr("ColorSlopeG") = kAAFParameterDef_ColorSlopeG;
    ParameterDef_scope.attr("ColorSlopeB") = kAAFParameterDef_ColorSlopeB;
    ParameterDef_scope.attr("ColorSlopeR") = kAAFParameterDef_ColorSlopeR;
    ParameterDef_scope.attr("SMPTEBorder") = kAAFParameterDefSMPTEBorder;
    ParameterDef_scope.attr("SMPTETumble") = kAAFParameterDefSMPTETumble;
    ParameterDef_scope.attr("ScaleY") = kAAFParameterDef_ScaleY;
    ParameterDef_scope.attr("SMPTECheckerboard") = kAAFParameterDefSMPTECheckerboard;
    ParameterDef_scope.attr("TitleBold") = kAAFParameterDef_TitleBold;
    ParameterDef_scope.attr("PhaseOffset") = kAAFParameterDefPhaseOffset;
    ParameterDef_scope.attr("TitleFontColorR") = kAAFParameterDef_TitleFontColorR;
    ParameterDef_scope.attr("TitleFontColorG") = kAAFParameterDef_TitleFontColorG;
    ParameterDef_scope.attr("SMPTECheckerboard") = kAAFParameterDef_SMPTECheckerboard;
    ParameterDef_scope.attr("SMPTESoft") = kAAFParameterDef_SMPTESoft;
    ParameterDef_scope.attr("SMPTEReplicationH") = kAAFParameterDef_SMPTEReplicationH;
    ParameterDef_scope.attr("Amplitude") = kAAFParameterDef_Amplitude;
    ParameterDef_scope.attr("PinTopLeftY") = kAAFParameterDef_PinTopLeftY;
    ParameterDef_scope.attr("TitleFontColorB") = kAAFParameterDef_TitleFontColorB;
    ParameterDef_scope.attr("Level") = kAAFParameterDefLevel;
    ParameterDef_scope.attr("PinTopLeftX") = kAAFParameterDef_PinTopLeftX;
    ParameterDef_scope.attr("TitleFontName") = kAAFParameterDef_TitleFontName;
    ParameterDef_scope.attr("ColorViewingDescription") = kAAFParameterDef_ColorViewingDescription;
    ParameterDef_scope.attr("ColorPowerR") = kAAFParameterDef_ColorPowerR;
    ParameterDef_scope.attr("ColorPowerG") = kAAFParameterDef_ColorPowerG;
    ParameterDef_scope.attr("ColorPowerB") = kAAFParameterDef_ColorPowerB;
    ParameterDef_scope.attr("SMPTEReplicationH") = kAAFParameterDefSMPTEReplicationH;
    ParameterDef_scope.attr("PositionOffsetX") = kAAFParameterDef_PositionOffsetX;
    ParameterDef_scope.attr("PositionOffsetY") = kAAFParameterDef_PositionOffsetY;
    ParameterDef_scope.attr("CropBottom") = kAAFParameterDef_CropBottom;
    ParameterDef_scope.attr("SMPTEPosition") = kAAFParameterDef_SMPTEPosition;
    ParameterDef_scope.attr("OutgoingLevel") = kAAFParameterDef_OutgoingLevel;
    ParameterDef_scope.attr("ColorInputDescription") = kAAFParameterDef_ColorInputDescription;
    ParameterDef_scope.attr("SMPTEShadow") = kAAFParameterDefSMPTEShadow;
    ParameterDef_scope.attr("Amplitude") = kAAFParameterDefAmplitude;
    ParameterDef_scope.attr("ColorOffsetG") = kAAFParameterDef_ColorOffsetG;
    ParameterDef_scope.attr("PhaseOffset") = kAAFParameterDef_PhaseOffset;
    ParameterDef_scope.attr("SMPTESoft") = kAAFParameterDefSMPTESoft;
    ParameterDef_scope.attr("ColorOffsetR") = kAAFParameterDef_ColorOffsetR;
    ParameterDef_scope.attr("SMPTEReplicationV") = kAAFParameterDefSMPTEReplicationV;
    ParameterDef_scope.attr("LumKeyLevel") = kAAFParameterDef_LumKeyLevel;
    ParameterDef_scope.attr("Rotation") = kAAFParameterDef_Rotation;
    ParameterDef_scope.attr("SMPTEReverse") = kAAFParameterDef_SMPTEReverse;
    ParameterDef_scope.attr("ColorSaturation") = kAAFParameterDef_ColorSaturation;
    }

