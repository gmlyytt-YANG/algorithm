// Created by Li,Yang(Duer04) on 2018/8/23.
// Author: liyang
//
// target sum

#ifndef INC_1STPROGRAM_LEETCODE_494_TARGET_SUM_H
#define INC_1STPROGRAM_LEETCODE_494_TARGET_SUM_H

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

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
