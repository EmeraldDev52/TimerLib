cmake_minimum_required(VERSION 3.14)
project(TimerLib VERSION 1.0 LANGUAGES CXX)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(TimerLib STATIC ${SOURCES})

add_library(Timers::TimerLib ALIAS TimerLib)

target_include_directories(TimerLib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

set_target_properties(TimerLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE ON
)

install(TARGETS TimerLib
    EXPORT TimerLibTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT TimerLibTargets
    FILE TimerLibTargets.cmake
    NAMESPACE TimerLib::
    DESTINATION lib/cmake/TimerLib
)
