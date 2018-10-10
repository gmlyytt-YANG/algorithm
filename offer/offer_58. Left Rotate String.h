/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_58. Left Rotate String.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/28 9:34:00
 * @brief 左旋字符串
 * */

#ifndef INC_1STPROGRAM_OFFER_58_LEFT_ROTATE_STRING_H
#define INC_1STPROGRAM_OFFER_58_LEFT_ROTATE_STRING_H

#include "../util/header_util.h"

void left_rotate_string(std::string &str, int num) {
    if (str.empty() || num <= 0) {
        return;
    }
    std::reverse(str.begin(), str.end());
    std::reverse(str.begin(), str.begin() + str.size() - num);
    std::reverse(str.begin() + str.size() - num, str.end());
}

/*
 * @link https://github.com/gmlyytt-YANG/The-Art-Of-Programming-by-July/blob/master/ebook/zh/01.0.md
 */
void left_rotate_string_2(std::string &str, int num) {
    int length = str.size();
    if (!length || num <= 0 || num > length) {
        return;
    }
    int p1 = 0;
    int p2 = num;

    // move the whole substr before p2 + num - 1 overflow.
    int move_steps_first = (length - num) - length % num;
    while (move_steps_first--) {
        std::swap(str[p1++], str[p2++]);
    }

    // move one step for each tail element.
    int residual = length - p2;
    while (residual--) {
        int temp = p2;
        while (temp > p1) {
            std::swap(str[temp], str[temp - 1]);
            --temp;
        }
        ++p1;
        ++p2;
    }
}

void test_left_rotate_string() {
    std::string str = "abcdefg";
    left_rotate_string_2(str, 2);
}

#endif //INC_1STPROGRAM_OFFER_58_LEFT_ROTATE_STRING_H
