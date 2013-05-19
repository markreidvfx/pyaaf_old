
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFDataBuffer.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

void AAFDataBuffer::fill_buffer(boost::python::list pybuff)
{
    int values[boost::python::len(pybuff)];
    
    unsigned int length = boost::python::len(pybuff);
    
    for (int i=0; i < boost::python::len(pybuff); i++)
    {
        values[i] = boost::python::extract<int>(pybuff[i]);
    }
    _buffer = reinterpret_cast<aafDataBuffer_t>(values);

    _length = length;
    
 
}

aafDataBuffer_t AAFDataBuffer::get_buffer()
{
    return _buffer;
}

size_t AAFDataBuffer::size()
{
    int value = 0;
    return sizeof(value) * _length;
}



// Module ======================================================================
void Export_pyste_src_AAFDataBuffer()
{

    class_<AAFDataBuffer >("AAFDataBuffer")
    .def("fill_buffer",&AAFDataBuffer::fill_buffer)
    .def("sizeof",&AAFDataBuffer::size)
    ;
    
    implicitly_convertible<AAFDataBuffer,aafDataBuffer_t>();
    implicitly_convertible<AAFDataBuffer,unsigned char*>();
}

