cmake_minimum_required(VERSION 3.12)

include(CMakePackageConfigHelpers)

SET(curr_version 1.0)

project(libKIniTest VERSION ${curr_version} 
				DESCRIPTION "A test program for libKIni"
				LANGUAGES CXX)
				
add_subdirectory(extern/libKIni)
include_directories(${CMAKE_SOURCE_DIR}/extern/libKIni/include)
add_subdirectory(src)