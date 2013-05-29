import core
from contextlib import contextmanager
import os

@contextmanager
def open(path,mode=None):
    """
    Open a AAF file, returning a AxFile Object. 
    Mode is a string is similar to python native open command.
    Possible modes are 'r' readonly, 'w' write, 'rw' readwrite or modify and 'ro' alias to readonly.
    """
    axfile = core.AxFile()
    o = False
    try:
        
        if mode == 'w':
            
            dirname = os.path.dirname(os.path.dirname(os.path.abspath(path)))
            if not os.path.exists(dirname):
                raise IOError(" No such directory: %s" % str(path))
            axfile.OpenNewModify(path)
            o = True
        elif mode is None or mode == 'r' or mode == 'ro':
            
            if not os.path.exists(path):
                raise IOError(" No such file: %s" % str(path))
            axfile.OpenExistingRead(path)
            o = True
            
        elif mode == 'rw':
            
            if not os.path.exists(path):
                raise IOError(" No such file: %s" % str(path))
            axfile.OpenExistingModify(path)
            o = True
        else:
            raise ValueError("mode must be string one of 'r','w','ro','rw', not %s" %str(mode))
            
        yield axfile
        
    finally:
        if o:
            axfile.Close()
    
    