/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_24. Permutation.h
 * @author gmlyytt@outlook.com
 * @date 2018/09/20 20:35:00
 * @brief 数组子集（不连续）的全排列
 * */

#ifndef INC_1STPROGRAM_COMMON_24_PERMUTATION_H
#define INC_1STPROGRAM_COMMON_24_PERMUTATION_H

#include "../util/header_util.h"

bool judge(std::vector<int> &temp, int k) {
    if (temp.empty()) {
        return false;
    }
    long long result = 1;
    for (auto &elem : temp) {
        result *= elem;
    }
    if (result < k) {
        return true;
    }
    return false;
}

void core(std::vector<int> &arr, std::vector<int> &temp, int start, int &count, int k) {
    if (start == arr.size()) {
        return;
    }
    for (int i = start; i < arr.size(); ++i) {
        temp.push_back(arr[i]);
        core(arr, temp, i + 1, count, k);
        for (auto &elem : temp) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
        if (judge(temp, k)) {
            ++count;
        }
        temp.pop_back();
    }
}

int numSubsetProductLessThanK(std::vector<int> &nums, int k) {
    if (nums.empty()) {
        return 0;
    }
    std::vector<int> temp;
    int start = 0;
    int count = 0;
    core(nums, temp, start, count, k);
    return count;
}

void test_numSubsetProductLessThanK() {
    std::vector<int> arr = {10, 5, 2, 6};
    int k = 100;
    std::cout << numSubsetProductLessThanK(arr, k) << std::endl;
}


#endif //INC_1STPROGRAM_COMMON_24_PERMUTATION_H
