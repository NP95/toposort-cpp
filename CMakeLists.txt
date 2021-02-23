set(LibName toposort)

project(${LibName} LANGUAGES CXX)

cmake_minimum_required(VERSION 3.0)

option(TOPOSORT_BUILD_EXAMPLE "Build the example application?" OFF)

add_library(${LibName} INTERFACE "toposort.hpp")

target_include_directories(${LibName} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(${LibName} INTERFACE cxx_std_14)

if (TOPOSORT_BUILD_EXAMPLE)
    set(ExampleName "${LibName}_example")
    add_executable(${ExampleName} "example.cpp")
    target_link_libraries(${ExampleName} PRIVATE ${LibName})
endif()
