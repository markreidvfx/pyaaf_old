import sys
import traceback

from PyQt4 import QtGui
from PyQt4 import QtCore
from PyQt4.QtCore import Qt

import pyaaf

from qt_aafmodel import AAFModel

class GraphicsClip(QtGui.QGraphicsRectItem):
    
    def __init__(self,length, parent=None):
        super(GraphicsClip,self).__init__(parent)
        
        self.length = length
        
        self.track = None
        self.left = None
        self.right = None
        self.name = None
        
        self.setFlag(QtGui.QGraphicsItem.ItemIsSelectable,True)
        
        
    def adjust(self):
        
        height = self.track.height
        
        self.setRect(QtCore.QRectF(0,0, self.length, height))
    
        y = self.track.y()
        x = 0
        
        if self.left:
            x = self.left.x() + self.left.length
        self.setPos(x,y)
        
    def paint(self,p,opt,w):
        
        super(GraphicsClip,self).paint(p,opt,w)
        
        if self.name:
            p.save()
            nameRect = QtCore.QRectF(self.rect())
            p.drawText(nameRect,Qt.AlignLeft,self.name)
            p.restore()
        
        


class GraphicsTrack(QtGui.QGraphicsItemGroup):
    
    def __init__(self,parent=None):
        
        super(GraphicsTrack,self).__init__(parent)
        
        self.height = 15
        self.length = 0
        self.name = "Track"
        
        self.timeline = None
        
        self.parent = None
        
        self.clips = []
        
        self.trackItem = QtGui.QGraphicsRectItem()
        
        self.addToGroup(self.trackItem)
        
        #scene.addItem(trackLabel)
        #self.addToGroup(self.trackLabel)
    def addClip(self,length):
        
        clip = GraphicsClip(length)
        clip.track = self
        
        if self.clips:
            
            prev_clip = self.clips[-1]
            prev_clip.right = clip
            
            clip.left = prev_clip
        
        scene = self.scene()
        scene.addItem(clip)
        
        self.clips.append(clip)
        
        clip.adjust()
        
        self.length += length
        self.adjust()
        
        return clip
            
        
        
    def adjust(self):
        
        
        track = self.trackItem
        
        track.setRect(QtCore.QRectF(0,0,self.length,self.height))
        
        spacing = self.timeline.track_spacing
        
        
        if self.parent:
            
            #r = self.parent.boundingRect()
            y = self.parent.y()
            self.setY(y - self.parent.height - spacing)
        



class AAFTimeline(QtGui.QGraphicsScene):
    
    def __init__(self,parent=None):
        
        super(AAFTimeline,self).__init__(parent)
        
        self.tracks = []
        self.track_spacing = 2
    
    def addTrack(self):
        
        track = GraphicsTrack()
        track.timeline = self
        if self.tracks:
            track.parent = self.tracks[-1]
        
            track.adjust()
        self.tracks.append(track)
        self.addItem(track)
        return track
    
    def clear(self):
        
        super(AAFTimeline,self).clear()
        
        self.tracks = []
        
        
              

    
class AAFTimelineGraphicsView(QtGui.QGraphicsView):
    
    def __init__(self,parent=None):
        
        super(AAFTimelineGraphicsView,self).__init__(parent)
        self.setViewportUpdateMode(QtGui.QGraphicsView.FullViewportUpdate)
        
        self.marginWidth = 90
        
        self.setViewportMargins(self.marginWidth, 0, 0, 0)
        
        self.trackWidgets = []

    def drawBackground(self,painter,rect):
        
        super(AAFTimelineGraphicsView,self).drawForeground(painter,rect)

        #print rect.left()
    def updateTrackLabels(self,offset=0):
        scene = self.scene()
        edge = self.mapToScene(0,0)
        
        for track in self.trackWidgets:
            track.hide()

        for i, track in enumerate(scene.tracks):
            #track.trackLabel.setX(max(0,edge.x() + offset))
            
            
            trackItem = track.trackItem
            rect = trackItem.rect()
            pos = track.pos()
            widget_pos = self.mapFromScene(pos)
            
            spacing = track.timeline.track_spacing
            
            topLeft = rect.topLeft() + QtCore.QPointF(0,spacing)
            
            
            
            widget_height =  self.mapFromScene(rect.bottomLeft()).y() - self.mapFromScene(rect.topLeft()).y()
            
            if i+1 > len(self.trackWidgets):
                l = QtGui.QLabel(self)
                l.setFrameStyle(QtGui.QFrame.Panel)
                self.trackWidgets.append(l)
                
            label = self.trackWidgets[i]
            
            label.show()
            label.move(0,widget_pos.y())
            
            label.setText(track.name)

            label.setFixedWidth(self.marginWidth)
            label.setFixedHeight(widget_height)
            
            
            

    def paintEvent(self, event):
        #self.updateTrackLabels()
        result = super(AAFTimelineGraphicsView,self).paintEvent(event)
        self.updateTrackLabels()
        
        
        

    def wheelEvent(self, event):
        
        self.setTransformationAnchor(QtGui.QGraphicsView.AnchorUnderMouse)
        scaleFactor = 1.15
        
        if event.delta() > 0:
            self.scale(scaleFactor, scaleFactor)
        else:
            self.scale(1.0 / scaleFactor, 1.0 / scaleFactor)

    def keyPressEvent(self, event):
        
        if event.key() == Qt.Key_F:
            scene = self.scene()
            if scene:
                mode=Qt.KeepAspectRatio
                if event.modifiers() == Qt.ShiftModifier:
                    mode = Qt.IgnoreAspectRatio           
                self.fitInView(scene.sceneRect(),mode=mode)
                
        else:
            super(AAFTimelineGraphicsView,self).keyPressEvent(event)
            


def AddMobFromIndex(index,grahicsview):
    treeItem = index.internalPointer()
    mob = treeItem.item
    if isinstance(mob, pyaaf.AxMob):
        SetMob(mob,grahicsview)
        

def SetMob(mob,grahicsview):

    scene = grahicsview.scene()
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
                        
            elif isinstance(segment, pyaaf.AxSourceClip):
                sequences.append(segment)
    scene.clear()
    i = 0   
    for seq in sequences:
        
        track = scene.addTrack()
        track.name = "Track %i" % i
        
        i += 1
        
        if isinstance(seq, pyaaf.AxSequence):
            components = list(seq.GetComponents())
            
        else:
            components = [seq]
        
        
            
        last_transition = 0
        for component in components:
            component_length = component.GetLength() -last_transition
            
            if isinstance(component,pyaaf.AxTransition):
                last_transition = component_length
                #clip = track.addClip(component_length)
                #clip.setBrush(Qt.blue)
            else:
            
                clip = track.addClip(component_length)
                if isinstance(component,(pyaaf.AxFiller,pyaaf.AxScopeReference)):
                    
                    clip.setBrush(Qt.gray)
                #elif isinstance(component, pyaaf.AxScopeReference):
                    #clip.setBrush(Qt.gray)
                else:
                    clip.setBrush(Qt.red)
                    
                name = None 
                if isinstance(component, pyaaf.AxSourceClip):
                    try:
                        ref = component.ResolveRef()
                        name = ref.GetName()
                    except:
                        pass
                    
                elif isinstance(component, pyaaf.AxOperationGroup):
                    name = component.GetOperationDef().GetName()
                
                if name:
                    clip.name = name
                    clip.adjust()
                    
                last_transition = 0
        
            #clip.adjust()







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
        
        topLevelMobs = list(storage.GetTopLevelMobs())

        model = AAFModel(storage)
        
        timeline = AAFTimeline()
        
        tree = QtGui.QTreeView()
        tree.setModel(model)
        tree.resize(650,600)
        tree.expandToDepth(0)
        tree.resizeColumnToContents(0)
        
        
        
        graphicsview = AAFTimelineGraphicsView()
        graphicsview.resize(400,600)
        graphicsview.setScene(timeline)

        tree.doubleClicked.connect(lambda x,y=graphicsview: AddMobFromIndex(x,y))
        
        if topLevelMobs:
            SetMob(topLevelMobs[0],graphicsview)
        window.addWidget(tree)
        window.addWidget(graphicsview)
        
        window.resize(900,600)
        
        #window.setLayout(layout)
        
        window.show()
        #graphicsview.show()
        
        sys.exit(app.exec_())
        
        