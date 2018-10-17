/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_39. Combination Sum.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/17 17:25:00
 * @brief https://leetcode.com/problems/combination-sum/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_39_39_COMBINATION_SUM_H
#define INC_1STPROGRAM_LEETCODE_39_39_COMBINATION_SUM_H

#include "../util/header_util.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) {
            return result;
        }
        int start = 0;
        int length = candidates.size();
        vector<int> path;
        dfs(candidates, result, start, length, path, target);
        return result;
    }

    void dfs(vector<int> &candidates, vector<vector<int>> &result,
             int &start, int length, vector<int> &path, int &target) {
        if (start >= length) {
            return;
        }

        for (int i = start; i < length; ++i) {
            target -= candidates[i];
            path.push_back(candidates[i]);
            if (target == 0) {
                result.push_back(path);
            } else if (target > 0) {
                dfs(candidates, result, i, length, path, target);
            }
            target += candidates[i];
            path.pop_back();
        }
    }
};

void test_combination_sum() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = Solution().combinationSum(candidates, target);
}

#endif //INC_1STPROGRAM_LEETCODE_39_39_COMBINATION_SUM_H
