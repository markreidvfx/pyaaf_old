
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxEx.h>
#include <AxIterator.h>
#include <AxMetaDef.h>
#include <AxPropertyValue.h>
#include <AxPropertyValueDump.h>
#include <AxSmartPointer.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================


std::wstring valueToString(AxPropertyValue& value)
{
    std::wstringstream buffer;
    std::wstreambuf * old = std::wcout.rdbuf(buffer.rdbuf());
    std::wstring text;

    try
        {
            AxPropertyValueDump axPropValueDump( std::wcout );
            value.Process( axPropValueDump );
            text = buffer.str();
        }
    catch (AxExHResult e)
        {
            text = L"Unregistered Data Type";
        }

    std::wcout.rdbuf(old);
    
    return text;
    
}

aafUInt8 GetUInt8( AxPropertyValue axPropertyValue )
{
    AxTypeDef axTypeDef( axPropertyValue.GetType() );
    AxTypeDefInt axTypeDefInt(
                              AxQueryInterface< IAAFTypeDef,
                                                IAAFTypeDefInt > (axTypeDef ) );
    
    aafUInt8 i;
    IAAFPropertyValueSP propValue( axPropertyValue.GetValue() );
    axTypeDefInt.GetInteger( propValue, &i );
    
    return i;
}


class PyValueGet : public AxPropertyValueNoopPrtcl {
public:
    PyValueGet()
    {}
    
    virtual ~PyValueGet()
    {}
    
    boost::python::object getObject()
    {
        return _obj;
    }
    
    void process( IAAFPropertyValueSP&, IAAFTypeDefCharacterSP& )
    {
    }
    
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefIndirectSP& spTypeDef )
    {
        AxTypeDefIndirect axIndirect( spTypeDef );
        AxTypeDef axActualTypeDef( axIndirect.GetActualType(spPropVal) );
        IAAFPropertyValueSP actualPropertyValueSP = axIndirect.GetActualValue(spPropVal);
        
        IAAFTypeDefVariableArraySP spVariableArray;
        if (AxIsA(axActualTypeDef, spVariableArray ))
        {
            
            IAAFTypeDefVariableArraySP sp(AxQueryInterface<IAAFTypeDef,
                                          IAAFTypeDefVariableArray>(axActualTypeDef));

            this->process(actualPropertyValueSP,sp);

        }

    }
    
    void process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefVariableArraySP&  spTypeDef)
    {
        
        AxTypeDefVariableArray axVarArray( spTypeDef );
        AxTypeDef axTypeDefOfArray( axVarArray.GetType() );
        IAAFTypeDefIntSP spTypeDefInt;
        
        if (AxIsA(axTypeDefOfArray,spTypeDefInt))
            {
                
                AxTypeDefInt axTypeDefInt(AxQueryInterface<IAAFTypeDef,
                                      IAAFTypeDefInt>(axTypeDefOfArray));
                
                aafUInt32 size = axVarArray.GetCount(spPropVal);
                
                AxPropertyValueIter axIter(axVarArray.GetElements(spPropVal));
                bool notAtEnd = true;
                
                boost::python::list elements;
                
                for ( aafUInt32 i = 0; i<size; i++ )
                    
                {
                    
                    IAAFSmartPointer2<IAAFPropertyValue> nextValue;
                    notAtEnd = axIter.NextOne(nextValue);
                    

                    if (notAtEnd)
                    {
                        AxPropertyValue value(nextValue);
                        elements.append(GetUInt8(value));
                        
                    }
                    
                    
                    _obj = elements;
                }
                                
                
            }
        
    }
private:
    boost::python::object _obj;
    
};

boost::python::object PyGetValue(AxPropertyValue& ax)
{
    
    PyValueGet valueGetter;
    ax.Process(valueGetter);
    return valueGetter.getObject();

}



// Module ======================================================================
void Export_pyste_src_AxPropertyValue()
{


    class_<AxPropertyValue ,std::auto_ptr<AxPropertyValue>, boost::noncopyable> ("AxPropertyValue", init <IAAFPropertyValueSP>())
    .def("GetType",&AxPropertyValue::GetType)
    .def("GetValue",PyGetValue)
    .def("toString",valueToString)
    .def("__str__",valueToString)
    ;

}

