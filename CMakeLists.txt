cmake_minimum_required(VERSION 3.13)
project(telbook C)

set(CMAKE_C_STANDARD 11)

add_executable(telbook main.c structs.c structs.h telbook.c telbook.h)