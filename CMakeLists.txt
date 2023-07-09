cmake_minimum_required(VERSION 3.0.0)
project(Multithreads VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include Conan
include ( cmake/modules/SetupConan.cmake )

# Enable ccache for caching compilation results
find_program ( CCACHE_FOUND ccache )
find_package(Catch2 3 REQUIRED)

if ( CCACHE_FOUND )
    set ( CMAKE_C_COMPILER_LAUNCHER ${CCACHE} )
    set ( CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE} )
endif ( CCACHE_FOUND )

add_subdirectory(lib)

add_executable(Multithreads main.cpp)

set ( LINKER_LANG CXX )
set ( CMAKE_PROJECT_Multithreads_LINKER_LANG CXX )

# cpp CXX standard
set_property ( TARGET Multithreads PROPERTY CXX_STANDARD 20 )
set_property ( TARGET Multithreads PROPERTY CXX_STANDARD_REQUIRED ON )

target_link_libraries(Multithreads 
PUBLIC 
ThreadPool)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
