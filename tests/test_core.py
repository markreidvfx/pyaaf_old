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
        

if __name__ == '__main__':
    unittest.main()

    