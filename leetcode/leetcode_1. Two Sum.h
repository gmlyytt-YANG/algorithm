/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_1. Two Sum.h
 * @author gmlyytt@outlook.com
 * @date 2018/11/15 20:33
 * */

#ifndef INC_1STPROGRAM_LEETCODE_1_TWO_SUM_H
#define INC_1STPROGRAM_LEETCODE_1_TWO_SUM_H

#include "../util/header_util.h"

class Solution {
public:
    vector<int> TwoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int component = target - nums[i];
            if (map.count(component) > 0 && map[component] != i) {
                result = {nums[i], component};
            }
        }
        return result;
    }
};

void test_two_sum() {
    vector<int> nums = {3, 4, 5};
    int target = 6;
    vector<int> result = Solution().TwoSum(nums, target);
}

#endif //INC_1STPROGRAM_LEETCODE_1_TWO_SUM_H
