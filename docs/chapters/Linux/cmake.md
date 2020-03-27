---
layout: default
title: CMake
lang-ref: chapter1.0
---
### Headers 
```bash
Cmake_minimum_required(VERSION 2.8)
project(project_name)
set (CMAKE_CXX_STANDARD 11)
```
#### find a library
```bash
find_package(OpenCV REQUIRED)
```
#### use a separately installed library
##### opencv
```bash
find_package(OpenCV 4.1.1 REQUIRED PATHS "/home/hitech/installation/OpenCV-master/lib/cmake/opencv4")
```