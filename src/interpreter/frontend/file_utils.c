//
// Created by fredd on 27/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

FileContents* read_file(const char* file) {
    unsigned char * buffer = 0;
    long length = 0;
    FILE * f = fopen (file, "rb");

    if (f)
    {
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        fseek (f, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer)
        {
            fread (buffer, 1, length, f);
        }
        fclose (f);
    }

    if(buffer) {
        FileContents* fc = malloc(sizeof(FileContents));
        fc->length = length;
        fc->contents = buffer;
    } else {
        return NULL;
    }
}