#include <stdlib.h>
#include <check.h>
#include "check_to_rpn.h"

Suite *to_rpn_suite(void){
    Suite *s; 

    s = suite_create("TO_RPN"); 

    return s;
}	
