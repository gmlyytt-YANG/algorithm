// Created by Li,Yang(Duer04) on 2018/8/15.
// Author: liyang
//
// 二进制数中1的个数

#ifndef INC_1STPROGRAM_OFFER_15_NUMBER_OF_1S_H
#define INC_1STPROGRAM_OFFER_15_NUMBER_OF_1S_H

#include <iostream>
#include <unordered_set>

int number_of_1s(int value) {
    int count = 0;
    unsigned int flag = 1;
    while (flag) {
        if (value & flag) {
            ++count;
        }
        flag = (flag << 1);
    }
    return count;
}

int number_of_1s_2(int value) {
    int count = 0;
    while (value) {
        value = (value - 1) & value;
        ++count;
    }
    return count;
}

int number_of_1_recursive(int num) {
    if (num <= 0) {
        return 0;
    }
    // std::cout << num << std::endl;
    return number_of_1_recursive(num & (num - 1)) + 1;
}

void test_number_of_1s() {
    int value = 14;
    std::cout << number_of_1s_2(value) << std::endl;
    std::cout << number_of_1_recursive(value) << std::endl;
}

#endif //INC_1STPROGRAM_OFFER_15_NUMBER_OF_1S_H
