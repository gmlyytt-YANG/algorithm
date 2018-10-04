// Created by Li,Yang(Duer04) on 2018/8/29.
// Author: liyang
//
// 数组中数值与下标相等的元素

#ifndef INC_1STPROGRAM_OFFER_53_NUMBER_EQUALS_SUBSCRIPT_H
#define INC_1STPROGRAM_OFFER_53_NUMBER_EQUALS_SUBSCRIPT_H

#include <iostream>
#include <vector>

int equal_subscript(std::vector<int>& arr) {
    if (arr.empty()) {
        return -1;
    }
    int length = arr.size();
    int low = 0;
    int high = length - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (arr[mid] == mid) {
            return mid;
        } else if (arr[mid] > mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void test_equal_subscript() {
    std::vector<int> arr = {-3, -1, 1, 3, 6, 7};
    std::cout << equal_subscript(arr) << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_53_NUMBER_EQUALS_SUBSCRIPT_H
