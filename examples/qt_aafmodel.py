import sys
from PyQt4 import QtCore

import pyaaf

class DummyItem(object):
    def __init__(self,item, name):
        self.item = item
        self.name = name
        
    def GetName(self):
        return self.name
    def GetClassName(self):
        return ""

class TreeItem(object):
    
    def __init__(self, item, parent=None):
        self.parentItem = parent
        self.item = item
        self.childItems = []
        self.properties = {}
        self.loaded = False
        #self.getData()
    def columnCount(self):
        return 1
    
    def childCount(self):
        self.setup()
        return len(self.childItems)
    
    def child(self,row):
        self.setup()
        return self.childItems[row]
    
    def childNumber(self):
        self.setup()
        if self.parentItem != None:
            return self.parentItem.childItems.index(self)
        return 0
    
    def parent(self):
        self.setup()
        return self.parentItem
    
    def extendChildItems(self, items):
        self.childItems.extend([TreeItem(i,self) for i in items])
        
    def name(self):
        item = self.item
        
        if isinstance(item,  pyaaf.AxSourceClip):
            try:
                ref = item.ResolveRef()
                return ref.GetName()
            except:
                return self.className()
                
        elif isinstance(item,pyaaf.AxOperationGroup):
            return item.GetOperationDef().GetName()
        elif hasattr(item,"GetName"):
            try:
                return item.GetName() or self.className()
            except:
                print "cannot GetName of %s" % str(item)
                return self.className()
        else:
            return self.className()

    def className(self):
        item = self.item

        if hasattr(item,"GetClassName"):
            return item.GetClassName()
        else:
            return item.__class__.__name__.replace("Ax","")
        
    def setup(self):
        if self.loaded:
            return
        
        item = self.item
        
        if isinstance(item, list):
            self.extendChildItems(item)
            
        elif isinstance(item, pyaaf.AxFile):
            self.extendChildItems([item.GetHeader()])
            
        elif isinstance(item, pyaaf.AxHeader):
            self.extendChildItems([item.GetContentStorage()])
            self.extendChildItems([item.GetDictionary()])
        
        elif isinstance(item, DummyItem):
            self.extendChildItems(item.item)
            
        elif isinstance(item, pyaaf.AxContentStorage):
            l = []
            l.append(DummyItem(list(item.GetCompositionMobs()),"CompositionMobs"))
            l.append(DummyItem(list(item.GetMasterMobs()),"MasterMobs"))
            l.append(DummyItem(list(item.GetSourceMobs()),"SourceMobs"))
            
            self.extendChildItems(l)
            
        elif isinstance(item, pyaaf.AxDictionary):
            l = []
            l.append(DummyItem(list(item.GetClassDefs()), 'ClassDefs'))
            l.append(DummyItem(list(item.GetCodecDefs()), 'CodecDefs'))
            l.append(DummyItem(list(item.GetContainerDefs()), 'ContainerDefs'))
            l.append(DummyItem(list(item.GetDataDefs()), 'DataDefs'))
            l.append(DummyItem(list(item.GetInterpolationDefs()), 'InterpolationDefs'))
            l.append(DummyItem(list(item.GetKLVDataDefs()), 'KLVDataDefs'))
            l.append(DummyItem(list(item.GetOperationDefs()), 'OperationDefs'))
            l.append(DummyItem(list(item.GetParameterDefs()), 'ParameterDefs'))
            l.append(DummyItem(list(item.GetPluginDefs()), 'PluginDefs'))
            l.append(DummyItem(list(item.GetTaggedValueDefs()), 'TaggedValueDefs'))
            l.append(DummyItem(list(item.GetTypeDefs()), 'TypeDefs'))
            self.extendChildItems(l)
            
        elif isinstance(item, (pyaaf.AxDefObject,pyaaf.AxMetaDefinition)):
            pass
                                   
        elif isinstance(item, pyaaf.AxMob):
            
            self.extendChildItems(list(item.GetSlots()))

        elif isinstance(item, pyaaf.AxMobSlot):
            self.extendChildItems([item.GetSegment()])
        elif isinstance(item, pyaaf.AxNestedScope):
            self.extendChildItems(list(item.GetSegments()))
            
        elif isinstance(item, pyaaf.AxSequence):
            self.extendChildItems(list(item.GetComponents()))
            
        elif isinstance(item, pyaaf.AxSourceClip):
            pass
            #self.extendChildItems([item.ResolveRef().GetName()])
            #self.extendChildItems([item.GetSourceID()])
        elif isinstance(item, pyaaf.AxTransition):
            self.extendChildItems([item.GetOperationGroup()])
            
        elif isinstance(item,pyaaf.AxOperationGroup):
            input_segments = []
            for i in xrange(item.CountSourceSegments()):
                segment = item.GetInputSegmentAt(i)
                input_segments.append(segment)
            self.extendChildItems(input_segments)
            
        elif isinstance(item, pyaaf.AxSelector):
            self.extendChildItems(list(item.EnumAlternateSegments()))
            
        elif isinstance(item, pyaaf.AxScopeReference):
            #print item, item.GetRelativeScope(),item.GetRelativeSlot()
            pass
        
        elif isinstance(item, pyaaf.AxEssenceGroup):
            segments = []
            
            for i in xrange(item.CountChoices()):
                choice = item.GetChoiceAt(i)
                segments.append(choice)
            self.extendChildItems(segments)
            
        elif isinstance(item, pyaaf.AxProperty):
            self.properties['Value'] = str(item.GetValue())
            
        elif isinstance(item, pyaaf.AxComponent):
            pass

        else:
            self.properties['Name'] = str(item)
            self.properties['ClassName'] = str(type(item))
            return
        
        self.properties['Name'] = self.name()
        self.properties['ClassName'] = self.className()
        
        
        if isinstance(item, pyaaf.AxComponent):
            try:
                self.properties['Length'] = item.GetLength()
            except:
                pass
                #print item
            
        self.loaded = True
    
class AAFModel(QtCore.QAbstractItemModel):

    def __init__(self, moblist,parent=None):
        super(AAFModel,self).__init__(parent)
        
        self.rootItem = TreeItem(moblist)
        
        self.headers = ['Name','Length', 'ClassName']
        
    def headerData(self, column, orientation,role):
        if orientation == QtCore.Qt.Horizontal and role == QtCore.Qt.DisplayRole:
            return QtCore.QVariant(self.headers[column])
        return QtCore.QVariant()

    def columnCount(self,index):
        #item = self.getItem(index)
        
        return len(self.headers)
    
    def rowCount(self,parent=QtCore.QModelIndex()):
        parentItem = self.getItem(parent)
        return parentItem.childCount()
    
    def data(self, index, role):
        
        if not index.isValid():
            return 0
        
        if role != QtCore.Qt.DisplayRole:
            return None
        
        item = self.getItem(index)
        
        header_key = self.headers[index.column()]
        
        return str(item.properties.get(header_key,''))
    
    def parent(self, index):
        
        if not index.isValid():
            return QtCore.QModelIndex()
        
        childItem = self.getItem(index)
        parentItem = childItem.parent()
        
        if parentItem == self.rootItem:
            return QtCore.QModelIndex()
        
        return self.createIndex(parentItem.childNumber(), 0, parentItem)
    
    def index(self, row, column, parent = QtCore.QModelIndex()):
        if parent.isValid() and parent.column() != 0:
            return QtCore.QModelIndex()
        
        item = self.getItem(parent)
        childItem = item.child(row)
        
        if childItem:
            return self.createIndex(row, column, childItem)
        else:
            return QtCore.QModelIndex()
        

    def getItem(self,index):
        
        if index.isValid():
            item = index.internalPointer()
            if item:
                return item
        return self.rootItem
        

if __name__ == "__main__":
    
    from PyQt4 import QtGui
        
    from optparse import OptionParser
    
    parser = OptionParser()
    parser.add_option('-c','--compmobs',action="store_true", default=False)
    parser.add_option('-m','--mastermobs',action="store_true", default=False)
    parser.add_option('-s','--sourcemobs',action="store_true", default=False)
    parser.add_option('-d','--dictionary',action="store_true", default=False)
    parser.add_option('-a','--all',action="store_true", default=False)

    
    
    (options, args) = parser.parse_args()
    
    if not args:
        parser.error("not enough arguments")
        
    file_path = args[0]
    
    with pyaaf.open(file_path) as axfile:
        
        #root = axfile
        header = axfile.GetHeader()
        storage = header.GetContentStorage()
        
        root = storage
        if options.compmobs:
            root = list(storage.GetCompositionMobs())
            
        if options.mastermobs:
            root = list(storage.GetMasterMobs())
            
        if options.sourcemobs:
            root = list(storage.GetSourceMobs())
            
        if options.dictionary:
            root = header.GetDictionary()
            
        if options.all:
            root = axfile
        #print mobs
    
        app = QtGui.QApplication(sys.argv)
        
        model = AAFModel(root)
        
        tree = QtGui.QTreeView()
        
        tree.setModel(model)
        
        tree.resize(700,600)
        #tree.expandToDepth(3)
        tree.resizeColumnToContents(0)
        tree.show()
        
        sys.exit(app.exec_())