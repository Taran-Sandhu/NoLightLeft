cmake_minimum_required(VERSION 3.16)
project(NoLightLeft VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES}
        src/manager/RoomManager.cpp
        src/model/Player.cpp
        src/model/Room.cpp
        src/util/StringUtil.cpp
        include/manager/MapGenerator.h
        src/manager/MapGenerator.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
)

target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra -pedantic
)
