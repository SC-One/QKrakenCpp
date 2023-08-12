cmake_minimum_required(VERSION 3.14)

set(ROOT_PRJ QKrakenCpp)
project(${ROOT_PRJ} LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network Concurrent)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Concurrent)

add_library(${ROOT_PRJ} SHARED
  QKrakenCpp_global.h
  QKrakenCpp.cpp
  QKrakenCpp.h
  TSNetworkManager.h TSNetworkManager.cpp
  KrakenJsonParser.h KrakenJsonParser.cpp
  Structures.h
)

target_link_libraries(${ROOT_PRJ} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Concurrent
)
target_include_directories(${ROOT_PRJ} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(${ROOT_PRJ} PRIVATE QKRAKENCPP_LIBRARY)
