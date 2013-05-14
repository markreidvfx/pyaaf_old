
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxBaseObj.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void Export_pyste_src_AxBaseObj()
{

    class_<AxBaseObj ,std::auto_ptr<AxBaseObj>, boost::noncopyable> ("AxBaseObj", no_init);
}

