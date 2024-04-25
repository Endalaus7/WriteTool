cmake_minimum_required(VERSION 3.10)
project(WriteTool)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_PREFIX_PATH ${QT_DIR}/bin)
set(QT6_DIR ${QT_DIR}/lib/cmake/Qt6)


set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)
set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${BIN_DIR}/${PROJECT_NAME})

set(DATA_PATH  "${PROJECT_SOURCE_DIR}/data" CACHE PATH "root path")
set(CONFIG_PATH "${PROJECT_SOURCE_DIR}/code/config")

configure_file (
  "${CONFIG_PATH}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

#standard_project_setup()

# 增加编译选项
add_compile_options("/permissive-")
add_compile_options("/Zc:__cplusplus")

set(PROJECT_SOURCE_DIR "./src")

add_subdirectory(code)

