/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_56 2. Find Number Appearing Once.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/09 9:34:00
 * @brief 剑指offer56_2题 一个数组中除了一个元素出现一次之外都出现三次，找出这个数字
 * */

#ifndef INC_1STPROGRAM_OFFER_56_2_FIND_NUMBER_APPEARING_ONCE_H
#define INC_1STPROGRAM_OFFER_56_2_FIND_NUMBER_APPEARING_ONCE_H

#include "../util/header_util.h"

int find_number_appearing_once(std::vector<int> &arr) {
    if (arr.empty()) {
        exit(-1);
    }
    std::vector<int> bit_sum(32, 0);
    for (auto &elem : arr) {
        int base = 1;
        for (int index = 0; index < 32; ++index) {
            int bit = base & elem;
            if (bit != 0) {
                bit_sum[index] += 1;
            }
            base = (base << 1);
        }
    }
    int result = 0;
    int base = 1;
    for (auto &elem : bit_sum) {
        int true_num = elem % 3;
        result += true_num * base;
        base = base << 1;
    }
    return result;
}

void test_find_number_appearing_once() {
    std::vector<int> arr = {1, 3, 4, 3, 4, 3, 4, 5, 5, 5};
    int result = find_number_appearing_once(arr);
    std::cout << result << std::endl;
}

#endif //INC_1STPROGRAM_OFFER_56_2_FIND_NUMBER_APPEARING_ONCE_H
