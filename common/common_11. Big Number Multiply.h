/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_11. Big Number Multiply.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/14 20:35:00
 * @brief 两个大数相乘
 * */

#ifndef INC_1STPROGRAM_COMMON_11_BIG_NUMBER_MULTIPLY_H
#define INC_1STPROGRAM_COMMON_11_BIG_NUMBER_MULTIPLY_H

#include "../util/header_util.h"

void multiply(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& result) {
    if (arr1.empty() || arr2.empty()) {
        return;
    }
    int length1 = arr1.size();
    int length2 = arr2.size();
    result.resize(length1 + length2);
    for (int i = 0; i < length1; ++i) {
        for (int j = 0; j < length2; ++j) {
            result[i + j] += arr1[i] * arr2[j];
        }
    }

    for (int i = 1; i < result.size(); ++i) {
        // don't need to consider carry, because the bits are enough.
        result[i] += result[i - 1] / 10;
        result[i - 1] %= 10;
    }

    // remove 0s
    int high = result.size() - 1;
    while (result[high] == 0) {
        --high;
    }
    std::vector<int> final_result(result.begin(), result.begin() + high + 1);
    result = final_result;
}

void test_multiply() {
    std::vector<int> arr1 = {3, 2};
    std::vector<int> arr2 = {3, 2};
    std::vector<int> result;
    multiply(arr1, arr2, result);
    for (auto& elem : result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

#endif //INC_1STPROGRAM_COMMON_11_BIG_NUMBER_MULTIPLY_H
