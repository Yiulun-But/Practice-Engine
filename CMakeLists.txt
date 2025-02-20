cmake_minimum_required(VERSION 3.20)

project(Lilasoul)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "" FORCE)

# Define linker flags for new config types
set(CMAKE_SHARED_LINKER_FLAGS_DIST "${CMAKE_SHARED_LINKER_FLAGS_RELEASE}")
set(CMAKE_EXE_LINKER_FLAGS_DIST "${CMAKE_EXE_LINKER_FLAGS_RELEASE}")

# Output directories
set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin")

# Set binary directory
set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/bin-int")

# Set glfw path
set(GLFW_DIR "${CMAKE_SOURCE_DIR}/bin-int")

include("C:/Users/yiulu/vcpkg/scripts/buildsystems/vcpkg.cmake")


find_package(OpenGL REQUIRED)


#Update submodules as needed
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/Practice/vendor/glfw")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# Add glfw
add_subdirectory(${PROJECT_SOURCE_DIR}/Practice/vendor/glfw)

#Add glm
add_subdirectory(${PROJECT_SOURCE_DIR}/Practice/vendor/glm)


# Add Macros
add_subdirectory(Macros)

# Find spdlog
# find_package(spdlog CONFIG REQUIRED)

# Project Lilasoul
add_subdirectory(Practice)

# Project Sandbox
add_subdirectory(Sandbox)
