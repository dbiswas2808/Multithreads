cmake_minimum_required(VERSION 3.15)

# add thread pool library
add_library(ThreadPool
    ThreadPool/ThreadPool.h
    ThreadPool/ThreadPool.cpp
)

set_target_properties(ThreadPool PROPERTIES LINKER_LANGUAGE CXX)
set_property(TARGET ThreadPool PROPERTY CXX_STANDARD 20)
set_property(TARGET ThreadPool PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(ThreadPool PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")

# Add test
add_executable(ThreadPoolTest ThreadPool/ThreadPool.t.cpp)
set_target_properties(ThreadPoolTest PROPERTIES LINKER_LANGUAGE CXX)
set_property(TARGET ThreadPoolTest PROPERTY CXX_STANDARD 20)
set_property(TARGET ThreadPoolTest PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(ThreadPoolTest PRIVATE Catch2::Catch2WithMain ThreadPool)

add_test(NAME ThreadPoolTest COMMAND ThreadPoolTest)
