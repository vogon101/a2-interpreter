//
// Created by fredd on 27/03/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "../a2-lib/program.h"
#include "../a2-lib/config.h"

void interpret_command(Instruction* inst, Context* context) {

    printf(">%d\n", context->stack_pointer);

    //TODO: Use the different operand types
    switch (inst->instruction_type) {
        case INST_ADD: {
            long a1 = (long) context->stack[--context->stack_pointer];
            long a2 = (long) context->stack[--context->stack_pointer];
            long res = a1 + a2;
            printf("Add @ %x : %d + %d = %d\n", context->stack_pointer, a1, a2, res);
            context->stack[context->stack_pointer++] = res;
            break;
        }
        case INST_SAVE:
            //TODO: The heap yo
            printf("Save\n");
            break;
        case INST_PUSH:
            printf("Push %8lxu to %x\n", inst->op_value, context->stack_pointer);
            context->stack[context->stack_pointer++] = inst->op_value;
            break;
        case INST_DISPLAY:
            printf("DISPLAY: %lu\n", context->stack[--context->stack_pointer]);
            break;
        default:
            break;
    }

}

void interpret(Program *p) {

    Context* context = malloc(sizeof(Context));
    unsigned long* stack = malloc(sizeof(long) * STACK_SIZE);
    context->stack = stack;
    context->stack_pointer = 0;

    for (int i = 0; i < p->main_length; i++) {
        Instruction* inst = p->m_arena + i;
        interpret_command(inst, context);
    }

    printf("Final SP: %d", context->stack_pointer);

}

