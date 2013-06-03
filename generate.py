import os
import subprocess
import glob
from multiprocessing import Pool
import traceback


AAF_ROOT = os.environ.get('AAFSDK_ROOT','/Users/mark/Dev/aaf/aaf-git/AAFx86_64DarwinSDK/g++')

aaf_include_dirs = ['./include',
                    './axLib',
                    os.path.join(AAF_ROOT, 'include'),
                    ]
                    



def run_cmd(cmd):
    #print subprocess.list2cmdline(cmd)
    stdout = None
    stderr = None
    try:
        p = subprocess.Popen(cmd,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
        
        stdout,stderr = p.communicate()
        
        
        
    except:
        print traceback.format_exc()
        
        
    return cmd,stdout,stderr

def find_aaf_header():
    
    for d in aaf_include_dirs:
        aaf_header = os.path.join(d,'AAF.h')
        if os.path.exists(aaf_header):
            return aaf_header

def run_gen(docs=False):

    working_dir = 'pyste_src'

    cmd = ['python','gen_smartpointers.py']
    print subprocess.list2cmdline(cmd)
    subprocess.check_call(cmd,cwd=working_dir)
    cmd = ['python','gen_iterators.py']
    print subprocess.list2cmdline(cmd)
    subprocess.check_call(cmd,cwd=working_dir)
    
    cmd = ['python','gen_implicitly_convertible.py']
    print subprocess.list2cmdline(cmd)
    subprocess.check_call(cmd,cwd=working_dir)
    
    aaf_header_path = find_aaf_header()
    
    if aaf_header_path and docs:
        cmd = ['python','docs/parse_aaf_header.py',aaf_header_path,'pyaaf/docs.pkl']
        print subprocess.list2cmdline(cmd)
        subprocess.check_call(cmd)
    else:
        print "skipping docstring generation"
  
def run_pyste(pyste_files=None):
    
    if not pyste_files:
        pyste_files = glob.glob('./pyste_src/*.pyste')
        
    all_pyste_files = glob.glob('./pyste_src/*.pyste')
    
    includes = []
    
    commands = []
    
    for item in aaf_include_dirs:
        includes.extend(['-I',item])
        
    cmd = ['pyste.py', '--module=core', '--multiple', '--generate-main', '--out=./src']
    cmd.extend(includes)
    cmd.extend(all_pyste_files)
    
    commands.append(cmd)
    
    for item in pyste_files:
        cmd = ['pyste.py', '--module=core', '--multiple' ,'--out=./src']
        cmd.extend(includes) 
        cmd.append(item)
        
        commands.append(cmd)
        
    p = Pool()
    
    for cmd,stdout,stderr in p.imap_unordered(run_cmd,commands):
        print subprocess.list2cmdline(cmd)
        print stdout
        #print stderr
  
    
    p.close()
    p.join()
    
    
    

if __name__ == "__main__":
    from optparse import OptionParser
    
    parser = OptionParser()
    parser.add_option('-d','--docstrings',action="store_true", default=False,
                      help="parse AAF.h and gerate docstrings")
    (options, args) = parser.parse_args()
    
    run_gen(options.docstrings)    
    run_pyste(args)


