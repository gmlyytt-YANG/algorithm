/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_18. Combination Sum To M.h
 * @author gmlyytt@outlook.com
 * @date 2018/09/09 20:35:00
 * @brief 找出一个数组中所有等于m的组合(不一定连续)
 * */

#ifndef INC_1STPROGRAM_COMMON_18_COMBINATION_SUM_TO_M_H
#define INC_1STPROGRAM_COMMON_18_COMBINATION_SUM_TO_M_H

#include <iostream>
#include <vector>

using namespace std;

/*
 * @brief just find whether arr has subsequence whose sum is m
 *
 * @param arr input vector
 * @param m target sum
 */
bool find_sum_to_m(vector<int> &arr, int m) {
    if (arr.empty()) {
        return false;
    }
    int Min = INT_MAX;
    int Max = INT_MIN;
    for (auto &num : arr) {
        if (num > Max) {
            Max = num;
        }
        if (num < Min) {
            Min = num;
        }
    }
    if (Max * arr.size() < m) {
        return false;
    }
    if (Min * arr.size() > m) {
        return false;
    }
    vector<bool> dp(m + 1, false);
    dp[0] = true;
    for (auto &num : arr) {
        for (int i = m; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
            if (dp[m] == true) {
                return true;
            }
        }
    }
    return false;
}

/*
 * @brief just find whether arr has subsequence whose sum is m
 *
 * @param arr input vector
 * @param path buf of path
 * @param result total result of all paths
 * @param m target sum
 * @param start start position of recursive method
 * @param top path top
 */
void combination_sum_to_m_core(vector<int> &arr, vector<int> &path, vector<vector<int>> &result,
                               int m, int start, int top) {
    if (start < 0 || start >= arr.size()
        || top >= arr.size() || path.size() > arr.size()) {
        return;
    }
    for (int i = start; i < arr.size(); ++i) {
        m -= arr[i];
        path[top++] = arr[i];
        if (m == 0) {
            vector<int> temp(path.begin(), path.begin() + top);
            result.push_back(temp);
        } else if (m > 0) {
            combination_sum_to_m_core(arr, path, result, m, i + 1, top);
        }
        --top;
        m += arr[i];
    }
}

void test_combination_sum_to_m_core() {
    vector<int> arr = {1, 2, 5, 5, 6, 9};
    int m = 11;
    vector<vector<int>> result;
    vector<int> path(arr.size(), 0);
    int start = 0;
    int top = 0;
    combination_sum_to_m_core(arr, path, result, m, start, top);
}

void test_find_sum_to_m() {
    vector<int> arr = {1, 2, 3, 4};
    int m = 11;
    cout << find_sum_to_m(arr, m) << endl;
}

#endif //INC_1STPROGRAM_COMMON_18_COMBINATION_SUM_TO_M_H
