cmake_minimum_required(VERSION 3.6)
project(assign2)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES assig_two117.c flight_path.c flight_path.h waypoint.h waypoint.c)
add_executable(assign2 ${SOURCE_FILES})