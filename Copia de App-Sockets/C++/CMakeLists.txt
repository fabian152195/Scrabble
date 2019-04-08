cmake_minimum_required(VERSION 3.13)
project(connection)

set(SOURCE_FILES main.cpp server.cpp server.h Client.cpp Client.h)

include_directories(.)

add_executable(connection ${SOURCE_FILES})
