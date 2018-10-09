/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_22. Subsequence.h
 * @author gmlyytt@outlook.com
 * @date 2018/09/16 20:35:00
 * @brief 连续子数组的各种变形
 * */

#ifndef INC_1STPROGRAM_COMMON_22_SUBSEQUENCE_H
#define INC_1STPROGRAM_COMMON_22_SUBSEQUENCE_H

#include "../util/header_util.h"

/*
 * @brief 数组的最小连续子数组之和
 *
 * @param arr input vector
 * @return min_sum
 */
int min_sum(std::vector<int> &arr) {
    if (arr.empty()) {
        return 0;
    }
    int sum = 0;
    int min_sum = 0;
    for (int i : arr) {
        sum += i;
        if (sum > 0) {
            sum = 0;
        }
        if (sum < min_sum) {
            min_sum = sum;
        }
    }
    if (min_sum == 0) {
        min_sum = INT_MAX;
        for (auto &elem : arr) {
            if (elem < min_sum) {
                min_sum = elem;
            }
        }
    }
    return min_sum;
}

/*
 * @brief 数组的连续子数组的和的绝对值最小值，暴力遍历
 *
 * @param arr input vector
 * @return min_sum
 */
int abs_min(std::vector<int> &arr) {
    if (arr.empty()) {
        return 0;
    }
    int min_sum = INT_MAX;
    for (int i = 0; i < arr.size(); ++i) {
        int cum = 0;
        for (int j = i; j < arr.size(); ++j) {
            cum += arr[j];
            if (std::abs(cum) < min_sum) {
                min_sum = std::abs(cum);
            }
        }
    }
    return min_sum;
}

/*
 * @brief 数组的连续子数组的和的绝对值最小值
 *
 * @param arr input vector
 * @return min_sum
 */
int abs_min_2(std::vector<int> &arr) {
    if (arr.empty()) {
        return 0;
    }
    std::vector<int> sum;
    int cum = 0;
    for (auto &elem : arr) {
        cum += elem;
        if (cum == 0) {
            return 0;
        }
        sum.push_back(cum);
    }
    sort(sum.begin(), sum.end());
    int min_sum = INT_MAX;
    for (int i = 0; i < sum.size() - 1; ++i) {
        int temp = std::abs(sum[i + 1] - sum[i]);
        if (temp < min_sum) {
            min_sum = temp;
        }
    }
    return min_sum;
}

/*
 * @brief 数组的连续子数组的和的绝对值最大值
 *
 * @param arr input vector
 * @return min_sum
 */
int max_abs_sum(std::vector<int> &arr) {
    if (arr.empty()) {
        return 0;
    }
    int cum = 0;
    std::vector<int> sum;
    for (auto &elem : arr) {
        cum += elem;
        sum.push_back(cum);
    }
    sort(sum.begin(), sum.end());
    int max_sum = INT_MIN;
    int Max = INT_MIN;
    int Min = INT_MAX;
    for (auto &elem : sum) {
        if (elem > Max) {
            Max = elem;
        }
        if (elem < Min) {
            Min = elem;
        }
        int temp = std::abs(Max - Min);
        if (temp > max_sum) {
            max_sum = temp;
        }
    }
    return max_sum;
}

void test_min_sum() {
    std::vector<int> arr = {6, 7, 8, -1, -4, -5, 6};
    std::cout << min_sum(arr) << std::endl;
}

void test_abs_min() {
    std::vector<int> arr = {1, 2, -4, 5, -6};
    std::cout << abs_min(arr) << std::endl;
    std::cout << abs_min_2(arr) << std::endl;
}

void test_max_abs_sum() {
    std::vector<int> arr = {1, 2, -10, -20, -30, 5, 6, 7};
    std::cout << max_abs_sum(arr) << std::endl;
}

#endif //INC_1STPROGRAM_COMMON_22_SUBSEQUENCE_H
