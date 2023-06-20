cmake_minimum_required(VERSION 3.10)
project(RayTracer)
set(CMAKE_CXX_STANDARD 14)


set(CMAKE_BUILD_TYPE Debug) # Remove this line if you already have a build type set

if(CMAKE_COMPILER_IS_GNUCXX)
    message("Adding code coverage flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -Ofast -fno-unroll-loops")
endif()

include_directories(${RayTracer_SOURCE_DIR}/include)
add_subdirectory(src)
add_subdirectory(tests)