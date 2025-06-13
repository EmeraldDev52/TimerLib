cmake_minimum_required(VERSION 3.10)

project(TimerLib
    VERSION 1.0.0
    DESCRIPTION "A simple cross-platform C++ timer library"
    LANGUAGES CXX
)

# Library target
add_library(TimerLib STATIC src/timer.cpp)

# Header include path
target_include_directories(TimerLib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Set C++ standard (optional but good practice)
target_compile_features(TimerLib PUBLIC cxx_std_11)

# Export targets
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/TimerLibConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Create install rules
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

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/TimerLibConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/TimerLibConfig.cmake"
    INSTALL_DESTINATION lib/cmake/TimerLib
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/TimerLibConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/TimerLibConfigVersion.cmake"
    DESTINATION lib/cmake/TimerLib
)