#include <resolve_smartpointer.h>


boost::python::object resolve_object(IAAFObjectSP sp)
{
    
    AxObject ax(sp);
    
    std::string classname = AxStringToString(ax.GetClassName());
    
    
    if (classname == "DataDefinition")
    {
        IAAFDataDefSP spItem = AxQueryInterface<IAAFObject,IAAFDataDef>(sp);
        return boost::python::object(spItem);
    }
    
    else if (classname == "ContainerDefinition")
    {
        IAAFContainerDefSP spItem = AxQueryInterface<IAAFObject,IAAFContainerDef>(sp);
        return boost::python::object(spItem);
    }
    
    else if (classname == "EdgeCode")
    {
        IAAFEdgecodeSP spItem = AxQueryInterface<IAAFObject,IAAFEdgecode>(sp);
        return boost::python::object(spItem);
    }
    
    else if (classname == "OperationDefinition")
    {
        IAAFOperationDefSP spItem = AxQueryInterface<IAAFObject,IAAFOperationDef>(sp);
        return boost::python::object(spItem);
    }
    
    else if (classname == "ParameterDefinition")
    {
        IAAFParameterDefSP spItem = AxQueryInterface<IAAFObject,IAAFParameterDef>(sp);
        return boost::python::object(spItem);
    }
    
    else if (classname == "InterpolationDefinition")
    {
        IAAFInterpolationDefSP spItem = AxQueryInterface<IAAFObject,IAAFInterpolationDef>(sp);
        return boost::python::object(spItem);
    }
    
    #define CASE(T)	\
    else if (classname == #T){	\
    IAAF##T##SP spItem = AxQueryInterface<IAAFObject,IAAF##T>(sp);	\
    return boost::python::object(spItem);}
    
    CASE(ContentStorage)
    
    CASE( AIFCDescriptor )
//    CASE( ClassDef )
    CASE( CodecDef )
    CASE( CommentMarker )
    CASE( Component )
    CASE( CompositionMob )
    CASE( CompositionMob2 )
    CASE( ConstantValue )
    //CASE( ContainerDef )
    CASE( ContentStorage )
    CASE( ControlPoint )
    CASE( DataDef )
    CASE( DefObject )
    CASE( PluginDef )
    CASE( Dictionary )
    //CASE( Edgecode )
    //CASE( OperationDef )
    CASE( EssenceAccess )
    CASE( EssenceData )
    CASE( EssenceDescriptor )
    CASE( Event )
    CASE( EventMobSlot )
    CASE( File )
    CASE( FileDescriptor )
    CASE( FilmDescriptor )
    CASE( DigitalImageDescriptor )
    CASE( CDCIDescriptor )
//    CASE( EssenceFormat )
    CASE( EssenceGroup )
    CASE( Filler )
    CASE( FindSourceInfo )
    CASE( OperationGroup )
    CASE( GPITrigger )
    CASE( Header )
    CASE( Identification )
//    CASE( InterpolationDef )
    CASE( KLVData )
    CASE( Locator )
    CASE( MasterMob )
    CASE( MasterMob2 )
    CASE( MasterMobEx )
//    CASE( MetaDefinition )
    CASE( Mob )
    CASE( MobSlot )
    CASE( NestedScope )
    CASE( NetworkLocator )
    CASE( Object )
    CASE( Parameter )
//    CASE( ParameterDef )
//    CASE( Property )
//    CASE( PropertyDef )
//    CASE( PropertyValue )
    CASE( PluginManager )
    CASE( Pulldown )
    CASE( RGBADescriptor )
    CASE( ScopeReference )
    CASE( Segment )
    CASE( Selector )
    CASE( Sequence )
    CASE( SourceClip )
    CASE( SourceMob )
    CASE( SourceReference )
    CASE( StaticMobSlot )
    CASE( TapeDescriptor )
    CASE( TaggedValue )
    CASE( TextLocator )
    CASE( Timecode )
    CASE( TimelineMobSlot )
    CASE( Transition )
    CASE( TIFFDescriptor )
    CASE( TimecodeStream )
    CASE( TimecodeStream12M )
    CASE( TypeDef )
    CASE( TypeDefCharacter )
    CASE( TypeDefIndirect )
    CASE( TypeDefInt )
    CASE( TypeDefRename )
    CASE( TypeDefEnum )
    CASE( TypeDefExtEnum )
    CASE( TypeDefFixedArray )
    CASE( TypeDefRecord )
    CASE( TypeDefSet )
    CASE( TypeDefStream )
    CASE( TypeDefString )
    CASE( TypeDefStrongObjRef )
    CASE( TypeDefWeakObjRef )
    CASE( TypeDefObjectRef )
    CASE( TypeDefOpaque )
    CASE( TypeDefVariableArray )
    CASE( VaryingValue )
    CASE( WAVEDescriptor )
    CASE( RawStorage )
    CASE( RandomRawStorage )
    CASE( GetFileBits )
    CASE( SetFileBits )
    CASE( RandomFile )
    CASE( Endian )
    CASE( SearchSource )
    CASE( EssenceMultiAccess )
    CASE( TypeDefVariableArrayEx )
    
    // New 1.1 objects.
    CASE( AES3PCMDescriptor )
    CASE( AuxiliaryDescriptor )
    CASE( Component2 )
    CASE( DataDef2 )
    CASE( DataDef3 )
    CASE( DescriptiveFramework )
    CASE( DescriptiveMarker )
    CASE( Dictionary2 )
    CASE( Header2 )
    CASE( ImportDescriptor )
    CASE( KLVDataDefinition )
    CASE( Mob2 )
    CASE( MultipleDescriptor )
    CASE( PCMDescriptor )
    CASE( PhysicalDescriptor )
    CASE( RecordingDescriptor )
    CASE( RGBADescriptor2 )
    CASE( SoundDescriptor )
    CASE( TaggedValueDefinition )
    CASE( TimelineMobSlot2 )

    
    // New additions for the 1.1.6 release (added since 1.1).
    CASE( BWFImportDescriptor )
    CASE( DataEssenceDescriptor )
    CASE( DescriptiveClip )
    CASE( DescriptiveObject )
    CASE( MPEGVideoDescriptor )
    CASE( RIFFChunk )
    
    // plugin interfaces
//    CASE( IAAFPlugin )
//    CASE( IAAFClassExtension )
//    CASE( IAAFEssenceStream )
//    CASE( IAAFEssenceDataStream )
//    CASE( IAAFEssenceCodec )
//    CASE( IAAFMultiEssenceCodec )
//    CASE( IAAFEssenceContainer )
//    CASE( IAAFInterpolator )

    
    #undef CASE

    
    else
    {
    std::cout <<"* Unable To Resovle" << classname << "\n";

    return boost::python::object(sp);
    
    
    }
}

boost::python::object resolve_metadef(IUnknownSP spMetaDef)
{
    
    
    
    if (isClassType<IAAFTypeDef>(spMetaDef) )
    {
            
        IAAFTypeDefSP spTypeDef =  AxQueryInterface<IUnknown,IAAFTypeDef>(spMetaDef);
        AxTypeDef axTypeDef(spTypeDef);
        eAAFTypeCategory_t cat = axTypeDef.GetTypeCategory();
        
        switch( cat )
        {
                
                #define CASE(T)	\
                case kAAFTypeCat##T :	\
                { \
                IAAFTypeDef##T##SP sp; \
                AxQueryInterface( axTypeDef.GetTypeDefSP(), sp ); \
                return boost::python::object(sp); \
                }
                
                CASE( Int )
                CASE( Character )
                CASE( StrongObjRef )
                CASE( WeakObjRef )
                CASE( Rename )
                CASE( Enum )
                CASE( FixedArray )
                CASE( Set )
                CASE( Record )
                CASE( Stream )
                CASE( String )
                CASE( ExtEnum )
                CASE( Indirect )
                CASE( Opaque )
                CASE( VariableArray )
                
                #undef CASE
                
            default:
                throw AxExBadImp( L"unknown typeDef category" );
                
        }
    }
    
    #define CASE(T)	\
    else if (isClassType<IAAF##T>(spMetaDef) ){	\
    IAAF##T##SP spItem = AxQueryInterface<IUnknown,IAAF##T>(spMetaDef);	\
    return boost::python::object(spItem);}
    
    CASE(ClassDef)
    CASE(PropertyDef)

    #undef CASE

    else
    {
        
        throw AxExBadImp( L"unknown typeDef category" );
    }
    
    return boost::python::object();
}
boost::python::object resolve_IEnumAAF(IUnknownSP sp)
{
        
        
    #define CASE(T)	\
    if (isClassType<T>(sp)){	\
    T##SP spItem = AxQueryInterface<IUnknown, T>(sp);	\
    return boost::python::object(spItem);}
    
    CASE( IEnumAAFClassDefs )
    CASE( IEnumAAFCodecDefs )
    CASE( IEnumAAFCodecFlavours )
    CASE( IEnumAAFComponents )
    CASE( IEnumAAFContainerDefs )
    CASE( IEnumAAFControlPoints )
    CASE( IEnumAAFDataDefs )
    CASE( IEnumAAFIdentifications )
    CASE( IEnumAAFInterpolationDefs )
    CASE( IEnumAAFOperationDefs )
    CASE( IEnumAAFEssenceData )
    CASE( IEnumAAFKLVData )
    CASE( IEnumAAFLoadedPlugins )
    CASE( IEnumAAFLocators )
    CASE( IEnumAAFMobSlots )
    CASE( IEnumAAFMobs )
    CASE( IEnumAAFParameterDefs )
    CASE( IEnumAAFParameters )
    CASE( IEnumAAFProperties )
    CASE( IEnumAAFPropertyDefs )
    CASE( IEnumAAFPropertyValues )
    CASE( IEnumAAFPluginDefs )
    CASE( IEnumAAFPluginLocators )
    CASE( IEnumAAFSegments )
    CASE( IEnumAAFTaggedValues )
    CASE( IEnumAAFTypeDefs )
    
    CASE( IEnumAAFKLVDataDefs )
    CASE( IEnumAAFTaggedValueDefs )
    
    
    #undef CASE
    
    throw AxExBadImp( L"unknown IUnknownSP type category" );

}

boost::python::object resolve_smartpointer(IUnknownSP sp)
{
    
    if (isClassType<IAAFObject>(sp))
        
    {
        
        IAAFObjectSP spObject = AxQueryInterface<IUnknown,IAAFObject>(sp);
        
        return resolve_object(spObject);
        
    }
    
    else if (isClassType<IAAFMetaDefinition>(sp))
    {
        return resolve_metadef(sp);
        
    }
    
    #define CASE(T)	\
    else if (isClassType<IAAF##T>(sp) ){	\
    IAAF##T##SP spItem = AxQueryInterface<IUnknown,IAAF##T>(sp);	\
    return boost::python::object(spItem);}
    
    CASE(Property)
    CASE(PropertyValue)
    CASE(EssenceFormat)
    CASE(EssenceAccess)
    CASE(EssenceMultiAccess)

    #undef CASE
    
    
    
    else
    {
        //return boost::python::object();
        
        return resolve_IEnumAAF(sp);
        throw AxExBadImp( L"unknown IUnknownSP type category" );
    }
    
}


