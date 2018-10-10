/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_53_1. Missing Number In [0, N-1].h
 * @author gmlyytt@outlook.com
 * @date 2018/08/18 9:34:00
 * @brief 剑指offer53_1题 [0, n-1]中缺失的数字
 * */

#ifndef INC_1STPROGRAM_OFFER_53_MISSING_NUMBER_IN_0_N_1_H
#define INC_1STPROGRAM_OFFER_53_MISSING_NUMBER_IN_0_N_1_H

#include "../util/header_util.h"

int missing_number(std::vector<int> &arr) {
    if (arr.empty()) {
        return -1;
    }
    int length = arr.size();
    int low = 0;
    int high = length - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
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
