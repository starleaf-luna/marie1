cmake_minimum_required(VERSION 3.16)
project(marie1 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(mariebin "src/main.cpp" "src/actor.h" "src/marie.h" "src/tileset.h")
target_link_libraries(mariebin PRIVATE sfml-graphics)
target_link_libraries(mariebin PRIVATE sfml-audio)
target_compile_features(mariebin PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET mariebin
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:mariebin>
        VERBATIM)
endif()

add_custom_command(
    TARGET mariebin POST_BUILD 
    COMMENT "Copy assets"
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/src/assets $<TARGET_FILE_DIR:mariebin>/assets)
