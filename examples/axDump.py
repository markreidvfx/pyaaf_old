import pyaaf
from pyaaf import core
import traceback
from optparse import OptionParser
    
parser = OptionParser()

parser.add_option('-o','--objects',action="store_true", default=False)
parser.add_option('-p','--properties',action="store_true", default=False)
parser.add_option('-v','--values',action="store_true", default=False)
parser.add_option('-r','--records',action="store_true", default=False)
parser.add_option('--verbose',action="store_true", default=False)

(options, args) = parser.parse_args()

if not args:
    parser.error("not enough argements")
    
    
with pyaaf.open(args[0]) as f:

    header = pyaaf.Ax(f.GetHeader())
    
    print "renamePeskyOpaques", pyaaf.renamePeskyOpaques(header)
    ObjectRecIter = pyaaf.BaseObjectRecIter(header)
    i = 0
    for record_name, item in ObjectRecIter:
        level = ObjectRecIter.GetLevel()
        class_name = item.GetClassName()
        obj = None
        try:
            obj = pyaaf.Ax(item)
        except:
            obj = pyaaf.AxObject(item)
            

        title = "%07d %03d    " % (i,level)
        title += "%s" +  "  "* level
        
        if record_name:
            if options.records:
                print title%"record  ",record_name
        
        elif class_name == "Property":
            
            if str(obj.GetAUID()) in (str(core.PropertyDef.Header_Dictionary),
                                      str(core.PropertyDef.Header_Version),
                                      str(core.PropertyDef.Header_IdentificationList),
                                      ):
                #skip dictionary section
                if not options.verbose:
                    ObjectRecIter.PopStack()
                
            if options.properties:
                print title%'property', obj.GetName()
                
        elif class_name == 'PropertyValue':
            if options.values:
                print title%"value   ", obj
        
    
        else:
       
            if options.objects:    
                print title%"object  ",class_name

        i+= 1

