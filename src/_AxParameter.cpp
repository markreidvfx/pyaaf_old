
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxParameter.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxParameter()
{
    class_< AxParameter, boost::noncopyable >("AxParameter", init< IAAFParameterSP >())
        .def("GetParameterDefinition", &AxParameter::GetParameterDefinition)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFParameterSP", &AxParameter::operator IAAFParameterSP)
    ;

    class_< AxConstantValue, bases< AxParameter > , boost::noncopyable >("AxConstantValue", init< IAAFConstantValueSP >())
        .def("Initialize", &AxConstantValue::Initialize)
        .def("GetValueBufLen", &AxConstantValue::GetValueBufLen)
        .def("GetTypeDefinition", &AxConstantValue::GetTypeDefinition)
        .def("SetValue", &AxConstantValue::SetValue)
        .def("to_IAAFConstantValueSP", &AxConstantValue::operator IAAFConstantValueSP)
    ;

    class_< AxVaryingValue, bases< AxParameter > , boost::noncopyable >("AxVaryingValue", init< IAAFVaryingValueSP >())
        .def("Initialize", &AxVaryingValue::Initialize)
        .def("AddControlPoint", &AxVaryingValue::AddControlPoint)
        .def("RemoveControlPointAt", &AxVaryingValue::RemoveControlPointAt)
        .def("GetControlPoints", &AxVaryingValue::GetControlPoints)
        .def("CountControlPoints", &AxVaryingValue::CountControlPoints)
        .def("GetControlPointAt", &AxVaryingValue::GetControlPointAt)
        .def("GetInterpolationDefinition", &AxVaryingValue::GetInterpolationDefinition)
        .def("GetValueBufLen", &AxVaryingValue::GetValueBufLen)
        .def("GetInterpolatedValue", &AxVaryingValue::GetInterpolatedValue)
        .def("to_IAAFVaryingValueSP", &AxVaryingValue::operator IAAFVaryingValueSP)
    ;

    class_< AxControlPoint, boost::noncopyable >("AxControlPoint", init< IAAFControlPointSP >())
        .def("Initialize", &AxControlPoint::Initialize)
        .def("GetTime", &AxControlPoint::GetTime)
        .def("GetEditHint", &AxControlPoint::GetEditHint)
        .def("GetValueBufLen", &AxControlPoint::GetValueBufLen)
        .def("GetValue", &AxControlPoint::GetValue)
        .def("SetTime", &AxControlPoint::SetTime)
        .def("SetEditHint", &AxControlPoint::SetEditHint)
        .def("GetTypeDefinition", &AxControlPoint::GetTypeDefinition)
        .def("SetValue", &AxControlPoint::SetValue)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFControlPointSP", &AxControlPoint::operator IAAFControlPointSP)
    ;

}

