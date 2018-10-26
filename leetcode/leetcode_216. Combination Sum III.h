/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_216. Combination Sum III.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/25 15:33:00
 * @brief https://leetcode.com/problems/combination-sum-iii/description/
 * */


#ifndef INC_1STPROGRAM_LEETCODE_216_COMBINATION_SUM_III_H
#define INC_1STPROGRAM_LEETCODE_216_COMBINATION_SUM_III_H

#include "../util/header_util.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path(k, 0);
        int top = 0;
        int start = 1;
        dfs(result, path, top, n, k, start);
        return result;
    }

    void dfs(vector<vector<int>> &result, vector<int> &path, int top, int n, int k, int start) {
        if (n < 0 || top >= k) {
            return;
        }
        for (int i = start; i <= n; ++i) {
            n -= i;
            path[top++] = i;
            if (n == 0 && top == k) {
                vector<int> tmp(path.begin(), path.begin() + top);
                result.push_back(tmp);
            } else if (n > 0) {
                dfs(result, path, top, n, k, i + 1);
            }
            --top;
            n += i;
        }
    }
};

void test_combination_sum_III() {
    int k = 3;
    int n = 7;
    vector<vector<int>> result = Solution().combinationSum3(k, n);
}

#endif //INC_1STPROGRAM_LEETCODE_216_COMBINATION_SUM_III_H
