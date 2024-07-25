cmake_minimum_required(VERSION 3.20)

add_library(glad STATIC "${CMAKE_CURRENT_LIST_DIR}/src/glad.c"
    "${CMAKE_CURRENT_LIST_DIR}/include/glad/glad.h"
    "${CMAKE_CURRENT_LIST_DIR}/include/KHR/khrplatform.h")

target_include_directories(glad PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/")

if (MSVC)
    target_compile_options(glad PRIVATE /MDd)
endif()

set_property(TARGET glad PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
