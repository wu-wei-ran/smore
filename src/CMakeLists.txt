cmake_minimum_required(VERSION 3.18)

set(project_name "sdk_base")
project(${project_name} LANGUAGES CXX)



include_directories(./include)

file(GLOB_RECURSE _SOURCES
    include/*.h
    cpp/*.cpp
)


set(source ${_SOURCES})

add_library(${project_name} SHARED
  ${source}
)
