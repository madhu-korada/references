Cmake_minimum_required(VERSION 2.8)
project(read_yaml)
set (CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable( read_yaml read_yaml_opencv.cpp )

target_link_libraries(read_yaml ${OpenCV_LIBS})


