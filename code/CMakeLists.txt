
# 设置 Qt 库的地址（按霢�设置＄1�71ￄ1�77

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(LOGIC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Logic)
set(MAPP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/MApp)
set(CONFIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/config)
#set(CMAKE_MODULE_PATH "D:/SDK/qt/6.8.0/mingw_64/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS Core Widgets Gui Xml REQUIRED)
find_library(LIBRARY_NAME Logic PATH ${LOGIC_DIR})
if(NOT Qt6_FOUND)
    message("############!!NOT FOUND QT6!!##############")
endif()


file(GLOB SOURCE_FILE ./*.cpp ${MAPP_DIR}/src/*.cpp)
file(GLOB RESOURCE_FILE ${MAPP_DIR}/src/*.qrc)
file(GLOB UI_FILE ${MAPP_DIR}/form/*.ui)
file(GLOB HEAD_FILE  ${MAPP_DIR}/include/*.h)
file(GLOB CONFIG_FILE  ${CONFIG_DIR}/*.in)


#QT6_WRAP_UI(UI_H_FILES ${UI_FILE} )
#QT6_WRAP_MOC()
#SOURCE_GROUP("Ui Header Files" FILES ${UI_H_FILES})
SOURCE_GROUP("Include Files" FILES ${HEAD_FILE})
SOURCE_GROUP("Resource Files" FILES ${RESOURCE_FILE})
SOURCE_GROUP("Ui Files" FILES ${UI_FILE})

add_executable(${CMAKE_PROJECT_NAME} ${HEAD_FILE} ${SOURCE_FILE} ${RESOURCE_FILE} ${UI_FILE} ${CONFIG_FILE}) 

target_link_libraries(${CMAKE_PROJECT_NAME} 
    Qt::Core
    Qt::Gui
    Qt::Widgets
    Qt::Xml
    Logic
)
#target_link_libraries(${CMAKE_PROJECT_NAME} Logic ${CMAKE_SOURCE_DIR}/Logic.lib)

message(${CMAKE_SOURCE_DIR}/Logic.lib)
#target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Logic)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE 
    ${MAPP_DIR}/include 
    ${LOGIC_DIR}/include
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