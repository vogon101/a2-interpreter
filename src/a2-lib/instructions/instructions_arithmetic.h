//
// Created by Freddie on 27/03/2020.
//

#ifndef A2_INTERPRETER_INSTRUCTIONS_ARITHMETIC_H
#define A2_INTERPRETER_INSTRUCTIONS_ARITHMETIC_H

#include "instruction.h"

enum ArithmeticInstructions {
    INST_ARITH_ADD,
    INST_ARITH_SUB,
    INST_ARITH_MULT,
    INST_ARITH_DIV
};

const static InstructionTypeConversion arithmetic_itcs[] = {
        {INST_ARITH_ADD, "ADD-"},
        {INST_ARITH_SUB, "SUB-"},
        {INST_ARITH_DIV, "DIV-"},
        {INST_ARITH_MULT, "MULT"}
};

const static size_t arithmetic_itcs_size = 4;

#endif //A2_INTERPRETER_INSTRUCTIONS_ARITHMETIC_H
