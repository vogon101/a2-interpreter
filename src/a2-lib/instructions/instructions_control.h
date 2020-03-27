//
// Created by Freddie on 27/03/2020.
//

#ifndef A2_INTERPRETER_INSTRUCTIONS_CONTROL_H
#define A2_INTERPRETER_INSTRUCTIONS_CONTROL_H

enum ControlInstructions {
    INST_CONTROL_HALT,
    INST_CONTROL_ERROR
};

const static InstructionTypeConversion control_itcs[] = {
        {INST_CONTROL_HALT, "HALT"},
        {INST_CONTROL_ERROR, "ERR-"}
};

const static size_t control_itcs_size = 4;

#endif //A2_INTERPRETER_INSTRUCTIONS_CONTROL_H
