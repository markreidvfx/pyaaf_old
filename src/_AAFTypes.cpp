
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

std::string modID_to_string(aafMobID_t& mobId)

{
    
    if (mobId.SMPTELabel[11] == 0x00 && // "not defined" material generation method
        mobId.material.Data4[0] == 0x06 &&
        mobId.material.Data4[1] == 0x0E &&
        mobId.material.Data4[2] == 0x2B &&
        mobId.material.Data4[3] == 0x34 &&
        mobId.material.Data4[4] == 0x7F &&
        mobId.material.Data4[5] == 0x7F)
    {
        
        std::string f = "urn:smpte:umid:%02x%02x%02x%02x.%02x%02x%02x%02x.%02x%02x%02x%02x."
                        "%02x" 
                        "%02x%02x%02x."
                        "%02x%02x%02x%02x.%02x%02x%02x%02x.%08x.%04x%04x";

        return boost::str(boost::format(f)
                          % (int)mobId.SMPTELabel[0] % (int)mobId.SMPTELabel[1] % (int)mobId.SMPTELabel[2] % (int)mobId.SMPTELabel[3]
                          % (int)mobId.SMPTELabel[4] % (int)mobId.SMPTELabel[5] % (int)mobId.SMPTELabel[6] % (int)mobId.SMPTELabel[7]
                          % (int)mobId.SMPTELabel[8] % (int)mobId.SMPTELabel[9] % (int)mobId.SMPTELabel[10] % (int)mobId.SMPTELabel[11]
                          % (int)mobId.length
                          % (int)mobId.instanceHigh % (int)mobId.instanceMid % (int)mobId.instanceLow
                          % (int)mobId.material.Data4[0] % (int)mobId.material.Data4[1] % (int)mobId.material.Data4[2] % (int)mobId.material.Data4[3]
                          % (int)mobId.material.Data4[4] % (int)mobId.material.Data4[5] % (int)mobId.material.Data4[6] % (int)mobId.material.Data4[7]
                          % (int)mobId.material.Data1 % (int)mobId.material.Data2 % (int)mobId.material.Data3
                          
                          
                          );
    }
    
    else
    {
        std::string f = "urn:smpte:umid:%02x%02x%02x%02x.%02x%02x%02x%02x.%02x%02x%02x%02x."
                        "%02x"
                        "%02x%02x%02x."
                        "%08x.%04x%04x.%02x%02x%02x%02x.%02x%02x%02x%02x";
        
        return boost::str(boost::format(f)
                          % (int)mobId.SMPTELabel[0] % (int)mobId.SMPTELabel[1] % (int)mobId.SMPTELabel[2] % (int)mobId.SMPTELabel[3]
                          % (int)mobId.SMPTELabel[4] % (int)mobId.SMPTELabel[5] % (int)mobId.SMPTELabel[6] % (int)mobId.SMPTELabel[7]
                          % (int)mobId.SMPTELabel[8] % (int)mobId.SMPTELabel[9] % (int)mobId.SMPTELabel[10] % (int)mobId.SMPTELabel[11]
                          % (int)mobId.length
                          % (int)mobId.instanceHigh % (int)mobId.instanceMid % (int)mobId.instanceLow
                          % (int)mobId.material.Data1 % (int)mobId.material.Data2 % (int)mobId.material.Data3
                          % (int)mobId.material.Data4[0] % (int)mobId.material.Data4[1] % (int)mobId.material.Data4[2] % (int)mobId.material.Data4[3]
                          % (int)mobId.material.Data4[4] % (int)mobId.material.Data4[5] % (int)mobId.material.Data4[6] % (int)mobId.material.Data4[7]
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

    class_< _aafMobID_t >("aafMobID_t", init<  >())
        .def(init< const _aafMobID_t& >())
        .def_readwrite("length", &_aafMobID_t::length)
        .def_readwrite("instanceHigh", &_aafMobID_t::instanceHigh)
        .def_readwrite("instanceMid", &_aafMobID_t::instanceMid)
        .def_readwrite("instanceLow", &_aafMobID_t::instanceLow)
        .def_readwrite("material", &_aafMobID_t::material)
        .def("toString",modID_to_string)
        .def("__str__",modID_to_string)
    ;

    class_< _aafRational_t >("aafRational_t", init<  >())
        .def(init< const _aafRational_t& >())
        .def_readwrite("numerator", &_aafRational_t::numerator)
        .def_readwrite("denominator", &_aafRational_t::denominator)
    ;

}

