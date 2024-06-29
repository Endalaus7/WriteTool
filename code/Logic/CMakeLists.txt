project(Logic)

file(GLOB SOURCE_FILE ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB RESOURCE_FILE ${PROJECT_SOURCE_DIR}/src/*.qrc)
file(GLOB HEADER_FILE ${PROJECT_SOURCE_DIR}/include/*.h)

set(LIBRARY_OUTPUT_PATH ${BIN_DIR}/${PROJECT_NAME})

find_package(Qt6 COMPONENTS Core Xml REQUIRED)
if(NOT Qt6_FOUND)
    message("############!!NOT FOUND QT6!!##############")
endif()

SOURCE_GROUP("Include Files" FILES ${HEADER_FILE})
SOURCE_GROUP("Resource Files" FILES ${RESOURCE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILE} ${RESOURCE_FILE} ${HEADER_FILE})
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${LOGIC_DIR}/include
    ${MAPP_DIR}/include
)
message(${MAPP_DIR}/include)
target_link_libraries(${PROJECT_NAME} 
    Qt::Core
    Qt::Xml
    MApp
)


install(TARGETS ${PROJECT_NAME} 
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

install(FILES ${HEADER_FILE} DESTINATION include)