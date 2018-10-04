// Created by Li,Yang(Duer04) on 2018/8/18.
// Author: liyang
//
// [0, n-1]中缺失的数字

#ifndef INC_1STPROGRAM_OFFER_53_MISSING_NUMBER_IN_0_N_1_H
#define INC_1STPROGRAM_OFFER_53_MISSING_NUMBER_IN_0_N_1_H

#include <iostream>
#include <vector>

int missing_number(std::vector<int>& arr) {
    if (arr.empty()) {
        return -1;
    }
    int length = arr.size();
    int low = 0;
    int high = length - 1;
    while (low <= high) {
        int mid = low + ((high - low ) >> 1);
        if (arr[mid] != mid) {
            if (mid == 0 || arr[mid - 1] == mid - 1) {
                return mid;
            }
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (low == length) {
        return length;
    }
    return -1;
}

void test_missing_number() {
    std::vector<int> arr = {0, 1, 2, 4, 5};
    std::cout << missing_number(arr) << std::endl;
}

#endif //INC_1STPROGRAM_OFFER_53_MISSING_NUMBER_IN_0_N_1_H
