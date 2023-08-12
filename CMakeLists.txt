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

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE HEADER_FILES
  ${INC_DIR}/*.hpp
  ${INC_DIR}/*.hxx
  ${INC_DIR}/*.h
)

file(GLOB_RECURSE SOURCE_FILES
  ${SRC_DIR}/*.cpp
  ${SRC_DIR}/*.cxx
  ${SRC_DIR}/*.cc
  ${SRC_DIR}/*.c
  ${proto_out_srcs}
)

add_library(${ROOT_PRJ} SHARED
  QKrakenCpp_global.h
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

target_link_libraries(${ROOT_PRJ} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Concurrent
)

target_include_directories(${ROOT_PRJ} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${INC_DIR}
)
