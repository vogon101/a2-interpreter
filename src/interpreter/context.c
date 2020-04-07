//
// Created by Freddie on 27/03/2020.
//

#include "context.h"
#include <stdlib.h>
Context* create_context(int stack_size, int heap_size) {
    Context* ctx = malloc(sizeof(Context));
    if (!ctx)
        return NULL;

    ctx->stack_size = stack_size;
    ctx->heap_size = heap_size;

    ctx->code_pointer = 0;
    ctx->stack_pointer = 0;
    ctx->stack = malloc(sizeof(unsigned long) * stack_size);
    if (!ctx->stack)
        return NULL;

    ctx->heap = malloc(sizeof(unsigned long) * heap_size);
    if (!ctx->heap)
        return NULL;

    return ctx;
}

void free_context(Context* ctx) {
    free(ctx->stack);
    free(ctx->heap);
    free(ctx);
}