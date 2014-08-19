project(ivi_server)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
find_path(STDIO_INCLUDE_PATH stdio.h)
include_directories("${STDIO_INCLUDE_PATH}/")
add_executable(${PROJECT_NAME} ${SRC_LIST})

