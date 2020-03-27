#include <stdio.h>
#include <stdlib.h>
#include "a2-lib/program.h"
#include "interpreter/file_utils.h"
#include "interpreter/interpreter.h"

#define FILENAME "compiled1.a2"

int main() {
    printf(FILENAME"\n");

    FileContents* fc = read_file(FILENAME);

    Program* p = make_program(fc->contents, fc->length);

    interpret(p);


    return 0;
}
