# Minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Project name
project(MyProject VERSION 1.0.0 LANGUAGES CXX)

# Add ASAN option
option(USE_ASAN "Use AddressSanitizer" OFF)
if (USE_ASAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -static-libasan -fsanitize=address")
endif()

# Add source files
add_executable(MyExecutable main.cpp)

# Set C++ standard
set_target_properties(MyExecutable PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# C++96, C++11, C++17, C++20