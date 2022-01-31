cmake_minimum_required(VERSION 3.17)
project(NekoHW)

set(CMAKE_CXX_STANDARD 14)

file(TOUCH ${CMAKE_CURRENT_BINARY_DIR}/pch.cpp)
add_library(PCH OBJECT ${CMAKE_BINARY_DIR}/pch.cpp)
target_precompile_headers(PCH PRIVATE /usr/local/Cellar/gcc/10.2.0/include/c++/10.2.0/x86_64-apple-darwin19/bits/stdc++.h)

file(GLOB_RECURSE FILES RELATIVE ${PROJECT_SOURCE_DIR} CONFIGURE_DEPENDS "*.cpp")

foreach (FILE ${FILES})
    if (NOT ${FILE} MATCHES "cmake-build*")
        string(REPLACE ".cpp" "" TARGET_NAME "${FILE}")
        string(REPLACE "/" "_" TARGET_NAME "${TARGET_NAME}")
        message(${TARGET_NAME} " = " ${FILE})
        add_executable(${TARGET_NAME} "${FILE}")
        target_precompile_headers(${TARGET_NAME} REUSE_FROM PCH)
    endif ()
endforeach ()

