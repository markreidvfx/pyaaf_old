
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================

#include <AxIterator.h>
#include <AxMetaDef.h>
#include <AxPropertyValue.h>
#include <AxPropertyValueDump.h>
#include <AxSmartPointer.h>
#include <AxUtil.h>
#include <AAFTypeDefUIDs.h>
#include <utilities.h>


class PyGetValue : public AxPropertyValueNoopPrtcl {
public:
    PyGetValue() {};
    virtual ~PyGetValue(){};
    boost::python::object GetObject();
    boost::python::object GetInteger( const IAAFPropertyValueSP& spPropVal,
                                     IAAFTypeDefIntSP& spTypeDef);
    void processAny(IAAFPropertyValueSP& spPropVal, IAAFTypeDefSP& spTypeDef);
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefCharacterSP& spTypeDef );
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefIndirectSP& spTypeDef );
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefIntSP& spTypeDef);
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefRenameSP& spTypeDef);
	void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefEnumSP& spTypeDef);
	void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefExtEnumSP& spTypeDef);
	void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefFixedArraySP& spTypeDef);
    
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefRecordSP& spTypeDef);
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefSetSP& spTypeDef);
	void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefStreamSP& spTypeDef);
	void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefStringSP& spTypeDef);
	void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefStrongObjRefSP& spTypeDef);
	void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefWeakObjRefSP& spTypeDef);
	void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefObjectRefSP& spTypeDef);
	void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefOpaqueSP& spTypeDef);
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefVariableArraySP&  spTypeDef);

    
private:
    boost::python::object _obj;
};