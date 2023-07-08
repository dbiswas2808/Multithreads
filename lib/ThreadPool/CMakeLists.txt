cmake_minimum_required(VERSION 3.15)

add_library(ThreadPool
    ThreadPool/ThreadPool.h
    ThreadPool/ThreadPool.cpp
)

set_target_properties ( ThreadPool PROPERTIES LINKER_LANGUAGE CXX )
set_property ( TARGET ThreadPool PROPERTY CXX_STANDARD 20 )
set_property ( TARGET ThreadPool PROPERTY CXX_STANDARD_REQUIRED ON )

target_include_directories(ThreadPool PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")

add_executable(ThreadPoolTest ThreadPool/ThreadPool.t.cpp)
target_link_libraries(ThreadPoolTest PRIVATE Catch2::Catch2WithMain Catch2::Catch2)

set ( LINKER_LANG CXX )
set ( CMAKE_PROJECT_ThreadPoolTest_LINKER_LANG CXX )

set_property ( TARGET ThreadPoolTest PROPERTY CXX_STANDARD 20 )
set_property ( TARGET ThreadPoolTest PROPERTY CXX_STANDARD_REQUIRED ON )

add_test(NAME ThreadPoolTest COMMAND ThreadPoolTest)
