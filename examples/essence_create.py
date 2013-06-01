import pyaaf
import os
from pyaaf import Ax

def chunks(l, n):
    """ Yield successive n-sized chunks from l.
    """
    for i in xrange(0, len(l), n):
        yield l[i:i+n]
        
def AddImageEssence(masterMob, axHeader):
    axContentStorage = Ax(axHeader.GetContentStorage())
    axDictionary = Ax(axHeader.GetDictionary())
    
    axPictureDef = pyaaf.AxDataDef(axDictionary.LookupDataDef(pyaaf.DataDef.Picture))
    
    codec = pyaaf.CodecDef.JPEG
    
    editRate = pyaaf.Rate(25,1)
    sampleRate = pyaaf.Rate(25,1)
    
    nullLocator = pyaaf.smartpointers.IAAFLocatorSP()
    
    
    axEssenceAccess = Ax(masterMob.CreateEssence(1,
                                                axPictureDef,
                                                codec,
                                                editRate,
                                                sampleRate,
                                                pyaaf.aafCompressEnable_e.kAAFCompressionEnable,
                                                nullLocator,
                                                pyaaf.ContainerDef.ContainerAAF
                                                ))
    
    axMobSlot = list(Ax(masterMob.GetSlots()))[0]
    
    axSourceClip = Ax(axMobSlot.GetSegment())
    
    sourceMob = Ax(axContentStorage.LookupMob(axSourceClip.GetSourceID()))
    
    cdciDesc = Ax(sourceMob.GetEssenceDescriptor())
    
    #loads of parameters to set...
    rect = pyaaf.aafRect_t()
    rect.xOffset = 0
    rect.yOffset = 0
    rect.xSize = 720
    rect.ySize = 576
    
    startScanLine = [0,1]
    
    layout = pyaaf.aafFrameLayout_e.kAAFMixedFields
    componentWidth = 8
    horizontalSubsampling = 2
    verticalSubsampling = 1
    colorRange = 255
    
    #CDCIDescriptor also implements DigitalImageDescriptor.  Here are some
    #parameters that DigitalImageDescriptor inherits from CDCI descriptor.
    
    cdciDesc.SetStoredView(rect.ySize, rect.xSize )
    cdciDesc.SetSampledView(rect.ySize, rect.xSize, rect.xOffset, rect.yOffset )
    cdciDesc.SetDisplayView(rect.ySize, rect.xSize, rect.xOffset, rect.yOffset )
    cdciDesc.SetFrameLayout(layout )
    cdciDesc.SetVideoLineMap( startScanLine )

    #CDCIDescriptor parameters.
    cdciDesc.SetComponentWidth( componentWidth )
    cdciDesc.SetHorizontalSubsampling( horizontalSubsampling )
    cdciDesc.SetVerticalSubsampling( verticalSubsampling )
    cdciDesc.SetColorRange( colorRange )
    
    #EssenceDescriptor parameters.
    #Nothing to do here.  We could add additional locators if necessary.

    #Now, set the same set of essence format specifiers.  We are "talking"
    #to the codec at this point.
    
    axEssenceFormat = pyaaf.AxEssenceFormat(axEssenceAccess.GetEmptyFileFormat())
    
    #Minimal "known good" set of format specifiers.
    axEssenceFormat.AddFormatSpecifier( pyaaf.EssenceFormatDef.StoredRect, rect)
    axEssenceFormat.AddFormatSpecifier( pyaaf.EssenceFormatDef.CDCIHorizSubsampling, horizontalSubsampling )
    colorSpace = pyaaf.aafColorSpace_e.kAAFColorSpaceYUV
    axEssenceFormat.AddFormatSpecifier( pyaaf.EssenceFormatDef.PixelFormat, colorSpace )
    
    #That's it for the format specifiers...                                            
    axEssenceAccess.PutFileFormat( axEssenceFormat );

    #With the essence descriptor, and format specifier, parameters set, we can
    #now write some data.
    
    numSamples = 1 #frames NOTE pyaaf.CodecDef.JPEG can only write 1 sample at a time
    
    numBytes = numSamples * rect.xSize * rect.ySize * 2 #number of bytes in a frame
     
    # Load pixels buffer with meaning full data here.
    # probable could use PIL to get a buffer...
    
    #write 2 frames
    for i in range(2):
        print masterMob.GetName(), 'writing video frame bytes:',numBytes
        result = axEssenceAccess.WriteSamples_UInt8(numSamples, [1 for x in range(numBytes)])
        
        if result.samplesWritten != numSamples:
            print ""
            raise Exception("Image WriteSamples size mismatch") 
    
        
    axEssenceAccess.CompleteWrite()
        
                                                
                                                
def AddAudioEssence(masterMob, axHeader):
    
    axContentStorage = Ax(axHeader.GetContentStorage())
    axDictionary = Ax(axHeader.GetDictionary())
    axSoundDef = Ax(axDictionary.LookupDataDef(pyaaf.DataDef.Sound))
    
    rateHz = 44100
    editRate = pyaaf.Rate(rateHz,1)
    sampleRate = pyaaf.Rate(rateHz, 1)
    
    #We will use ContainerAAF, hence no locator is required.
    nullLocator = pyaaf.smartpointers.IAAFLocatorSP()
    
    axEssenceAccess = Ax(masterMob.CreateEssence(1,
                                                axSoundDef, 
                                                pyaaf.CodecDef.WAVE,
                                                editRate,
                                                sampleRate,
                                                pyaaf.aafCompressEnable_e.kAAFCompressionDisable,
                                                nullLocator,
                                                pyaaf.ContainerDef.ContainerAAF
                                                ))
     
    axMobSlot = list(Ax(masterMob.GetSlots()))[0]

    # The AxMobSlot::GetSegment() method will return a segment interface.  We know
    # that this is really a source clip, so cast to source clip.
 
    axSourceClip = Ax(axMobSlot.GetSegment())

    sourceMob = Ax(axContentStorage.LookupMob(axSourceClip.GetSourceID()))
    
    #Get the essence descriptor, and cast to the WAVEDescriptor.
    
    wavDesc = Ax(sourceMob.GetEssenceDescriptor())
    
    # At this point, one must call wavDesc.SetSummary( size, pBuf ). A file
    # dump indicates this is a UInt8[36].  This is the header information
    # from the wave audio file.  It contains information such as sample
    # rate, sample size, etc.
     
    # Next, set the format specifiers.  The parameters that must be set
    # are codec dependent.  The values are obtained from the WaveDescriptor
    # Experience has shown that this is the only parameter that *must* be
    # set.
    
    axEssenceFormat = pyaaf.AxEssenceFormat(axEssenceAccess.GetEmptyFileFormat())
    
    sampleSize = 16

    axEssenceFormat.AddFormatSpecifier(pyaaf.EssenceFormatDef.AudioSampleBits,16)
    axEssenceAccess.PutFileFormat( axEssenceFormat )
    
    numSamples = 2 * rateHz / 25 # 2 pal frames in duration.
    samplesToWrite = 100
    
    # At this point one should write meaningful data into the
    # sample buffer.

    print masterMob.GetName(),'writing audio samples:',numSamples
    
    for c in chunks([1 for i in xrange(numSamples)], samplesToWrite):

        result = axEssenceAccess.WriteSamples_UInt16(len(c), c)

        if result.samplesWritten != len(c):
            print ""
            raise Exception("Audio WriteSamples size mismatch")
        
        print ".",
    
    print ""
    axEssenceAccess.CompleteWrite()
         
     
def essence_create():
    dirname = os.path.dirname(__file__)
    fileName = os.path.join(dirname,"essence_create.aaf")
    xmlfile = os.path.join(dirname,"essence_create.xml")

    axFile = pyaaf.AxFile()
    axFile.OpenNewModify( fileName )
    
    #get header dictionary and content storage
    axHeader = Ax(axFile.GetHeader())
    axDictionary = Ax(axHeader.GetDictionary())
    axContentStorage = Ax(axHeader.GetContentStorage())

    #create some master mob
    
    master_mobs = {}
    for name in ("Audio Mob A", "Audio Mob B", "Video Mob A","Video Mob B"):
    
        mob = pyaaf.AxMasterMob.CreateInstance(axDictionary)
        mob.Initialize()
        mob.SetName(name)
        
        #add master mob to file
        axHeader.AddMob(mob)
        master_mobs[name] = mob
        
    
    for name in ("Audio Mob A", "Audio Mob B"):
        AddAudioEssence(master_mobs[name], axHeader)
        master_mobs[name].AppendComment("Essence Comment", "Audio essence attached.")

    for name in ("Video Mob A","Video Mob B"):
        AddImageEssence(master_mobs[name], axHeader)
        master_mobs[name].AppendComment("Essence Comment", "Video essence attached.")
    
    
    
    axFile.Save()
    axFile.toXml(xmlfile)
    axFile.Close()
    
if __name__ == "__main__":
    essence_create()