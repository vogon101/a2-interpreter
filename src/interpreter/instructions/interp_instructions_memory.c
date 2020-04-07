//
// Created by fredd on 28/03/2020.
//

#include "interp_instructions.h"
#include "interp_instructions_memory.h"
#include <stdio.h>
#include "../log.h"


int interpret_memory_instruction(const Instruction* instruction, Context* context) {
    switch (instruction->id.inst_type) {
        case INST_MEM_PUSH: {
            unsigned long value = 0;
            switch (instruction->op_type) {
                case OP_NUMBER:
                    log_trace("Push n%8lxu to %x", instruction->op_value, context->stack_pointer);
                    value = instruction->op_value;
                    break;
                case OP_LOCATION:
                    //TODO: The heap
                    value = -1;
                    log_trace("Push l%8lxu (value: %8lxu) to %x", instruction->op_value, value, context->stack_pointer);
                    log_error("Unimplemented");
                    return 0;
                default:
                    log_error("Unsupported operand type for PUSH %d", instruction->op_type);
                    return 0;

            }
            context->stack[context->stack_pointer++] = value;
            break;
        }
        case INST_MEM_SAVE:
            log_error("Unimplemented");
            return 0;
    }
    return 1;
}
