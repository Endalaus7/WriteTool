cmake_minimum_required(VERSION 3.10)
project(WriteTool)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_PREFIX_PATH ${QT_DIR}/bin)
set(QT6_DIR ${QT_DIR}/lib/cmake/Qt6)


#standard_project_setup()

# 增加编译选项
add_compile_options("/permissive-")
add_compile_options("/Zc:__cplusplus")

set(PROJECT_SOURCE_DIR "./src")

add_subdirectory(code)