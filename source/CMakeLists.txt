cmake_minimum_required (VERSION 3.10)
project(plange)
enable_testing()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(NOT MSVC) # Remove condition once CMAKE supports this with Visual Studio 2017
	set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
endif()

set(DEP_DIR "${CMAKE_BINARY_DIR}/../../../Dependencies" CACHE INTERNAL "Dependenies directory")

add_subdirectory(utilities)
add_subdirectory(mpl)
add_subdirectory(collections)
add_subdirectory(parlex)
add_subdirectory(plc)
add_subdirectory(grammar_gen)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT plc)

