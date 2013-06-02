
import core


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
       if core.AxIter.__dict__.has_key(iterator_name):
           class_object = core.AxIter.__dict__[iterator_name]
           return AxIterWraper(class_object(sp))
           
       iterator_name = iterator_name.rstrip("s")
       if core.AxIter.__dict__.has_key(iterator_name):
           class_object = core.AxIter.__dict__[iterator_name]
           return AxIterWraper(class_object(sp))
       
       iterator_name = class_name.replace('IEnumAAF', '').replace('ies', 'y')
       if core.AxIter.__dict__.has_key(iterator_name):
           class_object = core.AxIter.__dict__[iterator_name]
           return AxIterWraper(class_object(sp))
       
       else:
           raise ValueError(class_name)
        
   
    else:
        name = class_name
        for old, new in (("Definition","Def"),('EdgeCode','Edgecode')):
            name = name.replace(old,new)
        ax_name = 'Ax%s' % name
        class_object = core.__dict__[ax_name]
        
        #if sp is already a AxObject simple return it
        if isinstance(sp, class_object):
            return sp
        methodToCall = None
        
        for n in (name,class_name):
            method = 'to_%sSP' % n
            if hasattr(sp,method):
                methodToCall = getattr(sp, method)
                
                
        return class_object(methodToCall())
    
    

class AxIterWraper(object):
    def __init__(self, ax_iter):
        self.ax_iter = ax_iter
        
    def __iter__(self):
        return self
    
    def next(self):
        return Ax(self.ax_iter.next())