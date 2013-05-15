
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxHeader.h>
#include <AxIterator.h>
#include <AxProperty.h>
#include <AxPropertyValue.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================


class PyAxObject {
    
public:
    void set_object(std::auto_ptr<AxBaseObj>);
    
    bool isAxObject();
    bool isAxHeader();
    bool isAxProperty();
    bool isAxPropertyValue();
    bool isAxRecordIterator();
    bool isAxExHResult();
    
    std::auto_ptr<AxObject> toAxObject();
    AxHeader* toAxHeader();
    std::auto_ptr<AxProperty> toAxProperty();
    std::auto_ptr<AxPropertyValue> toAxPropertyValue();
    std::auto_ptr<AxBaseObjAny<AxRecordIterator::Pair> > toAxRecordIterator();
    std::auto_ptr<AxBaseObjAny<AxExHResult > > toAxExHResult();

private:
    std::auto_ptr<AxBaseObj> _obj;
};


void PyAxObject::set_object(std::auto_ptr<AxBaseObj> obj)
{
    _obj.reset(obj.release());
}

std::auto_ptr<AxObject> PyAxObject::toAxObject()
{

    if (isAxObject())
    {
        std::auto_ptr<AxObject> obj(dynamic_cast<AxObject*>( _obj.release() ) );
        return obj;
        
    }
        
    else
    {
        PyErr_SetString(PyExc_RuntimeError, "cannot convert to AxObject");
        boost::python::throw_error_already_set();
    }
}

AxHeader* PyAxObject::toAxHeader()
{

    if (isAxHeader())
    {
        std::auto_ptr<AxHeader> obj(dynamic_cast<AxHeader*>( _obj.release() ) );
        return obj.release();
        
    }
        
    else
    {
        PyErr_SetString(PyExc_RuntimeError, "cannot convert to AxHeader");
        boost::python::throw_error_already_set();
    }
}


std::auto_ptr<AxProperty> PyAxObject::toAxProperty()
{
    
    if (isAxProperty())
    {
        std::auto_ptr<AxProperty> obj(dynamic_cast<AxProperty*>( _obj.release() ) );
        return obj;
        
    }
    
    else
    {
        PyErr_SetString(PyExc_RuntimeError, "cannot convert to AxProperty");
        boost::python::throw_error_already_set();
    }
}

std::auto_ptr<AxPropertyValue> PyAxObject::toAxPropertyValue()
{
    
    if (isAxPropertyValue())
    {
        std::auto_ptr<AxPropertyValue> obj(dynamic_cast<AxPropertyValue*>( _obj.release() ) );
        return obj;
        
    }
    
    else
    {
        PyErr_SetString(PyExc_RuntimeError, "cannot convert to AxPropertyValue");
        boost::python::throw_error_already_set();
    }
}


std::auto_ptr<AxBaseObjAny<AxRecordIterator::Pair> > PyAxObject::toAxRecordIterator()
{
    
    if (isAxRecordIterator())
    {
        std::auto_ptr< AxBaseObjAny<AxRecordIterator::Pair> > obj(
                                                                 dynamic_cast< AxBaseObjAny<AxRecordIterator::Pair>* >( _obj.release() ) );
    
        return obj;
        
    }
    
    else
    {
        PyErr_SetString(PyExc_RuntimeError, "cannot convert to AxRecordIterato");
        boost::python::throw_error_already_set();
    }
}


std::auto_ptr<AxBaseObjAny<AxExHResult > > PyAxObject::toAxExHResult()
{
    
    if (isAxExHResult())
    {
        std::auto_ptr<AxBaseObjAny<AxExHResult > > obj(dynamic_cast<AxBaseObjAny<AxExHResult >* >( _obj.release() ) );
        return obj;
        
    }
    
    else
    {
        PyErr_SetString(PyExc_RuntimeError, "cannot convert to AxExHResult");
        boost::python::throw_error_already_set();
    }
}



bool PyAxObject::isAxObject()
{
    if (dynamic_cast<AxObject*>( _obj.get()))
    {
        return true;
    }
    return false;
}

bool PyAxObject::isAxHeader()
{
    if (dynamic_cast<AxHeader*>( _obj.get()))
    {
        return true;
    }
    return false;
}

bool PyAxObject::isAxProperty()
{
    if (dynamic_cast<AxProperty*>( _obj.get()))
    {
        return true;
    }
    return false;
}

bool PyAxObject::isAxPropertyValue()
{
    if (dynamic_cast<AxPropertyValue*>( _obj.get()))
    {
        return true;
    }
    return false;
}

bool PyAxObject::isAxRecordIterator()
{
    if (dynamic_cast< AxBaseObjAny<AxRecordIterator::Pair>* >( _obj.get()))
    {
        return true;
    }
    return false;
}

bool PyAxObject::isAxExHResult()
{
    if (dynamic_cast<AxBaseObjAny<AxExHResult >* > ( _obj.get()))
    {
        return true;
    }
    return false;
}





// Module ======================================================================
void Export_pyste_src_PyAxObject()
{

 class_<PyAxObject,boost::noncopyable> ("PyAxObject")
    .def("set_object",&PyAxObject::set_object)
    .def("isAxObject",&PyAxObject::isAxObject)
    .def("isAxHeader",&PyAxObject::isAxHeader)
    .def("isAxProperty",&PyAxObject::isAxProperty)
    .def("isAxPropertyValue",&PyAxObject::isAxPropertyValue)
    .def("isAxRecordIterator",&PyAxObject::isAxRecordIterator)
    .def("isAxExHResult",&PyAxObject::isAxExHResult)
    
    .def("toAxObject", &PyAxObject::toAxObject)
    .def("toAxHeader", &PyAxObject::toAxHeader,  return_value_policy<manage_new_object>() )
    .def("toAxProperty", &PyAxObject::toAxProperty)
    .def("toAxPropertyValue", &PyAxObject::toAxPropertyValue)
    .def("toAxRecordIterator", &PyAxObject::toAxRecordIterator)
    .def("toAxExHResult", &PyAxObject::toAxExHResult)
    ;
    

}

