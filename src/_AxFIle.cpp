
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <AxFile.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(AxFile_OpenNewModify_overloads_1_3, OpenNewModify, 1, 3)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(AxFile_OpenExistingModify_overloads_1_3, OpenExistingModify, 1, 3)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(AxFile_OpenExistingRead_overloads_1_2, OpenExistingRead, 1, 2)

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(AxFile_OpenTransient_overloads_0_1, OpenTransient, 0, 1)


void PySaveAs(AxFile file, AxString path)
{

AxFile newfile;
newfile.OpenNewModify( path );
file.SaveCopyAs(newfile);
newfile.Close();
    }


}// namespace 


// Module ======================================================================
void Export_pyste_src_AxFIle()
{
    class_< AxFile >("AxFile", init<  >())
        .def(init< IAAFFileSP >())
        .def(init< const AxFile& >())
        .def("isAAFFile", &AxFile::isAAFFile)
        .def("OpenNewModify", &AxFile::OpenNewModify, AxFile_OpenNewModify_overloads_1_3())
        .def("OpenExistingModify", &AxFile::OpenExistingModify, AxFile_OpenExistingModify_overloads_1_3())
        .def("OpenExistingRead", &AxFile::OpenExistingRead, AxFile_OpenExistingRead_overloads_1_2())
        .def("OpenTransient", &AxFile::OpenTransient, AxFile_OpenTransient_overloads_0_1())
        .def("Save", &AxFile::Save)
        .def("SaveCopyAs", &PySaveAs)
        .def("Close", &AxFile::Close)
        .def("getName", &AxFile::getName, return_value_policy< copy_const_reference >())
        .def("getHeader", &AxFile::getHeader)
        .staticmethod("isAAFFile")
        .def("to_IAAFFileSP", &AxFile::operator IAAFFileSP)
    ;

}

