/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_42. Maximum Sub Array.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/25 9:34:00
 * @brief 剑指offer42题 最大子数组
 * */

#ifndef INC_1STPROGRAM_OFFER_42_MAXIMUM_SUB_ARRAY_H
#define INC_1STPROGRAM_OFFER_42_MAXIMUM_SUB_ARRAY_H

#include "../util/header_util.h"

std::pair<int, int> maximum_subarray(std::vector<int> &arr) {
    if (arr.empty()) {
        exit(-1);
    }
    if (arr.size() == 1) {
        return {0, 0};
    }
    int max = INT_MIN;
    int sum = 0;
    int begin = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (sum >= 0) {
            sum += arr[i];
        } else {
            sum = arr[i];
            begin = i;
        }
        if (sum > max) {
            max = sum;
            left = begin;
            right = i;
        }
    }
    return {left, right};
}

void test_maximum_subarray() {
    std::vector<int> arr = {6, -3, -2, 7, -15, 1, 2, 2};
    std::pair<int, int> result = maximum_subarray(arr);

}

#endif //INC_1STPROGRAM_OFFER_42_MAXIMUM_SUB_ARRAY_H
