#include <stdlib.h>
#include <string.h>
#include "converter.h"

void to_rpn(const char *infix, char *buf){

    char op_stack[256] = { };
    char *op_stack_ptr = op_stack;
    char top;
    int num = 0;
    char *buf_ptr = buf;

    for(int i = 0; i < strlen(infix); i++){
        if (infix[i] == '+')
        {
            if (top == '+')
            {
                *buf_ptr++ = infix[i];
            }
            else
            {
                *op_stack_ptr++ = infix[i];
                num++;
                top = infix[i];
            }
        }
        else if (infix[i] == '-')
        {
            num++;
            *op_stack_ptr++ = infix[i];
        }
        else if (infix[i])
        {
            *buf_ptr++ = infix[i];
        }
    }

    while(num--)
        *buf_ptr++ = *(--op_stack_ptr);

    *buf_ptr++ = '\0';
}

