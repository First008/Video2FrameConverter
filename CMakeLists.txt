
cmake_minimum_required(VERSION 2.8.12)
# Every project needs a name.  We call this the "examples" project.
project(example)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

link_directories( ${CMAKE_BINARY_DIR})

add_executable(Video2FrameConverter converter.cpp)

target_link_libraries(Video2FrameConverter ${OpenCV_LIBS} )
