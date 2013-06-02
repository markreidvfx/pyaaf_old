
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFTypeDefUIDs.h>
#include <AxBaseObjIter.h>
#include <AxDictionary.h>
#include <AxHeader.h>
#include <AxMetaDef.h>
#include <AxPropertyValue.h>
#include <query_interface.h>

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
    boost::python::tuple next();
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

boost::python::tuple PyBaseObjectRecIter::next()
{
    std::auto_ptr<AxBaseObj> nextPtr;
    bool nextExists;
    
    
    nextExists = recIter->NextOne(nextPtr,level.getRef());
    if (!nextExists) {
        PyErr_SetString(PyExc_StopIteration, "No more data.");
        boost::python::throw_error_already_set();
    }
    
    if (dynamic_cast< AxBaseObjAny<AxRecordIterator::Pair>* >( nextPtr.get()))
    {
        IUnknownSP sp = *nextPtr.get();
        std::auto_ptr< AxBaseObjAny<AxRecordIterator::Pair> > recPair(
                                                                  dynamic_cast< AxBaseObjAny<AxRecordIterator::Pair>* >( nextPtr.release() ) );
        
        AxString text = recPair->get().first;
        
        return boost::python::make_tuple(text, recPair->get().second);
        
    }
    
    else
    {
    
    AxString text = L"";
    IUnknownSP sp = *nextPtr.get();
        
        
        if ( PyAxIsA<IAAFObject>(sp) )
        {
            
            IAAFObjectSP obj = query_interface<IUnknown, IAAFObject>(sp);
            
            return boost::python::make_tuple(text, obj);
        }
        
        
        else if ( PyAxIsA<IAAFProperty>(sp) )
        {
            
            IAAFPropertySP obj = query_interface<IUnknown, IAAFProperty>(sp);
            
            return boost::python::make_tuple(text, obj);

        }
        
        else if ( PyAxIsA<IAAFPropertyValue>(sp) )
        {
            
            IAAFPropertyValueSP obj = query_interface<IUnknown, IAAFPropertyValue>(sp);
            
            return boost::python::make_tuple(text, obj);
        }
        
    return boost::python::make_tuple(text, sp);
    
    }

}

int PyBaseObjectRecIter::GetLevel()
{
    
    return level.getRef();
}

inline boost::python::object pass_through(boost::python::object const& o) { return o; }

class AxPropValueRenamePeskyOpaques : public AxPropertyValueNoopPrtcl {
public:
    
    AxPropValueRenamePeskyOpaques( AxDictionary& axDict )
    : _axDict( axDict ),
    _count(0)
    {}
    
    virtual ~AxPropValueRenamePeskyOpaques()
    {}
    
    virtual void process( IAAFPropertyValueSP& spPropVal,
                         IAAFTypeDefOpaqueSP& spTypeDefOpaque )
    {
        AxTypeDefOpaque axOpaque( spTypeDefOpaque );
        
        aafUID_t typeUid = axOpaque.GetActualTypeID( spPropVal );
        
        if ( !_axDict.isKnownTypeDef( typeUid ) ) {
            
            AxTypeDef axBaseTypeDef( _axDict.LookupTypeDef( kAAFTypeID_UInt8Array ) );
            
            AxTypeDefRename axTypeDefRename(
                                            AxCreateMetaInstance<IAAFTypeDefRename>( _axDict ) );
            
            axTypeDefRename.Initialize( typeUid, axBaseTypeDef, AxString( L"Opaque Data" ) );
            
            _axDict.RegisterOpaqueTypeDef( axTypeDefRename );
            
            _count++;
        }
    }
    
    int GetCount()
    {return _count;}
    
private:
    AxDictionary& _axDict;
    int _count;
};



int renamePeskyOpaques( AxHeader& axHeader)
{
    using namespace std;
    
    AxDictionary axDict(axHeader.GetDictionary());
    
    auto_ptr< AxBaseObjIterPrtcl > axHeaderIter(
                                                new AxBaseSolitaryObjIter<AxHeader>(axHeader) );
    
    AxBaseObjRecIter recIter( axHeaderIter );
    
    bool nextExists;
    auto_ptr<AxBaseObj> nextPtr;
    Level level(0);
    
    int count = 0;
    
    for( nextExists = recIter.NextOne( nextPtr, level.getRef() );
        nextExists;
        nextExists = recIter.NextOne( nextPtr, level.getRef() ) ) {
        
        if ( dynamic_cast<AxPropertyValue*>( nextPtr.get() ) ) {
            
            auto_ptr<AxPropertyValue> propVal(
                                              dynamic_cast<AxPropertyValue*>( nextPtr.release() ) );
            
            AxPropValueRenamePeskyOpaques axPropValueRenamePeskyOpaques( axDict );
            
            propVal->Process( axPropValueRenamePeskyOpaques );
            
            count += axPropValueRenamePeskyOpaques.GetCount();
        }
    }
    
    return count;
}




// Module ======================================================================
void Export_pyste_src_AxBaseObjIter()
{


    class_<PyBaseObjectRecIter ,boost::noncopyable > ("BaseObjectRecIter",init <AxHeader> ())
           .def("next", &PyBaseObjectRecIter::next)
           .def("__iter__", pass_through)
           .def("GetLevel",&PyBaseObjectRecIter::GetLevel)
    ;

    def("renamePeskyOpaques",renamePeskyOpaques);
}

