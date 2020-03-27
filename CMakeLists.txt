cmake_minimum_required(VERSION 3.15)
project(a2_interpreter C)

set(CMAKE_C_STANDARD 99)
add_executable(a2_interpreter src/main.c src/a2-lib/program.c src/a2-lib/program.h src/interpreter/interpreter.c src/interpreter/interpreter.h src/a2-lib/function.c src/a2-lib/function.h src/a2-lib/utils.c src/a2-lib/utils.h src/a2-lib/config.h src/interpreter/file_utils.c src/interpreter/file_utils.h)