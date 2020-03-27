//
// Created by fredd on 27/03/2020.
//

#ifndef A2_INTERPRETER_INTERPRETER_H
#define A2_INTERPRETER_INTERPRETER_H

#include "../a2-lib/program.h"

typedef struct {
    int stack_pointer;
    unsigned long* stack;
} Context;

void interpret(Program* p);

#endif //A2_INTERPRETER_INTERPRETER_H
