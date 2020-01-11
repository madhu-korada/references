Cmake_minimum_required(VERSION 2.8)
project( serial_cpp )
set (CMAKE_CXX_STANDARD 11)



set(SOURCE_FILES
    src/icd_radar.cpp
    src/serial.cpp
)
set(HEADER_FILES ${PROJECT_SOURCE_DIR}/include/icd_radar.h
				 ${PROJECT_SOURCE_DIR}/include/icdbitmasks.h
				 ${PROJECT_SOURCE_DIR}/include/serial.h
				 )

include_directories(
  "${PROJECT_SOURCE_DIR}/include"
)

add_executable( serial_cpp src/main.cpp ${HEADER_FILES} ${SOURCE_FILES})

# add_executable( serial_cpp src/main.cpp )


