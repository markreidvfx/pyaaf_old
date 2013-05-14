
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxPropertyValue.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxPropertyValue()
{


    class_<AxPropertyValue ,std::auto_ptr<AxPropertyValue>, boost::noncopyable> ("AxPropertyValue", init <IAAFPropertyValueSP>())
    .def("GetType",&AxPropertyValue::GetType)
    .def("GetValue",&AxPropertyValue::GetValue)
    ;

}

