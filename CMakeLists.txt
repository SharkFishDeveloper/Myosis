# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(main VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Collect all .c files in the functions directory and its subdirectories
file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/**/*.c
    ${PROJECT_SOURCE_DIR}/index.c
)

# Collect all .h files in the functions directory and its subdirectories
file(GLOB_RECURSE HEADERS
    ${PROJECT_SOURCE_DIR}/src/**/*.h
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

# Optionally add compiler flags for warnings and debugging
target_compile_options(${PROJECT_NAME} PRIVATE )
