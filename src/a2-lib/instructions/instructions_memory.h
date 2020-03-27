//
// Created by Freddie on 27/03/2020.
//

#ifndef A2_INTERPRETER_INSTRUCTIONS_MEMORY_H
#define A2_INTERPRETER_INSTRUCTIONS_MEMORY_H

enum MemoryInstructions {
    INST_MEM_PUSH,
    INST_MEM_SAVE
};

const static InstructionTypeConversion memory_itcs[] = {
        {INST_MEM_PUSH, "PUSH"},
        {INST_MEM_SAVE, "SAVE"}
};

const static size_t memory_itcs_size = 2;

#endif //A2_INTERPRETER_INSTRUCTIONS_MEMORY_H
