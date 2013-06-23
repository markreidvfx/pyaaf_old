
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

class AxIter {};



// Module ======================================================================
void Export_pyste_src_AxIterator()
{


scope* AxIter_scope = new scope(class_<AxIter>("AxIter"));iterator_wrappers<const IAAFClassDefSP, IAAFClassDef, AxClassDefIter, IEnumAAFClassDefsSP>().wrap("ClassDef");
iterator_wrappers<const IAAFCodecDefSP, IAAFCodecDef, AxCodecDefsIter, IEnumAAFCodecDefsSP>().wrap("CodecDefs");
iterator_wrappers<const IAAFComponentSP, IAAFComponent, AxComponentsIter, IEnumAAFComponentsSP>().wrap("Components");
iterator_wrappers<const IAAFContainerDefSP, IAAFContainerDef, AxContainerDefsIter, IEnumAAFContainerDefsSP>().wrap("ContainerDefs");
iterator_wrappers<const IAAFControlPointSP, IAAFControlPoint, AxControlPointIter, IEnumAAFControlPointsSP>().wrap("ControlPoint");
iterator_wrappers<const IAAFDataDefSP, IAAFDataDef, AxDataDefsIter, IEnumAAFDataDefsSP>().wrap("DataDefs");
iterator_wrappers<const IAAFInterpolationDefSP, IAAFInterpolationDef, AxInterpolationDefsIter, IEnumAAFInterpolationDefsSP>().wrap("InterpolationDefs");
iterator_wrappers<const IAAFOperationDefSP, IAAFOperationDef, AxOperationDefIter, IEnumAAFOperationDefsSP>().wrap("OperationDef");
iterator_wrappers<const IAAFEssenceDataSP, IAAFEssenceData, AxEssenceIter, IEnumAAFEssenceDataSP>().wrap("Essence");
iterator_wrappers<const IAAFKLVDataDefinitionSP, IAAFKLVDataDefinition, AxKLVDataDefsIter, IEnumAAFKLVDataDefsSP>().wrap("KLVDataDefs");
iterator_wrappers<const IAAFLocatorSP, IAAFLocator, AxLocatorIter, IEnumAAFLocatorsSP>().wrap("Locator");
iterator_wrappers<const IAAFMobSlotSP, IAAFMobSlot, AxMobSlotIter, IEnumAAFMobSlotsSP>().wrap("MobSlot");
iterator_wrappers<const IAAFMobSP, IAAFMob, AxMobIter, IEnumAAFMobsSP>().wrap("Mob");
iterator_wrappers<const IAAFParameterDefSP, IAAFParameterDef, AxParameterDefsIter, IEnumAAFParameterDefsSP>().wrap("ParameterDefs");
iterator_wrappers<const IAAFParameterSP, IAAFParameter, AxParameterIter, IEnumAAFParametersSP>().wrap("Parameter");
iterator_wrappers<const IAAFPropertySP, IAAFProperty, AxPropertyIter, IEnumAAFPropertiesSP>().wrap("Property");
iterator_wrappers<const IAAFPropertyDefSP, IAAFPropertyDef, AxPropertyDefIter, IEnumAAFPropertyDefsSP>().wrap("PropertyDef");
iterator_wrappers<const IAAFPropertyValueSP, IAAFPropertyValue, AxPropertyValueIter, IEnumAAFPropertyValuesSP>().wrap("PropertyValue");
iterator_wrappers<const IAAFPluginDefSP, IAAFPluginDef, AxPluginDefsIter, IEnumAAFPluginDefsSP>().wrap("PluginDefs");
iterator_wrappers<const IAAFSegmentSP, IAAFSegment, AxSegmentsIter, IEnumAAFSegmentsSP>().wrap("Segments");
iterator_wrappers<const IAAFTaggedValueSP, IAAFTaggedValue, AxTaggedValuesIter, IEnumAAFTaggedValuesSP>().wrap("TaggedValues");
iterator_wrappers<const IAAFTypeDefSP, IAAFTypeDef, AxTypeDefIter, IEnumAAFTypeDefsSP>().wrap("TypeDef");
delete AxIter_scope;
}

