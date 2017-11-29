cmake_minimum_required(VERSION 3.8)
project(Week_8)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp StringConvert.h StringMatch.h RangeIntersectionResolver.h helpers.h RangeIntersection.h Task2/Task2.cpp Task2/Task2.h)
add_executable(Week_8 ${SOURCE_FILES})