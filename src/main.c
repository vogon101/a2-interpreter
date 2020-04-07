#include <stdio.h>
#include <stdlib.h>
#include "a2-lib/program.h"
#include "interpreter/frontend/file_utils.h"
#include "interpreter/interpreter.h"
#include "interpreter/frontend/file_reader.h"

#define FILENAME "compiled2.a2"

int main() {
    printf("Running: "FILENAME"\n");

    FileContents* fc = read_file(FILENAME);

    Program* p = read_program(fc->contents, fc->length);

    interpret(p);

    return 0;
}
