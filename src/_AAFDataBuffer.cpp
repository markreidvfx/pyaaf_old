
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFTypes.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class AAFDataBuffer {

public:
    void fill_buffer(boost::python::list);
    aafDataBuffer_t get_buffer();
    inline operator aafDataBuffer_t (){return _buffer;}
    int length(){return _length;}
private:
    aafDataBuffer_t _buffer;
    int _length;
};

void AAFDataBuffer::fill_buffer(boost::python::list pybuff)
{
    int values[boost::python::len(pybuff)];
    
    for (int i=0; i < boost::python::len(pybuff); i++)
    {
        values[i] = boost::python::extract<int>(pybuff[i]);
    }
    _buffer = reinterpret_cast<aafDataBuffer_t>(values);
    _length = boost::python::len(pybuff);
}

aafDataBuffer_t AAFDataBuffer::get_buffer()
{
    return _buffer;
}



// Module ======================================================================
void Export_pyste_src_AAFDataBuffer()
{

    class_<AAFDataBuffer >("AAFDataBuffer")
    .def("fill_buffer",&AAFDataBuffer::fill_buffer)
    ;
    
    implicitly_convertible<AAFDataBuffer,aafDataBuffer_t>();
}

