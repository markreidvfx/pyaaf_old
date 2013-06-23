
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
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
#include <AxSmartPointer.h>
#include <AxStorageErrors.h>
#include <AxTaggedValue.h>
#include <AxTypes.h>
#include <AxUtil.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_implicitly_convertible()
{



//AxConstantValue

     implicitly_convertible<AxConstantValue, IAAFSmartPointer<IAAFConstantValue> > ();

     implicitly_convertible<AxConstantValue, IAAFSmartPointer<IAAFObject> > ();

//AxContainerDef

     implicitly_convertible<AxContainerDef, IAAFSmartPointer<IAAFContainerDef> > ();

     implicitly_convertible<AxContainerDef, IAAFSmartPointer<IAAFDefObject> > ();
     implicitly_convertible<AxContainerDef, IAAFSmartPointer<IAAFObject> > ();

//AxRandomFile

     implicitly_convertible<AxRandomFile, IAAFSmartPointer<IAAFRandomFile> > ();

     implicitly_convertible<AxRandomFile, IAAFSmartPointer<IAAFFile> > ();

//AxInterpolationDef

     implicitly_convertible<AxInterpolationDef, IAAFSmartPointer<IAAFInterpolationDef> > ();

     implicitly_convertible<AxInterpolationDef, IAAFSmartPointer<IAAFDefObject> > ();
     implicitly_convertible<AxInterpolationDef, IAAFSmartPointer<IAAFObject> > ();

//AxObject

     implicitly_convertible<AxObject, IAAFSmartPointer<IAAFObject> > ();


//AxFilmDescriptor

     implicitly_convertible<AxFilmDescriptor, IAAFSmartPointer<IAAFFilmDescriptor> > ();

     implicitly_convertible<AxFilmDescriptor, IAAFSmartPointer<IAAFEssenceDescriptor> > ();
     implicitly_convertible<AxFilmDescriptor, IAAFSmartPointer<IAAFObject> > ();

//AxMob

     implicitly_convertible<AxMob, IAAFSmartPointer<IAAFMob> > ();

     implicitly_convertible<AxMob, IAAFSmartPointer<IAAFObject> > ();

//AxDataDef

     implicitly_convertible<AxDataDef, IAAFSmartPointer<IAAFDataDef> > ();

     implicitly_convertible<AxDataDef, IAAFSmartPointer<IAAFDefObject> > ();
     implicitly_convertible<AxDataDef, IAAFSmartPointer<IAAFObject> > ();

//AxSourceClip

     implicitly_convertible<AxSourceClip, IAAFSmartPointer<IAAFSourceClip> > ();

     implicitly_convertible<AxSourceClip, IAAFSmartPointer<IAAFSourceReference> > ();
     implicitly_convertible<AxSourceClip, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxSourceClip, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxSourceClip, IAAFSmartPointer<IAAFObject> > ();

//AxEssenceDescriptor

     implicitly_convertible<AxEssenceDescriptor, IAAFSmartPointer<IAAFEssenceDescriptor> > ();

     implicitly_convertible<AxEssenceDescriptor, IAAFSmartPointer<IAAFObject> > ();

//AxMobSlot

     implicitly_convertible<AxMobSlot, IAAFSmartPointer<IAAFMobSlot> > ();

     implicitly_convertible<AxMobSlot, IAAFSmartPointer<IAAFObject> > ();

//AxRGBADescriptor

     implicitly_convertible<AxRGBADescriptor, IAAFSmartPointer<IAAFRGBADescriptor> > ();

     implicitly_convertible<AxRGBADescriptor, IAAFSmartPointer<IAAFEssenceDescriptor> > ();
     implicitly_convertible<AxRGBADescriptor, IAAFSmartPointer<IAAFObject> > ();

//AxEventMobSlot

     implicitly_convertible<AxEventMobSlot, IAAFSmartPointer<IAAFEventMobSlot> > ();

     implicitly_convertible<AxEventMobSlot, IAAFSmartPointer<IAAFMobSlot> > ();
     implicitly_convertible<AxEventMobSlot, IAAFSmartPointer<IAAFObject> > ();

//AxNestedScope

     implicitly_convertible<AxNestedScope, IAAFSmartPointer<IAAFNestedScope> > ();

     implicitly_convertible<AxNestedScope, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxNestedScope, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxNestedScope, IAAFSmartPointer<IAAFObject> > ();

//AxEssenceGroup

     implicitly_convertible<AxEssenceGroup, IAAFSmartPointer<IAAFEssenceGroup> > ();

     implicitly_convertible<AxEssenceGroup, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxEssenceGroup, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxEssenceGroup, IAAFSmartPointer<IAAFObject> > ();

//AxStaticMobSlot

     implicitly_convertible<AxStaticMobSlot, IAAFSmartPointer<IAAFStaticMobSlot> > ();

     implicitly_convertible<AxStaticMobSlot, IAAFSmartPointer<IAAFMobSlot> > ();
     implicitly_convertible<AxStaticMobSlot, IAAFSmartPointer<IAAFObject> > ();

//AxDefObject

     implicitly_convertible<AxDefObject, IAAFSmartPointer<IAAFDefObject> > ();

     implicitly_convertible<AxDefObject, IAAFSmartPointer<IAAFObject> > ();

//AxScopeReference

     implicitly_convertible<AxScopeReference, IAAFSmartPointer<IAAFScopeReference> > ();

     implicitly_convertible<AxScopeReference, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxScopeReference, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxScopeReference, IAAFSmartPointer<IAAFObject> > ();

//AxPhysicalDescriptor

     implicitly_convertible<AxPhysicalDescriptor, IAAFSmartPointer<IAAFPhysicalDescriptor> > ();

     implicitly_convertible<AxPhysicalDescriptor, IAAFSmartPointer<IAAFEssenceDescriptor> > ();
     implicitly_convertible<AxPhysicalDescriptor, IAAFSmartPointer<IAAFObject> > ();

//AxHeader

     implicitly_convertible<AxHeader, IAAFSmartPointer<IAAFHeader> > ();

     implicitly_convertible<AxHeader, IAAFSmartPointer<IAAFObject> > ();

//AxImportDescriptor

     implicitly_convertible<AxImportDescriptor, IAAFSmartPointer<IAAFImportDescriptor> > ();

     implicitly_convertible<AxImportDescriptor, IAAFSmartPointer<IAAFPhysicalDescriptor> > ();
     implicitly_convertible<AxImportDescriptor, IAAFSmartPointer<IAAFEssenceDescriptor> > ();
     implicitly_convertible<AxImportDescriptor, IAAFSmartPointer<IAAFObject> > ();

//AxSelector

     implicitly_convertible<AxSelector, IAAFSmartPointer<IAAFSelector> > ();

     implicitly_convertible<AxSelector, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxSelector, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxSelector, IAAFSmartPointer<IAAFObject> > ();

//AxNetworkLocator

     implicitly_convertible<AxNetworkLocator, IAAFSmartPointer<IAAFNetworkLocator> > ();

     implicitly_convertible<AxNetworkLocator, IAAFSmartPointer<IAAFLocator> > ();
     implicitly_convertible<AxNetworkLocator, IAAFSmartPointer<IAAFObject> > ();

//AxAuxiliaryDescriptor

     implicitly_convertible<AxAuxiliaryDescriptor, IAAFSmartPointer<IAAFAuxiliaryDescriptor> > ();

     implicitly_convertible<AxAuxiliaryDescriptor, IAAFSmartPointer<IAAFPhysicalDescriptor> > ();
     implicitly_convertible<AxAuxiliaryDescriptor, IAAFSmartPointer<IAAFEssenceDescriptor> > ();
     implicitly_convertible<AxAuxiliaryDescriptor, IAAFSmartPointer<IAAFObject> > ();

//AxRecordingDescriptor

     implicitly_convertible<AxRecordingDescriptor, IAAFSmartPointer<IAAFRecordingDescriptor> > ();

     implicitly_convertible<AxRecordingDescriptor, IAAFSmartPointer<IAAFPhysicalDescriptor> > ();
     implicitly_convertible<AxRecordingDescriptor, IAAFSmartPointer<IAAFEssenceDescriptor> > ();
     implicitly_convertible<AxRecordingDescriptor, IAAFSmartPointer<IAAFObject> > ();

//AxKLVData

     implicitly_convertible<AxKLVData, IAAFSmartPointer<IAAFKLVData> > ();

     implicitly_convertible<AxKLVData, IAAFSmartPointer<IAAFObject> > ();

//AxClassDef

     implicitly_convertible<AxClassDef, IAAFSmartPointer<IAAFClassDef> > ();


//AxParameterDef

     implicitly_convertible<AxParameterDef, IAAFSmartPointer<IAAFParameterDef> > ();

     implicitly_convertible<AxParameterDef, IAAFSmartPointer<IAAFDefObject> > ();
     implicitly_convertible<AxParameterDef, IAAFSmartPointer<IAAFObject> > ();

//AxOperationGroup

     implicitly_convertible<AxOperationGroup, IAAFSmartPointer<IAAFOperationGroup> > ();

     implicitly_convertible<AxOperationGroup, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxOperationGroup, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxOperationGroup, IAAFSmartPointer<IAAFObject> > ();

//AxMasterMob

     implicitly_convertible<AxMasterMob, IAAFSmartPointer<IAAFMasterMob> > ();

     implicitly_convertible<AxMasterMob, IAAFSmartPointer<IAAFMob> > ();
     implicitly_convertible<AxMasterMob, IAAFSmartPointer<IAAFObject> > ();

//AxEdgecode

     implicitly_convertible<AxEdgecode, IAAFSmartPointer<IAAFEdgecode> > ();

     implicitly_convertible<AxEdgecode, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxEdgecode, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxEdgecode, IAAFSmartPointer<IAAFObject> > ();

//AxTypeDefRename

     implicitly_convertible<AxTypeDefRename, IAAFSmartPointer<IAAFTypeDefRename> > ();

     implicitly_convertible<AxTypeDefRename, IAAFSmartPointer<IAAFTypeDef> > ();

//AxTaggedValueDef

     implicitly_convertible<AxTaggedValueDef, IAAFSmartPointer<IAAFTaggedValueDefinition> > ();

     implicitly_convertible<AxTaggedValueDef, IAAFSmartPointer<IAAFDefObject> > ();
     implicitly_convertible<AxTaggedValueDef, IAAFSmartPointer<IAAFObject> > ();

//AxSourceMob

     implicitly_convertible<AxSourceMob, IAAFSmartPointer<IAAFSourceMob> > ();

     implicitly_convertible<AxSourceMob, IAAFSmartPointer<IAAFMob> > ();
     implicitly_convertible<AxSourceMob, IAAFSmartPointer<IAAFObject> > ();

//AxPropertyValue

     implicitly_convertible<AxPropertyValue, IAAFSmartPointer<IAAFPropertyValue> > ();


//AxKLVDataDef

     implicitly_convertible<AxKLVDataDef, IAAFSmartPointer<IAAFKLVDataDefinition> > ();

     implicitly_convertible<AxKLVDataDef, IAAFSmartPointer<IAAFDefObject> > ();
     implicitly_convertible<AxKLVDataDef, IAAFSmartPointer<IAAFObject> > ();

//AxDictionary

     implicitly_convertible<AxDictionary, IAAFSmartPointer<IAAFDictionary> > ();

     implicitly_convertible<AxDictionary, IAAFSmartPointer<IAAFObject> > ();

//AxTimecodeStream12M

     implicitly_convertible<AxTimecodeStream12M, IAAFSmartPointer<IAAFTimecodeStream12M> > ();

     implicitly_convertible<AxTimecodeStream12M, IAAFSmartPointer<IAAFTimecodeStream> > ();
     implicitly_convertible<AxTimecodeStream12M, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxTimecodeStream12M, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxTimecodeStream12M, IAAFSmartPointer<IAAFObject> > ();

//AxMasterMobEx

     implicitly_convertible<AxMasterMobEx, IAAFSmartPointer<IAAFMasterMobEx> > ();

     implicitly_convertible<AxMasterMobEx, IAAFSmartPointer<IAAFMasterMob> > ();
     implicitly_convertible<AxMasterMobEx, IAAFSmartPointer<IAAFMob> > ();
     implicitly_convertible<AxMasterMobEx, IAAFSmartPointer<IAAFObject> > ();

//AxTimecodeStream

     implicitly_convertible<AxTimecodeStream, IAAFSmartPointer<IAAFTimecodeStream> > ();

     implicitly_convertible<AxTimecodeStream, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxTimecodeStream, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxTimecodeStream, IAAFSmartPointer<IAAFObject> > ();

//AxTimelineMobSlot

     implicitly_convertible<AxTimelineMobSlot, IAAFSmartPointer<IAAFTimelineMobSlot> > ();

     implicitly_convertible<AxTimelineMobSlot, IAAFSmartPointer<IAAFMobSlot> > ();
     implicitly_convertible<AxTimelineMobSlot, IAAFSmartPointer<IAAFObject> > ();

//AxControlPoint

     implicitly_convertible<AxControlPoint, IAAFSmartPointer<IAAFControlPoint> > ();

     implicitly_convertible<AxControlPoint, IAAFSmartPointer<IAAFObject> > ();

//AxTransition

     implicitly_convertible<AxTransition, IAAFSmartPointer<IAAFTransition> > ();

     implicitly_convertible<AxTransition, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxTransition, IAAFSmartPointer<IAAFObject> > ();

//AxTaggedValue

     implicitly_convertible<AxTaggedValue, IAAFSmartPointer<IAAFTaggedValue> > ();

     implicitly_convertible<AxTaggedValue, IAAFSmartPointer<IAAFObject> > ();

//AxCompositionMob

     implicitly_convertible<AxCompositionMob, IAAFSmartPointer<IAAFCompositionMob> > ();

     implicitly_convertible<AxCompositionMob, IAAFSmartPointer<IAAFMob> > ();
     implicitly_convertible<AxCompositionMob, IAAFSmartPointer<IAAFObject> > ();

//AxEssenceFormat

     implicitly_convertible<AxEssenceFormat, IAAFSmartPointer<IAAFEssenceFormat> > ();


//AxDescriptiveMarker

     implicitly_convertible<AxDescriptiveMarker, IAAFSmartPointer<IAAFDescriptiveMarker> > ();

     implicitly_convertible<AxDescriptiveMarker, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxDescriptiveMarker, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxDescriptiveMarker, IAAFSmartPointer<IAAFObject> > ();

//AxOperationDef

     implicitly_convertible<AxOperationDef, IAAFSmartPointer<IAAFOperationDef> > ();

     implicitly_convertible<AxOperationDef, IAAFSmartPointer<IAAFDefObject> > ();
     implicitly_convertible<AxOperationDef, IAAFSmartPointer<IAAFObject> > ();

//AxTapeDescriptor

     implicitly_convertible<AxTapeDescriptor, IAAFSmartPointer<IAAFTapeDescriptor> > ();

     implicitly_convertible<AxTapeDescriptor, IAAFSmartPointer<IAAFEssenceDescriptor> > ();
     implicitly_convertible<AxTapeDescriptor, IAAFSmartPointer<IAAFObject> > ();

//AxDescriptiveFramework

     implicitly_convertible<AxDescriptiveFramework, IAAFSmartPointer<IAAFDescriptiveFramework> > ();

     implicitly_convertible<AxDescriptiveFramework, IAAFSmartPointer<IAAFObject> > ();

//AxPulldown

     implicitly_convertible<AxPulldown, IAAFSmartPointer<IAAFPulldown> > ();

     implicitly_convertible<AxPulldown, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxPulldown, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxPulldown, IAAFSmartPointer<IAAFObject> > ();

//AxPCMDescriptor

     implicitly_convertible<AxPCMDescriptor, IAAFSmartPointer<IAAFPCMDescriptor> > ();

     implicitly_convertible<AxPCMDescriptor, IAAFSmartPointer<IAAFSoundDescriptor> > ();
     implicitly_convertible<AxPCMDescriptor, IAAFSmartPointer<IAAFEssenceDescriptor> > ();
     implicitly_convertible<AxPCMDescriptor, IAAFSmartPointer<IAAFObject> > ();

//AxVaryingValue

     implicitly_convertible<AxVaryingValue, IAAFSmartPointer<IAAFVaryingValue> > ();

     implicitly_convertible<AxVaryingValue, IAAFSmartPointer<IAAFObject> > ();

//AxPropertyDef

     implicitly_convertible<AxPropertyDef, IAAFSmartPointer<IAAFPropertyDef> > ();


//AxLocator

     implicitly_convertible<AxLocator, IAAFSmartPointer<IAAFLocator> > ();

     implicitly_convertible<AxLocator, IAAFSmartPointer<IAAFObject> > ();

//AxComponent

     implicitly_convertible<AxComponent, IAAFSmartPointer<IAAFComponent> > ();

     implicitly_convertible<AxComponent, IAAFSmartPointer<IAAFObject> > ();

//AxSoundDescriptor

     implicitly_convertible<AxSoundDescriptor, IAAFSmartPointer<IAAFSoundDescriptor> > ();

     implicitly_convertible<AxSoundDescriptor, IAAFSmartPointer<IAAFEssenceDescriptor> > ();
     implicitly_convertible<AxSoundDescriptor, IAAFSmartPointer<IAAFObject> > ();

//AxSegment

     implicitly_convertible<AxSegment, IAAFSmartPointer<IAAFSegment> > ();

     implicitly_convertible<AxSegment, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxSegment, IAAFSmartPointer<IAAFObject> > ();

//AxPluginDef

     implicitly_convertible<AxPluginDef, IAAFSmartPointer<IAAFPluginDef> > ();

     implicitly_convertible<AxPluginDef, IAAFSmartPointer<IAAFDefObject> > ();
     implicitly_convertible<AxPluginDef, IAAFSmartPointer<IAAFObject> > ();

//AxCodecDef

     implicitly_convertible<AxCodecDef, IAAFSmartPointer<IAAFCodecDef> > ();

     implicitly_convertible<AxCodecDef, IAAFSmartPointer<IAAFDefObject> > ();
     implicitly_convertible<AxCodecDef, IAAFSmartPointer<IAAFObject> > ();

//AxTypeDef

     implicitly_convertible<AxTypeDef, IAAFSmartPointer<IAAFTypeDef> > ();


//AxSourceReference

     implicitly_convertible<AxSourceReference, IAAFSmartPointer<IAAFSourceReference> > ();

     implicitly_convertible<AxSourceReference, IAAFSmartPointer<IAAFSegment> > ();
     implicitly_convertible<AxSourceReference, IAAFSmartPointer<IAAFComponent> > ();
     implicitly_convertible<AxSourceReference, IAAFSmartPointer<IAAFObject> > ();

//AxFile

     implicitly_convertible<AxFile, IAAFSmartPointer<IAAFFile> > ();


}

