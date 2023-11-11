cmake_minimum_required(VERSION 3.0)
project(MandelbrotProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SDL2 library
set(SDL2_DIR "/opt/homebrew/Cellar/SDL2/2.28.5")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(SDL2 REQUIRED)

# Include directories
include_directories(${SDL2_INCLUDE_DIRS})

# Add your source files
add_executable(Mandelbrot mandelbrot.cpp)

# Link SDL2 libraries
target_link_libraries(Mandelbrot ${SDL2_LIBRARIES})