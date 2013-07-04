#include <get_property_value.h>

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




void PyGetValue::processAny(IAAFPropertyValueSP& spPropVal, IAAFTypeDefSP& spTypeDef)
{
    AxTypeDef axTypeDef(spTypeDef);
    
    
    if (isClassType<IAAFTypeDefInt>(axTypeDef))
    {
        
        IAAFTypeDefIntSP sp(AxQueryInterface<IAAFTypeDef,
                            IAAFTypeDefInt>(axTypeDef));
        
        this->process(spPropVal, sp);
        
        
    }
    
    else if (isClassType<IAAFTypeDefFixedArray>(axTypeDef))
        
    {

        IAAFTypeDefFixedArraySP sp(AxQueryInterface<IAAFTypeDef,
                                   IAAFTypeDefFixedArray>(axTypeDef));
        
        this->process(spPropVal, sp);

    }
    
    else
    {
        
        std::wcout << axTypeDef.GetName() << "\n";
        throw std::invalid_argument("Invalid AUID ");

        
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
    
    //IAAFTypeDefVariableArraySP spVariableArray;
    if (isClassType<IAAFTypeDefVariableArray>(axActualTypeDef))
    {
        
        IAAFTypeDefVariableArraySP sp(AxQueryInterface<IAAFTypeDef,
                                      IAAFTypeDefVariableArray>(axActualTypeDef));
        
        this->process(actualPropertyValueSP,sp);
        
    }
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefIntSP& spTypeDef)
{
    _obj = this->GetInteger(spPropVal,spTypeDef);
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefRenameSP& spTypeDef)
{
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefEnumSP& spTypeDef)
{
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefExtEnumSP& spTypeDef)
{
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefFixedArraySP& spTypeDef)
{
    
    AxTypeDefFixedArray axTDFA(spTypeDef);
    
    
    aafUInt32 size = axTDFA.GetCount();
    
    std::wcout << size << "\n";

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
            d[name] = DateToString(date);
        }
        else if (axDef.GetAUID() == kAAFTypeID_TimeStruct)
        {
            _aafTimeStruct_t time = GetTime( axValue);
            
            d[name] = TimeToString(time);
            
        }
        
        else if (axDef.GetAUID() == kAAFTypeID_TimeStamp)
        {
            _aafTimeStamp_t timeStamp = GetTimeStamp(axValue);
            d[name] = TimeStampToString( timeStamp );
        }
        
        else
        {
            
            PyGetValue valueGetter;
            
            valueGetter.processAny(spValue, spMemTypeDef);
            
            d[name] = valueGetter.getObject();
            //throw std::invalid_argument("Invalid AUID ");
        }
        
        
        //std::wcout << axTDR.GetName() << " " << name << " " <<axDef.GetName() << "\n";
        
    }
    _obj = d;
    
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefSetSP& spTypeDef)
{
    AxTypeDefSet axDefSet(spTypeDef);
    
    
    
    _obj = boost::python::object(axDefSet.GetElements(spPropVal));
    
    
    //boost::python::list elements;
    //AxPropertyValueIter axIter(axDefSet.GetElements(spPropVal));
    
    /*
    bool notAtEnd =true;
    while (notAtEnd)
    {
        IAAFSmartPointer2<IAAFPropertyValue> nextValue;
    
    
        notAtEnd = axIter.NextOne(nextValue);
        if (notAtEnd)
        {
            
            IAAFPropertyValueSP spValue = nextValue;
            AxPropertyValue axValue(spValue);
            
            AxTypeDef axValueTypeDef(axValue.GetType());
            
            if (isClassType<IAAFTypeDefStrongObjRef>(axValueTypeDef))
            {
                IAAFTypeDefStrongObjRefSP sp(AxQueryInterface<IAAFTypeDef,
                                              IAAFTypeDefStrongObjRef>(axValueTypeDef));
                AxTypeDefStrongObjRef axDefRef(sp);
                
                
                
                IAAFObjectSP spObj = axDefRef.GetObject<IAAFObject>(spValue);
                elements.append(spObj);
          
                //std::wcout << axValueTypeDef.GetName() << "\n";
            }
            
            
        }
    }
    
    _obj = elements;
     */
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefStreamSP& spTypeDef)
{
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefStringSP& spTypeDef)
{
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefStrongObjRefSP& spTypeDef)
{
    
    AxTypeDefStrongObjRef axDefRef(spTypeDef);
    
    IAAFObjectSP spObj = axDefRef.GetObject<IAAFObject>(spPropVal);
    _obj = boost::python::object(spObj);
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefWeakObjRefSP& spTypeDef)
{
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefObjectRefSP& spTypeDef)
{
    
}

void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefOpaqueSP& spTypeDef)
{
    
}


void PyGetValue::process( IAAFPropertyValueSP& spPropVal, IAAFTypeDefVariableArraySP&  spTypeDef)
{
    
    AxTypeDefVariableArray axVarArray( spTypeDef );
    AxTypeDef axTypeDefOfArray( axVarArray.GetType() );
    IAAFTypeDefIntSP spTypeDefInt;
    
    if (isClassType<IAAFTypeDefInt>(axTypeDefOfArray))
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
