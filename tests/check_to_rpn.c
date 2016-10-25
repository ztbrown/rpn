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

START_TEST(to_rpn_turns_a_plus_b_plus_c_into_a_b_plus_c_plus)
{
    char buf[256] = { };
    to_rpn("a+b+c", buf);
    ck_assert_str_eq(buf, "ab+c+");
}
END_TEST

START_TEST(to_rpn_turns_a_plus_b_minus_c_into_a_b_c_minus_plus)
{
    char buf[256] = { };
    to_rpn("a+b-c", buf);
    ck_assert_str_eq(buf, "abc-+");
}
END_TEST

START_TEST(to_rpn_turns_a_minus_b_times_c_into_a_b_c_times_minus)
{
    char buf[256] = { };
    to_rpn("a-b*c", buf);
    ck_assert_str_eq(buf, "abc*-");
}
END_TEST

START_TEST(to_rpn_turns_a_divide_b_exponent_c_into_a_b_c_exponent_divide)
{
    char buf[256] = { };
    to_rpn("a/b^c", buf);
    ck_assert_str_eq(buf, "abc^/");
}
END_TEST

START_TEST(to_rpn_turns_a_times_b_minus_c_plus_d_into_a_b_times_c_minus_d_plus)
{
    char buf[256] = { };
    to_rpn("a*b-c+d", buf);
    ck_assert_str_eq(buf, "ab*c-d+");
}
END_TEST

START_TEST(to_rpn_can_handle_multiple_high_precedence_operators_preceding_multiple_low_precedence_operators)
{
    char buf[256] = { };
    to_rpn("l/m^n*o-p", buf);
    ck_assert_str_eq(buf, "lmn^/o*p-");
}
END_TEST

Suite *to_rpn_suite(void){
    Suite *s; 
    TCase *tc;

    tc = tcase_create("Core");
    s = suite_create("TO_RPN"); 

    tcase_add_test(tc, to_rpn_turns_a_plus_b_into_a_b_plus);
    tcase_add_test(tc, to_rpn_turns_b_plus_c_into_b_c_plus);
    tcase_add_test(tc, to_rpn_turns_a_plus_b_plus_c_into_a_b_plus_c_plus);
    tcase_add_test(tc, to_rpn_turns_a_plus_b_minus_c_into_a_b_c_minus_plus);
    tcase_add_test(tc, to_rpn_turns_a_minus_b_times_c_into_a_b_c_times_minus);
    tcase_add_test(tc, to_rpn_turns_a_divide_b_exponent_c_into_a_b_c_exponent_divide);
    tcase_add_test(tc, to_rpn_turns_a_times_b_minus_c_plus_d_into_a_b_times_c_minus_d_plus);
    tcase_add_test(tc, to_rpn_can_handle_multiple_high_precedence_operators_preceding_multiple_low_precedence_operators);

    suite_add_tcase(s, tc);

    return s;
}	
