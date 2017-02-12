cmake_minimum_required(VERSION 3.0.0)
project(interviews VERSION 0.0.0)

file(GLOB_RECURSE sources      src/*.cpp src/*.h)
file(GLOB_RECURSE sources_test src/test/*.cpp)

include(CMakeToolsHelpers OPTIONAL)

add_executable(interviews ${sources})
target_compile_options(interviews PUBLIC -std=c++1y -Wall -Werror)

target_include_directories(interviews PUBLIC src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)