cmake_minimum_required(VERSION 3.27)
project(ps2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt")

find_package(Qt6 COMPONENTS
        Core Widgets
        REQUIRED)

add_executable(ps2 main.cpp)
target_link_libraries(ps2
        Qt::Core
)
target_link_libraries(ps2
        Qt::Widgets
)

