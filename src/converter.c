#include <stdlib.h>
#include <string.h>
#include "converter.h"

typedef int bool;
enum { false, true };

static bool is_operator(const char token);
static bool operator_has_precedence(const char token, const char top);

typedef enum {
  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV,
  OP_EXP
} op_code;

const char operators[] = { '+', '-', '*', '/', '^' };
const op_code op_val[] = { OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_EXP };

void to_rpn(const char *infix, char *buf){

    char op_stack[256] = { };
    char *op_stack_ptr = op_stack;
    char top;
    int num = 0;
    char *buf_ptr = buf;

    for(int i = 0; i < strlen(infix); i++){
        if (is_operator(infix[i]))
        {
            if (top != NULL && !operator_has_precedence(infix[i], top))
            {
                *buf_ptr++ = *(--op_stack_ptr);
                *op_stack_ptr++ = infix[i];
                top = infix[i];
            }
            else
            {
                *op_stack_ptr++ = infix[i];
                num++;
                top = infix[i];
            }
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

static bool is_operator(const char token)
{
    return token == '+' ||
           token == '-' ||
           token == '*' ||
           token == '/' ||
           token == '^';
}

static bool operator_has_precedence(const char operator, const char other)
{
    op_code this_op, other_op;

    for(int i = 0; i <  4; i++){
        if (operator == operators[i])
            this_op = op_val[i];
        if (other == operators[i])
            other_op = op_val[i];
    }

    return this_op > other_op;
}
