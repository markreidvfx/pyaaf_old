#f = open("smart.txt", 'r')
#print f
#s = f.read()

#f.close()

pyste = 'Include("AxIterator.h")\n'

pyste += 'declaration_code("""\n'

pyste += """

inline object pass_through(object const& o) { return o; }

template<class Klass,class KlassRef, class KlassIter, class KlassIterInit >
struct iterator_wrappers
{
    static Klass
    next(KlassIter& o)
    {
        bool notAtEnd;
        IAAFSmartPointer2<KlassRef> nextMob;
        
        notAtEnd = o.NextOne(nextMob);
        if (!notAtEnd) {
            PyErr_SetString(PyExc_StopIteration, "No more data.");
            boost::python::throw_error_already_set();
        }
        return nextMob;
    }
    
    static void
    wrap(const char* python_name)
    {
        //using namespace boost::python;
        class_<KlassIter>(python_name, init <KlassIterInit>())
        .def("next", next)
        .def("__iter__", pass_through)
        ;
    }
};

class AxIter {};

"""
pyste += '""")\n'


iters = [
'ClassDef',
'CodecDef',
#'CodecFlavours',
'Component',
'ContainerDef',
'ControlPoint',
'DataDef',
#'Identification',
'InterpolationDef',
'OperationDef',
'EssenceData', #no s
#'KLVData', #no s IAAFKLVDataDefinition???
#'LoadedPlugin',
'Locator',
'MobSlot',
'Mob',
'ParameterDef',
'Parameter',
'Property',
'PropertyDef',
'PropertyValue',
'PluginDef',
#'PluginLocator',
'Segment',
#'TaggedValueDef',
'TypeDef',
]

#iterator_wrappers<const IAAFMobSP, IAAFMob, AxMobIter, IEnumAAFMobsSP>().wrap("AxMobIter");


pyste += 'module_code("""\n\n'
pyste += 'scope* AxIter_scope = new scope(class_<AxIter>("AxIter"));'
for i in iters:
    
    if i in ('EssenceData','KLVData','CodecFlavours'):
        IEnumAAF =  i
        
    elif i in ('Property'):
        IEnumAAF = 'Properties'
    
    else:
        IEnumAAF = "%ss" % i
        
    if i in ('ClassDef','CodecFlavours','ControlPoint','Identification','OperationDef','KLVData','Property',
             'Locator','TypeDef','MobSlot','Mob','Parameter','PropertyDef','PropertyValue'):
        AxName = i
        
    elif i in ('EssenceData'):
        AxName = 'Essence'
    else: 
        AxName = '%ss' %  i
        
    if i in ('Components'):
        smartpointer = i[:-1]
    
    elif i in ('Property'):
        smartpointer = 'Properties'
        
    else:
        smartpointer = i
        
        
    
    s = 'iterator_wrappers<const IAAF%sSP, IAAF%s, Ax%sIter, IEnumAAF%sSP>().wrap("%s");\n'  % (i,i,AxName,IEnumAAF,AxName)
    
    pyste += s

pyste += 'delete AxIter_scope;'

pyste += '\n""")\n'

f = open("AxIterator.pyste","w")

f.write(pyste)
f.close()