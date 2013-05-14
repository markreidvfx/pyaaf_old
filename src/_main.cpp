// Include =====================================================================
#include <boost/python/module.hpp>

// Exports =====================================================================
void Export_pyste_src_PyRecord();
void Export_pyste_src_PyAxObject();
void Export_pyste_src_AxUtil();
void Export_pyste_src_AxTypes();
void Export_pyste_src_AxSmartPointer();
void Export_pyste_src_AxPropertyValue();
void Export_pyste_src_AxProperty();
void Export_pyste_src_AxObject();
void Export_pyste_src_AxMobSlot();
void Export_pyste_src_AxMob();
void Export_pyste_src_AxIterator();
void Export_pyste_src_AxInit();
void Export_pyste_src_AxHeader();
void Export_pyste_src_AxFIle();
void Export_pyste_src_AxEssence();
void Export_pyste_src_AxDictionary();
void Export_pyste_src_AxContentStorage();
void Export_pyste_src_AxBaseObjIter();
void Export_pyste_src_AxBaseObj();
void Export_pyste_src_AAFTypes();

// Module ======================================================================
BOOST_PYTHON_MODULE(pyaaf)
{
    Export_pyste_src_PyRecord();
    Export_pyste_src_PyAxObject();
    Export_pyste_src_AxUtil();
    Export_pyste_src_AxTypes();
    Export_pyste_src_AxSmartPointer();
    Export_pyste_src_AxPropertyValue();
    Export_pyste_src_AxProperty();
    Export_pyste_src_AxObject();
    Export_pyste_src_AxMobSlot();
    Export_pyste_src_AxMob();
    Export_pyste_src_AxIterator();
    Export_pyste_src_AxInit();
    Export_pyste_src_AxHeader();
    Export_pyste_src_AxFIle();
    Export_pyste_src_AxEssence();
    Export_pyste_src_AxDictionary();
    Export_pyste_src_AxContentStorage();
    Export_pyste_src_AxBaseObjIter();
    Export_pyste_src_AxBaseObj();
    Export_pyste_src_AAFTypes();
}
