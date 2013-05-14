
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxBaseObjIter.h>
#include <AxIterator.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================


class PyRecord {
public:
    void set_object(std::auto_ptr< AxBaseObjAny<AxRecordIterator::Pair> > recPair);
    AxString first();
    IAAFPropertyValueSP second();
    
private:
    std::auto_ptr< AxBaseObjAny<AxRecordIterator::Pair> > _recPair;
    AxString _first;
    IAAFPropertyValueSP _second;
    
};



void PyRecord::set_object(std::auto_ptr< AxBaseObjAny<AxRecordIterator::Pair> > recPair)
{
    
    
    _recPair.reset(recPair.release());
    
    _first = _recPair->get().first;
    _second = _recPair->get().second;
    
}


AxString PyRecord::first()
{
    return _first;
}

IAAFPropertyValueSP PyRecord::second()
{
    return _second;
}





// Module ======================================================================
void Export_pyste_src_PyRecord()
{


    class_<PyRecord,boost::noncopyable> ("PyRecord")
    .def("set_object",&PyRecord::set_object)
    .def("first",&PyRecord::first)
    .def("second",&PyRecord::second)
    ;

    class_< AxBaseObjAny<AxRecordIterator::Pair>, 
           std::auto_ptr<AxBaseObjAny<AxRecordIterator::Pair> > ,
           boost::noncopyable > ("AxAnyRecordIterator",no_init)
    ;

}

