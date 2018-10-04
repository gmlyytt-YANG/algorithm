// Created by Li,Yang(Duer04) on 2018/8/13.
// Author: liyang
//
// 字符串中回文串的数量

#ifndef INC_1STPROGRAM_COMMON_9_PALINDROME_NUMBER_H
#define INC_1STPROGRAM_COMMON_9_PALINDROME_NUMBER_H

#include <iostream>

int palindrome(const std::string& str, int left, int right) {
    int count = 0;
    while (left >=0 && right < str.size() && str[left] == str[right]) {
        ++count;
        --left;
        ++right;
    }
    return count;
}

int palindrome_totoal_number(const std::string& str) {
    if (str.empty()) {
        return 0;
    }
    int num = 0;
    for (int i = 0; i < str.size(); ++i) {
        num += palindrome(str, i, i);
        num += palindrome(str, i, i + 1);
    }
    return num;
}

void test_palindrome_totoal_number() {
    std::string str = "abbacbcabdad";
    std::cout << palindrome_totoal_number(str) << std::endl;
}
#endif //INC_1STPROGRAM_COMMON_9_PALINDROME_NUMBER_H
