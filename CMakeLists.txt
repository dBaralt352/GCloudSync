cmake_minimum_required(VERSION 3.28)
project(GCloudSync C)

set(CMAKE_C_STANDARD 23)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_executable(GCloudSync main.c
        authentication.c
        authentication.h)

target_compile_definitions(GCloudSync PRIVATE "CLIENT_SECRET=\"$ENV{CLIENT_SECRET}\"" "CLIENT_ID=\"$ENV{CLIENT_ID}\"")

include(FindPkgConfig)
find_package(HTTPListener REQUIRED)
include_directories(${HTTPListener_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${HTTPListener_LIBRARY})
