//
// Created by Freddie on 27/03/2020.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../a2-lib/include.h"
#include "../include.h"
#include "instruction_converters.h"
#include "../log.h"


char* extract_instruction_name(const char* str) {
    char* x = malloc(INST_NAME_LEN + 1);
    for (int i = 0; i < INST_NAME_LEN; i++)
        x[i] = str[i];
    x[INST_NAME_LEN] = '\0';
    return x;
}



InstructionID* get_instruction_id(char* instruction) {
    const InstructionCategoryConversion* category = NULL;
    const InstructionType* type = NULL;

    // Find the category of instruction
    for (int i = 0; i < INSTRUCTION_CATEGORY_COUNT; i++) {
        if(!strncmp(instruction, instruction_category_conversion[i].str, INST_CAT_LEN)) {
            category = instruction_category_conversion + i;
            break;
        }
    }

    if (!category) {
        log_error("Failed to find category");
        return NULL;
    }

    //Find the type of instruction
    for (int i = 0; i < category->itcs_size; i++) {
        if (!strncmp(instruction + INST_CAT_LEN, category->itcs[i].str, INST_TYP_LEN))
            type = &(category->itcs[i].inst_type);
    }
    if (!type) {
        log_error("Failed to find type");
        return NULL;
    }

    //printf("Found instruction id %i %i\n", category->category, *type);

    InstructionID* inst_id = malloc(sizeof(InstructionID));
    inst_id->inst_type = *type;
    inst_id->inst_category = category->category;

    return inst_id;
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
    log_debug("+ %s %c %8x", inst, op_type, op);
    InstructionID* instructionID = get_instruction_id(inst);
    Instruction res = {*instructionID, operandType, op};
    return res;
}

Program* read_program(const unsigned char *program, long f_length) {

    unsigned short version = make_short(program);
    unsigned short headerLength = make_short(program + 2);
    unsigned int programLength = make_int(program + 4);

    log_debug("Version: %4hu, Header Length: %4hu", version, headerLength);
    log_debug("Program length (instructions) %u", programLength);
    log_debug("Program length (chars) %ld", f_length);

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
