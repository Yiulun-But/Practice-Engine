cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SANDBOX_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")

add_executable(Sandbox ${SANDBOX_SRC})

target_include_directories(Sandbox PRIVATE 
    ${PROJECT_SOURCE_DIR}/Practice/vendor/spdlog/include
    ${PROJECT_SOURCE_DIR}/Practice/vendor/glm/glm
    ${PROJECT_SOURCE_DIR}/Practice/src
)

target_link_libraries(Sandbox PRIVATE Lilasoul)

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set_target_properties(Sandbox PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${OUTPUT_DIR}/${OUTPUTCONFIG}-$<PLATFORM_ID>-${CMAKE_SYSTEM_PROCESSOR}/Sandbox
        LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${OUTPUT_DIR}/${OUTPUTCONFIG}-$<PLATFORM_ID>-${CMAKE_SYSTEM_PROCESSOR}/Sandbox
        RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${OUTPUT_DIR}/${OUTPUTCONFIG}-$<PLATFORM_ID>-${CMAKE_SYSTEM_PROCESSOR}/Sandbox
    )
endforeach()

if (MSVC)
    set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
    target_compile_definitions(Sandbox PRIVATE LS_PLATFORM_WINDOWS)
    target_compile_options(Sandbox PRIVATE /MDd)
    add_custom_command(TARGET Sandbox POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Lilasoul> $<TARGET_FILE_DIR:Sandbox>)
endif()

# Configuration specific settings
set_property(TARGET Sandbox PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

foreach(CONFIG_TYPE IN ITEMS Debug Release Dist)
    string(TOUPPER ${CONFIG_TYPE} CONFIG_TYPE_UPPER)
    if(${CONFIG_TYPE} STREQUAL "Debug")
        target_compile_definitions(Sandbox PRIVATE LS_DEBUG)
        target_compile_options(Sandbox PRIVATE $<$<CONFIG:Debug>:/Zi>)
    elseif(${CONFIG_TYPE} STREQUAL "Release")
        target_compile_definitions(Sandbox PRIVATE LS_RELEASE)
        target_compile_options(Sandbox PRIVATE $<$<CONFIG:Release>:-O3>)
    elseif(${CONFIG_TYPE} STREQUAL "Dist")
        target_compile_definitions(Sandbox PRIVATE LS_DIST)
        target_compile_options(Sandbox PRIVATE $<$<CONFIG:Dist>:-O3>)
    endif()
endforeach()
