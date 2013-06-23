//=---------------------------------------------------------------------=
//
// $Id$ $Name$
//
// The contents of this file are subject to the AAF SDK Public Source
// License Agreement Version 2.0 (the "License"); You may not use this
// file except in compliance with the License.  The License is available
// in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
// Advanced Media Workflow Association, Inc., or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.  Refer to Section 3.3 of the License for proper use
// of this Exhibit.
//
// WARNING:  Please contact the Advanced Media Workflow Association,
// Inc., for more information about any additional licenses to
// intellectual property covering the AAF Standard that may be required
// to create and distribute AAF compliant products.
// (http://www.amwa.tv/policies).
//
// Copyright Notices:
// The Original Code of this file is Copyright 1998-2009, licensor of the
// Advanced Media Workflow Association.  All rights reserved.
//
//=---------------------------------------------------------------------=

#include "AxMetaDef.h"

#include "AxUtil.h"

#include <sstream>

AxMetaDefinition::AxMetaDefinition( IAAFMetaDefinitionSP spIaafMetaDefinition )
:	AxBaseObj( AxQueryInterface<IAAFMetaDefinition,IUnknown>(spIaafMetaDefinition) ),
	_spIaafMetaDefinition( spIaafMetaDefinition )
{}

AxMetaDefinition::~AxMetaDefinition()
{}


aafUID_t AxMetaDefinition::GetAUID()
{
	aafUID_t auid;

	CHECK_HRESULT( _spIaafMetaDefinition->GetAUID( &auid ) );

	return auid;
}

AxString AxMetaDefinition::GetName()
{
  return AxNameToString( _spIaafMetaDefinition );
}


AxString AxMetaDefinition::GetDescription()
{
  return AxDescriptionToString( _spIaafMetaDefinition );
}


//=---------------------------------------------------------------------=

AxClassDef::AxClassDef( IAAFClassDefSP spIaafClassDef )
:	AxMetaDefinition( AxQueryInterface<IAAFClassDef,IAAFMetaDefinition>(spIaafClassDef) ),
	_spIaafClassDef( spIaafClassDef )
{}

AxClassDef::~AxClassDef()
{}

IUnknownSP AxClassDef::CreateInstance( const IID& auid )
{
	IUnknownSP spIUnknown;

	CHECK_HRESULT( _spIaafClassDef->CreateInstance( auid, &spIUnknown ) );

	return spIUnknown;
}


IAAFClassDefSP AxClassDef::GetParent()
{
	IAAFClassDefSP spClassDef;

	CHECK_HRESULT( _spIaafClassDef->GetParent( &spClassDef ) );

	return spClassDef;
}

aafBoolean_t AxClassDef::IsConcrete()
{
	aafBoolean_t isConcrete;

	CHECK_HRESULT( _spIaafClassDef->IsConcrete( &isConcrete ) );

	return isConcrete;
}

IEnumAAFPropertyDefsSP AxClassDef::GetPropertyDefs()
{
	IEnumAAFPropertyDefsSP spIEnumAAFPropertyDefs;

	CHECK_HRESULT( _spIaafClassDef->GetPropertyDefs( &spIEnumAAFPropertyDefs ) );

	return spIEnumAAFPropertyDefs;
}

IAAFPropertyDefSP AxClassDef::LookupPropertyDef( aafUID_constref  propertyId )
{
	IAAFPropertyDefSP spIaafPropertyDef;

	CHECK_HRESULT( _spIaafClassDef->LookupPropertyDef( propertyId, &spIaafPropertyDef ) );

	return spIaafPropertyDef;
}

//=---------------------------------------------------------------------=

AxPropertyDef::AxPropertyDef( IAAFPropertyDefSP spIaafPropertyDef )
:	AxMetaDefinition( AxQueryInterface<IAAFPropertyDef,IAAFMetaDefinition>(spIaafPropertyDef) ),
	_spIaafPropertyDef( spIaafPropertyDef )
{}

AxPropertyDef::~AxPropertyDef()
{}

aafBoolean_t AxPropertyDef::GetIsOptional()
{
	aafBoolean_t isOptional;

	CHECK_HRESULT( _spIaafPropertyDef->GetIsOptional( &isOptional ) );

	return isOptional;
}

aafBoolean_t AxPropertyDef::GetIsUniqueIdentifier()
{
	aafBoolean_t isUniqueIdentifier;

	CHECK_HRESULT( _spIaafPropertyDef->GetIsUniqueIdentifier( &isUniqueIdentifier ) );

	return isUniqueIdentifier;
}

IAAFTypeDefSP AxPropertyDef::GetTypeDef()
{
	IAAFTypeDefSP spTypeDef;

	CHECK_HRESULT( _spIaafPropertyDef->GetTypeDef( &spTypeDef ) );

	return spTypeDef;
}


//=---------------------------------------------------------------------=

AxTypeDef::AxTypeDef( IAAFTypeDefSP spIaafTypeDef )
:	AxMetaDefinition( AxQueryInterface<IAAFTypeDef,IAAFMetaDefinition>(spIaafTypeDef) ),
	_spIaafTypeDef( spIaafTypeDef )
{}

AxTypeDef::~AxTypeDef()
{}

eAAFTypeCategory_t AxTypeDef::GetTypeCategory()
{
	eAAFTypeCategory_t typeCategory;

	CHECK_HRESULT( _spIaafTypeDef->GetTypeCategory (&typeCategory) );

	return typeCategory;
}

IAAFTypeDefSP AxTypeDef::GetTypeDefSP()
{
	return _spIaafTypeDef;
}
	
//=---------------------------------------------------------------------=

AxTypeDefIndirect::AxTypeDefIndirect( IAAFTypeDefIndirectSP spIaafTypeDefIndirect )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefIndirect, IAAFTypeDef>(spIaafTypeDefIndirect) ),
	_spIaafTypeDefIndirect( spIaafTypeDefIndirect )
{}

AxTypeDefIndirect::~AxTypeDefIndirect()
{}

IAAFTypeDefSP AxTypeDefIndirect::GetActualType( IAAFPropertyValueSP& spPropVal )
{
	IAAFTypeDefSP spTypeDef;

	CHECK_HRESULT( _spIaafTypeDefIndirect->GetActualType( spPropVal, &spTypeDef ) );

	return spTypeDef;
}

IAAFPropertyValueSP AxTypeDefIndirect::GetActualValue( IAAFPropertyValueSP& spPropVal )
{
	IAAFPropertyValueSP spActualPropVal;

	CHECK_HRESULT( _spIaafTypeDefIndirect->GetActualValue( spPropVal, &spActualPropVal ) );

	return spActualPropVal;
}

//=---------------------------------------------------------------------=


AxTypeDefOpaque::AxTypeDefOpaque( IAAFTypeDefOpaqueSP spIaafTypeDefOpaque  )
:	AxTypeDefIndirect( AxQueryInterface<IAAFTypeDefOpaque, IAAFTypeDefIndirect>(spIaafTypeDefOpaque) ),
	_spIaafTypeDefOpaque ( spIaafTypeDefOpaque  )
{}

AxTypeDefOpaque::~AxTypeDefOpaque ()
{}

aafUID_t AxTypeDefOpaque::GetActualTypeID( IAAFPropertyValueSP& spPropVal )
{
	aafUID_t uid;

	CHECK_HRESULT( _spIaafTypeDefOpaque->GetActualTypeID( spPropVal, &uid ) );

	return uid;
}

aafUInt32 AxTypeDefOpaque::GetHandleBufLen( IAAFPropertyValueSP& spPropVal )
{
	aafUInt32 len;

	CHECK_HRESULT( _spIaafTypeDefOpaque->GetHandleBufLen( spPropVal, &len ) );

	return len;
}

//=---------------------------------------------------------------------=

AxTypeDefRename::AxTypeDefRename( IAAFTypeDefRenameSP spIaafTypeDefRename )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefRename, IAAFTypeDef>(spIaafTypeDefRename) ),
	_spIaafTypeDefRename( spIaafTypeDefRename )
{}

AxTypeDefRename::~AxTypeDefRename()
{}

void AxTypeDefRename::Initialize( const aafUID_t& typeUID,
								IAAFTypeDefSP spBaseTypeDef,
								const AxString&  typeName )
{
	CHECK_HRESULT( _spIaafTypeDefRename->Initialize(
					typeUID, spBaseTypeDef, typeName.c_str() ) );
}


IAAFTypeDefSP AxTypeDefRename::GetBaseType()
{
	IAAFTypeDefSP spTypeDef;

	CHECK_HRESULT( _spIaafTypeDefRename->GetBaseType( &spTypeDef ) );

	return spTypeDef;
}

IAAFPropertyValueSP AxTypeDefRename::GetBaseValue( IAAFPropertyValueSP& spPropVal )
{
	IAAFPropertyValueSP spBasePropVal;

	CHECK_HRESULT( _spIaafTypeDefRename->GetBaseValue( spPropVal, &spBasePropVal ) );

	return spBasePropVal;
}

//=---------------------------------------------------------------------=

AxTypeDefInt::AxTypeDefInt( IAAFTypeDefIntSP spIaafTypeDefInt )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefInt, IAAFTypeDef>(spIaafTypeDefInt) ),
	_spIaafTypeDefInt( spIaafTypeDefInt )
{}

AxTypeDefInt::~AxTypeDefInt()
{}

aafUInt32 AxTypeDefInt::GetSize()
{
	aafUInt32 size;

	CHECK_HRESULT( _spIaafTypeDefInt->GetSize( &size ) );

	return size;
}

aafBoolean_t AxTypeDefInt::IsSigned()
{
	aafBoolean_t sign;

	CHECK_HRESULT( _spIaafTypeDefInt->IsSigned( &sign ) );

	return sign;
}

void AxTypeDefInt::GetInteger( IAAFPropertyValueSP& spPropVal,
			       aafMemPtr_t pVal,
			       aafUInt32  valSize )
{
	CHECK_HRESULT( _spIaafTypeDefInt->GetInteger( spPropVal, pVal, valSize ) );
}

IAAFPropertyValueSP AxTypeDefInt::CreateValue(aafMemPtr_t pVal, aafUInt32  valSize)
{
	IAAFPropertyValueSP propval;

	CHECK_HRESULT( _spIaafTypeDefInt->CreateValue(pVal, valSize, &propval));

	return propval;
}

//=---------------------------------------------------------------------=

AxTypeDefFixedArray::AxTypeDefFixedArray( IAAFTypeDefFixedArraySP spIaafTypeDefFixedArray )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefFixedArray,IAAFTypeDef>(spIaafTypeDefFixedArray) ),
	_spIaafTypeDefFixedArray( spIaafTypeDefFixedArray )
{}

AxTypeDefFixedArray::~AxTypeDefFixedArray()
{}

IAAFTypeDefSP AxTypeDefFixedArray::GetType()
{
	IAAFTypeDefSP spIaafTypeDef;

	CHECK_HRESULT( _spIaafTypeDefFixedArray->GetType( &spIaafTypeDef ) );

	return spIaafTypeDef;
}

aafUInt32 AxTypeDefFixedArray::GetCount()
{
	aafUInt32 count;

	CHECK_HRESULT( _spIaafTypeDefFixedArray->GetCount( &count ) );

	return count;
}

IEnumAAFPropertyValuesSP AxTypeDefFixedArray::GetElements( IAAFPropertyValueSP& spPropVal )
{
	IEnumAAFPropertyValuesSP spEnum;

	CHECK_HRESULT( _spIaafTypeDefFixedArray->GetElements( spPropVal, &spEnum ) );

	return spEnum;
}


IAAFPropertyValueSP AxTypeDefFixedArray::GetElementValue( IAAFPropertyValueSP& spFixedArrayPropVal, aafUInt32 index )
{
	IAAFPropertyValueSP spElementPropVal;

	CHECK_HRESULT( _spIaafTypeDefFixedArray->GetElementValue( spFixedArrayPropVal, index, &spElementPropVal ) );

	return spElementPropVal;
}



//=---------------------------------------------------------------------=

AxTypeDefRecord::AxTypeDefRecord( IAAFTypeDefRecordSP spIaafTypeDefRecord )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefRecord, IAAFTypeDef>(spIaafTypeDefRecord) ),
	_spIaafTypeDefRecord( spIaafTypeDefRecord )
{}

AxTypeDefRecord::~AxTypeDefRecord()
{}

aafUInt32 AxTypeDefRecord::GetCount()
{
	aafUInt32 count;

	CHECK_HRESULT( _spIaafTypeDefRecord->GetCount( &count ) );

	return count;
}

IAAFTypeDefSP AxTypeDefRecord::GetMemberType( aafUInt32 index )
{
	IAAFTypeDefSP spIaafTypeDef;

	CHECK_HRESULT( _spIaafTypeDefRecord->GetMemberType( index, &spIaafTypeDef ) );

	return spIaafTypeDef;
}

AxString AxTypeDefRecord::GetMemberName( aafUInt32 index )
{
	using namespace std;
	
	aafUInt32 sizeInChars;
	aafUInt32 sizeInBytes;

	CHECK_HRESULT( _spIaafTypeDefRecord->GetMemberNameBufLen( index, &sizeInBytes ) );

	sizeInChars = sizeInBytes / sizeof(aafCharacter) + 1;

	std::vector< aafCharacter > buf( sizeInChars );
	
	CHECK_HRESULT( _spIaafTypeDefRecord->GetMemberName( index,
							    &buf[0],
							    sizeInBytes ) );
													  
	return AxString( &buf[0] );
}

IAAFPropertyValueSP AxTypeDefRecord::GetValue( IAAFPropertyValueSP& spRecordPropVal,
					       aafUInt32 index )
{
	IAAFPropertyValueSP spMemberPropVal;

	CHECK_HRESULT( _spIaafTypeDefRecord->GetValue( spRecordPropVal, index, &spMemberPropVal ) );

	return spMemberPropVal;
}

//=---------------------------------------------------------------------=

AxTypeDefStream::AxTypeDefStream( IAAFTypeDefStreamSP spIaafTypeDefStream )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefStream, IAAFTypeDef>(spIaafTypeDefStream) ),
	_spIaafTypeDefStream( spIaafTypeDefStream )
{}

AxTypeDefStream::~AxTypeDefStream()
{}

aafInt64 AxTypeDefStream::GetSize( IAAFPropertyValueSP& spPropVal )
{
	aafInt64 size;

	CHECK_HRESULT( _spIaafTypeDefStream->GetSize( spPropVal, &size ) );

	return size;
}

//=---------------------------------------------------------------------=

AxTypeDefString::AxTypeDefString( IAAFTypeDefStringSP spIaafTypeDefString )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefString, IAAFTypeDef>(spIaafTypeDefString) ),
	_spIaafTypeDefString( spIaafTypeDefString )
{}

AxTypeDefString::~AxTypeDefString()
{}

AxString AxTypeDefString::GetElements( IAAFPropertyValueSP& propVal )
{
	// FIXME - String can be composed of characters other than aafCharacter.
	//	could also be of type int.
	
	using namespace std;

	aafUInt32 sizeInChars;
	int sizeInBytes;
	
	CHECK_HRESULT( _spIaafTypeDefString->GetCount( propVal, &sizeInChars ) );

	sizeInBytes = sizeof(aafCharacter)*sizeInChars;

	std::vector< aafCharacter > buf( sizeInChars );
	
	CHECK_HRESULT( _spIaafTypeDefString->GetElements( propVal,
							  reinterpret_cast<aafMemPtr_t>(&buf[0]),
							  sizeInBytes ) );
	
	return AxString( &buf[0] );
}

//=---------------------------------------------------------------------=

AxTypeDefCharacter::AxTypeDefCharacter( IAAFTypeDefCharacterSP spIaafTypeDefCharacter )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefCharacter, IAAFTypeDef>(spIaafTypeDefCharacter) ),
_spIaafTypeDefCharacter( spIaafTypeDefCharacter )
{}

AxTypeDefCharacter::~AxTypeDefCharacter()
{}

aafCharacter AxTypeDefCharacter::GetCharacter( IAAFPropertyValueSP& propVal )
{

    aafCharacter *c;
    CHECK_HRESULT( _spIaafTypeDefCharacter->GetCharacter( propVal, c) );
    return *c;
    
}

//=---------------------------------------------------------------------=

AxTypeDefSet::AxTypeDefSet( IAAFTypeDefSetSP spIaafTypeDefSet )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefSet, IAAFTypeDef>(spIaafTypeDefSet) ),
	_spIaafTypeDefSet( spIaafTypeDefSet )
{}

AxTypeDefSet::~AxTypeDefSet()
{}

IEnumAAFPropertyValuesSP AxTypeDefSet::GetElements( IAAFPropertyValueSP& spPropVal )
{
	IEnumAAFPropertyValuesSP spEnum;

	CHECK_HRESULT( _spIaafTypeDefSet->GetElements( spPropVal, &spEnum ) );

	return spEnum;
}

IAAFTypeDefSP AxTypeDefSet::GetElementType()
{
	IAAFTypeDefSP spIaafTypeDef;

	CHECK_HRESULT( _spIaafTypeDefSet->GetElementType( &spIaafTypeDef ) );

	return spIaafTypeDef;
}

IAAFTypeDefSP AxTypeDefSet::GetType()
{
	return GetElementType();
}

//=---------------------------------------------------------------------=

AxTypeDefObjRef::AxTypeDefObjRef( IAAFTypeDefObjectRefSP spIaafTypeDefObjRef )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefObjectRef,IAAFTypeDef>(spIaafTypeDefObjRef) ),
	_spIaafTypeDefObjRef( spIaafTypeDefObjRef )
{}

AxTypeDefObjRef::~AxTypeDefObjRef()
{}

IUnknownSP AxTypeDefObjRef::GetObject( IAAFPropertyValueSP& spPropVal,
									   const IID& iid )
{
	IUnknownSP spIUnknown;

	CHECK_HRESULT( _spIaafTypeDefObjRef->GetObject( spPropVal,
							iid,
							&spIUnknown ) );

	return spIUnknown;
}

IAAFClassDefSP AxTypeDefObjRef::GetObjectType()
{
	IAAFClassDefSP spRefClassDef;

	CHECK_HRESULT( _spIaafTypeDefObjRef->GetObjectType( &spRefClassDef ) );

	return spRefClassDef;

}

//=---------------------------------------------------------------------=

AxTypeDefWeakObjRef::AxTypeDefWeakObjRef( IAAFTypeDefWeakObjRefSP sp )
:	AxTypeDefObjRef( AxQueryInterface<IAAFTypeDefWeakObjRef,IAAFTypeDefObjectRef>(sp) ),
	_spIaafTypeDefWeakObjRef( sp )
{}

AxTypeDefWeakObjRef::~AxTypeDefWeakObjRef()
{}

//=---------------------------------------------------------------------=

AxTypeDefStrongObjRef::AxTypeDefStrongObjRef( IAAFTypeDefStrongObjRefSP sp )
:	AxTypeDefObjRef( AxQueryInterface<IAAFTypeDefStrongObjRef,IAAFTypeDefObjectRef>(sp) ),
	_spIaafTypeDefStrongObjRef( sp )
{}

AxTypeDefStrongObjRef::~AxTypeDefStrongObjRef()
{}


//=---------------------------------------------------------------------=

AxTypeDefVariableArrayEx::AxTypeDefVariableArrayEx( IAAFTypeDefVariableArrayExSP sp)
:	AxTypeDef( AxQueryInterface<IAAFTypeDefVariableArrayEx,IAAFTypeDef>(sp) ),
	_spIaafTypeDefVariableArrayEx( sp )
{}

AxTypeDefVariableArrayEx::~AxTypeDefVariableArrayEx()
{}

//=---------------------------------------------------------------------=

AxTypeDefVariableArray::AxTypeDefVariableArray( IAAFTypeDefVariableArraySP sp )
:	AxTypeDefVariableArrayEx( AxQueryInterface<IAAFTypeDefVariableArray,IAAFTypeDefVariableArrayEx>(sp) ),
	_spIaafTypeDefVariableArray( sp )
{}

AxTypeDefVariableArray::~AxTypeDefVariableArray()
{}

IAAFTypeDefSP AxTypeDefVariableArray::GetType()
{
	IAAFTypeDefSP spIaafTypeDef;

	CHECK_HRESULT( _spIaafTypeDefVariableArray->GetType( &spIaafTypeDef ) );

	return spIaafTypeDef;
}

aafUInt32 AxTypeDefVariableArray::GetCount( IAAFPropertyValueSP& spPropVal )
{
	aafUInt32 count;

	CHECK_HRESULT( _spIaafTypeDefVariableArray->GetCount( spPropVal, &count ) );

	return count;
}

IEnumAAFPropertyValuesSP AxTypeDefVariableArray::GetElements( IAAFPropertyValueSP& spPropVal )
{
	IEnumAAFPropertyValuesSP spEnum;

	CHECK_HRESULT( _spIaafTypeDefVariableArray->GetElements( spPropVal, &spEnum ) );

	return spEnum;
}

//=---------------------------------------------------------------------=

AxTypeDefEnum::AxTypeDefEnum( IAAFTypeDefEnumSP spIaafTypeDefEnum )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefEnum, IAAFTypeDef>(spIaafTypeDefEnum) ),
	_spIaafTypeDefEnum( spIaafTypeDefEnum )
{}

AxTypeDefEnum::~AxTypeDefEnum()
{}

IAAFTypeDefSP AxTypeDefEnum::GetElementType()
{
	IAAFTypeDefSP spIaafTypeDef;

	CHECK_HRESULT( _spIaafTypeDefEnum->GetElementType( &spIaafTypeDef ) );

	return spIaafTypeDef;
}

aafUInt32 AxTypeDefEnum::CountElements()
{
	aafUInt32 count;

	CHECK_HRESULT( _spIaafTypeDefEnum->CountElements( &count ) );

	return count;
}

AxString AxTypeDefEnum::GetElementName( aafUInt32 index )
{
	aafUInt32 sizeInBytes = 0;
	CHECK_HRESULT( _spIaafTypeDefEnum->GetElementNameBufLen( index, &sizeInBytes ) );

	int sizeInChars = (int)( (double)sizeInBytes / sizeof(aafCharacter) + 0.5 );
	std::vector< aafCharacter > buf( sizeInChars );

	CHECK_HRESULT( _spIaafTypeDefEnum->GetElementName( index, &buf[0], 
		sizeInChars*sizeof(aafCharacter) ) );
	
	AxString name( &buf[0] );

	return name;
}

aafInt64 AxTypeDefEnum::GetElementValue( aafUInt32 index )
{
	aafInt64 value;

	CHECK_HRESULT( _spIaafTypeDefEnum->GetElementValue( index, &value ) );

	return value;
}

AxString AxTypeDefEnum::GetNameFromValue( IAAFPropertyValueSP &spPropVal )
{
	aafUInt32 sizeInBytes = 0;
	CHECK_HRESULT( _spIaafTypeDefEnum->GetNameBufLenFromValue( spPropVal, &sizeInBytes ) );

	int sizeInChars = (int)( (double)sizeInBytes / sizeof(aafCharacter) + 0.5 );
	std::vector< aafCharacter > buf( sizeInChars );

	CHECK_HRESULT( _spIaafTypeDefEnum->GetNameFromValue( spPropVal, &buf[0], 
		sizeInChars*sizeof(aafCharacter) ) );
	
	AxString name( &buf[0] );

	return name;

}


aafInt64 AxTypeDefEnum::GetIntegerValue( IAAFPropertyValueSP& spPropVal )
{
	aafInt64 value;

	CHECK_HRESULT( _spIaafTypeDefEnum->GetIntegerValue( spPropVal, &value ) );

	return value;
}


//=---------------------------------------------------------------------=

AxTypeDefExtEnum::AxTypeDefExtEnum( IAAFTypeDefExtEnumSP spIaafTypeDefExtEnum )
:	AxTypeDef( AxQueryInterface<IAAFTypeDefExtEnum, IAAFTypeDef>(spIaafTypeDefExtEnum) ),
	_spIaafTypeDefExtEnum( spIaafTypeDefExtEnum )
{}

AxTypeDefExtEnum::~AxTypeDefExtEnum()
{}

aafUInt32 AxTypeDefExtEnum::CountElements()
{
	aafUInt32 count;

	CHECK_HRESULT( _spIaafTypeDefExtEnum->CountElements( &count ) );

	return count;
}

AxString AxTypeDefExtEnum::GetElementName( aafUInt32 index )
{
	aafUInt32 sizeInBytes = 0;
	CHECK_HRESULT( _spIaafTypeDefExtEnum->GetElementNameBufLen( index, &sizeInBytes ) );

	int sizeInChars = (int)( (double)sizeInBytes / sizeof(aafCharacter) + 0.5 );
	std::vector< aafCharacter > buf( sizeInChars );

	CHECK_HRESULT( _spIaafTypeDefExtEnum->GetElementName( index, &buf[0], 
		sizeInChars*sizeof(aafCharacter) ) );
	
	AxString name( &buf[0] );

	return name;
}

aafUID_t AxTypeDefExtEnum::GetElementValue( aafUInt32 index )
{
	aafUID_t auid;

	CHECK_HRESULT( _spIaafTypeDefExtEnum->GetElementValue( index, &auid ) );

	return auid;
}

AxString AxTypeDefExtEnum::GetNameFromValue( IAAFPropertyValueSP spVal )
{
  AxString name;
  AX_ANY_TO_STRING_ONEARG( name, _spIaafTypeDefExtEnum, GetNameBufLenFromValue, GetNameFromValue, spVal )
  return name;
}
