//
// Created by fredd on 28/03/2020.
//

#include "interp_instructions.h"
#include "interp_instructions_flow.h"
#include "../log.h"
#include <stdio.h>

int interpret_flow_instruction(const Instruction* instruction, Context* context){

    switch (instruction->id.inst_type) {
        case INST_FLOW_JUMP:
            switch (instruction->op_type) {
                case OP_NUMBER:
                    context->code_pointer = instruction->op_value & 0xffffffff;
                    break;
                case OP_LOCATION:
                    log_error("Unimplemented: JMP to location");
                    return 0;
                default:
                    log_error("Unsupported operand type for JMP %d\n", instruction->op_type);
                    return 0;
            }
    }

    return 1;

}
