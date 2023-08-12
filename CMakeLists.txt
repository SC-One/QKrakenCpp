cmake_minimum_required(VERSION 3.14)

set(ROOT_PRJ QKrakenCpp)
project(${ROOT_PRJ} LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(${ROOT_PRJ} SHARED
  QKrakenCpp_global.h
  QKrakenCpp.cpp
  QKrakenCpp.h
)

target_link_libraries(${ROOT_PRJ} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
)

target_compile_definitions(${ROOT_PRJ} PRIVATE QKRAKENCPP_LIBRARY)