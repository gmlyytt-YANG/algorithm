// Created by Li,Yang(Duer04) on 2018/8/15.
// Author: liyang
//
// 奇数放到偶数前面

#ifndef INC_1STPROGRAM_OFFER_21_ODD_BEFORE_EVEN_H
#define INC_1STPROGRAM_OFFER_21_ODD_BEFORE_EVEN_H

#include <iostream>
#include <vector>

void odd_before_even(std::vector<int>& arr) {
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
