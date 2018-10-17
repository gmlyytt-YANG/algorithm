/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_40. Combination Sum II.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/17 17:58:00
 * @brief https://leetcode.com/problems/combination-sum-ii/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_40_COMBINATION_SUM_II_H
#define INC_1STPROGRAM_LEETCODE_40_COMBINATION_SUM_II_H

#include "../util/header_util.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
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
             int start, int length, vector<int> &path, int &target) {
        if (start >= length) {
            return;
        }

        for (int i = start; i < length; ++i) {
            target -= candidates[i];
            path.push_back(candidates[i]);
            if (target == 0) {
                // 如果直接sort path， 后面path.pop_back()就会出问题
                vector<int> temp(path.begin(), path.end());
                sort(temp.begin(), temp.end());
                if (find(result.begin(), result.end(), temp) == result.end()) {
                    result.push_back(temp);
                }
            } else if (target > 0) {
                dfs(candidates, result, i + 1, length, path, target);
            }
            target += candidates[i];
            path.pop_back();
        }
    }
};

void test_combination_sum_II() {
    vector<int> candidates = {2, 5, 2, 1, 2};
    int target = 5;
    vector<vector<int>> result = Solution().combinationSum2(candidates, target);
}

#endif //INC_1STPROGRAM_LEETCODE_40_COMBINATION_SUM_II_H
