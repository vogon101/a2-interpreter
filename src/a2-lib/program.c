//
// Created by fredd on 27/03/2020.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "program.h"
#include "utils.h"
#include "config.h"

char* get_instruction(const char* str) {
    char* x = malloc(INST_NAME_LEN + 1);
    for (int i = 0; i < INST_NAME_LEN; i++)
        x[i] = str[i];
    x[INST_NAME_LEN] = '\0';
    return x;
}

InstructionType get_instruction_type(char* instruction) {
    for (int i = 0; i < sizeof(conversion) / sizeof(conversion[0]); i++) {
        if(!strcmp(instruction, conversion[i].str))
            return conversion[i].it;
    }
    return INST_ERROR;
}

Instruction make_instruction(const char *instruction) {
    char* inst = get_instruction(instruction);
    char op_type = instruction[INST_NAME_LEN];

    OperandType operandType;
    switch (op_type) {
        case 'i':
            operandType = OP_NUMBER;
            break;
        case 'l':
            operandType = OP_LOCATION;
            break;
        default:
            operandType = OP_NONE;
    }

    unsigned int op = make_long((const unsigned char *) instruction + INST_NAME_LEN + 1);
    printf("Instruction %s %c %8x\n", inst, op_type, op);
    Instruction res = {get_instruction_type(inst), operandType, op};
    return res;
}

Program* make_program(const unsigned char *program, long f_length) {

    printf(program);
    printf("\n");
    unsigned int programLength = make_int(program);

    printf("Program length (instructions) %u\n", programLength);
    printf("Program length (chars) %ld\n", f_length);

    Instruction* m_arena = malloc(sizeof(Instruction) * programLength);
    //TODO functions

    unsigned long i = 4;
    size_t instruction_idx = 0;

    while (i < f_length) {
        Instruction inst = make_instruction(program + i);
        m_arena[instruction_idx] = inst;
        i += INST_SIZE;
        instruction_idx += 1;
    }

    Program* p = malloc(sizeof(Program));
    p->m_arena = m_arena;
    p->main_length = programLength;

    return p;
}

