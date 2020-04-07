//
// Created by fredd on 27/03/2020.
//

#ifndef A2_INTERPRETER_FILE_UTILS_H
#define A2_INTERPRETER_FILE_UTILS_H

typedef struct {
    long length;
    const unsigned char* contents;
} FileContents;

FileContents* read_file(const char* file);
#endif //A2_INTERPRETER_FILE_UTILS_H
