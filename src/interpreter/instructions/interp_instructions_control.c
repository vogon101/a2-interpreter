//
// Created by fredd on 28/03/2020.
//

#include "interp_instructions.h"
#include "interp_instructions_control.h"
#include "../log.h"
#include <stdio.h>

int interpret_control_instruction(const Instruction* instruction, Context* context) {

    switch (instruction->id.inst_type){
        case INST_CONTROL_HALT:
            return 0;
        case INST_CONTROL_ERROR:
            log_error("Error State at cp: %x!", context->code_pointer);
            return 0;
    }

    return 1;

}