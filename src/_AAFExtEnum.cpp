
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFExtEnum.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class ExtEnumDef {};


// Module ======================================================================
void Export_pyste_src_AAFExtEnum()
{

    scope ExtEnumDef_scope = class_<ExtEnumDef>("ExtEnumDef");
    ExtEnumDef_scope.attr("PluginCategory_Interpolation") = kAAFPluginCategory_Interpolation;
    ExtEnumDef_scope.attr("PluginCategory_Codec") = kAAFPluginCategory_Codec;
    ExtEnumDef_scope.attr("ColorPrimaries_ITU709") = kAAFColorPrimaries_ITU709;
    ExtEnumDef_scope.attr("CodingEquations_SMPTE240M") = kAAFCodingEquations_SMPTE240M;
    ExtEnumDef_scope.attr("TransferCharacteristic_ITU709") = kAAFTransferCharacteristic_ITU709;
    ExtEnumDef_scope.attr("TransferCharacteristic_ITU1361") = kAAFTransferCharacteristic_ITU1361;
    ExtEnumDef_scope.attr("Usage_Template") = kAAFUsage_Template;
    ExtEnumDef_scope.attr("Usage_TopLevel") = kAAFUsage_TopLevel;
    ExtEnumDef_scope.attr("TransferCharacteristic_ITU470_PAL") = kAAFTransferCharacteristic_ITU470_PAL;
    ExtEnumDef_scope.attr("CodingEquations_ITU709") = kAAFCodingEquations_ITU709;
    ExtEnumDef_scope.attr("Usage_SubClip") = kAAFUsage_SubClip;
    ExtEnumDef_scope.attr("ColorPrimaries_ITU470_PAL") = kAAFColorPrimaries_ITU470_PAL;
    ExtEnumDef_scope.attr("CodingEquations_ITU601") = kAAFCodingEquations_ITU601;
    ExtEnumDef_scope.attr("OperationCategory_Effect") = kAAFOperationCategory_Effect;
    ExtEnumDef_scope.attr("PluginCategory_Effect") = kAAFPluginCategory_Effect;
    ExtEnumDef_scope.attr("TransferCharacteristic_274M_296M") = kAAFTransferCharacteristic_274M_296M;
    ExtEnumDef_scope.attr("ColorPrimaries_SMPTE170M") = kAAFColorPrimaries_SMPTE170M;
    ExtEnumDef_scope.attr("TransferCharacteristic_SMPTE240M") = kAAFTransferCharacteristic_SMPTE240M;
    ExtEnumDef_scope.attr("Usage_AdjustedClip") = kAAFUsage_AdjustedClip;
    ExtEnumDef_scope.attr("TransferCharacteristic_linear") = kAAFTransferCharacteristic_linear;
    ExtEnumDef_scope.attr("Usage_LowerLevel") = kAAFUsage_LowerLevel;
 }

