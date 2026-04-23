cmake_minimum_required(VERSION 3.5)
project(jbig C)
add_library(jbig STATIC
    jbig.c jbig_tab.c
)
target_include_directories(jbig PUBLIC .)
