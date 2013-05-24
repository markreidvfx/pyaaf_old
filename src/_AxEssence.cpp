
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFTypes.h>
#include <AxEssence.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================


template <typename T>
void PyAddFormatSpecifier(AxEssenceFormat &axEssenceFormat,
                          const aafUID_t essenceFormatCode,
                          T sampleSize)
{
    axEssenceFormat.AddFormatSpecifier( essenceFormatCode, sizeof( sampleSize ),
                                       reinterpret_cast<aafUInt8*>(&sampleSize) );
};

template <typename T>
AxEssenceAccess::WriteResult PyWriteSamples(AxEssenceAccess& axEssenceAccess, int samples, boost::python::list l)
{
    
    const int length = boost::python::len(l);
    T values[length];
    
    for (int i=0; i < length; i++)
    {
        values[i] = boost::python::extract<T>(l[i]);
    }
    
    
    return axEssenceAccess.WriteSamples(samples,
                                        sizeof(values[0]) * length,
                                        reinterpret_cast<aafDataBuffer_t>(&values));
};


void PySetVideoLineMap(AxDigitalImageDescriptor& a, boost::python::list l)
{
    
    const int length = boost::python::len(l);
    aafInt32 values[length];

    for (int i=0; i < length; i++)
    {
        values[i] = boost::python::extract<aafUInt16>(l[i]);
    }
    a.SetVideoLineMap(length, values);
    
}



// Module ======================================================================
void Export_pyste_src_AxEssence()
{


    class_< AxEssenceMultiAccess, boost::noncopyable >("AxEssenceMultiAccess", init< IAAFEssenceMultiAccessSP >())
    ;

    scope* AxEssenceAccess_scope = new scope(
    class_< AxEssenceAccess, bases< AxEssenceMultiAccess > , boost::noncopyable >("AxEssenceAccess", init< IAAFEssenceAccessSP >())
        .def("GetEmptyFileFormat", &AxEssenceAccess::GetEmptyFileFormat)
        .def("GetFileFormat", &AxEssenceAccess::GetFileFormat)
        .def("GetFileFormatParameterList", &AxEssenceAccess::GetFileFormatParameterList)
        .def("PutFileFormat", &AxEssenceAccess::PutFileFormat)
        .def("CountSamples", &AxEssenceAccess::CountSamples)
        .def("WriteSamples_UInt16", &PyWriteSamples<aafUInt16>)
        .def("WriteSamples_UInt8", &PyWriteSamples<aafUInt8>)
        .def("CompleteWrite", &AxEssenceAccess::CompleteWrite)
        .def("GetCodecName", &AxEssenceAccess::GetCodecName)
        .def("GetLargestSampleSize", &AxEssenceAccess::GetLargestSampleSize)
        .def("ReadSamples", &AxEssenceAccess::ReadSamples)
    );

    class_< AxEssenceAccess::WriteResult >("WriteResult", init<  >())
        .def(init< const AxEssenceAccess::WriteResult& >())
        .def_readwrite("hr", &AxEssenceAccess::WriteResult::hr)
        .def_readwrite("samplesWritten", &AxEssenceAccess::WriteResult::samplesWritten)
        .def_readwrite("bytesWritten", &AxEssenceAccess::WriteResult::bytesWritten)
    ;


    class_< AxEssenceAccess::ReadResult >("ReadResult", init<  >())
        .def(init< const AxEssenceAccess::ReadResult& >())
        .def_readwrite("samplesRead", &AxEssenceAccess::ReadResult::samplesRead)
        .def_readwrite("bytesRead", &AxEssenceAccess::ReadResult::bytesRead)
    ;

    delete AxEssenceAccess_scope;

    class_< AxLocator, boost::noncopyable >("AxLocator", init< IAAFLocatorSP >())
        .def("SetPath", &AxLocator::SetPath)
        .def("GetPath", &AxLocator::GetPath)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFLocatorSP", &AxLocator::operator IAAFLocatorSP)
    ;

    class_< AxEssenceDescriptor, boost::noncopyable >("AxEssenceDescriptor", init< IAAFEssenceDescriptorSP >())
        .def("CountLocators", &AxEssenceDescriptor::CountLocators)
        .def("AppendLocator", &AxEssenceDescriptor::AppendLocator)
        .def("GetLocators", &AxEssenceDescriptor::GetLocators)
        .def("GetClassName", &AxObject::GetClassName)
        .def("GetDictionary", &AxObject::GetDictionary)
        .def("GetProperties", &AxObject::GetProperties)
        .def("GetDefinition", &AxObject::GetDefinition)
        .def("to_IAAFEssenceDescriptorSP", &AxEssenceDescriptor::operator IAAFEssenceDescriptorSP)
    ;

    class_< AxWAVEDescriptor, bases< AxEssenceDescriptor > , boost::noncopyable >("AxWAVEDescriptor", init< IAAFWAVEDescriptorSP >())
        .def("SetSummary", &AxWAVEDescriptor::SetSummary)
        .def("GetSummary", &AxWAVEDescriptor::GetSummary)
        .def("GetContainerFormat", &AxFileDescriptor::GetContainerFormat)
        .def("GetLength", &AxFileDescriptor::GetLength)
        .def("GetSampleRate", &AxFileDescriptor::GetSampleRate)
        .def("SetCodecDef", &AxFileDescriptor::SetCodecDef)
        .def("SetContainerFormat", &AxFileDescriptor::SetContainerFormat)
        .def("SetLength", &AxFileDescriptor::SetLength)
        .def("SetSampleRate", &AxFileDescriptor::SetSampleRate)
    ;

    class_< AxDigitalImageDescriptor, bases< AxEssenceDescriptor > , boost::noncopyable >("AxDigitalImageDescriptor", init< IAAFDigitalImageDescriptorSP >())
        .def("SetStoredView", &AxDigitalImageDescriptor::SetStoredView)
        .def("SetSampledView", &AxDigitalImageDescriptor::SetSampledView)
        .def("SetDisplayView", &AxDigitalImageDescriptor::SetDisplayView)
        .def("SetFrameLayout", &AxDigitalImageDescriptor::SetFrameLayout)
        .def("SetVideoLineMap", &PySetVideoLineMap)
        .def("SetCompression", &AxDigitalImageDescriptor::SetCompression)
        .def("SetAlphaTransparency", &AxDigitalImageDescriptor::SetAlphaTransparency)
        .def("SetGamma", &AxDigitalImageDescriptor::SetGamma)
        .def("SetImageAspectRatio", &AxDigitalImageDescriptor::SetImageAspectRatio)
        .def("SetImageAlignmentFactor", &AxDigitalImageDescriptor::SetImageAlignmentFactor)
        .def("GetStoredView", &AxDigitalImageDescriptor::GetStoredView)
        .def("GetSampledView", &AxDigitalImageDescriptor::GetSampledView)
        .def("GetDisplayView", &AxDigitalImageDescriptor::GetDisplayView)
        .def("GetFrameLayout", &AxDigitalImageDescriptor::GetFrameLayout)
        .def("GetVideoLineMap", &AxDigitalImageDescriptor::GetVideoLineMap)
        .def("GetCompression", &AxDigitalImageDescriptor::GetCompression)
        .def("GetAlphaTransparency", &AxDigitalImageDescriptor::GetAlphaTransparency)
        .def("GetGamma", &AxDigitalImageDescriptor::GetGamma)
        .def("GetImageAspectRatio", &AxDigitalImageDescriptor::GetImageAspectRatio)
        .def("GetImageAlignmentFactor", &AxDigitalImageDescriptor::GetImageAlignmentFactor)
        .def("GetContainerFormat", &AxFileDescriptor::GetContainerFormat)
        .def("GetLength", &AxFileDescriptor::GetLength)
        .def("GetSampleRate", &AxFileDescriptor::GetSampleRate)
        .def("SetCodecDef", &AxFileDescriptor::SetCodecDef)
        .def("SetContainerFormat", &AxFileDescriptor::SetContainerFormat)
        .def("SetLength", &AxFileDescriptor::SetLength)
        .def("SetSampleRate", &AxFileDescriptor::SetSampleRate)
    ;

    class_< AxCDCIDescriptor, bases< AxDigitalImageDescriptor > , boost::noncopyable >("AxCDCIDescriptor", init< IAAFCDCIDescriptorSP >())
        .def("SetPaddingBits", &AxCDCIDescriptor::SetPaddingBits)
        .def("SetComponentWidth", &AxCDCIDescriptor::SetComponentWidth)
        .def("SetHorizontalSubsampling", &AxCDCIDescriptor::SetHorizontalSubsampling)
        .def("SetVerticalSubsampling", &AxCDCIDescriptor::SetVerticalSubsampling)
        .def("SetColorSiting", &AxCDCIDescriptor::SetColorSiting)
        .def("SetBlackReferenceLevel", &AxCDCIDescriptor::SetBlackReferenceLevel)
        .def("SetWhiteReferenceLevel", &AxCDCIDescriptor::SetWhiteReferenceLevel)
        .def("SetColorRange", &AxCDCIDescriptor::SetColorRange)
        .def("GetPaddingBits", &AxCDCIDescriptor::GetPaddingBits)
        .def("GetComponentWidth", &AxCDCIDescriptor::GetComponentWidth)
        .def("GetHorizontalSubsampling", &AxCDCIDescriptor::GetHorizontalSubsampling)
        .def("GetVerticalSubsampling", &AxCDCIDescriptor::GetVerticalSubsampling)
        .def("GetColorSiting", &AxCDCIDescriptor::GetColorSiting)
        .def("GetBlackReferenceLevel", &AxCDCIDescriptor::GetBlackReferenceLevel)
        .def("GetWhiteReferenceLevel", &AxCDCIDescriptor::GetWhiteReferenceLevel)
        .def("GetColorRange", &AxCDCIDescriptor::GetColorRange)
    ;

    class_< AxRGBADescriptor, bases< AxDigitalImageDescriptor > , boost::noncopyable >("AxRGBADescriptor", init< IAAFRGBADescriptor2SP >())
        .def(init< IAAFRGBADescriptorSP >())
        .def("SetPixelLayout", &AxRGBADescriptor::SetPixelLayout)
        .def("SetPalette", &AxRGBADescriptor::SetPalette)
        .def("SetPaletteLayout", &AxRGBADescriptor::SetPaletteLayout)
        .def("SetComponentMaxRef", &AxRGBADescriptor::SetComponentMaxRef)
        .def("SetComponentMinRef", &AxRGBADescriptor::SetComponentMinRef)
        .def("SetAlphaMaxRef", &AxRGBADescriptor::SetAlphaMaxRef)
        .def("SetAlphaMinRef", &AxRGBADescriptor::SetAlphaMinRef)
        .def("SetScanningDirection", &AxRGBADescriptor::SetScanningDirection)
        .def("GetPixelLayout", &AxRGBADescriptor::GetPixelLayout)
        .def("GetPalette", &AxRGBADescriptor::GetPalette)
        .def("GetPaletteLayout", &AxRGBADescriptor::GetPaletteLayout)
        .def("GetComponentMaxRef", &AxRGBADescriptor::GetComponentMaxRef)
        .def("GetComponentMinRef", &AxRGBADescriptor::GetComponentMinRef)
        .def("GetAlphaMaxRef", &AxRGBADescriptor::GetAlphaMaxRef)
        .def("GetAlphaMinRef", &AxRGBADescriptor::GetAlphaMinRef)
        .def("GetScanningDirection", &AxRGBADescriptor::GetScanningDirection)
        .def("to_IAAFRGBADescriptorSP", &AxRGBADescriptor::operator IAAFRGBADescriptorSP)
        .def("to_IAAFRGBADescriptor2SP", &AxRGBADescriptor::operator IAAFRGBADescriptor2SP)
    ;

    class_< AxTapeDescriptor, bases< AxEssenceDescriptor > , boost::noncopyable >("AxTapeDescriptor", init< IAAFTapeDescriptorSP >())
        .def("Initialize", &AxTapeDescriptor::Initialize)
        .def("SetTapeManufacturer", &AxTapeDescriptor::SetTapeManufacturer)
        .def("GetTapeManufacturer", &AxTapeDescriptor::GetTapeManufacturer)
        .def("SetTapeModel", &AxTapeDescriptor::SetTapeModel)
        .def("GetTapeModel", &AxTapeDescriptor::GetTapeModel)
        .def("SetTapeFormFactor", &AxTapeDescriptor::SetTapeFormFactor)
        .def("GetTapeFormFactor", &AxTapeDescriptor::GetTapeFormFactor)
        .def("SetSignalType", &AxTapeDescriptor::SetSignalType)
        .def("GetSignalType", &AxTapeDescriptor::GetSignalType)
        .def("SetTapeFormat", &AxTapeDescriptor::SetTapeFormat)
        .def("GetTapeFormat", &AxTapeDescriptor::GetTapeFormat)
        .def("SetTapeLength", &AxTapeDescriptor::SetTapeLength)
        .def("GetTapeLength", &AxTapeDescriptor::GetTapeLength)
        .def("to_IAAFTapeDescriptorSP", &AxTapeDescriptor::operator IAAFTapeDescriptorSP)
    ;

    class_< AxFilmDescriptor, bases< AxEssenceDescriptor > , boost::noncopyable >("AxFilmDescriptor", init< IAAFFilmDescriptorSP >())
        .def("SetFilmManufacturer", &AxFilmDescriptor::SetFilmManufacturer)
        .def("GetFilmManufacturer", &AxFilmDescriptor::GetFilmManufacturer)
        .def("SetFilmModel", &AxFilmDescriptor::SetFilmModel)
        .def("GetFilmModel", &AxFilmDescriptor::GetFilmModel)
        .def("SetFilmFormat", &AxFilmDescriptor::SetFilmFormat)
        .def("GetFilmFormat", &AxFilmDescriptor::GetFilmFormat)
        .def("SetFrameRate", &AxFilmDescriptor::SetFrameRate)
        .def("GetFrameRate", &AxFilmDescriptor::GetFrameRate)
        .def("SetPerfPerFrame", &AxFilmDescriptor::SetPerfPerFrame)
        .def("GetPerfPerFrame", &AxFilmDescriptor::GetPerfPerFrame)
        .def("SetFilmAspectRatio", &AxFilmDescriptor::SetFilmAspectRatio)
        .def("GetFilmAspectRatio", &AxFilmDescriptor::GetFilmAspectRatio)
        .def("to_IAAFFilmDescriptorSP", &AxFilmDescriptor::operator IAAFFilmDescriptorSP)
    ;

    class_< AxPhysicalDescriptor, bases< AxEssenceDescriptor > , boost::noncopyable >("AxPhysicalDescriptor", init< IAAFPhysicalDescriptorSP >())
        .def("to_IAAFPhysicalDescriptorSP", &AxPhysicalDescriptor::operator IAAFPhysicalDescriptorSP)
    ;

    class_< AxImportDescriptor, bases< AxPhysicalDescriptor > , boost::noncopyable >("AxImportDescriptor", init< IAAFImportDescriptorSP >())
        .def("Initialize", &AxImportDescriptor::Initialize)
        .def("to_IAAFImportDescriptorSP", &AxImportDescriptor::operator IAAFImportDescriptorSP)
    ;

    class_< AxRecordingDescriptor, bases< AxPhysicalDescriptor > , boost::noncopyable >("AxRecordingDescriptor", init< IAAFRecordingDescriptorSP >())
        .def("Initialize", &AxRecordingDescriptor::Initialize)
        .def("to_IAAFRecordingDescriptorSP", &AxRecordingDescriptor::operator IAAFRecordingDescriptorSP)
    ;

    class_< AxAuxiliaryDescriptor, bases< AxPhysicalDescriptor > , boost::noncopyable >("AxAuxiliaryDescriptor", init< IAAFAuxiliaryDescriptorSP >())
        .def("Initialize", &AxAuxiliaryDescriptor::Initialize)
        .def("GetMimeType", &AxAuxiliaryDescriptor::GetMimeType)
        .def("GetCharSet", &AxAuxiliaryDescriptor::GetCharSet)
        .def("SetMimeType", &AxAuxiliaryDescriptor::SetMimeType)
        .def("SetCharSet", &AxAuxiliaryDescriptor::SetCharSet)
        .def("to_IAAFAuxiliaryDescriptorSP", &AxAuxiliaryDescriptor::operator IAAFAuxiliaryDescriptorSP)
    ;

    class_< AxSoundDescriptor, bases< AxEssenceDescriptor > , boost::noncopyable >("AxSoundDescriptor", init< IAAFSoundDescriptorSP >())
        .def("GetCompression", &AxSoundDescriptor::GetCompression)
        .def("GetChannelCount", &AxSoundDescriptor::GetChannelCount)
        .def("GetAudioSamplingRate", &AxSoundDescriptor::GetAudioSamplingRate)
        .def("IsLocked", &AxSoundDescriptor::IsLocked)
        .def("GetElectroSpatialFormulation", &AxSoundDescriptor::GetElectroSpatialFormulation)
        .def("GetAudioRefLevel", &AxSoundDescriptor::GetAudioRefLevel)
        .def("GetDialNorm", &AxSoundDescriptor::GetDialNorm)
        .def("GetQuantizationBits", &AxSoundDescriptor::GetQuantizationBits)
        .def("SetCompression", &AxSoundDescriptor::SetCompression)
        .def("SetChannelCount", &AxSoundDescriptor::SetChannelCount)
        .def("SetAudioSamplingRate", &AxSoundDescriptor::SetAudioSamplingRate)
        .def("SetIsLocked", &AxSoundDescriptor::SetIsLocked)
        .def("SetElectroSpatialFormulation", &AxSoundDescriptor::SetElectroSpatialFormulation)
        .def("SetAudioRefLevel", &AxSoundDescriptor::SetAudioRefLevel)
        .def("SetDialNorm", &AxSoundDescriptor::SetDialNorm)
        .def("SetQuantizationBits", &AxSoundDescriptor::SetQuantizationBits)
        .def("GetContainerFormat", &AxFileDescriptor::GetContainerFormat)
        .def("GetLength", &AxFileDescriptor::GetLength)
        .def("GetSampleRate", &AxFileDescriptor::GetSampleRate)
        .def("SetCodecDef", &AxFileDescriptor::SetCodecDef)
        .def("SetContainerFormat", &AxFileDescriptor::SetContainerFormat)
        .def("SetLength", &AxFileDescriptor::SetLength)
        .def("SetSampleRate", &AxFileDescriptor::SetSampleRate)
        .def("to_IAAFSoundDescriptorSP", &AxSoundDescriptor::operator IAAFSoundDescriptorSP)
    ;


    class_< AxEssenceFormat, boost::noncopyable >("AxEssenceFormat", init< IAAFEssenceFormatSP >())
        .def("to_IAAFEssenceFormatSP", &AxEssenceFormat::operator IAAFEssenceFormatSP)
        .def("AddFormatSpecifier", PyAddFormatSpecifier<aafUInt32>)
        .def("AddFormatSpecifier", PyAddFormatSpecifier<aafRect_t>)
        ;
}

