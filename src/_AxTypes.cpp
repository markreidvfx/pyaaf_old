
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxTypes.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxTypes()
{
    class_< AxProductIdentification >("AxProductIdentification", init<  >())
        .def(init< const AxProductIdentification& >())
        .def(init< const AxString&, const AxString&, const AxString&, const AxString&, const aafUID_t&, const aafProductVersion_t& >())
    ;

}

