/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_442. Find All Duplicates in an Array.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/30 22:00:00
 * @brief 
 * */

#ifndef INC_1STPROGRAM_LEETCODE_442_FIND_ALL_DUPLICATES_IN_AN_ARRAY_H
#define INC_1STPROGRAM_LEETCODE_442_FIND_ALL_DUPLICATES_IN_AN_ARRAY_H

#include "../util/header_util.h"

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> result;
        if (nums.empty()) {
            return result;
        }
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                ++i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};

void test_find_dup() {
    vector<int> nums = {1, 2, 2, 3, 4, 5, 5, 6};
    vector<int> result = Solution().findDuplicates(nums);
}

#endif //INC_1STPROGRAM_LEETCODE_442_FIND_ALL_DUPLICATES_IN_AN_ARRAY_H
