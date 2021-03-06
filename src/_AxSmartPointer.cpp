
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFTypes.h>
#include <AxBaseObj.h>
#include <AxBaseObjIter.h>
#include <AxComponent.h>
#include <AxContentStorage.h>
#include <AxDefObject.h>
#include <AxDescriptiveFramework.h>
#include <AxDictionary.h>
#include <AxEssence.h>
#include <AxEx.h>
#include <AxFile.h>
#include <AxHeader.h>
#include <AxHrMap.h>
#include <AxInit.h>
#include <AxIterator.h>
#include <AxKLVData.h>
#include <AxMetaDef.h>
#include <AxMob.h>
#include <AxMobSlot.h>
#include <AxObject.h>
#include <AxParameter.h>
#include <AxPluginMgr.h>
#include <AxProperty.h>
#include <AxPropertyValue.h>
#include <AxPropertyValueDump.h>
#include <AxStorageErrors.h>
#include <AxTaggedValue.h>
#include <AxTypes.h>
#include <AxUtil.h>
#include <query_interface.h>
#include <resolve_smartpointer.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class SmartPointers {};
class AxSmartPointer {};
extern const char classname_ClassDef[] = "ClassDef";
extern const char classname_EssenceAccess[] = "EssenceAccess";
extern const char classname_File[] = "File";
extern const char classname_EssenceFormat[] = "EssenceFormat";
extern const char classname_MetaDefinition[] = "MetaDefinition";
extern const char classname_Property[] = "Property";
extern const char classname_PropertyDef[] = "PropertyDef";
extern const char classname_PropertyValue[] = "PropertyValue";
extern const char classname_IEnumAAFClassDefs[] = "IEnumAAFClassDefs";
extern const char classname_IEnumAAFCodecDefs[] = "IEnumAAFCodecDefs";
extern const char classname_IEnumAAFCodecFlavours[] = "IEnumAAFCodecFlavours";
extern const char classname_IEnumAAFComponents[] = "IEnumAAFComponents";
extern const char classname_IEnumAAFContainerDefs[] = "IEnumAAFContainerDefs";
extern const char classname_IEnumAAFControlPoints[] = "IEnumAAFControlPoints";
extern const char classname_IEnumAAFDataDefs[] = "IEnumAAFDataDefs";
extern const char classname_IEnumAAFIdentifications[] = "IEnumAAFIdentifications";
extern const char classname_IEnumAAFInterpolationDefs[] = "IEnumAAFInterpolationDefs";
extern const char classname_IEnumAAFOperationDefs[] = "IEnumAAFOperationDefs";
extern const char classname_IEnumAAFEssenceData[] = "IEnumAAFEssenceData";
extern const char classname_IEnumAAFKLVData[] = "IEnumAAFKLVData";
extern const char classname_IEnumAAFLoadedPlugins[] = "IEnumAAFLoadedPlugins";
extern const char classname_IEnumAAFLocators[] = "IEnumAAFLocators";
extern const char classname_IEnumAAFMobSlots[] = "IEnumAAFMobSlots";
extern const char classname_IEnumAAFMobs[] = "IEnumAAFMobs";
extern const char classname_IEnumAAFParameterDefs[] = "IEnumAAFParameterDefs";
extern const char classname_IEnumAAFParameters[] = "IEnumAAFParameters";
extern const char classname_IEnumAAFProperties[] = "IEnumAAFProperties";
extern const char classname_IEnumAAFPropertyDefs[] = "IEnumAAFPropertyDefs";
extern const char classname_IEnumAAFPropertyValues[] = "IEnumAAFPropertyValues";
extern const char classname_IEnumAAFPluginDefs[] = "IEnumAAFPluginDefs";
extern const char classname_IEnumAAFPluginLocators[] = "IEnumAAFPluginLocators";
extern const char classname_IEnumAAFSegments[] = "IEnumAAFSegments";
extern const char classname_IEnumAAFTaggedValues[] = "IEnumAAFTaggedValues";
extern const char classname_IEnumAAFTypeDefs[] = "IEnumAAFTypeDefs";
extern const char classname_RandomFile[] = "RandomFile";
extern const char classname_EssenceMultiAccess[] = "EssenceMultiAccess";
extern const char classname_IEnumAAFKLVDataDefs[] = "IEnumAAFKLVDataDefs";
extern const char classname_IEnumAAFTaggedValueDefs[] = "IEnumAAFTaggedValueDefs";
extern const char classname_IUnknown[] = "IUnknown";


// Module ======================================================================
void Export_pyste_src_AxSmartPointer()
{

scope smartpointers = class_<SmartPointers>("smartpointers");
class_<AxSmartPointer>("AxSmartPointer");
class_< IAAFAIFCDescriptorSP , bases < AxSmartPointer >  > ("IAAFAIFCDescriptorSP")
.def("to_AIFCDescriptorSP", query_interface_pass_through<IAAFAIFCDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFAIFCDescriptor > )
;
class_< IAAFClassDefSP , bases < AxSmartPointer >  > ("IAAFClassDefSP")
.def("to_ClassDefSP", query_interface_pass_through<IAAFClassDefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFClassDef > )
.def("GetClassName",PyGetClassName_from_string<IAAFClassDefSP, classname_ClassDef> )
;
class_< IAAFCodecDefSP , bases < AxSmartPointer >  > ("IAAFCodecDefSP")
.def("to_CodecDefSP", query_interface_pass_through<IAAFCodecDefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFCodecDef > )
.def("GetClassName",PyGetClassName<IAAFCodecDef, AxCodecDef> )
;
class_< IAAFCommentMarkerSP , bases < AxSmartPointer >  > ("IAAFCommentMarkerSP")
.def("to_CommentMarkerSP", query_interface_pass_through<IAAFCommentMarkerSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFCommentMarker > )
.def("to_DescriptiveMarkerSP", query_interface<IAAFCommentMarker, IAAFDescriptiveMarker > )
.def("GetClassName",PyGetClassName<IAAFCommentMarker, AxCommentMarker> )
;
class_< IAAFComponentSP , bases < AxSmartPointer >  > ("IAAFComponentSP")
.def("to_ComponentSP", query_interface_pass_through<IAAFComponentSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFComponent > )
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
.def("GetClassName",PyGetClassName<IAAFComponent, AxComponent> )
;
class_< IAAFCompositionMobSP , bases < AxSmartPointer >  > ("IAAFCompositionMobSP")
.def("to_CompositionMobSP", query_interface_pass_through<IAAFCompositionMobSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFCompositionMob > )
.def("GetClassName",PyGetClassName<IAAFCompositionMob, AxCompositionMob> )
;
class_< IAAFCompositionMob2SP , bases < AxSmartPointer >  > ("IAAFCompositionMob2SP")
.def("to_CompositionMob2SP", query_interface_pass_through<IAAFCompositionMob2SP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFCompositionMob2 > )
.def("GetClassName",PyGetClassName<IAAFCompositionMob2, AxCompositionMob> )
;
class_< IAAFConstantValueSP , bases < AxSmartPointer >  > ("IAAFConstantValueSP")
.def("to_ConstantValueSP", query_interface_pass_through<IAAFConstantValueSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFConstantValue > )
.def("GetClassName",PyGetClassName<IAAFConstantValue, AxConstantValue> )
;
class_< IAAFContainerDefSP , bases < AxSmartPointer >  > ("IAAFContainerDefSP")
.def("to_ContainerDefSP", query_interface_pass_through<IAAFContainerDefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFContainerDef > )
.def("GetClassName",PyGetClassName<IAAFContainerDef, AxContainerDef> )
;
class_< IAAFContentStorageSP , bases < AxSmartPointer >  > ("IAAFContentStorageSP")
.def("to_ContentStorageSP", query_interface_pass_through<IAAFContentStorageSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFContentStorage > )
.def("GetClassName",PyGetClassName<IAAFContentStorage, AxContentStorage> )
;
class_< IAAFControlPointSP , bases < AxSmartPointer >  > ("IAAFControlPointSP")
.def("to_ControlPointSP", query_interface_pass_through<IAAFControlPointSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFControlPoint > )
.def("GetClassName",PyGetClassName<IAAFControlPoint, AxControlPoint> )
;
class_< IAAFDataDefSP , bases < AxSmartPointer >  > ("IAAFDataDefSP")
.def("to_DataDefSP", query_interface_pass_through<IAAFDataDefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDataDef > )
.def("GetClassName",PyGetClassName<IAAFDataDef, AxDataDef> )
;
class_< IAAFDefObjectSP , bases < AxSmartPointer >  > ("IAAFDefObjectSP")
.def("to_DefObjectSP", query_interface_pass_through<IAAFDefObjectSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDefObject > )
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
.def("GetClassName",PyGetClassName<IAAFDefObject, AxDefObject> )
;
class_< IAAFPluginDefSP , bases < AxSmartPointer >  > ("IAAFPluginDefSP")
.def("to_PluginDefSP", query_interface_pass_through<IAAFPluginDefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFPluginDef > )
.def("GetClassName",PyGetClassName<IAAFPluginDef, AxPluginDef> )
;
class_< IAAFDictionarySP , bases < AxSmartPointer >  > ("IAAFDictionarySP")
.def("to_DictionarySP", query_interface_pass_through<IAAFDictionarySP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDictionary > )
.def("GetClassName",PyGetClassName<IAAFDictionary, AxDictionary> )
;
class_< IAAFEdgecodeSP , bases < AxSmartPointer >  > ("IAAFEdgecodeSP")
.def("to_EdgecodeSP", query_interface_pass_through<IAAFEdgecodeSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEdgecode > )
.def("GetClassName",PyGetClassName<IAAFEdgecode, AxEdgecode> )
;
class_< IAAFOperationDefSP , bases < AxSmartPointer >  > ("IAAFOperationDefSP")
.def("to_OperationDefSP", query_interface_pass_through<IAAFOperationDefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFOperationDef > )
.def("GetClassName",PyGetClassName<IAAFOperationDef, AxOperationDef> )
;
class_< IAAFEssenceAccessSP , bases < AxSmartPointer >  > ("IAAFEssenceAccessSP")
.def("to_EssenceAccessSP", query_interface_pass_through<IAAFEssenceAccessSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEssenceAccess > )
.def("GetClassName",PyGetClassName_from_string<IAAFEssenceAccessSP, classname_EssenceAccess> )
;
class_< IAAFEssenceDataSP , bases < AxSmartPointer >  > ("IAAFEssenceDataSP")
.def("to_EssenceDataSP", query_interface_pass_through<IAAFEssenceDataSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEssenceData > )
;
class_< IAAFEssenceDescriptorSP , bases < AxSmartPointer >  > ("IAAFEssenceDescriptorSP")
.def("to_EssenceDescriptorSP", query_interface_pass_through<IAAFEssenceDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEssenceDescriptor > )
.def("to_FileDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFFileDescriptor > )
.def("to_SoundDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFSoundDescriptor > )
.def("to_PCMDescriptorSP", query_interface<IAAFEssenceDescriptor, IAAFPCMDescriptor > )
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
.def("GetClassName",PyGetClassName<IAAFEssenceDescriptor, AxEssenceDescriptor> )
;
class_< IAAFEventSP , bases < AxSmartPointer >  > ("IAAFEventSP")
.def("to_EventSP", query_interface_pass_through<IAAFEventSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEvent > )
.def("to_CommentMarkerSP", query_interface<IAAFEvent, IAAFCommentMarker > )
.def("to_DescriptiveMarkerSP", query_interface<IAAFEvent, IAAFDescriptiveMarker > )
.def("to_GPITriggerSP", query_interface<IAAFEvent, IAAFGPITrigger > )
.def("to_TimecodeStreamSP", query_interface<IAAFEvent, IAAFTimecodeStream > )
.def("to_TimecodeStream12MSP", query_interface<IAAFEvent, IAAFTimecodeStream12M > )
.def("GetClassName",PyGetClassName<IAAFEvent, AxEvent> )
;
class_< IAAFEventMobSlotSP , bases < AxSmartPointer >  > ("IAAFEventMobSlotSP")
.def("to_EventMobSlotSP", query_interface_pass_through<IAAFEventMobSlotSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEventMobSlot > )
.def("GetClassName",PyGetClassName<IAAFEventMobSlot, AxEventMobSlot> )
;
class_< IAAFFileSP , bases < AxSmartPointer >  > ("IAAFFileSP")
.def("to_FileSP", query_interface_pass_through<IAAFFileSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFFile > )
.def("to_RandomFileSP", query_interface<IAAFFile, IAAFRandomFile > )
.def("GetClassName",PyGetClassName_from_string<IAAFFileSP, classname_File> )
;
class_< IAAFFileDescriptorSP , bases < AxSmartPointer >  > ("IAAFFileDescriptorSP")
.def("to_FileDescriptorSP", query_interface_pass_through<IAAFFileDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFFileDescriptor > )
.def("to_SoundDescriptorSP", query_interface<IAAFFileDescriptor, IAAFSoundDescriptor > )
.def("to_PCMDescriptorSP", query_interface<IAAFFileDescriptor, IAAFPCMDescriptor > )
.def("to_WAVEDescriptorSP", query_interface<IAAFFileDescriptor, IAAFWAVEDescriptor > )
.def("to_DigitalImageDescriptorSP", query_interface<IAAFFileDescriptor, IAAFDigitalImageDescriptor > )
.def("to_CDCIDescriptorSP", query_interface<IAAFFileDescriptor, IAAFCDCIDescriptor > )
.def("to_RGBADescriptorSP", query_interface<IAAFFileDescriptor, IAAFRGBADescriptor > )
.def("GetClassName",PyGetClassName<IAAFFileDescriptor, AxFileDescriptor> )
;
class_< IAAFFilmDescriptorSP , bases < AxSmartPointer >  > ("IAAFFilmDescriptorSP")
.def("to_FilmDescriptorSP", query_interface_pass_through<IAAFFilmDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFFilmDescriptor > )
.def("GetClassName",PyGetClassName<IAAFFilmDescriptor, AxFilmDescriptor> )
;
class_< IAAFDigitalImageDescriptorSP , bases < AxSmartPointer >  > ("IAAFDigitalImageDescriptorSP")
.def("to_DigitalImageDescriptorSP", query_interface_pass_through<IAAFDigitalImageDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDigitalImageDescriptor > )
.def("to_CDCIDescriptorSP", query_interface<IAAFDigitalImageDescriptor, IAAFCDCIDescriptor > )
.def("to_RGBADescriptorSP", query_interface<IAAFDigitalImageDescriptor, IAAFRGBADescriptor > )
.def("to_RGBADescriptor2SP", query_interface<IAAFDigitalImageDescriptor, IAAFRGBADescriptor2 > )
.def("GetClassName",PyGetClassName<IAAFDigitalImageDescriptor, AxDigitalImageDescriptor> )
;
class_< IAAFCDCIDescriptorSP , bases < AxSmartPointer >  > ("IAAFCDCIDescriptorSP")
.def("to_CDCIDescriptorSP", query_interface_pass_through<IAAFCDCIDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFCDCIDescriptor > )
.def("GetClassName",PyGetClassName<IAAFCDCIDescriptor, AxCDCIDescriptor> )
;
class_< IAAFEssenceFormatSP , bases < AxSmartPointer >  > ("IAAFEssenceFormatSP")
.def("to_EssenceFormatSP", query_interface_pass_through<IAAFEssenceFormatSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEssenceFormat > )
.def("GetClassName",PyGetClassName_from_string<IAAFEssenceFormatSP, classname_EssenceFormat> )
;
class_< IAAFEssenceGroupSP , bases < AxSmartPointer >  > ("IAAFEssenceGroupSP")
.def("to_EssenceGroupSP", query_interface_pass_through<IAAFEssenceGroupSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEssenceGroup > )
.def("GetClassName",PyGetClassName<IAAFEssenceGroup, AxEssenceGroup> )
;
class_< IAAFFillerSP , bases < AxSmartPointer >  > ("IAAFFillerSP")
.def("to_FillerSP", query_interface_pass_through<IAAFFillerSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFFiller > )
.def("GetClassName",PyGetClassName<IAAFFiller, AxFiller> )
;
class_< IAAFFindSourceInfoSP , bases < AxSmartPointer >  > ("IAAFFindSourceInfoSP")
.def("to_FindSourceInfoSP", query_interface_pass_through<IAAFFindSourceInfoSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFFindSourceInfo > )
;
class_< IAAFOperationGroupSP , bases < AxSmartPointer >  > ("IAAFOperationGroupSP")
.def("to_OperationGroupSP", query_interface_pass_through<IAAFOperationGroupSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFOperationGroup > )
.def("GetClassName",PyGetClassName<IAAFOperationGroup, AxOperationGroup> )
;
class_< IAAFGPITriggerSP , bases < AxSmartPointer >  > ("IAAFGPITriggerSP")
.def("to_GPITriggerSP", query_interface_pass_through<IAAFGPITriggerSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFGPITrigger > )
.def("GetClassName",PyGetClassName<IAAFGPITrigger, AxGPITrigger> )
;
class_< IAAFHeaderSP , bases < AxSmartPointer >  > ("IAAFHeaderSP")
.def("to_HeaderSP", query_interface_pass_through<IAAFHeaderSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFHeader > )
.def("GetClassName",PyGetClassName<IAAFHeader, AxHeader> )
;
class_< IAAFIdentificationSP , bases < AxSmartPointer >  > ("IAAFIdentificationSP")
.def("to_IdentificationSP", query_interface_pass_through<IAAFIdentificationSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFIdentification > )
.def("GetClassName",PyGetClassName<IAAFIdentification, AxIdentification> )
;
class_< IAAFInterpolationDefSP , bases < AxSmartPointer >  > ("IAAFInterpolationDefSP")
.def("to_InterpolationDefSP", query_interface_pass_through<IAAFInterpolationDefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFInterpolationDef > )
.def("GetClassName",PyGetClassName<IAAFInterpolationDef, AxInterpolationDef> )
;
class_< IAAFKLVDataSP , bases < AxSmartPointer >  > ("IAAFKLVDataSP")
.def("to_KLVDataSP", query_interface_pass_through<IAAFKLVDataSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFKLVData > )
.def("GetClassName",PyGetClassName<IAAFKLVData, AxKLVData> )
;
class_< IAAFLocatorSP , bases < AxSmartPointer >  > ("IAAFLocatorSP")
.def("to_LocatorSP", query_interface_pass_through<IAAFLocatorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFLocator > )
.def("to_NetworkLocatorSP", query_interface<IAAFLocator, IAAFNetworkLocator > )
.def("GetClassName",PyGetClassName<IAAFLocator, AxLocator> )
;
class_< IAAFMasterMobSP , bases < AxSmartPointer >  > ("IAAFMasterMobSP")
.def("to_MasterMobSP", query_interface_pass_through<IAAFMasterMobSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFMasterMob > )
.def("to_MasterMobExSP", query_interface<IAAFMasterMob, IAAFMasterMobEx > )
.def("GetClassName",PyGetClassName<IAAFMasterMob, AxMasterMob> )
;
class_< IAAFMasterMob2SP , bases < AxSmartPointer >  > ("IAAFMasterMob2SP")
.def("to_MasterMob2SP", query_interface_pass_through<IAAFMasterMob2SP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFMasterMob2 > )
.def("to_MasterMobExSP", query_interface<IAAFMasterMob2, IAAFMasterMobEx > )
.def("GetClassName",PyGetClassName<IAAFMasterMob2, AxMasterMob> )
;
class_< IAAFMasterMobExSP , bases < AxSmartPointer >  > ("IAAFMasterMobExSP")
.def("to_MasterMobExSP", query_interface_pass_through<IAAFMasterMobExSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFMasterMobEx > )
.def("GetClassName",PyGetClassName<IAAFMasterMobEx, AxMasterMobEx> )
;
class_< IAAFMetaDefinitionSP , bases < AxSmartPointer >  > ("IAAFMetaDefinitionSP")
.def("to_MetaDefinitionSP", query_interface_pass_through<IAAFMetaDefinitionSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFMetaDefinition > )
.def("to_ClassDefSP", query_interface<IAAFMetaDefinition, IAAFClassDef > )
.def("to_PropertyDefSP", query_interface<IAAFMetaDefinition, IAAFPropertyDef > )
.def("to_TypeDefSP", query_interface<IAAFMetaDefinition, IAAFTypeDef > )
.def("to_TypeDefRecordSP", query_interface<IAAFMetaDefinition, IAAFTypeDefRecord > )
.def("to_TypeDefVariableArraySP", query_interface<IAAFMetaDefinition, IAAFTypeDefVariableArray > )
.def("to_TypeDefFixedArraySP", query_interface<IAAFMetaDefinition, IAAFTypeDefFixedArray > )
.def("to_TypeDefIntSP", query_interface<IAAFMetaDefinition, IAAFTypeDefInt > )
.def("to_TypeDefWeakObjRefSP", query_interface<IAAFMetaDefinition, IAAFTypeDefWeakObjRef > )
.def("to_TypeDefExtEnumSP", query_interface<IAAFMetaDefinition, IAAFTypeDefExtEnum > )
.def("to_TypeDefCharacterSP", query_interface<IAAFMetaDefinition, IAAFTypeDefCharacter > )
.def("to_TypeDefVariableArrayExSP", query_interface<IAAFMetaDefinition, IAAFTypeDefVariableArrayEx > )
.def("to_TypeDefStringSP", query_interface<IAAFMetaDefinition, IAAFTypeDefString > )
.def("to_TypeDefObjectRefSP", query_interface<IAAFMetaDefinition, IAAFTypeDefObjectRef > )
.def("to_TypeDefStrongObjRefSP", query_interface<IAAFMetaDefinition, IAAFTypeDefStrongObjRef > )
.def("to_TypeDefEnumSP", query_interface<IAAFMetaDefinition, IAAFTypeDefEnum > )
.def("to_TypeDefIndirectSP", query_interface<IAAFMetaDefinition, IAAFTypeDefIndirect > )
.def("to_TypeDefOpaqueSP", query_interface<IAAFMetaDefinition, IAAFTypeDefOpaque > )
.def("to_TypeDefRenameSP", query_interface<IAAFMetaDefinition, IAAFTypeDefRename > )
.def("to_TypeDefSetSP", query_interface<IAAFMetaDefinition, IAAFTypeDefSet > )
.def("to_TypeDefStreamSP", query_interface<IAAFMetaDefinition, IAAFTypeDefStream > )
.def("GetClassName",PyGetClassName_from_string<IAAFMetaDefinitionSP, classname_MetaDefinition> )
;
class_< IAAFMobSP , bases < AxSmartPointer >  > ("IAAFMobSP")
.def("to_MobSP", query_interface_pass_through<IAAFMobSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFMob > )
.def("to_MasterMobSP", query_interface<IAAFMob, IAAFMasterMob > )
.def("to_MasterMob2SP", query_interface<IAAFMob, IAAFMasterMob2 > )
.def("to_MasterMobExSP", query_interface<IAAFMob, IAAFMasterMobEx > )
.def("to_SourceMobSP", query_interface<IAAFMob, IAAFSourceMob > )
.def("to_CompositionMobSP", query_interface<IAAFMob, IAAFCompositionMob > )
.def("to_CompositionMob2SP", query_interface<IAAFMob, IAAFCompositionMob2 > )
.def("GetClassName",PyGetClassName<IAAFMob, AxMob> )
;
class_< IAAFMobSlotSP , bases < AxSmartPointer >  > ("IAAFMobSlotSP")
.def("to_MobSlotSP", query_interface_pass_through<IAAFMobSlotSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFMobSlot > )
.def("to_TimelineMobSlotSP", query_interface<IAAFMobSlot, IAAFTimelineMobSlot > )
.def("to_TimelineMobSlot2SP", query_interface<IAAFMobSlot, IAAFTimelineMobSlot2 > )
.def("to_StaticMobSlotSP", query_interface<IAAFMobSlot, IAAFStaticMobSlot > )
.def("to_EventMobSlotSP", query_interface<IAAFMobSlot, IAAFEventMobSlot > )
.def("GetClassName",PyGetClassName<IAAFMobSlot, AxMobSlot> )
;
class_< IAAFNestedScopeSP , bases < AxSmartPointer >  > ("IAAFNestedScopeSP")
.def("to_NestedScopeSP", query_interface_pass_through<IAAFNestedScopeSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFNestedScope > )
.def("GetClassName",PyGetClassName<IAAFNestedScope, AxNestedScope> )
;
class_< IAAFNetworkLocatorSP , bases < AxSmartPointer >  > ("IAAFNetworkLocatorSP")
.def("to_NetworkLocatorSP", query_interface_pass_through<IAAFNetworkLocatorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFNetworkLocator > )
.def("GetClassName",PyGetClassName<IAAFNetworkLocator, AxNetworkLocator> )
;
class_< IAAFObjectSP , bases < AxSmartPointer >  > ("IAAFObjectSP")
.def("to_ObjectSP", query_interface_pass_through<IAAFObjectSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFObject > )
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
.def("to_PCMDescriptorSP", query_interface<IAAFObject, IAAFPCMDescriptor > )
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
.def("to_VaryingValueSP", query_interface<IAAFObject, IAAFVaryingValue > )
.def("to_ConstantValueSP", query_interface<IAAFObject, IAAFConstantValue > )
.def("to_MobSlotSP", query_interface<IAAFObject, IAAFMobSlot > )
.def("to_TimelineMobSlotSP", query_interface<IAAFObject, IAAFTimelineMobSlot > )
.def("to_StaticMobSlotSP", query_interface<IAAFObject, IAAFStaticMobSlot > )
.def("to_EventMobSlotSP", query_interface<IAAFObject, IAAFEventMobSlot > )
.def("to_TaggedValueSP", query_interface<IAAFObject, IAAFTaggedValue > )
.def("to_KLVDataSP", query_interface<IAAFObject, IAAFKLVData > )
.def("to_ControlPointSP", query_interface<IAAFObject, IAAFControlPoint > )
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
.def("GetClassName",PyGetClassName<IAAFObject, AxObject> )
;
class_< IAAFParameterSP , bases < AxSmartPointer >  > ("IAAFParameterSP")
.def("to_ParameterSP", query_interface_pass_through<IAAFParameterSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFParameter > )
.def("to_VaryingValueSP", query_interface<IAAFParameter, IAAFVaryingValue > )
.def("to_ConstantValueSP", query_interface<IAAFParameter, IAAFConstantValue > )
.def("GetClassName",PyGetClassName<IAAFParameter, AxParameter> )
;
class_< IAAFParameterDefSP , bases < AxSmartPointer >  > ("IAAFParameterDefSP")
.def("to_ParameterDefSP", query_interface_pass_through<IAAFParameterDefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFParameterDef > )
.def("GetClassName",PyGetClassName<IAAFParameterDef, AxParameterDef> )
;
class_< IAAFPropertySP , bases < AxSmartPointer >  > ("IAAFPropertySP")
.def("to_PropertySP", query_interface_pass_through<IAAFPropertySP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFProperty > )
.def("GetClassName",PyGetClassName_from_string<IAAFPropertySP, classname_Property> )
;
class_< IAAFPropertyDefSP , bases < AxSmartPointer >  > ("IAAFPropertyDefSP")
.def("to_PropertyDefSP", query_interface_pass_through<IAAFPropertyDefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFPropertyDef > )
.def("GetClassName",PyGetClassName_from_string<IAAFPropertyDefSP, classname_PropertyDef> )
;
class_< IAAFPropertyValueSP , bases < AxSmartPointer >  > ("IAAFPropertyValueSP")
.def("to_PropertyValueSP", query_interface_pass_through<IAAFPropertyValueSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFPropertyValue > )
.def("GetClassName",PyGetClassName_from_string<IAAFPropertyValueSP, classname_PropertyValue> )
;
class_< IAAFPluginManagerSP , bases < AxSmartPointer >  > ("IAAFPluginManagerSP")
.def("to_PluginManagerSP", query_interface_pass_through<IAAFPluginManagerSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFPluginManager > )
;
class_< IAAFPulldownSP , bases < AxSmartPointer >  > ("IAAFPulldownSP")
.def("to_PulldownSP", query_interface_pass_through<IAAFPulldownSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFPulldown > )
.def("GetClassName",PyGetClassName<IAAFPulldown, AxPulldown> )
;
class_< IAAFRGBADescriptorSP , bases < AxSmartPointer >  > ("IAAFRGBADescriptorSP")
.def("to_RGBADescriptorSP", query_interface_pass_through<IAAFRGBADescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFRGBADescriptor > )
.def("GetClassName",PyGetClassName<IAAFRGBADescriptor, AxRGBADescriptor> )
;
class_< IAAFScopeReferenceSP , bases < AxSmartPointer >  > ("IAAFScopeReferenceSP")
.def("to_ScopeReferenceSP", query_interface_pass_through<IAAFScopeReferenceSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFScopeReference > )
.def("GetClassName",PyGetClassName<IAAFScopeReference, AxScopeReference> )
;
class_< IAAFSegmentSP , bases < AxSmartPointer >  > ("IAAFSegmentSP")
.def("to_SegmentSP", query_interface_pass_through<IAAFSegmentSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFSegment > )
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
.def("GetClassName",PyGetClassName<IAAFSegment, AxSegment> )
;
class_< IAAFSelectorSP , bases < AxSmartPointer >  > ("IAAFSelectorSP")
.def("to_SelectorSP", query_interface_pass_through<IAAFSelectorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFSelector > )
.def("GetClassName",PyGetClassName<IAAFSelector, AxSelector> )
;
class_< IAAFSequenceSP , bases < AxSmartPointer >  > ("IAAFSequenceSP")
.def("to_SequenceSP", query_interface_pass_through<IAAFSequenceSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFSequence > )
.def("GetClassName",PyGetClassName<IAAFSequence, AxSequence> )
;
class_< IAAFSourceClipSP , bases < AxSmartPointer >  > ("IAAFSourceClipSP")
.def("to_SourceClipSP", query_interface_pass_through<IAAFSourceClipSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFSourceClip > )
.def("GetClassName",PyGetClassName<IAAFSourceClip, AxSourceClip> )
;
class_< IAAFSourceMobSP , bases < AxSmartPointer >  > ("IAAFSourceMobSP")
.def("to_SourceMobSP", query_interface_pass_through<IAAFSourceMobSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFSourceMob > )
.def("GetClassName",PyGetClassName<IAAFSourceMob, AxSourceMob> )
;
class_< IAAFSourceReferenceSP , bases < AxSmartPointer >  > ("IAAFSourceReferenceSP")
.def("to_SourceReferenceSP", query_interface_pass_through<IAAFSourceReferenceSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFSourceReference > )
.def("to_SourceClipSP", query_interface<IAAFSourceReference, IAAFSourceClip > )
.def("GetClassName",PyGetClassName<IAAFSourceReference, AxSourceReference> )
;
class_< IAAFStaticMobSlotSP , bases < AxSmartPointer >  > ("IAAFStaticMobSlotSP")
.def("to_StaticMobSlotSP", query_interface_pass_through<IAAFStaticMobSlotSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFStaticMobSlot > )
.def("GetClassName",PyGetClassName<IAAFStaticMobSlot, AxStaticMobSlot> )
;
class_< IAAFTapeDescriptorSP , bases < AxSmartPointer >  > ("IAAFTapeDescriptorSP")
.def("to_TapeDescriptorSP", query_interface_pass_through<IAAFTapeDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTapeDescriptor > )
.def("GetClassName",PyGetClassName<IAAFTapeDescriptor, AxTapeDescriptor> )
;
class_< IAAFTaggedValueSP , bases < AxSmartPointer >  > ("IAAFTaggedValueSP")
.def("to_TaggedValueSP", query_interface_pass_through<IAAFTaggedValueSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTaggedValue > )
.def("GetClassName",PyGetClassName<IAAFTaggedValue, AxTaggedValue> )
;
class_< IAAFTextLocatorSP , bases < AxSmartPointer >  > ("IAAFTextLocatorSP")
.def("to_TextLocatorSP", query_interface_pass_through<IAAFTextLocatorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTextLocator > )
;
class_< IAAFTimecodeSP , bases < AxSmartPointer >  > ("IAAFTimecodeSP")
.def("to_TimecodeSP", query_interface_pass_through<IAAFTimecodeSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTimecode > )
.def("GetClassName",PyGetClassName<IAAFTimecode, AxTimecode> )
;
class_< IAAFTimelineMobSlotSP , bases < AxSmartPointer >  > ("IAAFTimelineMobSlotSP")
.def("to_TimelineMobSlotSP", query_interface_pass_through<IAAFTimelineMobSlotSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTimelineMobSlot > )
.def("GetClassName",PyGetClassName<IAAFTimelineMobSlot, AxTimelineMobSlot> )
;
class_< IAAFTransitionSP , bases < AxSmartPointer >  > ("IAAFTransitionSP")
.def("to_TransitionSP", query_interface_pass_through<IAAFTransitionSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTransition > )
.def("GetClassName",PyGetClassName<IAAFTransition, AxTransition> )
;
class_< IAAFTIFFDescriptorSP , bases < AxSmartPointer >  > ("IAAFTIFFDescriptorSP")
.def("to_TIFFDescriptorSP", query_interface_pass_through<IAAFTIFFDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTIFFDescriptor > )
;
class_< IAAFTimecodeStreamSP , bases < AxSmartPointer >  > ("IAAFTimecodeStreamSP")
.def("to_TimecodeStreamSP", query_interface_pass_through<IAAFTimecodeStreamSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTimecodeStream > )
.def("to_TimecodeStream12MSP", query_interface<IAAFTimecodeStream, IAAFTimecodeStream12M > )
.def("GetClassName",PyGetClassName<IAAFTimecodeStream, AxTimecodeStream> )
;
class_< IAAFTimecodeStream12MSP , bases < AxSmartPointer >  > ("IAAFTimecodeStream12MSP")
.def("to_TimecodeStream12MSP", query_interface_pass_through<IAAFTimecodeStream12MSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTimecodeStream12M > )
;
class_< IAAFTypeDefSP , bases < AxSmartPointer >  > ("IAAFTypeDefSP")
.def("to_TypeDefSP", query_interface_pass_through<IAAFTypeDefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDef > )
.def("to_TypeDefRecordSP", query_interface<IAAFTypeDef, IAAFTypeDefRecord > )
.def("to_TypeDefVariableArraySP", query_interface<IAAFTypeDef, IAAFTypeDefVariableArray > )
.def("to_TypeDefFixedArraySP", query_interface<IAAFTypeDef, IAAFTypeDefFixedArray > )
.def("to_TypeDefIntSP", query_interface<IAAFTypeDef, IAAFTypeDefInt > )
.def("to_TypeDefWeakObjRefSP", query_interface<IAAFTypeDef, IAAFTypeDefWeakObjRef > )
.def("to_TypeDefExtEnumSP", query_interface<IAAFTypeDef, IAAFTypeDefExtEnum > )
.def("to_TypeDefCharacterSP", query_interface<IAAFTypeDef, IAAFTypeDefCharacter > )
.def("to_TypeDefVariableArrayExSP", query_interface<IAAFTypeDef, IAAFTypeDefVariableArrayEx > )
.def("to_TypeDefStringSP", query_interface<IAAFTypeDef, IAAFTypeDefString > )
.def("to_TypeDefObjectRefSP", query_interface<IAAFTypeDef, IAAFTypeDefObjectRef > )
.def("to_TypeDefStrongObjRefSP", query_interface<IAAFTypeDef, IAAFTypeDefStrongObjRef > )
.def("to_TypeDefEnumSP", query_interface<IAAFTypeDef, IAAFTypeDefEnum > )
.def("to_TypeDefIndirectSP", query_interface<IAAFTypeDef, IAAFTypeDefIndirect > )
.def("to_TypeDefOpaqueSP", query_interface<IAAFTypeDef, IAAFTypeDefOpaque > )
.def("to_TypeDefRenameSP", query_interface<IAAFTypeDef, IAAFTypeDefRename > )
.def("to_TypeDefSetSP", query_interface<IAAFTypeDef, IAAFTypeDefSet > )
.def("to_TypeDefStreamSP", query_interface<IAAFTypeDef, IAAFTypeDefStream > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefSP, AxTypeDef> )
;
class_< IAAFTypeDefCharacterSP , bases < AxSmartPointer >  > ("IAAFTypeDefCharacterSP")
.def("to_TypeDefCharacterSP", query_interface_pass_through<IAAFTypeDefCharacterSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefCharacter > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefCharacterSP, AxTypeDefCharacter> )
;
class_< IAAFTypeDefIndirectSP , bases < AxSmartPointer >  > ("IAAFTypeDefIndirectSP")
.def("to_TypeDefIndirectSP", query_interface_pass_through<IAAFTypeDefIndirectSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefIndirect > )
.def("to_TypeDefOpaqueSP", query_interface<IAAFTypeDefIndirect, IAAFTypeDefOpaque > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefIndirectSP, AxTypeDefIndirect> )
;
class_< IAAFTypeDefIntSP , bases < AxSmartPointer >  > ("IAAFTypeDefIntSP")
.def("to_TypeDefIntSP", query_interface_pass_through<IAAFTypeDefIntSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefInt > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefIntSP, AxTypeDefInt> )
;
class_< IAAFTypeDefRenameSP , bases < AxSmartPointer >  > ("IAAFTypeDefRenameSP")
.def("to_TypeDefRenameSP", query_interface_pass_through<IAAFTypeDefRenameSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefRename > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefRenameSP, AxTypeDefRename> )
;
class_< IAAFTypeDefEnumSP , bases < AxSmartPointer >  > ("IAAFTypeDefEnumSP")
.def("to_TypeDefEnumSP", query_interface_pass_through<IAAFTypeDefEnumSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefEnum > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefEnumSP, AxTypeDefEnum> )
;
class_< IAAFTypeDefExtEnumSP , bases < AxSmartPointer >  > ("IAAFTypeDefExtEnumSP")
.def("to_TypeDefExtEnumSP", query_interface_pass_through<IAAFTypeDefExtEnumSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefExtEnum > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefExtEnumSP, AxTypeDefExtEnum> )
;
class_< IAAFTypeDefFixedArraySP , bases < AxSmartPointer >  > ("IAAFTypeDefFixedArraySP")
.def("to_TypeDefFixedArraySP", query_interface_pass_through<IAAFTypeDefFixedArraySP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefFixedArray > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefFixedArraySP, AxTypeDefFixedArray> )
;
class_< IAAFTypeDefRecordSP , bases < AxSmartPointer >  > ("IAAFTypeDefRecordSP")
.def("to_TypeDefRecordSP", query_interface_pass_through<IAAFTypeDefRecordSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefRecord > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefRecordSP, AxTypeDefRecord> )
;
class_< IAAFTypeDefSetSP , bases < AxSmartPointer >  > ("IAAFTypeDefSetSP")
.def("to_TypeDefSetSP", query_interface_pass_through<IAAFTypeDefSetSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefSet > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefSetSP, AxTypeDefSet> )
;
class_< IAAFTypeDefStreamSP , bases < AxSmartPointer >  > ("IAAFTypeDefStreamSP")
.def("to_TypeDefStreamSP", query_interface_pass_through<IAAFTypeDefStreamSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefStream > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefStreamSP, AxTypeDefStream> )
;
class_< IAAFTypeDefStringSP , bases < AxSmartPointer >  > ("IAAFTypeDefStringSP")
.def("to_TypeDefStringSP", query_interface_pass_through<IAAFTypeDefStringSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefString > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefStringSP, AxTypeDefString> )
;
class_< IAAFTypeDefStrongObjRefSP , bases < AxSmartPointer >  > ("IAAFTypeDefStrongObjRefSP")
.def("to_TypeDefStrongObjRefSP", query_interface_pass_through<IAAFTypeDefStrongObjRefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefStrongObjRef > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefStrongObjRefSP, AxTypeDefStrongObjRef> )
;
class_< IAAFTypeDefWeakObjRefSP , bases < AxSmartPointer >  > ("IAAFTypeDefWeakObjRefSP")
.def("to_TypeDefWeakObjRefSP", query_interface_pass_through<IAAFTypeDefWeakObjRefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefWeakObjRef > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefWeakObjRefSP, AxTypeDefWeakObjRef> )
;
class_< IAAFTypeDefObjectRefSP , bases < AxSmartPointer >  > ("IAAFTypeDefObjectRefSP")
.def("to_TypeDefObjectRefSP", query_interface_pass_through<IAAFTypeDefObjectRefSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefObjectRef > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefObjectRefSP, AxTypeDefObjRef> )
;
class_< IAAFTypeDefOpaqueSP , bases < AxSmartPointer >  > ("IAAFTypeDefOpaqueSP")
.def("to_TypeDefOpaqueSP", query_interface_pass_through<IAAFTypeDefOpaqueSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefOpaque > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefOpaqueSP, AxTypeDefOpaque> )
;
class_< IAAFTypeDefVariableArraySP , bases < AxSmartPointer >  > ("IAAFTypeDefVariableArraySP")
.def("to_TypeDefVariableArraySP", query_interface_pass_through<IAAFTypeDefVariableArraySP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefVariableArray > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefVariableArraySP, AxTypeDefVariableArray> )
;
class_< IAAFVaryingValueSP , bases < AxSmartPointer >  > ("IAAFVaryingValueSP")
.def("to_VaryingValueSP", query_interface_pass_through<IAAFVaryingValueSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFVaryingValue > )
.def("GetClassName",PyGetClassName<IAAFVaryingValue, AxVaryingValue> )
;
class_< IAAFWAVEDescriptorSP , bases < AxSmartPointer >  > ("IAAFWAVEDescriptorSP")
.def("to_WAVEDescriptorSP", query_interface_pass_through<IAAFWAVEDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFWAVEDescriptor > )
.def("GetClassName",PyGetClassName<IAAFWAVEDescriptor, AxWAVEDescriptor> )
;
class_< IEnumAAFClassDefsSP , bases < AxSmartPointer >  > ("IEnumAAFClassDefsSP")
.def("to_IEnumAAFClassDefsSP", query_interface_pass_through<IEnumAAFClassDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFClassDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFClassDefsSP, classname_IEnumAAFClassDefs> )
;
class_< IEnumAAFCodecDefsSP , bases < AxSmartPointer >  > ("IEnumAAFCodecDefsSP")
.def("to_IEnumAAFCodecDefsSP", query_interface_pass_through<IEnumAAFCodecDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFCodecDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFCodecDefsSP, classname_IEnumAAFCodecDefs> )
;
class_< IEnumAAFCodecFlavoursSP , bases < AxSmartPointer >  > ("IEnumAAFCodecFlavoursSP")
.def("to_IEnumAAFCodecFlavoursSP", query_interface_pass_through<IEnumAAFCodecFlavoursSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFCodecFlavours > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFCodecFlavoursSP, classname_IEnumAAFCodecFlavours> )
;
class_< IEnumAAFComponentsSP , bases < AxSmartPointer >  > ("IEnumAAFComponentsSP")
.def("to_IEnumAAFComponentsSP", query_interface_pass_through<IEnumAAFComponentsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFComponents > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFComponentsSP, classname_IEnumAAFComponents> )
;
class_< IEnumAAFContainerDefsSP , bases < AxSmartPointer >  > ("IEnumAAFContainerDefsSP")
.def("to_IEnumAAFContainerDefsSP", query_interface_pass_through<IEnumAAFContainerDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFContainerDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFContainerDefsSP, classname_IEnumAAFContainerDefs> )
;
class_< IEnumAAFControlPointsSP , bases < AxSmartPointer >  > ("IEnumAAFControlPointsSP")
.def("to_IEnumAAFControlPointsSP", query_interface_pass_through<IEnumAAFControlPointsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFControlPoints > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFControlPointsSP, classname_IEnumAAFControlPoints> )
;
class_< IEnumAAFDataDefsSP , bases < AxSmartPointer >  > ("IEnumAAFDataDefsSP")
.def("to_IEnumAAFDataDefsSP", query_interface_pass_through<IEnumAAFDataDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFDataDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFDataDefsSP, classname_IEnumAAFDataDefs> )
;
class_< IEnumAAFIdentificationsSP , bases < AxSmartPointer >  > ("IEnumAAFIdentificationsSP")
.def("to_IEnumAAFIdentificationsSP", query_interface_pass_through<IEnumAAFIdentificationsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFIdentifications > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFIdentificationsSP, classname_IEnumAAFIdentifications> )
;
class_< IEnumAAFInterpolationDefsSP , bases < AxSmartPointer >  > ("IEnumAAFInterpolationDefsSP")
.def("to_IEnumAAFInterpolationDefsSP", query_interface_pass_through<IEnumAAFInterpolationDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFInterpolationDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFInterpolationDefsSP, classname_IEnumAAFInterpolationDefs> )
;
class_< IEnumAAFOperationDefsSP , bases < AxSmartPointer >  > ("IEnumAAFOperationDefsSP")
.def("to_IEnumAAFOperationDefsSP", query_interface_pass_through<IEnumAAFOperationDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFOperationDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFOperationDefsSP, classname_IEnumAAFOperationDefs> )
;
class_< IEnumAAFEssenceDataSP , bases < AxSmartPointer >  > ("IEnumAAFEssenceDataSP")
.def("to_IEnumAAFEssenceDataSP", query_interface_pass_through<IEnumAAFEssenceDataSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFEssenceData > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFEssenceDataSP, classname_IEnumAAFEssenceData> )
;
class_< IEnumAAFKLVDataSP , bases < AxSmartPointer >  > ("IEnumAAFKLVDataSP")
.def("to_IEnumAAFKLVDataSP", query_interface_pass_through<IEnumAAFKLVDataSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFKLVData > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFKLVDataSP, classname_IEnumAAFKLVData> )
;
class_< IEnumAAFLoadedPluginsSP , bases < AxSmartPointer >  > ("IEnumAAFLoadedPluginsSP")
.def("to_IEnumAAFLoadedPluginsSP", query_interface_pass_through<IEnumAAFLoadedPluginsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFLoadedPlugins > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFLoadedPluginsSP, classname_IEnumAAFLoadedPlugins> )
;
class_< IEnumAAFLocatorsSP , bases < AxSmartPointer >  > ("IEnumAAFLocatorsSP")
.def("to_IEnumAAFLocatorsSP", query_interface_pass_through<IEnumAAFLocatorsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFLocators > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFLocatorsSP, classname_IEnumAAFLocators> )
;
class_< IEnumAAFMobSlotsSP , bases < AxSmartPointer >  > ("IEnumAAFMobSlotsSP")
.def("to_IEnumAAFMobSlotsSP", query_interface_pass_through<IEnumAAFMobSlotsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFMobSlots > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFMobSlotsSP, classname_IEnumAAFMobSlots> )
;
class_< IEnumAAFMobsSP , bases < AxSmartPointer >  > ("IEnumAAFMobsSP")
.def("to_IEnumAAFMobsSP", query_interface_pass_through<IEnumAAFMobsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFMobs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFMobsSP, classname_IEnumAAFMobs> )
;
class_< IEnumAAFParameterDefsSP , bases < AxSmartPointer >  > ("IEnumAAFParameterDefsSP")
.def("to_IEnumAAFParameterDefsSP", query_interface_pass_through<IEnumAAFParameterDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFParameterDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFParameterDefsSP, classname_IEnumAAFParameterDefs> )
;
class_< IEnumAAFParametersSP , bases < AxSmartPointer >  > ("IEnumAAFParametersSP")
.def("to_IEnumAAFParametersSP", query_interface_pass_through<IEnumAAFParametersSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFParameters > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFParametersSP, classname_IEnumAAFParameters> )
;
class_< IEnumAAFPropertiesSP , bases < AxSmartPointer >  > ("IEnumAAFPropertiesSP")
.def("to_IEnumAAFPropertiesSP", query_interface_pass_through<IEnumAAFPropertiesSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFProperties > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFPropertiesSP, classname_IEnumAAFProperties> )
;
class_< IEnumAAFPropertyDefsSP , bases < AxSmartPointer >  > ("IEnumAAFPropertyDefsSP")
.def("to_IEnumAAFPropertyDefsSP", query_interface_pass_through<IEnumAAFPropertyDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFPropertyDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFPropertyDefsSP, classname_IEnumAAFPropertyDefs> )
;
class_< IEnumAAFPropertyValuesSP , bases < AxSmartPointer >  > ("IEnumAAFPropertyValuesSP")
.def("to_IEnumAAFPropertyValuesSP", query_interface_pass_through<IEnumAAFPropertyValuesSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFPropertyValues > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFPropertyValuesSP, classname_IEnumAAFPropertyValues> )
;
class_< IEnumAAFPluginDefsSP , bases < AxSmartPointer >  > ("IEnumAAFPluginDefsSP")
.def("to_IEnumAAFPluginDefsSP", query_interface_pass_through<IEnumAAFPluginDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFPluginDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFPluginDefsSP, classname_IEnumAAFPluginDefs> )
;
class_< IEnumAAFPluginLocatorsSP , bases < AxSmartPointer >  > ("IEnumAAFPluginLocatorsSP")
.def("to_IEnumAAFPluginLocatorsSP", query_interface_pass_through<IEnumAAFPluginLocatorsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFPluginLocators > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFPluginLocatorsSP, classname_IEnumAAFPluginLocators> )
;
class_< IEnumAAFSegmentsSP , bases < AxSmartPointer >  > ("IEnumAAFSegmentsSP")
.def("to_IEnumAAFSegmentsSP", query_interface_pass_through<IEnumAAFSegmentsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFSegments > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFSegmentsSP, classname_IEnumAAFSegments> )
;
class_< IEnumAAFTaggedValuesSP , bases < AxSmartPointer >  > ("IEnumAAFTaggedValuesSP")
.def("to_IEnumAAFTaggedValuesSP", query_interface_pass_through<IEnumAAFTaggedValuesSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFTaggedValues > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFTaggedValuesSP, classname_IEnumAAFTaggedValues> )
;
class_< IEnumAAFTypeDefsSP , bases < AxSmartPointer >  > ("IEnumAAFTypeDefsSP")
.def("to_IEnumAAFTypeDefsSP", query_interface_pass_through<IEnumAAFTypeDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFTypeDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFTypeDefsSP, classname_IEnumAAFTypeDefs> )
;
class_< IAAFRawStorageSP , bases < AxSmartPointer >  > ("IAAFRawStorageSP")
.def("to_RawStorageSP", query_interface_pass_through<IAAFRawStorageSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFRawStorage > )
;
class_< IAAFRandomRawStorageSP , bases < AxSmartPointer >  > ("IAAFRandomRawStorageSP")
.def("to_RandomRawStorageSP", query_interface_pass_through<IAAFRandomRawStorageSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFRandomRawStorage > )
;
class_< IAAFGetFileBitsSP , bases < AxSmartPointer >  > ("IAAFGetFileBitsSP")
.def("to_GetFileBitsSP", query_interface_pass_through<IAAFGetFileBitsSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFGetFileBits > )
;
class_< IAAFSetFileBitsSP , bases < AxSmartPointer >  > ("IAAFSetFileBitsSP")
.def("to_SetFileBitsSP", query_interface_pass_through<IAAFSetFileBitsSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFSetFileBits > )
;
class_< IAAFRandomFileSP , bases < AxSmartPointer >  > ("IAAFRandomFileSP")
.def("to_RandomFileSP", query_interface_pass_through<IAAFRandomFileSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFRandomFile > )
.def("GetClassName",PyGetClassName_from_string<IAAFRandomFileSP, classname_RandomFile> )
;
class_< IAAFEndianSP , bases < AxSmartPointer >  > ("IAAFEndianSP")
.def("to_EndianSP", query_interface_pass_through<IAAFEndianSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEndian > )
;
class_< IAAFSearchSourceSP , bases < AxSmartPointer >  > ("IAAFSearchSourceSP")
.def("to_SearchSourceSP", query_interface_pass_through<IAAFSearchSourceSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFSearchSource > )
;
class_< IAAFEssenceMultiAccessSP , bases < AxSmartPointer >  > ("IAAFEssenceMultiAccessSP")
.def("to_EssenceMultiAccessSP", query_interface_pass_through<IAAFEssenceMultiAccessSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEssenceMultiAccess > )
.def("to_EssenceAccessSP", query_interface<IAAFEssenceMultiAccess, IAAFEssenceAccess > )
.def("GetClassName",PyGetClassName_from_string<IAAFEssenceMultiAccessSP, classname_EssenceMultiAccess> )
;
class_< IAAFTypeDefVariableArrayExSP , bases < AxSmartPointer >  > ("IAAFTypeDefVariableArrayExSP")
.def("to_TypeDefVariableArrayExSP", query_interface_pass_through<IAAFTypeDefVariableArrayExSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTypeDefVariableArrayEx > )
.def("GetClassName",PyGetTypeCategory<IAAFTypeDefVariableArrayExSP, AxTypeDefVariableArrayEx> )
;
class_< IAAFAES3PCMDescriptorSP , bases < AxSmartPointer >  > ("IAAFAES3PCMDescriptorSP")
.def("to_AES3PCMDescriptorSP", query_interface_pass_through<IAAFAES3PCMDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFAES3PCMDescriptor > )
;
class_< IAAFAuxiliaryDescriptorSP , bases < AxSmartPointer >  > ("IAAFAuxiliaryDescriptorSP")
.def("to_AuxiliaryDescriptorSP", query_interface_pass_through<IAAFAuxiliaryDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFAuxiliaryDescriptor > )
.def("GetClassName",PyGetClassName<IAAFAuxiliaryDescriptor, AxAuxiliaryDescriptor> )
;
class_< IAAFComponent2SP , bases < AxSmartPointer >  > ("IAAFComponent2SP")
.def("to_Component2SP", query_interface_pass_through<IAAFComponent2SP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFComponent2 > )
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
.def("GetClassName",PyGetClassName<IAAFComponent2, AxComponent> )
;
class_< IAAFDataDef2SP , bases < AxSmartPointer >  > ("IAAFDataDef2SP")
.def("to_DataDef2SP", query_interface_pass_through<IAAFDataDef2SP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDataDef2 > )
.def("GetClassName",PyGetClassName<IAAFDataDef2, AxDataDef> )
;
class_< IAAFDataDef3SP , bases < AxSmartPointer >  > ("IAAFDataDef3SP")
.def("to_DataDef3SP", query_interface_pass_through<IAAFDataDef3SP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDataDef3 > )
.def("GetClassName",PyGetClassName<IAAFDataDef3, AxDataDef> )
;
class_< IAAFDescriptiveFrameworkSP , bases < AxSmartPointer >  > ("IAAFDescriptiveFrameworkSP")
.def("to_DescriptiveFrameworkSP", query_interface_pass_through<IAAFDescriptiveFrameworkSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDescriptiveFramework > )
.def("GetClassName",PyGetClassName<IAAFDescriptiveFramework, AxDescriptiveFramework> )
;
class_< IAAFDescriptiveMarkerSP , bases < AxSmartPointer >  > ("IAAFDescriptiveMarkerSP")
.def("to_DescriptiveMarkerSP", query_interface_pass_through<IAAFDescriptiveMarkerSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDescriptiveMarker > )
.def("GetClassName",PyGetClassName<IAAFDescriptiveMarker, AxDescriptiveMarker> )
;
class_< IAAFDictionary2SP , bases < AxSmartPointer >  > ("IAAFDictionary2SP")
.def("to_Dictionary2SP", query_interface_pass_through<IAAFDictionary2SP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDictionary2 > )
.def("GetClassName",PyGetClassName<IAAFDictionary2, AxDictionary> )
;
class_< IAAFHeader2SP , bases < AxSmartPointer >  > ("IAAFHeader2SP")
.def("to_Header2SP", query_interface_pass_through<IAAFHeader2SP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFHeader2 > )
.def("GetClassName",PyGetClassName<IAAFHeader2, AxHeader> )
;
class_< IAAFImportDescriptorSP , bases < AxSmartPointer >  > ("IAAFImportDescriptorSP")
.def("to_ImportDescriptorSP", query_interface_pass_through<IAAFImportDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFImportDescriptor > )
.def("GetClassName",PyGetClassName<IAAFImportDescriptor, AxImportDescriptor> )
;
class_< IAAFKLVDataDefinitionSP , bases < AxSmartPointer >  > ("IAAFKLVDataDefinitionSP")
.def("to_KLVDataDefinitionSP", query_interface_pass_through<IAAFKLVDataDefinitionSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFKLVDataDefinition > )
.def("GetClassName",PyGetClassName<IAAFKLVDataDefinition, AxKLVDataDef> )
;
class_< IAAFMob2SP , bases < AxSmartPointer >  > ("IAAFMob2SP")
.def("to_Mob2SP", query_interface_pass_through<IAAFMob2SP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFMob2 > )
.def("to_MasterMobSP", query_interface<IAAFMob2, IAAFMasterMob > )
.def("to_MasterMob2SP", query_interface<IAAFMob2, IAAFMasterMob2 > )
.def("to_MasterMobExSP", query_interface<IAAFMob2, IAAFMasterMobEx > )
.def("to_SourceMobSP", query_interface<IAAFMob2, IAAFSourceMob > )
.def("to_CompositionMobSP", query_interface<IAAFMob2, IAAFCompositionMob > )
.def("to_CompositionMob2SP", query_interface<IAAFMob2, IAAFCompositionMob2 > )
.def("GetClassName",PyGetClassName<IAAFMob2, AxMob> )
;
class_< IAAFMultipleDescriptorSP , bases < AxSmartPointer >  > ("IAAFMultipleDescriptorSP")
.def("to_MultipleDescriptorSP", query_interface_pass_through<IAAFMultipleDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFMultipleDescriptor > )
;
class_< IAAFPCMDescriptorSP , bases < AxSmartPointer >  > ("IAAFPCMDescriptorSP")
.def("to_PCMDescriptorSP", query_interface_pass_through<IAAFPCMDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFPCMDescriptor > )
.def("GetClassName",PyGetClassName<IAAFPCMDescriptor, AxPCMDescriptor> )
;
class_< IAAFPhysicalDescriptorSP , bases < AxSmartPointer >  > ("IAAFPhysicalDescriptorSP")
.def("to_PhysicalDescriptorSP", query_interface_pass_through<IAAFPhysicalDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFPhysicalDescriptor > )
.def("to_ImportDescriptorSP", query_interface<IAAFPhysicalDescriptor, IAAFImportDescriptor > )
.def("to_RecordingDescriptorSP", query_interface<IAAFPhysicalDescriptor, IAAFRecordingDescriptor > )
.def("to_AuxiliaryDescriptorSP", query_interface<IAAFPhysicalDescriptor, IAAFAuxiliaryDescriptor > )
.def("GetClassName",PyGetClassName<IAAFPhysicalDescriptor, AxPhysicalDescriptor> )
;
class_< IAAFRecordingDescriptorSP , bases < AxSmartPointer >  > ("IAAFRecordingDescriptorSP")
.def("to_RecordingDescriptorSP", query_interface_pass_through<IAAFRecordingDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFRecordingDescriptor > )
.def("GetClassName",PyGetClassName<IAAFRecordingDescriptor, AxRecordingDescriptor> )
;
class_< IAAFRGBADescriptor2SP , bases < AxSmartPointer >  > ("IAAFRGBADescriptor2SP")
.def("to_RGBADescriptor2SP", query_interface_pass_through<IAAFRGBADescriptor2SP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFRGBADescriptor2 > )
.def("GetClassName",PyGetClassName<IAAFRGBADescriptor2, AxRGBADescriptor> )
;
class_< IAAFSoundDescriptorSP , bases < AxSmartPointer >  > ("IAAFSoundDescriptorSP")
.def("to_SoundDescriptorSP", query_interface_pass_through<IAAFSoundDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFSoundDescriptor > )
.def("to_PCMDescriptorSP", query_interface<IAAFSoundDescriptor, IAAFPCMDescriptor > )
.def("GetClassName",PyGetClassName<IAAFSoundDescriptor, AxSoundDescriptor> )
;
class_< IAAFTaggedValueDefinitionSP , bases < AxSmartPointer >  > ("IAAFTaggedValueDefinitionSP")
.def("to_TaggedValueDefinitionSP", query_interface_pass_through<IAAFTaggedValueDefinitionSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTaggedValueDefinition > )
.def("GetClassName",PyGetClassName<IAAFTaggedValueDefinition, AxTaggedValueDef> )
;
class_< IAAFTimelineMobSlot2SP , bases < AxSmartPointer >  > ("IAAFTimelineMobSlot2SP")
.def("to_TimelineMobSlot2SP", query_interface_pass_through<IAAFTimelineMobSlot2SP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFTimelineMobSlot2 > )
.def("GetClassName",PyGetClassName<IAAFTimelineMobSlot2, AxTimelineMobSlot> )
;
class_< IEnumAAFKLVDataDefsSP , bases < AxSmartPointer >  > ("IEnumAAFKLVDataDefsSP")
.def("to_IEnumAAFKLVDataDefsSP", query_interface_pass_through<IEnumAAFKLVDataDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFKLVDataDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFKLVDataDefsSP, classname_IEnumAAFKLVDataDefs> )
;
class_< IEnumAAFTaggedValueDefsSP , bases < AxSmartPointer >  > ("IEnumAAFTaggedValueDefsSP")
.def("to_IEnumAAFTaggedValueDefsSP", query_interface_pass_through<IEnumAAFTaggedValueDefsSP > )
.def("ResolveSP", resolve_any_smartpointer< IEnumAAFTaggedValueDefs > )
.def("GetClassName",PyGetClassName_from_string<IEnumAAFTaggedValueDefsSP, classname_IEnumAAFTaggedValueDefs> )
;
class_< IAAFBWFImportDescriptorSP , bases < AxSmartPointer >  > ("IAAFBWFImportDescriptorSP")
.def("to_BWFImportDescriptorSP", query_interface_pass_through<IAAFBWFImportDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFBWFImportDescriptor > )
;
class_< IAAFDataEssenceDescriptorSP , bases < AxSmartPointer >  > ("IAAFDataEssenceDescriptorSP")
.def("to_DataEssenceDescriptorSP", query_interface_pass_through<IAAFDataEssenceDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDataEssenceDescriptor > )
;
class_< IAAFDescriptiveClipSP , bases < AxSmartPointer >  > ("IAAFDescriptiveClipSP")
.def("to_DescriptiveClipSP", query_interface_pass_through<IAAFDescriptiveClipSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDescriptiveClip > )
;
class_< IAAFDescriptiveObjectSP , bases < AxSmartPointer >  > ("IAAFDescriptiveObjectSP")
.def("to_DescriptiveObjectSP", query_interface_pass_through<IAAFDescriptiveObjectSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFDescriptiveObject > )
;
class_< IAAFMPEGVideoDescriptorSP , bases < AxSmartPointer >  > ("IAAFMPEGVideoDescriptorSP")
.def("to_MPEGVideoDescriptorSP", query_interface_pass_through<IAAFMPEGVideoDescriptorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFMPEGVideoDescriptor > )
;
class_< IAAFRIFFChunkSP , bases < AxSmartPointer >  > ("IAAFRIFFChunkSP")
.def("to_RIFFChunkSP", query_interface_pass_through<IAAFRIFFChunkSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFRIFFChunk > )
;
class_< IAAFPluginSP , bases < AxSmartPointer >  > ("IAAFPluginSP")
.def("to_IAAFPluginSP", query_interface_pass_through<IAAFPluginSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFPlugin > )
;
class_< IAAFClassExtensionSP , bases < AxSmartPointer >  > ("IAAFClassExtensionSP")
.def("to_IAAFClassExtensionSP", query_interface_pass_through<IAAFClassExtensionSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFClassExtension > )
;
class_< IAAFEssenceStreamSP , bases < AxSmartPointer >  > ("IAAFEssenceStreamSP")
.def("to_IAAFEssenceStreamSP", query_interface_pass_through<IAAFEssenceStreamSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEssenceStream > )
;
class_< IAAFEssenceDataStreamSP , bases < AxSmartPointer >  > ("IAAFEssenceDataStreamSP")
.def("to_IAAFEssenceDataStreamSP", query_interface_pass_through<IAAFEssenceDataStreamSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEssenceDataStream > )
;
class_< IAAFEssenceCodecSP , bases < AxSmartPointer >  > ("IAAFEssenceCodecSP")
.def("to_IAAFEssenceCodecSP", query_interface_pass_through<IAAFEssenceCodecSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEssenceCodec > )
;
class_< IAAFMultiEssenceCodecSP , bases < AxSmartPointer >  > ("IAAFMultiEssenceCodecSP")
.def("to_IAAFMultiEssenceCodecSP", query_interface_pass_through<IAAFMultiEssenceCodecSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFMultiEssenceCodec > )
;
class_< IAAFEssenceContainerSP , bases < AxSmartPointer >  > ("IAAFEssenceContainerSP")
.def("to_IAAFEssenceContainerSP", query_interface_pass_through<IAAFEssenceContainerSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFEssenceContainer > )
;
class_< IAAFInterpolatorSP , bases < AxSmartPointer >  > ("IAAFInterpolatorSP")
.def("to_IAAFInterpolatorSP", query_interface_pass_through<IAAFInterpolatorSP > )
.def("ResolveSP", resolve_any_smartpointer< IAAFInterpolator > )
;
class_< IUnknownSP , bases < AxSmartPointer >  > ("IUnknownSP")
.def("to_IUnknownSP", query_interface_pass_through<IUnknownSP > )
.def("ResolveSP", resolve_any_smartpointer< IUnknown > )
.def("GetClassName",PyGetClassName_from_string<IUnknownSP, classname_IUnknown> )
;
}

