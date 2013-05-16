
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFOperationDefs.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AAFOperationDefs()
{
    scope().attr("kAAFOperationDef_VideoSeparateAlphaKey") = kAAFOperationDef_VideoSeparateAlphaKey;
    scope().attr("kAAFOperationUnknown") = kAAFOperationUnknown;
    scope().attr("kAAFOperationDef_MonoAudioGain") = kAAFOperationDef_MonoAudioGain;
    scope().attr("kAAFEffectMonoAudioPan") = kAAFEffectMonoAudioPan;
    scope().attr("kAAFEffectMonoAudioDissolve") = kAAFEffectMonoAudioDissolve;
    scope().attr("kAAFOperationDef_VideoPosition") = kAAFOperationDef_VideoPosition;
    scope().attr("kAAFOperationDef_VideoScale") = kAAFOperationDef_VideoScale;
    scope().attr("kAAFEffectVideoDissolve") = kAAFEffectVideoDissolve;
    scope().attr("kAAFOperationDef_MonoAudioDissolve") = kAAFOperationDef_MonoAudioDissolve;
    scope().attr("kAAFEffectStereoAudioDissolve") = kAAFEffectStereoAudioDissolve;
    scope().attr("kAAFOperationDef_VideoCornerPinning") = kAAFOperationDef_VideoCornerPinning;
    scope().attr("kAAFOperationDef_VideoDissolve") = kAAFOperationDef_VideoDissolve;
    scope().attr("kAAFOperationDef_VideoRepeat") = kAAFOperationDef_VideoRepeat;
    scope().attr("kAAFOperationDef_FlipFlop") = kAAFOperationDef_FlipFlop;
    scope().attr("kAAFEffectVideoSpeedControl") = kAAFEffectVideoSpeedControl;
    scope().attr("kAAFEffectMonoAudioGain") = kAAFEffectMonoAudioGain;
    scope().attr("kAAFOperationDef_Flip") = kAAFOperationDef_Flip;
    scope().attr("kAAFOperationDef_VideoRotate") = kAAFOperationDef_VideoRotate;
    scope().attr("kAAFOperationDef_VideoSpeedControl") = kAAFOperationDef_VideoSpeedControl;
    scope().attr("kAAFOperationDef_VideoTitle") = kAAFOperationDef_VideoTitle;
    scope().attr("kAAFEffectVideoFadeToBlack") = kAAFEffectVideoFadeToBlack;
    scope().attr("kAAFEffectVideoRepeat") = kAAFEffectVideoRepeat;
    scope().attr("kAAFEffectVideoFrameToMask") = kAAFEffectVideoFrameToMask;
    scope().attr("kAAFOperationDef_SMPTEVideoWipe") = kAAFOperationDef_SMPTEVideoWipe;
    scope().attr("kAAFOperationDef_MonoAudioPan") = kAAFOperationDef_MonoAudioPan;
    scope().attr("kAAFOperationDef_TwoParameterMonoAudioDissolve") = kAAFOperationDef_TwoParameterMonoAudioDissolve;
    scope().attr("kAAFOperationDef_VideoFadeToBlack") = kAAFOperationDef_VideoFadeToBlack;
    scope().attr("kAAFOperationDef_VideoChromaKey") = kAAFOperationDef_VideoChromaKey;
    scope().attr("kAAFEffectStereoAudioGain") = kAAFEffectStereoAudioGain;
    scope().attr("kAAFOperationDef_StereoAudioDissolve") = kAAFOperationDef_StereoAudioDissolve;
    scope().attr("kAAFOperationDef_MonoAudioMixdown") = kAAFOperationDef_MonoAudioMixdown;
    scope().attr("kAAFOperationDef_Flop") = kAAFOperationDef_Flop;
    scope().attr("kAAFEffectMonoAudioMixdown") = kAAFEffectMonoAudioMixdown;
    scope().attr("kAAFOperationDef_VideoLuminanceKey") = kAAFOperationDef_VideoLuminanceKey;
    scope().attr("kAAFOperationDef_StereoAudioGain") = kAAFOperationDef_StereoAudioGain;
    scope().attr("kAAFOperationDef_VideoCrop") = kAAFOperationDef_VideoCrop;
    scope().attr("kAAFEffectSMPTEVideoWipe") = kAAFEffectSMPTEVideoWipe;
    scope().attr("kAAFOperationDef_VideoFrameToMask") = kAAFOperationDef_VideoFrameToMask;
    scope().attr("kAAFEffectPictureWithMate") = kAAFEffectPictureWithMate;
    scope().attr("kAAFOperationDef_VideoAlphaWithinVideoKey") = kAAFOperationDef_VideoAlphaWithinVideoKey;
    scope().attr("kAAFOperationDef_PictureWithMate") = kAAFOperationDef_PictureWithMate;
    scope().attr("kAAFOperationDef_VideoColor") = kAAFOperationDef_VideoColor;
    scope().attr("kAAFOperationDef_Unknown") = kAAFOperationDef_Unknown;
    scope().attr("kAAFOperationDef_VideoOpacity") = kAAFOperationDef_VideoOpacity;
}

