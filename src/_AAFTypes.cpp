
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAF.h>
#include <AAFTypes.h>
#include <AxTypes.h>
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


void string_to_uid(_aafUID_t& id, AxString string)
{
    const wchar_t* uri = string.c_str();
    
    unsigned int bytes[16];
    
    if (wcsncmp(uri, L"urn:uuid", 8) == 0)
    {
        int ret = swscanf(uri,
                          L"urn:uuid:%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
                          &bytes[0], &bytes[1], &bytes[2], &bytes[3],
                          &bytes[4], &bytes[5], &bytes[6], &bytes[7],
                          &bytes[8], &bytes[9], &bytes[10], &bytes[11],
                          &bytes[12], &bytes[13], &bytes[14], &bytes[15]);
        
        if (ret != 16)
        {
            throw "Invalid AUID";
        }
    }
    else
    {
        int ret = swscanf(uri,
                          L"urn:smpte:ul:%02x%02x%02x%02x.%02x%02x%02x%02x.%02x%02x%02x%02x.%02x%02x%02x%02x",
                          &bytes[8], &bytes[9], &bytes[10], &bytes[11],
                          &bytes[12], &bytes[13], &bytes[14], &bytes[15],
                          &bytes[0], &bytes[1], &bytes[2], &bytes[3],
                          &bytes[4], &bytes[5],
                          &bytes[6], &bytes[7]);
        
        if (ret != 16)
        {
            throw "Invalid AUID";
        }
    }
    
    id.Data1 = ((aafInt32)bytes[0] << 24) + ((aafInt32)bytes[1] << 16) +
    ((aafInt32)bytes[2] << 8) + (aafInt32)(bytes[3]);
    id.Data2 = ((aafInt16)bytes[4] << 8) + (aafInt16)(bytes[5]);
    id.Data3 = ((aafInt16)bytes[6] << 8) + (aafInt16)(bytes[7]);
    for (unsigned int i=0; i<8; i++)
    {
        id.Data4[i] = (aafInt8)bytes[i + 8];
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
        .def("fromString",string_to_uid)
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

    class_< _aafSourceRef_t >("aafSourceRef_t", init<  >())
        .def(init< const _aafSourceRef_t& >())
        .def_readwrite("sourceID", &_aafSourceRef_t::sourceID)
        .def_readwrite("sourceSlotID", &_aafSourceRef_t::sourceSlotID)
        .def_readwrite("startTime", &_aafSourceRef_t::startTime)
    ;

    enum_< _aafCompressEnable_e >("aafCompressEnable_e")
        .value("kAAFCompressionEnable", kAAFCompressionEnable)
        .value("kAAFCompressionDisable", kAAFCompressionDisable)
    ;

}

