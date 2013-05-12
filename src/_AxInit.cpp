
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxInit.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxInit()
{
    class_< AxInit >("AxInit", init<  >())
        .def(init< const AxInit& >())
        .def(init< const char* >())
    ;

}

