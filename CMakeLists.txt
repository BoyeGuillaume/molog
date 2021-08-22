# require the minimum version of cmake to be 3.12
cmake_minimum_required(VERSION 3.12)

# create the project and configure some variables
project(molog LANGUAGES CXX)

# require std+17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(MOLOG_VERSION_MAJOR 0)
set(MOLOG_VERSION_MINOR 1)
set(MOLOG_VERSION_PATCH 4)
set(MOLOG_VERSION "${MOLOG_VERSION_MAJOR}.${MOLOG_VERSION_MINOR}.${MOLOG_VERSION_PATCH}")
set(MOLOG_THIRD_PARTY "${CMAKE_CURRENT_SOURCE_DIR}/third_party/")
message("-- Found Molog v${MOLOG_VERSION} at ${CMAKE_CURRENT_SOURCE_DIR}")

# options that enable to configure this script
option(MOLOG_BUILD_TEST "Add the testing target" OFF)
option(MOLOG_BUILD_SHARED "Build the library as a dynamic library (.dll / .so)" ON)
option(MOLOG_VALIDATION_LAYER "Add a validation layer to the library" ON)
option(MOLOG_ENABLE_STACKTRACE "Enable display the stack trace on exception" ON)
option(MOLOG_ENABLE_DB_COMPABILITIES "Database will be compatible with over platform (generic endianness). May impact performance" OFF)

if(${MOLOG_BUILD_SHARED} AND ${MOLOG_BUILD_TEST})
    message(FATAL_ERROR "-- Incompatible option : Test required static library linkage")
endif()

# add the source subdirectory
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/molog/")

# add the test subdirectory if option is enable
if(${MOLOG_BUILD_TEST})
    message("-- Build Molog Test")

    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
    )

    # For Windows: Prevent overriding the parent project's compiler/linker settings
    message("-- Molog Test : retrieve or download googletest this step might take some times...")
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/test/")
endif()
