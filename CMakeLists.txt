# Author: Joseph Lisee <jlisee@gmail.com>
# License: BSD (see LICENSE in root)

cmake_minimum_required (VERSION 2.6)

project (structered_typing)

# Definitions
add_definitions(-g -O3)

# Template
add_executable(template template.cpp)

# Virtual
add_library(virtuallib SHARED libvirtual.cpp)

add_executable(virtual virtual.cpp)

target_link_libraries(virtual virtuallib)

add_executable(unity_virtual unity_virtual.cpp)

# Structured
add_library(structuredlib SHARED libstructured.cpp)

add_executable(structured structured.cpp)

target_link_libraries(structured structuredlib)

add_executable(unity_structured unity_structured.cpp)