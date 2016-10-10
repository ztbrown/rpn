#include <stdlib.h>
#include <string.h>
#include "converter.h"

void to_rpn(const char *infix, char *buf){
    buf[0] = infix[0];
    buf[1] = infix[2];
    buf[2] = infix[1];

    buf[3] = '\0';
}

