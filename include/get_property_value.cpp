#include <get_property_value.h>

template < class T>
T GetInt(AxPropertyValue axPropertyValue )
{
    AxTypeDef axTypeDef( axPropertyValue.GetType() );
    AxTypeDefInt axTypeDefInt(
                              AxQueryInterface< IAAFTypeDef,
                              IAAFTypeDefInt > (axTypeDef ) );
    
    T i;
    IAAFPropertyValueSP propValue( axPropertyValue.GetValue() );
    axTypeDefInt.GetInteger( propValue, &i );
    
    return i;
};

_aafDateStruct_t GetDate( AxPropertyValue axPropertyValue )
{
    _aafDateStruct_t retDate;
    
    AxTypeDef axTypeDef( axPropertyValue.GetType() );
    AxTypeDefRecord axTypeDefRecord(
                                    AxQueryInterface< IAAFTypeDef,IAAFTypeDefRecord > (
                                                                                       axTypeDef ) );
    IAAFPropertyValueSP propValue( axPropertyValue.GetValue() );
    
    AxPropertyValue year = axTypeDefRecord.GetValue( propValue, 0 );
    AxPropertyValue month = axTypeDefRecord.GetValue( propValue, 1 );
    AxPropertyValue day = axTypeDefRecord.GetValue( propValue, 2 );
    
    retDate.year = GetInt<aafUInt16>( year );
    retDate.month = GetInt<aafUInt8>( month );
    retDate.day = GetInt<aafUInt8>( day );
    
    return retDate;
}

_aafTimeStruct_t GetTime( AxPropertyValue axPropertyValue )
{
    _aafTimeStruct_t retTime;
    
    AxTypeDef axTypeDef( axPropertyValue.GetType() );
    AxTypeDefRecord axTypeDefRecord(
                                    AxQueryInterface< IAAFTypeDef,IAAFTypeDefRecord > (
                                                                                       axTypeDef ) );
    IAAFPropertyValueSP propValue( axPropertyValue.GetValue() );
    
    AxPropertyValue hour = axTypeDefRecord.GetValue( propValue, 0 );
    AxPropertyValue minute = axTypeDefRecord.GetValue( propValue, 1 );
    AxPropertyValue second = axTypeDefRecord.GetValue( propValue, 2 );
    AxPropertyValue fraction = axTypeDefRecord.GetValue( propValue, 3 );
    
    retTime.hour = (aafUInt8)GetInt<aafUInt16>( hour );
    retTime.minute = GetInt<aafUInt8>( minute );
    retTime.second = GetInt<aafUInt8>( second );
    retTime.fraction = GetInt<aafUInt8>( fraction );
    
    return retTime;
}
std::string TimeToString( _aafTimeStruct_t &time )
{
    char buf[16];
    
    sprintf( buf, "%02d:%02d:%02d.%02d", time.hour, time.minute, time.second, time.fraction );
    
    return buf;
}



boost::python::object PyGetValue::getObject()
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

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefCharacterSP& spTypeDef)
{
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefIndirectSP& spTypeDef )
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

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefVariableArraySP&  spTypeDef)
{
    
    AxTypeDefVariableArray axVarArray( spTypeDef );
    AxTypeDef axTypeDefOfArray( axVarArray.GetType() );
    IAAFTypeDefIntSP spTypeDefInt;
    
    if (AxIsA(axTypeDefOfArray,spTypeDefInt))
    {
        IAAFTypeDefIntSP TypeDefIntSP(AxQueryInterface<IAAFTypeDef,IAAFTypeDefInt>(axTypeDefOfArray));
        AxTypeDefInt axTypeDefInt(TypeDefIntSP);
        
        
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
                elements.append(this->GetInteger(nextValue,TypeDefIntSP));
                
            }
            
            
            _obj = elements;
        }
        
        
    }
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefIntSP& spTypeDef)
{
    _obj = this->GetInteger(spPropVal,spTypeDef);
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
        
        AxPropertyValue axValue(spValue);
        IAAFTypeDefSP spMemTypeDef = axValue.GetType();
        AxTypeDef axDef(spMemTypeDef);
        
        if (axDef.GetAUID() == kAAFTypeID_DateStruct)
        {
            aafDateStruct_t date = GetDate(axValue);
            
            
            d[name] = boost::python::make_tuple(date.year, date.month, date.day);
        }
        else if (axDef.GetAUID() == kAAFTypeID_TimeStruct)
        {
            _aafTimeStruct_t time = GetTime( axValue);
            
            d[name] = TimeToString(time);
            
        }
        
        else
        {
            throw std::invalid_argument("Invalid AUID ");
        }
        
        
        std::wcout << name << " " <<axDef.GetName() << "\n";
        
    }
    _obj = d;
    
    
}
