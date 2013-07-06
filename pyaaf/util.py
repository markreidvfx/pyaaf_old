from functools import wraps
import core
import pickle
import os

AX_NAME_REPLACERS = (("",""),("Definition","Def"),
                     ('EdgeCode','Edgecode'))

def Ax(sp):
    """
    converts a smartpointer (objects prefixed with SP) object to a AxObject.
    if sp is not a smartpointer the object is returned as is.
    """
    # if not a smartpointer return sp
    if not isinstance(sp, core.smartpointers.AxSmartPointer):
        return sp
    
    sp = sp.ResolveSP()
    
    #if sp is a IAAFObjectSP After resolving, return a AxObject
    if isinstance(sp, core.smartpointers.IAAFObjectSP):
        return core.AxObject(sp)
    
    class_name = sp.GetClassName()
    
    #iterators are wrap in a AxIterWraper 
    if class_name.count("IEnumAAF"):
       iterator_name = class_name.replace('IEnumAAF', '')
       
       d = core.AxIter.__dict__
       
       if d.has_key(iterator_name):
           class_object = d[iterator_name]
           return AxIterWraper(class_object(sp))
           
       iterator_name = iterator_name.rstrip("s")
       if d.has_key(iterator_name):
           class_object = d[iterator_name]
           return AxIterWraper(class_object(sp))
       
       iterator_name = class_name.replace('IEnumAAF', '').replace('ies', 'y')
       
       if d.has_key(iterator_name):
           class_object = d[iterator_name]
           return AxIterWraper(class_object(sp))
       
       else:
           raise ValueError("unknown Ax iterator for %s %s" % (class_name, str(sp)) )
    else:
        
        class_object = get_AxClass(sp)
        if not class_object:
            raise ValueError("no AxObject found for %s %s" % (class_name,str(sp)))

        return class_object(sp)
    
def get_AxClass(sp):
    
    """find the Ax Class for a given smartpointer
    """
    
    if not isinstance(sp, core.smartpointers.AxSmartPointer):
        return None
    class_name = sp.GetClassName() 
    
    d = core.__dict__
    
    for old, new in AX_NAME_REPLACERS:
        class_name = class_name.replace(old,new)
        ax_name = 'Ax%s' % class_name
        
        if d.has_key(ax_name):
            return d[ax_name]
        
    return None



class AxIterWraper(object):
    def __init__(self, ax_iter):
        self.ax_iter = ax_iter
        
    def __iter__(self):
        return self
    
    def next(self):
        return Ax(self.ax_iter.next())
    
def __get_docs():
    
    doc_file = os.path.join(os.path.dirname(os.path.abspath(__file__)),'docs.pkl')
    
    if os.path.exists(doc_file):
        f = open(doc_file)
        docs = pickle.load(f)
        f.close()
        return docs
            
    
    
def __AxWrap(d):
    skip = ("AxInit")
    docs = __get_docs()
    for name, obj in d.items():
        if name in skip:
            pass
        elif name.startswith("Ax"):
            __AxWrapClass(obj,docs.get(name) or {})
            

def __AxWrapClass(obj,docs=None):
    startswiths = ('_','to','Initialize','CreateInstance')
    for name in dir(obj):
        if not any([name.startswith(i) for i in startswiths]):
            
            setattr(obj,name, __AxDecorator(getattr(obj,name), docs.get(name)))
            
        if name.startswith('CreateInstance'):
            setattr(obj,name, __AxDecoratorStatic(getattr(obj,name)))
        
def __AxDecoratorStatic(f,docs =None):
    @staticmethod
    @wraps(f)
    def _decorator(*args, **kwargs):
        return Ax(f(*args, **kwargs))
    return _decorator
    
            
def __AxDecorator(f,docs=None):
    @wraps(f)
    def _decorator(*args, **kwargs):
        return Ax(f(*args, **kwargs))
    
    if docs:
        _decorator.__doc__ += '\n\n' + docs
        
    return _decorator