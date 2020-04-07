//
// Created by fredd on 28/03/2020.
//

#include "interp_instructions.h"
#include "interp_instructions_io.h"
#include <stdio.h>

void debug_context(Context* ctx) {

    printf("====DEBUG====\n");
    printf("SP: %8x CP: %8x\n", ctx->stack_pointer, ctx->code_pointer);
    printf("Stack:\n");
    for (int i = 0; i < ctx->stack_pointer; i++) {
        printf("%8x: %lu\n", i, ctx->stack[i]);
    }
    printf("=============\n");

}

int interpret_io_instruction(const Instruction* instruction, Context* context) {
    switch (instruction->id.inst_type){
        case INST_IO_DISPLAY:
            printf("DISPLAY: %lu\n", context->stack[--context->stack_pointer]);
            break;
        case INST_IO_PEEK:
            printf("PEEK: %lu\n", context->stack[context->stack_pointer-1]);
            break;
        case INST_IO_DEBUG:
            debug_context(context);
            break;
    }

    return 1;

}
