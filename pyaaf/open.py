import core
from contextlib import contextmanager

@contextmanager
def open(path,mode):
    axfile = core.AxFile()
    
    try:
        if mode == 'w':
            axfile.OpenNewModify(path)
        elif mode == 'r' or mode == 'ro':
            axfile.OpenExistingRead(path)
        elif mode == 'rw':
            axfile.OpenExistingModify(path)
            
        yield axfile
        
    finally:
        axfile.Close()
    
    