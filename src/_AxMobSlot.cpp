
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxMobSlot.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxMobSlot()
{
    class_< AxMobSlot, boost::noncopyable >("AxMobSlot", init< IAAFMobSlotSP >())
        .def("SetName", &AxMobSlot::SetName)
        .def("SetSegment", &AxMobSlot::SetSegment)
        .def("SetPhysicalNum", &AxMobSlot::SetPhysicalNum)
        .def("SetSlotID", &AxMobSlot::SetSlotID)
        .def("GetName", (AxString (AxMobSlot::*)() )&AxMobSlot::GetName)
        .def("GetName", (AxString (AxMobSlot::*)(const AxString&) )&AxMobSlot::GetName)
        .def("ExistsName", &AxMobSlot::ExistsName)
        .def("GetSegment", &AxMobSlot::GetSegment)
        .def("GetPhysicalNum", &AxMobSlot::GetPhysicalNum)
        .def("GetSlotID", &AxMobSlot::GetSlotID)
        .def("GetDataDef", &AxMobSlot::GetDataDef)
        .def("ExistsPhysicalNum", &AxMobSlot::ExistsPhysicalNum)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFMobSlotSP", &AxMobSlot::operator IAAFMobSlotSP)
    ;

    class_< AxTimelineMobSlot, bases< AxMobSlot > , boost::noncopyable >("AxTimelineMobSlot", init< IAAFTimelineMobSlotSP >())
        .def(init< IAAFTimelineMobSlot2SP >())
        .def("Initialize", &AxTimelineMobSlot::Initialize)
        .def("SetOrigin", &AxTimelineMobSlot::SetOrigin)
        .def("SetEditRate", &AxTimelineMobSlot::SetEditRate)
        .def("SetMarkIn", &AxTimelineMobSlot::SetMarkIn)
        .def("SetMarkOut", &AxTimelineMobSlot::SetMarkOut)
        .def("SetUserPos", &AxTimelineMobSlot::SetUserPos)
        .def("GetOrigin", &AxTimelineMobSlot::GetOrigin)
        .def("GetEditRate", &AxTimelineMobSlot::GetEditRate)
        .def("GetUserPos", &AxTimelineMobSlot::GetUserPos)
        .def("GetMarkIn", &AxTimelineMobSlot::GetMarkIn)
        .def("GetMarkOut", &AxTimelineMobSlot::GetMarkOut)
        .def("ExistsMarkIn", &AxTimelineMobSlot::ExistsMarkIn)
        .def("ExistsMarkOut", &AxTimelineMobSlot::ExistsMarkOut)
        .def("ExistsUserPos", &AxTimelineMobSlot::ExistsUserPos)
        .def("to_IAAFTimelineMobSlotSP", &AxTimelineMobSlot::operator IAAFTimelineMobSlotSP)
        .def("to_IAAFTimelineMobSlot2SP", &AxTimelineMobSlot::operator IAAFTimelineMobSlot2SP)
    ;

    class_< AxEventMobSlot, bases< AxMobSlot > , boost::noncopyable >("AxEventMobSlot", init< IAAFEventMobSlotSP >())
        .def("SetEditRate", &AxEventMobSlot::SetEditRate)
        .def("GetEditRate", &AxEventMobSlot::GetEditRate)
        .def("to_IAAFEventMobSlotSP", &AxEventMobSlot::operator IAAFEventMobSlotSP)
    ;

    class_< AxStaticMobSlot, bases< AxMobSlot > , boost::noncopyable >("AxStaticMobSlot", init< IAAFStaticMobSlotSP >())
        .def("to_IAAFStaticMobSlotSP", &AxStaticMobSlot::operator IAAFStaticMobSlotSP)
    ;

}

