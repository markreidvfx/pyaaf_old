
import os
import pyaaf
import essence_create



def CreateSourceClipToAppendToSequence(axDictionary, sourceMob,sequenceToAppendTo):

    # Search for the first slot in the source mob that matches the
    # data def of the sequenceToAppendTo.
    
    sequenceDataDef = sequenceToAppendTo.GetDataDef()
    sequenceDataDefAUID = sequenceDataDef.GetAUID()    
        
    spSourceSlot = None
    for axTimelineMobSlot in sourceMob.GetSlots():

        axDataDef = pyaaf.AxDataDef(axTimelineMobSlot.GetDataDef())
        
        #Does it match the sequence's data def
        if str(axDataDef.GetAUID()) == str(sequenceDataDefAUID):
            spSourceSlot = axTimelineMobSlot
            break
        
    if spSourceSlot is None:
        raise Exception("Failed to find matching data definition.") 

    # Create a source clip refering to the slot that we just
    # found, and append it to the sequence.

    # Here we assume that we always want to refer to the start of
    # the essence, hence the startTime is the sourceSlot origin.

    sourceRef = pyaaf.aafSourceRef_t()
    
    sourceRef.sourceID = sourceMob.GetMobID()
    sourceRef.sourceSlotID = spSourceSlot.GetSlotID()
    sourceRef.startTime =  spSourceSlot.GetOrigin()
    
    axSegment = spSourceSlot.GetSegment()
    
    axSourceClip = pyaaf.AxSourceClip.CreateInstance(axDictionary)
    
    axSourceClip.Initialize( sequenceDataDef, axSegment.GetLength(), sourceRef )
    
    return axSourceClip


def comp_create():
    
    dirname = os.path.dirname(__file__)
    fileName = os.path.join(dirname,"essence_create.aaf")
    comp_fileName = os.path.join(dirname,"comp_create.aaf")
    xmlfile = os.path.join(dirname,"comp_create.xml")
    #pyaaf.AxInit() # don't need to do this its done in essence_create
    
    axFile = pyaaf.AxFile()
    axFile.OpenExistingModify( fileName )
    
    #get header dictionary and content storage
    axHeader = axFile.GetHeader()
    axDictionary = axHeader.GetDictionary()
    axContentStorage = axHeader.GetContentStorage()

    #get master mobs
    master_mobs = {}
    for mastermob in axContentStorage.GetMasterMobs():
        
        name = mastermob.GetName()
        master_mobs[name] = mastermob
        
    
    #create composition mob
    compMob = pyaaf.AxCompositionMob.CreateInstance(axDictionary)
    
    compMob.SetName("Example Composition")
    
    axHeader.AddMob(compMob)
    
    editRate = pyaaf.Rate(25,1)

    videoSlotID = 1
    videoSlotName = "Video Timeline"
    
    audioSlotID = 2
    audioSlotName = "Audio Timeline" 
    
    audioDataDef = axDictionary.LookupDataDef(pyaaf.DataDef.Sound)
    audioSequence = pyaaf.AxSequence.CreateInstance(axDictionary)
    audioSequence.Initialize(audioDataDef)
    
    videoDataDef = axDictionary.LookupDataDef(pyaaf.DataDef.Picture)
    videoSequence = pyaaf.AxSequence.CreateInstance(axDictionary)
    videoSequence.Initialize(videoDataDef)
    
    # Append one timeline slot per sequence to the composition mob.
    
    compMob.AppendNewTimelineSlot(editRate,
                                  videoSequence,
                                  videoSlotID,
                                  videoSlotName,
                                  0)
    
    compMob.AppendNewTimelineSlot(editRate,
                                  audioSequence,
                                  audioSlotID,
                                  audioSlotName,
                                  0)    
    
    
    # Create source clips and transitions.

    # First audio....
    
    axAudioClipA = CreateSourceClipToAppendToSequence(axDictionary, master_mobs["Audio Mob A"],audioSequence)
    axAudioClipB = CreateSourceClipToAppendToSequence(axDictionary, master_mobs["Audio Mob B"],audioSequence)
    
    
    # If the operation definition is not in the dictionary already, then it is
    # the programmers job to create the operation definition, initialize it,
    # and register it.
    
    if not axDictionary.isKnownOperationDef(pyaaf.OperationDef.EffectMonoAudioDissolve):
        axOpDef = pyaaf.AxOperationDef.CreateInstance(axDictionary)
        axOpDef.Initialize(pyaaf.OperationDef.EffectMonoAudioDissolve,
                           "Example Mono Audio Dissolve",
                           "No timewarp, bypass track 0, 2 mono audio inputs")
        axOpDef.SetIsTimeWarp( False )
        
        #this will make toXml spit out a error: Invalid extendible enumeration value encountered still works...
        axOpDef.SetCategory( pyaaf.OperationDef.EffectMonoAudioDissolve ) 
        
        axOpDef.SetBypass( 0 )
        axOpDef.SetNumberInputs( 2 )
        axOpDef.SetDataDef( audioDataDef )
    
        axDictionary.RegisterOperationDef( axOpDef)
    
    
    MonoAudioDissolveDef = axDictionary.LookupOperationDef(pyaaf.OperationDef.EffectMonoAudioDissolve)
    axMonoAudioDslvOpGroup = pyaaf.AxOperationGroup.CreateInstance(axDictionary)
    
    
    #FIXME - Duration... that's in samples - right?
    #We will overlap the segment by 1 pal frame (at 44100 samples/sec).
    #FIXME - Assumed rate and duration of source material.
    axMonoAudioDslvOpGroup.Initialize(audioDataDef, 44100/25, MonoAudioDissolveDef)
    
    axMonoAudioDslvTransition = pyaaf.AxTransition.CreateInstance(axDictionary)
    axMonoAudioDslvTransition.Initialize( audioDataDef, 44100/25, 0, axMonoAudioDslvOpGroup )
    
    # Now video
    
    axVideoClipA = CreateSourceClipToAppendToSequence(axDictionary, master_mobs["Video Mob A"],videoSequence)
    axVideoClipB = CreateSourceClipToAppendToSequence(axDictionary, master_mobs["Video Mob B"],videoSequence)
    
    # Setup a video dissolve

    # If the operation definition is not in the dictionary already, then it is
    # the programmers job to create the operation definition, initialize it,
    # and register it.
    
    if not axDictionary.isKnownOperationDef(pyaaf.OperationDef.EffectVideoDissolve):

        axOpDef = pyaaf.AxOperationDef.CreateInstance(axDictionary)
        
        axOpDef.Initialize( pyaaf.OperationDef.EffectVideoDissolve,
                        "Example Video Dissolve",
                        "No timewarp, bypass track 0, 2 video inputs" )
        axOpDef.SetIsTimeWarp( False )
        
        #this will make toXml spit out a error: Invalid extendible enumeration value encountered still works...
        axOpDef.SetCategory( pyaaf.OperationDef.EffectVideoDissolve )
        
        axOpDef.SetBypass( 0 )
        axOpDef.SetNumberInputs( 2 )
        axOpDef.SetDataDef( audioDataDef )
        
        axDictionary.RegisterOperationDef( axOpDef )
        
    
    axVideoDslvOpDef = axDictionary.LookupOperationDef(pyaaf.OperationDef.EffectVideoDissolve)
    
    axVideoDslvOpGroup = pyaaf.AxOperationGroup.CreateInstance(axDictionary)
    
    #overlap by one frame.
    
    axVideoDslvOpGroup.Initialize( videoDataDef, 1, axVideoDslvOpDef );
    
    
    axVideoDslvTransition = pyaaf.AxTransition.CreateInstance(axDictionary)
    
    axVideoDslvTransition.Initialize(videoDataDef,1,0,axVideoDslvOpGroup)
    
    # Append the series of components to the sequences to form each
    # track.  The components order is:
    # [first segment of essence] [transition] [second segment of essence]
    
    audioSequence.AppendComponent(axAudioClipA)
    audioSequence.AppendComponent(axMonoAudioDslvTransition)
    audioSequence.AppendComponent(axAudioClipB)
    
    videoSequence.AppendComponent(axVideoClipA)
    videoSequence.AppendComponent(axVideoDslvTransition)
    videoSequence.AppendComponent(axVideoClipB)

    print "savinging comp"
    axFile.SaveCopyAs(comp_fileName)
    axFile.toXml(xmlfile)
    axFile.Close()


if __name__ == "__main__":
    #run essence_create to setup mobs
    essence_create.essence_create()
    #create composition
    comp_create()