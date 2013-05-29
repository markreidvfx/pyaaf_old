import pyaaf
import uuid
import os


KLVKey_AxExampleData_A = pyaaf.aafUID.fromString(uuid.UUID("4353dc46-5a56-42f0-a4d8-9516dd98335f").urn)
KLVKey_AxExampleData_B = pyaaf.aafUID.fromString(uuid.UUID("6def0b26-d055-41f9-892b-c7528fdae103").urn)


def metaCreate():
    
    dirname = os.path.dirname(__file__)
    fileName = os.path.join(dirname,"meta_create.aaf")
    
    axFile = pyaaf.AxFile()
    axFile.OpenNewModify( fileName )
    
    axHeader = axFile.GetHeader()
    axDictionary = pyaaf.AxDictionary(axHeader.GetDictionary())
    
    axDictionary.RegisterKLVDataKey(KLVKey_AxExampleData_A,
                                    axDictionary.LookupTypeDef( pyaaf.TypeDefUID.UInt8Array ) )
    
    axDictionary.RegisterKLVDataKey(KLVKey_AxExampleData_B,
                                    axDictionary.LookupTypeDef( pyaaf.TypeDefUID.UInt8Array ) );
                                    
    for name in ('Audio Mob A', 'Audio Mob B', 'Video Mob A' ,'Video Mob B'):
        axMasterMob = pyaaf.AxMasterMob.CreateInstance(axDictionary)
        axMasterMob.Initialize()
        
        axMasterMob.SetName(name)
    
        axMasterMob.AppendComment('comment_category_a', 'comment_a')
        axMasterMob.AppendComment('comment_category_b', 'comment_b')
        
        klv_UInt16 = pyaaf.AxKLVData.CreateInstance(axDictionary)
        klv_UInt16.Initialize_aafUInt16(KLVKey_AxExampleData_A,0xabcd)
        
        klv_UInt32 = pyaaf.AxKLVData.CreateInstance(axDictionary)
        klv_UInt32.Initialize_aafUInt32(KLVKey_AxExampleData_B,0x87654321)
        
        axMasterMob.AppendKLVData( klv_UInt16 )
        axMasterMob.AppendKLVData( klv_UInt32 )
        
        axHeader.AddMob(axMasterMob)

    
    axFile.Save()
    axFile.toXml(os.path.join(dirname,"metaCreate.xml"))
    axFile.Close()



if __name__ == "__main__":
    
    metaCreate()