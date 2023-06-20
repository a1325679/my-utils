cmake_minimum_required(VERSION 3.10)
project(myproject)
include_directories(include)
include_directories(file_operate/include)
# link_directories(${PROJECT_SOURCE_DIR}/lib)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

#add_subdirectory(file_operate)

add_executable(test main.cpp file_operate/src/file_operator.cpp common/common.cpp)
#target_link_libraries(test mylib)