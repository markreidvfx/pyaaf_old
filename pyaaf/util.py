
import core


def Ax(sp):
    """
    converts smartpointer(SP) object to corresponding AxObject
    """
    
    class_name = sp.GetClassName()
    
    if class_name == 'EdgeCode':
        class_name = 'Edgecode'

    if class_name.count("IEnumAAF"):
       iterator_name = class_name.replace('IEnumAAF', '')
       if core.AxIter.__dict__.has_key(iterator_name):
           return core.AxIter.__dict__[iterator_name](sp)
       iterator_name = iterator_name.rstrip("s")
       if core.AxIter.__dict__.has_key(iterator_name):
           return core.AxIter.__dict__[iterator_name](sp)
       iterator_name = class_name.replace('IEnumAAF', '').replace('ies', 'y')
       if core.AxIter.__dict__.has_key(iterator_name):
           return core.AxIter.__dict__[iterator_name](sp)
       
       else:
           raise ValueError(class_name)
   
    else:
        
        class_object = core.__dict__['Ax%s' % class_name]
        methodToCall = getattr(sp, 'to_%sSP' % class_name)
        return class_object(methodToCall())