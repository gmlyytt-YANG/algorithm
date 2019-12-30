/*************************************************************************
 *
 * Copyright (c) gmlyytt@outlook.com. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_41. First Missing Positive.h
 * @author gmlyytt@outlook.com
 * @date 2019/12/30 08:∂07:54
 * @brief https://leetcode.com/problems/first-missing-positive/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_41_FIRST_MISSING_POSITIVE_H
#define INC_1STPROGRAM_LEETCODE_41_FIRST_MISSING_POSITIVE_H

#include "../util/header_util.h"

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int length = nums.size();
        int index = 0;

        // put the element in the right place
        while (index < length) {
            if (nums[index] > 0 && nums[index] <= length
                && nums[index] != nums[nums[index] - 1]) {
                int x = nums[index];
                nums[index] = nums[x - 1];
                nums[x - 1] = x;
            } else if (nums[index] <= 0 || nums[index] > length
                       || nums[index] == index + 1
                       || nums[index] == nums[nums[index] - 1]) {
                ++index;
            }
        }

        // find the Outlier
        for (int index = 0; index < length; ++index) {
            if (nums[index] != index + 1) {
                return index + 1;
            }
        }

        // there is no Outlier in nums
        return length + 1;
    }
};

#endif //INC_1STPROGRAM_LEETCODE_41_FIRST_MISSING_POSITIVE_H
