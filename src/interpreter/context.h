//
// Created by Freddie on 27/03/2020.
//

#ifndef A2_INTERPRETER_CONTEXT_H
#define A2_INTERPRETER_CONTEXT_H

typedef struct {
    int stack_pointer;
    unsigned long* stack;

    unsigned long* heap;

    int code_pointer;
} Context;

Context* create_context(int stack_size, int heap_size);
void free_context(Context* context);

#endif //A2_INTERPRETER_CONTEXT_H
