cmake_minimum_required(VERSION 3.15)
project(Bombreak)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source file
set(SOURCE_FILE Bombreak.cpp)

# Add the executable
add_executable(Bombreak ${SOURCE_FILE})

# Set the output directory for the binary
set_target_properties(Bombreak PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
