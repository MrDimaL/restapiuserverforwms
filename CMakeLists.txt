cmake_minimum_required(VERSION 3.15)
project(wms-userver CXX)

find_package(userver COMPONENTS core REQUIRED)

include_directories(src)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} userver::core)