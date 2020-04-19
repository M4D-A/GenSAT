cmake_minimum_required(VERSION 3.16)
project(GenSAT VERSION 0.1.0)

add_subdirectory(libraries)
add_executable(gensat main.c)


target_link_libraries(gensat PRIVATE dimacs)
target_link_libraries(gensat PRIVATE memory)