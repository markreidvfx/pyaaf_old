
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFPropertyDefs.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class PropertyDef {};


// Module ======================================================================
void Export_pyste_src_AAFPropertyDefs()
{

    scope PropertyDef_scope = class_<PropertyDef>("PropertyDef");
    PropertyDef_scope.attr("DigitalImageDescriptor_ColorPrimaries") = kAAFPropID_DigitalImageDescriptor_ColorPrimaries;
    PropertyDef_scope.attr("TypeDefinitionRename_RenamedType") = kAAFPropID_TypeDefinitionRename_RenamedType;
    PropertyDef_scope.attr("BWFImportDescriptor_QltyFileSecurityWave") = kAAFPropID_BWFImportDescriptor_QltyFileSecurityWave;
    PropertyDef_scope.attr("TimelineMobSlot_UserPos") = kAAFPropID_TimelineMobSlot_UserPos;
    PropertyDef_scope.attr("TapeDescriptor_TapeBatchNumber") = kAAFPropID_TapeDescriptor_TapeBatchNumber;
    PropertyDef_scope.attr("SourceMob_EssenceDescription") = kAAFPropID_SourceMob_EssenceDescription;
    PropertyDef_scope.attr("TapeDescriptor_TapeStock") = kAAFPropID_TapeDescriptor_TapeStock;
    PropertyDef_scope.attr("Dictionary_ContainerDefinitions") = kAAFPropID_Dictionary_ContainerDefinitions;
    PropertyDef_scope.attr("TimecodeStream_Source") = kAAFPropID_TimecodeStream_Source;
    PropertyDef_scope.attr("FileDescriptor_CodecDefinition") = kAAFPropID_FileDescriptor_CodecDefinition;
    PropertyDef_scope.attr("FileDescriptor_ContainerFormat") = kAAFPropID_FileDescriptor_ContainerFormat;
    PropertyDef_scope.attr("PCMDescriptor_BlockAlign") = kAAFPropID_PCMDescriptor_BlockAlign;
    PropertyDef_scope.attr("PropertyDefinition_Type") = kAAFPropID_PropertyDefinition_Type;
    PropertyDef_scope.attr("MPEGVideoDescriptor_ConstantBPictureCount") = kAAFPropID_MPEGVideoDescriptor_ConstantBPictureCount;
    PropertyDef_scope.attr("DigitalImageDescriptor_TransferCharacteristic") = kAAFPropID_DigitalImageDescriptor_TransferCharacteristic;
    PropertyDef_scope.attr("FileDescriptor_Length") = kAAFPropID_FileDescriptor_Length;
    PropertyDef_scope.attr("BWFImportDescriptor_QltyQualityParameter") = kAAFPropID_BWFImportDescriptor_QltyQualityParameter;
    PropertyDef_scope.attr("EventMobSlot_EditRate") = kAAFPropID_EventMobSlot_EditRate;
    PropertyDef_scope.attr("OperationDefinition_IsTimeWarp") = kAAFPropID_OperationDefinition_IsTimeWarp;
    PropertyDef_scope.attr("DescriptiveClip_DescribedSlotIDs") = kAAFPropID_DescriptiveClip_DescribedSlotIDs;
    PropertyDef_scope.attr("ParameterDefinition_Type") = kAAFPropID_ParameterDefinition_Type;
    PropertyDef_scope.attr("CodecDefinition_DataDefinitions") = kAAFPropID_CodecDefinition_DataDefinitions;
    PropertyDef_scope.attr("Identification_ToolkitVersion") = kAAFPropID_Identification_ToolkitVersion;
    PropertyDef_scope.attr("KLVDataDefinition_KLVDataType") = kAAFPropID_KLVDataDefinition_KLVDataType;
    PropertyDef_scope.attr("Pulldown_InputSegment") = kAAFPropID_Pulldown_InputSegment;
    PropertyDef_scope.attr("ContentStorage_Mobs") = kAAFPropID_ContentStorage_Mobs;
    PropertyDef_scope.attr("Pulldown_PulldownKind") = kAAFPropID_Pulldown_PulldownKind;
    PropertyDef_scope.attr("TypeDefinitionSet_ElementType") = kAAFPropID_TypeDefinitionSet_ElementType;
    PropertyDef_scope.attr("NestedScope_Slots") = kAAFPropID_NestedScope_Slots;
    PropertyDef_scope.attr("Header_ObjectModelVersion") = kAAFPropID_Header_ObjectModelVersion;
    PropertyDef_scope.attr("TypeDefinitionWeakObjectReference_TargetSet") = kAAFPropID_TypeDefinitionWeakObjectReference_TargetSet;
    PropertyDef_scope.attr("SoundDescriptor_ElectroSpatial") = kAAFPropID_SoundDescriptor_ElectroSpatial;
    PropertyDef_scope.attr("TypeDefinitionWeakObjectReference_ReferencedType") = kAAFPropID_TypeDefinitionWeakObjectReference_ReferencedType;
    PropertyDef_scope.attr("Component_DataDefinition") = kAAFPropID_Component_DataDefinition;
    PropertyDef_scope.attr("MPEGVideoDescriptor_IdenticalGOP") = kAAFPropID_MPEGVideoDescriptor_IdenticalGOP;
    PropertyDef_scope.attr("TypeDefinitionStrongObjectReference_ReferencedType") = kAAFPropID_TypeDefinitionStrongObjectReference_ReferencedType;
    PropertyDef_scope.attr("EventMobSlot_EventSlotOrigin") = kAAFPropID_EventMobSlot_EventSlotOrigin;
    PropertyDef_scope.attr("BWFImportDescriptor_QltyCueSheet") = kAAFPropID_BWFImportDescriptor_QltyCueSheet;
    PropertyDef_scope.attr("DigitalImageDescriptor_FieldEndOffset") = kAAFPropID_DigitalImageDescriptor_FieldEndOffset;
    PropertyDef_scope.attr("Mob_Slots") = kAAFPropID_Mob_Slots;
    PropertyDef_scope.attr("CompositionMob_DefFadeEditUnit") = kAAFPropID_CompositionMob_DefFadeEditUnit;
    PropertyDef_scope.attr("TIFFDescriptor_IsContiguous") = kAAFPropID_TIFFDescriptor_IsContiguous;
    PropertyDef_scope.attr("TapeDescriptor_ManufacturerID") = kAAFPropID_TapeDescriptor_ManufacturerID;
    PropertyDef_scope.attr("DigitalImageDescriptor_SignalStandard") = kAAFPropID_DigitalImageDescriptor_SignalStandard;
    PropertyDef_scope.attr("SourceClip_StartTime") = kAAFPropID_SourceClip_StartTime;
    PropertyDef_scope.attr("Dictionary_InterpolationDefinitions") = kAAFPropID_Dictionary_InterpolationDefinitions;
    PropertyDef_scope.attr("CDCIDescriptor_BlackReferenceLevel") = kAAFPropID_CDCIDescriptor_BlackReferenceLevel;
    PropertyDef_scope.attr("PluginDefinition_MinEngineVersion") = kAAFPropID_PluginDefinition_MinEngineVersion;
    PropertyDef_scope.attr("Header_LastModified") = kAAFPropID_Header_LastModified;
    PropertyDef_scope.attr("TIFFDescriptor_JPEGTableID") = kAAFPropID_TIFFDescriptor_JPEGTableID;
    PropertyDef_scope.attr("MPEGVideoDescriptor_LowDelay") = kAAFPropID_MPEGVideoDescriptor_LowDelay;
    PropertyDef_scope.attr("MPEGVideoDescriptor_ClosedGOP") = kAAFPropID_MPEGVideoDescriptor_ClosedGOP;
    PropertyDef_scope.attr("TypeDefinitionRecord_MemberTypes") = kAAFPropID_TypeDefinitionRecord_MemberTypes;
    PropertyDef_scope.attr("DigitalImageDescriptor_DisplayYOffset") = kAAFPropID_DigitalImageDescriptor_DisplayYOffset;
    PropertyDef_scope.attr("Dictionary_DataDefinitions") = kAAFPropID_Dictionary_DataDefinitions;
    PropertyDef_scope.attr("DigitalImageDescriptor_VideoLineMap") = kAAFPropID_DigitalImageDescriptor_VideoLineMap;
    PropertyDef_scope.attr("MobSlot_SlotID") = kAAFPropID_MobSlot_SlotID;
    PropertyDef_scope.attr("NetworkLocator_URLString") = kAAFPropID_NetworkLocator_URLString;
    PropertyDef_scope.attr("SourceReference_SourceMobSlotID") = kAAFPropID_SourceReference_SourceMobSlotID;
    PropertyDef_scope.attr("TapeDescriptor_FormFactor") = kAAFPropID_TapeDescriptor_FormFactor;
    PropertyDef_scope.attr("BWFImportDescriptor_QltyBasicData") = kAAFPropID_BWFImportDescriptor_QltyBasicData;
    PropertyDef_scope.attr("RIFFChunk_ChunkLength") = kAAFPropID_RIFFChunk_ChunkLength;
    PropertyDef_scope.attr("EssenceDescriptor_Locator") = kAAFPropID_EssenceDescriptor_Locator;
    PropertyDef_scope.attr("SourceClip_FadeOutLength") = kAAFPropID_SourceClip_FadeOutLength;
    PropertyDef_scope.attr("Dictionary_CodecDefinitions") = kAAFPropID_Dictionary_CodecDefinitions;
    PropertyDef_scope.attr("CDCIDescriptor_ColorRange") = kAAFPropID_CDCIDescriptor_ColorRange;
    PropertyDef_scope.attr("DigitalImageDescriptor_StoredWidth") = kAAFPropID_DigitalImageDescriptor_StoredWidth;
    PropertyDef_scope.attr("Dictionary_ParameterDefinitions") = kAAFPropID_Dictionary_ParameterDefinitions;
    PropertyDef_scope.attr("PluginDefinition_Accelerator") = kAAFPropID_PluginDefinition_Accelerator;
    PropertyDef_scope.attr("DigitalImageDescriptor_ActiveFormatDescriptor") = kAAFPropID_DigitalImageDescriptor_ActiveFormatDescriptor;
    PropertyDef_scope.attr("Parameter_Definition") = kAAFPropID_Parameter_Definition;
    PropertyDef_scope.attr("FilmDescriptor_FilmBatchNumber") = kAAFPropID_FilmDescriptor_FilmBatchNumber;
    PropertyDef_scope.attr("Component_Attributes") = kAAFPropID_Component_Attributes;
    PropertyDef_scope.attr("Pulldown_PhaseFrame") = kAAFPropID_Pulldown_PhaseFrame;
    PropertyDef_scope.attr("TimelineMobSlot_EditRate") = kAAFPropID_TimelineMobSlot_EditRate;
    PropertyDef_scope.attr("TimelineMobSlot_Origin") = kAAFPropID_TimelineMobSlot_Origin;
    PropertyDef_scope.attr("SoundDescriptor_Locked") = kAAFPropID_SoundDescriptor_Locked;
    PropertyDef_scope.attr("EdgeCode_Header") = kAAFPropID_EdgeCode_Header;
    PropertyDef_scope.attr("TaggedValue_Value") = kAAFPropID_TaggedValue_Value;
    PropertyDef_scope.attr("EdgeCode_FilmKind") = kAAFPropID_EdgeCode_FilmKind;
    PropertyDef_scope.attr("Event_Comment") = kAAFPropID_Event_Comment;
    PropertyDef_scope.attr("GPITrigger_ActiveState") = kAAFPropID_GPITrigger_ActiveState;
    PropertyDef_scope.attr("SoundDescriptor_AudioSamplingRate") = kAAFPropID_SoundDescriptor_AudioSamplingRate;
    PropertyDef_scope.attr("Header_DescriptiveSchemes") = kAAFPropID_Header_DescriptiveSchemes;
    PropertyDef_scope.attr("PCMDescriptor_AverageBPS") = kAAFPropID_PCMDescriptor_AverageBPS;
    PropertyDef_scope.attr("OperationGroup_Parameters") = kAAFPropID_OperationGroup_Parameters;
    PropertyDef_scope.attr("PCMDescriptor_PeakOfPeaksPosition") = kAAFPropID_PCMDescriptor_PeakOfPeaksPosition;
    PropertyDef_scope.attr("TIFFDescriptor_Summary") = kAAFPropID_TIFFDescriptor_Summary;
    PropertyDef_scope.attr("FilmDescriptor_FilmFormat") = kAAFPropID_FilmDescriptor_FilmFormat;
    PropertyDef_scope.attr("Root_Header") = kAAFPropID_Root_Header;
    PropertyDef_scope.attr("MPEGVideoDescriptor_ProfileAndLevel") = kAAFPropID_MPEGVideoDescriptor_ProfileAndLevel;
    PropertyDef_scope.attr("PluginDefinition_SoftwareOnly") = kAAFPropID_PluginDefinition_SoftwareOnly;
    PropertyDef_scope.attr("TypeDefinitionVariableArray_ElementType") = kAAFPropID_TypeDefinitionVariableArray_ElementType;
    PropertyDef_scope.attr("PluginDefinition_MaxEngineVersion") = kAAFPropID_PluginDefinition_MaxEngineVersion;
    PropertyDef_scope.attr("PluginDefinition_MinPlatformVersion") = kAAFPropID_PluginDefinition_MinPlatformVersion;
    PropertyDef_scope.attr("EssenceGroup_Choices") = kAAFPropID_EssenceGroup_Choices;
    PropertyDef_scope.attr("SoundDescriptor_DialNorm") = kAAFPropID_SoundDescriptor_DialNorm;
    PropertyDef_scope.attr("Transition_CutPoint") = kAAFPropID_Transition_CutPoint;
    PropertyDef_scope.attr("EssenceGroup_StillFrame") = kAAFPropID_EssenceGroup_StillFrame;
    PropertyDef_scope.attr("TimecodeStream_SampleRate") = kAAFPropID_TimecodeStream_SampleRate;
    PropertyDef_scope.attr("HTMLClip_BeginAnchor") = kAAFPropID_HTMLClip_BeginAnchor;
    PropertyDef_scope.attr("PropertyDefinition_IsUniqueIdentifier") = kAAFPropID_PropertyDefinition_IsUniqueIdentifier;
    PropertyDef_scope.attr("TapeDescriptor_Length") = kAAFPropID_TapeDescriptor_Length;
    PropertyDef_scope.attr("FilmDescriptor_FilmGaugeFormat") = kAAFPropID_FilmDescriptor_FilmGaugeFormat;
    PropertyDef_scope.attr("RGBADescriptor_ScanningDirection") = kAAFPropID_RGBADescriptor_ScanningDirection;
    PropertyDef_scope.attr("ControlPoint_EditHint") = kAAFPropID_ControlPoint_EditHint;
    PropertyDef_scope.attr("DigitalImageDescriptor_FieldDominance") = kAAFPropID_DigitalImageDescriptor_FieldDominance;
    PropertyDef_scope.attr("InterchangeObject_ObjClass") = kAAFPropID_InterchangeObject_ObjClass;
    PropertyDef_scope.attr("PropertyDefinition_LocalIdentification") = kAAFPropID_PropertyDefinition_LocalIdentification;
    PropertyDef_scope.attr("HTMLClip_EndAnchor") = kAAFPropID_HTMLClip_EndAnchor;
    PropertyDef_scope.attr("SoundDescriptor_QuantizationBits") = kAAFPropID_SoundDescriptor_QuantizationBits;
    PropertyDef_scope.attr("Header_IdentificationList") = kAAFPropID_Header_IdentificationList;
    PropertyDef_scope.attr("OperationGroup_Operation") = kAAFPropID_OperationGroup_Operation;
    PropertyDef_scope.attr("DefinitionObject_Identification") = kAAFPropID_DefinitionObject_Identification;
    PropertyDef_scope.attr("MPEGVideoDescriptor_MaxBPictureCount") = kAAFPropID_MPEGVideoDescriptor_MaxBPictureCount;
    PropertyDef_scope.attr("PCMDescriptor_PeakEnvelopeBlockSize") = kAAFPropID_PCMDescriptor_PeakEnvelopeBlockSize;
    PropertyDef_scope.attr("AES3PCMDescriptor_BlockStartOffset") = kAAFPropID_AES3PCMDescriptor_BlockStartOffset;
    PropertyDef_scope.attr("FilmDescriptor_FrameRate") = kAAFPropID_FilmDescriptor_FrameRate;
    PropertyDef_scope.attr("MetaDictionary_TypeDefinitions") = kAAFPropID_MetaDictionary_TypeDefinitions;
    PropertyDef_scope.attr("AES3PCMDescriptor_AuxBitsMode") = kAAFPropID_AES3PCMDescriptor_AuxBitsMode;
    PropertyDef_scope.attr("Root_MetaDictionary") = kAAFPropID_Root_MetaDictionary;
    PropertyDef_scope.attr("Component_UserComments") = kAAFPropID_Component_UserComments;
    PropertyDef_scope.attr("PluginDefinition_ManufacturerID") = kAAFPropID_PluginDefinition_ManufacturerID;
    PropertyDef_scope.attr("Transition_OperationGroup") = kAAFPropID_Transition_OperationGroup;
    PropertyDef_scope.attr("SourceReference_SourceID") = kAAFPropID_SourceReference_SourceID;
    PropertyDef_scope.attr("MetaDictionary_ClassDefinitions") = kAAFPropID_MetaDictionary_ClassDefinitions;
    PropertyDef_scope.attr("DescriptiveMarker_DescribedSlots") = kAAFPropID_DescriptiveMarker_DescribedSlots;
    PropertyDef_scope.attr("CDCIDescriptor_WhiteReferenceLevel") = kAAFPropID_CDCIDescriptor_WhiteReferenceLevel;
    PropertyDef_scope.attr("DigitalImageDescriptor_DisplayWidth") = kAAFPropID_DigitalImageDescriptor_DisplayWidth;
    PropertyDef_scope.attr("CDCIDescriptor_ReversedByteOrder") = kAAFPropID_CDCIDescriptor_ReversedByteOrder;
    PropertyDef_scope.attr("BWFImportDescriptor_BextCodingHistory") = kAAFPropID_BWFImportDescriptor_BextCodingHistory;
    PropertyDef_scope.attr("TypeDefinitionInteger_IsSigned") = kAAFPropID_TypeDefinitionInteger_IsSigned;
    PropertyDef_scope.attr("Mob_UserComments") = kAAFPropID_Mob_UserComments;
    PropertyDef_scope.attr("TimelineMobSlot_MarkOut") = kAAFPropID_TimelineMobSlot_MarkOut;
    PropertyDef_scope.attr("Identification_CompanyName") = kAAFPropID_Identification_CompanyName;
    PropertyDef_scope.attr("DigitalImageDescriptor_SampledYOffset") = kAAFPropID_DigitalImageDescriptor_SampledYOffset;
    PropertyDef_scope.attr("PCMDescriptor_PeakChannels") = kAAFPropID_PCMDescriptor_PeakChannels;
    PropertyDef_scope.attr("FilmDescriptor_FilmAspectRatio") = kAAFPropID_FilmDescriptor_FilmAspectRatio;
    PropertyDef_scope.attr("DigitalImageDescriptor_SampledWidth") = kAAFPropID_DigitalImageDescriptor_SampledWidth;
    PropertyDef_scope.attr("MobSlot_PhysicalTrackNumber") = kAAFPropID_MobSlot_PhysicalTrackNumber;
    PropertyDef_scope.attr("DigitalImageDescriptor_DisplayHeight") = kAAFPropID_DigitalImageDescriptor_DisplayHeight;
    PropertyDef_scope.attr("PluginDefinition_PluginCategory") = kAAFPropID_PluginDefinition_PluginCategory;
    PropertyDef_scope.attr("EdgeCode_Start") = kAAFPropID_EdgeCode_Start;
    PropertyDef_scope.attr("FileDescriptor_LinkedSlotID") = kAAFPropID_FileDescriptor_LinkedSlotID;
    PropertyDef_scope.attr("PluginDefinition_Locators") = kAAFPropID_PluginDefinition_Locators;
    PropertyDef_scope.attr("ControlPoint_Value") = kAAFPropID_ControlPoint_Value;
    PropertyDef_scope.attr("VaryingValue_Interpolation") = kAAFPropID_VaryingValue_Interpolation;
    PropertyDef_scope.attr("RGBADescriptor_AlphaMinRef") = kAAFPropID_RGBADescriptor_AlphaMinRef;
    PropertyDef_scope.attr("SoundDescriptor_Compression") = kAAFPropID_SoundDescriptor_Compression;
    PropertyDef_scope.attr("Mob_UsageCode") = kAAFPropID_Mob_UsageCode;
    PropertyDef_scope.attr("TypeDefinitionString_ElementType") = kAAFPropID_TypeDefinitionString_ElementType;
    PropertyDef_scope.attr("TypeDefinitionRecord_MemberNames") = kAAFPropID_TypeDefinitionRecord_MemberNames;
    PropertyDef_scope.attr("DigitalImageDescriptor_ImageAspectRatio") = kAAFPropID_DigitalImageDescriptor_ImageAspectRatio;
    PropertyDef_scope.attr("MPEGVideoDescriptor_MaxGOP") = kAAFPropID_MPEGVideoDescriptor_MaxGOP;
    PropertyDef_scope.attr("SoundDescriptor_Channels") = kAAFPropID_SoundDescriptor_Channels;
    PropertyDef_scope.attr("TypeDefinitionExtendibleEnumeration_ElementValues") = kAAFPropID_TypeDefinitionExtendibleEnumeration_ElementValues;
    PropertyDef_scope.attr("TIFFDescriptor_TrailingLines") = kAAFPropID_TIFFDescriptor_TrailingLines;
    PropertyDef_scope.attr("CDCIDescriptor_PaddingBits") = kAAFPropID_CDCIDescriptor_PaddingBits;
    PropertyDef_scope.attr("ContainerDefinition_EssenceIsIdentified") = kAAFPropID_ContainerDefinition_EssenceIsIdentified;
    PropertyDef_scope.attr("Mob_Attributes") = kAAFPropID_Mob_Attributes;
    PropertyDef_scope.attr("Identification_GenerationAUID") = kAAFPropID_Identification_GenerationAUID;
    PropertyDef_scope.attr("EssenceData_SampleIndex") = kAAFPropID_EssenceData_SampleIndex;
    PropertyDef_scope.attr("EdgeCode_CodeFormat") = kAAFPropID_EdgeCode_CodeFormat;
    PropertyDef_scope.attr("PluginDefinition_Engine") = kAAFPropID_PluginDefinition_Engine;
    PropertyDef_scope.attr("PluginDefinition_ManufacturerInfo") = kAAFPropID_PluginDefinition_ManufacturerInfo;
    PropertyDef_scope.attr("Header_OperationalPattern") = kAAFPropID_Header_OperationalPattern;
    PropertyDef_scope.attr("DigitalImageDescriptor_AlphaTransparency") = kAAFPropID_DigitalImageDescriptor_AlphaTransparency;
    PropertyDef_scope.attr("PluginDefinition_MaxPluginAPI") = kAAFPropID_PluginDefinition_MaxPluginAPI;
    PropertyDef_scope.attr("DigitalImageDescriptor_CodingEquations") = kAAFPropID_DigitalImageDescriptor_CodingEquations;
    PropertyDef_scope.attr("DigitalImageDescriptor_StoredHeight") = kAAFPropID_DigitalImageDescriptor_StoredHeight;
    PropertyDef_scope.attr("FileDescriptor_SampleRate") = kAAFPropID_FileDescriptor_SampleRate;
    PropertyDef_scope.attr("PluginDefinition_MinPluginAPI") = kAAFPropID_PluginDefinition_MinPluginAPI;
    PropertyDef_scope.attr("SourceClip_FadeOutType") = kAAFPropID_SourceClip_FadeOutType;
    PropertyDef_scope.attr("DigitalImageDescriptor_SampledHeight") = kAAFPropID_DigitalImageDescriptor_SampledHeight;
    PropertyDef_scope.attr("PluginDefinition_MaxPlatformVersion") = kAAFPropID_PluginDefinition_MaxPlatformVersion;
    PropertyDef_scope.attr("PluginDefinition_VersionString") = kAAFPropID_PluginDefinition_VersionString;
    PropertyDef_scope.attr("ScopeReference_RelativeScope") = kAAFPropID_ScopeReference_RelativeScope;
    PropertyDef_scope.attr("TextLocator_Name") = kAAFPropID_TextLocator_Name;
    PropertyDef_scope.attr("AES3PCMDescriptor_ChannelStatusMode") = kAAFPropID_AES3PCMDescriptor_ChannelStatusMode;
    PropertyDef_scope.attr("TimecodeStream_SourceType") = kAAFPropID_TimecodeStream_SourceType;
    PropertyDef_scope.attr("CDCIDescriptor_ColorSiting") = kAAFPropID_CDCIDescriptor_ColorSiting;
    PropertyDef_scope.attr("PluginDefinition_VersionNumber") = kAAFPropID_PluginDefinition_VersionNumber;
    PropertyDef_scope.attr("TypeDefinitionInteger_Size") = kAAFPropID_TypeDefinitionInteger_Size;
    PropertyDef_scope.attr("Pulldown_PulldownDirection") = kAAFPropID_Pulldown_PulldownDirection;
    PropertyDef_scope.attr("Mob_Name") = kAAFPropID_Mob_Name;
    PropertyDef_scope.attr("SourceClip_FadeInLength") = kAAFPropID_SourceClip_FadeInLength;
    PropertyDef_scope.attr("MetaDefinition_Name") = kAAFPropID_MetaDefinition_Name;
    PropertyDef_scope.attr("Component_KLVData") = kAAFPropID_Component_KLVData;
    PropertyDef_scope.attr("FilmDescriptor_Model") = kAAFPropID_FilmDescriptor_Model;
    PropertyDef_scope.attr("BWFImportDescriptor_QltyEndOfModulation") = kAAFPropID_BWFImportDescriptor_QltyEndOfModulation;
    PropertyDef_scope.attr("ConstantValue_Value") = kAAFPropID_ConstantValue_Value;
    PropertyDef_scope.attr("CompositionMob_DefaultFadeLength") = kAAFPropID_CompositionMob_DefaultFadeLength;
    PropertyDef_scope.attr("InterchangeObject_Generation") = kAAFPropID_InterchangeObject_Generation;
    PropertyDef_scope.attr("Header_Content") = kAAFPropID_Header_Content;
    PropertyDef_scope.attr("CommentMarker_Annotation") = kAAFPropID_CommentMarker_Annotation;
    PropertyDef_scope.attr("MobSlot_SlotName") = kAAFPropID_MobSlot_SlotName;
    PropertyDef_scope.attr("Identification_ProductName") = kAAFPropID_Identification_ProductName;
    PropertyDef_scope.attr("TypeDefinitionExtendibleEnumeration_ElementNames") = kAAFPropID_TypeDefinitionExtendibleEnumeration_ElementNames;
    PropertyDef_scope.attr("OperationGroup_Rendering") = kAAFPropID_OperationGroup_Rendering;
    PropertyDef_scope.attr("AES3PCMDescriptor_UserDataMode") = kAAFPropID_AES3PCMDescriptor_UserDataMode;
    PropertyDef_scope.attr("SourceReference_MonoSourceSlotIDs") = kAAFPropID_SourceReference_MonoSourceSlotIDs;
    PropertyDef_scope.attr("RIFFChunk_ChunkData") = kAAFPropID_RIFFChunk_ChunkData;
    PropertyDef_scope.attr("PCMDescriptor_PeakEnvelopeData") = kAAFPropID_PCMDescriptor_PeakEnvelopeData;
    PropertyDef_scope.attr("MPEGVideoDescriptor_CodedContentScanning") = kAAFPropID_MPEGVideoDescriptor_CodedContentScanning;
    PropertyDef_scope.attr("AuxiliaryDescriptor_MimeType") = kAAFPropID_AuxiliaryDescriptor_MimeType;
    PropertyDef_scope.attr("AES3PCMDescriptor_FixedChannelStatusData") = kAAFPropID_AES3PCMDescriptor_FixedChannelStatusData;
    PropertyDef_scope.attr("CompositionMob_DefFadeType") = kAAFPropID_CompositionMob_DefFadeType;
    PropertyDef_scope.attr("DigitalImageDescriptor_DisplayF2Offset") = kAAFPropID_DigitalImageDescriptor_DisplayF2Offset;
    PropertyDef_scope.attr("Dictionary_TaggedValueDefinitions") = kAAFPropID_Dictionary_TaggedValueDefinitions;
    PropertyDef_scope.attr("TapeDescriptor_TapeFormat") = kAAFPropID_TapeDescriptor_TapeFormat;
    PropertyDef_scope.attr("DigitalImageDescriptor_FieldStartOffset") = kAAFPropID_DigitalImageDescriptor_FieldStartOffset;
    PropertyDef_scope.attr("RGBADescriptor_ComponentMaxRef") = kAAFPropID_RGBADescriptor_ComponentMaxRef;
    PropertyDef_scope.attr("PluginDefinition_PluginAPI") = kAAFPropID_PluginDefinition_PluginAPI;
    PropertyDef_scope.attr("PluginDefinition_Authentication") = kAAFPropID_PluginDefinition_Authentication;
    PropertyDef_scope.attr("OperationDefinition_Bypass") = kAAFPropID_OperationDefinition_Bypass;
    PropertyDef_scope.attr("CodecDefinition_FileDescriptorClass") = kAAFPropID_CodecDefinition_FileDescriptorClass;
    PropertyDef_scope.attr("TapeDescriptor_Model") = kAAFPropID_TapeDescriptor_Model;
    PropertyDef_scope.attr("PCMDescriptor_PointsPerPeakValue") = kAAFPropID_PCMDescriptor_PointsPerPeakValue;
    PropertyDef_scope.attr("BWFImportDescriptor_QltyOperatorComment") = kAAFPropID_BWFImportDescriptor_QltyOperatorComment;
    PropertyDef_scope.attr("Timecode_Drop") = kAAFPropID_Timecode_Drop;
    PropertyDef_scope.attr("Identification_Date") = kAAFPropID_Identification_Date;
    PropertyDef_scope.attr("Selector_Alternates") = kAAFPropID_Selector_Alternates;
    PropertyDef_scope.attr("EssenceData_Data") = kAAFPropID_EssenceData_Data;
    PropertyDef_scope.attr("Mob_KLVData") = kAAFPropID_Mob_KLVData;
    PropertyDef_scope.attr("CompositionMob_Rendering") = kAAFPropID_CompositionMob_Rendering;
    PropertyDef_scope.attr("OperationGroup_InputSegments") = kAAFPropID_OperationGroup_InputSegments;
    PropertyDef_scope.attr("TimecodeStream12M_IncludeSync") = kAAFPropID_TimecodeStream12M_IncludeSync;
    PropertyDef_scope.attr("ControlPoint_Time") = kAAFPropID_ControlPoint_Time;
    PropertyDef_scope.attr("Sequence_Components") = kAAFPropID_Sequence_Components;
    PropertyDef_scope.attr("CDCIDescriptor_VerticalSubsampling") = kAAFPropID_CDCIDescriptor_VerticalSubsampling;
    PropertyDef_scope.attr("BWFImportDescriptor_UnknownBWFChunks") = kAAFPropID_BWFImportDescriptor_UnknownBWFChunks;
    PropertyDef_scope.attr("KLVData_Value") = kAAFPropID_KLVData_Value;
    PropertyDef_scope.attr("TimelineMobSlot_MarkIn") = kAAFPropID_TimelineMobSlot_MarkIn;
    PropertyDef_scope.attr("MPEGVideoDescriptor_SingleSequence") = kAAFPropID_MPEGVideoDescriptor_SingleSequence;
    PropertyDef_scope.attr("ClassDefinition_ParentClass") = kAAFPropID_ClassDefinition_ParentClass;
    PropertyDef_scope.attr("WAVEDescriptor_Summary") = kAAFPropID_WAVEDescriptor_Summary;
    PropertyDef_scope.attr("Dictionary_PluginDefinitions") = kAAFPropID_Dictionary_PluginDefinitions;
    PropertyDef_scope.attr("Selector_Selected") = kAAFPropID_Selector_Selected;
    PropertyDef_scope.attr("ContentStorage_EssenceData") = kAAFPropID_ContentStorage_EssenceData;
    PropertyDef_scope.attr("DigitalImageDescriptor_StoredF2Offset") = kAAFPropID_DigitalImageDescriptor_StoredF2Offset;
    PropertyDef_scope.attr("MobSlot_Segment") = kAAFPropID_MobSlot_Segment;
    PropertyDef_scope.attr("DigitalImageDescriptor_FrameLayout") = kAAFPropID_DigitalImageDescriptor_FrameLayout;
    PropertyDef_scope.attr("DigitalImageDescriptor_Compression") = kAAFPropID_DigitalImageDescriptor_Compression;
    PropertyDef_scope.attr("RGBADescriptor_ComponentMinRef") = kAAFPropID_RGBADescriptor_ComponentMinRef;
    PropertyDef_scope.attr("Identification_ProductVersion") = kAAFPropID_Identification_ProductVersion;
    PropertyDef_scope.attr("TypeDefinitionEnumeration_ElementValues") = kAAFPropID_TypeDefinitionEnumeration_ElementValues;
    PropertyDef_scope.attr("TypeDefinitionEnumeration_ElementType") = kAAFPropID_TypeDefinitionEnumeration_ElementType;
    PropertyDef_scope.attr("OperationDefinition_ParametersDefined") = kAAFPropID_OperationDefinition_ParametersDefined;
    PropertyDef_scope.attr("PluginDefinition_Platform") = kAAFPropID_PluginDefinition_Platform;
    PropertyDef_scope.attr("Dictionary_OperationDefinitions") = kAAFPropID_Dictionary_OperationDefinitions;
    PropertyDef_scope.attr("PCMDescriptor_PeakEnvelopeTimestamp") = kAAFPropID_PCMDescriptor_PeakEnvelopeTimestamp;
    PropertyDef_scope.attr("Mob_LastModified") = kAAFPropID_Mob_LastModified;
    PropertyDef_scope.attr("SoundDescriptor_AudioRefLevel") = kAAFPropID_SoundDescriptor_AudioRefLevel;
    PropertyDef_scope.attr("DigitalImageDescriptor_SampledXOffset") = kAAFPropID_DigitalImageDescriptor_SampledXOffset;
    PropertyDef_scope.attr("DataEssenceDescriptor_DataEssenceCoding") = kAAFPropID_DataEssenceDescriptor_DataEssenceCoding;
    PropertyDef_scope.attr("TypeDefinitionFixedArray_ElementCount") = kAAFPropID_TypeDefinitionFixedArray_ElementCount;
    PropertyDef_scope.attr("Header_Dictionary") = kAAFPropID_Header_Dictionary;
    PropertyDef_scope.attr("EssenceData_MobID") = kAAFPropID_EssenceData_MobID;
    PropertyDef_scope.attr("ClassDefinition_Properties") = kAAFPropID_ClassDefinition_Properties;
    PropertyDef_scope.attr("PCMDescriptor_PeakFrames") = kAAFPropID_PCMDescriptor_PeakFrames;
    PropertyDef_scope.attr("OperationDefinition_DataDefinition") = kAAFPropID_OperationDefinition_DataDefinition;
    PropertyDef_scope.attr("DigitalImageDescriptor_ImageAlignmentFactor") = kAAFPropID_DigitalImageDescriptor_ImageAlignmentFactor;
    PropertyDef_scope.attr("Identification_ProductVersionString") = kAAFPropID_Identification_ProductVersionString;
    PropertyDef_scope.attr("OperationDefinition_DegradeTo") = kAAFPropID_OperationDefinition_DegradeTo;
    PropertyDef_scope.attr("Timecode_FPS") = kAAFPropID_Timecode_FPS;
    PropertyDef_scope.attr("ClassDefinition_IsConcrete") = kAAFPropID_ClassDefinition_IsConcrete;
    PropertyDef_scope.attr("AES3PCMDescriptor_FixedUserData") = kAAFPropID_AES3PCMDescriptor_FixedUserData;
    PropertyDef_scope.attr("RIFFChunk_ChunkID") = kAAFPropID_RIFFChunk_ChunkID;
    PropertyDef_scope.attr("Header_EssenceContainers") = kAAFPropID_Header_EssenceContainers;
    PropertyDef_scope.attr("Mob_MobID") = kAAFPropID_Mob_MobID;
    PropertyDef_scope.attr("CDCIDescriptor_AlphaSamplingWidth") = kAAFPropID_CDCIDescriptor_AlphaSamplingWidth;
    PropertyDef_scope.attr("PCMDescriptor_SequenceOffset") = kAAFPropID_PCMDescriptor_SequenceOffset;
    PropertyDef_scope.attr("RGBADescriptor_PixelLayout") = kAAFPropID_RGBADescriptor_PixelLayout;
    PropertyDef_scope.attr("OperationDefinition_OperationCategory") = kAAFPropID_OperationDefinition_OperationCategory;
    PropertyDef_scope.attr("BWFImportDescriptor_QltyStartOfModulation") = kAAFPropID_BWFImportDescriptor_QltyStartOfModulation;
    PropertyDef_scope.attr("Timecode_Start") = kAAFPropID_Timecode_Start;
    PropertyDef_scope.attr("SourceClip_FadeInType") = kAAFPropID_SourceClip_FadeInType;
    PropertyDef_scope.attr("MetaDefinition_Description") = kAAFPropID_MetaDefinition_Description;
    PropertyDef_scope.attr("OperationGroup_BypassOverride") = kAAFPropID_OperationGroup_BypassOverride;
    PropertyDef_scope.attr("Identification_Platform") = kAAFPropID_Identification_Platform;
    PropertyDef_scope.attr("TypeDefinitionFixedArray_ElementType") = kAAFPropID_TypeDefinitionFixedArray_ElementType;
    PropertyDef_scope.attr("Header_ByteOrder") = kAAFPropID_Header_ByteOrder;
    PropertyDef_scope.attr("Mob_CreationTime") = kAAFPropID_Mob_CreationTime;
    PropertyDef_scope.attr("TaggedValue_Name") = kAAFPropID_TaggedValue_Name;
    PropertyDef_scope.attr("RGBADescriptor_PaletteLayout") = kAAFPropID_RGBADescriptor_PaletteLayout;
    PropertyDef_scope.attr("Header_Version") = kAAFPropID_Header_Version;
    PropertyDef_scope.attr("CDCIDescriptor_HorizontalSubsampling") = kAAFPropID_CDCIDescriptor_HorizontalSubsampling;
    PropertyDef_scope.attr("DefinitionObject_Name") = kAAFPropID_DefinitionObject_Name;
    PropertyDef_scope.attr("TypeDefinitionEnumeration_ElementNames") = kAAFPropID_TypeDefinitionEnumeration_ElementNames;
    PropertyDef_scope.attr("PluginDefinition_Manufacturer") = kAAFPropID_PluginDefinition_Manufacturer;
    PropertyDef_scope.attr("DescriptiveMarker_Description") = kAAFPropID_DescriptiveMarker_Description;
    PropertyDef_scope.attr("FilmDescriptor_Manufacturer") = kAAFPropID_FilmDescriptor_Manufacturer;
    PropertyDef_scope.attr("DigitalImageDescriptor_DisplayXOffset") = kAAFPropID_DigitalImageDescriptor_DisplayXOffset;
    PropertyDef_scope.attr("AES3PCMDescriptor_Emphasis") = kAAFPropID_AES3PCMDescriptor_Emphasis;
    PropertyDef_scope.attr("Event_Position") = kAAFPropID_Event_Position;
    PropertyDef_scope.attr("VaryingValue_PointList") = kAAFPropID_VaryingValue_PointList;
    PropertyDef_scope.attr("FilmDescriptor_PerforationsPerFrame") = kAAFPropID_FilmDescriptor_PerforationsPerFrame;
    PropertyDef_scope.attr("TapeDescriptor_VideoSignal") = kAAFPropID_TapeDescriptor_VideoSignal;
    PropertyDef_scope.attr("OperationDefinition_NumberInputs") = kAAFPropID_OperationDefinition_NumberInputs;
    PropertyDef_scope.attr("MultipleDescriptor_FileDescriptors") = kAAFPropID_MultipleDescriptor_FileDescriptors;
    PropertyDef_scope.attr("DefinitionObject_Description") = kAAFPropID_DefinitionObject_Description;
    PropertyDef_scope.attr("PropertyDefinition_IsOptional") = kAAFPropID_PropertyDefinition_IsOptional;
    PropertyDef_scope.attr("MPEGVideoDescriptor_BitRate") = kAAFPropID_MPEGVideoDescriptor_BitRate;
    PropertyDef_scope.attr("ParameterDefinition_DisplayUnits") = kAAFPropID_ParameterDefinition_DisplayUnits;
    PropertyDef_scope.attr("BWFImportDescriptor_QltyQualityEvent") = kAAFPropID_BWFImportDescriptor_QltyQualityEvent;
    PropertyDef_scope.attr("SourceReference_ChannelIDs") = kAAFPropID_SourceReference_ChannelIDs;
    PropertyDef_scope.attr("PCMDescriptor_ChannelAssignment") = kAAFPropID_PCMDescriptor_ChannelAssignment;
    PropertyDef_scope.attr("TIFFDescriptor_IsUniform") = kAAFPropID_TIFFDescriptor_IsUniform;
    PropertyDef_scope.attr("RGBADescriptor_AlphaMaxRef") = kAAFPropID_RGBADescriptor_AlphaMaxRef;
    PropertyDef_scope.attr("TIFFDescriptor_LeadingLines") = kAAFPropID_TIFFDescriptor_LeadingLines;
    PropertyDef_scope.attr("ScopeReference_RelativeSlot") = kAAFPropID_ScopeReference_RelativeSlot;
    PropertyDef_scope.attr("PluginDefinition_DefinitionObject") = kAAFPropID_PluginDefinition_DefinitionObject;
    PropertyDef_scope.attr("PCMDescriptor_PeakEnvelopeVersion") = kAAFPropID_PCMDescriptor_PeakEnvelopeVersion;
    PropertyDef_scope.attr("RGBADescriptor_Palette") = kAAFPropID_RGBADescriptor_Palette;
    PropertyDef_scope.attr("AuxiliaryDescriptor_CharSet") = kAAFPropID_AuxiliaryDescriptor_CharSet;
    PropertyDef_scope.attr("Dictionary_KLVDataDefinitions") = kAAFPropID_Dictionary_KLVDataDefinitions;
    PropertyDef_scope.attr("BWFImportDescriptor_QltyFileSecurityReport") = kAAFPropID_BWFImportDescriptor_QltyFileSecurityReport;
    PropertyDef_scope.attr("CDCIDescriptor_ComponentWidth") = kAAFPropID_CDCIDescriptor_ComponentWidth;
    PropertyDef_scope.attr("Component_Length") = kAAFPropID_Component_Length;
    PropertyDef_scope.attr("MetaDefinition_Identification") = kAAFPropID_MetaDefinition_Identification;
    PropertyDef_scope.attr("PCMDescriptor_PeakEnvelopeFormat") = kAAFPropID_PCMDescriptor_PeakEnvelopeFormat;
    PropertyDef_scope.attr("Identification_ProductID") = kAAFPropID_Identification_ProductID;
    PropertyDef_scope.attr("AIFCDescriptor_Summary") = kAAFPropID_AIFCDescriptor_Summary;
    }

