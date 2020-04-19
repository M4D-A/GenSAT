add_library(
    dimacs
    dimacs_lib/dimacs.h
    dimacs_lib/dimacs.c
)

target_include_directories(dimacs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(
    memory
    memory_lib/memory.h
    memory_lib/memory.c
)

target_include_directories(memory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})