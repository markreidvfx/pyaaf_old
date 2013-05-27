cmake_minimum_required(VERSION 2.6)

project(PyAAF)

if(APPLE)
    SET(CMAKE_SHARED_LIBRARY_SUFFIX .so)
endif()

if (DEFINED ENV{AAFSDK_ROOT})
    SET(AAFSDK_ROOT $ENV{AAFSDK_ROOT})
    message("AAFSDK_ROOT: " ${AAFSDK_ROOT})
else()
    message(FATAL_ERROR "No AAFSDK_ROOT set")
endif()

find_package(Boost COMPONENTS python REQUIRED)
message("Include dirs of boost: " ${Boost_INCLUDE_DIRS} )
message("Libs of boost: " ${Boost_LIBRARIES} )

SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_MULTITHREADED ON)
SET(Boost_USE_STATIC_RUNTIME OFF)

find_package(PythonLibs REQUIRED)
message("Include dirs of Python: " ${PYTHON_INCLUDE_DIRS} )
message("Libs of Python: " ${PYTHON_LIBRARIES} )

include_directories(
    ${Boost_INCLUDE_DIRS}
    ${PYTHON_INCLUDE_DIRS}
    ${AAFSDK_ROOT}/examples2/axLib
    ${AAFSDK_ROOT}/include
    include
    axLib
)


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("debug mode")
    LINK_DIRECTORIES(
    ${AAFSDK_ROOT}/lib/debug
    ${AAFSDK_ROOT}/bin/debug
    )
else()
    LINK_DIRECTORIES(
    ${AAFSDK_ROOT}/lib
    ${AAFSDK_ROOT}/bin
    )
endif()



FILE(GLOB Souces src/*.cpp)
FILE(GLOB AxLibSouces axLib/*.cpp)
SET(CMAKE_SHARED_LIBRARY_PREFIX "")
ADD_LIBRARY(core SHARED ${Souces} ${AxLibSouces})


target_link_libraries(core
    ${Boost_LIBRARIES}
    ${PYTHON_LIBRARIES}
    aaflib
    aafiid
    com-api
)

