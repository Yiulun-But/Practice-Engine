cmake_minimum_required(VERSION 3.10)

# Project Lilasoul
file(GLOB_RECURSE LILASOUL_SRC "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/src/*.h")

add_library(Lilasoul SHARED ${LILASOUL_SRC})

target_include_directories(Lilasoul PRIVATE 
    ${PROJECT_SOURCE_DIR}/Practice/vendor/spdlog/include
    ${PROJECT_SOURCE_DIR}/Practice/
)

target_link_libraries(Lilasoul PRIVATE spdlog)

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set_target_properties(Lilasoul PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${OUTPUT_DIR}/${OUTPUTCONFIG}-$<PLATFORM_ID>-${CMAKE_SYSTEM_PROCESSOR}/Lilasoul
        LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${OUTPUT_DIR}/${OUTPUTCONFIG}-$<PLATFORM_ID>-${CMAKE_SYSTEM_PROCESSOR}/Lilasoul
        RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${OUTPUT_DIR}/${OUTPUTCONFIG}-$<PLATFORM_ID>-${CMAKE_SYSTEM_PROCESSOR}/Lilasoul
    )
endforeach()

if (MSVC)
    target_compile_definitions(Lilasoul PRIVATE LS_BUILD_DLL)
    target_compile_definitions(Lilasoul PRIVATE LS_PLATFORM_WINDOWS)
    target_compile_options(Lilasoul PRIVATE /MT)
elseif(NOT MSVC)
    message(FATAL_ERROR "Does not support non-msvc yet!")
endif()

# Configuration specific settings
set_property(TARGET Lilasoul PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE INTERNAL "")

foreach(CONFIG_TYPE IN ITEMS Debug Release Dist)
    string(TOUPPER ${CONFIG_TYPE} CONFIG_TYPE_UPPER)
    if(${CONFIG_TYPE} STREQUAL "Debug")
        target_compile_definitions(Lilasoul PRIVATE LS_DEBUG)
        target_compile_options(Lilasoul PRIVATE $<$<CONFIG:Debug>:/Zi>)
    elseif(${CONFIG_TYPE} STREQUAL "Release")
        target_compile_definitions(Lilasoul PRIVATE LS_RELEASE)
        target_compile_options(Lilasoul PRIVATE $<$<CONFIG:Release>:-O3>)
    elseif(${CONFIG_TYPE} STREQUAL "Dist")
        target_compile_definitions(Lilasoul PRIVATE LS_DIST)
        target_compile_options(Lilasoul PRIVATE $<$<CONFIG:Dist>:-O3>)
    endif()
endforeach()