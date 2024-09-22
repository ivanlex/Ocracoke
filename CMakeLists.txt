cmake_minimum_required(VERSION 3.13)

project("Ocracoke")
set(CMAKE_CXX_STANDARD 17)
set(REFOLDER ${PROJECT_SOURCE_DIR}/reference)

# Source files
set(SOURCES Ocracoke.cpp
        core/Application.cpp
        core/Common.cpp
        core/CommonDef.cpp)

# Headers from 3rd library
set(INCLUDES ${REFOLDER}/cpp-httplib/include
        ${REFOLDER}/glfw/include
        ${REFOLDER}/rapidJson/include
        ${REFOLDER}/glad/include
        ${REFOLDER}/glm/include)

# Libraries from 3rd library
set(LINK_LIBRARIES ${REFOLDER}/glfw/lib_vc2022/lib/glfw3.lib)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LINK_LIBRARIES})

# Debug Deploy
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            "${PROJECT_SOURCE_DIR}/reference/glfw/lib_vc2022/bin/glfw3.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/")

