

from hierarchy import get_hierachy
import traceback
h = get_hierachy()

f = open("smart.txt", 'r')
s = f.read()

f.close()

pyste = 'Include("AxSmartPointer.h")\n'
pyste = 'Include("query_interface.h")\n'

pyste += 'declaration_code("""\n'

pyste += 'class SmartPointers {};\n'

pyste += '""")\n'

pyste += 'module_code("""\n'
pyste += 'scope smartpointers = class_<SmartPointers>("smartpointers");\n'

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
            
            string =  'class_< %s > ("%s")\n' 
            string = string % (pointer_name,pointer_name)
            
            
            try:
                key = name.replace("2",'').replace('3','')
                if key in h.keys():
                    #print name, h[name].get_all_children()
                    
                    for q in h[key].get_all_children(True):
                        string += '.def("to_%sSP", query_interface<IAAF%s, IAAF%s > )\n' % ( q, name, q)
                
                
                #queryInterfaces =  line.split(":")[1].strip().split(' ')
                #for q in queryInterfaces:
                    
                    
            except:
                print traceback.format_exc()
                
            
            
            string += ';\n'
            pyste += string
    
        
    except:
        pass

pyste += '""")\n'


#print pyste

f = open("AxSmartPointer.pyste",'w')

f.write(pyste)
f.close()
