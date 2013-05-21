
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFOperationDefs.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class OperationDef {};


// Module ======================================================================
void Export_pyste_src_AAFOperationDefs()
{

    scope OperationDef_scope = class_<OperationDef>("OperationDef");
    OperationDef_scope.attr("VideoSeparateAlphaKey") = kAAFOperationDef_VideoSeparateAlphaKey;
    OperationDef_scope.attr("OperationUnknown") = kAAFOperationUnknown;
    OperationDef_scope.attr("MonoAudioGain") = kAAFOperationDef_MonoAudioGain;
    OperationDef_scope.attr("EffectMonoAudioPan") = kAAFEffectMonoAudioPan;
    OperationDef_scope.attr("EffectMonoAudioDissolve") = kAAFEffectMonoAudioDissolve;
    OperationDef_scope.attr("VideoPosition") = kAAFOperationDef_VideoPosition;
    OperationDef_scope.attr("VideoScale") = kAAFOperationDef_VideoScale;
    OperationDef_scope.attr("EffectVideoDissolve") = kAAFEffectVideoDissolve;
    OperationDef_scope.attr("MonoAudioDissolve") = kAAFOperationDef_MonoAudioDissolve;
    OperationDef_scope.attr("EffectStereoAudioDissolve") = kAAFEffectStereoAudioDissolve;
    OperationDef_scope.attr("VideoCornerPinning") = kAAFOperationDef_VideoCornerPinning;
    OperationDef_scope.attr("VideoDissolve") = kAAFOperationDef_VideoDissolve;
    OperationDef_scope.attr("VideoRepeat") = kAAFOperationDef_VideoRepeat;
    OperationDef_scope.attr("FlipFlop") = kAAFOperationDef_FlipFlop;
    OperationDef_scope.attr("EffectVideoSpeedControl") = kAAFEffectVideoSpeedControl;
    OperationDef_scope.attr("EffectMonoAudioGain") = kAAFEffectMonoAudioGain;
    OperationDef_scope.attr("Flip") = kAAFOperationDef_Flip;
    OperationDef_scope.attr("VideoRotate") = kAAFOperationDef_VideoRotate;
    OperationDef_scope.attr("VideoSpeedControl") = kAAFOperationDef_VideoSpeedControl;
    OperationDef_scope.attr("VideoTitle") = kAAFOperationDef_VideoTitle;
    OperationDef_scope.attr("EffectVideoFadeToBlack") = kAAFEffectVideoFadeToBlack;
    OperationDef_scope.attr("EffectVideoRepeat") = kAAFEffectVideoRepeat;
    OperationDef_scope.attr("EffectVideoFrameToMask") = kAAFEffectVideoFrameToMask;
    OperationDef_scope.attr("SMPTEVideoWipe") = kAAFOperationDef_SMPTEVideoWipe;
    OperationDef_scope.attr("MonoAudioPan") = kAAFOperationDef_MonoAudioPan;
    OperationDef_scope.attr("TwoParameterMonoAudioDissolve") = kAAFOperationDef_TwoParameterMonoAudioDissolve;
    OperationDef_scope.attr("VideoFadeToBlack") = kAAFOperationDef_VideoFadeToBlack;
    OperationDef_scope.attr("VideoChromaKey") = kAAFOperationDef_VideoChromaKey;
    OperationDef_scope.attr("EffectStereoAudioGain") = kAAFEffectStereoAudioGain;
    OperationDef_scope.attr("StereoAudioDissolve") = kAAFOperationDef_StereoAudioDissolve;
    OperationDef_scope.attr("MonoAudioMixdown") = kAAFOperationDef_MonoAudioMixdown;
    OperationDef_scope.attr("Flop") = kAAFOperationDef_Flop;
    OperationDef_scope.attr("EffectMonoAudioMixdown") = kAAFEffectMonoAudioMixdown;
    OperationDef_scope.attr("VideoLuminanceKey") = kAAFOperationDef_VideoLuminanceKey;
    OperationDef_scope.attr("StereoAudioGain") = kAAFOperationDef_StereoAudioGain;
    OperationDef_scope.attr("VideoCrop") = kAAFOperationDef_VideoCrop;
    OperationDef_scope.attr("EffectSMPTEVideoWipe") = kAAFEffectSMPTEVideoWipe;
    OperationDef_scope.attr("VideoFrameToMask") = kAAFOperationDef_VideoFrameToMask;
    OperationDef_scope.attr("EffectPictureWithMate") = kAAFEffectPictureWithMate;
    OperationDef_scope.attr("VideoAlphaWithinVideoKey") = kAAFOperationDef_VideoAlphaWithinVideoKey;
    OperationDef_scope.attr("PictureWithMate") = kAAFOperationDef_PictureWithMate;
    OperationDef_scope.attr("VideoColor") = kAAFOperationDef_VideoColor;
    OperationDef_scope.attr("Unknown") = kAAFOperationDef_Unknown;
    OperationDef_scope.attr("VideoOpacity") = kAAFOperationDef_VideoOpacity;
}

