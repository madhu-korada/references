Cmake_minimum_required(VERSION 2.8)
project( Radar_parser )
set (CMAKE_CXX_STANDARD 11)

include_directories(
  "${PROJECT_SOURCE_DIR}/include"
)

add_executable( Radar_parser src/radar_parser.cpp )
#add_executable( Radar_parser src/main_verification.cpp )


