import pyaaf
from pyaaf.pct_parser import pct_parser
import array

"""
This example walks through all the video tracks looking for Title_2 OperationGroups 
(these are avid Title Effects, clips a that are created with AvidTitleTool) 
and prints their text, along with the video Track number, in frame and out frame.
"""

def get_video_tracks(mob):
    tracks = []
    
    for slot in mob.GetSlots():
        segment = slot.GetSegment()

        if segment.GetDataDef().GetName() == "Picture":
            if isinstance(segment, pyaaf.AxNestedScope):
                
                for nested_segment in segment.GetSegments():
                    
                    if isinstance(nested_segment, pyaaf.AxSequence):
                        tracks.append(list(nested_segment.GetComponents()))
                        
            elif isinstance(segment, pyaaf.AxSequence):
                tracks.append(list(segment.GetComponents()))
                
            elif isinstance(segment, pyaaf.AxSourceClip):
                tracks.append([segment])

    return tracks

def get_transition_offset(index,component_list):
    
    offset = 0

    nextItem = None
    prevousItem = None
    
    if len(component_list) > index + 1:
        nextItem = component_list[index + 1]
        
    if index != 0:
        prevousItem = component_list[index -1]

    if isinstance(nextItem, pyaaf.AxTransition):
        offset -= nextItem.GetLength() - nextItem.GetCutPoint()

    if isinstance(prevousItem, pyaaf.AxTransition):
        offset -= prevousItem.GetCutPoint()
        
    return offset
    
    

def dump_avid_titles(header):
    
    storage= header.GetContentStorage()
    
    main_mob = list(storage.GetTopLevelMobs())[0]
    
    tracks = get_video_tracks(main_mob)
    
    for i, track in enumerate(tracks):

        length = 0
        for k, component in enumerate(track):
            
            transition_offset = get_transition_offset(k,track)
            component_length = component.GetLength() + transition_offset
            
            in_frame = length
            out_frame = length +component_length + transition_offset
            
            if isinstance(component, pyaaf.AxOperationGroup):
                if component.GetOperationDef().GetName() == "Title_2":
                    for param in component.GetParameters():
                        
                        definition = param.GetParameterDefinition()
                        param_name = definition.GetName()
                        
                        param_type_name = definition.GetTypeDefinition().GetName()
     
                        if param_name == "AvidGraphicFXAttr":
                            #first property is the Definition Second is the Value
                            p = list(param.GetProperties())[1]
                            
                            #returns a AxPropertyValue
                            value = p.GetValue()
                            
                            #finally get the data
                            
                            AvidBagOfBits = value.GetValue()
                            string_data = array.array("B",AvidBagOfBits).tostring()
                            
                            print "Track: V%i Title_2 in: %i out: %i" % (i+1, in_frame, out_frame)
                            
                            #converts data to list of dictionaries
                            data = pct_parser(string_data)
                            for item in data:

                                if item['type'] == "TitleText":

                                    print '  ', item['text'].replace("\r",'\n   ')
                                    
                                    
            if not isinstance(component, pyaaf.AxTransition):
                length += component_length

if __name__ == "__main__":
    from pprint import pprint
    from optparse import OptionParser
    
    parser = OptionParser()
    (options, args) = parser.parse_args()
    
    
    if not args:
        parser.error("not enough argements")
    
    
    with pyaaf.open(args[0]) as f:
        
        header = f.GetHeader()
        
        dump_avid_titles(header)