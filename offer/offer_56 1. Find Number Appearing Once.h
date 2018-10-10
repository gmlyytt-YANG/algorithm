/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_56 1. Find Number Appearing Once.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/14 9:34:00
 * @brief 剑指offer56_1题 一个数组中只有两个元素出现一次，其他元素出现两次，找出这两个数
 * */

#ifndef INC_1STPROGRAM_OFFER_56_1_FIND_NUMBER_APPEARING_ONCE_H
#define INC_1STPROGRAM_OFFER_56_1_FIND_NUMBER_APPEARING_ONCE_H

#include "../util/header_util.h"

int find_first_index_1(int value) {
    int index = 0;
    while ((value & 1) == 0 && index < 8 * sizeof(int)) {
        value = value >> 1;
        ++index;
    }
    return index;
}

bool judge_bit_1_or_0(int value, int index) {
    value = value >> index;
    return (value & 1);
}

std::pair<int, int> find_number_appearing_once(std::vector<int> &arr) {
    std::pair<int, int> result = {};
    if (arr.empty()) {
        return result;
    }
    int data = 0;
    for (auto &elem : arr) {
        data ^= elem;
    }
    int index = find_first_index_1(data);
    int num1 = 0;
    int num2 = 0;
    for (auto &elem : arr) {
        if (judge_bit_1_or_0(elem, index)) {
            num1 ^= elem;
        } else {
            num2 ^= elem;
        }
    }
    return {num1, num2};
}

void test_find_number_appearing_once() {
    std::vector<int> arr = {1, 2, 3, 3, 4, 5, 2, 1};
    std::pair<int, int> result = find_number_appearing_once(arr);
}

#endif //INC_1STPROGRAM_OFFER_56_1_FIND_NUMBER_APPEARING_ONCE_H
