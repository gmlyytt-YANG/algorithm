// Created by Li,Yang(Duer04) on 2018/8/28.
// Author: liyang
//
// 左旋字符串
#ifndef INC_1STPROGRAM_OFFER_58_LEFT_ROTATE_STRING_H
#define INC_1STPROGRAM_OFFER_58_LEFT_ROTATE_STRING_H

#include <iostream>

void left_rotate_string(std::string& str, int num) {
    if (str.empty() || num <= 0) {
        return;
    }
    std::reverse(str.begin(), str.end());
    std::reverse(str.begin(), str.begin() + str.size() - num);
    std::reverse(str.begin() + str.size() - num, str.end());
}

void test_left_rotate_string() {
    std::string str = "abcdefg";
    int num = 2;
    left_rotate_string(str, 2);
}
#endif //INC_1STPROGRAM_OFFER_58_LEFT_ROTATE_STRING_H
