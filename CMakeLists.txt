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

if (DEFINED ENV{AAF_PLATFORM})
    SET(AAF_PLATFORM $ENV{AAF_PLATFORM})
    message("AAF_PLATFORM: " ${AAF_PLATFORM})
else()
    message(FATAL_ERROR "No AAF_PLATFORM set")
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
    ${AAFSDK_ROOT}/AAF${AAF_PLATFORM}SDK/g++/include
    include
)

LINK_DIRECTORIES(
    ${AAFSDK_ROOT}/AAF${AAF_PLATFORM}SDK/g++/lib/debug
    ${AAFSDK_ROOT}/AAF${AAF_PLATFORM}SDK/g++/bin/debug
    ${AAFSDK_ROOT}/AAF${AAF_PLATFORM}SDK/g++/axExamples/debug
    )

FILE(GLOB Souces src/*.cpp)
SET(CMAKE_SHARED_LIBRARY_PREFIX "")
ADD_LIBRARY(pyaaf SHARED ${Souces})


target_link_libraries(pyaaf
    ${Boost_LIBRARIES}
    ${PYTHON_LIBRARIES}
    aaflib
    aafiid
    com-api
    axLib
)

