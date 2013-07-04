
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================

#include <AxIterator.h>
#include <AxMetaDef.h>
#include <AxPropertyValue.h>
#include <AxPropertyValueDump.h>
#include <AxSmartPointer.h>
#include <AAFTypeDefUIDs.h>
#include <utilities.h>


class PyGetValue : public AxPropertyValueNoopPrtcl {
public:
    PyGetValue() {};
    virtual ~PyGetValue(){};
    boost::python::object getObject();
    boost::python::object GetInteger( const IAAFPropertyValueSP& spPropVal,
                                     IAAFTypeDefIntSP& spTypeDef);
    void processAny(IAAFPropertyValueSP& spPropVal, IAAFTypeDef& spTypeDef);
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefCharacterSP& spTypeDef );
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefIndirectSP& spTypeDef );
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefVariableArraySP&  spTypeDef);
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefIntSP& spTypeDef);
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefRecordSP& spTypeDef);
    
private:
    boost::python::object _obj;
};