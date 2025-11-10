cmake_minimum_required(VERSION 3.16)
project(SDL3BlueWindow LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use pkg-config to find SDL3 on Arch
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED sdl3)

# Include SDL3 headers
include_directories(${SDL3_INCLUDE_DIRS})

# Add your source file(s)
add_executable(${PROJECT_NAME}
    src/main.cpp
)

# Link SDL3 libraries
target_link_libraries(${PROJECT_NAME}
    ${SDL3_LIBRARIES}
)

# Ensure rpath includes SDL3 location (so it finds libSDL3.so at runtime)
set_target_properties(${PROJECT_NAME} PROPERTIES
    BUILD_RPATH "${SDL3_LIBRARY_DIRS}"
)

