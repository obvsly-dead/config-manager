cmake_minimum_required(VERSION 3.10)
project(CONFIG_MANAGER)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core DBus)

add_subdirectory(server)
add_subdirectory(app)
