add_library(
    dimacs
    dimacs_lib/dimacs.h
    dimacs_lib/dimacs.c
)

target_include_directories(dimacs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
