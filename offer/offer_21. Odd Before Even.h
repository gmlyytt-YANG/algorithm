/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_21. Odd Before Even.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/15 10:29:00
 * @brief 剑指offer第21题 奇数放到偶数前面
 * */

#ifndef INC_1STPROGRAM_OFFER_21_ODD_BEFORE_EVEN_H
#define INC_1STPROGRAM_OFFER_21_ODD_BEFORE_EVEN_H

#include "../util/header_util.h"

void odd_before_even(std::vector<int> &arr) {
    int length = arr.size();
    int tail = length - 1;
    for (int head = 0; head < tail; ++head) {
        if ((arr[head] & 0x1) == 0) {
            std::swap(arr[head--], arr[tail--]);
        }
    }
}

void test_odd_before_even() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    odd_before_even(arr);
}

#endif //INC_1STPROGRAM_OFFER_21_ODD_BEFORE_EVEN_H
