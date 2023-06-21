cmake_minimum_required(VERSION 3.10)
project(myproject)
include_directories(include)
include_directories(file_operate/include)
include_directories(clock/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_library(mylib STATIC file_operate/src/file_operator.cpp clock/src/clock.cpp common/common.cpp)


add_executable(test main.cpp)
target_link_libraries(test mylib)