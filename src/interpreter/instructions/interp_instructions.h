//
// Created by fredd on 28/03/2020.
//

#ifndef A2_INTERPRETER_INTERP_INSTRUCTIONS_H
#define A2_INTERPRETER_INTERP_INSTRUCTIONS_H

#include "stdlib.h"
#include "../../a2-lib/include.h"
#include "../context.h"

int interpret_instruction (const Instruction* instruction, Context* context);


#endif //A2_INTERPRETER_INTERP_INSTRUCTIONS_H
