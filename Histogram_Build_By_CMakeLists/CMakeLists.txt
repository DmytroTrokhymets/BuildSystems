cmake_minimum_required(VERSION 2.6)

project(hello)
set(SOURCES main.cpp)

include_directories(lbPrint)
add_subdirectory(lbPrint)
add_executable(main ${SOURCES})
target_link_libraries(main lbPrint)

