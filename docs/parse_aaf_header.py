
import pickle

header_path = "/Users/mark/Dev/aaf/aaf-git/AAFx86_64DarwinSDK/g++/include/AAF.h"
f = open(header_path, 'r')
header = f.read()
f.close()


comments = ""


interface = {}

current = None
for line in header.splitlines():
    if line.count("//"):
        
        if line.count("// Interface"):
            current = line.replace("// Interface",'').strip()
            
            current = current.replace('IEnumAAF','AxIter.').replace("IAAF",'Ax')
            
        if current:
            if not interface.has_key(current):
                interface[current] = ""
            interface[current] += line
            interface[current] += '\n'
            
doc_dict = {}   
for item, value in sorted(interface.items()):
    
    for i in value.split("//***********************************************************"):
        lines = i.splitlines()
        method = None
        try:
            
            line2 = lines[2]
            if line2.count("("):
                method = line2.replace("//",'').replace("(",'').replace(")","").strip()
        except:
            pass
        
        if method:
            if not doc_dict.has_key(item):
                doc_dict[item] = {}
            
            doc = ""
            
            for l in lines[3:]:
                doc_line = """  ///"""
                if l.count(doc_line):
                    doc += l.replace(doc_line,'') + '\n'
            
            doc_dict[item][method] = doc
            
            #"\n".join(lines[3:])
            

for key,value in sorted(doc_dict.items()):
    print key
    for method,docs in value.items():
        print key,'::',method
        print docs
            
pickle.dump(doc_dict,open('docs.pkl', 'w'),pickle.HIGHEST_PROTOCOL)
