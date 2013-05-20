
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
.def("to_DescriptiveMarkerSP", query_interface<IAAFCommentMarker, IAAFDescriptiveMarker > )
;
class_< IAAFComponentSP > ("IAAFComponentSP")
.def("to_TransitionSP", query_interface<IAAFComponent, IAAFTransition > )
.def("to_SegmentSP", query_interface<IAAFComponent, IAAFSegment > )
.def("to_TimecodeSP", query_interface<IAAFComponent, IAAFTimecode > )
.def("to_SourceReferenceSP", query_interface<IAAFComponent, IAAFSourceReference > )
.def("to_SourceClipSP", query_interface<IAAFComponent, IAAFSourceClip > )
.def("to_EventSP", query_interface<IAAFComponent, IAAFEvent > )
.def("to_CommentMarkerSP", query_interface<IAAFComponent, IAAFCommentMarker > )
.def("to_DescriptiveMarkerSP", query_interface<IAAFComponent, IAAFDescriptiveMarker > )
.def("to_GPITriggerSP", query_interface<IAAFComponent, IAAFGPITrigger > )
.def("to_TimecodeStreamSP", query_interface<IAAFComponent, IAAFTimecodeStream > )
.def("to_TimecodeStream12MSP", query_interface<IAAFComponent, IAAFTimecodeStream12M > )
.def("to_FillerSP", query_interface<IAAFComponent, IAAFFiller > )
.def("to_NestedScopeSP", query_interface<IAAFComponent, IAAFNestedScope > )
.def("to_PulldownSP", query_interface<IAAFComponent, IAAFPulldown > )
.def("to_SequenceSP", query_interface<IAAFComponent, IAAFSequence > )
.def("to_EssenceGroupSP", query_interface<IAAFComponent, IAAFEssenceGroup > )
.def("to_OperationGroupSP", query_interface<IAAFComponent, IAAFOperationGroup > )
.def("to_ScopeReferenceSP", query_interface<IAAFComponent, IAAFScopeReference > )
.def("to_SelectorSP", query_interface<IAAFComponent, IAAFSelector > )
.def("to_EdgecodeSP", query_interface<IAAFComponent, IAAFEdgecode > )
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
.def("to_KLVDataDefinitionSP", query_interface<IAAFDefObject, IAAFKLVDataDefinition > )
.def("to_CodecDefSP", query_interface<IAAFDefObject, IAAFCodecDef > )
.def("to_PluginDefSP", query_interface<IAAFDefObject, IAAFPluginDef > )
.def("to_ContainerDefSP", query_interface<IAAFDefObject, IAAFContainerDef > )
.def("to_InterpolationDefSP", query_interface<IAAFDefObject, IAAFInterpolationDef > )
.def("to_OperationDefSP", query_interface<IAAFDefObject, IAAFOperationDef > )
.def("to_DataDefSP", query_interface<IAAFDefObject, IAAFDataDef > )
.def("to_DataDef2SP", query_interface<IAAFDefObject, IAAFDataDef2 > )
.def("to_DataDef3SP", query_interface<IAAFDefObject, IAAFDataDef3 > )
.def("to_ParameterDefSP", query_interface<IAAFDefObject, IAAFParameterDef > )
.def("to_TaggedValueDefinitionSP", query_interface<IAAFDefObject, IAAFTaggedValueDefinition > )
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
.def("to_FileDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFFileDescriptor > )
.def("to_SoundDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFSoundDescriptor > )
.def("to_WAVEDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFWAVEDescriptor > )
.def("to_DigitalImageDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFDigitalImageDescriptor > )
.def("to_CDCIDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFCDCIDescriptor > )
.def("to_RGBADescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFRGBADescriptor > )
.def("to_PhysicalDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFPhysicalDescriptor > )
.def("to_ImportDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFImportDescriptor > )
.def("to_RecordingDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFRecordingDescriptor > )
.def("to_AuxiliaryDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFAuxiliaryDescriptor > )
.def("to_TapeDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFTapeDescriptor > )
.def("to_FilmDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFFilmDescriptor > )
;
class_< IAAFEventSP > ("IAAFEventSP")
.def("to_CommentMarkerSP", query_interface<IAAFEvent, IAAFCommentMarker > )
.def("to_DescriptiveMarkerSP", query_interface<IAAFEvent, IAAFDescriptiveMarker > )
.def("to_GPITriggerSP", query_interface<IAAFEvent, IAAFGPITrigger > )
.def("to_TimecodeStreamSP", query_interface<IAAFEvent, IAAFTimecodeStream > )
.def("to_TimecodeStream12MSP", query_interface<IAAFEvent, IAAFTimecodeStream12M > )
;
class_< IAAFEventMobSlotSP > ("IAAFEventMobSlotSP")
;
class_< IAAFFileSP > ("IAAFFileSP")
.def("to_RandomFileSP", query_interface<IAAFFile, IAAFRandomFile > )
;
class_< IAAFFileDescriptorSP > ("IAAFFileDescriptorSP")
.def("to_SoundDescriptorSP", query_interface<IAAFFileDescriptor, IAAFSoundDescriptor > )
.def("to_WAVEDescriptorSP", query_interface<IAAFFileDescriptor, IAAFWAVEDescriptor > )
.def("to_DigitalImageDescriptorSP", query_interface<IAAFFileDescriptor, IAAFDigitalImageDescriptor > )
.def("to_CDCIDescriptorSP", query_interface<IAAFFileDescriptor, IAAFCDCIDescriptor > )
.def("to_RGBADescriptorSP", query_interface<IAAFFileDescriptor, IAAFRGBADescriptor > )
;
class_< IAAFFilmDescriptorSP > ("IAAFFilmDescriptorSP")
;
class_< IAAFDigitalImageDescriptorSP > ("IAAFDigitalImageDescriptorSP")
.def("to_CDCIDescriptorSP", query_interface<IAAFDigitalImageDescriptor, IAAFCDCIDescriptor > )
.def("to_RGBADescriptorSP", query_interface<IAAFDigitalImageDescriptor, IAAFRGBADescriptor > )
.def("to_RGBADescriptor2SP", query_interface<IAAFDigitalImageDescriptor, IAAFRGBADescriptor2 > )
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
.def("to_NetworkLocatorSP", query_interface<IAAFLocator, IAAFNetworkLocator > )
;
class_< IAAFMasterMobSP > ("IAAFMasterMobSP")
.def("to_MasterMobExSP", query_interface<IAAFMasterMob, IAAFMasterMobEx > )
;
class_< IAAFMasterMob2SP > ("IAAFMasterMob2SP")
.def("to_MasterMobExSP", query_interface<IAAFMasterMob2, IAAFMasterMobEx > )
;
class_< IAAFMasterMobExSP > ("IAAFMasterMobExSP")
;
class_< IAAFMetaDefinitionSP > ("IAAFMetaDefinitionSP")
.def("to_ClassDefSP", query_interface<IAAFMetaDefinition, IAAFClassDef > )
.def("to_PropertyDefSP", query_interface<IAAFMetaDefinition, IAAFPropertyDef > )
.def("to_TypeDefSP", query_interface<IAAFMetaDefinition, IAAFTypeDef > )
.def("to_TypeDefObjectRefSP", query_interface<IAAFMetaDefinition, IAAFTypeDefObjectRef > )
.def("to_TypeDefRecordSP", query_interface<IAAFMetaDefinition, IAAFTypeDefRecord > )
.def("to_TypeDefVariableArraySP", query_interface<IAAFMetaDefinition, IAAFTypeDefVariableArray > )
.def("to_TypeDefFixedArraySP", query_interface<IAAFMetaDefinition, IAAFTypeDefFixedArray > )
.def("to_TypeDefStrongObjRefSP", query_interface<IAAFMetaDefinition, IAAFTypeDefStrongObjRef > )
.def("to_TypeDefVariableArrayExSP", query_interface<IAAFMetaDefinition, IAAFTypeDefVariableArrayEx > )
.def("to_TypeDefEnumSP", query_interface<IAAFMetaDefinition, IAAFTypeDefEnum > )
.def("to_TypeDefIndirectSP", query_interface<IAAFMetaDefinition, IAAFTypeDefIndirect > )
.def("to_TypeDefOpaqueSP", query_interface<IAAFMetaDefinition, IAAFTypeDefOpaque > )
.def("to_TypeDefIntSP", query_interface<IAAFMetaDefinition, IAAFTypeDefInt > )
.def("to_TypeDefRenameSP", query_interface<IAAFMetaDefinition, IAAFTypeDefRename > )
.def("to_TypeDefStringSP", query_interface<IAAFMetaDefinition, IAAFTypeDefString > )
.def("to_TypeDefSetSP", query_interface<IAAFMetaDefinition, IAAFTypeDefSet > )
.def("to_TypeDefWeakObjRefSP", query_interface<IAAFMetaDefinition, IAAFTypeDefWeakObjRef > )
.def("to_TypeDefExtEnumSP", query_interface<IAAFMetaDefinition, IAAFTypeDefExtEnum > )
.def("to_TypeDefStreamSP", query_interface<IAAFMetaDefinition, IAAFTypeDefStream > )
;
class_< IAAFMobSP > ("IAAFMobSP")
.def("to_MasterMobSP", query_interface<IAAFMob, IAAFMasterMob > )
.def("to_MasterMob2SP", query_interface<IAAFMob, IAAFMasterMob2 > )
.def("to_MasterMobExSP", query_interface<IAAFMob, IAAFMasterMobEx > )
.def("to_SourceMobSP", query_interface<IAAFMob, IAAFSourceMob > )
.def("to_CompositionMobSP", query_interface<IAAFMob, IAAFCompositionMob > )
.def("to_CompositionMob2SP", query_interface<IAAFMob, IAAFCompositionMob2 > )
;
class_< IAAFMobSlotSP > ("IAAFMobSlotSP")
.def("to_TimelineMobSlotSP", query_interface<IAAFMobSlot, IAAFTimelineMobSlot > )
.def("to_TimelineMobSlot2SP", query_interface<IAAFMobSlot, IAAFTimelineMobSlot2 > )
.def("to_StaticMobSlotSP", query_interface<IAAFMobSlot, IAAFStaticMobSlot > )
.def("to_EventMobSlotSP", query_interface<IAAFMobSlot, IAAFEventMobSlot > )
;
class_< IAAFNestedScopeSP > ("IAAFNestedScopeSP")
;
class_< IAAFNetworkLocatorSP > ("IAAFNetworkLocatorSP")
;
class_< IAAFObjectSP > ("IAAFObjectSP")
.def("to_ContentStorageSP", query_interface<IAAFObject, IAAFContentStorage > )
.def("to_LocatorSP", query_interface<IAAFObject, IAAFLocator > )
.def("to_NetworkLocatorSP", query_interface<IAAFObject, IAAFNetworkLocator > )
.def("to_HeaderSP", query_interface<IAAFObject, IAAFHeader > )
.def("to_Header2SP", query_interface<IAAFObject, IAAFHeader2 > )
.def("to_MobSP", query_interface<IAAFObject, IAAFMob > )
.def("to_Mob2SP", query_interface<IAAFObject, IAAFMob2 > )
.def("to_MasterMobSP", query_interface<IAAFObject, IAAFMasterMob > )
.def("to_MasterMobExSP", query_interface<IAAFObject, IAAFMasterMobEx > )
.def("to_SourceMobSP", query_interface<IAAFObject, IAAFSourceMob > )
.def("to_CompositionMobSP", query_interface<IAAFObject, IAAFCompositionMob > )
.def("to_EssenceDescriptorSP", query_interface<IAAFObject, IAAFEssenceDescriptor > )
.def("to_FileDescriptorSP", query_interface<IAAFObject, IAAFFileDescriptor > )
.def("to_SoundDescriptorSP", query_interface<IAAFObject, IAAFSoundDescriptor > )
.def("to_WAVEDescriptorSP", query_interface<IAAFObject, IAAFWAVEDescriptor > )
.def("to_DigitalImageDescriptorSP", query_interface<IAAFObject, IAAFDigitalImageDescriptor > )
.def("to_CDCIDescriptorSP", query_interface<IAAFObject, IAAFCDCIDescriptor > )
.def("to_RGBADescriptorSP", query_interface<IAAFObject, IAAFRGBADescriptor > )
.def("to_PhysicalDescriptorSP", query_interface<IAAFObject, IAAFPhysicalDescriptor > )
.def("to_ImportDescriptorSP", query_interface<IAAFObject, IAAFImportDescriptor > )
.def("to_RecordingDescriptorSP", query_interface<IAAFObject, IAAFRecordingDescriptor > )
.def("to_AuxiliaryDescriptorSP", query_interface<IAAFObject, IAAFAuxiliaryDescriptor > )
.def("to_TapeDescriptorSP", query_interface<IAAFObject, IAAFTapeDescriptor > )
.def("to_FilmDescriptorSP", query_interface<IAAFObject, IAAFFilmDescriptor > )
.def("to_DescriptiveFrameworkSP", query_interface<IAAFObject, IAAFDescriptiveFramework > )
.def("to_IdentificationSP", query_interface<IAAFObject, IAAFIdentification > )
.def("to_DictionarySP", query_interface<IAAFObject, IAAFDictionary > )
.def("to_Dictionary2SP", query_interface<IAAFObject, IAAFDictionary2 > )
.def("to_ParameterSP", query_interface<IAAFObject, IAAFParameter > )
.def("to_ControlPointSP", query_interface<IAAFObject, IAAFControlPoint > )
.def("to_VaryingValueSP", query_interface<IAAFObject, IAAFVaryingValue > )
.def("to_ConstantValueSP", query_interface<IAAFObject, IAAFConstantValue > )
.def("to_MobSlotSP", query_interface<IAAFObject, IAAFMobSlot > )
.def("to_TimelineMobSlotSP", query_interface<IAAFObject, IAAFTimelineMobSlot > )
.def("to_StaticMobSlotSP", query_interface<IAAFObject, IAAFStaticMobSlot > )
.def("to_EventMobSlotSP", query_interface<IAAFObject, IAAFEventMobSlot > )
.def("to_TaggedValueSP", query_interface<IAAFObject, IAAFTaggedValue > )
.def("to_DefObjectSP", query_interface<IAAFObject, IAAFDefObject > )
.def("to_KLVDataDefinitionSP", query_interface<IAAFObject, IAAFKLVDataDefinition > )
.def("to_CodecDefSP", query_interface<IAAFObject, IAAFCodecDef > )
.def("to_PluginDefSP", query_interface<IAAFObject, IAAFPluginDef > )
.def("to_ContainerDefSP", query_interface<IAAFObject, IAAFContainerDef > )
.def("to_InterpolationDefSP", query_interface<IAAFObject, IAAFInterpolationDef > )
.def("to_OperationDefSP", query_interface<IAAFObject, IAAFOperationDef > )
.def("to_DataDefSP", query_interface<IAAFObject, IAAFDataDef > )
.def("to_ParameterDefSP", query_interface<IAAFObject, IAAFParameterDef > )
.def("to_TaggedValueDefinitionSP", query_interface<IAAFObject, IAAFTaggedValueDefinition > )
.def("to_ComponentSP", query_interface<IAAFObject, IAAFComponent > )
.def("to_Component2SP", query_interface<IAAFObject, IAAFComponent2 > )
.def("to_TransitionSP", query_interface<IAAFObject, IAAFTransition > )
.def("to_SegmentSP", query_interface<IAAFObject, IAAFSegment > )
.def("to_TimecodeSP", query_interface<IAAFObject, IAAFTimecode > )
.def("to_SourceReferenceSP", query_interface<IAAFObject, IAAFSourceReference > )
.def("to_SourceClipSP", query_interface<IAAFObject, IAAFSourceClip > )
.def("to_EventSP", query_interface<IAAFObject, IAAFEvent > )
.def("to_CommentMarkerSP", query_interface<IAAFObject, IAAFCommentMarker > )
.def("to_DescriptiveMarkerSP", query_interface<IAAFObject, IAAFDescriptiveMarker > )
.def("to_GPITriggerSP", query_interface<IAAFObject, IAAFGPITrigger > )
.def("to_TimecodeStreamSP", query_interface<IAAFObject, IAAFTimecodeStream > )
.def("to_TimecodeStream12MSP", query_interface<IAAFObject, IAAFTimecodeStream12M > )
.def("to_FillerSP", query_interface<IAAFObject, IAAFFiller > )
.def("to_NestedScopeSP", query_interface<IAAFObject, IAAFNestedScope > )
.def("to_PulldownSP", query_interface<IAAFObject, IAAFPulldown > )
.def("to_SequenceSP", query_interface<IAAFObject, IAAFSequence > )
.def("to_EssenceGroupSP", query_interface<IAAFObject, IAAFEssenceGroup > )
.def("to_OperationGroupSP", query_interface<IAAFObject, IAAFOperationGroup > )
.def("to_ScopeReferenceSP", query_interface<IAAFObject, IAAFScopeReference > )
.def("to_SelectorSP", query_interface<IAAFObject, IAAFSelector > )
.def("to_EdgecodeSP", query_interface<IAAFObject, IAAFEdgecode > )
;
class_< IAAFParameterSP > ("IAAFParameterSP")
.def("to_ControlPointSP", query_interface<IAAFParameter, IAAFControlPoint > )
.def("to_VaryingValueSP", query_interface<IAAFParameter, IAAFVaryingValue > )
.def("to_ConstantValueSP", query_interface<IAAFParameter, IAAFConstantValue > )
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
.def("to_TimecodeSP", query_interface<IAAFSegment, IAAFTimecode > )
.def("to_SourceReferenceSP", query_interface<IAAFSegment, IAAFSourceReference > )
.def("to_SourceClipSP", query_interface<IAAFSegment, IAAFSourceClip > )
.def("to_EventSP", query_interface<IAAFSegment, IAAFEvent > )
.def("to_CommentMarkerSP", query_interface<IAAFSegment, IAAFCommentMarker > )
.def("to_DescriptiveMarkerSP", query_interface<IAAFSegment, IAAFDescriptiveMarker > )
.def("to_GPITriggerSP", query_interface<IAAFSegment, IAAFGPITrigger > )
.def("to_TimecodeStreamSP", query_interface<IAAFSegment, IAAFTimecodeStream > )
.def("to_TimecodeStream12MSP", query_interface<IAAFSegment, IAAFTimecodeStream12M > )
.def("to_FillerSP", query_interface<IAAFSegment, IAAFFiller > )
.def("to_NestedScopeSP", query_interface<IAAFSegment, IAAFNestedScope > )
.def("to_PulldownSP", query_interface<IAAFSegment, IAAFPulldown > )
.def("to_SequenceSP", query_interface<IAAFSegment, IAAFSequence > )
.def("to_EssenceGroupSP", query_interface<IAAFSegment, IAAFEssenceGroup > )
.def("to_OperationGroupSP", query_interface<IAAFSegment, IAAFOperationGroup > )
.def("to_ScopeReferenceSP", query_interface<IAAFSegment, IAAFScopeReference > )
.def("to_SelectorSP", query_interface<IAAFSegment, IAAFSelector > )
.def("to_EdgecodeSP", query_interface<IAAFSegment, IAAFEdgecode > )
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
.def("to_SourceClipSP", query_interface<IAAFSourceReference, IAAFSourceClip > )
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
.def("to_TimecodeStream12MSP", query_interface<IAAFTimecodeStream, IAAFTimecodeStream12M > )
;
class_< IAAFTimecodeStream12MSP > ("IAAFTimecodeStream12MSP")
;
class_< IAAFTypeDefSP > ("IAAFTypeDefSP")
.def("to_TypeDefObjectRefSP", query_interface<IAAFTypeDef, IAAFTypeDefObjectRef > )
.def("to_TypeDefRecordSP", query_interface<IAAFTypeDef, IAAFTypeDefRecord > )
.def("to_TypeDefVariableArraySP", query_interface<IAAFTypeDef, IAAFTypeDefVariableArray > )
.def("to_TypeDefFixedArraySP", query_interface<IAAFTypeDef, IAAFTypeDefFixedArray > )
.def("to_TypeDefStrongObjRefSP", query_interface<IAAFTypeDef, IAAFTypeDefStrongObjRef > )
.def("to_TypeDefVariableArrayExSP", query_interface<IAAFTypeDef, IAAFTypeDefVariableArrayEx > )
.def("to_TypeDefEnumSP", query_interface<IAAFTypeDef, IAAFTypeDefEnum > )
.def("to_TypeDefIndirectSP", query_interface<IAAFTypeDef, IAAFTypeDefIndirect > )
.def("to_TypeDefOpaqueSP", query_interface<IAAFTypeDef, IAAFTypeDefOpaque > )
.def("to_TypeDefIntSP", query_interface<IAAFTypeDef, IAAFTypeDefInt > )
.def("to_TypeDefRenameSP", query_interface<IAAFTypeDef, IAAFTypeDefRename > )
.def("to_TypeDefStringSP", query_interface<IAAFTypeDef, IAAFTypeDefString > )
.def("to_TypeDefSetSP", query_interface<IAAFTypeDef, IAAFTypeDefSet > )
.def("to_TypeDefWeakObjRefSP", query_interface<IAAFTypeDef, IAAFTypeDefWeakObjRef > )
.def("to_TypeDefExtEnumSP", query_interface<IAAFTypeDef, IAAFTypeDefExtEnum > )
.def("to_TypeDefStreamSP", query_interface<IAAFTypeDef, IAAFTypeDefStream > )
;
class_< IAAFTypeDefCharacterSP > ("IAAFTypeDefCharacterSP")
;
class_< IAAFTypeDefIndirectSP > ("IAAFTypeDefIndirectSP")
.def("to_TypeDefOpaqueSP", query_interface<IAAFTypeDefIndirect, IAAFTypeDefOpaque > )
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
.def("to_EssenceAccessSP", query_interface<IAAFEssenceMultiAccess, IAAFEssenceAccess > )
;
class_< IAAFTypeDefVariableArrayExSP > ("IAAFTypeDefVariableArrayExSP")
;
class_< IAAFAES3PCMDescriptorSP > ("IAAFAES3PCMDescriptorSP")
;
class_< IAAFAuxiliaryDescriptorSP > ("IAAFAuxiliaryDescriptorSP")
;
class_< IAAFComponent2SP > ("IAAFComponent2SP")
.def("to_TransitionSP", query_interface<IAAFComponent2, IAAFTransition > )
.def("to_SegmentSP", query_interface<IAAFComponent2, IAAFSegment > )
.def("to_TimecodeSP", query_interface<IAAFComponent2, IAAFTimecode > )
.def("to_SourceReferenceSP", query_interface<IAAFComponent2, IAAFSourceReference > )
.def("to_SourceClipSP", query_interface<IAAFComponent2, IAAFSourceClip > )
.def("to_EventSP", query_interface<IAAFComponent2, IAAFEvent > )
.def("to_CommentMarkerSP", query_interface<IAAFComponent2, IAAFCommentMarker > )
.def("to_DescriptiveMarkerSP", query_interface<IAAFComponent2, IAAFDescriptiveMarker > )
.def("to_GPITriggerSP", query_interface<IAAFComponent2, IAAFGPITrigger > )
.def("to_TimecodeStreamSP", query_interface<IAAFComponent2, IAAFTimecodeStream > )
.def("to_TimecodeStream12MSP", query_interface<IAAFComponent2, IAAFTimecodeStream12M > )
.def("to_FillerSP", query_interface<IAAFComponent2, IAAFFiller > )
.def("to_NestedScopeSP", query_interface<IAAFComponent2, IAAFNestedScope > )
.def("to_PulldownSP", query_interface<IAAFComponent2, IAAFPulldown > )
.def("to_SequenceSP", query_interface<IAAFComponent2, IAAFSequence > )
.def("to_EssenceGroupSP", query_interface<IAAFComponent2, IAAFEssenceGroup > )
.def("to_OperationGroupSP", query_interface<IAAFComponent2, IAAFOperationGroup > )
.def("to_ScopeReferenceSP", query_interface<IAAFComponent2, IAAFScopeReference > )
.def("to_SelectorSP", query_interface<IAAFComponent2, IAAFSelector > )
.def("to_EdgecodeSP", query_interface<IAAFComponent2, IAAFEdgecode > )
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
.def("to_MasterMobSP", query_interface<IAAFMob2, IAAFMasterMob > )
.def("to_MasterMob2SP", query_interface<IAAFMob2, IAAFMasterMob2 > )
.def("to_MasterMobExSP", query_interface<IAAFMob2, IAAFMasterMobEx > )
.def("to_SourceMobSP", query_interface<IAAFMob2, IAAFSourceMob > )
.def("to_CompositionMobSP", query_interface<IAAFMob2, IAAFCompositionMob > )
.def("to_CompositionMob2SP", query_interface<IAAFMob2, IAAFCompositionMob2 > )
;
class_< IAAFMultipleDescriptorSP > ("IAAFMultipleDescriptorSP")
;
class_< IAAFPCMDescriptorSP > ("IAAFPCMDescriptorSP")
;
class_< IAAFPhysicalDescriptorSP > ("IAAFPhysicalDescriptorSP")
.def("to_ImportDescriptorSP", query_interface<IAAFPhysicalDescriptor, IAAFImportDescriptor > )
.def("to_RecordingDescriptorSP", query_interface<IAAFPhysicalDescriptor, IAAFRecordingDescriptor > )
.def("to_AuxiliaryDescriptorSP", query_interface<IAAFPhysicalDescriptor, IAAFAuxiliaryDescriptor > )
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

