
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxPropertyValueDump.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================


std::wstring valueDump(AxPropertyValue* value)
{
    std::wstringstream buffer;
    std::wstreambuf * old = std::wcout.rdbuf(buffer.rdbuf());

    AxPropertyValueDump axPropValueDump( std::wcout );
    value->Process( axPropValueDump );
    
    std::wstring text = buffer.str();
    std::wcout.rdbuf(old);
    
    return text;
    
}



// Module ======================================================================
void Export_pyste_src_AxPropertyValueDump()
{


    def("valueDump",valueDump);

}

