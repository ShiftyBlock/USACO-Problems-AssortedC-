cmake_minimum_required(VERSION 3.17)
project(trainingUSACO)

set(CMAKE_CXX_STANDARD 14)

add_executable(trainingUSACO main.cpp)
add_executable(prefix prefix.cpp)
add_executable(nocows nocows.cpp)
add_executable(zerosum zerosum.cpp)
add_executable(moneys moneys.cpp)
add_executable(concom concom.cpp)
add_executable(fracdec fracdec.cpp)