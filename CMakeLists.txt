cmake_minimum_required(VERSION 2.8.12...3.22)
project(OpenGL_Base VERSION 1.0.0 DESCRIPTION "Base for OpenGL" LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(enable_warnings target)
target_compile_options(${target} PUBLIC 
$<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
$<$<CXX_COMPILER_ID:AppleClang>:-Wall -Wextra -Wconversion>
$<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wconversion>
$<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wconversion>
)
endfunction()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

find_package(OpenGL REQUIRED)
add_subdirectory(modules)

set(HEADER_FILES
	include/rendering/controls.h
	include/rendering/Mesh.h
	include/rendering/Model.h
	include/rendering/Shader.h
	include/rendering/util.h
)

set(SOURCE_FILES 
	src/main.cpp
	src/rendering/controls.cpp
	src/rendering/Mesh.cpp
	src/rendering/Model.cpp
	src/rendering/Shader.cpp
	src/rendering/util.cpp
)

# Add header with path to resources and add header to include directory
set(INCLUDE_RESOURCES_STRING ${CMAKE_CURRENT_LIST_DIR}/resources)
configure_file(
    ${CMAKE_SOURCE_DIR}/resources/ResourcePath.h.in
    ${CMAKE_BINARY_DIR}/generated/ResourcePath.h @ONLY
)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/generated)

add_executable(OpenGL_Base ${SOURCE_FILES} ${HEADER_FILES})

enable_warnings(OpenGL_Base)
# make OpenGL_T the default project in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT OpenGL_T)

target_include_directories(OpenGL_Base PRIVATE include ${GLM_INCLUDE_DIR})

## target_link_libraries takes care of setting the include
target_link_libraries(OpenGL_Base PRIVATE OpenGL::GL glad::glad glfw assimp stb::stb glm::glm)
