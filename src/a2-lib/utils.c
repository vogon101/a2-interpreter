//
// Created by fredd on 27/03/2020.
//

#include "utils.h"
unsigned int make_int(const unsigned char* str) {
    return (str[0] << 24u) + (str[1] << 16u) + (str[2] << 8u) + str[3];
}

unsigned long make_long(const unsigned char *str) {
    return
            str[7]
            + (str[6] << 8u)
            + (str[5] << 16u)
            + (str[4] << 24u)
            + (str[3] << 32u)
            + (str[2] << 40u)
            + (str[1] << 48u)
            + (str[0] << 56u);
}
