cmake_minimum_required(VERSION 3.10.2)

project(shortest_path)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(shortest_path ${SOURCES})