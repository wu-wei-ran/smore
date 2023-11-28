
set(project_name demo)
project(${project_name} LANGUAGES CXX)

file(GLOB_RECURSE HEADERS
    *.h)

file(GLOB_RECURSE SOURCES
    *.cpp)

set(MAIN_SOURCES ${HEADERS} ${SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${MAIN_SOURCES})

add_executable(${project_name}
    #WIN32
    ${MAIN_SOURCES}
)


include_directories(../src/include)
target_link_libraries(${project_name} PRIVATE sdk_base)
