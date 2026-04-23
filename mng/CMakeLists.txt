cmake_minimum_required(VERSION 3.5)
project(mng C)
add_library(mng STATIC
    libmng_callback_xs.c libmng_chunk_descr.c libmng_chunk_io.c libmng_chunk_prc.c libmng_chunk_xs.c libmng_cms.c libmng_display.c libmng_dither.c libmng_error.c libmng_filter.c libmng_hlapi.c libmng_jpeg.c libmng_object_prc.c libmng_pixels.c libmng_prop_xs.c libmng_read.c libmng_trace.c libmng_write.c libmng_zlib.c
)
target_include_directories(mng PUBLIC . ${CMAKE_CURRENT_SOURCE_DIR}/../jpeg ${CMAKE_CURRENT_SOURCE_DIR}/../zlib)
target_compile_definitions(mng PRIVATE MNG_SUPPORT_DISPLAY MNG_SUPPORT_READ MNG_SUPPORT_WRITE MNG_ACCESS_CHUNKS MNG_STORE_CHUNKS MNG_ERROR_TELLTALE)
