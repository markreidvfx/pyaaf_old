

from hierarchy import get_hierachy
import traceback
h = get_hierachy()

f = open("smart.txt", 'r')
s = f.read()

f.close()

pyste = 'Include("AxSmartPointer.h")\n'
pyste = 'Include("query_interface.h")\n'

pyste +="""
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
Include("AxStorageErrors.h")
Include("AxTaggedValue.h")
Include("AxTypes.h")
Include("AxUtil.h")
Include("AAFTypes.h")
Include("resolve_smartpointer.h")

"""

declaration_code = 'declaration_code("""\n'

declaration_code += 'class SmartPointers {};\n'
declaration_code += 'class AxSmartPointer {};\n'

pyste += 'module_code("""\n'
pyste += 'scope smartpointers = class_<SmartPointers>("smartpointers");\n'
pyste += 'class_<AxSmartPointer>("AxSmartPointer");\n'

for line in s.splitlines():
    
    
        
    try:
        if not line[0] == '/':
            
            pointer_type = line.split("(")[0].strip()
            name = line.split("(")[1].split(")")[0].split(',')[0].strip()
            
            pointer_name = 'IAAF%sSP' % name
            
            if pointer_type == 'AXSP_TDEF_C':
                pointer_name = '%sSP' % name
                
            #elif pointer_type == 'AXSP_TDEF_D':
                #pointer_name = 'IAAF%sSP' % name[:-1]
                
                #pointer_name = ""
                
            #if pointer_type == 'AXSP_TDEF_A':
            #    pass
            #else:
            
            #print pointer_name
            
            string =  'class_< %s , bases < AxSmartPointer >  > ("%s")\n' 
            string = string % (pointer_name,pointer_name)
            
            string += '.def("to_%sSP", query_interface_pass_through<%s > )\n' % ( name, pointer_name)
            
            if pointer_type == "AXSP_TDEF_C":
                string += '.def("ResolveSP", resolve_any_smartpointer< %s > )\n' % (name) 
            else:
                string += '.def("ResolveSP", resolve_any_smartpointer< IAAF%s > )\n' % (name) 

            try:
                key = name.replace("2",'').replace('3','')
                if key in h.keys():
                    #print name, h[name].get_all_children()
                    node = h[key]
                    for q in node.get_all_children(True):
                        string += '.def("to_%sSP", query_interface<IAAF%s, IAAF%s > )\n' % ( q, name, q)
                        
                        
                        
                    if "Object" in node.get_parents() or key == 'Object':
                        axname = node.alt_name or key
                        string += '.def("GetClassName",PyGetClassName<IAAF%s, Ax%s> )\n' %(name,axname)
                    elif 'TypeDef' in node.get_parents() or key == 'TypeDef':
                        axname = node.alt_name or key
                        string += '.def("GetClassName",PyGetTypeCategory<IAAF%sSP, Ax%s> )\n' %(name,axname)
                        pass
                    else:
                        declaration_code += 'extern const char classname_%s[] = "%s";\n'  % (name,key)
                        
                        string += '.def("GetClassName",PyGetClassName_from_string<IAAF%sSP, classname_%s> )\n' %(name, key)
                elif key.count("IEnumAAF"):
                    declaration_code += 'extern const char classname_%s[] = "%s";\n'  % (name,key)
                    string += '.def("GetClassName",PyGetClassName_from_string<%sSP, classname_%s> )\n' %(name, key)
                    
                elif key in ("IUnknown"):
                    declaration_code += 'extern const char classname_%s[] = "%s";\n'  % (key,key)
                    string += '.def("GetClassName",PyGetClassName_from_string<%sSP, classname_%s> )\n' %(key, key)

                    
            except:
                print traceback.format_exc()
                
            
            
            string += ';\n'
            pyste += string
    
        
    except:
        pass

pyste += '""")\n'


declaration_code += '""")\n'

pyste += declaration_code

#print pyste

f = open("AxSmartPointer.pyste",'w')

f.write(pyste)
f.close()
