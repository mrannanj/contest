cmake_minimum_required(VERSION 2.8.4)
project(contest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Woverloaded-virtual -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-variable -Wno-unused-result")

file(GLOB_RECURSE CPP_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

foreach( source ${CPP_SOURCES} )
    string( REPLACE ".cpp" "" bin_name ${source} )
    string( REPLACE "${PROJECT_SOURCE_DIR}/" "" bin_name ${bin_name} )
    GET_FILENAME_COMPONENT( bin_path ${source} PATH)
    string( REPLACE "${PROJECT_SOURCE_DIR}/" "" bin_path ${bin_path} )
    file( MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/${bin_path}" )
    add_executable( ${bin_name} ${source} )
endforeach( source ${CPP_SOURCES} )

file(GLOB_RECURSE C_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

foreach( source ${C_SOURCES} )
    string( REPLACE ".c" "" bin_name ${source} )
    string( REPLACE "${PROJECT_SOURCE_DIR}/" "" bin_name ${bin_name} )
    GET_FILENAME_COMPONENT( bin_path ${source} PATH)
    string( REPLACE "${PROJECT_SOURCE_DIR}/" "" bin_path ${bin_path} )
    file( MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/${bin_path}" )
    add_executable( ${bin_name} ${source} )
    target_link_libraries( ${bin_name} "-lm")
endforeach( source ${C_SOURCES} )
