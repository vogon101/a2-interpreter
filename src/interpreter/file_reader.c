//
// Created by Freddie on 27/03/2020.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../a2-lib/include.h"
#include "utils.h"
#include "file_reader.h"
#include "config.h"


char* extract_instruction_name(const char* str) {
    char* x = malloc(INST_NAME_LEN + 1);
    for (int i = 0; i < INST_NAME_LEN; i++)
        x[i] = str[i];
    x[INST_NAME_LEN] = '\0';
    return x;
}



InstructionID get_instruction_type(char* instruction) {
    for (int i = 0; i < sizeof(instruction_category_conversion) / sizeof(instruction_category_conversion[0]); i++) {
        if(!strcmp(instruction, instruction_category_conversion[i].str))
            return instruction_category_conversion[i].it;
    }
    return INST_ERROR;
}

Instruction make_instruction(const char *instruction) {
    char* inst = extract_instruction_name(instruction);
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

Program* read_program(const unsigned char *program, long f_length) {

    unsigned short version = make_short(program);
    unsigned short headerLength = make_short(program + 2);
    unsigned int programLength = make_int(program + 4);

    printf("Version: %4xs, Header Length: %4xs", version, headerLength);
    printf("Program length (instructions) %u\n", programLength);
    printf("Program length (chars) %ld\n", f_length);

    Instruction* m_arena = malloc(sizeof(Instruction) * programLength);
    //TODO functions

    unsigned long i = headerLength * 16;
    size_t instruction_idx = 0;

    while (instruction_idx < programLength) {
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
