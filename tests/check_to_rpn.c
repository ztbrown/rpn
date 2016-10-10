#include <stdlib.h>
#include <check.h>
#include "../src/converter.h"
#include "check_to_rpn.h"

START_TEST(to_rpn_turns_a_plus_b_into_a_b_plus)
{
    char buf[256] = { };
    to_rpn("a+b", buf);
    ck_assert_str_eq(buf, "ab+");
}
END_TEST

START_TEST(to_rpn_turns_b_plus_c_into_b_c_plus)
{
    char buf[256] = { };
    to_rpn("b+c", buf);
    ck_assert_str_eq(buf, "bc+");
}
END_TEST

Suite *to_rpn_suite(void){
    Suite *s; 
    TCase *tc;

    tc = tcase_create("Core");
    s = suite_create("TO_RPN"); 

    tcase_add_test(tc, to_rpn_turns_a_plus_b_into_a_b_plus);
    tcase_add_test(tc, to_rpn_turns_b_plus_c_into_b_c_plus);

    suite_add_tcase(s, tc);

    return s;
}	
