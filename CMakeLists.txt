cmake_minimum_required(VERSION 3.10)

project(Sample_01)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INSTALL_PREFIX .)

include(ExternalProject)
ExternalProject_Add(
    Sample_02
    GIT_REPOSITORY  https://github.com/nilanindraweera/Build-Sample-02.git
    GIT_TAG Develop
    CMAKE_ARGS  -DSAMPLE_02_STATIC_LIB=OFF -DCMAKE_CXX_STANDARD=17 -DCMAKE_CXX_STANDARD_REQUIRED=True -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_BINARY_DIR}/libemp
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/my-sample-02
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/my-libraries    
)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/libemp/include)
add_executable(Sample_01 main.cpp)
target_link_libraries(Sample_01 ${CMAKE_CURRENT_BINARY_DIR}/libemp/lib/libSample_02.a)