//
// Created by Freddie on 27/03/2020.
//

#ifndef A2_INTERPRETER_INSTRUCTIONS_IO_H
#define A2_INTERPRETER_INSTRUCTIONS_IO_H

enum IOInstructions {
    INST_IO_PEEK,
    INST_IO_DISPLAY,
    INST_IO_DEBUG
};

const static InstructionTypeConversion io_itcs[] = {
        {INST_IO_PEEK, "PEEK"},
        {INST_IO_DISPLAY, "DISP"},
        {INST_IO_DEBUG, "DBUG"}
};

const static size_t io_itcs_size = 3;

#endif //A2_INTERPRETER_INSTRUCTIONS_IO_H
