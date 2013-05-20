from hierarchy import get_hierachy

pyste = ""


pyste += """
Include("AxBaseObj.h")
Include("AxBaseObjIter.h")
Include("AxComponent.h")
Include("AxContentStorage.h")
Include("AxDefObject.h")
Include("AxDescriptiveFramework.h")
Include("AxDictionary.h")
Include("AxEssence.h")
Include("AxEx.h")
Include("AxFile.h")
Include("AxHeader.h")
Include("AxHrMap.h")
Include("AxInit.h")
Include("AxIterator.h")
Include("AxKLVData.h")
Include("AxMetaDef.h")
Include("AxMob.h")
Include("AxMobSlot.h")
Include("AxObject.h")
Include("AxParameter.h")
Include("AxPluginMgr.h")
Include("AxProperty.h")
Include("AxPropertyValue.h")
Include("AxPropertyValueDump.h")
Include("AxSmartPointer.h")
Include("AxStorageErrors.h")
Include("AxTaggedValue.h")
Include("AxTypes.h")
Include("AxUtil.h")


"""

h = get_hierachy()




pyste += 'module_code("""\n\n'


implicit = '     implicitly_convertible<Ax%s, IAAFSmartPointer<IAAF%s> > ();\n'
implicitSP = '     implicitly_convertible<Ax%s, IAAF%sSP> ();\n'
for key,value in h.items():
    #print key
    #print value.get_parents(True)
    name = value.alt_name or value.name
    sp = ()
    #sp = ("Filler")
    
    skip = ("CDCIDescriptor",
            "WAVEDescriptor",
            "DigitalImageDescriptor",
            "Sequence",
            "EssenceMultiAccess",
            "Timecode",
            "FileDescriptor",
            "GPITrigger",
            "Identification",
            "Filler",
            "BaseObj",
            "ContentStorage",
            "Property",
            'TypeDefObjRef',
            "TypeDefObjectRef",
            'TypeDefRecord',
            "TypeDefVariableArray",
            "TypeDefIndirect",
            "TypeDefExtEnum",
            "TypeDefInt",
            "TypeDefSet",
            "TypeDefString",
            "TypeDefStream",
            "TypeDefVariableArrayEx",
            "TypeDefWeakObjRef",
            "TypeDefStrongObjRef",
            "CommentMarker",
            "TypeDefEnum",
            "TypeDefFixedArray",
            "TypeDefOpaque",
            "MetaDefinition",
            "EssenceAccess",
            "Parameter",
            "Event")

    if name in sp:
        pyste += implicitSP % (name,key)
        pyste += "\n"
    
    elif name in skip:
        pass

    else:
    
       
        
        #print name, key
        
        pyste += "\n//Ax%s\n\n" % name
        
        pyste += implicit % (name,key)
        pyste += "\n"
        for item in value.get_parents():
            
            
            if item in skip:
                pass
            else:
            
                pyste += implicit % (name,item)
        #implicitly_convertible<AxSequence,IAAFSmartPointer<IAAFSegment> > ();
    
pyste += '\n""")\n'

f = open("implicitly_convertible.pyste","w")

f.write(pyste)
f.close()