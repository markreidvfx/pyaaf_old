
#include <AAFTypes.h>

class AAFDataBuffer {
    
public:
    void fill_buffer(boost::python::list);
    aafDataBuffer_t get_buffer();
    size_t size();
    inline operator aafDataBuffer_t (){return _buffer;}
    int length(){return _length;}
    
private:
    aafDataBuffer_t _buffer;
    int _length;
};
