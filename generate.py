import os
import subprocess
import glob
from multiprocessing import Pool
import traceback


AAF_ROOT = os.environ.get('AAFSDK_ROOT','/Users/mark/Dev/aaf/aaf-git')
AAF_PLATFORM = os.environ.get('AAF_PLATFORM', "x86_64Darwin")


aaf_include_dirs = [os.path.join(AAF_ROOT, 'AAF%sSDK' % AAF_PLATFORM, 'g++', 'include'),
                    os.path.join(AAF_ROOT,'examples2','axLib'),
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
    

def run_gen():

    working_dir = 'pyste_src'

    cmd = ['python','gen_smartpointers.py']
    print subprocess.list2cmdline(cmd)
    subprocess.check_call(cmd,cwd=working_dir)
    cmd = ['python','gen_iterators.py']
    print subprocess.list2cmdline(cmd)
    subprocess.check_call(cmd,cwd=working_dir)
    
  
def run_pyste(pyste_files=None):
    
    if not pyste_files:
        pyste_files = glob.glob('./pyste_src/*.pyste')
        
    all_pyste_files = glob.glob('./pyste_src/*.pyste')
    
    includes = []
    
    commands = []
    
    for item in aaf_include_dirs:
        includes.extend(['-I',item])
        
    cmd = ['pyste.py', '--module=pyaaf', '--multiple', '--generate-main', '--out=./src']
    cmd.extend(includes)
    cmd.extend(all_pyste_files)
    
    commands.append(cmd)
    
    for item in pyste_files:
        cmd = ['pyste.py', '--module=pyaaf', '--multiple' ,'--out=./src']
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
    (options, args) = parser.parse_args()
    
    run_gen()    
    run_pyste(args)


