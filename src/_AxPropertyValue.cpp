
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxEx.h>
#include <AxPropertyValue.h>
#include <AxPropertyValueDump.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================


std::wstring valueToString(AxPropertyValue& value)
{
    std::wstringstream buffer;
    std::wstreambuf * old = std::wcout.rdbuf(buffer.rdbuf());
    std::wstring text;

    try
        {
            AxPropertyValueDump axPropValueDump( std::wcout );
            value.Process( axPropValueDump );
            text = buffer.str();
        }
    catch (AxExHResult e)
        {
            text = L"Unregistered Data Type";
        }

    std::wcout.rdbuf(old);
    
    return text;
    
}



// Module ======================================================================
void Export_pyste_src_AxPropertyValue()
{


    class_<AxPropertyValue ,std::auto_ptr<AxPropertyValue>, boost::noncopyable> ("AxPropertyValue", init <IAAFPropertyValueSP>())
    .def("GetType",&AxPropertyValue::GetType)
    .def("GetValue",&AxPropertyValue::GetValue)
    .def("toString",valueToString)
    .def("__str__",valueToString)
    ;

}

