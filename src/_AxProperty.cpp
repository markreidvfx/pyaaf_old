
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxProperty.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxProperty()
{

    class_<AxProperty ,std::auto_ptr<AxProperty>, boost::noncopyable> ("AxProperty", init <IAAFPropertySP>())
    .def("GetName",&AxProperty::GetName)
    .def("GetValue",&AxProperty::GetValue)
    .def("GetAUID", &AxProperty::GetAUID)
    .def("GetDefinition", &AxProperty::GetDefinition)
    ;

}

