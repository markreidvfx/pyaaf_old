
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AAFFileKinds.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================

class FileKindDef {};


// Module ======================================================================
void Export_pyste_src_AAFFileKinds()
{

    scope FileKindDef_scope = class_<FileKindDef>("FileKindDef");
    FileKindDef_scope.attr("AafS512Binary") = kAAFFileKind_AafS512Binary;
    FileKindDef_scope.attr("AafM512Binary") = kAAFFileKind_AafM512Binary;
    FileKindDef_scope.attr("AafG512Binary") = kAAFFileKind_AafG512Binary;
    FileKindDef_scope.attr("Aaf4KBinary") = kAAFFileKind_Aaf4KBinary;
    FileKindDef_scope.attr("Aaf512Binary") = kAAFFileKind_Aaf512Binary;
    FileKindDef_scope.attr("Pathological") = kAAFFileKind_Pathological;
    FileKindDef_scope.attr("AafKlvBinary") = kAAFFileKind_AafKlvBinary;
    FileKindDef_scope.attr("AafS4KBinary") = kAAFFileKind_AafS4KBinary;
    FileKindDef_scope.attr("DontCare") = kAAFFileKind_DontCare;
    FileKindDef_scope.attr("AafM4KBinary") = kAAFFileKind_AafM4KBinary;
    FileKindDef_scope.attr("AafG4KBinary") = kAAFFileKind_AafG4KBinary;
    FileKindDef_scope.attr("AafXmlText") = kAAFFileKind_AafXmlText;
    }

