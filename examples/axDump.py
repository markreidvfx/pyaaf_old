import pyaaf


from optparse import OptionParser
    
parser = OptionParser()
(options, args) = parser.parse_args()

if not args:
    parser.error("not enough argements")


a = pyaaf.AxInit()
f= pyaaf.AxFile()
f.OpenExistingRead(args[0])

headerSP = f.getHeader()

ObjectRecIter = pyaaf.BaseObjectRecIter(pyaaf.AxHeader(headerSP))

for item in ObjectRecIter:
    
    ax = pyaaf.PyAxObject()
    ax.set_object(item)
    
    level = ObjectRecIter.GetLevel()
    
    print " " * level,
    
    if isinstance(item, pyaaf.AxHeader):
        print "AxHeader"
    
    elif ax.isAxObject():
        obj = ax.toAxObject()
        name = obj.GetClassName()
        print 'AxObject', name
        
    elif ax.isAxProperty():
        obj = ax.toAxProperty()
        name = obj.GetName()
        auid = obj.GetAUID()
        definition = obj.GetDefinition()
        value = pyaaf.AxPropertyValue(obj.GetValue())
        
        print "AxProperty",name,value,definition
    
    elif ax.isAxPropertyValue():
        obj = ax.toAxPropertyValue()
        #dump = pyaaf.valueDump(obj)
        print "AxPropertyValue",str(obj)

        
    elif ax.isAxRecordIterator():
        obj = ax.toAxRecordIterator()
        record = pyaaf.PyRecord()
        record.set_object(obj)
        
        second = record.second()
        p = pyaaf.AxPropertyValue(second)
        
        print "AxRecordIterator", record.first(),str(p)

    else:
        print "***",item
        

