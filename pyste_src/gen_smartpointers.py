
f = open("smart.txt", 'r')
s = f.read()

f.close()

pyste = 'Include("AxSmartPointer.h")\n'

pyste += 'module_code("""\n'

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
            
            string =  'class_< %s > ("%s");\n' 
            string = string % (pointer_name,pointer_name)
            
            pyste += string
    
        
    except:
        pass

pyste += '""")\n'


#print pyste

f = open("AxSmartPointer.pyste",'w')

f.write(pyste)
f.close()
