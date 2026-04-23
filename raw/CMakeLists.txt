cmake_minimum_required(VERSION 3.5)
project(libdcr C)
add_library(libdcr STATIC libdcr.c)
target_include_directories(libdcr PUBLIC .)
