
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxBaseObjIter.h>
#include <AxHeader.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================


class Level {
public:
    
    inline Level(){_l = 0;};
    
    inline Level(int l)
    :_l(l) {};
    
    inline Level& operator=( const Level& rhs )
    {
        _l = rhs._l;
        return *this;
    }
    
    inline int get() const
    {return _l;}
    
    inline int& getRef()
    { return _l; }
    
private:
    int _l;
};


class PyBaseObjectRecIter {
public:
    PyBaseObjectRecIter (AxHeader);
    std::auto_ptr<AxBaseObj> next();
    int GetLevel();
    virtual ~PyBaseObjectRecIter();
    
private:
    std::auto_ptr< AxBaseObjIterPrtcl > axHeaderIter;
    std::auto_ptr< AxBaseObjRecIter > recIter;
    Level level;
    
};

PyBaseObjectRecIter::PyBaseObjectRecIter(AxHeader header)
{

    axHeaderIter.reset(new AxBaseSolitaryObjIter<AxHeader>(header) );
    recIter.reset(new AxBaseObjRecIter(axHeaderIter));

}
PyBaseObjectRecIter::~PyBaseObjectRecIter()
{
}

std::auto_ptr<AxBaseObj> PyBaseObjectRecIter::next()
{
    std::auto_ptr<AxBaseObj> nextPtr;
    bool nextExists;
    
    
    nextExists = recIter->NextOne(nextPtr,level.getRef());
    if (!nextExists) {
        PyErr_SetString(PyExc_StopIteration, "No more data.");
        boost::python::throw_error_already_set();
    }
    
    return nextPtr;
}

int PyBaseObjectRecIter::GetLevel()
{
    
    return level.getRef();
}

inline boost::python::object pass_through(boost::python::object const& o) { return o; }



// Module ======================================================================
void Export_pyste_src_AxBaseObjIter()
{


    class_<PyBaseObjectRecIter ,boost::noncopyable > ("BaseObjectRecIter",init <AxHeader> ())
           .def("next", &PyBaseObjectRecIter::next)
           .def("__iter__", pass_through)
           .def("GetLevel",&PyBaseObjectRecIter::GetLevel)
    ;

}
