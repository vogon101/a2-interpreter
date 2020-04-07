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

#define INSTRUCTION_CATEGORY_COUNT 5

enum eOperandType {
    OP_NONE,
    OP_NUMBER,
    OP_LOCATION
};

typedef unsigned char InstructionCategory;
typedef unsigned char InstructionType;
typedef unsigned char OperandType;

//TODO: The are effectively singletons, but are created on the fly
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




#endif //A2_INTERPRETER_INSTRUCTION_H
