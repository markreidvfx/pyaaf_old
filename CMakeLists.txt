cmake_minimum_required(VERSION 2.6)

project(PyAAF)

if(APPLE)
    SET(CMAKE_SHARED_LIBRARY_SUFFIX .so)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
    SET (CMAKE_SHARED_LINKER_FLAGS
    "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-rpath,'$ORIGIN'" )
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
    include
    axLib
    ${Boost_INCLUDE_DIRS}
    ${PYTHON_INCLUDE_DIRS}
    ${AAFSDK_ROOT}/include
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

#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/pyaaf)

FILE(GLOB Souces src/*.cpp)
FILE(GLOB AxLibSouces axLib/*.cpp)
FILE(GLOB IncludeSources include/*.cpp)
SET(CMAKE_SHARED_LIBRARY_PREFIX "")
ADD_LIBRARY(core SHARED ${Souces} ${AxLibSouces} ${IncludeSources})


target_link_libraries(core
    ${Boost_LIBRARIES}
    ${PYTHON_LIBRARIES}
    aaflib
    aafiid
    com-api
)

