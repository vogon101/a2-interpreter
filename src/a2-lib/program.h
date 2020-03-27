//
// Created by fredd on 27/03/2020.
//

#ifndef A2_INTERPRETER_PROGRAM_H
#define A2_INTERPRETER_PROGRAM_H

#include "function.h"
#include "instructions/instruction.h"


struct Program {
    unsigned int main_length;
    Instruction* m_arena;

    int functions_length;
    Function* f_arena;
};

typedef struct Program Program;

#endif //A2_INTERPRETER_PROGRAM_H
