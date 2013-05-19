
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <query_interface.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class SmartPointers {};


// Module ======================================================================
void Export_pyste_src_AxSmartPointer()
{

scope smartpointers = class_<SmartPointers>("smartpointers");
class_< IAAFAIFCDescriptorSP > ("IAAFAIFCDescriptorSP")
;
class_< IAAFClassDefSP > ("IAAFClassDefSP")
;
class_< IAAFCodecDefSP > ("IAAFCodecDefSP")
;
class_< IAAFCommentMarkerSP > ("IAAFCommentMarkerSP")
;
class_< IAAFComponentSP > ("IAAFComponentSP")
;
class_< IAAFCompositionMobSP > ("IAAFCompositionMobSP")
;
class_< IAAFCompositionMob2SP > ("IAAFCompositionMob2SP")
;
class_< IAAFConstantValueSP > ("IAAFConstantValueSP")
;
class_< IAAFContainerDefSP > ("IAAFContainerDefSP")
;
class_< IAAFContentStorageSP > ("IAAFContentStorageSP")
;
class_< IAAFControlPointSP > ("IAAFControlPointSP")
;
class_< IAAFDataDefSP > ("IAAFDataDefSP")
;
class_< IAAFDefObjectSP > ("IAAFDefObjectSP")
;
class_< IAAFPluginDefSP > ("IAAFPluginDefSP")
;
class_< IAAFDictionarySP > ("IAAFDictionarySP")
;
class_< IAAFEdgecodeSP > ("IAAFEdgecodeSP")
;
class_< IAAFOperationDefSP > ("IAAFOperationDefSP")
;
class_< IAAFEssenceAccessSP > ("IAAFEssenceAccessSP")
;
class_< IAAFEssenceDataSP > ("IAAFEssenceDataSP")
;
class_< IAAFEssenceDescriptorSP > ("IAAFEssenceDescriptorSP")
;
class_< IAAFEventSP > ("IAAFEventSP")
;
class_< IAAFEventMobSlotSP > ("IAAFEventMobSlotSP")
;
class_< IAAFFileSP > ("IAAFFileSP")
;
class_< IAAFFileDescriptorSP > ("IAAFFileDescriptorSP")
;
class_< IAAFFilmDescriptorSP > ("IAAFFilmDescriptorSP")
;
class_< IAAFDigitalImageDescriptorSP > ("IAAFDigitalImageDescriptorSP")
;
class_< IAAFCDCIDescriptorSP > ("IAAFCDCIDescriptorSP")
;
class_< IAAFEssenceFormatSP > ("IAAFEssenceFormatSP")
;
class_< IAAFEssenceGroupSP > ("IAAFEssenceGroupSP")
;
class_< IAAFFillerSP > ("IAAFFillerSP")
;
class_< IAAFFindSourceInfoSP > ("IAAFFindSourceInfoSP")
;
class_< IAAFOperationGroupSP > ("IAAFOperationGroupSP")
;
class_< IAAFGPITriggerSP > ("IAAFGPITriggerSP")
;
class_< IAAFHeaderSP > ("IAAFHeaderSP")
;
class_< IAAFIdentificationSP > ("IAAFIdentificationSP")
;
class_< IAAFInterpolationDefSP > ("IAAFInterpolationDefSP")
;
class_< IAAFKLVDataSP > ("IAAFKLVDataSP")
;
class_< IAAFLocatorSP > ("IAAFLocatorSP")
;
class_< IAAFMasterMobSP > ("IAAFMasterMobSP")
;
class_< IAAFMasterMob2SP > ("IAAFMasterMob2SP")
;
class_< IAAFMasterMobExSP > ("IAAFMasterMobExSP")
;
class_< IAAFMetaDefinitionSP > ("IAAFMetaDefinitionSP")
;
class_< IAAFMobSP > ("IAAFMobSP")
.def("to_MasterMobSP", query_interface<IAAFMob, IAAFMasterMob > )
.def("to_SourceMobSP", query_interface<IAAFMob, IAAFSourceMob > )
.def("to_CompositionMobSP", query_interface<IAAFMob, IAAFCompositionMob > )
;
class_< IAAFMobSlotSP > ("IAAFMobSlotSP")
;
class_< IAAFNestedScopeSP > ("IAAFNestedScopeSP")
;
class_< IAAFNetworkLocatorSP > ("IAAFNetworkLocatorSP")
;
class_< IAAFObjectSP > ("IAAFObjectSP")
;
class_< IAAFParameterSP > ("IAAFParameterSP")
;
class_< IAAFParameterDefSP > ("IAAFParameterDefSP")
;
class_< IAAFPropertySP > ("IAAFPropertySP")
;
class_< IAAFPropertyDefSP > ("IAAFPropertyDefSP")
;
class_< IAAFPropertyValueSP > ("IAAFPropertyValueSP")
;
class_< IAAFPluginManagerSP > ("IAAFPluginManagerSP")
;
class_< IAAFPulldownSP > ("IAAFPulldownSP")
;
class_< IAAFRGBADescriptorSP > ("IAAFRGBADescriptorSP")
;
class_< IAAFScopeReferenceSP > ("IAAFScopeReferenceSP")
;
class_< IAAFSegmentSP > ("IAAFSegmentSP")
;
class_< IAAFSelectorSP > ("IAAFSelectorSP")
;
class_< IAAFSequenceSP > ("IAAFSequenceSP")
;
class_< IAAFSourceClipSP > ("IAAFSourceClipSP")
;
class_< IAAFSourceMobSP > ("IAAFSourceMobSP")
;
class_< IAAFSourceReferenceSP > ("IAAFSourceReferenceSP")
;
class_< IAAFStaticMobSlotSP > ("IAAFStaticMobSlotSP")
;
class_< IAAFTapeDescriptorSP > ("IAAFTapeDescriptorSP")
;
class_< IAAFTaggedValueSP > ("IAAFTaggedValueSP")
;
class_< IAAFTextLocatorSP > ("IAAFTextLocatorSP")
;
class_< IAAFTimecodeSP > ("IAAFTimecodeSP")
;
class_< IAAFTimelineMobSlotSP > ("IAAFTimelineMobSlotSP")
;
class_< IAAFTransitionSP > ("IAAFTransitionSP")
;
class_< IAAFTIFFDescriptorSP > ("IAAFTIFFDescriptorSP")
;
class_< IAAFTimecodeStreamSP > ("IAAFTimecodeStreamSP")
;
class_< IAAFTimecodeStream12MSP > ("IAAFTimecodeStream12MSP")
;
class_< IAAFTypeDefSP > ("IAAFTypeDefSP")
;
class_< IAAFTypeDefCharacterSP > ("IAAFTypeDefCharacterSP")
;
class_< IAAFTypeDefIndirectSP > ("IAAFTypeDefIndirectSP")
;
class_< IAAFTypeDefIntSP > ("IAAFTypeDefIntSP")
;
class_< IAAFTypeDefRenameSP > ("IAAFTypeDefRenameSP")
;
class_< IAAFTypeDefEnumSP > ("IAAFTypeDefEnumSP")
;
class_< IAAFTypeDefExtEnumSP > ("IAAFTypeDefExtEnumSP")
;
class_< IAAFTypeDefFixedArraySP > ("IAAFTypeDefFixedArraySP")
;
class_< IAAFTypeDefRecordSP > ("IAAFTypeDefRecordSP")
;
class_< IAAFTypeDefSetSP > ("IAAFTypeDefSetSP")
;
class_< IAAFTypeDefStreamSP > ("IAAFTypeDefStreamSP")
;
class_< IAAFTypeDefStringSP > ("IAAFTypeDefStringSP")
;
class_< IAAFTypeDefStrongObjRefSP > ("IAAFTypeDefStrongObjRefSP")
;
class_< IAAFTypeDefWeakObjRefSP > ("IAAFTypeDefWeakObjRefSP")
;
class_< IAAFTypeDefObjectRefSP > ("IAAFTypeDefObjectRefSP")
;
class_< IAAFTypeDefOpaqueSP > ("IAAFTypeDefOpaqueSP")
;
class_< IAAFTypeDefVariableArraySP > ("IAAFTypeDefVariableArraySP")
;
class_< IAAFVaryingValueSP > ("IAAFVaryingValueSP")
;
class_< IAAFWAVEDescriptorSP > ("IAAFWAVEDescriptorSP")
;
class_< IEnumAAFClassDefsSP > ("IEnumAAFClassDefsSP")
;
class_< IEnumAAFCodecDefsSP > ("IEnumAAFCodecDefsSP")
;
class_< IEnumAAFCodecFlavoursSP > ("IEnumAAFCodecFlavoursSP")
;
class_< IEnumAAFComponentsSP > ("IEnumAAFComponentsSP")
;
class_< IEnumAAFContainerDefsSP > ("IEnumAAFContainerDefsSP")
;
class_< IEnumAAFControlPointsSP > ("IEnumAAFControlPointsSP")
;
class_< IEnumAAFDataDefsSP > ("IEnumAAFDataDefsSP")
;
class_< IEnumAAFIdentificationsSP > ("IEnumAAFIdentificationsSP")
;
class_< IEnumAAFInterpolationDefsSP > ("IEnumAAFInterpolationDefsSP")
;
class_< IEnumAAFOperationDefsSP > ("IEnumAAFOperationDefsSP")
;
class_< IEnumAAFEssenceDataSP > ("IEnumAAFEssenceDataSP")
;
class_< IEnumAAFKLVDataSP > ("IEnumAAFKLVDataSP")
;
class_< IEnumAAFLoadedPluginsSP > ("IEnumAAFLoadedPluginsSP")
;
class_< IEnumAAFLocatorsSP > ("IEnumAAFLocatorsSP")
;
class_< IEnumAAFMobSlotsSP > ("IEnumAAFMobSlotsSP")
;
class_< IEnumAAFMobsSP > ("IEnumAAFMobsSP")
;
class_< IEnumAAFParameterDefsSP > ("IEnumAAFParameterDefsSP")
;
class_< IEnumAAFParametersSP > ("IEnumAAFParametersSP")
;
class_< IEnumAAFPropertiesSP > ("IEnumAAFPropertiesSP")
;
class_< IEnumAAFPropertyDefsSP > ("IEnumAAFPropertyDefsSP")
;
class_< IEnumAAFPropertyValuesSP > ("IEnumAAFPropertyValuesSP")
;
class_< IEnumAAFPluginDefsSP > ("IEnumAAFPluginDefsSP")
;
class_< IEnumAAFPluginLocatorsSP > ("IEnumAAFPluginLocatorsSP")
;
class_< IEnumAAFSegmentsSP > ("IEnumAAFSegmentsSP")
;
class_< IEnumAAFTaggedValuesSP > ("IEnumAAFTaggedValuesSP")
;
class_< IEnumAAFTypeDefsSP > ("IEnumAAFTypeDefsSP")
;
class_< IAAFRawStorageSP > ("IAAFRawStorageSP")
;
class_< IAAFRandomRawStorageSP > ("IAAFRandomRawStorageSP")
;
class_< IAAFGetFileBitsSP > ("IAAFGetFileBitsSP")
;
class_< IAAFSetFileBitsSP > ("IAAFSetFileBitsSP")
;
class_< IAAFRandomFileSP > ("IAAFRandomFileSP")
;
class_< IAAFEndianSP > ("IAAFEndianSP")
;
class_< IAAFSearchSourceSP > ("IAAFSearchSourceSP")
;
class_< IAAFEssenceMultiAccessSP > ("IAAFEssenceMultiAccessSP")
;
class_< IAAFTypeDefVariableArrayExSP > ("IAAFTypeDefVariableArrayExSP")
;
class_< IAAFAES3PCMDescriptorSP > ("IAAFAES3PCMDescriptorSP")
;
class_< IAAFAuxiliaryDescriptorSP > ("IAAFAuxiliaryDescriptorSP")
;
class_< IAAFComponent2SP > ("IAAFComponent2SP")
;
class_< IAAFDataDef2SP > ("IAAFDataDef2SP")
;
class_< IAAFDataDef3SP > ("IAAFDataDef3SP")
;
class_< IAAFDescriptiveFrameworkSP > ("IAAFDescriptiveFrameworkSP")
;
class_< IAAFDescriptiveMarkerSP > ("IAAFDescriptiveMarkerSP")
;
class_< IAAFDictionary2SP > ("IAAFDictionary2SP")
;
class_< IAAFHeader2SP > ("IAAFHeader2SP")
;
class_< IAAFImportDescriptorSP > ("IAAFImportDescriptorSP")
;
class_< IAAFKLVDataDefinitionSP > ("IAAFKLVDataDefinitionSP")
;
class_< IAAFMob2SP > ("IAAFMob2SP")
;
class_< IAAFMultipleDescriptorSP > ("IAAFMultipleDescriptorSP")
;
class_< IAAFPCMDescriptorSP > ("IAAFPCMDescriptorSP")
;
class_< IAAFPhysicalDescriptorSP > ("IAAFPhysicalDescriptorSP")
;
class_< IAAFRecordingDescriptorSP > ("IAAFRecordingDescriptorSP")
;
class_< IAAFRGBADescriptor2SP > ("IAAFRGBADescriptor2SP")
;
class_< IAAFSoundDescriptorSP > ("IAAFSoundDescriptorSP")
;
class_< IAAFTaggedValueDefinitionSP > ("IAAFTaggedValueDefinitionSP")
;
class_< IAAFTimelineMobSlot2SP > ("IAAFTimelineMobSlot2SP")
;
class_< IEnumAAFKLVDataDefsSP > ("IEnumAAFKLVDataDefsSP")
;
class_< IEnumAAFTaggedValueDefsSP > ("IEnumAAFTaggedValueDefsSP")
;
class_< IAAFBWFImportDescriptorSP > ("IAAFBWFImportDescriptorSP")
;
class_< IAAFDataEssenceDescriptorSP > ("IAAFDataEssenceDescriptorSP")
;
class_< IAAFDescriptiveClipSP > ("IAAFDescriptiveClipSP")
;
class_< IAAFDescriptiveObjectSP > ("IAAFDescriptiveObjectSP")
;
class_< IAAFMPEGVideoDescriptorSP > ("IAAFMPEGVideoDescriptorSP")
;
class_< IAAFRIFFChunkSP > ("IAAFRIFFChunkSP")
;
class_< IAAFPluginSP > ("IAAFPluginSP")
;
class_< IAAFClassExtensionSP > ("IAAFClassExtensionSP")
;
class_< IAAFEssenceStreamSP > ("IAAFEssenceStreamSP")
;
class_< IAAFEssenceDataStreamSP > ("IAAFEssenceDataStreamSP")
;
class_< IAAFEssenceCodecSP > ("IAAFEssenceCodecSP")
;
class_< IAAFMultiEssenceCodecSP > ("IAAFMultiEssenceCodecSP")
;
class_< IAAFEssenceContainerSP > ("IAAFEssenceContainerSP")
;
class_< IAAFInterpolatorSP > ("IAAFInterpolatorSP")
;
class_< IUnknownSP > ("IUnknownSP")
;
}

