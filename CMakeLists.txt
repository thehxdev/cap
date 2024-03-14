cmake_minimum_required(VERSION 3.15)

project(
    cap
    VERSION 1.0.3
    LANGUAGES C
)

set(CMAKE_C_STANDARD 99)
add_compile_options(
    -Wall
    -Wextra
    -Wno-unused-result
    -Wno-unused-function
)

if (OPTIMIZE)
    add_compile_options(-O2 -DNDEBUG)
else()
    add_compile_options(-Og -ggdb)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES 
      ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif()

add_executable(test
    src/cap.c
    test/test.c
)
