
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAF.h>
#include <AAFTypes.h>
#include <boost/format.hpp>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

std::string uid_to_string(_aafUID_t& id)
{
    if ((id.Data4[0] & 0x80) != 0 ) // bit 65 of a UUID is 1 for non-NCS UUIDs
    {
    return boost::str(boost::format("urn:uuid:%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x") % (int)id.Data1 % (int)id.Data2 % (int)id.Data3
                      % (int)id.Data4[0] % (int)id.Data4[1] % (int)id.Data4[2] % (int)id.Data4[3]
                      % (int)id.Data4[4] % (int)id.Data4[5] % (int)id.Data4[6] % (int)id.Data4[7]
                      );
    }
    
    else
    {
        return boost::str(boost::format("urn:smpte:ul:%02x%02x%02x%02x.%02x%02x%02x%02x.%08x.%04x%04x")
                          % (int)id.Data4[0] % (int)id.Data4[1] % (int)id.Data4[2] % (int)id.Data4[3]
                          % (int)id.Data4[4] % (int)id.Data4[5] % (int)id.Data4[6] % (int)id.Data4[7]
                          % (int)id.Data1 % (int)id.Data2 % (int)id.Data3
                          );
    }
}


// Module ======================================================================
void Export_pyste_src_AAFTypes()
{

    class_< _aafUID_t >("aafUID_t", init<  >())
        .def(init< const _aafUID_t& >())
        .def_readwrite("Data1", &_aafUID_t::Data1)
        .def_readwrite("Data2", &_aafUID_t::Data2)
        .def_readwrite("Data3", &_aafUID_t::Data3)
        .def("toString",uid_to_string)
        .def("__str__",uid_to_string)
    ;


    class_< _aafRational_t >("aafRational_t", init<  >())
        .def(init< const _aafRational_t& >())
        .def_readwrite("numerator", &_aafRational_t::numerator)
        .def_readwrite("denominator", &_aafRational_t::denominator)
    ;

}

