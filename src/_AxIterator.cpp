
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxIterator.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================



inline object pass_through(object const& o) { return o; }

template<class Klass,class KlassRef, class KlassIter, class KlassIterInit >
struct iterator_wrappers
{
    static Klass
    next(KlassIter& o)
    {
        bool notAtEnd;
        IAAFSmartPointer2<KlassRef> nextMob;
        
        notAtEnd = o.NextOne(nextMob);
        if (!notAtEnd) {
            PyErr_SetString(PyExc_StopIteration, "No more data.");
            boost::python::throw_error_already_set();
        }
        return nextMob;
    }
    
    static void
    wrap(const char* python_name)
    {
        //using namespace boost::python;
        class_<KlassIter>(python_name, init <KlassIterInit>())
        .def("next", next)
        .def("__iter__", pass_through)
        ;
    }
};


// Module ======================================================================
void Export_pyste_src_AxIterator()
{


iterator_wrappers<const IAAFClassDefSP, IAAFClassDef, AxClassDefIter, IEnumAAFClassDefsSP>().wrap("AxClassDefIter");
iterator_wrappers<const IAAFCodecDefSP, IAAFCodecDef, AxCodecDefsIter, IEnumAAFCodecDefsSP>().wrap("AxCodecDefsIter");
iterator_wrappers<const IAAFComponentSP, IAAFComponent, AxComponentsIter, IEnumAAFComponentsSP>().wrap("AxComponentsIter");
iterator_wrappers<const IAAFContainerDefSP, IAAFContainerDef, AxContainerDefsIter, IEnumAAFContainerDefsSP>().wrap("AxContainerDefsIter");
iterator_wrappers<const IAAFControlPointSP, IAAFControlPoint, AxControlPointIter, IEnumAAFControlPointsSP>().wrap("AxControlPointIter");
iterator_wrappers<const IAAFDataDefSP, IAAFDataDef, AxDataDefsIter, IEnumAAFDataDefsSP>().wrap("AxDataDefsIter");
iterator_wrappers<const IAAFInterpolationDefSP, IAAFInterpolationDef, AxInterpolationDefsIter, IEnumAAFInterpolationDefsSP>().wrap("AxInterpolationDefsIter");
iterator_wrappers<const IAAFOperationDefSP, IAAFOperationDef, AxOperationDefIter, IEnumAAFOperationDefsSP>().wrap("AxOperationDefIter");
iterator_wrappers<const IAAFEssenceDataSP, IAAFEssenceData, AxEssenceIter, IEnumAAFEssenceDataSP>().wrap("AxEssenceIter");
iterator_wrappers<const IAAFLocatorSP, IAAFLocator, AxLocatorIter, IEnumAAFLocatorsSP>().wrap("AxLocatorIter");
iterator_wrappers<const IAAFMobSlotSP, IAAFMobSlot, AxMobSlotIter, IEnumAAFMobSlotsSP>().wrap("AxMobSlotIter");
iterator_wrappers<const IAAFMobSP, IAAFMob, AxMobIter, IEnumAAFMobsSP>().wrap("AxMobIter");
iterator_wrappers<const IAAFParameterDefSP, IAAFParameterDef, AxParameterDefsIter, IEnumAAFParameterDefsSP>().wrap("AxParameterDefsIter");
iterator_wrappers<const IAAFParameterSP, IAAFParameter, AxParameterIter, IEnumAAFParametersSP>().wrap("AxParameterIter");
iterator_wrappers<const IAAFPropertySP, IAAFProperty, AxPropertyIter, IEnumAAFPropertiesSP>().wrap("AxPropertyIter");
iterator_wrappers<const IAAFPropertyDefSP, IAAFPropertyDef, AxPropertyDefIter, IEnumAAFPropertyDefsSP>().wrap("AxPropertyDefIter");
iterator_wrappers<const IAAFPropertyValueSP, IAAFPropertyValue, AxPropertyValueIter, IEnumAAFPropertyValuesSP>().wrap("AxPropertyValueIter");
iterator_wrappers<const IAAFPluginDefSP, IAAFPluginDef, AxPluginDefsIter, IEnumAAFPluginDefsSP>().wrap("AxPluginDefsIter");
iterator_wrappers<const IAAFSegmentSP, IAAFSegment, AxSegmentsIter, IEnumAAFSegmentsSP>().wrap("AxSegmentsIter");
iterator_wrappers<const IAAFTypeDefSP, IAAFTypeDef, AxTypeDefIter, IEnumAAFTypeDefsSP>().wrap("AxTypeDefIter");

}

