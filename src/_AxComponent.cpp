
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxComponent.h>
#include <create_instance.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxComponent()
{

    class_< AxComponent, boost::noncopyable >("AxComponent", init< IAAFComponentSP >())
        .def(init< IAAFComponent2SP >())
        .def("GetLength", &AxComponent::GetLength)
        .def("ExistsLength", &AxComponent::ExistsLength)
        .def("SetLength", &AxComponent::SetLength)
        .def("SetDataDef", &AxComponent::SetDataDef)
        .def("GetDataDef", &AxComponent::GetDataDef)
        .def("AppendKLVData", &AxComponent::AppendKLVData)
        .def("AppendComment", &AxComponent::AppendComment)
        .def("AppendAttribute", &AxComponent::AppendAttribute)
        .def("CountKLVData", &AxComponent::CountKLVData)
        .def("CountComments", &AxComponent::CountComments)
        .def("CountAttributes", &AxComponent::CountAttributes)
        .def("GetKLVData", &AxComponent::GetKLVData)
        .def("GetComments", &AxComponent::GetComments)
        .def("GetAttributes", &AxComponent::GetAttributes)
        .def("RemoveKLVData", &AxComponent::RemoveKLVData)
        .def("RemoveComment", &AxComponent::RemoveComment)
        .def("RemoveAttribute", &AxComponent::RemoveAttribute)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFComponentSP", &AxComponent::operator IAAFComponentSP)
        .def("to_IAAFComponent2SP", &AxComponent::operator IAAFComponent2SP)
        .def("CreateInstance",create_instance<IAAFComponent, AxComponent>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxSegment, bases< AxComponent > , boost::noncopyable >("AxSegment", init< IAAFSegmentSP >())
        .def("to_IAAFSegmentSP", &AxSegment::operator IAAFSegmentSP)
        .def("CreateInstance",create_instance<IAAFSegment,AxSegment>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxTransition, bases< AxComponent > , boost::noncopyable >("AxTransition", init< IAAFTransitionSP >())
        .def("Initialize", &AxTransition::Initialize)
        .def("GetCutPoint", &AxTransition::GetCutPoint)
        .def("SetCutPoint", &AxTransition::SetCutPoint)
        .def("GetOperationGroup", &AxTransition::GetOperationGroup)
        .def("SetOperationGroup", &AxTransition::SetOperationGroup)
        .def("to_IAAFTransitionSP", &AxTransition::operator IAAFTransitionSP)
        .def("CreateInstance",create_instance<IAAFTransition, AxTransition>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxSequence, bases< AxSegment > , boost::noncopyable >("AxSequence", init< IAAFSequenceSP >())
        .def("Initialize", &AxSequence::Initialize)
        .def("AppendComponent", &AxSequence::AppendComponent)
        .def("PrependComponent", &AxSequence::PrependComponent)
        .def("GetComponents", &AxSequence::GetComponents)
        .def("GetComponentAt", &AxSequence::GetComponentAt)
        .def("InsertComponentAt", &AxSequence::InsertComponentAt)
        .def("RemoveComponentAt", &AxSequence::RemoveComponentAt)
        .def("CountComponents", &AxSequence::CountComponents)
        .def("CreateInstance",create_instance<IAAFSequence, AxSequence>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxTimecode, bases< AxSegment > , boost::noncopyable >("AxTimecode", init< IAAFTimecodeSP >())
        .def("Initialize", &AxTimecode::Initialize)
        .def("GetTimecode", &AxTimecode::GetTimecode)
        .def("SetTimecode", &AxTimecode::SetTimecode)
        .def("CreateInstance",create_instance<IAAFTimecode, AxTimecode>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxFiller, bases< AxSegment > , boost::noncopyable >("AxFiller", init< IAAFFillerSP >())
        .def("Initialize", &AxFiller::Initialize)
        .def("CreateInstance",create_instance<IAAFFiller, AxFiller>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxPulldown, bases< AxSegment > , boost::noncopyable >("AxPulldown", init< IAAFPulldownSP >())
        .def("GetInputSegment", &AxPulldown::GetInputSegment)
        .def("GetPulldownKind", &AxPulldown::GetPulldownKind)
        .def("GetPulldownDirection", &AxPulldown::GetPulldownDirection)
        .def("GetPhaseFrame", &AxPulldown::GetPhaseFrame)
        .def("SetInputSegment", &AxPulldown::SetInputSegment)
        .def("SetPulldownKind", &AxPulldown::SetPulldownKind)
        .def("SetPulldownDirection", &AxPulldown::SetPulldownDirection)
        .def("SetPhaseFrame", &AxPulldown::SetPhaseFrame)
        .def("to_IAAFPulldownSP", &AxPulldown::operator IAAFPulldownSP)
        .def("CreateInstance",create_instance<IAAFPulldown, AxPulldown>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxSourceReference, bases< AxSegment > , boost::noncopyable >("AxSourceReference", init< IAAFSourceReferenceSP >())
        .def("GetSourceID", &AxSourceReference::GetSourceID)
        .def("SetSourceID", &AxSourceReference::SetSourceID)
        .def("GetSourceMobSlotID", &AxSourceReference::GetSourceMobSlotID)
        .def("SetSourceMobSlotID", &AxSourceReference::SetSourceMobSlotID)
        .def("to_IAAFSourceReferenceSP", &AxSourceReference::operator IAAFSourceReferenceSP)
        .def("CreateInstance",create_instance<IAAFSourceReference, AxSourceReference>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxSourceClip, bases< AxSourceReference > , boost::noncopyable >("AxSourceClip", init< IAAFSourceClipSP >())
        .def("Initialize", &AxSourceClip::Initialize)
        .def("SetSourceReference", &AxSourceClip::SetSourceReference)
        .def("GetSourceReference", &AxSourceClip::GetSourceReference)
        .def("ResolveRef", &AxSourceClip::ResolveRef)
        .def("to_IAAFSourceClipSP", &AxSourceClip::operator IAAFSourceClipSP)
        .def("CreateInstance",create_instance<IAAFSourceClip, AxSourceClip>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxOperationGroup, bases< AxSegment > , boost::noncopyable >("AxOperationGroup", init< IAAFOperationGroupSP >())
        .def("Initialize", &AxOperationGroup::Initialize)
        .def("AppendInputSegment", &AxOperationGroup::AppendInputSegment)
        .def("PrependInputSegment", &AxOperationGroup::PrependInputSegment)
        .def("InsertInputSegmentAt", &AxOperationGroup::InsertInputSegmentAt)
        .def("GetInputSegmentAt", &AxOperationGroup::GetInputSegmentAt)
        .def("RemoveInputSegmentAt", &AxOperationGroup::RemoveInputSegmentAt)
        .def("CountSourceSegments", &AxOperationGroup::CountSourceSegments)
        .def("GetOperationDef", &AxOperationGroup::GetOperationDef)
        .def("SetOperationDef", &AxOperationGroup::SetOperationDef)
        .def("GetRender", &AxOperationGroup::GetRender)
        .def("SetRender", &AxOperationGroup::SetRender)
        .def("IsATimeWarp", &AxOperationGroup::IsATimeWarp)
        .def("IsValidTranOperation", &AxOperationGroup::IsValidTranOperation)
        .def("GetBypassOverride", &AxOperationGroup::GetBypassOverride)
        .def("SetBypassOverride", &AxOperationGroup::SetBypassOverride)
        .def("CountParameters", &AxOperationGroup::CountParameters)
        .def("AddParameter", &AxOperationGroup::AddParameter)
        .def("GetParameters", &AxOperationGroup::GetParameters)
        .def("LookupParameter", &AxOperationGroup::LookupParameter)
        .def("to_IAAFOperationGroupSP", &AxOperationGroup::operator IAAFOperationGroupSP)
        .def("CreateInstance",create_instance<IAAFOperationGroup, AxOperationGroup>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxNestedScope, bases< AxSegment > , boost::noncopyable >("AxNestedScope", init< IAAFNestedScopeSP >())
        .def("AppendSegment", &AxNestedScope::AppendSegment)
        .def("PrependSegment", &AxNestedScope::PrependSegment)
        .def("InsertSegmentAt", &AxNestedScope::InsertSegmentAt)
        .def("RemoveSegmentAt", &AxNestedScope::RemoveSegmentAt)
        .def("CountSegments", &AxNestedScope::CountSegments)
        .def("GetSegmentAt", &AxNestedScope::GetSegmentAt)
        .def("GetSegments", &AxNestedScope::GetSegments)
        .def("to_IAAFNestedScopeSP", &AxNestedScope::operator IAAFNestedScopeSP)
        .def("CreateInstance",create_instance<IAAFNestedScope, AxNestedScope>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxScopeReference, bases< AxSegment > , boost::noncopyable >("AxScopeReference", init< IAAFScopeReferenceSP >())
        .def("Initialize", &AxScopeReference::Initialize)
        .def("GetRelativeScope", &AxScopeReference::GetRelativeScope)
        .def("GetRelativeSlot", &AxScopeReference::GetRelativeSlot)
        .def("to_IAAFScopeReferenceSP", &AxScopeReference::operator IAAFScopeReferenceSP)
        .def("CreateInstance",create_instance<IAAFScopeReference, AxScopeReference>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxEssenceGroup, bases< AxSegment > , boost::noncopyable >("AxEssenceGroup", init< IAAFEssenceGroupSP >())
        .def("GetStillFrame", &AxEssenceGroup::GetStillFrame)
        .def("CountChoices", &AxEssenceGroup::CountChoices)
        .def("GetChoiceAt", &AxEssenceGroup::GetChoiceAt)
        .def("to_IAAFEssenceGroupSP", &AxEssenceGroup::operator IAAFEssenceGroupSP)
        .def("CreateInstance",create_instance<IAAFEssenceGroup, AxEssenceGroup>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxSelector, bases< AxSegment > , boost::noncopyable >("AxSelector", init< IAAFSelectorSP >())
        .def("GetSelectedSegment", &AxSelector::GetSelectedSegment)
        .def("EnumAlternateSegments", &AxSelector::EnumAlternateSegments)
        .def("to_IAAFSelectorSP", &AxSelector::operator IAAFSelectorSP)
        .def("CreateInstance",create_instance<IAAFSelector, AxSelector>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxEdgecode, bases< AxSegment > , boost::noncopyable >("AxEdgecode", init< IAAFEdgecodeSP >())
        .def("Initialize", &AxEdgecode::Initialize)
        .def("GetEdgecode", &AxEdgecode::GetEdgecode)
        .def("to_IAAFEdgecodeSP", &AxEdgecode::operator IAAFEdgecodeSP)
        .def("CreateInstance",create_instance<IAAFEdgecode, AxEdgecode>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxEvent, bases< AxSegment > , boost::noncopyable >("AxEvent", init< IAAFEventSP >())
        .def("GetPosition", &AxEvent::GetPosition)
        .def("SetPosition", &AxEvent::SetPosition)
        .def("SetComment", &AxEvent::SetComment)
        .def("GetComment", &AxEvent::GetComment)
        .def("CreateInstance",create_instance<IAAFEvent, AxEvent>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxCommentMarker, bases< AxEvent > , boost::noncopyable >("AxCommentMarker", init< IAAFCommentMarkerSP >())
        .def("GetAnnotation", &AxCommentMarker::GetAnnotation)
        .def("SetAnnotation", &AxCommentMarker::SetAnnotation)
        .def("CreateInstance",create_instance<IAAFCommentMarker, AxCommentMarker>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxGPITrigger, bases< AxEvent > , boost::noncopyable >("AxGPITrigger", init< IAAFGPITriggerSP >())
        .def("GetActiveState", &AxGPITrigger::GetActiveState)
        .def("SetActiveState", &AxGPITrigger::SetActiveState)
        .def("CreateInstance",create_instance<IAAFGPITrigger, AxGPITrigger>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxTimecodeStream, bases< AxSegment > , boost::noncopyable >("AxTimecodeStream", init< IAAFTimecodeStreamSP >())
        .def("GetPositionTimecode", &AxTimecodeStream::GetPositionTimecode)
        .def("GetUserDataLength", &AxTimecodeStream::GetUserDataLength)
        .def("GetSampleRate", &AxTimecodeStream::GetSampleRate)
        .def("GetSourceType", &AxTimecodeStream::GetSourceType)
        .def("GetSampleSize", &AxTimecodeStream::GetSampleSize)
        .def("GetSourceBufLen", &AxTimecodeStream::GetSourceBufLen)
        .def("GetUserDataAtPosition", &AxTimecodeStream::GetUserDataAtPosition)
        .def("GetSource", &AxTimecodeStream::GetSource)
        .def("SetPositionTimecode", &AxTimecodeStream::SetPositionTimecode)
        .def("SetUserDataAtPosition", &AxTimecodeStream::SetUserDataAtPosition)
        .def("SetSampleRate", &AxTimecodeStream::SetSampleRate)
        .def("SetSourceType", &AxTimecodeStream::SetSourceType)
        .def("SetSource", &AxTimecodeStream::SetSource)
        .def("to_IAAFTimecodeStreamSP", &AxTimecodeStream::operator IAAFTimecodeStreamSP)
        .def("CreateInstance",create_instance<IAAFTimecodeStream, AxTimecodeStream>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxTimecodeStream12M, bases< AxTimecodeStream > , boost::noncopyable >("AxTimecodeStream12M", init< IAAFTimecodeStream12MSP >())
        .def("to_IAAFTimecodeStream12MSP", &AxTimecodeStream12M::operator IAAFTimecodeStream12MSP)
        .def("CreateInstance",create_instance<IAAFTimecodeStream12M, AxTimecodeStream12M>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;

    class_< AxDescriptiveMarker, bases< AxCommentMarker > , boost::noncopyable >("AxDescriptiveMarker", init< IAAFDescriptiveMarkerSP >())
        .def("Initialize", &AxDescriptiveMarker::Initialize)
        .def("GetDescribedSlotIDs", &AxDescriptiveMarker::GetDescribedSlotIDs)
        .def("GetDescriptiveFramework", &AxDescriptiveMarker::GetDescriptiveFramework)
        .def("SetDescribedSlotIDs", &AxDescriptiveMarker::SetDescribedSlotIDs)
        .def("SetDescriptiveFramework", &AxDescriptiveMarker::SetDescriptiveFramework)
        .def("to_IAAFDescriptiveMarkerSP", &AxDescriptiveMarker::operator IAAFDescriptiveMarkerSP)
        .def("CreateInstance",create_instance<IAAFDescriptiveMarker, AxDescriptiveMarker>, return_value_policy<manage_new_object>() )
        .staticmethod("CreateInstance")
    ;
}

