#ifndef A2_INTERPRETER_FRONTEND_CONVERTERS_H
#define A2_INTERPRETER_FRONTEND_CONVERTERS_H

#include <stdlib.h>
#include "../../a2-lib/include.h"

typedef struct {
    InstructionType inst_type;
    const char *str;
} InstructionTypeConversion;


typedef struct {
    InstructionCategory category;
    const char *str;
    const InstructionTypeConversion* itcs;
    size_t itcs_size;
} InstructionCategoryConversion;


const static InstructionTypeConversion control_itcs[] = {
        {INST_CONTROL_HALT, "HALT"},
        {INST_CONTROL_ERROR, "ERR-"}
};

const static InstructionTypeConversion flow_itcs[] = {
        {INST_FLOW_JUMP, "JMP-"},
        {INST_FLOW_JMPZ, "JMPZ"},
};

const static InstructionTypeConversion arithmetic_itcs[] = {
        {INST_ARITH_MULT, "MULT"},
        {INST_ARITH_DIV, "DIV-"},
        {INST_ARITH_ADD, "ADD-"},
        {INST_ARITH_SUB, "SUB-"},
};

const static InstructionTypeConversion memory_itcs[] = {
        {INST_MEM_PUSH, "PUSH"},
        {INST_MEM_SAVE, "SAVE"},
};

const static InstructionTypeConversion io_itcs[] = {
        {INST_IO_DEBUG, "DBUG"},
        {INST_IO_DISPLAY, "DISP"},
        {INST_IO_PEEK, "PEEK"}
};

const static InstructionCategoryConversion instruction_category_conversion [] = {
        {INST_CONTROL, "CTR", &control_itcs[0], CONTROL_INSTRUCTION_COUNT},
        {INST_FLOW, "FLO", &flow_itcs[0], FLOW_INSTRUCTION_COUNT},
        {INST_ARITHMETIC, "ARI", &arithmetic_itcs[0], ARITHMETIC_INSTRUCTION_COUNT},
        {INST_MEMORY, "MEM", &memory_itcs[0], MEMORY_INSTRUCTION_COUNT},
        {INST_IO, "IO-", &io_itcs[0], IO_INSTRUCTION_COUNT}
};
#endif