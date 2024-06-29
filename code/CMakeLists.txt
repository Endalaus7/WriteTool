
# 设置 Qt 库的地址（按霢�设置＄1�71ￄ1�77

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(LOGIC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Logic)
set(MAPP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/MApp)
set(CONFIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/config)
#set(CMAKE_MODULE_PATH "D:/SDK/qt/6.8.0/mingw_64/lib/cmake/Qt6")

find_library(LIBRARY_NAME Logic PATH ${LOGIC_DIR})
find_library(LIBRARY_NAME MApp PATH ${MAPP_DIR})

file(GLOB SOURCE_FILE ./*.cpp)
file(GLOB CONFIG_FILE  ${CONFIG_DIR}/*.in)


add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILE} ${CONFIG_FILE}) 

target_link_libraries(${CMAKE_PROJECT_NAME} 
    MApp
    Logic
)
#target_link_libraries(${CMAKE_PROJECT_NAME} Logic ${CMAKE_SOURCE_DIR}/Logic.lib)
#target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


add_subdirectory(MApp)
add_subdirectory(Logic)


target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE 
    ${LOGIC_DIR}/include
    ${MAPP_DIR}/include
    ${PROJECT_BINARY_DIR}
    )

# cmake本身有四种编译模式：`Debug`, `Release`, `RelWithDebInfo`, `MinSizeRel`
# 此操作将`Debug`和`RelWithDebInfo`归类于QML的debug，即这两种模式下QML运行会保留debug信息
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)



install(TARGETS ${PROJECT_NAME} ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib 
    ARCHIVE DESTINATION static_lib
)