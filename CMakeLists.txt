cmake_minimum_required(VERSION 3.15)
project(a2_interpreter C)

set(CMAKE_C_STANDARD 99)
add_executable(a2_interpreter src/main.c src/a2-lib/program.c src/a2-lib/program.h src/interpreter/interpreter.c src/interpreter/interpreter.h src/a2-lib/function.c src/a2-lib/function.h src/interpreter/utils.c src/interpreter/utils.h src/interpreter/config.h src/interpreter/file_utils.c src/interpreter/file_utils.h src/interpreter/file_reader.c src/interpreter/file_reader.h src/interpreter/context.c src/interpreter/context.h src/a2-lib/instructions/instruction.h src/a2-lib/instructions/instructions_arithmetic.h src/a2-lib/instructions/instructions_control.h src/a2-lib/instructions/instructions_memory.h src/a2-lib/instructions/instructions_io.h src/interpreter/instruction_text_converter.h)