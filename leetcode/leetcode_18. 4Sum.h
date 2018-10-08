/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_18. 4Sum.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/08 14:19:00
 * @brief https://leetcode.com/problems/4sum/description/
 * @link http://note.youdao.com/noteshare?id=73e15b566d37967af8791873c89d7e5b&sub=5E362A38CDE24B36A74C2FA66829D964
 * */

#ifndef INC_1STPROGRAM_LEETCODE_18_4SUM_H
#define INC_1STPROGRAM_LEETCODE_18_4SUM_H

#include "../util/header_util.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> result;
        if (nums.size() < 4) {
            return vector<vector<int>>(result.begin(), result.end());
        }
        if (nums.size() == 4) {
            if (accumulate(nums.begin(), nums.end(), 0) == target) {
                result.insert(nums);
            }
            return vector<vector<int>>(result.begin(), result.end());
        }
        map<int, vector<pair<int, int>>> m;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int sum = nums[i] + nums[j];
                m[sum].push_back({i, j});
            }
        }
        for (auto &elem1 : m) {
            int component = target - elem1.first;
            if (m.count(component) > 0) {
                for (auto &elem2 : elem1.second) {
                    for (auto &elem3 : m[component]) {
                        int i = elem2.first;
                        int j = elem2.second;
                        int k = elem3.first;
                        int l = elem3.second;
                        if (i != k && j != l && j != k && i != l) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            result.insert(temp);
                        }
                    }
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};

void test_4_sum() {
    int target = 0;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = Solution().fourSum(nums, target)
}

#endif //INC_1STPROGRAM_LEETCODE_18_4SUM_H
