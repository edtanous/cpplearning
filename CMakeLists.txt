
CMAKE_MINIMUM_REQUIRED(VERSION 3.2.2)

# See http://git.libssh.org/projects/libssh.git/tree/ for example of a good project configuration.

# Global vars

SET(CMAKE_PROJECT_NAME "CppLearning")

SET(EXECUTABLE_NAME "CppLearning")

SET(EXECUTABLE_VERSION_MAJOR "0")
SET(EXECUTABLE_VERSION_MINOR "0")
SET(EXECUTABLE_VERSION_PATCH "0")

SET(EXECUTABLE_VERSION "${EXECUTABLE_VERSION_MAJOR}.${EXECUTABLE_VERSION_MINOR}.${EXECUTABLE_VERSION_PATCH}")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "Config.h.in"
  "Config.h"
  )

# Additional CMake modules, specific for this project
SET(CMAKE_MODULE_PATH
  ${CMAKE_SOURCE_DIR}/CMake/Modules
  )

# Load those modules
INCLUDE(Define_CMakeDefaults)
INCLUDE(Define_PlatformDefaults)
INCLUDE(Define_CompilerFlags)

# Project command is here, to set some values correctly.
PROJECT(${CMAKE_PROJECT_NAME})

# Nifty marco, which forbids in source build. (source: http://git.libssh.org/projects/libssh.git)
INCLUDE(Macro_EnsureOutOfSourceBuild)
MACRO_ENSURE_OUT_OF_SOURCE_BUILD("${PROJECT_NAME}  requires an out of source build. Please create a separate build directory and run 'cmake /path/to/${CMAKE_PROJECT_NAME} [options]' there.")

# Another macro used in this project to add sources efficiently.
INCLUDE(Macro_AddSources)

# Source files for the test suite. This should only include source files in
# the test subdirectory. Compiler options for the test build are located in
# the CMakeLists.txt file in the test subdirectory.
set(TEST_SOURCES 
        TestMyMath.cpp
    )


#Add aditional components.
FIND_PACKAGE ( Boost COMPONENTS serialization system filesystem REQUIRED )

# add the boost include dirs
include_directories(${Boost_INCLUDE_DIRS})




set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)


MESSAGE(STATUS "Current built type: ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "Current build type flags: ${CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}}")

MESSAGE(STATUS "Configuring application ${APPLICATION_NAME}")

MACRO_PREPARE_SOURCES(PROJECT_SOURCES)

# The googletest code should be unzipped and placed in the gtest directory.
# No user-created files should be placed in the gtest directory.
add_subdirectory(gtest)
include_directories(gtest/include)

# The add_subdirectory commands should be last.

# Project source files should be placed in the src subdirectory.
add_subdirectory(src)


#Line below outputs all included source.
MACRO_PRINT_SOURCES()

INCLUDE_DIRECTORIES(
    ${Boost_INCLUDE_DIR}
)

ADD_EXECUTABLE(
    ${EXECUTABLE_NAME}
    ${PROJECT_SOURCES}
)

TARGET_LINK_LIBRARIES(
    ${EXECUTABLE_NAME}
    ${Boost_LIBRARIES}
)


