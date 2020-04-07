//
// Created by fredd on 27/03/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "../a2-lib/include.h"
#include "interpreter.h"
#include "config.h"
#include "log.h"

void interpret(Program *p) {

    Context *context = create_context(STACK_SIZE, HEAP_SIZE);

    log_set_quiet(0);
   // log_set_fp(stdout);

    int running = 1;

    while(running) {
        if (context->code_pointer >= p->main_length) {
            log_warn("Code pointer: %d is beyond length %d", context->code_pointer, p->main_length);
            running = 0;
            break;
        }

        Instruction *inst = p->m_arena + context->code_pointer;
        running = interpret_instruction(inst, context);
        context->code_pointer += 1;
    }

    log_debug("Final SP: %d", context->stack_pointer);

    free_context(context);

}

