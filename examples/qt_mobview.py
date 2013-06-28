import sys
import traceback

from PyQt4 import QtGui
from PyQt4 import QtCore
from PyQt4.QtCore import Qt

import pyaaf

from qt_aafmodel import AAFModel

class GraphicsTimeSlider(QtGui.QGraphicsRectItem):
    
    
    def __init__(self,parent=None):
        super(GraphicsTimeSlider,self).__init__(parent)
        
        #self.setFlag(QtGui.QGraphicsItem.ItemIsSelectable,True)
        
        self.height = 100
        self.edge_spacing = 10
        
        pen = QtGui.QPen()
        pen.setBrush(Qt.blue)
        self.setPen(pen)
        self.setBrush(Qt.blue)
        self.frame = 0
        self.setZValue(100)
        self.setPos(0,0)
        
        
    def setHeight(self,value):
        self.height = value
        
        self.adjust()
        
    def setFrame(self,value):
        
        self.frame = int(value)
        self.adjust()
        
        print "frame =", self.frame
    def getFrame(self):
        return self.frame
        
    def adjust(self):
        
        rect = QtCore.QRectF(0,0,1,self.height)
        
        rect.adjust(0,-self.edge_spacing,0,self.edge_spacing)
        self.setRect(rect)
        self.setPos(self.frame, 0)

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
        
        


class GraphicsTrack(QtGui.QGraphicsRectItem):
    
    def __init__(self,parent=None):
        
        super(GraphicsTrack,self).__init__(parent)
        
        self.height = 20
        self.length = 0
        self.name = "Track"
        
        self.timeline = None
        
        self.parent = None
        
        self.clips = []
        
        

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
        self.setRect(QtCore.QRectF(0,0,self.length,self.height))
        
        spacing = self.timeline.track_spacing
        
        
        if self.parent:
            y = self.parent.y()
            self.setY(y + self.parent.height + spacing)
            
class AAFTimeline(QtGui.QGraphicsScene):
    
    def __init__(self,parent=None):
        
        super(AAFTimeline,self).__init__(parent)
        
        self.tracks = []
        self.track_spacing = 10
        self.edge_spacing = 50
        self.timeSlider = None
        
        self.timeSliderDrag = False
    
    def addTrack(self):
        
        track = GraphicsTrack()
        track.timeline = self
        if self.tracks:
            track.parent = self.tracks[-1]
        
            track.adjust()
        self.tracks.append(track)
        self.addItem(track)
        
        self.updateSceneRect()
        return track
    
    def updateSceneRect(self):
        
        rect = QtCore.QRectF()
        for track in self.tracks:
            rect = rect.united(track.sceneBoundingRect())

        height = rect.height()
        rect.adjust(0,-self.edge_spacing,0,self.edge_spacing)
        self.setSceneRect(rect)
        
        self.timeSlider.edge_spacing = self.edge_spacing
        self.timeSlider.setHeight(height)
        
    def setFrame(self,value):
        self.timeSlider.setFrame(value)
        
    def getFrame(self):
        return self.timeSlider.getFrame()
        
    def mousePressEvent(self,event):
        
        pos = event.scenePos()
        print pos
        if not self.itemAt(event.scenePos()):
            self.setFrame(pos.x())
            self.timeSliderDrag = True
            event.accept()
        else:
            super(AAFTimeline,self).mousePressEvent(event)
            
    def mouseMoveEvent(self, event):
        super(AAFTimeline,self).mouseMoveEvent(event)
        
        if self.timeSliderDrag:
            pos = event.scenePos()
            self.setFrame(pos.x())
            
    def mouseReleaseEvent(self,event):
        if self.timeSliderDrag:
            self.timeSliderDrag = False
        
        super(AAFTimeline,self).mouseReleaseEvent(event)

        
    
    def clear(self):
        
        super(AAFTimeline,self).clear()
        
        self.tracks = []
        
        self.timeSlider = GraphicsTimeSlider()
        self.timeSlider.edge_space = self.edge_spacing
        self.timeSlider.setPos(0,0)
        
        self.addItem(self.timeSlider)
        
              
class TimeLineWidget(QtGui.QWidget):
    
    def __init__(self,parent):
        
        super(TimeLineWidget,self).__init__(parent)
        
        self.start = 0
        self.end = 0
        self.scale = 1
    
    def paintEvent(self, event):
        super(TimeLineWidget,self).paintEvent(event)
        
        width = self.width()
        
        end = (width / self.scale) + self.start
        #print self.scale,self.width(),self.start,'-', end
        
        painter =QtGui.QPainter()
        painter.begin(self)
        #painter.setBrush(Qt.black)
        
        rect = self.rect()
        rect.adjust(0,0,0,-2)
        
        painter.drawRect(rect)

        #step = 1 * self.scale
        length = end - self.start
        step = 1
        while width / length * step < 10:
            step += 1
        
        for i in xrange(int(self.start), int(end), step):
            x = (i-self.start)  * self.scale
            
            height_ratio = .5
            
            if i% 12 == 0:
                height_ratio = .25
            
            painter.drawLine(x, self.height() * height_ratio, x, self.height()-4)
        
        #while True:
            
            
        
       # print width * self.scale,  self.end

        painter.end()
        
        
class AAFTimelineGraphicsView(QtGui.QGraphicsView):
    
    def __init__(self,parent=None):
        
        super(AAFTimelineGraphicsView,self).__init__(parent)
        #self.setViewportUpdateMode(QtGui.QGraphicsView.FullViewportUpdate)
        
        self.marginWidth = 90
        self.topMaginHeight = 20
        
        self.setViewportMargins(self.marginWidth, self.topMaginHeight, 0, 0)
        
        self.timelineWidget = TimeLineWidget(self)
        
        self.trackWidgets = []
                

    def updateTrackLabels(self,offset=0):
        scene = self.scene()
        edge = self.mapToScene(0,0)
        
        for track in self.trackWidgets:
            track.hide()

        for i, track in enumerate(scene.tracks):
            rect = track.rect()
            pos = track.pos()
            widget_pos = self.mapFromScene(pos)
            widget_height =  self.mapFromScene(rect.bottomLeft()).y() - self.mapFromScene(rect.topLeft()).y()
            
            if i+1 > len(self.trackWidgets):
                l = QtGui.QLabel(self)
                l.setFrameStyle(QtGui.QFrame.Panel)
                self.trackWidgets.append(l)
                
            label = self.trackWidgets[i]
            
            label.show()
            label.move(0,widget_pos.y() + self.topMaginHeight)
            
            label.setText(track.name)

            label.setFixedWidth(self.marginWidth)
            label.setFixedHeight(widget_height + 2)
            
    def updateTimeLine(self):
        
        t = self.timelineWidget
        
        t.move(QtCore.QPoint(self.marginWidth,0))
        
        t.setFixedWidth(self.viewport().width())
        t.setFixedHeight(self.topMaginHeight)
        
        
        scene = self.scene()
        if scene:
            t.scale = self.transform().m11()
            #print t.scale
            
            t.start = self.mapToScene(0,0).x()
            
            #t.end = self.mapToScene(self.width() - self.m, self.topMaginHeight).x()
            t.repaint()
        

    def paintEvent(self, event):
        #self.updateTrackLabels()
        result = super(AAFTimelineGraphicsView,self).paintEvent(event)
        self.updateTrackLabels()
        self.updateTimeLine()

    def wheelEvent(self, event):
        
        self.setTransformationAnchor(QtGui.QGraphicsView.AnchorUnderMouse)
        scaleFactor = 1.15
        
        if event.delta() > 0:
            self.scale(scaleFactor, scaleFactor)
        else:
            self.scale(1.0 / scaleFactor, 1.0 / scaleFactor)

    def keyPressEvent(self, event):
        
        scene = self.scene()
        
        if scene:
            if event.key() == Qt.Key_F:
                mode=Qt.KeepAspectRatio
                if event.modifiers() == Qt.ShiftModifier:
                    mode = Qt.IgnoreAspectRatio           
                self.fitInView(scene.sceneRect(),mode=mode)
                
            elif event.key() == Qt.Key_Right:
                
                frame = scene.getFrame()
                scene.setFrame(frame + 1)
            
            elif event.key() == Qt.Key_Left:
                
                frame = scene.getFrame()
                scene.setFrame(frame - 1)
                
            else:
                super(AAFTimelineGraphicsView,self).keyPressEvent(event)
                

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
    for i, seq in reversed(list(enumerate(sequences))):
        
        track = scene.addTrack()
        track.name = "Track %i" % i
        
        
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
        
        