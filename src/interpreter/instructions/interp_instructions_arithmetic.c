//
// Created by fredd on 28/03/2020.
//

#include "interp_instructions.h"
#include "interp_instructions_arithmetic.h"
#include "../log.h"
#include <stdio.h>

//const static InstructionTypeConversion arithmetic_itcs[] = {
//        {INST_ARITH_ADD, "ADD-"},
//        {INST_ARITH_SUB, "SUB-"},
//        {INST_ARITH_DIV, "DIV-"},
//        {INST_ARITH_MULT, "MULT"}
//};

//TODO: Make commands have a byte structure that makes type obvious
int interpret_arithmetic_instruction(const Instruction* instruction, Context *context) {
    long a1 = (long) context->stack[--context->stack_pointer];
    long a2 = (long) context->stack[--context->stack_pointer];
    long res = 0;
    switch (instruction->id.inst_type) {
        case INST_ARITH_ADD:
            res = a1 + a2;
            break;
        case INST_ARITH_SUB:
            res = a2 - a1;
            break;
        case INST_ARITH_MULT:
            res = a1 * a2;
            break;
        case INST_ARITH_DIV:
            res = a2/a1;
            break;
        default:
            log_error("Unrecognised arithmetic command %d", instruction->id.inst_type);
            return 0;
    }
    log_trace("Arith %d @ %x : (%d, %d) = %d", instruction->id.inst_type, context->stack_pointer, a1, a2, res);
    context->stack[context->stack_pointer++] = res;
    return 1;
}