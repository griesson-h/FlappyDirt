cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 23)

#set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE MinSizeRel)

#option(ENABLE_ASAN "Enable AddressSanitizer" ON)

project(FlappyDirt)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game.cpp
    src/flappy.cpp
    src/object.cpp
    src/ground.cpp
    src/background.cpp
    src/pipes.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
