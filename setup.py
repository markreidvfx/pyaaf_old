from distutils.core import setup, Extension

import os
import glob

AAFSDK_ROOT = os.environ.get('AAFSDK_ROOT', '/usr')
BOOST_ROOT = os.environ.get('BOOST_ROOT', '/usr')

include_dirs = ['axLib', 
                'include',
                os.path.join(BOOST_ROOT, 'include'),
                os.path.join(AAFSDK_ROOT, 'include')
                 ]

library_dirs = [ os.path.join(BOOST_ROOT, 'lib'),
                os.path.join(AAFSDK_ROOT, 'lib') ]

#this might be boost_python 
libraries = [ 'boost_python-mt' ]

axLib_source_files = glob.glob('axLib/*.cpp')
pyaaf_source_files = glob.glob('src/*.cpp')


source_files = []
source_files.extend(axLib_source_files)
source_files.extend(pyaaf_source_files)


setup( name="pyaaf", 
       version='0.0.1',
        packages=['pyaaf'],
        ext_modules=[Extension( 'pyaaf.core', source_files, 
                                include_dirs=include_dirs, 
                                library_dirs=library_dirs, 
                                libraries=libraries )] )