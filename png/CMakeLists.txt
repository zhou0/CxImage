cmake_minimum_required(VERSION 3.5)
project(libpng C)

add_library(png_static STATIC
    png.c
    pngerror.c
    pngget.c
    pngmem.c
    pngpread.c
    pngread.c
    pngrio.c
    pngrtran.c
    pngrutil.c
    pngset.c
    pngtrans.c
    pngwio.c
    pngwrite.c
    pngwtran.c
    pngwutil.c
)

target_include_directories(png_static PUBLIC . ${CMAKE_CURRENT_SOURCE_DIR}/../zlib)
target_link_libraries(png_static zlib)
