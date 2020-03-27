//
// Created by fredd on 27/03/2020.
//

#include "utils.h"
unsigned int make_int(const unsigned char* str) {
    return (str[0] << 24u) + (str[1] << 16u) + (str[2] << 8u) + str[3];
}

unsigned long make_long(const unsigned char *str) {
    return
               (unsigned  long) str[7]
            + ((unsigned  long) str[6] << 8u)
            + ((unsigned  long) str[5] << 16u)
            + ((unsigned  long) str[4] << 24u)
            + ((unsigned  long) str[3] << 32u)
            + ((unsigned  long) str[2] << 40u)
            + ((unsigned  long) str[1] << 48u)
            + ((unsigned  long) str[0] << 56u);
}

unsigned short make_short(const unsigned char* str) {
    return (str[0] << 8u) + str[1];
}