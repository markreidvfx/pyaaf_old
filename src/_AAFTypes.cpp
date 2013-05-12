
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAF.h>
#include <AAFTypes.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AAFTypes()
{
    class_< _aafUID_t >("aafUID_t", init<  >())
        .def(init< const _aafUID_t& >())
        .def_readwrite("Data1", &_aafUID_t::Data1)
        .def_readwrite("Data2", &_aafUID_t::Data2)
        .def_readwrite("Data3", &_aafUID_t::Data3)
    ;

}

