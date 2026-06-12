cmake_minimum_required(VERSION 3.20)
project(coursera_cpp LANGUAGES CXX)

# Aggiungi questo prima di tutto
set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-15")
set(CMAKE_C_COMPILER "/opt/homebrew/bin/gcc-15")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Werror -pedantic -O2 -g)

set(SOURCES
    aggregates.cpp
    loops.cpp
    unicode.cpp
    bindings.cpp
    constants.cpp
    booleans.cpp
    lambda.cpp
    attributes.cpp
    enums.cpp
    println.cpp
    formatting.cpp
    concepts.cpp
    comparisons.cpp
    orderings.cpp
    utilities.cpp
    algorithms_ranges.cpp
    pipelines.cpp
    subroutines.cpp
    concurrency.cpp
    syncstream.cpp
)

foreach(source_file IN LISTS SOURCES)
    get_filename_component(target_name "${source_file}" NAME_WE)
    add_executable("${target_name}" "${source_file}")
endforeach()
