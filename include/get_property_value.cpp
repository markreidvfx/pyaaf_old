#include <get_property_value.h>

boost::python::object PyGetValue::GetObject()
{
    return _obj;
}

boost::python::object PyGetValue::GetInteger( const IAAFPropertyValueSP& spPropVal, IAAFTypeDefIntSP& spTypeDef)
{
    AxTypeDefInt axIntDef(spTypeDef);
    AxPropertyValue axValue(spPropVal);
    aafUInt32 size = axIntDef.GetSize();
    
    if (axIntDef.IsSigned())
    {
        if (sizeof(aafInt8) == size)
            return boost::python::object(GetInt<aafInt8>(axValue));
        else if (sizeof(aafInt16) == size)
            return boost::python::object(GetInt<aafInt16>(axValue));
        else if (sizeof(aafInt32) == size)
            return boost::python::object(GetInt<aafInt32>(axValue));
        else
            return boost::python::object(GetInt<aafInt64>(axValue));
    }
    else
    {
        if (sizeof(aafUInt8) == size)
            return boost::python::object(GetInt<aafUInt8>(axValue));
        else if (sizeof(aafUInt16) == size)
            return boost::python::object(GetInt<aafUInt16>(axValue));
        else if (sizeof(aafUInt32) == size)
            return boost::python::object(GetInt<aafUInt32>(axValue));
        else
            return boost::python::object(GetInt<aafUInt64>(axValue));
    }
    
    
}




void PyGetValue::processAny(IAAFPropertyValueSP& spPropVal)
{
    AxPropertyValue axValue(spPropVal);
    IAAFTypeDefSP spTypeDef = axValue.GetType();
    AxTypeDef axTypeDef(spTypeDef);
    
    if (axTypeDef.GetAUID() == kAAFTypeID_DateStruct)
    {
        aafDateStruct_t date = GetDate(axValue);
        _obj = boost::python::object( DateToString(date));
    }
    else if (axTypeDef.GetAUID() == kAAFTypeID_TimeStruct)
    {
        _aafTimeStruct_t time = GetTime( axValue);
        
        _obj = boost::python::object(TimeToString(time));
        
    }
    
    else if (axTypeDef.GetAUID() == kAAFTypeID_TimeStamp)
    {
        _aafTimeStamp_t timeStamp = GetTimeStamp(axValue);
        _obj = boost::python::object(TimeStampToString( timeStamp ));
    }
    
    else if (axTypeDef.GetAUID() == kAAFTypeID_AUID)
    {
        
        aafUID_t uid = GetUID( axValue);
        _obj = boost::python::object(uid);
    }
    
    else
    {
        
        eAAFTypeCategory_t cat = axTypeDef.GetTypeCategory();
        
        switch( cat )
        {
                
                #define CASE(T)	\
                case kAAFTypeCat##T :	\
                { \
                IAAFTypeDef##T##SP sp; \
                AxQueryInterface( axTypeDef.GetTypeDefSP(), sp ); \
                this->process( spPropVal, sp ); \
                break; \
                }
                        
                CASE( Int )
                CASE( Character )
                CASE( StrongObjRef )
                CASE( WeakObjRef )
                CASE( Rename )
                CASE( Enum )
                CASE( FixedArray )
                // CASE( VariableArray )
                CASE( Set )
                CASE( Record )
                CASE( Stream )
                CASE( String )
                CASE( ExtEnum )
                CASE( Indirect )
                CASE( Opaque )
                CASE( VariableArray )
                
                #undef CASE
                
            case kAAFTypeCatUnknown:
                // FIXME - What to do here?  Get RawAccessType perhaps, but how is that
                // distinquished from encrypted using only the process() argument type?
                break;
            case kAAFTypeCatEncrypted:
                // FIXME - see kAAFTypeCatUnknown above.
                break;
                
            default:
                throw AxExBadImp( L"unknown type category" );
        
        }
    
    }
    
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefCharacterSP& spTypeDef)
{
  throw std::invalid_argument("IAAFTypeDefCharacterSP Not Implemented");  
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefIndirectSP& spTypeDef )
{
    AxTypeDefIndirect axIndirect( spTypeDef );
    
    IAAFPropertyValueSP actualValueSP = axIndirect.GetActualValue(spPropVal);
    
    PyGetValue valueGetter;
    valueGetter.processAny(actualValueSP);
    
    _obj = valueGetter.GetObject();
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefIntSP& spTypeDef)
{
    _obj = this->GetInteger(spPropVal,spTypeDef);
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefRenameSP& spTypeDef)
{
    
    AxTypeDefRename axTDR(spTypeDef);
    IAAFPropertyValueSP spRealValue = axTDR.GetBaseValue(spPropVal);
    
    PyGetValue valueGetter;
    valueGetter.processAny(spRealValue);
    
    _obj = valueGetter.GetObject();

}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefEnumSP& spTypeDef)
{
    AxTypeDefEnum axTDE(spTypeDef);
    aafUInt32 size = axTDE.CountElements();
    
    boost::python::dict d;
    
    for ( aafUInt32 i = 0; i<size; i++ )
    {
        AxString name = axTDE.GetElementName(i);
        aafInt64 id = axTDE.GetElementValue(i);
        d[name] = id;
        
    }
    _obj = d;
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefExtEnumSP& spTypeDef)
{
    
    
    AxTypeDefExtEnum axTDEE(spTypeDef);
    aafUInt32 size = axTDEE.CountElements();
    
    boost::python::dict d;
    
    for ( aafUInt32 i = 0; i<size; i++ )
    {
        AxString name = axTDEE.GetElementName(i);
        aafUID_t id = axTDEE.GetElementValue(i);
        
        d[name] = id;
        
    }
    _obj = d;

}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefFixedArraySP& spTypeDef)
{
    
    AxTypeDefFixedArray axTDFA(spTypeDef);
    
    
    aafUInt32 size = axTDFA.GetCount();
    
    boost::python::list elements;
    
    for ( aafUInt32 i = 0; i<size; i++ )
    {
        
        IAAFPropertyValueSP spElement = axTDFA.GetElementValue(spPropVal, i);
       
        PyGetValue valueGetter;
        valueGetter.processAny(spElement);
        
        elements.append(valueGetter.GetObject());
        
    }
    
    _obj = elements;

}


void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefRecordSP& spTypeDef)
{
    AxTypeDefRecord axTDR(spTypeDef);
    aafUInt32 size = axTDR.GetCount();
    
    
    boost::python::dict d;
    
    for (aafUInt32 i = 0; i<size; i++)
    {
        
        AxString name = axTDR.GetMemberName(i);
        IAAFPropertyValueSP spValue = axTDR.GetValue(spPropVal, i);
        
        PyGetValue valueGetter;
        valueGetter.processAny(spValue);
        
        d[name] = valueGetter.GetObject();

        
    }
    _obj = d;
    
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefSetSP& spTypeDef)
{
    AxTypeDefSet axDefSet(spTypeDef);
    boost::python::list elements;
    AxPropertyValueIter axIter(axDefSet.GetElements(spPropVal));
    

    bool notAtEnd =true;
    while (notAtEnd)
    {
        IAAFSmartPointer2<IAAFPropertyValue> nextValue;
    
    
        notAtEnd = axIter.NextOne(nextValue);
        if (notAtEnd)
        {
            
            IAAFPropertyValueSP spValue = nextValue;
            
            PyGetValue valueGetter;
            valueGetter.processAny(spValue);
            
            elements.append(valueGetter.GetObject());
            
        }
    }
    
    _obj = elements;
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefStreamSP& spTypeDef)
{
    
    //TODO Implemented THIS
    //std::cout << "IAAFTypeDefStreamSP GetValue Not Implemented Yet\n";
    _obj = boost::python::object(0);
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefStringSP& spTypeDef)
{
    
    AxTypeDefString axTypeDefString(spTypeDef);
    AxString value = axTypeDefString.GetElements( spPropVal );
    
    _obj = boost::python::object(value);
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefStrongObjRefSP& spTypeDef)
{
    AxTypeDefStrongObjRef axDefRef(spTypeDef);
    
    IUnknownSP spObj = axDefRef.GetObject<IUnknown>(spPropVal);
    _obj = resolve_smartpointer(spObj);
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefWeakObjRefSP& spTypeDef)
{
    AxTypeDefWeakObjRef axDefWRef(spTypeDef);
    
    IUnknownSP spObj = axDefWRef.GetObject<IUnknown>(spPropVal);
    _obj = resolve_smartpointer(spObj);
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefObjectRefSP& spTypeDef)
{
    throw std::invalid_argument("IAAFTypeDefObjectRefSP Not Implemented");
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefOpaqueSP& spTypeDef)
{
    throw std::invalid_argument("IAAFTypeDefOpaqueSP Not Implemented");
}


void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefVariableArraySP&  spTypeDef)
{
    
    AxTypeDefVariableArray axVarArray( spTypeDef );
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
            IAAFPropertyValueSP spValue = nextValue;

            PyGetValue valueGetter;
            valueGetter.processAny(spValue);
                        
            elements.append(valueGetter.GetObject());

            
        }
        
    }
    
    _obj = elements;
        
}
