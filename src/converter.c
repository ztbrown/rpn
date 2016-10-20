#include <stdlib.h>
#include <string.h>
#include "converter.h"

void to_rpn(const char *infix, char *buf){

    buf[0] = infix[0];

    for(int i = 0; i < (sizeof(infix)/sizeof(infix[0])); i++){
        if (infix[i] == '+')
        {
            buf[i] = infix[i+1];
            buf[i+1] = '+';
        }
    }
    strcat(buf, "");
}

