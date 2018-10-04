// Created by Li,Yang(Duer04) on 2018/8/25.
// Author: liyang
//
// 最大子数组

#ifndef INC_1STPROGRAM_OFFER_42_MAXIMUM_SUB_ARRAY_H
#define INC_1STPROGRAM_OFFER_42_MAXIMUM_SUB_ARRAY_H

#include <iostream>
#include <vector>

std::pair<int, int> maximum_subarray(std::vector<int>& arr) {
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
    std::vector<int> arr = {6,-3,-2,7,-15,1,2,2};
    std::pair<int, int> result = maximum_subarray(arr);

}
#endif //INC_1STPROGRAM_OFFER_42_MAXIMUM_SUB_ARRAY_H
