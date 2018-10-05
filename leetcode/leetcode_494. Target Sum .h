/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_494. Target Sum .h
 * @author gmlyytt@outlook.com
 * @date 2018/08/23 10:01:00
 * @brief https://leetcode.com/problems/target-sum/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_494_TARGET_SUM_H
#define INC_1STPROGRAM_LEETCODE_494_TARGET_SUM_H

#include "../util/header_util.h"

int find_target_sum_ways_core(std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return 0;
    }
    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (auto& elem : nums) {
        for (int i = target; i >= elem; --i) {
            dp[i] += dp[i - elem];
        }
    }
    return dp[target];
}

int find_target_sum_ways(std::vector<int>& nums, int S) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    return find_target_sum_ways_core(nums, (sum + S) >> 1);
}
#endif //INC_1STPROGRAM_LEETCODE_494_TARGET_SUM_H
