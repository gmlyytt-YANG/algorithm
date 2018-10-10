/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_51. Inverse Pair.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/18 9:34:00
 * @brief 剑指offer51题 数组中的逆序对
 * */

#ifndef INC_1STPROGRAM_OFFER_51_INVERSE_PAIR_H
#define INC_1STPROGRAM_OFFER_51_INVERSE_PAIR_H

#include "../util/header_util.h"

int inverse_pair_core(std::vector<int>& arr, int low, int high, int mid) {
    if (arr.empty()) {
        return 0;
    }
    int length = arr.size();
    if (low > high || low < 0 || high < 0 || high >= length || mid < low || mid > high) {
        return -1;
    }
    std::vector<int> arr_left(arr.begin() + low, arr.begin() + mid + 1);
    arr_left.push_back(INT_MAX);
    std::vector<int> arr_right(arr.begin() + mid + 1, arr.begin() + high + 1);
    arr_right.push_back(INT_MAX);

    int left_index = 0;
    int right_index = 0;
    int count = 0;
    for (int i = low; i <= high; ++i) {
        if (arr_left[left_index] > arr_right[right_index]) {
            count += arr_left.size() - 1 - left_index;
            ++right_index;
        } else {
            ++left_index;
        }
    }
    return count;
}

int inverse_pair(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + ((high - low) >> 1);
        int left_count = inverse_pair(arr, low, mid);
        int right_count = inverse_pair(arr, mid + 1, high);
        int count = inverse_pair_core(arr, low, high, mid);
        return count + left_count + right_count;
    }
    return 0;
}

void test_inverse_pair() {
    std::vector<int> arr = { 6, 5, 4, 3, 2, 1 };
    std::cout << inverse_pair(arr, 0, arr.size() - 1) << std::endl;
}

#endif //INC_1STPROGRAM_OFFER_51_INVERSE_PAIR_H
