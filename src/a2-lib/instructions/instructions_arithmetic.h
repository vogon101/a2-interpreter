//
// Created by Freddie on 27/03/2020.
//

#ifndef A2_INTERPRETER_INSTRUCTIONS_ARITHMETIC_H
#define A2_INTERPRETER_INSTRUCTIONS_ARITHMETIC_H

#include "instruction.h"

typedef enum ArithmeticInstructions {
    INST_ARITH_ADD,
    INST_ARITH_SUB,
    INST_ARITH_MULT,
    INST_ARITH_DIV
} ArithmeticInstructions;

#define ARITHMETIC_INSTRUCTION_COUNT 4

#endif //A2_INTERPRETER_INTERP_INSTRUCTIONS_ARITHMETIC_H
