from core import *
import core


def Initialize():
    """
    find libcom-api and initialize
    """
    import os
    import sys
    dirname = os.path.dirname(__file__)
    
    ext = '.so'
    if sys.platform == 'darwin':
        ext = '.dylib'
    elif sys.platform.startswith("win"):
        ext = '.dll'
        
    AX_AAF_COMAPI = os.path.join(dirname,'libcom-api' + ext)
    os.environ['AX_AAF_COMAPI'] = os.environ.get('AX_AAF_COMAPI', AX_AAF_COMAPI)
    
    return core.AxInit()
    
    
_AxInit = Initialize()

from util import __AxWrap

__AxWrap(globals())

from open import open
from util import Ax