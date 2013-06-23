#ifndef __AxMetaDef_h__
#define __AxMetaDef_h__

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

#include "AxTypes.h"
#include "AxSmartPointer.h"
#include "AxBaseObj.h"

// Please refer to the UML, for an overview of the class inheritance
// graph implemented here.

class AxMetaDefinition : public AxBaseObj {

public:
	AxMetaDefinition( IAAFMetaDefinitionSP spIaafMetaDefinition );
	virtual ~AxMetaDefinition();

	aafUID_t GetAUID();
        AxString GetName();
	AxString GetDescription();

private:
	AxMetaDefinition();
	AxMetaDefinition( const AxMetaDefinition& );
	AxMetaDefinition& operator=( const AxMetaDefinition& );
		
	IAAFMetaDefinitionSP _spIaafMetaDefinition;
};


//=---------------------------------------------------------------------=

class AxClassDef : public AxMetaDefinition {
public:
	AxClassDef( IAAFClassDefSP spIaafClassDef );
	~AxClassDef();

	// vanilla wrapper
	IUnknownSP CreateInstance( const IID& iid );

	// Type safe wrapper.  First calls vanilla wrapper to get an IUnknown given
	// iid, then casts that to Type using iid.
	template< class Type >
	void CreateInstance( const IID& iid, IAAFSmartPointer<Type>& sp )
	{
		AxQueryInterface( CreateInstance( iid ), sp, iid );
	}

	template< class Type >
	IAAFSmartPointer<Type> CreateInstance( const IID& iid )
	{
		IAAFSmartPointer<Type> sp;
		AxQueryInterface( CreateInstance( iid ), sp, iid );
	}


	IAAFClassDefSP GetParent();
	aafBoolean_t IsConcrete();

	IEnumAAFPropertyDefsSP GetPropertyDefs();
	IAAFPropertyDefSP LookupPropertyDef( const aafUID_t& propertyId );

	operator IAAFClassDefSP ()
	{ return _spIaafClassDef; }

private:
	IAAFClassDefSP _spIaafClassDef;
};


//=---------------------------------------------------------------------=

class AxPropertyDef : public AxMetaDefinition {
public:
	AxPropertyDef( IAAFPropertyDefSP spIaafPropertyDef );
	~AxPropertyDef();

	aafBoolean_t GetIsOptional();
	aafBoolean_t GetIsUniqueIdentifier();
	IAAFTypeDefSP GetTypeDef();
	inline operator IAAFPropertyDefSP()
	{
		return _spIaafPropertyDef;
	}

private:
	IAAFPropertyDefSP _spIaafPropertyDef;
};

//=---------------------------------------------------------------------=


class AxTypeDef : public AxMetaDefinition {

public:
	AxTypeDef( IAAFTypeDefSP spIaafTypeDef );
	virtual ~AxTypeDef();

	virtual eAAFTypeCategory_t GetTypeCategory();

	IAAFTypeDefSP GetTypeDefSP();

	operator IAAFTypeDefSP ()
	{ return _spIaafTypeDef; }

private:
	AxTypeDef();
	AxTypeDef( const AxTypeDef& );
	AxTypeDef& operator=( const AxTypeDef& );
		
	IAAFTypeDefSP _spIaafTypeDef;
};

//=---------------------------------------------------------------------=

class AxTypeDefIndirect : public AxTypeDef {
public:
	AxTypeDefIndirect( IAAFTypeDefIndirectSP spIaafTypeDefIndirect );
	virtual ~AxTypeDefIndirect();

	IAAFTypeDefSP GetActualType( IAAFPropertyValueSP& );
	IAAFPropertyValueSP GetActualValue( IAAFPropertyValueSP& );

private:
	AxTypeDefIndirect();
	AxTypeDefIndirect( const AxTypeDefIndirect& );
	AxTypeDefIndirect& operator=( const AxTypeDefIndirect& );
		
	IAAFTypeDefIndirectSP _spIaafTypeDefIndirect;
};

//=---------------------------------------------------------------------=

class AxTypeDefOpaque : public AxTypeDefIndirect {
public:
	AxTypeDefOpaque( IAAFTypeDefOpaqueSP spIaafTypeDefOpaque  );
	virtual ~AxTypeDefOpaque();

	aafUID_t GetActualTypeID( IAAFPropertyValueSP& );

	aafUInt32 GetHandleBufLen( IAAFPropertyValueSP& );

private:
	AxTypeDefOpaque();
	AxTypeDefOpaque( const AxTypeDefOpaque & );
	AxTypeDefOpaque& operator=( const AxTypeDefOpaque & );
		
	IAAFTypeDefOpaqueSP _spIaafTypeDefOpaque ;
};

//=---------------------------------------------------------------------=


class AxTypeDefRename : public AxTypeDef {
public:
	AxTypeDefRename( IAAFTypeDefRenameSP spIaafTypeDefRename );
	virtual ~AxTypeDefRename();

	void Initialize( const aafUID_t&, IAAFTypeDefSP, const AxString& );

	IAAFTypeDefSP GetBaseType();
	IAAFPropertyValueSP GetBaseValue( IAAFPropertyValueSP& );

	operator IAAFTypeDefRenameSP ()
	{ return _spIaafTypeDefRename; }

private:
	AxTypeDefRename();
	AxTypeDefRename( const AxTypeDefRename& );
	AxTypeDefRename& operator=( const AxTypeDefRename& );
		
	IAAFTypeDefRenameSP _spIaafTypeDefRename;
};


//=---------------------------------------------------------------------=


class AxTypeDefInt : public AxTypeDef {
public:
	AxTypeDefInt( IAAFTypeDefIntSP spIaafTypeDefInt );
	virtual ~AxTypeDefInt();

	aafUInt32 GetSize();
	aafBoolean_t IsSigned();

	void GetInteger( IAAFPropertyValueSP& spPropVal,
					 aafMemPtr_t pVal,
					 aafUInt32  valSize );

	template <typename IntType>
	IntType GetInteger( IAAFPropertyValueSP& spPropVal )
	{
		IntType val;
		GetInteger( spPropVal, &val, sizeof( IntType ) );
		return val;
	}

	template <typename IntType>
	void GetInteger( IAAFPropertyValueSP& spPropVal, IntType* pVal )
	{
		GetInteger( spPropVal, reinterpret_cast<aafMemPtr_t>(pVal), sizeof( IntType ) );
	}

	IAAFPropertyValueSP CreateValue(aafMemPtr_t pVal, aafUInt32  valSize);

private:

	AxTypeDefInt();
	AxTypeDefInt( const AxTypeDefInt& );
	AxTypeDefInt& operator=( const AxTypeDefInt& );
		
	IAAFTypeDefIntSP _spIaafTypeDefInt;
};

//=---------------------------------------------------------------------=

class AxTypeDefFixedArray : public AxTypeDef {
public:
	AxTypeDefFixedArray( IAAFTypeDefFixedArraySP spIaafTypeDefFixedArray );
	virtual ~AxTypeDefFixedArray();

	IAAFTypeDefSP GetType();

	aafUInt32 GetCount();

	IEnumAAFPropertyValuesSP GetElements( IAAFPropertyValueSP& );

	IAAFPropertyValueSP GetElementValue( IAAFPropertyValueSP& spFixedArrayPropVal, aafUInt32 index );

private:
	AxTypeDefFixedArray();
	AxTypeDefFixedArray( const AxTypeDefFixedArray& );
	AxTypeDefFixedArray& operator=( const AxTypeDefFixedArray& );

	IAAFTypeDefFixedArraySP _spIaafTypeDefFixedArray;
};

//=---------------------------------------------------------------------=

class AxTypeDefRecord : public AxTypeDef {
public:
	AxTypeDefRecord( IAAFTypeDefRecordSP spIaafTypeDefRecord );
	virtual ~AxTypeDefRecord();

	aafUInt32 GetCount();

	IAAFTypeDefSP GetMemberType( aafUInt32 index );

	AxString GetMemberName( aafUInt32 index );

	IAAFPropertyValueSP GetValue( IAAFPropertyValueSP& spRecordPropVal, aafUInt32 index );

private:
	AxTypeDefRecord();
	AxTypeDefRecord( const AxTypeDefRecord& );
	AxTypeDefRecord& operator=( const AxTypeDefRecord& );
		
	IAAFTypeDefRecordSP _spIaafTypeDefRecord;
};

//=---------------------------------------------------------------------=

class AxTypeDefStream : public AxTypeDef {
public:
	AxTypeDefStream( IAAFTypeDefStreamSP spIaafTypeDefStream );
	virtual ~AxTypeDefStream();

	aafInt64 GetSize( IAAFPropertyValueSP& );

private:
	AxTypeDefStream();
	AxTypeDefStream( const AxTypeDefStream& );
	AxTypeDefStream& operator=( const AxTypeDefStream& );
		
	IAAFTypeDefStreamSP _spIaafTypeDefStream;
};

//=---------------------------------------------------------------------=

class AxTypeDefString : public AxTypeDef {
public:
	AxTypeDefString( IAAFTypeDefStringSP spIaafTypeDefString );
	virtual ~AxTypeDefString();

	AxString GetElements( IAAFPropertyValueSP& );

private:
	AxTypeDefString();
	AxTypeDefString( const AxTypeDefString& );
	AxTypeDefString& operator=( const AxTypeDefString& );
		
	IAAFTypeDefStringSP _spIaafTypeDefString;
};

//=---------------------------------------------------------------------=

class AxTypeDefCharacter : public AxTypeDef {
public:
	AxTypeDefCharacter( IAAFTypeDefCharacterSP spIaafTypeDefCharacter );
	virtual ~AxTypeDefCharacter();
    
	//AxString GetElements( IAAFPropertyValueSP& );
    
private:
	AxTypeDefCharacter();
	AxTypeDefCharacter( const AxTypeDefCharacter& );
	AxTypeDefCharacter& operator=( const AxTypeDefCharacter& );
    
	IAAFTypeDefCharacterSP _spIaafTypeDefCharacter;
};

//=---------------------------------------------------------------------=

class AxTypeDefSet : public AxTypeDef {
public:
	AxTypeDefSet( IAAFTypeDefSetSP spIaafTypeDefSet );
	virtual ~AxTypeDefSet();

	IAAFTypeDefSP GetElementType();
	
	// GetType() is not part of the IAAFTypeDef interface but
	// matches the IAAFTypeDef{Fixed,Variable}Array interface.
	// This makes it possible to use the GetType call in
	// templated code.
	IAAFTypeDefSP GetType();

	IEnumAAFPropertyValuesSP GetElements( IAAFPropertyValueSP& );

private:
	AxTypeDefSet();
	AxTypeDefSet( const AxTypeDefSet& );
	AxTypeDefSet& operator=( const AxTypeDefSet& );
		
	IAAFTypeDefSetSP _spIaafTypeDefSet;
};

//=---------------------------------------------------------------------=

class AxTypeDefObjRef : public AxTypeDef {
public:
	AxTypeDefObjRef( IAAFTypeDefObjectRefSP spIaafTypeDefObjRef );
	virtual ~AxTypeDefObjRef();

	IUnknownSP GetObject( IAAFPropertyValueSP& spPropVal,
			      const IID& iid );

	template <class Type>
	IAAFSmartPointer<Type> GetObject(IAAFPropertyValueSP& spPropVal )
        {
	  IUnknownSP sp = GetObject( spPropVal, IID_IUnknown );
	  return AxQueryInterface<IUnknown,Type>( sp );
        }

	IAAFClassDefSP GetObjectType();

private:
	AxTypeDefObjRef();
	AxTypeDefObjRef( const AxTypeDefObjRef& );
	AxTypeDefObjRef& operator=( const AxTypeDefObjRef& );

	IAAFTypeDefObjectRefSP _spIaafTypeDefObjRef;
};

//=---------------------------------------------------------------------=

class AxTypeDefWeakObjRef : public AxTypeDefObjRef {

public:
	AxTypeDefWeakObjRef( IAAFTypeDefWeakObjRefSP spIaafTypeDefWeakObjRef );
	virtual ~AxTypeDefWeakObjRef();

private:
	AxTypeDefWeakObjRef();
	AxTypeDefWeakObjRef( const AxTypeDefWeakObjRef& );
	AxTypeDefWeakObjRef& operator=( const AxTypeDefWeakObjRef& );
		
	IAAFTypeDefWeakObjRefSP _spIaafTypeDefWeakObjRef;
};

//=---------------------------------------------------------------------=

class AxTypeDefStrongObjRef : public AxTypeDefObjRef {

public:
	AxTypeDefStrongObjRef( IAAFTypeDefStrongObjRefSP spIaafTypeDefStrongObjRef );
	virtual ~AxTypeDefStrongObjRef();

private:
	AxTypeDefStrongObjRef();
	AxTypeDefStrongObjRef( const AxTypeDefStrongObjRef& );
	AxTypeDefStrongObjRef& operator=( const AxTypeDefStrongObjRef& );
		
	IAAFTypeDefStrongObjRefSP _spIaafTypeDefStrongObjRef;
};

//=---------------------------------------------------------------------=

class AxTypeDefVariableArrayEx : public AxTypeDef {
public:
	AxTypeDefVariableArrayEx( IAAFTypeDefVariableArrayExSP spIaafTypeDefVariableArrayEx );
	virtual ~AxTypeDefVariableArrayEx();

private:
	AxTypeDefVariableArrayEx();
	AxTypeDefVariableArrayEx( const AxTypeDefVariableArrayEx& );
	AxTypeDefVariableArrayEx& operator=( const AxTypeDefVariableArrayEx& );
		
	IAAFTypeDefVariableArrayExSP _spIaafTypeDefVariableArrayEx;
};

//=---------------------------------------------------------------------=

class AxTypeDefVariableArray : public AxTypeDefVariableArrayEx {
public:
	AxTypeDefVariableArray( IAAFTypeDefVariableArraySP spIaafTypeDefVariableArray );
	virtual ~AxTypeDefVariableArray();

	IAAFTypeDefSP GetType();

	aafUInt32 GetCount( IAAFPropertyValueSP& spPropVal );

	IEnumAAFPropertyValuesSP GetElements( IAAFPropertyValueSP& spPropVal );

private:
	AxTypeDefVariableArray();
	AxTypeDefVariableArray( const AxTypeDefVariableArray& );
	AxTypeDefVariableArray& operator=( const AxTypeDefVariableArray& );

	IAAFTypeDefVariableArraySP _spIaafTypeDefVariableArray;
};


//=---------------------------------------------------------------------=

class AxTypeDefEnum : public AxTypeDef {
public:
	AxTypeDefEnum( IAAFTypeDefEnumSP spIaafTypeDefEnum );
	virtual ~AxTypeDefEnum();

	IAAFTypeDefSP GetElementType();

	aafUInt32 CountElements();
	AxString GetElementName( aafUInt32 index );
	aafInt64 GetElementValue( aafUInt32 index );


	AxString GetNameFromValue( IAAFPropertyValueSP &spPropVal );

	aafInt64 GetIntegerValue( IAAFPropertyValueSP &spPropVal );

private:
	AxTypeDefEnum();
	AxTypeDefEnum( const AxTypeDefEnum& );
	AxTypeDefEnum& operator=( const AxTypeDefEnum& );

	IAAFTypeDefEnumSP _spIaafTypeDefEnum;
};

//=---------------------------------------------------------------------=

class AxTypeDefExtEnum : public AxTypeDef {
public:
	AxTypeDefExtEnum( IAAFTypeDefExtEnumSP spIaafTypeDefExtEnum );
	virtual ~AxTypeDefExtEnum();

	aafUInt32 CountElements();
	AxString GetElementName( aafUInt32 index );
	aafUID_t GetElementValue( aafUInt32 index );

	AxString GetNameFromValue( IAAFPropertyValueSP spVal );

private:
	AxTypeDefExtEnum();
	AxTypeDefExtEnum( const AxTypeDefExtEnum& );
	AxTypeDefExtEnum& operator=( const AxTypeDefExtEnum& );
		
	IAAFTypeDefExtEnumSP _spIaafTypeDefExtEnum;
};

#endif
