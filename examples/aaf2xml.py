import pyaaf
import os
from optparse import OptionParser
    
parser = OptionParser()
(options, args) = parser.parse_args()

if not args:
    parser.error("not enough argements")
    
path = args[0]
name, ext = os.path.splitext(path)

with pyaaf.open(path, 'r') as f:
    f.toXml(name + ".xml")

