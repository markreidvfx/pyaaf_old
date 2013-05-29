import unittest

import pyaaf
import os


def output_file(name):
    
    out_dir = os.path.join(os.path.dirname(__file__),'test_output')
    if not os.path.exists(out_dir):
        os.makedirs(out_dir)
        
    out_file = os.path.join(out_dir, name)
    
    if os.path.exists(out_file):
        os.remove(out_file)
        
    return out_file

class TestGeneral(unittest.TestCase):
    
    
    def test_create(self):

        aaf_file = output_file('test.aaf')
        aaf_copy = output_file('test_copy.aaf')
        xml_file = output_file('test.xml')
        
        with pyaaf.open(aaf_file, 'w') as f:
            
            f.toXml(xml_file)
            f.SaveCopyAs(aaf_copy)
        
        
        self.assertTrue(os.path.exists(aaf_file))
        self.assertTrue(os.path.exists(aaf_copy))
        self.assertTrue(os.path.exists(xml_file))
        
    def test_file_modes(self):
        
        aaf_file = output_file('test_file_modes.aaf')
        with pyaaf.open(aaf_file, 'w') as f:
            f.Save()
            
        with pyaaf.open(aaf_file) as f:
            with self.assertRaises(RuntimeError):
                f.Save()
                
        with pyaaf.open(aaf_file,'r') as f:
            with self.assertRaises(RuntimeError):
                f.Save()
        
        with pyaaf.open(aaf_file,'ro') as f:
            with self.assertRaises(RuntimeError):
                f.Save()
                
        with self.assertRaises(ValueError):        
            with pyaaf.open(aaf_file,'Bad File mode') as f: 
                pass
            
        with self.assertRaises(IOError):
            with pyaaf.open("this/path/does/not/exists.aaf",'r') as f: 
                pass
            

if __name__ == '__main__':
    unittest.main()

    