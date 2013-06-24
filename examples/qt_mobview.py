import sys
import traceback

from PyQt4 import QtGui
from PyQt4 import QtCore
from PyQt4.QtCore import Qt

import pyaaf

from qt_aafmodel import AAFModel



class AAFTimeline(QtGui.QGraphicsScene):
    
    def setMob(self,mob):
        
        self.clear()
        sequences = []
        
        for slot in mob.GetSlots():
            if isinstance(slot, (pyaaf.AxTimelineMobSlot)):
                segment = slot.GetSegment()
                
                if isinstance(segment, pyaaf.AxSequence):
                    sequences.append(segment)
                
                elif isinstance(segment, pyaaf.AxNestedScope):
                    for seq in segment.GetSegments():
                        if isinstance(seq, pyaaf.AxSequence):
                            sequences.append(seq)
        height = 25 
        timelineLength = 0       
        for i, seq in enumerate(reversed(sequences)):
            length = seq.GetLength()
            
            timelineLength = max(timelineLength,length)
            print seq
            
            offset = i * height
            
            pen = QtGui.QPen(Qt.black)
            pen.setWidth(0)
            brush = QtGui.QBrush(Qt.NoBrush)
            
            timeline = self.addRect(QtCore.QRectF(0,0, length,height),pen,brush)
            timeline.moveBy(0,offset)
            
            
            if isinstance(seq, pyaaf.AxSequence):
                x_pos = 0
                for component in seq.GetComponents():
                    component_length = component.GetLength()
                    brush.setStyle(Qt.SolidPattern)
                    if isinstance(component, (pyaaf.AxFiller,pyaaf.AxScopeReference)):
                        
                        brush.setColor(Qt.gray)
                    else:
                        brush.setColor(Qt.red)
                        
                    
                    if isinstance(component,pyaaf.AxTransition):
                        x_pos -= component_length
                    else:

                    
                        clip = self.addRect(QtCore.QRectF(0,0, component_length,height),pen,brush)
                        clip.moveBy(x_pos,offset)
                    
                        x_pos += component_length
                                        
                                        
            
            
        self.setSceneRect(QtCore.QRectF(-20,-20, timelineLength+20, height*len(sequences) + 20 ))
        

        
        
    def setMobFromModelIndex(self,index):
        
        treeItem = index.internalPointer()
        if isinstance(treeItem.item, pyaaf.AxMob):
            self.setMob(treeItem.item)







if __name__ == "__main__":
    
   
        
    
    from optparse import OptionParser
    
    parser = OptionParser()
    (options, args) = parser.parse_args()
    
    if not args:
        parser.error("not enough arguments")
        
    file_path = args[0]
    
    with pyaaf.open(file_path) as axfile:
        
        app = QtGui.QApplication(sys.argv)

        window = QtGui.QSplitter()
        
        #layout = QtGui.QHBoxLayout()
        
        header = axfile.GetHeader()
        storage = header.GetContentStorage()
        
        model = AAFModel(storage)
        
        timeline = AAFTimeline()
        
        tree = QtGui.QTreeView()
        tree.setModel(model)
        tree.resize(650,600)
        tree.expandToDepth(0)
        tree.resizeColumnToContents(0)
        
        
        
        graphicsview = QtGui.QGraphicsView()
        graphicsview.resize(400,600)
        graphicsview.setScene(timeline)
        def loadMob( index,grahicsview):
            scene = grahicsview.scene()
            scene.setMobFromModelIndex(index)
            grahicsview.fitInView(scene.sceneRect())
            
        tree.doubleClicked.connect(lambda x,y=graphicsview: loadMob(x,y))
        
        window.addWidget(tree)
        window.addWidget(graphicsview)
        
        window.resize(900,600)
        
        #window.setLayout(layout)
        
        window.show()
        
        sys.exit(app.exec_())
        
        