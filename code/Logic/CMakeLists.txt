file(GLOB SOURCE_FILE ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB RESOURCE_FILE ${PROJECT_SOURCE_DIR}/src/*.qrc)

add_library(logic STATIC ${SOURCE_FILE} ${RESOURCE_FILE})
#target_link_libraries(logic PRIVATE Qt6::Core)
#target_include_directories(logic INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


