//
// Created by Freddie on 27/03/2020.
//

#ifndef A2_INTERPRETER_INSTRUCTION_H
#define A2_INTERPRETER_INSTRUCTION_H

enum eInstructionCategory {

    INST_CONTROL,
    INST_FLOW,
    INST_ARITHMETIC,
    INST_MEMORY,
    INST_IO

};

enum eOperandType {
    OP_NONE,
    OP_NUMBER,
    OP_LOCATION
};

typedef unsigned char InstructionCategory;

typedef unsigned char InstructionType;
typedef unsigned char OperandType;
typedef struct {
    InstructionCategory inst_category;
    InstructionType inst_type;
} InstructionID;

struct Instruction {
    InstructionID id;

    OperandType op_type;
    unsigned long op_value;
};



typedef struct Instruction Instruction;

typedef struct {
    InstructionType inst_type;
    const char *str;
} InstructionTypeConversion;

#include "instructions_arithmetic.h"
#include "instructions_control.h"
#include "instructions_io.h"
#include "instructions_memory.h"

const static struct {
    enum eInstructionCategory category;
    const char *str;
    const InstructionTypeConversion* itcs;
    size_t itcs_size;
} instruction_category_conversion [] = {
        {INST_CONTROL, "CTR"},
        {INST_FLOW, "FLO"},
        {INST_ARITHMETIC, "ARI", &arithmetic_itcs, arithmetic_itcs_size},
        {INST_MEMORY, "MEM"},
        {INST_IO, "IO-"}
};

#endif //A2_INTERPRETER_INSTRUCTION_H
