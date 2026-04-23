cmake_minimum_required(VERSION 3.5)
project(cximage CXX)
add_library(cximage STATIC
    tif_xfile.cpp ximabmp.cpp ximadsp.cpp ximaenc.cpp ximaexif.cpp ximage.cpp ximagif.cpp ximahist.cpp ximaico.cpp ximainfo.cpp ximaint.cpp ximajas.cpp ximajbg.cpp ximajpg.cpp ximalpha.cpp ximalyr.cpp ximamng.cpp ximapal.cpp ximapcx.cpp ximapng.cpp ximapsd.cpp ximaraw.cpp ximasel.cpp ximaska.cpp ximatga.cpp ximath.cpp ximatif.cpp ximatran.cpp ximawbmp.cpp ximawmf.cpp ximawnd.cpp xmemfile.cpp
)
target_include_directories(cximage PUBLIC . ${CMAKE_CURRENT_SOURCE_DIR}/../jpeg ${CMAKE_CURRENT_SOURCE_DIR}/../png ${CMAKE_CURRENT_SOURCE_DIR}/../zlib ${CMAKE_CURRENT_SOURCE_DIR}/../mng ${CMAKE_CURRENT_SOURCE_DIR}/../tiff ${CMAKE_CURRENT_SOURCE_DIR}/../jasper/include ${CMAKE_CURRENT_SOURCE_DIR}/../jbig ${CMAKE_CURRENT_SOURCE_DIR}/../raw ${CMAKE_CURRENT_SOURCE_DIR}/../libpsd)
target_compile_definitions(cximage PRIVATE )
