
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFClassDefUIDs.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class ClassDefUID {};


// Module ======================================================================
void Export_pyste_src_AAFClassDefUIDs()
{

    scope ClassDefUID_scope = class_<ClassDefUID>("ClassDefUID");
    ClassDefUID_scope.attr("Header") = kAAFClassID_Header;
    ClassDefUID_scope.attr("TimecodeStream") = kAAFClassID_TimecodeStream;
    ClassDefUID_scope.attr("RecordingDescriptor") = kAAFClassID_RecordingDescriptor;
    ClassDefUID_scope.attr("TextClip") = kAAFClassID_TextClip;
    ClassDefUID_scope.attr("DataDefinition") = kAAFClassID_DataDefinition;
    ClassDefUID_scope.attr("AuxiliaryDescriptor") = kAAFClassID_AuxiliaryDescriptor;
    ClassDefUID_scope.attr("Sequence") = kAAFClassID_Sequence;
    ClassDefUID_scope.attr("EdgeCode") = kAAFClassID_EdgeCode;
    ClassDefUID_scope.attr("NestedScope") = kAAFClassID_NestedScope;
    ClassDefUID_scope.attr("VaryingValue") = kAAFClassID_VaryingValue;
    ClassDefUID_scope.attr("EventMobSlot") = kAAFClassID_EventMobSlot;
    ClassDefUID_scope.attr("Component") = kAAFClassID_Component;
    ClassDefUID_scope.attr("CompositionMob") = kAAFClassID_CompositionMob;
    ClassDefUID_scope.attr("Parameter") = kAAFClassID_Parameter;
    ClassDefUID_scope.attr("InterchangeObject") = kAAFClassID_InterchangeObject;
    ClassDefUID_scope.attr("TypeDefinitionRename") = kAAFClassID_TypeDefinitionRename;
    ClassDefUID_scope.attr("ParameterDefinition") = kAAFClassID_ParameterDefinition;
    ClassDefUID_scope.attr("MasterMob") = kAAFClassID_MasterMob;
    ClassDefUID_scope.attr("TypeDefinitionOpaque") = kAAFClassID_TypeDefinitionOpaque;
    ClassDefUID_scope.attr("KLVDataDefinition") = kAAFClassID_KLVDataDefinition;
    ClassDefUID_scope.attr("Segment") = kAAFClassID_Segment;
    ClassDefUID_scope.attr("NetworkLocator") = kAAFClassID_NetworkLocator;
    ClassDefUID_scope.attr("TypeDefinitionExtendibleEnumeration") = kAAFClassID_TypeDefinitionExtendibleEnumeration;
    ClassDefUID_scope.attr("ControlPoint") = kAAFClassID_ControlPoint;
    ClassDefUID_scope.attr("TimelineMobSlot") = kAAFClassID_TimelineMobSlot;
    ClassDefUID_scope.attr("FilmDescriptor") = kAAFClassID_FilmDescriptor;
    ClassDefUID_scope.attr("Mob") = kAAFClassID_Mob;
    ClassDefUID_scope.attr("DataEssenceDescriptor") = kAAFClassID_DataEssenceDescriptor;
    ClassDefUID_scope.attr("Event") = kAAFClassID_Event;
    ClassDefUID_scope.attr("OperationGroup") = kAAFClassID_OperationGroup;
    ClassDefUID_scope.attr("TimecodeStream12M") = kAAFClassID_TimecodeStream12M;
    ClassDefUID_scope.attr("PluginDefinition") = kAAFClassID_PluginDefinition;
    ClassDefUID_scope.attr("EssenceGroup") = kAAFClassID_EssenceGroup;
    ClassDefUID_scope.attr("Identification") = kAAFClassID_Identification;
    ClassDefUID_scope.attr("SourceMob") = kAAFClassID_SourceMob;
    ClassDefUID_scope.attr("DefinitionObject") = kAAFClassID_DefinitionObject;
    ClassDefUID_scope.attr("StaticMobSlot") = kAAFClassID_StaticMobSlot;
    ClassDefUID_scope.attr("Locator") = kAAFClassID_Locator;
    ClassDefUID_scope.attr("TextLocator") = kAAFClassID_TextLocator;
    ClassDefUID_scope.attr("TypeDefinitionIndirect") = kAAFClassID_TypeDefinitionIndirect;
    ClassDefUID_scope.attr("ImportDescriptor") = kAAFClassID_ImportDescriptor;
    ClassDefUID_scope.attr("TaggedValueDefinition") = kAAFClassID_TaggedValueDefinition;
    ClassDefUID_scope.attr("DescriptiveObject") = kAAFClassID_DescriptiveObject;
    ClassDefUID_scope.attr("EssenceDescriptor") = kAAFClassID_EssenceDescriptor;
    ClassDefUID_scope.attr("PCMDescriptor") = kAAFClassID_PCMDescriptor;
    ClassDefUID_scope.attr("MPEGVideoDescriptor") = kAAFClassID_MPEGVideoDescriptor;
    ClassDefUID_scope.attr("TypeDefinitionRecord") = kAAFClassID_TypeDefinitionRecord;
    ClassDefUID_scope.attr("CDCIDescriptor") = kAAFClassID_CDCIDescriptor;
    ClassDefUID_scope.attr("TypeDefinitionSet") = kAAFClassID_TypeDefinitionSet;
    ClassDefUID_scope.attr("ConstantValue") = kAAFClassID_ConstantValue;
    ClassDefUID_scope.attr("Timecode") = kAAFClassID_Timecode;
    ClassDefUID_scope.attr("PropertyDefinition") = kAAFClassID_PropertyDefinition;
    ClassDefUID_scope.attr("RGBADescriptor") = kAAFClassID_RGBADescriptor;
    ClassDefUID_scope.attr("DescriptiveClip") = kAAFClassID_DescriptiveClip;
    ClassDefUID_scope.attr("TypeDefinitionFixedArray") = kAAFClassID_TypeDefinitionFixedArray;
    ClassDefUID_scope.attr("TypeDefinitionEnumeration") = kAAFClassID_TypeDefinitionEnumeration;
    ClassDefUID_scope.attr("CommentMarker") = kAAFClassID_CommentMarker;
    ClassDefUID_scope.attr("AIFCDescriptor") = kAAFClassID_AIFCDescriptor;
    ClassDefUID_scope.attr("TIFFDescriptor") = kAAFClassID_TIFFDescriptor;
    ClassDefUID_scope.attr("MultipleDescriptor") = kAAFClassID_MultipleDescriptor;
    ClassDefUID_scope.attr("RIFFChunk") = kAAFClassID_RIFFChunk;
    ClassDefUID_scope.attr("SourceReference") = kAAFClassID_SourceReference;
    ClassDefUID_scope.attr("ClassDefinition") = kAAFClassID_ClassDefinition;
    ClassDefUID_scope.attr("Filler") = kAAFClassID_Filler;
    ClassDefUID_scope.attr("TypeDefinitionCharacter") = kAAFClassID_TypeDefinitionCharacter;
    ClassDefUID_scope.attr("CodecDefinition") = kAAFClassID_CodecDefinition;
    ClassDefUID_scope.attr("Transition") = kAAFClassID_Transition;
    ClassDefUID_scope.attr("TypeDefinitionStream") = kAAFClassID_TypeDefinitionStream;
    ClassDefUID_scope.attr("OperationDefinition") = kAAFClassID_OperationDefinition;
    ClassDefUID_scope.attr("SourceClip") = kAAFClassID_SourceClip;
    ClassDefUID_scope.attr("WAVEDescriptor") = kAAFClassID_WAVEDescriptor;
    ClassDefUID_scope.attr("TypeDefinitionStrongObjectReference") = kAAFClassID_TypeDefinitionStrongObjectReference;
    ClassDefUID_scope.attr("BWFImportDescriptor") = kAAFClassID_BWFImportDescriptor;
    ClassDefUID_scope.attr("TapeDescriptor") = kAAFClassID_TapeDescriptor;
    ClassDefUID_scope.attr("Selector") = kAAFClassID_Selector;
    ClassDefUID_scope.attr("TypeDefinitionInteger") = kAAFClassID_TypeDefinitionInteger;
    ClassDefUID_scope.attr("AES3PCMDescriptor") = kAAFClassID_AES3PCMDescriptor;
    ClassDefUID_scope.attr("GPITrigger") = kAAFClassID_GPITrigger;
    ClassDefUID_scope.attr("PhysicalDescriptor") = kAAFClassID_PhysicalDescriptor;
    ClassDefUID_scope.attr("FileDescriptor") = kAAFClassID_FileDescriptor;
    ClassDefUID_scope.attr("InterpolationDefinition") = kAAFClassID_InterpolationDefinition;
    ClassDefUID_scope.attr("ContentStorage") = kAAFClassID_ContentStorage;
    ClassDefUID_scope.attr("HTMLClip") = kAAFClassID_HTMLClip;
    ClassDefUID_scope.attr("TypeDefinitionString") = kAAFClassID_TypeDefinitionString;
    ClassDefUID_scope.attr("ScopeReference") = kAAFClassID_ScopeReference;
    ClassDefUID_scope.attr("SoundDescriptor") = kAAFClassID_SoundDescriptor;
    ClassDefUID_scope.attr("MetaDictionary") = kAAFClassID_MetaDictionary;
    ClassDefUID_scope.attr("TypeDefinitionVariableArray") = kAAFClassID_TypeDefinitionVariableArray;
    ClassDefUID_scope.attr("MetaDefinition") = kAAFClassID_MetaDefinition;
    ClassDefUID_scope.attr("ContainerDefinition") = kAAFClassID_ContainerDefinition;
    ClassDefUID_scope.attr("MobSlot") = kAAFClassID_MobSlot;
    ClassDefUID_scope.attr("DescriptiveFramework") = kAAFClassID_DescriptiveFramework;
    ClassDefUID_scope.attr("TypeDefinitionWeakObjectReference") = kAAFClassID_TypeDefinitionWeakObjectReference;
    ClassDefUID_scope.attr("EssenceData") = kAAFClassID_EssenceData;
    ClassDefUID_scope.attr("DigitalImageDescriptor") = kAAFClassID_DigitalImageDescriptor;
    ClassDefUID_scope.attr("Pulldown") = kAAFClassID_Pulldown;
    ClassDefUID_scope.attr("HTMLDescriptor") = kAAFClassID_HTMLDescriptor;
    ClassDefUID_scope.attr("KLVData") = kAAFClassID_KLVData;
    ClassDefUID_scope.attr("TaggedValue") = kAAFClassID_TaggedValue;
    ClassDefUID_scope.attr("DescriptiveMarker") = kAAFClassID_DescriptiveMarker;
    ClassDefUID_scope.attr("TypeDefinition") = kAAFClassID_TypeDefinition;
    ClassDefUID_scope.attr("Dictionary") = kAAFClassID_Dictionary;
}

