//
// Created by fredd on 27/03/2020.
//

#ifndef A2_INTERPRETER_INTERP_INSTRUCTIONS_FLOW_H
#define A2_INTERPRETER_INTERP_INSTRUCTIONS_FLOW_H

#include "instruction.h"

enum FlowInstructions {
    INST_FLOW_JUMP,
    INST_FLOW_JMPZ
};

#define FLOW_INSTRUCTION_COUNT 2

#endif //A2_INTERPRETER_INTERP_INSTRUCTIONS_FLOW_H
