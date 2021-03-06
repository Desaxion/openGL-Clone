
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS    OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS     OFF CACHE INTERNAL "Build the GLFW documentation")
add_subdirectory(glfw)

set(BUILD_FRAMEWORK            OFF CACHE INTERNAL "Build package as Mac OS X Framework bundle.")
set(ASSIMP_DOUBLE_PRECISION    OFF CACHE INTERNAL "Set to ON to enable double precision processing")
set(ASSIMP_OPT_BUILD_PACKAGES  OFF CACHE INTERNAL "Set to ON to generate CPack configuration files and packaging targets")
set(ASSIMP_INSTALL_PDB         OFF CACHE INTERNAL "Install MSVC debug files.")
set(ASSIMP_ANDROID_JNIIOSYSTEM OFF CACHE INTERNAL "Android JNI IOSystem support is active")
set(ASSIMP_NO_EXPORT           OFF CACHE INTERNAL "Disable Assimp's export functionality.")
set(ASSIMP_BUILD_ZLIB          OFF CACHE INTERNAL "Build your own zlib")
set(ASSIMP_BUILD_ASSIMP_TOOLS  OFF CACHE INTERNAL "If the supplementary tools for Assimp are built in addition to the library.")
set(ASSIMP_BUILD_SAMPLES       OFF CACHE INTERNAL "If the official samples are built as well (needs Glut).")
set(ASSIMP_BUILD_TESTS         OFF CACHE INTERNAL "If the test suite for Assimp is built in addition to the library.")
set(ASSIMP_COVERALLS           OFF CACHE INTERNAL "Enable this to measure test coverage.")
set(ASSIMP_WERROR              OFF CACHE INTERNAL "Treat warnings as errors.")
set(ASSIMP_ASAN                OFF CACHE INTERNAL "Enable AddressSanitizer.")
set(ASSIMP_UBSAN               OFF CACHE INTERNAL "Enable Undefined Behavior sanitizer.")
set(SYSTEM_IRRXML              OFF CACHE INTERNAL "Use system installed Irrlicht/IrrXML library.")
set(BUILD_DOCS                 OFF CACHE INTERNAL "Build documentation using Doxygen.")
set(INJECT_DEBUG_POSTFIX       ON  CACHE INTERNAL "Inject debug postfix in .a/.so lib names")
set(IGNORE_GIT_HASH            ON  CACHE INTERNAL "Don't call git to get the hash.")
add_subdirectory(assimp)

option(GLM_QUIET "No CMake Message" ON)
option(GLM_TEST_ENABLE "Build unit tests" OFF)
# set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "GLM shared lib build")
# set(BUILD_STATIC_LIBS ON  CACHE INTERNAL "GLM static build")
add_subdirectory(glm)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # Needed when using clang since GLM fails to detect c++11/14 support
    # https://github.com/g-truc/glm/issues/620
    target_compile_definitions(glm INTERFACE GLM_FORCE_CXX14)
endif()

add_subdirectory(stb)
add_subdirectory(glad)
