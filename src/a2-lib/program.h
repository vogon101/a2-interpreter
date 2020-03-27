//
// Created by fredd on 27/03/2020.
//

#ifndef A2_INTERPRETER_PROGRAM_H
#define A2_INTERPRETER_PROGRAM_H

#include "function.h"

enum InstructionType {
    INST_ERROR,
    INST_ADD,
    INST_PUSH,
    INST_SAVE,
    INST_DISPLAY
};

enum OperandType {
    OP_NONE,
    OP_NUMBER,
    OP_LOCATION
};


typedef enum InstructionType InstructionType;
typedef enum OperandType OperandType;

const static struct {
    InstructionType it;
    const char *str;
} conversion [] = {
        {INST_ADD, "ADD---"},
        {INST_PUSH, "PUSH--"},
        {INST_SAVE, "SAVE--"},
        {INST_DISPLAY, "DISP--"}
};

/*
struct Operand {
    OperandType operand_type;
    unsigned long value;
};

typedef struct Operand Operand;
*/
struct Instruction {
    InstructionType instruction_type;
    OperandType op_type;
    unsigned long op_value;
};

typedef struct Instruction Instruction;

struct Program {
    unsigned int main_length;
    Instruction* m_arena;

    int functions_length;
    Function* f_arena;
};

typedef struct Program Program;

Program* make_program (const unsigned char* program, long f_length);

#endif //A2_INTERPRETER_PROGRAM_H
