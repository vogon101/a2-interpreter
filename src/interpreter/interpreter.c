//
// Created by fredd on 27/03/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "../a2-lib/program.h"
#include "config.h"
#include "context.h"

void debug_context(Context* ctx) {

    printf("====DEBUG====\n");
    printf("SP: %8x CP: %8x\n", ctx->stack_pointer, ctx->code_pointer);
    printf("Stack:\n");
    for (int i = 0; i < ctx->stack_pointer; i++) {
        printf("%8x: %lu\n", i, ctx->stack[i]);
    }
    printf("=============\n");

}

//TODO: Make commands have a byte structure that makes type obvious
void arithmetic_instruction(int instruction_type, Context *context) {
    long a1 = (long) context->stack[--context->stack_pointer];
    long a2 = (long) context->stack[--context->stack_pointer];
    long res = 0;
    switch (instruction_type) {
        case INST_ADD:
            res = a1 + a2;
            break;
        case INST_SUB:
            res = a2 - a1;
            break;
        case INST_MULT:
            res = a1 * a2;
            break;
        case INST_DIV:
            res = a2/a1;
            break;
        default:
            printf("Unrecognised arithmetic command %d", instruction_type);
    }
    printf("Arith %d @ %x : (%d, %d) = %d\n", instruction_type, context->stack_pointer, a1, a2, res);
    context->stack[context->stack_pointer++] = res;
}

int interpret_instruction(Instruction *inst, Context *context) {

    printf(">cp: %d, sp: %d\n", context->code_pointer, context->stack_pointer);


    //TODO: Use the different operand types
    switch (inst->instruction_type) {
        case INST_HALT:
            return 0;

        case INST_ADD:
        case INST_MULT:
        case INST_SUB:
        case INST_DIV:
            arithmetic_instruction(inst->instruction_type, context);
            break;
        case INST_SAVE:
            //TODO: The heap yo
            printf("Save\n");
            break;
        case INST_PUSH: {
            unsigned long value = 0;
            switch (inst->op_type) {
                case OP_NUMBER:
                    printf("Push n%8lxu to %x\n", inst->op_value, context->stack_pointer);
                    value = inst->op_value;
                    break;
                case OP_LOCATION:
                    //TODO: The heap
                    value = -1;
                    printf("Push l%8lxu (value: %8lxu) to %x\n", inst->op_value, value, context->stack_pointer);
                    break;
                default:
                    printf("Unsupported operand type for PUSH %d\n", inst->op_type);
            }
            context->stack[context->stack_pointer++] = inst->op_value;
            break;
        }


        case INST_DISPLAY:
            printf("DISPLAY: %lu\n", context->stack[--context->stack_pointer]);
            break;
        case INST_PEEK:
            printf("PEEK: %lu\n", context->stack[context->stack_pointer-1]);
            break;
        case INST_DEBUG:
            debug_context(context);
            break;
        default:
            printf("ERROR instruction: %d [operand: %d %8lx]; sp: %d\n", inst->instruction_type, inst->op_type,
                   inst->op_value, context->stack_pointer);
    }

    return 1;

}

void interpret(Program *p) {

    Context *context = create_context(STACK_SIZE, HEAP_SIZE);

    int running = 1;

    while(running) {
        if (context->code_pointer >= p->main_length) {
            printf("Code pointer: %d is beyond length %d", context->code_pointer, p->main_length);
            running = 0;
            break;
        }

        Instruction *inst = p->m_arena + context->code_pointer;
        running = interpret_instruction(inst, context);
        context->code_pointer += 1;
    }

    printf("Final SP: %d", context->stack_pointer);

    free_context(context);

}

