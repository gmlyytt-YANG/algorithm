/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_8. Palindrome Number.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/13 20:35:00
 * @brief 数字是否是回文串
 * */

#ifndef INC_1STPROGRAM_COMMON_8_PALINDROME_NUMBER_H
#define INC_1STPROGRAM_COMMON_8_PALINDROME_NUMBER_H

#include <iostream>

bool number_palindrome(int value) {
    int base = 1;
    while (base < value / 10) {
        base *= 10;
    }
    while (base) {
        int left = value / base;
        int right = value % 10;
        if (left != right) {
            return false;
        }
        value -= base * left;
        value /= 10;
        base /= 100;
    }
    return true;
}

void test_number_palindrome() {
    int value = 3456;
    std::cout << number_palindrome(value) << std::endl;
}
#endif //INC_1STPROGRAM_COMMON_8_PALINDROME_NUMBER_H
