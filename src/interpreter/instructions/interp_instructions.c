//
// Created by fredd on 28/03/2020.
//

#include "interp_instructions_arithmetic.h"
#include "interp_instructions_control.h"
#include "interp_instructions_flow.h"
#include "interp_instructions_memory.h"
#include "interp_instructions_io.h"
#include "interp_instructions.h"
#include "../log.h"
#include <stdio.h>

//TODO: Maybe inline the subfunctions
int interpret_instruction(const Instruction* instruction, Context* context) {

    switch (instruction->id.inst_category) {
        case INST_MEMORY:
            return interpret_memory_instruction(instruction, context);
        case INST_ARITHMETIC:
            return interpret_arithmetic_instruction(instruction, context);
        case INST_IO:
            return interpret_io_instruction(instruction, context);
        case INST_CONTROL:
            return interpret_control_instruction(instruction, context);
        case INST_FLOW:
            return interpret_flow_instruction(instruction, context);
        default:
            log_error("Unknown instruction category");
            return 0;
    }

}