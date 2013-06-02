
import core

AX_NAME_REPLACERS = (("",""),("Definition","Def"),('EdgeCode','Edgecode'))

def Ax(sp):
    """
    converts smartpointer(SP) object to corresponding AxObject.
    if sp does not have the a method named GetClassName the object is returned as is
    """
    
    if not hasattr(sp,"GetClassName"):
        return sp
    
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
           raise ValueError(class_name)
    else:
        
        class_object = get_AxClass(sp)
        if not class_object:
            raise ValueError(class_name)
        
        #if sp is already a AxObject simple return it
        if isinstance(sp, class_object):
            return sp
        
        methodToCall = None
        name = class_name
        for old, new in AX_NAME_REPLACERS:
            name = name.replace(old,new)
            method = 'to_%sSP' % name
            if hasattr(sp,method):
                methodToCall = getattr(sp, method)
                
                
        return class_object(methodToCall())
    
def get_AxClass(sp):
    
    if not hasattr(sp,"GetClassName"):
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