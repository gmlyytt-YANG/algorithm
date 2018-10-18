/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_26. Big Num Add.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/18 11:47:00
 * @brief 
 * */

#ifndef INC_1STPROGRAM_COMMON_26_BIG_NUM_ADD_H
#define INC_1STPROGRAM_COMMON_26_BIG_NUM_ADD_H

#include "../util/header_util.h"

void add_two_numbers_string_recursive_core(string &a, string &b, int index,
                                             int& carry, string &result) {
   if (index < a.size() || index < b.size()) {
       int num_a = 0;
       int num_b = 0;
       if (index < a.size()) {
           num_a = a[a.size() - 1 - index] - '0';
       }
       if (index < b.size()) {
           num_b = b[b.size() - 1 - index] - '0';
       }
       int sum = num_a + num_b + carry;
       carry = sum / 10;
       result += sum % 10 + '0';
       add_two_numbers_string_recursive_core(a, b, index + 1, carry, result);
   } else {
       if (carry) {
           result += '1';
       }
       reverse(result.begin(), result.end());
   }
}

string add_two_numbers_string_recursive(string& a, string& b) {
    string result;
    if (a.empty() || b.empty()) {
        return result;
    }
    int carry = 0;
    int index = 0;
    add_two_numbers_string_recursive_core(a, b, index, carry, result);
    return result;
}

void test_add_two_numbers_string() {
    string a = "1010202";
    string b = "22939482";
    string result = add_two_numbers_string_recursive(a, b);
}
#endif //INC_1STPROGRAM_COMMON_26_BIG_NUM_ADD_H
