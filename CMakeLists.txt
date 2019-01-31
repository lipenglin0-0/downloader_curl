cmake_minimum_required(VERSION 3.13)
project(download_tool)

set(CMAKE_CXX_STANDARD 14)

set(CURL /usr/local/curl)

set(INCLUDE_CURL ${CURL}/include/curl)

set(LIB_LIBCURL ${CURL}/lib/libcurl.dylib)
set(LIB_LIBCURL_4 ${CURL}/lib/libcurl.4.dylib)

link_libraries(${INCLUDE_CURL} ${LIB_LIBCURL} ${LIB_LIBCURL_4})

add_executable(download_tool main.cpp tools/Downloader.cpp tools/Downloader.h)