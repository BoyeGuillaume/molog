# require the minimum version of cmake to be 3.12
cmake_minimum_required(VERSION 3.12)

# list of all the source file(s)
file(GLOB_RECURSE MOLOG_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/molog/**.cpp")


# add the library as a target
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/generated/configure.hpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/src/molog/configure.hpp")

if(${MOLOG_BUILD_SHARED})
    add_library(Molog SHARED ${MOLOG_SOURCE_FILES})
    target_compile_definitions(Molog PRIVATE __MO_DLL_EXPORT)
else()
    add_library(Molog ${MOLOG_SOURCE_FILES})
endif()

target_include_directories(Molog
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/"
    PUBLIC "${MOLOG_THIRD_PARTY}/backward-cpp/include/"
)


